/*
 * JKBot static-geometry rays for agent clients (simulator only, P1-ENG-13). See README.md here.
 *
 * After each agent client frame (netsched.cpp, after prediction and the visibility model), the
 * agent's rays are cast from the eye of its predicted playerState (shared/rays.c) with CM traces
 * against the world model only, so no player or other entity can stop one. The bridge sends them
 * in OBS (hit fractions of the ray length).
 *
 * Console commands:
 *   jkbot_rays <count> <length>   the ray count (1..JKB_MAX_RAYS) and length; the simulator sends
 *                                 config/v1.toml's observation.ray_count and ray_length
 *   jkbot_rays_params             prints the count and length
 *   jkbot_rays_agent <client>     the agent's latest rays: eye, yaw and fractions
 *   jkbot_rays_test <x> <y> <z> <yaw>
 *                                 rays cast from that eye, with their directions
 *   jkbot_trace <sx> <sy> <sz> <ex> <ey> <ez> [<pass>]
 *                                 one point trace: the world model with the rays' mask, or with
 *                                 <pass>, the game's trace through entities too (skipping that
 *                                 entity) with MASK_PLAYERSOLID
 */
#ifdef JKBOT_AGENT

#include <stdlib.h>

#include "server/server.h"
#include "qcommon/cm_public.h"
#include "jkbot_agent.h"
#include "jkbot_proto.h"
#include "shared/rays.h"

static int rayCount = 64;
static float rayLength = 1024.0f;

static float rays[MAX_CLIENTS][JKB_MAX_RAYS];
static vec3_t rayEye[MAX_CLIENTS];
static float rayYaw[MAX_CLIENTS];
static qboolean haveRays[MAX_CLIENTS];

static void WorldTrace( trace_t *result, const vec3_t start, const vec3_t end, int mask ) {
	CM_BoxTrace( result, start, end, vec3_origin, vec3_origin, 0, mask, qfalse );
}

// After the agent's client frame, prediction and visibility (netsched.cpp).
void JKBot_RaysAgent( int clientNum ) {
	playerState_t ps;
	haveRays[clientNum] = qfalse;
	if ( !JKBot_Predicted( clientNum, &ps ) ) {
		return;
	}
	JKBRays_Eye( &ps, rayEye[clientNum] );
	rayYaw[clientNum] = ps.viewangles[YAW];
	JKBRays_Cast( rayEye[clientNum], rayYaw[clientNum], rayCount, rayLength, WorldTrace, rays[clientNum] );
	haveRays[clientNum] = qtrue;
}

// The agent's rays after its latest client frame into out (JKB_MAX_RAYS); the count, or 0 if none.
int JKBot_Rays( int clientNum, float *out ) {
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS || !haveRays[clientNum] ) {
		return 0;
	}
	memcpy( out, rays[clientNum], sizeof( float ) * rayCount );
	return rayCount;
}

void JKBot_RaysForget( int clientNum ) {
	haveRays[clientNum] = qfalse;
}

static void JKBot_Rays_f( void ) {
	const int count = atoi( Cmd_Argv( 1 ) );
	const float length = atof( Cmd_Argv( 2 ) );
	if ( Cmd_Argc() != 3 || count < 1 || count > JKB_MAX_RAYS || length <= 0.0f ) {
		Com_Printf( "usage: jkbot_rays <count 1..%d> <length>\n", JKB_MAX_RAYS );
		return;
	}
	rayCount = count;
	rayLength = length;
	memset( haveRays, 0, sizeof( haveRays ) );
	Com_Printf( "jkbot_rays %d %g\n", rayCount, rayLength );
}

static void JKBot_RaysParams_f( void ) {
	Com_Printf( "jkbot_rays_params count %d length %g\n", rayCount, rayLength );
}

static void PrintFractions( const char *head, const float *f, int n ) {
	char line[4096];  // Com_Printf's buffer (MAXPRINTMSG); 192 directions fit
	Q_strncpyz( line, head, sizeof( line ) );
	for ( int i = 0; i < n; i++ ) {
		Q_strcat( line, sizeof( line ), va( " %.9g", f[i] ) );
	}
	Com_Printf( "%s\n", line );
}

static void JKBot_RaysAgent_f( void ) {
	const int c = atoi( Cmd_Argv( 1 ) );
	if ( Cmd_Argc() < 2 || c < 0 || c >= MAX_CLIENTS || !haveRays[c] ) {
		Com_Printf( "jkbot_rays_agent %d none\n", c );
		return;
	}
	PrintFractions( va( "jkbot_rays_agent %d eye %.9g %.9g %.9g yaw %.9g n %d", c, rayEye[c][0], rayEye[c][1],
		rayEye[c][2], rayYaw[c], rayCount ), rays[c], rayCount );
}

static void JKBot_RaysTest_f( void ) {
	if ( Cmd_Argc() < 5 ) {
		Com_Printf( "usage: jkbot_rays_test <x> <y> <z> <yaw>\n" );
		return;
	}
	vec3_t eye;
	float f[JKB_MAX_RAYS], d[JKB_MAX_RAYS * 3];
	VectorSet( eye, atof( Cmd_Argv( 1 ) ), atof( Cmd_Argv( 2 ) ), atof( Cmd_Argv( 3 ) ) );
	const float yaw = atof( Cmd_Argv( 4 ) );
	JKBRays_Cast( eye, yaw, rayCount, rayLength, WorldTrace, f );
	for ( int i = 0; i < rayCount; i++ ) {
		JKBRays_Direction( i, rayCount, yaw, &d[i * 3] );
	}
	PrintFractions( va( "jkbot_rays_test n %d", rayCount ), f, rayCount );
	PrintFractions( "jkbot_rays_dirs", d, rayCount * 3 );
}

static void JKBot_Trace_f( void ) {
	if ( Cmd_Argc() < 7 ) {
		Com_Printf( "usage: jkbot_trace <sx> <sy> <sz> <ex> <ey> <ez> [<pass entity>]\n" );
		return;
	}
	vec3_t start, end;
	trace_t tr;
	VectorSet( start, atof( Cmd_Argv( 1 ) ), atof( Cmd_Argv( 2 ) ), atof( Cmd_Argv( 3 ) ) );
	VectorSet( end, atof( Cmd_Argv( 4 ) ), atof( Cmd_Argv( 5 ) ), atof( Cmd_Argv( 6 ) ) );
	if ( Cmd_Argc() >= 8 ) {
		SV_Trace( &tr, start, vec3_origin, vec3_origin, end, atoi( Cmd_Argv( 7 ) ), MASK_PLAYERSOLID, qfalse, 0, 10 );
	} else {
		WorldTrace( &tr, start, end, JKB_RAYS_MASK );
	}
	Com_Printf( "jkbot_trace %.9g %d %d\n", tr.fraction, tr.entityNum, tr.startsolid );
}

void JKBot_GeometryInit( void ) {
	Cmd_AddCommand( "jkbot_rays", JKBot_Rays_f, "JKBot: static-geometry ray count and length (agent builds only)" );
	Cmd_AddCommand( "jkbot_rays_params", JKBot_RaysParams_f, "JKBot: print the ray count and length (agent builds only)" );
	Cmd_AddCommand( "jkbot_rays_agent", JKBot_RaysAgent_f, "JKBot: an agent's latest rays (agent builds only)" );
	Cmd_AddCommand( "jkbot_rays_test", JKBot_RaysTest_f, "JKBot: rays cast from a given eye (agent builds only)" );
	Cmd_AddCommand( "jkbot_trace", JKBot_Trace_f, "JKBot: one point trace (agent builds only)" );
}

#endif // JKBOT_AGENT
