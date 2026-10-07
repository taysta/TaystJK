/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#ifdef JKBOT_AGENT

#include "server/server.h"
#include "jkbot_agent.h"

// The bridge endpoint's address: the socket path the Python bridge connects to (P1-BR-04).
// Set on the command line only; empty means no bridge.
static cvar_t *jkbot_socket;

void JKBot_Init( void ) {
	jkbot_socket = Cvar_Get( "jkbot_socket", "", CVAR_INIT, "JKBot bridge socket path (agent builds only)" );
	Com_Printf( "JKBot agent build (simulator only)\n" );
}

void JKBot_Shutdown( void ) {
}

#endif // JKBOT_AGENT
