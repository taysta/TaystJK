/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#ifdef JKBOT_AGENT

#include "server/server.h"
#include "jkbot_agent.h"

// The bridge endpoint's address: the socket path the Python bridge connects to (P1-BR-04).
// Empty means no bridge. The generated server cfg sets it (jkbot sim cfg).
static cvar_t *jkbot_bridge;

// Game frames run by SV_Frame since startup (the settle frames of SV_SpawnServer excluded).
static int jkbot_frames;

// jkbot_status: one machine-readable line for the sim harness.
static void JKBot_Status_f( void ) {
	Com_Printf( "jkbot_status frames=%d sv.time=%d svs.time=%d state=%d\n", jkbot_frames, sv.time,
		svs.time, (int)sv.state );
}

void JKBot_Init( void ) {
	jkbot_bridge = Cvar_Get( "jkbot_bridge", "", 0, "JKBot bridge socket path (agent builds only)" );
	Cmd_AddCommand( "jkbot_status", JKBot_Status_f, "JKBot sim harness status (agent builds only)" );
	Com_Printf( "JKBot agent build (simulator only)\n" );
}

void JKBot_Shutdown( void ) {
}

void JKBot_GameFrame( void ) {
	jkbot_frames++;
}

#endif // JKBOT_AGENT
