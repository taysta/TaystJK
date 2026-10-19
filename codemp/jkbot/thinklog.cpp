/*
 * JKBot think log (simulator only). See README.md in this directory.
 *
 * Logs every usercmd the game module receives for a client, at GAME_CLIENT_THINK (GVM_ClientThink:
 * the client's lastUsercmd, which the game reads with trap_GetUsercmd), in the usercmd logger's
 * format (record/cmdlog.cpp, jkbot.demos.cmdlog), so the stock-bot ground-truth dataset (P2-LBL-01)
 * pairs each svrecord demo with the usercmds behind it. It only reads; nothing the game sees changes.
 *
 *   jkbot_thinklog <client> <path>    start (a new file) for one client
 *   jkbot_thinklog <client> stop      stop one client's log
 *   jkbot_thinklog stop               stop every log
 *
 * Records (little-endian `u8 type, u16 payload size, payload`, as the client's log):
 *   0 session  "JKBCMDLOG" u16 version, then "key\tvalue\n" text: source (server_think), client,
 *              name, bot (1 for a stock bot), step_msec, sv_fps
 *   1 usercmd  as the client's, with cmdNumber the count of thinks since the log opened, key
 *              catcher 0, frame msec the STEP's msec (jkbot_step_msec: an agent's Pmove step),
 *              realtime sv.time at the call and com_frameTime sv.time + sv.timeResidual (the
 *              lockstep clock)
 *   5 frame    i32 levelTime: GAME_RUN_FRAME is about to run at levelTime. A stock bot's Pmove runs
 *              there (G_RunClient) on its latest usercmd with serverTime set to levelTime; an agent
 *              runs Pmove inside GAME_CLIENT_THINK on each usercmd (ClientThink_real)
 */
#ifdef JKBOT_AGENT

#include <stdio.h>

#include "server/server.h"
#include "jkbot_agent.h"

#define THINKLOG_VERSION	1
#define THINKLOG_BUFFER		( 256 * 1024 )

enum { REC_SESSION = 0, REC_USERCMD = 1, REC_FRAME = 5 };

typedef struct {
	FILE *f;
	int count;  // thinks logged
} thinkLog_t;

static thinkLog_t logs[MAX_CLIENTS];
static int numOpen;

static void PutI32( FILE *f, int v ) {
	const byte b[4] = { (byte)v, (byte)( v >> 8 ), (byte)( v >> 16 ), (byte)( v >> 24 ) };
	fwrite( b, 1, 4, f );
}

static void PutU8( FILE *f, int v ) {
	const byte b = (byte)v;
	fwrite( &b, 1, 1, f );
}

static void Begin( FILE *f, int type, size_t size ) {
	const byte b[3] = { (byte)type, (byte)size, (byte)( size >> 8 ) };
	fwrite( b, 1, 3, f );
}

static void Close( int clientNum ) {
	if ( logs[clientNum].f ) {
		fclose( logs[clientNum].f );
		logs[clientNum].f = NULL;
		numOpen--;
	}
}

void JKBot_ThinkLogUsercmd( int clientNum ) {
	if ( !numOpen || clientNum < 0 || clientNum >= MAX_CLIENTS || !logs[clientNum].f ) {
		return;
	}
	FILE *f = logs[clientNum].f;
	const usercmd_t *cmd = &svs.clients[clientNum].lastUsercmd;
	Begin( f, REC_USERCMD, 44 );  // 6 i32, 8 bytes, 3 i32
	PutI32( f, logs[clientNum].count++ );
	PutI32( f, cmd->serverTime );
	for ( int i = 0; i < 3; i++ ) {
		PutI32( f, cmd->angles[i] );
	}
	PutI32( f, cmd->buttons );
	PutU8( f, cmd->weapon );
	PutU8( f, cmd->forcesel );
	PutU8( f, cmd->invensel );
	PutU8( f, cmd->generic_cmd );
	PutU8( f, cmd->forwardmove );
	PutU8( f, cmd->rightmove );
	PutU8( f, cmd->upmove );
	PutU8( f, 0 );
	PutI32( f, JKBot_StepMsec() );
	PutI32( f, sv.time );
	PutI32( f, sv.time + sv.timeResidual );
}

void JKBot_ThinkLogFrame( int levelTime ) {
	if ( !numOpen ) {
		return;
	}
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		if ( logs[i].f ) {
			Begin( logs[i].f, REC_FRAME, 4 );
			PutI32( logs[i].f, levelTime );
		}
	}
}

static void JKBot_ThinkLog_f( void ) {
	if ( Cmd_Argc() == 2 && !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		for ( int i = 0; i < MAX_CLIENTS; i++ ) {
			Close( i );
		}
		Com_Printf( "jkbot_thinklog stopped\n" );
		return;
	}
	if ( Cmd_Argc() != 3 ) {
		Com_Printf( "usage: jkbot_thinklog <client> <path> | <client> stop | stop\n" );
		return;
	}
	const int c = atoi( Cmd_Argv( 1 ) );
	if ( c < 0 || c >= sv_maxclients->integer || c >= MAX_CLIENTS ) {
		Com_Printf( "usage: jkbot_thinklog <client> <path> | <client> stop | stop\n" );
		return;
	}
	Close( c );
	if ( !Q_stricmp( Cmd_Argv( 2 ), "stop" ) ) {
		Com_Printf( "jkbot_thinklog %d stopped\n", c );
		return;
	}
	FILE *f = fopen( Cmd_Argv( 2 ), "wb" );
	if ( !f ) {
		Com_Printf( "jkbot_thinklog %d: can't open the file\n", c );
		return;
	}
	setvbuf( f, NULL, _IOFBF, THINKLOG_BUFFER );
	const client_t *cl = &svs.clients[c];
	const char *info = va( "source\tserver_think\nclient\t%d\nname\t%s\nbot\t%d\nstep_msec\t%d\nsv_fps\t%d\n", c,
		cl->name, cl->netchan.remoteAddress.type == NA_BOT, JKBot_StepMsec(), sv_fps->integer );
	Begin( f, REC_SESSION, 9 + 2 + strlen( info ) );
	fwrite( "JKBCMDLOG", 1, 9, f );
	PutU8( f, THINKLOG_VERSION & 0xff );
	PutU8( f, THINKLOG_VERSION >> 8 );
	fwrite( info, 1, strlen( info ), f );
	logs[c].f = f;
	logs[c].count = 0;
	numOpen++;
	Com_Printf( "jkbot_thinklog %d started\n", c );
}

void JKBot_ThinkLogInit( void ) {
	Cmd_AddCommand( "jkbot_thinklog", JKBot_ThinkLog_f, "JKBot: log the usercmds the game receives for a client (agent builds only)" );
}

#endif // JKBOT_AGENT
