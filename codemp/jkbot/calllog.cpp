/*
 * JKBot game call log (simulator only). See README.md in this directory.
 *
 * Logs the game module's trace and Ghoul2 collision syscalls together with the game entry point
 * they're made from, so a measurement can tell whether saber collision runs once per usercmd
 * (inside GAME_CLIENT_THINK) or once per server frame (inside GAME_RUN_FRAME) (P1-M-COLL). It only
 * reads the syscall arguments; nothing the game sees changes.
 *
 *   jkbot_calllog <path> | stop
 *
 * One line per event:
 *   F <levelTime>                 GAME_RUN_FRAME entered        f   left
 *   T <client> <cmd.serverTime>   GAME_CLIENT_THINK entered     t   left
 *   C <call> <a> <b>              a syscall, inside the innermost open entry (or none)
 * with calls
 *   trace / g2trace / capsule     G_TRACE / G_G2TRACE / G_TRACECAPSULE: a = passEntityNum,
 *                                 b = contentmask
 *   g2col / g2colc                G_G2_COLLISIONDETECT(CACHE): a = the entity tested, b = frameNumber
 *   bolt                          G_G2_GETBOLT(_NOREC(_NOROT)): a = modelIndex, b = boltIndex
 */
#ifdef JKBOT_AGENT

#include <stdio.h>

#include "server/server.h"
#include "jkbot_agent.h"

static FILE *calllog;

void JKBot_CallLogEnter( char kind, int a, int b ) {
	if ( !calllog ) {
		return;
	}
	if ( kind == 'T' ) {
		fprintf( calllog, "T %d %d\n", a, b );
	} else {
		fprintf( calllog, "%c %d\n", kind, a );
	}
}

void JKBot_CallLogLeave( char kind ) {
	if ( calllog ) {
		fprintf( calllog, "%c\n", kind );
	}
}

void JKBot_CallLogSyscall( const intptr_t *args ) {
	if ( !calllog ) {
		return;
	}
	const char *name;
	int a, b;
	switch ( args[0] ) {
	case G_TRACE: name = "trace"; a = (int)args[6]; b = (int)args[7]; break;
	case G_G2TRACE: name = "g2trace"; a = (int)args[6]; b = (int)args[7]; break;
	case G_TRACECAPSULE: name = "capsule"; a = (int)args[6]; b = (int)args[7]; break;
	case G_G2_COLLISIONDETECT: name = "g2col"; a = (int)args[6]; b = (int)args[5]; break;
	case G_G2_COLLISIONDETECTCACHE: name = "g2colc"; a = (int)args[6]; b = (int)args[5]; break;
	case G_G2_GETBOLT:
	case G_G2_GETBOLT_NOREC:
	case G_G2_GETBOLT_NOREC_NOROT: name = "bolt"; a = (int)args[2]; b = (int)args[3]; break;
	default: return;
	}
	fprintf( calllog, "C %s %d %d\n", name, a, b );
}

static void JKBot_CallLog_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_calllog <path> | stop\n" );
		return;
	}
	if ( calllog ) {
		fclose( calllog );
		calllog = NULL;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		Com_Printf( "jkbot_calllog stopped\n" );
		return;
	}
	calllog = fopen( Cmd_Argv( 1 ), "w" );
	Com_Printf( calllog ? "jkbot_calllog started\n" : "jkbot_calllog: can't open the file\n" );
}

void JKBot_CallLogInit( void ) {
	Cmd_AddCommand( "jkbot_calllog", JKBot_CallLog_f, "JKBot: log the game's trace and Ghoul2 collision calls (agent builds only)" );
}

#endif // JKBOT_AGENT
