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

// sv_voip.cpp -- proximity voice chat relay
//
// The server never decodes voice. It takes clc_voip packets from clients that
// sent "voip on", picks the listeners in range of the speaker and queues the
// packet for each of them; SV_WriteVoipToClient appends the queue to the next
// snapshot after the server demo has been written, so recorded demos stay
// playable by every client.

#include "server.h"

static cvar_t	*sv_voip;
static cvar_t	*sv_voipRange;
static cvar_t	*sv_voipProtocol;

#define VOIP_BUDGET_MSEC	1000
#define VOIP_BUDGET_BYTES	8000	// ~3x a 24 kbit/s talker, per second

void SV_Voip_Init( void ) {
	sv_voip = Cvar_Get( "sv_voip", "0", CVAR_ARCHIVE_ND, "Relay proximity voice chat between TaystJK clients" );
	sv_voipRange = Cvar_Get( "sv_voipRange", "1200", CVAR_ARCHIVE_ND, "Players hear voices within this distance (0 = whole map)" );
	sv_voipProtocol = Cvar_Get( "sv_voipProtocol", "", CVAR_SERVERINFO | CVAR_ROM, "Voice chat protocol advertised to clients" );
	sv_voip->modified = qtrue;
}

void SV_Voip_ClearQueue( client_t *cl ) {
	cl->voipQueueHead = 0;
	cl->voipQueueCount = 0;
}

void SV_Voip_Frame( void ) {
	if ( !sv_voip || !sv_voip->modified ) {
		return;
	}
	sv_voip->modified = qfalse;

	Cvar_Set( "sv_voipProtocol", sv_voip->integer ? VOIP_PROTOCOL : "" );

	if ( !sv_voip->integer && svs.clients && com_sv_running->integer ) {
		for ( int i = 0; i < sv_maxclients->integer; i++ ) {
			SV_Voip_ClearQueue( &svs.clients[i] );
		}
	}
}

/*
==================
SV_Voip_f

"voip on" / "voip off" from a client that understands svc_voip
==================
*/
void SV_Voip_f( client_t *cl ) {
	const char *arg = Cmd_Argv( 1 );

	if ( !Q_stricmp( arg, "on" ) ) {
		cl->hasVoip = qtrue;
	} else if ( !Q_stricmp( arg, "off" ) ) {
		cl->hasVoip = qfalse;
		SV_Voip_ClearQueue( cl );
	}
}

// Following spectators carry the followed player's playerState, so check the
// view owner as well as the team.
static qboolean SV_Voip_IsSpectator( int clientNum, const playerState_t *ps ) {
	return (qboolean)( ps->clientNum != clientNum
		|| ps->pm_type == PM_SPECTATOR
		|| ps->persistant[PERS_TEAM] == TEAM_SPECTATOR
		|| ( ps->pm_flags & PMF_FOLLOW ) );
}

// Spectators and dead players can't talk to the living, only to each other.
static qboolean SV_Voip_IsGhost( int clientNum, const playerState_t *ps ) {
	return (qboolean)( SV_Voip_IsSpectator( clientNum, ps )
		|| ps->pm_type == PM_DEAD
		|| ps->stats[STAT_HEALTH] <= 0 );
}

static void SV_Voip_Enqueue( client_t *to, const voipServerPacket_t *packet ) {
	if ( to->voipQueueCount >= VOIP_SERVER_QUEUE ) {
		// listener is rate-choked; drop the oldest so they stay current
		to->voipQueueHead = ( to->voipQueueHead + 1 ) % VOIP_SERVER_QUEUE;
		to->voipQueueCount--;
	}
	to->voipQueue[( to->voipQueueHead + to->voipQueueCount ) % VOIP_SERVER_QUEUE] = *packet;
	to->voipQueueCount++;
}

/*
==================
SV_UserVoip

clc_voip: [byte generation] [long sequence] [byte frames] [short len] [len bytes]
Always fully read so the usercmds after it still parse. Returns qfalse if the
rest of the message can't be trusted.
==================
*/
qboolean SV_UserVoip( client_t *cl, msg_t *msg ) {
	static voipServerPacket_t packet;
	const int sender = cl - svs.clients;

	const int generation = MSG_ReadByte( msg );
	const int sequence = MSG_ReadLong( msg );
	const int frames = MSG_ReadByte( msg );
	const int len = MSG_ReadShort( msg );

	if ( len < 0 || len > VOIP_MAX_PACKET_BYTES ) {
		// can't resync after a bogus length; skip the rest of this message
		Com_DPrintf( "SV_UserVoip: bad length %i from %s\n", len, cl->name );
		return qfalse;
	}

	for ( int i = 0; i < len; i++ ) {
		packet.data[i] = (byte)MSG_ReadByte( msg );
	}

	if ( !sv_voip->integer || !cl->hasVoip || cl->voipMuted || cl->state != CS_ACTIVE ) {
		return qtrue;
	}
	if ( frames <= 0 || frames > VOIP_MAX_PACKET_FRAMES || len <= 0 ) {
		return qtrue;
	}

	// rate limit
	if ( svs.time - cl->voipBudgetTime >= VOIP_BUDGET_MSEC || svs.time < cl->voipBudgetTime ) {
		cl->voipBudgetTime = svs.time;
		cl->voipBudgetBytes = 0;
	}
	cl->voipBudgetBytes += len;
	if ( cl->voipBudgetBytes > VOIP_BUDGET_BYTES ) {
		return qtrue;
	}

	const playerState_t *senderPs = SV_GameClientNum( sender );
	const qboolean senderGhost = SV_Voip_IsGhost( sender, senderPs );
	const int range = Q_min( Q_max( 0, sv_voipRange->integer ), 32767 );
	const float rangeSquared = (float)range * range;

	packet.sender = sender;
	packet.generation = generation;
	packet.sequence = sequence;
	packet.frames = frames;
	packet.flags = senderGhost ? VOIP_FLAG_NONSPATIAL : 0;
	packet.range = senderGhost ? 0 : range;
	packet.origin[0] = (int)senderPs->origin[0];
	packet.origin[1] = (int)senderPs->origin[1];
	packet.origin[2] = (int)senderPs->origin[2];
	packet.len = len;

	for ( int i = 0; i < sv_maxclients->integer; i++ ) {
		client_t *to = &svs.clients[i];

		if ( i == sender || to->state != CS_ACTIVE || !to->hasVoip ) {
			continue;
		}
		if ( to->netchan.remoteAddress.type == NA_BOT ) {
			continue;
		}

		const playerState_t *toPs = SV_GameClientNum( i );

		if ( senderGhost ) {
			// spectators and the dead only talk among themselves, so they can't call out positions
			if ( !SV_Voip_IsGhost( i, toPs ) ) {
				continue;
			}
		} else if ( range > 0 && DistanceSquared( senderPs->origin, toPs->origin ) > rangeSquared ) {
			// toPs->origin is the followed player's for spectators in follow mode
			continue;
		}

		SV_Voip_Enqueue( to, &packet );
	}

	return qtrue;
}

/*
==================
SV_WriteVoipToClient

svc_voip: [byte sender] [byte generation] [long sequence] [byte frames]
          [byte flags] [short range] [long origin x3] [short len] [len bytes]

Called right before the message goes out, after any server demo copy, so
voice is never recorded into demos.
==================
*/
void SV_WriteVoipToClient( client_t *cl, msg_t *msg ) {
	if ( !cl->hasVoip || !cl->voipQueueCount || cl->state != CS_ACTIVE || msg->overflowed ) {
		return;
	}

	// The demo copy may already have written svc_EOF into the rest of the
	// current byte; Huffman output ORs into it, so clear those bits first.
	if ( !msg->oob && ( msg->bit & 7 ) ) {
		msg->data[msg->bit >> 3] &= (byte)( ( 1 << ( msg->bit & 7 ) ) - 1 );
	}

	while ( cl->voipQueueCount > 0 ) {
		const voipServerPacket_t *packet = &cl->voipQueue[cl->voipQueueHead];

		// Huffman can expand random Opus bytes, so budget generously
		if ( msg->cursize + ( 32 + packet->len ) * 2 + 8 > msg->maxsize ) {
			break;	// rest goes with the next snapshot
		}

		MSG_WriteByte( msg, svc_voip );
		MSG_WriteByte( msg, packet->sender );
		MSG_WriteByte( msg, packet->generation );
		MSG_WriteLong( msg, packet->sequence );
		MSG_WriteByte( msg, packet->frames );
		MSG_WriteByte( msg, packet->flags );
		MSG_WriteShort( msg, packet->range );
		MSG_WriteLong( msg, packet->origin[0] );
		MSG_WriteLong( msg, packet->origin[1] );
		MSG_WriteLong( msg, packet->origin[2] );
		MSG_WriteShort( msg, packet->len );
		MSG_WriteData( msg, packet->data, packet->len );

		cl->voipQueueHead = ( cl->voipQueueHead + 1 ) % VOIP_SERVER_QUEUE;
		cl->voipQueueCount--;
	}
}
