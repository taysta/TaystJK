/*
 * Usercmd logger (JKBot P2-CL-02). Records only: no input endpoint, so it may ship in release builds
 * (see README.md). After the hook aufau's jedi_ai branch adds after CL_FinishMove in CL_CreateCmd
 * (JKBot ROADMAP [39]).
 *
 * With `jkbot_cmdlog <path>` set (absolute, or relative to fs_homepath), the client appends to a
 * binary log: every final usercmd as the client built it, and as a secondary stream the raw key and
 * mouse events (turning mouse counts into angles needs the player's sensitivity and m_yaw, so the
 * cvars that govern it are logged too). Writes go to a 64 KB buffer flushed when full, once a
 * second, when the path changes and at exit, so logging adds no disk access to most frames.
 *
 * Layout: little-endian records, each `u8 type, u16 payload size, payload`; readers skip types
 * they don't know. jkbot.demos.cmdlog parses and writes it.
 *   0 session  (when the log is opened)  "JKBCMDLOG" u16 version, then text: "key\tvalue\n" lines
 *              (engine SHA, unix time, the input cvars)
 *   1 usercmd  i32 cmdNumber, i32 serverTime, i32 angles[3], i32 buttons, u8 weapon, u8 forcesel,
 *              u8 invensel, u8 generic_cmd, i8 forwardmove, i8 rightmove, i8 upmove, u8 key
 *              catcher, i32 frame msec, i32 realtime, i32 com_frameTime
 *   2 key      i32 time, i32 key, u8 down, u8 key catcher
 *   3 mouse    i32 time, i32 dx, i32 dy, u8 key catcher
 *   4 cvars    text as in the session record, when an input cvar changes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "client/client.h"

#ifndef DEMO_DUMP_ENGINE_SHA
#define DEMO_DUMP_ENGINE_SHA "unknown"
#endif

#define CMDLOG_VERSION		1
#define CMDLOG_BUFFER		( 64 * 1024 )
#define CMDLOG_FLUSH_MSEC	1000

enum { REC_SESSION, REC_USERCMD, REC_KEY, REC_MOUSE, REC_CVARS };

extern unsigned frame_msec;  // cl_input.cpp

// The cvars that decide how input becomes angles and usercmds.
static const char *inputCvars[] = {
	"sensitivity", "m_yaw", "m_pitch", "m_filter", "cl_mouseAccel", "cl_mouseAccelStyle",
	"cl_mouseAccelOffset", "in_mouse", "cl_yawspeed", "cl_pitchspeed", "cl_anglespeedkey",
	"cl_run", "cl_freelook", "com_maxfps", "cl_maxpackets", "cl_packetdup", "cl_timeNudge",
	"snaps", "rate",
};

static cvar_t	*cmdlog;
static FILE		*logFile;
static char		logPath[MAX_OSPATH];
static byte		buffer[CMDLOG_BUFFER];
static size_t	used;
static int		lastFlush;
static char		cvarsLogged[4096];	// the input cvars as last written

static void Flush( void ) {
	if ( logFile && used ) {
		fwrite( buffer, 1, used, logFile );
		fflush( logFile );
	}
	used = 0;
	lastFlush = Sys_Milliseconds();
}

static void CloseLog( void ) {
	Flush();
	if ( logFile ) {
		fclose( logFile );
		logFile = NULL;
	}
	logPath[0] = '\0';
}

static void Put( const void *data, size_t n ) {
	if ( used + n > sizeof( buffer ) ) {
		Flush();
	}
	memcpy( buffer + used, data, n );  // n is far below the buffer size
	used += n;
}

static void PutI32( int v ) {
	const byte b[4] = { (byte)v, (byte)( v >> 8 ), (byte)( v >> 16 ), (byte)( v >> 24 ) };
	Put( b, 4 );
}

static void PutU8( int v ) {
	const byte b = (byte)v;
	Put( &b, 1 );
}

static void Begin( int type, size_t size ) {
	const byte b[3] = { (byte)type, (byte)size, (byte)( size >> 8 ) };
	if ( used + 3 + size > sizeof( buffer ) ) {
		Flush();  // keep a record in one write
	}
	Put( b, 3 );
}

// "key\tvalue\n" lines of the input cvars ("" for one this client doesn't have).
static void CvarText( char *out, size_t size ) {
	out[0] = '\0';
	for ( size_t i = 0; i < ARRAY_LEN( inputCvars ); i++ ) {
		Q_strcat( out, size, va( "%s\t%s\n", inputCvars[i], Cvar_VariableString( inputCvars[i] ) ) );
	}
}

static void PutText( int type, const char *text ) {
	Begin( type, strlen( text ) );
	Put( text, strlen( text ) );
}

// Opens (or reopens, when the cvar changed) the log; qfalse when logging is off.
static qboolean Ready( void ) {
	if ( !cmdlog ) {
		cmdlog = Cvar_Get( "jkbot_cmdlog", "", CVAR_ARCHIVE, "Usercmd log file (empty: off)" );
		atexit( CloseLog );
	}
	if ( !cmdlog->string[0] ) {
		if ( logFile ) {
			CloseLog();
		}
		return qfalse;
	}
	char path[MAX_OSPATH];
	if ( cmdlog->string[0] == '/' ) {
		Q_strncpyz( path, cmdlog->string, sizeof( path ) );
	} else {
		Q_strncpyz( path, FS_BuildOSPath( Cvar_VariableString( "fs_homepath" ), cmdlog->string ), sizeof( path ) );
	}
	if ( logFile && !strcmp( path, logPath ) ) {
		return qtrue;
	}
	CloseLog();
	FS_CreatePath( path );
	logFile = fopen( path, "ab" );
	if ( !logFile ) {
		Com_Printf( S_COLOR_YELLOW "cmdlog: can't open %s; logging off\n", path );
		Cvar_Set( "jkbot_cmdlog", "" );
		return qfalse;
	}
	Q_strncpyz( logPath, path, sizeof( logPath ) );

	char text[sizeof( cvarsLogged )];
	CvarText( text, sizeof( text ) );
	Q_strncpyz( cvarsLogged, text, sizeof( cvarsLogged ) );
	const char *info = va( "engine\t%s\ntime\t%lld\n", DEMO_DUMP_ENGINE_SHA, (long long)time( NULL ) );
	Begin( REC_SESSION, 9 + 2 + strlen( info ) + strlen( text ) );
	Put( "JKBCMDLOG", 9 );
	PutU8( CMDLOG_VERSION & 0xff );
	PutU8( CMDLOG_VERSION >> 8 );
	Put( info, strlen( info ) );
	Put( text, strlen( text ) );
	Flush();
	return qtrue;
}

static void MaybeFlush( void ) {
	if ( Sys_Milliseconds() - lastFlush >= CMDLOG_FLUSH_MSEC ) {
		Flush();
	}
}

void CL_CmdLogUsercmd( const usercmd_t *cmd ) {
	if ( !Ready() ) {
		return;
	}
	char text[sizeof( cvarsLogged )];
	CvarText( text, sizeof( text ) );
	if ( strcmp( text, cvarsLogged ) ) {
		Q_strncpyz( cvarsLogged, text, sizeof( cvarsLogged ) );
		PutText( REC_CVARS, text );
	}
	Begin( REC_USERCMD, 44 );  // 6 i32, 8 bytes, 3 i32
	PutI32( cl.cmdNumber );
	PutI32( cmd->serverTime );
	for ( int i = 0; i < 3; i++ ) {
		PutI32( cmd->angles[i] );
	}
	PutI32( cmd->buttons );
	PutU8( cmd->weapon );
	PutU8( cmd->forcesel );
	PutU8( cmd->invensel );
	PutU8( cmd->generic_cmd );
	PutU8( cmd->forwardmove );
	PutU8( cmd->rightmove );
	PutU8( cmd->upmove );
	PutU8( Key_GetCatcher() );
	PutI32( (int)frame_msec );
	PutI32( cls.realtime );
	PutI32( com_frameTime );
	MaybeFlush();
}

void CL_CmdLogKey( int key, qboolean down, unsigned time ) {
	if ( !Ready() ) {
		return;
	}
	Begin( REC_KEY, 4 + 4 + 1 + 1 );
	PutI32( (int)time );
	PutI32( key );
	PutU8( down ? 1 : 0 );
	PutU8( Key_GetCatcher() );
	MaybeFlush();
}

void CL_CmdLogMouse( int dx, int dy, int time ) {
	if ( !Ready() ) {
		return;
	}
	Begin( REC_MOUSE, 4 * 3 + 1 );
	PutI32( time );
	PutI32( dx );
	PutI32( dy );
	PutU8( Key_GetCatcher() );
	MaybeFlush();
}
