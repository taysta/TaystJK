/*
 * JKBot own-state prediction (simulator only, P1-ENG-11). See README.md in this directory.
 *
 * Each agent client predicts its own playerState as a human client's cgame does
 * (CG_PredictPlayerState): from the snapshot it holds (netsched.cpp), Pmove over its usercmds
 * that snapshot hasn't run yet (later than ps.commandTime), after every client frame. The
 * movement code is the cgame's own bg_* build in libjkbpredict.so (predict/jkbpredict.h),
 * loaded with RTLD_LOCAL from the server binary's directory, so it shares no symbols with the
 * game module, and the game's mechanics stay in jampgame. Collision uses the server's collision
 * map (the same BSP the client loads) and the held snapshot's solid entities, as CG_Trace does.
 *
 * Console command:
 *   jkbot_predlog <path> | stop   per agent usercmd n: the predicted playerState right after the
 *                                 client frame that created it (Q), and the authoritative one
 *                                 right after the server ran it (A)
 */
#ifdef JKBOT_AGENT

#include <dlfcn.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "server/server.h"
#include "server/sv_gameapi.h"
#include "qcommon/cm_public.h"
#include "jkbot_agent.h"
#include "predict/jkbpredict.h"

#define JKB_SNAP_ENTITIES 256  // the client's MAX_ENTITIES_IN_SNAPSHOT (cg_public.h)
// usercmds offered to Predict, newest last; it runs those later than the snapshot's commandTime,
// which at 8 ms and pings up to ~400 ms are fewer than this
#define JKB_PRED_CMDS 64

static const jkbpAPI_t *api;
static qboolean loadFailed;
static playerState_t predicted[MAX_CLIENTS];
static qboolean havePredicted[MAX_CLIENTS];
static char clientSabers[MAX_CLIENTS][2][64];
static FILE *predlog;

static void HostPrint( const char *msg ) {
	Com_Printf( "%s", msg );
}

static void HostError( const char *msg ) {
	Com_Error( ERR_DROP, "jkbpredict: %s", msg );
}

static int HostMilliseconds( void ) {
	return Sys_Milliseconds();
}

static const char *HostConfigString( int index ) {
	if ( index < 0 || index >= MAX_CONFIGSTRINGS || !sv.configstrings[index] ) {
		return "";
	}
	return sv.configstrings[index];
}

static jkbpHost_t host = {
	JKBP_API_VERSION,
	(int)sizeof( playerState_t ), (int)sizeof( entityState_t ), (int)sizeof( usercmd_t ), (int)sizeof( trace_t ),
	HostPrint, HostError, HostMilliseconds, Sys_SnapVector,
	FS_FOpenFileByMode, FS_Read, FS_FCloseFile, FS_GetFileList,
	CM_InlineModel, CM_TempBoxModel, CM_PointContents, CM_TransformedPointContents,
	CM_BoxTrace, CM_TransformedBoxTrace,
	HostConfigString,
};

static qboolean Load( void ) {
	if ( api || loadFailed ) {
		return (qboolean)( api != NULL );
	}
	loadFailed = qtrue;
	char exe[PATH_MAX], path[PATH_MAX];
	const ssize_t n = readlink( "/proc/self/exe", exe, sizeof( exe ) - 1 );
	if ( n <= 0 ) {
		Com_Printf( "jkbpredict: can't find the server binary's directory\n" );
		return qfalse;
	}
	exe[n] = 0;
	char *slash = strrchr( exe, '/' );
	if ( slash ) {
		*slash = 0;
	}
	Com_sprintf( path, sizeof( path ), "%s/libjkbpredict.so", exe );
	void *lib = dlopen( path, RTLD_NOW | RTLD_LOCAL );
	if ( !lib ) {
		Com_Printf( "jkbpredict: %s\n", dlerror() );
		return qfalse;
	}
	jkbpGetAPI_t getAPI = (jkbpGetAPI_t)dlsym( lib, JKBP_GETAPI );
	const jkbpAPI_t *a = getAPI ? getAPI( JKBP_API_VERSION ) : NULL;
	if ( !a || !a->Init( &host ) ) {
		Com_Printf( "jkbpredict: %s didn't initialise\n", path );
		dlclose( lib );
		return qfalse;
	}
	api = a;
	loadFailed = qfalse;
	Com_Printf( "jkbpredict: loaded %s\n", path );
	return qtrue;
}

static void LogPS( char kind, int clientNum, int cmdNum, const playerState_t *ps ) {
	if ( !predlog ) {
		return;
	}
	fprintf( predlog, "%c %d %d %d %.9g %.9g %.9g %.9g %.9g %.9g %d %d %d %d %d %d %d %d %d %d %d %.9g\n",
		kind, clientNum, cmdNum, ps->commandTime, ps->origin[0], ps->origin[1], ps->origin[2],
		ps->velocity[0], ps->velocity[1], ps->velocity[2], ps->groundEntityNum, ps->pm_type,
		ps->pm_flags, ps->pm_time, ps->legsAnim, ps->torsoAnim, ps->saberMove, ps->weaponTime,
		ps->fd.forcePower, ps->legsTimer, ps->torsoTimer, ps->viewangles[YAW] );
}

// After the client frame that created usercmd cmdNum (netsched.cpp).
void JKBot_PredictAgent( int clientNum, int cmdNum ) {
	havePredicted[clientNum] = qfalse;
	if ( !Load() ) {
		return;
	}
	client_t *cl = &svs.clients[clientNum];
	int serverTime;
	const int seq = JKBot_NetHeld( clientNum, &serverTime );
	if ( cl->state < CS_ACTIVE || seq < 0 || cl->netchan.outgoingSequence - seq > PACKET_BACKUP ) {
		return;
	}
	const clientSnapshot_t *frame = &cl->frames[seq & PACKET_MASK];
	static entityState_t ents[JKB_SNAP_ENTITIES];
	const int numEnts = frame->num_entities < JKB_SNAP_ENTITIES ? frame->num_entities : JKB_SNAP_ENTITIES;
	for ( int e = 0; e < numEnts; e++ ) {
		ents[e] = svs.snapshotEntities[( frame->first_entity + e ) % svs.numSnapshotEntities];
	}
	// the client's sabers, as its cgame parses them from the userinfo it sees
	const char *s1 = Info_ValueForKey( cl->userinfo, "saber1" );
	const char *s2 = Info_ValueForKey( cl->userinfo, "saber2" );
	if ( Q_stricmp( s1, clientSabers[clientNum][0] ) || Q_stricmp( s2, clientSabers[clientNum][1] ) ) {
		Q_strncpyz( clientSabers[clientNum][0], s1, sizeof( clientSabers[clientNum][0] ) );
		Q_strncpyz( clientSabers[clientNum][1], s2, sizeof( clientSabers[clientNum][1] ) );
		api->SetClient( clientNum, s1, s2 );
	}
	static usercmd_t cmds[JKB_PRED_CMDS];
	const int numCmds = JKBot_NetRecentCmds( clientNum, cmds, JKB_PRED_CMDS );
	api->SetServerInfo();
	api->SetSnapshot( serverTime, &frame->ps, ents, numEnts );
	api->Predict( cmds, numCmds, &predicted[clientNum] );
	havePredicted[clientNum] = qtrue;
	LogPS( 'Q', clientNum, cmdNum, &predicted[clientNum] );
}

// After the server ran the agent's usercmd cmdNum (netsched.cpp).
void JKBot_PredictAuthoritative( int clientNum, int cmdNum ) {
	if ( predlog ) {
		LogPS( 'A', clientNum, cmdNum, SV_GameClientNum( clientNum ) );
	}
}

// The agent's predicted playerState after its latest client frame; qfalse if there's none.
qboolean JKBot_Predicted( int clientNum, playerState_t *out ) {
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS || !havePredicted[clientNum] ) {
		return qfalse;
	}
	*out = predicted[clientNum];
	return qtrue;
}

void JKBot_PredictForget( int clientNum ) {
	havePredicted[clientNum] = qfalse;
	clientSabers[clientNum][0][0] = clientSabers[clientNum][1][0] = 0;
}

static void JKBot_PredLog_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_predlog <path> | stop\n" );
		return;
	}
	if ( predlog ) {
		fclose( predlog );
		predlog = NULL;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		Com_Printf( "jkbot_predlog stopped\n" );
		return;
	}
	predlog = fopen( Cmd_Argv( 1 ), "w" );
	Com_Printf( predlog ? "jkbot_predlog started\n" : "jkbot_predlog: can't open the file\n" );
}

void JKBot_PredictInit( void ) {
	Cmd_AddCommand( "jkbot_predlog", JKBot_PredLog_f, "JKBot: log agents' predicted and authoritative playerStates (agent builds only)" );
}

#endif // JKBOT_AGENT
