/*
 * JKBot lockstep mode (simulator only). See README.md in this directory.
 *
 * With jkbot_lockstep 1 the server's clock no longer follows the wall clock: the main loop's
 * SV_Frame calls return at once, and time advances only through STEP. Each STEP is one usercmd
 * period (JKB_USERCMD_MSEC, the 142 fps client of environment.md §2) and runs SV_Frame once with
 * that msec, so the stock code path decides everything else exactly as on a live server: game
 * frames run whenever the residual crosses 1000/sv_fps, SV_BotFrame runs (stock bots think and
 * send their usercmds), timeouts and snapshots follow svs.time. Then each agent client's usercmd
 * runs (agent.cpp). Nothing here sleeps or reads the wall clock.
 *
 * Until the bridge carries STEP (P1-BR-04), the console command `jkbot_step [n]` runs n steps.
 */
#ifdef JKBOT_AGENT

#include "server/server.h"
#include "jkbot_agent.h"

static cvar_t *jkbot_lockstep;
static qboolean stepping;
static int steps;  // since startup
static int virtualMsec;  // steps * JKB_USERCMD_MSEC

qboolean JKBot_Lockstep( void ) {
	return (qboolean)( jkbot_lockstep && jkbot_lockstep->integer );
}

qboolean JKBot_Stepping( void ) {
	return stepping;
}

void JKBot_Step( int n ) {
	if ( !JKBot_Lockstep() ) {
		Com_Printf( "jkbot_step: jkbot_lockstep is 0\n" );
		return;
	}
	if ( !com_sv_running->integer ) {
		Com_Printf( "jkbot_step: no server running\n" );
		return;
	}
	for ( int i = 0; i < n; i++ ) {
		stepping = qtrue;
		SV_Frame( JKB_USERCMD_MSEC );
		stepping = qfalse;
		JKBot_AgentsThink();
		JKBot_ExportStep();
		steps++;
		virtualMsec += JKB_USERCMD_MSEC;
	}
}

int JKBot_Steps( void ) {
	return steps;
}

int JKBot_VirtualMsec( void ) {
	return virtualMsec;
}

static void JKBot_Step_f( void ) {
	int n = Cmd_Argc() > 1 ? atoi( Cmd_Argv( 1 ) ) : 1;
	if ( n < 1 ) {
		Com_Printf( "usage: jkbot_step [n >= 1]\n" );
		return;
	}
	JKBot_Step( n );
}

void JKBot_LockstepInit( void ) {
	jkbot_lockstep = Cvar_Get( "jkbot_lockstep", "0", 0, "JKBot lockstep mode: time advances only on STEP (agent builds only)" );
	Cmd_AddCommand( "jkbot_step", JKBot_Step_f, "JKBot: run n lockstep steps (agent builds only)" );
}

#endif // JKBOT_AGENT
