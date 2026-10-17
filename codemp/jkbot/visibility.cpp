/*
 * JKBot opponent visibility for agent clients (simulator only, P1-ENG-12). See README.md here.
 *
 * After each agent client frame (netsched.cpp, after prediction), the agent's camera follows
 * its predicted playerState (shared/vis.c: the cgame's third-person camera, damped and clipped
 * against the world), and every player in the snapshot it holds is tested with the visibility
 * model: in the frustum with a clear line of sight from the camera to a sample point on its box.
 * The sight geometry is the map's (MASK_OPAQUE world brushes and extra occluding surfaces, minus
 * the shaders a human sees through or never sees), built on first use from the BSP and the lists
 * `jkbot_sight` sets (measurements/sightsurfaces.json; jkbot.sim.server sends them).
 *
 * Console commands:
 *   jkbot_sight clear | mask <contents> | ignore <shader> | occluder <shader>
 *                           one item per line (the stdin console reads 256 bytes at a time)
 *   jkbot_vis <client>      prints the agent's camera and the clients it sees
 *   jkbot_vis_test <x> <y> <z> <pitch> <yaw> <viewheight> <tx> <ty> <tz>
 *                           a fresh camera for a player standing there, and a player box at t
 */
#ifdef JKBOT_AGENT

#include <stdlib.h>
#include <string.h>

#include "server/server.h"
#include "qcommon/cm_public.h"
#include "jkbot_agent.h"
#include "shared/vis.h"

#define JKB_SIGHT_LIST 64

static jkbVisParams_t params;
static jkbVisSight_t sight;
static qboolean sightLoaded;
static int sightMask = MASK_OPAQUE;
static char sightIgnore[JKB_SIGHT_LIST][MAX_QPATH], sightOccluders[JKB_SIGHT_LIST][MAX_QPATH];
static int numIgnore, numOccluders;
static qboolean sightConfigured;

static jkbVisCamera_t cams[MAX_CLIENTS];
static vec3_t camOrg[MAX_CLIENTS], camAngles[MAX_CLIENTS];
static int visibleMask[MAX_CLIENTS];  // clients each agent sees, as of its latest client frame
static qboolean haveView[MAX_CLIENTS];

static void CameraTrace( trace_t *result, const vec3_t start, const vec3_t mins, const vec3_t maxs,
	const vec3_t end, int mask ) {
	// MASK_CAMERACLIP: world brushes (entity brush models would clip too; mp/duel1 has none)
	CM_BoxTrace( result, start, end, mins, maxs, 0, mask, qfalse );
}

static qboolean Sight( void ) {
	const char *map = sv_mapname ? sv_mapname->string : "";
	if ( sightLoaded && !Q_stricmp( sight.map, map ) ) {
		return (qboolean)( sight.numBrushes > 0 );
	}
	JKBVis_FreeSight( &sight );
	sightLoaded = qtrue;
	if ( !sightConfigured ) {
		Com_Printf( "jkbot visibility: no jkbot_sight lists; every MASK_OPAQUE brush blocks sight\n" );
	}
	void *buf = NULL;
	const int len = FS_ReadFile( va( "maps/%s.bsp", map ), &buf );
	if ( len <= 0 || !buf ) {
		Com_Printf( "jkbot visibility: can't read maps/%s.bsp\n", map );
		return qfalse;
	}
	const char *ignore[JKB_SIGHT_LIST], *occluders[JKB_SIGHT_LIST];
	for ( int i = 0; i < numIgnore; i++ ) ignore[i] = sightIgnore[i];
	for ( int i = 0; i < numOccluders; i++ ) occluders[i] = sightOccluders[i];
	const qboolean ok = JKBVis_LoadSight( &sight, map, buf, len, sightMask, ignore, numIgnore,
		occluders, numOccluders );
	FS_FreeFile( buf );
	Com_Printf( "jkbot visibility: %s: %d brushes, %d occluding triangles%s\n", map,
		sight.numBrushes, sight.numTris, ok ? "" : " (bad BSP)" );
	return ok;
}

static void PlayerBox( const entityState_t *es, vec3_t mins, vec3_t maxs ) {
	if ( es->solid && es->solid != SOLID_BMODEL ) {  // the packed box (BG_PlayerStateToEntityState)
		const int x = es->solid & 255, zd = ( es->solid >> 8 ) & 255, zu = ( ( es->solid >> 16 ) & 255 ) - 32;
		VectorSet( mins, -x, -x, -zd );
		VectorSet( maxs, x, x, zu );
	} else {  // a player's default box
		VectorSet( mins, -15, -15, DEFAULT_MINS_2 );
		VectorSet( maxs, 15, 15, DEFAULT_MAXS_2 );
	}
}

// After the agent's client frame and prediction (netsched.cpp).
void JKBot_VisAgent( int clientNum ) {
	playerState_t ps;
	haveView[clientNum] = qfalse;
	visibleMask[clientNum] = 0;
	if ( !JKBot_Predicted( clientNum, &ps ) || !Sight() ) {
		return;
	}
	JKBVis_Camera( &cams[clientNum], &params, &ps, CameraTrace, camOrg[clientNum], camAngles[clientNum] );
	haveView[clientNum] = qtrue;

	client_t *cl = &svs.clients[clientNum];
	const int seq = JKBot_NetHeld( clientNum, NULL );
	if ( seq < 0 || cl->netchan.outgoingSequence - seq > PACKET_BACKUP ) {
		return;
	}
	const clientSnapshot_t *frame = &cl->frames[seq & PACKET_MASK];
	for ( int e = 0; e < frame->num_entities; e++ ) {
		const entityState_t *es = &svs.snapshotEntities[( frame->first_entity + e ) % svs.numSnapshotEntities];
		if ( es->eType != ET_PLAYER || es->number >= MAX_CLIENTS || es->number == clientNum ) {
			continue;
		}
		vec3_t mins, maxs;
		PlayerBox( es, mins, maxs );
		if ( JKBVis_Visible( &sight, &params, camOrg[clientNum], camAngles[clientNum], es->pos.trBase,
				mins, maxs, NULL, NULL ) ) {
			visibleMask[clientNum] |= 1 << es->number;
		}
	}
}

// Whether the agent saw the target client after its latest client frame; -1 if it has no view.
int JKBot_Sees( int clientNum, int target ) {
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS || !haveView[clientNum] || target < 0 || target >= MAX_CLIENTS ) {
		return -1;
	}
	return ( visibleMask[clientNum] >> target ) & 1;
}

void JKBot_VisForget( int clientNum ) {
	JKBVis_CameraReset( &cams[clientNum] );
	haveView[clientNum] = qfalse;
	visibleMask[clientNum] = 0;
}

static void JKBot_Sight_f( void ) {
	const char *what = Cmd_Argv( 1 );
	if ( !Q_stricmp( what, "clear" ) ) {
		sightMask = MASK_OPAQUE;
		numIgnore = numOccluders = 0;
	} else if ( !Q_stricmp( what, "mask" ) && Cmd_Argc() == 3 ) {
		sightMask = atoi( Cmd_Argv( 2 ) );
	} else if ( !Q_stricmp( what, "ignore" ) && Cmd_Argc() == 3 && numIgnore < JKB_SIGHT_LIST ) {
		Q_strncpyz( sightIgnore[numIgnore++], Cmd_Argv( 2 ), MAX_QPATH );
	} else if ( !Q_stricmp( what, "occluder" ) && Cmd_Argc() == 3 && numOccluders < JKB_SIGHT_LIST ) {
		Q_strncpyz( sightOccluders[numOccluders++], Cmd_Argv( 2 ), MAX_QPATH );
	} else {
		Com_Printf( "usage: jkbot_sight clear | mask <contents> | ignore <shader> | occluder <shader>\n" );
		return;
	}
	sightConfigured = qtrue;
	sightLoaded = qfalse;  // rebuilt on next use
	Com_Printf( "jkbot_sight %d %d %d\n", sightMask, numIgnore, numOccluders );
}

static void JKBot_Vis_f( void ) {
	const int c = atoi( Cmd_Argv( 1 ) );
	if ( Cmd_Argc() < 2 || c < 0 || c >= MAX_CLIENTS || !haveView[c] ) {
		Com_Printf( "jkbot_vis %d none\n", c );
		return;
	}
	Com_Printf( "jkbot_vis %d cam %.3f %.3f %.3f %.3f %.3f visible %d\n", c, camOrg[c][0], camOrg[c][1],
		camOrg[c][2], camAngles[c][PITCH], camAngles[c][YAW], visibleMask[c] );
}

static void JKBot_VisTest_f( void ) {
	if ( Cmd_Argc() < 10 ) {
		Com_Printf( "usage: jkbot_vis_test <x> <y> <z> <pitch> <yaw> <viewheight> <tx> <ty> <tz>\n" );
		return;
	}
	if ( !Sight() ) {
		Com_Printf( "jkbot_vis_test no sight geometry\n" );
		return;
	}
	playerState_t ps;
	jkbVisCamera_t cam;
	vec3_t org, ang, target, mins, maxs;
	memset( &ps, 0, sizeof( ps ) );
	JKBVis_CameraReset( &cam );
	VectorSet( ps.origin, atof( Cmd_Argv( 1 ) ), atof( Cmd_Argv( 2 ) ), atof( Cmd_Argv( 3 ) ) );
	VectorSet( ps.viewangles, atof( Cmd_Argv( 4 ) ), atof( Cmd_Argv( 5 ) ), 0 );
	ps.viewheight = atoi( Cmd_Argv( 6 ) );
	ps.standheight = DEFAULT_MAXS_2;
	ps.stats[STAT_HEALTH] = 100;
	ps.commandTime = 1000;
	VectorSet( target, atof( Cmd_Argv( 7 ) ), atof( Cmd_Argv( 8 ) ), atof( Cmd_Argv( 9 ) ) );
	VectorSet( mins, -15, -15, DEFAULT_MINS_2 );
	VectorSet( maxs, 15, 15, DEFAULT_MAXS_2 );
	JKBVis_Camera( &cam, &params, &ps, CameraTrace, org, ang );
	int inView = 0, clear = 0;
	const qboolean vis = JKBVis_Visible( &sight, &params, org, ang, target, mins, maxs, &inView, &clear );
	Com_Printf( "jkbot_vis_test cam %.3f %.3f %.3f %.3f %.3f inview %d clear %d visible %d\n", org[0],
		org[1], org[2], ang[PITCH], ang[YAW], inView, clear, vis );
}

static void JKBot_VisParams_f( void ) {
	Com_Printf( "jkbot_vis_params range %g angle %g vert %g targetdamp %g cameradamp %g camerafps %g fov %.6f %.6f\n",
		params.range, params.angle, params.vertOffset, params.targetDamp, params.cameraDamp,
		params.cameraFPS, params.fovX, params.fovY );
}

void JKBot_VisInit( void ) {
	JKBVis_DefaultParams( &params );
	Cmd_AddCommand( "jkbot_sight", JKBot_Sight_f, "JKBot: the sight geometry's shader lists (agent builds only)" );
	Cmd_AddCommand( "jkbot_vis", JKBot_Vis_f, "JKBot: an agent's camera and the clients it sees (agent builds only)" );
	Cmd_AddCommand( "jkbot_vis_test", JKBot_VisTest_f, "JKBot: the visibility model for a given view (agent builds only)" );
	Cmd_AddCommand( "jkbot_vis_params", JKBot_VisParams_f, "JKBot: the visibility model's camera and FOV (agent builds only)" );
}

#endif // JKBOT_AGENT
