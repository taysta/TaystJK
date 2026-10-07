/*
 * JKBot agent clients (simulator only). See README.md in this directory.
 *
 * An agent takes a normal (non-bot) client slot, connected engine-side the way SV_DirectConnect
 * connects a remote client: a loopback netchan stands in for the network, GVM_ClientConnect is
 * called with isBot qfalse, then SV_UserinfoChanged and SV_ClientEnterWorld (GVM_ClientBegin).
 * The game module (jampgame) is untouched and sees an ordinary client.
 *
 * Each lockstep STEP, after SV_Frame, every agent's held usercmd becomes one client frame's
 * usercmd; netsched.cpp sends them in the client's packet pattern over the agent's link and, on
 * arrival, gives them to the game through SV_ClientThink (GAME_CLIENT_THINK), then acknowledges
 * snapshots and reliable commands as the client's packet would (else the server drops the
 * client after MAX_RELIABLE_COMMANDS). Command strings go through SV_ExecuteClientCommand
 * (GAME_CLIENT_COMMAND) at once.
 *
 * The agent's name always carries the bot label (ROADMAP System 7; ruleset 6.7, §4.1.2).
 *
 * Console commands until the bridge carries them (P1-BR-04):
 *   jkbot_agent_add <name> <model> <saber1> [saber2]       prints "jkbot_agent <client>"
 *   jkbot_usercmd <client> <forward> <right> <up> <buttons> <angle0> <angle1> [generic_cmd]
 *   jkbot_clientcmd <client> <command...>
 *   jkbot_agent_drop <client>
 */
#ifdef JKBOT_AGENT

#include "server/server.h"
#include "server/sv_gameapi.h"
#include "jkbot_agent.h"

#define JKB_BOT_LABEL "[BOT] "
// The agent's force configuration (userinfo forcepowers: rank-side-levels, one digit per power
// in forcePowers_t order). User ruling: levitation, saber offense and saber defense at 3, every
// other power 0 (the stock client default "7-1-032330000000001333" also had speed, push, pull,
// sight and saber throw, all disabled by the FACEIT mask anyway). The server's disable mask and
// rank limit apply on top; P1-M-03 measures the levels the game grants.
#define JKB_FORCEPOWERS "7-1-030000000000000330"

typedef struct {
	qboolean active;
	usercmd_t cmd;  // held until changed: keys and buttons stay down across STEPs
} jkbAgent_t;

static jkbAgent_t agents[MAX_CLIENTS];

qboolean JKBot_IsAgent( int clientNum ) {
	return (qboolean)( clientNum >= 0 && clientNum < MAX_CLIENTS && agents[clientNum].active );
}

static client_t *AgentClient( const char *arg ) {
	int n = atoi( arg );
	if ( !JKBot_IsAgent( n ) || n >= sv_maxclients->integer ) {
		Com_Printf( "jkbot: %s isn't an agent client\n", arg );
		return NULL;
	}
	return &svs.clients[n];
}

int JKBot_AddAgent( const char *name, const char *model, const char *saber1, const char *saber2 ) {
	if ( !com_sv_running->integer || sv.state != SS_GAME ) {
		Com_Printf( "jkbot_agent_add: no game running\n" );
		return -1;
	}
	int clientNum = -1;
	for ( int i = sv_privateClients->integer; i < sv_maxclients->integer; i++ ) {
		if ( svs.clients[i].state == CS_FREE ) {
			clientNum = i;
			break;
		}
	}
	if ( clientNum < 0 ) {
		Com_Printf( "jkbot_agent_add: server is full\n" );
		return -1;
	}

	char label[MAX_NAME_LENGTH];
	if ( !Q_stricmpn( name, JKB_BOT_LABEL, strlen( JKB_BOT_LABEL ) ) ) {
		Q_strncpyz( label, name, sizeof( label ) );
	} else {
		Com_sprintf( label, sizeof( label ), JKB_BOT_LABEL "%s", name );
	}
	char userinfo[MAX_INFO_STRING] = "";
	Info_SetValueForKey( userinfo, "name", label );
	Info_SetValueForKey( userinfo, "model", model );
	Info_SetValueForKey( userinfo, "saber1", saber1 );
	Info_SetValueForKey( userinfo, "saber2", saber2 );
	Info_SetValueForKey( userinfo, "color1", "4" );
	Info_SetValueForKey( userinfo, "color2", "4" );
	Info_SetValueForKey( userinfo, "forcepowers", JKB_FORCEPOWERS );
	Info_SetValueForKey( userinfo, "sex", "male" );
	Info_SetValueForKey( userinfo, "handicap", "100" );
	Info_SetValueForKey( userinfo, "rate", "90000" );  // ruleset §3.1: at most 90000
	Info_SetValueForKey( userinfo, "snaps", "40" );  // at least sv_fps: every server frame
	Info_SetValueForKey( userinfo, "cg_predictItems", "1" );
	Info_SetValueForKey( userinfo, "ip", "127.0.0.1" );  // not "localhost": no local-client privileges

	// As SV_DirectConnect: a fresh client_t, the netchan, the userinfo, then the game decides.
	client_t *cl = &svs.clients[clientNum];
	Com_Memset( cl, 0, sizeof( *cl ) );
	cl->gentity = SV_GentityNum( clientNum );
	netadr_t adr;
	Com_Memset( &adr, 0, sizeof( adr ) );
	adr.type = NA_LOOPBACK;
	Netchan_Setup( NS_SERVER, &cl->netchan, &adr, 0 );
	Q_strncpyz( cl->userinfo, userinfo, sizeof( cl->userinfo ) );
	const char *denied = GVM_ClientConnect( clientNum, qtrue, qfalse );
	if ( denied ) {
		Com_Printf( "jkbot_agent_add: the game refused the client: %s\n", denied );
		Com_Memset( cl, 0, sizeof( *cl ) );
		return -1;
	}
	SV_UserinfoChanged( cl );
	cl->state = CS_PRIMED;  // what SV_SendClientGameState leaves; there's no gamestate to send
	cl->nextSnapshotTime = svs.time;
	cl->lastPacketTime = svs.time;
	cl->lastConnectTime = svs.time;
	cl->gamestateMessageNum = -1;

	agents[clientNum].active = qtrue;
	Com_Memset( &agents[clientNum].cmd, 0, sizeof( agents[clientNum].cmd ) );
	usercmd_t cmd = agents[clientNum].cmd;
	cmd.serverTime = sv.time + sv.timeResidual;
	SV_ClientEnterWorld( cl, &cmd );
	JKBot_NetReset( clientNum, 0, 0, 100, 1 );  // until jkbot_agent_net or RESET sets the link
	return clientNum;
}

// Stop treating the slot as an agent (before the server drops the client).
void JKBot_AgentForget( int clientNum ) {
	if ( clientNum >= 0 && clientNum < MAX_CLIENTS ) {
		agents[clientNum].active = qfalse;
		JKBot_NetDrop( clientNum );
	}
}

usercmd_t *JKBot_AgentCmd( int clientNum ) {
	return &agents[clientNum].cmd;
}

void JKBot_AgentCmdConsumed( int clientNum ) {
	agents[clientNum].cmd.generic_cmd = 0;  // a one-shot event, like a key press
}

// After each STEP's SV_Frame (lockstep.cpp): drop departed agents, then the agents' client frames
// and packet arrivals (netsched.cpp).
void JKBot_AgentsThink( void ) {
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		if ( agents[i].active && svs.clients[i].state < CS_CONNECTED ) {  // dropped by the game
			agents[i].active = qfalse;
			JKBot_NetDrop( i );
		}
	}
	JKBot_NetStep();
}

static void JKBot_AgentAdd_f( void ) {
	if ( Cmd_Argc() < 4 ) {
		Com_Printf( "usage: jkbot_agent_add <name> <model> <saber1> [saber2]\n" );
		return;
	}
	int n = JKBot_AddAgent( Cmd_Argv( 1 ), Cmd_Argv( 2 ), Cmd_Argv( 3 ), Cmd_Argc() > 4 ? Cmd_Argv( 4 ) : "none" );
	Com_Printf( "jkbot_agent %d\n", n );
}

static void JKBot_Usercmd_f( void ) {
	if ( Cmd_Argc() < 8 ) {
		Com_Printf( "usage: jkbot_usercmd <client> <forward> <right> <up> <buttons> <angle0> <angle1> [generic_cmd]\n" );
		return;
	}
	client_t *cl = AgentClient( Cmd_Argv( 1 ) );
	if ( !cl ) {
		return;
	}
	usercmd_t *cmd = &agents[cl - svs.clients].cmd;
	cmd->forwardmove = (signed char)atoi( Cmd_Argv( 2 ) );
	cmd->rightmove = (signed char)atoi( Cmd_Argv( 3 ) );
	cmd->upmove = (signed char)atoi( Cmd_Argv( 4 ) );
	cmd->buttons = atoi( Cmd_Argv( 5 ) );
	cmd->angles[0] = atoi( Cmd_Argv( 6 ) );
	cmd->angles[1] = atoi( Cmd_Argv( 7 ) );
	cmd->generic_cmd = Cmd_Argc() > 8 ? (byte)atoi( Cmd_Argv( 8 ) ) : 0;
}

static void JKBot_ClientCmd_f( void ) {
	if ( Cmd_Argc() < 3 ) {
		Com_Printf( "usage: jkbot_clientcmd <client> <command...>\n" );
		return;
	}
	client_t *cl = AgentClient( Cmd_Argv( 1 ) );
	if ( cl ) {
		SV_ExecuteClientCommand( cl, Cmd_ArgsFrom( 2 ), qtrue );
	}
}

static void JKBot_AgentDrop_f( void ) {
	client_t *cl = Cmd_Argc() > 1 ? AgentClient( Cmd_Argv( 1 ) ) : NULL;
	if ( cl ) {
		SV_DropClient( cl, "left" );
		agents[cl - svs.clients].active = qfalse;
		JKBot_NetDrop( cl - svs.clients );
	}
}

void JKBot_AgentInit( void ) {
	Cmd_AddCommand( "jkbot_agent_add", JKBot_AgentAdd_f, "JKBot: connect an agent client (agent builds only)" );
	Cmd_AddCommand( "jkbot_usercmd", JKBot_Usercmd_f, "JKBot: set an agent's held usercmd (agent builds only)" );
	Cmd_AddCommand( "jkbot_clientcmd", JKBot_ClientCmd_f, "JKBot: run a client command for an agent (agent builds only)" );
	Cmd_AddCommand( "jkbot_agent_drop", JKBot_AgentDrop_f, "JKBot: drop an agent client (agent builds only)" );
}

#endif // JKBOT_AGENT
