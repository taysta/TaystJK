/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#ifdef JKBOT_AGENT

#include "server/server.h"
#include "jkbot_agent.h"

// The bridge endpoint's address: the socket path the Python bridge connects to (P1-BR-04).
// Empty means no bridge. The generated server cfg sets it (jkbot sim cfg).
static cvar_t *jkbot_bridge;

// Game frames run by SV_Frame since startup (the settle frames of SV_SpawnServer excluded), and
// the time the last one ran at: G_RunFrame sets level.time to exactly this.
static int jkbot_frames;
static int jkbot_gameTime;

// jkbot_status: one machine-readable line for the sim harness.
static void JKBot_Status_f( void ) {
	Com_Printf( "jkbot_status frames=%d sv.time=%d svs.time=%d state=%d game.time=%d residual=%d "
		"lockstep=%d steps=%d virtual=%d step_msec=%d hash=%016llx episode=%d round_start=%d\n",
		jkbot_frames, sv.time, svs.time, (int)sv.state, jkbot_gameTime, sv.timeResidual,
		(int)JKBot_Lockstep(), JKBot_Steps(), JKBot_VirtualMsec(), JKB_USERCMD_MSEC,
		(unsigned long long)JKBot_FrameHash(), JKBot_EpisodeIndex(), JKBot_RoundStart() );
}

// jkbot_clients: one line per connected client (number, state, bot or agent, command time, origin,
// velocity, ground entity, pm_type, known force powers and the three FACEIT-enabled levels, name).
static void JKBot_Clients_f( void ) {
	for ( int i = 0; i < sv_maxclients->integer; i++ ) {
		const client_t *cl = &svs.clients[i];
		if ( cl->state < CS_CONNECTED ) {
			continue;
		}
		const playerState_t *ps = SV_GameClientNum( i );
		char levels[NUM_FORCE_POWERS * 2 + 1] = "";
		for ( int p = 0; p < NUM_FORCE_POWERS; p++ ) {
			Q_strcat( levels, sizeof( levels ), va( p ? ",%d" : "%d", ps->fd.forcePowerLevel[p] ) );
		}
		Com_Printf( "jkbot_client %d state=%d bot=%d agent=%d commandTime=%d origin=%.3f,%.3f,%.3f "
			"velocity=%.3f,%.3f,%.3f groundEntityNum=%d pm_type=%d eFlags=%d forceKnown=%d levitation=%d "
			"saberOffense=%d saberDefense=%d forceLevels=%s name=%s\n", i, (int)cl->state,
			cl->netchan.remoteAddress.type == NA_BOT, (int)JKBot_IsAgent( i ), ps->commandTime,
			ps->origin[0], ps->origin[1], ps->origin[2], ps->velocity[0], ps->velocity[1],
			ps->velocity[2], ps->groundEntityNum, ps->pm_type, ps->eFlags, ps->fd.forcePowersKnown,
			ps->fd.forcePowerLevel[FP_LEVITATION], ps->fd.forcePowerLevel[FP_SABER_OFFENSE],
			ps->fd.forcePowerLevel[FP_SABER_DEFENSE], levels, cl->name );
	}
}

void JKBot_Init( void ) {
	jkbot_bridge = Cvar_Get( "jkbot_bridge", "", 0, "JKBot bridge socket path (agent builds only)" );
	Cmd_AddCommand( "jkbot_status", JKBot_Status_f, "JKBot sim harness status (agent builds only)" );
	Cmd_AddCommand( "jkbot_clients", JKBot_Clients_f, "JKBot sim harness client list (agent builds only)" );
	JKBot_LockstepInit();
	JKBot_AgentInit();
	JKBot_ExportInit();
	JKBot_NetInit();
	JKBot_ResetInit();
	JKBot_CallLogInit();
	Com_Printf( "JKBot agent build (simulator only)\n" );
}

void JKBot_Shutdown( void ) {
}

void JKBot_GameFrame( int gameTime ) {
	jkbot_frames++;
	jkbot_gameTime = gameTime;
	JKBot_HashFrame( gameTime );
}

#endif // JKBOT_AGENT
