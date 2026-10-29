/*
 * JKBot episode reset (simulator only). See README.md in this directory.
 *
 * RESET (jkb_reset_t) starts a new round through the game's normal paths:
 *   1. every agent and stock bot is dropped (SV_DropClient), so no session data (Duel wins and
 *      losses survive a map_restart) carries into the episode; agent slots are freed at once (no
 *      zombie state), so an episode's agents always take the same slots;
 *   2. fraglimit / timelimit are set when the message gives them;
 *   3. the seed: jkbot_seed (G_InitGame's randomSeed, export.cpp) and srand( seed ) for the
 *      engine's libc rand(), which the game module and the botlib share;
 *   4. map_restart 0: the game module restarts and seeds itself from randomSeed; the lockstep
 *      residual is zeroed so every episode starts on a server-frame boundary, and a finished
 *      round's CS_INTERMISSION is cleared;
 *   5. the agents connect as clients (agent.cpp) with the episode's name, model and hilt
 *      (userinfo) and link (netsched.cpp);
 *   6. the opponent: a stock bot joins through the game's addbot (profile and skill), its model and
 *      hilt then set in its userinfo (GVM_ClientUserinfoChanged), and its scripted chat windows
 *      armed: during each, the talk button is held in its usercmds, as a human opening the chat;
 *   7. demo-state starts (P4-DSR-01): a client whose setup has an active start is put there once
 *      it has spawned (in Duel a joining client is a spectator until the game's CheckTournament
 *      makes it a duelist and spawns it, in a later game frame: so the start waits, checked
 *      after every game frame, JKBot_ResetGameFrame, and is dropped with a warning if the client
 *      hasn't spawned within JKB_START_WAIT_MS): its playerState takes the start's origin, velocity and view (the view
 *      through delta_angles, as the game's SetClientViewAngle does, so its usercmds' angles keep
 *      steering from there), the teleport bit toggles (no lerp), and its entity follows and is
 *      relinked so the first snapshot shows it there. Health and every other game state stay as
 *      spawned. This isn't a game path (the game's setviewpos needs cheats and throws the player
 *      out at 400 u/s); it changes no physics or combat.
 * Between frags the game respawns players itself; the engine does nothing.
 *
 * Console commands:
 *   jkbot_reset <path>   a jkb_reset_t read from the file; prints
 *                        "jkbot_reset <episode> agents <client...> bot <client>" (until the bridge
 *                        carries RESET, P1-BR-04)
 *   jkbot_botcmdlog <path> | stop
 *                        every stock-bot usercmd as the server gets it, one line each: sv.time,
 *                        client, serverTime, angles[3], buttons, forward, right, up, weapon,
 *                        generic_cmd (parity diagnosis: the game's AI makes them, P1-REB-02)
 */
#ifdef JKBOT_AGENT

#include <stdio.h>
#include <stdlib.h>

#include "server/server.h"
#include "server/sv_gameapi.h"
#include "jkbot_agent.h"
#include "jkbot_proto.h"

#define JKB_DEFAULT_BOT			"Tavion"	// when RESET names no profile
#define JKB_EF_TELEPORT_BIT		( 1 << 3 )	// bg_public.h: toggled when the origin jumps
#define JKB_PM_NORMAL			0			// bg_public.h pmtype_t
#define JKB_STAT_HEALTH			0			// bg_public.h statIndex_t
#define JKB_START_WAIT_MS		2000

typedef struct {
	int client;
	jkb_start_t start;
} pendingStart_t;
static pendingStart_t pending[JKB_MAX_AGENTS + 1];
static int numPending;
static int pendingSince;  // sv.time when the starts were queued
#define JKB_DEFAULT_BOT_SKILL	4.0f		// the Phase 1 gate's skill-4 stock bot

static int episodeIndex = -1;
static int roundStart;  // sv.time when the episode's round started
static int chatBot = -1;
static int numChat;
static jkb_chat_event_t chat[JKB_MAX_CHAT_EVENTS];
static FILE *botCmdLog;

static void FixedString( char *out, size_t size, const char *in, size_t inSize ) {
	size_t n = 0;
	while ( n < inSize && in[n] ) {
		n++;
	}
	if ( n >= size ) {
		n = size - 1;
	}
	memcpy( out, in, n );
	out[n] = 0;
}

static void SetUserinfoKey( int clientNum, const char *key, const char *value ) {
	if ( !value[0] ) {
		return;
	}
	client_t *cl = &svs.clients[clientNum];
	Info_SetValueForKey( cl->userinfo, key, value );
	SV_UserinfoChanged( cl );
	GVM_ClientUserinfoChanged( clientNum );
}

static void LogBotCmd( int clientNum, const usercmd_t *cmd ) {
	if ( botCmdLog ) {
		fprintf( botCmdLog, "%d %d %d %d %d %d %d %d %d %d %d %d\n", sv.time, clientNum, cmd->serverTime,
			cmd->angles[0], cmd->angles[1], cmd->angles[2], cmd->buttons, cmd->forwardmove,
			cmd->rightmove, cmd->upmove, cmd->weapon, cmd->generic_cmd );
	}
}

// The talk button during the stock bot's scripted chat windows (BOTLIB_USER_COMMAND).
void JKBot_BotUsercmd( int clientNum, usercmd_t *cmd ) {
	if ( clientNum == chatBot && numChat ) {
		const int t = sv.time - roundStart;
		for ( int i = 0; i < numChat; i++ ) {
			if ( t >= chat[i].start_ms && t < chat[i].start_ms + chat[i].duration_ms ) {
				cmd->buttons |= BUTTON_TALK;
				break;
			}
		}
	}
	LogBotCmd( clientNum, cmd );
}

int JKBot_EpisodeIndex( void ) {
	return episodeIndex;
}

int JKBot_RoundStart( void ) {
	return roundStart;
}

static void QueueStart( int clientNum, const jkb_start_t *st ) {
	if ( clientNum >= 0 && st->active && numPending < JKB_MAX_AGENTS + 1 ) {
		pending[numPending].client = clientNum;
		pending[numPending].start = *st;
		numPending++;
	}
}

static void ApplyStart( int clientNum, const jkb_start_t *st ) {
	playerState_t *ps = (playerState_t *)SV_GameClientNum( clientNum );
	const usercmd_t *cmd = JKBot_IsAgent( clientNum ) ? JKBot_AgentCmd( clientNum )
		: &svs.clients[clientNum].lastUsercmd;
	const vec3_t view = { st->angles[0], st->angles[1], 0.0f };
	for ( int i = 0; i < 3; i++ ) {
		ps->origin[i] = st->origin[i];
		ps->velocity[i] = st->velocity[i];
		ps->viewangles[i] = view[i];
		ps->delta_angles[i] = ANGLE2SHORT( view[i] ) - cmd->angles[i];
	}
	ps->eFlags ^= JKB_EF_TELEPORT_BIT;
	sharedEntity_t *ent = SV_GentityNum( clientNum );
	VectorCopy( ps->origin, ent->r.currentOrigin );
	VectorCopy( ps->origin, ent->s.pos.trBase );
	VectorCopy( ps->velocity, ent->s.pos.trDelta );
	VectorCopy( view, ent->s.apos.trBase );
	ent->s.eFlags ^= JKB_EF_TELEPORT_BIT;
	SV_LinkEntity( ent );
}

void JKBot_ResetGameFrame( void ) {
	int kept = 0;
	for ( int i = 0; i < numPending; i++ ) {
		const playerState_t *ps = SV_GameClientNum( pending[i].client );
		if ( ps->pm_type == JKB_PM_NORMAL && ps->stats[JKB_STAT_HEALTH] > 0 ) {
			ApplyStart( pending[i].client, &pending[i].start );
		} else if ( sv.time - pendingSince < JKB_START_WAIT_MS ) {
			pending[kept++] = pending[i];
		} else {
			Com_Printf( "jkbot_reset: client %d didn't spawn within %d ms: its start is dropped\n",
				pending[i].client, JKB_START_WAIT_MS );
		}
	}
	numPending = kept;
}

static int AddStockBot( const jkb_agent_setup_t *setup, float skill ) {
	char name[JKB_NAME_LEN + 1];
	FixedString( name, sizeof( name ), setup->name, sizeof( setup->name ) );
	if ( !name[0] ) {
		Q_strncpyz( name, JKB_DEFAULT_BOT, sizeof( name ) );
	}
	if ( skill <= 0.0f ) {
		skill = JKB_DEFAULT_BOT_SKILL;
	}
	qboolean before[MAX_CLIENTS];
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		before[i] = (qboolean)( svs.clients[i].state >= CS_CONNECTED );
	}
	Cmd_ExecuteString( va( "addbot \"%s\" %g", name, skill ) );
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		if ( !before[i] && svs.clients[i].state >= CS_CONNECTED &&
			svs.clients[i].netchan.remoteAddress.type == NA_BOT ) {
			char model[JKB_NAME_LEN + 1], saber1[JKB_NAME_LEN + 1];
			FixedString( model, sizeof( model ), setup->model, sizeof( setup->model ) );
			FixedString( saber1, sizeof( saber1 ), setup->saber1, sizeof( setup->saber1 ) );
			SetUserinfoKey( i, "model", model );
			SetUserinfoKey( i, "saber1", saber1 );
			return i;
		}
	}
	Com_Printf( "jkbot_reset: addbot %s didn't connect a bot\n", name );
	return -1;
}

qboolean JKBot_Reset( const jkb_reset_t *r, int *agentClients, int *botClient ) {
	if ( !com_sv_running->integer || sv.state != SS_GAME ) {
		Com_Printf( "jkbot_reset: no game running\n" );
		return qfalse;
	}
	if ( r->num_agents < 0 || r->num_agents > JKB_MAX_AGENTS ) {
		Com_Printf( "jkbot_reset: bad num_agents %d\n", r->num_agents );
		return qfalse;
	}
	// 1. everyone out: no session data carries over
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		client_t *cl = &svs.clients[i];
		if ( cl->state >= CS_CONNECTED && ( JKBot_IsAgent( i ) || cl->netchan.remoteAddress.type == NA_BOT ) ) {
			const qboolean agent = JKBot_IsAgent( i );
			JKBot_AgentForget( i );
			SV_DropClient( cl, "episode reset" );
			if ( agent ) {
				// no real net connection, as for bots: free the slot now rather than after
				// sv_zombietime, so the episode's agents get the same client slots every time
				cl->state = CS_FREE;
			}
		}
	}
	chatBot = -1;
	numChat = 0;
	numPending = 0;
	// 2. limits
	if ( r->fraglimit > 0 ) {
		Cvar_Set( "fraglimit", va( "%i", r->fraglimit ) );
	}
	if ( r->timelimit_min > 0 ) {
		Cvar_Set( "timelimit", va( "%i", r->timelimit_min ) );
	}
	// 3. the seed
	Cvar_Set( "jkbot_seed", va( "%u", r->engine_seed ) );
	srand( r->engine_seed );
	// 4. a new round, starting on a server-frame boundary: the lockstep residual (under one frame of
	// idle time) would otherwise carry the previous episode's step phase into this one
	// SV_MapRestart_f returns early when it already ran this frame (com_frameTime == sv.serverId),
	// and the bridge serves the whole session inside one SV_Frame, so com_frameTime never moves:
	// every RESET after the first was skipped, the round carrying on. Lockstep time is virtual;
	// step the frame clock past the last restart. A restart the game itself scheduled (a delayed
	// map_restart at a round's end) is superseded by this one.
	if ( com_frameTime == sv.serverId ) {
		com_frameTime++;
	}
	sv.restartTime = 0;
	Cmd_ExecuteString( "map_restart 0" );
	sv.timeResidual = 0;
	// the game sets CS_INTERMISSION at a round's end and never clears it (map_restart keeps
	// configstrings; the stock cgame drops its intermission flag in CG_MapRestart), so after a
	// finished round the bridge would see the new one as over. The game module never reads it.
	SV_SetConfigstring( CS_INTERMISSION, "" );
	roundStart = sv.time;
	episodeIndex = (int)r->episode_index;
	// 5. agents
	for ( int a = 0; a < r->num_agents; a++ ) {
		const jkb_agent_setup_t *s = &r->agents[a];
		char name[JKB_NAME_LEN + 1], model[JKB_NAME_LEN + 1], saber1[JKB_NAME_LEN + 1];
		FixedString( name, sizeof( name ), s->name, sizeof( s->name ) );
		FixedString( model, sizeof( model ), s->model, sizeof( s->model ) );
		FixedString( saber1, sizeof( saber1 ), s->saber1, sizeof( s->saber1 ) );
		const int n = JKBot_AddAgent( name[0] ? name : "JKBot", model[0] ? model : "kyle",
			saber1[0] ? saber1 : "single_8", "none" );
		if ( n < 0 ) {
			return qfalse;
		}
		JKBot_NetReset( n, s->ping_up_ms, s->ping_down_ms, 100, 1 );
		agentClients[a] = n;
	}
	// 6. the opponent
	*botClient = -1;
	if ( r->opponent_kind == JKB_OPPONENT_STOCK_BOT ) {
		*botClient = AddStockBot( &r->bot, r->bot_skill );
		if ( *botClient < 0 ) {
			return qfalse;
		}
		numChat = r->bot.num_chat_events < 0 ? 0 :
			r->bot.num_chat_events > JKB_MAX_CHAT_EVENTS ? JKB_MAX_CHAT_EVENTS : r->bot.num_chat_events;
		memcpy( chat, r->bot.chat, sizeof( chat[0] ) * numChat );
		chatBot = *botClient;
		QueueStart( *botClient, &r->bot.start );
	}
	for ( int a = 0; a < r->num_agents; a++ ) {
		QueueStart( agentClients[a], &r->agents[a].start );
	}
	pendingSince = sv.time;
	return qtrue;
}

static void JKBot_Reset_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_reset <path to a jkb_reset_t>\n" );
		return;
	}
	static jkb_reset_t r;
	FILE *f = fopen( Cmd_Argv( 1 ), "rb" );
	const size_t got = f ? fread( &r, 1, sizeof( r ), f ) : 0;
	if ( f ) {
		fclose( f );
	}
	if ( got != sizeof( r ) ) {
		Com_Printf( "jkbot_reset: can't read a %d-byte jkb_reset_t from %s\n", (int)sizeof( r ), Cmd_Argv( 1 ) );
		return;
	}
	int agentClients[JKB_MAX_AGENTS] = { -1, -1 };
	int bot = -1;
	if ( !JKBot_Reset( &r, agentClients, &bot ) ) {
		Com_Printf( "jkbot_reset failed\n" );
		return;
	}
	char line[128];
	Com_sprintf( line, sizeof( line ), "jkbot_reset %d agents", (int)r.episode_index );
	for ( int a = 0; a < r.num_agents; a++ ) {
		Q_strcat( line, sizeof( line ), va( " %d", agentClients[a] ) );
	}
	Com_Printf( "%s bot %d\n", line, bot );
}

static void JKBot_BotCmdLog_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_botcmdlog <path> | stop\n" );
		return;
	}
	if ( botCmdLog ) {
		fclose( botCmdLog );
		botCmdLog = NULL;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		Com_Printf( "jkbot_botcmdlog stopped\n" );
		return;
	}
	botCmdLog = fopen( Cmd_Argv( 1 ), "w" );
	Com_Printf( botCmdLog ? "jkbot_botcmdlog started\n" : "jkbot_botcmdlog: can't open the file\n" );
}

void JKBot_ResetInit( void ) {
	Cmd_AddCommand( "jkbot_botcmdlog", JKBot_BotCmdLog_f, "JKBot: log every stock-bot usercmd (agent builds only)" );
	Cmd_AddCommand( "jkbot_reset", JKBot_Reset_f, "JKBot: start an episode from a jkb_reset_t file (agent builds only)" );
}

#endif // JKBOT_AGENT
