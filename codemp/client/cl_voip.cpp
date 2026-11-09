/*
===========================================================================
Copyright (C) 2026, TaystJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

// cl_voip.cpp -- proximity voice chat, client side
//
// Microphone (or a test WAV) -> 20 ms Opus frames -> clc_voip with the next
// usercmd packet. The server relays to players in range (sv_voip.cpp) and
// svc_voip comes back here, is decoded per speaker and handed to the sound
// system (snd_voice.cpp), which plays it at the speaker and moves their lips.
//
// Nothing is sent unless the server advertises VOIP_PROTOCOL and we have told
// it "voip on", so other servers and clients never see the new opcodes.

#include "client.h"
#include "snd_local.h"
#include "sdl/sdl_sound.h"

#ifdef USE_VOIP
#include <opus.h>
#endif

// bit position of the first svc_voip in the message being parsed, or -1;
// CL_WriteDemoMessage cuts demos there so they stay playable everywhere
int cl_voipDemoCutBit = -1;

#ifdef USE_VOIP

#define VOIP_MAX_FRAME_BYTES	255		// frame lengths travel as one byte
#define VOIP_MAX_DECODE			5760	// 120 ms, Opus's largest frame
#define VOIP_MAX_PLC_FRAMES		5		// conceal up to 100 ms of lost frames
#define VOIP_VAD_HOLD_MSEC		400
#define VOIP_MIC_IDLE_MSEC		10000	// close the microphone after this long unused
#define VOIP_MIC_RETRY_MSEC		5000

static cvar_t	*cl_voip;
static cvar_t	*cl_voipUseVAD;
static cvar_t	*cl_voipVADThreshold;
static cvar_t	*cl_voipGain;
static cvar_t	*cl_voipBitrate;
static cvar_t	*cl_voipShowMeter;
static cvar_t	*cl_voipCaptureDevice;

// server handshake
static qboolean		voipAnnounced;		// sent "voip on" to this server

// input
static kbutton_t	voipButton;			// +voiprecord
static qboolean		voipButtonWasDown;
static qboolean		micOpen;
static qboolean		micRunning;
static int			micIdleSince;
static int			micFailTime;

static short		*fileData;			// voip_playfile
static int			fileLength;
static int			filePos;
static int			fileStartTime;

static short		captureFrame[VOIP_FRAME_SAMPLES];
static int			captureFill;
static float		meterLevel;
static int			vadHoldUntil;

// encoding
static OpusEncoder	*encoder;
static int			encoderBitrate;
static qboolean		transmitting;
static int			generation;
static int			sequence;

static byte			outData[VOIP_MAX_PACKET_BYTES];
static int			outLen;
static int			outFrames;
static int			outGeneration;
static int			outSequence;

// loopback test
static int			loopbackEnt = -1;
static OpusDecoder	*loopbackDecoder;

// decoding
typedef struct voipSpeaker_s {
	OpusDecoder	*decoder;
	qboolean	started;
	int			generation;
	int			nextSequence;
} voipSpeaker_t;

static voipSpeaker_t	speakers[MAX_CLIENTS];
static qboolean			muted[MAX_CLIENTS];

/*
===============================================================================

Helpers

===============================================================================
*/

static qboolean CL_Voip_ServerSupported( void ) {
	const char *serverInfo = cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO];
	return (qboolean)!strcmp( Info_ValueForKey( serverInfo, "sv_voipProtocol" ), VOIP_PROTOCOL );
}

static qboolean CL_Voip_CanTransmit( void ) {
	return (qboolean)( voipAnnounced && cls.state == CA_ACTIVE && !clc.demoplaying );
}

static const char *CL_Voip_PlayerName( int clientNum ) {
	const char *cs = cl.gameState.stringData + cl.gameState.stringOffsets[CS_PLAYERS + clientNum];
	return cs[0] ? Info_ValueForKey( cs, "n" ) : "";
}

static void CL_Voip_ResetOutgoing( void ) {
	outLen = 0;
	outFrames = 0;
}

static void CL_Voip_ResetSpeakers( void ) {
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		speakers[i].started = qfalse;
	}
}

static OpusDecoder *CL_Voip_CreateDecoder( void ) {
	int error = OPUS_OK;
	OpusDecoder *decoder = opus_decoder_create( VOIP_SAMPLE_RATE, 1, &error );
	if ( error != OPUS_OK ) {
		Com_Printf( "VoIP: couldn't create an Opus decoder: %s\n", opus_strerror( error ) );
		return NULL;
	}
	return decoder;
}

static qboolean CL_Voip_EnsureEncoder( void ) {
	const int bitrate = Com_Clampi( 6000, 64000, cl_voipBitrate->integer );

	if ( !encoder ) {
		int error = OPUS_OK;
		encoder = opus_encoder_create( VOIP_SAMPLE_RATE, 1, OPUS_APPLICATION_VOIP, &error );
		if ( error != OPUS_OK ) {
			Com_Printf( "VoIP: couldn't create an Opus encoder: %s\n", opus_strerror( error ) );
			encoder = NULL;
			return qfalse;
		}
		opus_encoder_ctl( encoder, OPUS_SET_SIGNAL( OPUS_SIGNAL_VOICE ) );
		encoderBitrate = 0;
	}

	if ( bitrate != encoderBitrate ) {
		opus_encoder_ctl( encoder, OPUS_SET_BITRATE( bitrate ) );
		encoderBitrate = bitrate;
	}
	return qtrue;
}

/*
===============================================================================

Capture and encoding

===============================================================================
*/

static void CL_Voip_HandleFrame( const short *frame, qboolean held ) {
	const int now = Sys_Milliseconds();
	const qboolean canTransmit = CL_Voip_CanTransmit();

	// level for the meter and voice activation
	double sum = 0.0;
	for ( int i = 0; i < VOIP_FRAME_SAMPLES; i++ ) {
		sum += (double)frame[i] * frame[i];
	}
	meterLevel = (float)( sqrt( sum / VOIP_FRAME_SAMPLES ) / 32768.0 );

	if ( cl_voipUseVAD->integer && meterLevel >= cl_voipVADThreshold->value ) {
		vadHoldUntil = now + VOIP_VAD_HOLD_MSEC;
	}

	const qboolean open = (qboolean)( canTransmit && ( held || ( cl_voipUseVAD->integer && now < vadHoldUntil ) ) );
	const qboolean loopback = (qboolean)( loopbackEnt >= 0 );

	if ( !open ) {
		transmitting = qfalse;
	}
	if ( !open && !loopback ) {
		return;
	}

	if ( !CL_Voip_EnsureEncoder() ) {
		return;
	}

	if ( open && !transmitting ) {
		// new talk spurt: listeners reset their decoder on a new generation
		generation = ( generation + 1 ) & 0xff;
		sequence = 0;
		if ( !loopback ) {
			opus_encoder_ctl( encoder, OPUS_RESET_STATE );
		}
		transmitting = qtrue;
	}

	byte encoded[VOIP_MAX_FRAME_BYTES];
	const int bytes = opus_encode( encoder, frame, VOIP_FRAME_SAMPLES, encoded, sizeof( encoded ) );
	if ( bytes < 0 ) {
		Com_DPrintf( "VoIP: opus_encode failed: %s\n", opus_strerror( bytes ) );
		return;
	}

	if ( open ) {
		if ( outFrames && outGeneration != generation ) {
			CL_Voip_ResetOutgoing();
		}
		if ( outFrames < VOIP_MAX_PACKET_FRAMES && outLen + 1 + bytes <= VOIP_MAX_PACKET_BYTES ) {
			if ( !outFrames ) {
				outGeneration = generation;
				outSequence = sequence;
			}
			outData[outLen++] = (byte)bytes;
			memcpy( outData + outLen, encoded, bytes );
			outLen += bytes;
			outFrames++;
		} else {
			Com_DPrintf( "VoIP: outgoing buffer full, dropped a frame\n" );
			if ( !outFrames ) {
				outSequence = sequence + 1;
			}
		}
		sequence++;
	}

	if ( loopback ) {
		if ( !loopbackDecoder ) {
			loopbackDecoder = CL_Voip_CreateDecoder();
		}
		if ( loopbackDecoder ) {
			static short pcm[VOIP_MAX_DECODE];
			const int samples = opus_decode( loopbackDecoder, encoded, bytes, pcm, VOIP_MAX_DECODE, 0 );
			if ( samples > 0 ) {
				S_Voip_Write( loopbackEnt, pcm, samples, NULL );
			}
		}
	}
}

static void CL_Voip_ProcessSamples( const short *samples, int count, qboolean held ) {
	const float gain = Com_Clamp( 0.0f, 10.0f, cl_voipGain->value );

	for ( int i = 0; i < count; i++ ) {
		int s = (int)( samples[i] * gain );
		captureFrame[captureFill++] = (short)Com_Clampi( -32768, 32767, s );

		if ( captureFill == VOIP_FRAME_SAMPLES ) {
			CL_Voip_HandleFrame( captureFrame, held );
			captureFill = 0;
		}
	}
}

// Send what's left of a talk spurt, padded with silence.
static void CL_Voip_FlushFrame( void ) {
	if ( !captureFill ) {
		return;
	}
	memset( captureFrame + captureFill, 0, ( VOIP_FRAME_SAMPLES - captureFill ) * sizeof( short ) );
	captureFill = 0;
	CL_Voip_HandleFrame( captureFrame, qtrue );
}

static void CL_Voip_FreeFile( void ) {
	if ( fileData ) {
		Z_Free( fileData );
		fileData = NULL;
	}
	fileLength = filePos = 0;
}

static void CL_Voip_CloseMic( void ) {
	if ( micOpen ) {
		SNDDMA_CloseCapture();
	}
	micOpen = micRunning = qfalse;
}

static void CL_Voip_FeedMic( qboolean wanted, qboolean held ) {
	static short buf[4096];
	const int now = Sys_Milliseconds();

	if ( wanted && !micOpen ) {
		if ( micFailTime && now - micFailTime < VOIP_MIC_RETRY_MSEC ) {
			return;
		}
		if ( !SNDDMA_OpenCapture( cl_voipCaptureDevice->string, VOIP_SAMPLE_RATE ) ) {
			micFailTime = now;
			return;
		}
		micFailTime = 0;
		micOpen = qtrue;
	}

	if ( wanted && !micRunning ) {
		SNDDMA_PauseCapture( qfalse );
		micRunning = qtrue;
		captureFill = 0;
	}

	if ( micRunning ) {
		int avail = SNDDMA_AvailableCaptureSamples();
		while ( avail > 0 ) {
			const int got = SNDDMA_Capture( Q_min( avail, (int)ARRAY_LEN( buf ) ), buf );
			if ( got <= 0 ) {
				break;
			}
			CL_Voip_ProcessSamples( buf, got, held );
			avail -= got;
		}
	}

	if ( !wanted && micRunning ) {
		CL_Voip_FlushFrame();
		SNDDMA_PauseCapture( qtrue );
		micRunning = qfalse;
		micIdleSince = now;
	}

	if ( micOpen && !micRunning && now - micIdleSince > VOIP_MIC_IDLE_MSEC ) {
		CL_Voip_CloseMic();
	}
}

static void CL_Voip_FeedFile( void ) {
	// paced in real time, like a microphone
	const int due = (int)Q_min( (int64_t)fileLength,
		( (int64_t)( Sys_Milliseconds() - fileStartTime ) * VOIP_SAMPLE_RATE ) / 1000 );

	if ( due > filePos ) {
		CL_Voip_ProcessSamples( fileData + filePos, due - filePos, qtrue );
		filePos = due;
	}

	if ( filePos >= fileLength ) {
		CL_Voip_FlushFrame();
		CL_Voip_FreeFile();
	}
}

/*
===============================================================================

Per-frame update

===============================================================================
*/

// Called from CA_PRIMED on, so a map change doesn't flap "voip off" / "voip on".
static void CL_Voip_UpdateServerState( void ) {
	const qboolean want = (qboolean)( cl_voip->integer && CL_Voip_ServerSupported() );

	if ( want != voipAnnounced ) {
		CL_AddReliableCommand( want ? "voip on" : "voip off", qfalse );
		voipAnnounced = want;
		if ( !want ) {
			CL_Voip_ResetOutgoing();
			CL_Voip_ResetSpeakers();
			transmitting = qfalse;
		}
	}

	// forget mutes for players who have left
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		if ( muted[i] && !CL_Voip_PlayerName( i )[0] ) {
			muted[i] = qfalse;
		}
	}
}

void CL_Voip_Frame( void ) {
	if ( !cl_voip ) {
		return;
	}

	if ( cls.state >= CA_PRIMED && !clc.demoplaying ) {
		CL_Voip_UpdateServerState();
	}

	const qboolean buttonDown = (qboolean)( voipButton.active != 0 );
	const qboolean held = (qboolean)( buttonDown || voipButtonWasDown );	// keep the tail captured before release
	voipButtonWasDown = buttonDown;

	if ( fileData ) {
		CL_Voip_FeedMic( qfalse, qfalse );
		CL_Voip_FeedFile();
		return;
	}

	const qboolean micWanted = (qboolean)( buttonDown
		|| ( cl_voipUseVAD->integer && CL_Voip_CanTransmit() )
		|| loopbackEnt >= 0 );
	CL_Voip_FeedMic( micWanted, held );
}

/*
===============================================================================

Network

===============================================================================
*/

/*
==================
CL_WriteVoipPacket

clc_voip: [byte generation] [long sequence] [byte frames] [short len] [len bytes]
==================
*/
void CL_WriteVoipPacket( msg_t *msg ) {
	if ( !outFrames ) {
		return;
	}

	if ( CL_Voip_CanTransmit() ) {
		MSG_WriteByte( msg, clc_voip );
		MSG_WriteByte( msg, outGeneration );
		MSG_WriteLong( msg, outSequence );
		MSG_WriteByte( msg, outFrames );
		MSG_WriteShort( msg, outLen );
		MSG_WriteData( msg, outData, outLen );
	}

	CL_Voip_ResetOutgoing();
}

static qboolean CL_Voip_EntityInSnapshot( int entnum ) {
	if ( !cl.snap.valid ) {
		return qfalse;
	}
	if ( cl.snap.ps.clientNum == entnum ) {
		return qtrue;
	}
	for ( int i = 0; i < cl.snap.numEntities; i++ ) {
		if ( cl.parseEntities[( cl.snap.parseEntitiesNum + i ) & ( MAX_PARSE_ENTITIES - 1 )].number == entnum ) {
			return qtrue;
		}
	}
	return qfalse;
}

/*
==================
CL_ParseVoip

svc_voip: [byte sender] [byte generation] [long sequence] [byte frames]
          [byte flags] [short range] [long origin x3] [short len] [len bytes]
==================
*/
void CL_ParseVoip( msg_t *msg ) {
	static byte data[VOIP_MAX_PACKET_BYTES];
	static short pcm[VOIP_MAX_DECODE];

	const int sender = MSG_ReadByte( msg );
	const int gen = MSG_ReadByte( msg );
	const int seq = MSG_ReadLong( msg );
	const int frames = MSG_ReadByte( msg );
	const int flags = MSG_ReadByte( msg );
	const int range = MSG_ReadShort( msg );
	vec3_t origin;
	origin[0] = (float)MSG_ReadLong( msg );
	origin[1] = (float)MSG_ReadLong( msg );
	origin[2] = (float)MSG_ReadLong( msg );
	const int len = MSG_ReadShort( msg );

	if ( len < 0 || len > VOIP_MAX_PACKET_BYTES ) {
		Com_Error( ERR_DROP, "CL_ParseVoip: bad length %i", len );
	}
	MSG_ReadData( msg, data, len );

	if ( !cl_voip->integer || !voipAnnounced ) {
		return;
	}
	if ( sender < 0 || sender >= MAX_CLIENTS || sender == clc.clientNum || muted[sender] ) {
		return;
	}

	voipSpeaker_t *sp = &speakers[sender];
	if ( !sp->decoder ) {
		sp->decoder = CL_Voip_CreateDecoder();
		if ( !sp->decoder ) {
			return;
		}
	}

	if ( !sp->started || gen != sp->generation ) {
		opus_decoder_ctl( sp->decoder, OPUS_RESET_STATE );
		sp->started = qtrue;
		sp->generation = gen;
		sp->nextSequence = seq;
	}

	voipSource_t source;
	memset( &source, 0, sizeof( source ) );
	source.nonSpatial = (qboolean)( ( flags & VOIP_FLAG_NONSPATIAL ) != 0 );
	source.range = (float)Q_max( 0, range );
	source.useOrigin = (qboolean)!CL_Voip_EntityInSnapshot( sender );
	VectorCopy( origin, source.origin );

	int skip = 0;
	if ( seq < sp->nextSequence ) {
		// duplicate or late
		skip = sp->nextSequence - seq;
		if ( skip >= frames ) {
			return;
		}
	} else if ( seq > sp->nextSequence ) {
		// lost frames: let Opus fill short gaps instead of clicking
		const int gap = seq - sp->nextSequence;
		for ( int i = 0; i < gap && i < VOIP_MAX_PLC_FRAMES; i++ ) {
			const int samples = opus_decode( sp->decoder, NULL, 0, pcm, VOIP_FRAME_SAMPLES, 0 );
			if ( samples > 0 ) {
				S_Voip_Write( sender, pcm, samples, &source );
			}
		}
	}
	sp->nextSequence = seq + frames;

	int pos = 0;
	for ( int i = 0; i < frames && pos < len; i++ ) {
		const int frameLen = data[pos++];
		if ( pos + frameLen > len ) {
			break;
		}
		if ( i >= skip ) {
			const int samples = opus_decode( sp->decoder, data + pos, frameLen, pcm, VOIP_MAX_DECODE, 0 );
			if ( samples > 0 ) {
				S_Voip_Write( sender, pcm, samples, &source );
			}
		}
		pos += frameLen;
	}
}

/*
===============================================================================

HUD

===============================================================================
*/

void CL_Voip_DrawMeter( void ) {
	if ( !cl_voip || !cl_voipShowMeter->integer ) {
		return;
	}

	const qboolean buttonDown = (qboolean)( voipButton.active != 0 );
	if ( !transmitting && !buttonDown && loopbackEnt < 0 ) {
		return;
	}

	const float charW = 8.0f * cls.widthRatioCoef;
	const float y = SCREEN_HEIGHT - 92.0f;

	if ( buttonDown && !CL_Voip_CanTransmit() && loopbackEnt < 0 ) {
		const char *text = cl_voip->integer ? "No voice chat on this server" : "Voice chat is off (cl_voip)";
		SCR_DrawStringExt2( SCREEN_WIDTH / 2.0f - strlen( text ) * charW / 2.0f, y, charW, 8.0f,
			text, g_color_table[ColorIndex( COLOR_YELLOW )], qtrue, qfalse );
		return;
	}

	// -50 dBFS .. 0 dBFS
	const float db = meterLevel > 0.0f ? 20.0f * log10f( meterLevel ) : -100.0f;
	const float fill = Com_Clamp( 0.0f, 1.0f, ( db + 50.0f ) / 50.0f );
	const float barW = 80.0f * cls.widthRatioCoef;
	const float textW = 6 * charW;
	const float x = SCREEN_WIDTH / 2.0f - ( textW + barW ) / 2.0f;
	const vec4_t back = { 0.0f, 0.0f, 0.0f, 0.5f };
	const vec4_t gate = { 0.9f, 0.9f, 0.9f, 0.8f };
	const vec4_t live = { 0.2f, 0.9f, 0.3f, 0.9f };
	const vec4_t idle = { 0.5f, 0.5f, 0.5f, 0.9f };

	SCR_DrawStringExt2( x, y, charW, 8.0f, transmitting ? "VOICE" : "MIC", g_color_table[ColorIndex( COLOR_WHITE )], qtrue, qfalse );
	SCR_FillRect( x + textW, y, barW, 8.0f, back );
	SCR_FillRect( x + textW, y, barW * fill, 8.0f, transmitting ? live : idle );

	if ( cl_voipUseVAD->integer && cl_voipVADThreshold->value > 0.0f ) {
		// voice activation threshold marker
		const float t = Com_Clamp( 0.0f, 1.0f, ( 20.0f * log10f( cl_voipVADThreshold->value ) + 50.0f ) / 50.0f );
		SCR_FillRect( x + textW + barW * t, y - 1.0f, 1.0f, 10.0f, gate );
	}
}

/*
===============================================================================

Commands

===============================================================================
*/

extern void IN_KeyDown( kbutton_t *b );
extern void IN_KeyUp( kbutton_t *b );

static void CL_Voip_RecordDown_f( void ) { IN_KeyDown( &voipButton ); }
static void CL_Voip_RecordUp_f( void ) { IN_KeyUp( &voipButton ); }

static int CL_Voip_FindPlayer( const char *arg ) {
	char wanted[MAX_NAME_LENGTH * 2];
	char name[MAX_NAME_LENGTH * 2];
	int i;

	for ( i = 0; arg[i] >= '0' && arg[i] <= '9'; i++ ) {
	}
	if ( arg[0] && !arg[i] ) {
		const int num = atoi( arg );
		if ( num >= 0 && num < MAX_CLIENTS && CL_Voip_PlayerName( num )[0] ) {
			return num;
		}
	}

	Q_strncpyz( wanted, arg, sizeof( wanted ) );
	Q_StripColor( wanted );
	for ( i = 0; i < MAX_CLIENTS; i++ ) {
		Q_strncpyz( name, CL_Voip_PlayerName( i ), sizeof( name ) );
		if ( !name[0] ) {
			continue;
		}
		Q_StripColor( name );
		if ( !Q_stricmp( name, wanted ) ) {
			return i;
		}
	}

	Com_Printf( "No player \"%s\"\n", arg );
	return -1;
}

static void CL_Voip_ListMuted( void ) {
	int count = 0;
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		if ( muted[i] ) {
			Com_Printf( "  %2i %s\n", i, CL_Voip_PlayerName( i ) );
			count++;
		}
	}
	if ( !count ) {
		Com_Printf( "Nobody is muted.\n" );
	}
}

static void CL_Voip_Mute_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: voip_mute <player name or id>\n" );
		CL_Voip_ListMuted();
		return;
	}
	const int num = CL_Voip_FindPlayer( Cmd_Args() );
	if ( num >= 0 ) {
		muted[num] = qtrue;
		Com_Printf( "Muted %s^7's voice.\n", CL_Voip_PlayerName( num ) );
	}
}

static void CL_Voip_Unmute_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: voip_unmute <player name or id|all>\n" );
		CL_Voip_ListMuted();
		return;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "all" ) ) {
		memset( muted, 0, sizeof( muted ) );
		return;
	}
	const int num = CL_Voip_FindPlayer( Cmd_Args() );
	if ( num >= 0 ) {
		muted[num] = qfalse;
		Com_Printf( "Unmuted %s^7's voice.\n", CL_Voip_PlayerName( num ) );
	}
}

static void CL_Voip_Loopback_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: voip_loopback <entnum|off>\n" );
		if ( loopbackEnt >= 0 ) {
			Com_Printf( "Your voice is looped back onto entity %i.\n", loopbackEnt );
		}
		return;
	}

	if ( !Q_stricmp( Cmd_Argv( 1 ), "off" ) ) {
		loopbackEnt = -1;
		return;
	}

	const int ent = atoi( Cmd_Argv( 1 ) );
	if ( ent < 0 || ent >= MAX_GENTITIES ) {
		Com_Printf( "Bad entity number %i\n", ent );
		return;
	}
	loopbackEnt = ent;
	Com_Printf( "Your voice (through Opus) now plays from entity %i.\n", ent );
}

static void CL_Voip_PlayFile_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: voip_playfile <file.wav>\n" );
		return;
	}

	char name[MAX_QPATH];
	Q_strncpyz( name, Cmd_Argv( 1 ), sizeof( name ) );
	COM_DefaultExtension( name, sizeof( name ), ".wav" );

	byte *file = NULL;
	const int len = FS_ReadFile( name, (void **)&file );
	if ( !file ) {
		Com_Printf( "Couldn't load %s\n", name );
		return;
	}

	const wavinfo_t info = GetWavinfo( name, file, len );
	if ( info.format != WAV_FORMAT_PCM || info.width != 2 || info.channels < 1 || info.rate <= 0 ) {
		Com_Printf( "%s must be 16-bit PCM\n", name );
		FS_FreeFile( file );
		return;
	}

	// downmix and resample up front
	const short *src = (const short *)( file + info.dataofs );
	const int frames = info.samples / info.channels;
	const int outLength = (int)( ( (int64_t)frames * VOIP_SAMPLE_RATE ) / info.rate );

	CL_Voip_FreeFile();
	fileData = (short *)Z_Malloc( Q_max( outLength, 1 ) * sizeof( short ), TAG_SND_RAWDATA, qfalse );
	for ( int i = 0; i < outLength; i++ ) {
		const int frame = (int)( ( (int64_t)i * info.rate ) / VOIP_SAMPLE_RATE );
		int sum = 0;
		for ( int c = 0; c < info.channels; c++ ) {
			sum += LittleShort( src[frame * info.channels + c] );
		}
		fileData[i] = (short)( sum / info.channels );
	}
	FS_FreeFile( file );

	fileLength = outLength;
	filePos = 0;
	fileStartTime = Sys_Milliseconds();
	captureFill = 0;
	Com_Printf( "Speaking %s (%.1f s) as your voice.\n", name, (float)outLength / VOIP_SAMPLE_RATE );
}

static void CL_Voip_Stop_f( void ) {
	CL_Voip_FreeFile();
	loopbackEnt = -1;
	captureFill = 0;
	CL_Voip_CloseMic();
}

static void CL_Voip_Devices_f( void ) {
	SNDDMA_ListCaptureDevices();
}

/*
===============================================================================

Lifecycle

===============================================================================
*/

void CL_Voip_Init( void ) {
	cl_voip = Cvar_Get( "cl_voip", "1", CVAR_ARCHIVE_ND, "Proximity voice chat on servers that support it" );
	cl_voipUseVAD = Cvar_Get( "cl_voipUseVAD", "0", CVAR_ARCHIVE_ND, "Transmit whenever you talk instead of holding +voiprecord" );
	cl_voipVADThreshold = Cvar_Get( "cl_voipVADThreshold", "0.02", CVAR_ARCHIVE_ND, "Microphone level (0-1) that opens voice activation" );
	cl_voipGain = Cvar_Get( "cl_voipGain", "1.0", CVAR_ARCHIVE_ND, "Microphone gain" );
	cl_voipBitrate = Cvar_Get( "cl_voipBitrate", "24000", CVAR_ARCHIVE_ND, "Voice chat bitrate in bits per second (6000-64000)" );
	cl_voipShowMeter = Cvar_Get( "cl_voipShowMeter", "1", CVAR_ARCHIVE_ND, "Show a microphone level meter while talking" );
	cl_voipCaptureDevice = Cvar_Get( "cl_voipCaptureDevice", "", CVAR_ARCHIVE_ND, "Microphone to use (see voip_devices); empty for the default" );

	Cmd_AddCommand( "+voiprecord", CL_Voip_RecordDown_f, "Push to talk" );
	Cmd_AddCommand( "-voiprecord", CL_Voip_RecordUp_f );
	Cmd_AddCommand( "voip_mute", CL_Voip_Mute_f, "Stop hearing a player's voice" );
	Cmd_AddCommand( "voip_unmute", CL_Voip_Unmute_f, "Hear a muted player's voice again" );
	Cmd_AddCommand( "voip_loopback", CL_Voip_Loopback_f, "Hear your own voice from an entity, through the codec" );
	Cmd_AddCommand( "voip_playfile", CL_Voip_PlayFile_f, "Speak a WAV file as if it came from your microphone" );
	Cmd_AddCommand( "voip_stop", CL_Voip_Stop_f, "Stop voice tests and close the microphone" );
	Cmd_AddCommand( "voip_devices", CL_Voip_Devices_f, "List microphones" );

	generation = rand() & 0xff;
}

void CL_Voip_Disconnect( void ) {
	voipAnnounced = qfalse;
	transmitting = qfalse;
	captureFill = 0;
	CL_Voip_ResetOutgoing();
	CL_Voip_ResetSpeakers();
	memset( muted, 0, sizeof( muted ) );
	CL_Voip_FreeFile();
	if ( micRunning ) {
		SNDDMA_PauseCapture( qtrue );
		micRunning = qfalse;
		micIdleSince = Sys_Milliseconds();
	}
}

void CL_Voip_Shutdown( void ) {
	CL_Voip_Disconnect();
	CL_Voip_CloseMic();
	loopbackEnt = -1;

	if ( encoder ) {
		opus_encoder_destroy( encoder );
		encoder = NULL;
	}
	if ( loopbackDecoder ) {
		opus_decoder_destroy( loopbackDecoder );
		loopbackDecoder = NULL;
	}
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		if ( speakers[i].decoder ) {
			opus_decoder_destroy( speakers[i].decoder );
			speakers[i].decoder = NULL;
		}
	}

	Cmd_RemoveCommand( "+voiprecord" );
	Cmd_RemoveCommand( "-voiprecord" );
	Cmd_RemoveCommand( "voip_mute" );
	Cmd_RemoveCommand( "voip_unmute" );
	Cmd_RemoveCommand( "voip_loopback" );
	Cmd_RemoveCommand( "voip_playfile" );
	Cmd_RemoveCommand( "voip_stop" );
	Cmd_RemoveCommand( "voip_devices" );
}

#else // !USE_VOIP

// Built without Opus: never announce, so servers never send us voice.
void CL_Voip_Init( void ) {}
void CL_Voip_Shutdown( void ) {}
void CL_Voip_Disconnect( void ) {}
void CL_Voip_Frame( void ) {}
void CL_Voip_DrawMeter( void ) {}
void CL_WriteVoipPacket( msg_t *msg ) {}

void CL_ParseVoip( msg_t *msg ) {
	byte data[VOIP_MAX_PACKET_BYTES];

	MSG_ReadByte( msg );	// sender
	MSG_ReadByte( msg );	// generation
	MSG_ReadLong( msg );	// sequence
	MSG_ReadByte( msg );	// frames
	MSG_ReadByte( msg );	// flags
	MSG_ReadShort( msg );	// range
	MSG_ReadLong( msg );	// origin
	MSG_ReadLong( msg );
	MSG_ReadLong( msg );
	const int len = MSG_ReadShort( msg );
	if ( len < 0 || len > VOIP_MAX_PACKET_BYTES ) {
		Com_Error( ERR_DROP, "CL_ParseVoip: bad length %i", len );
	}
	MSG_ReadData( msg, data, len );
}

#endif // USE_VOIP
