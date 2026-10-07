/*
 * JKBot bridge endpoint (simulator only). See README.md in this directory.
 *
 * With jkbot_bridge set to a Unix socket path and jkbot_lockstep 1, the engine connects to the
 * Python env (which listens) once the map is loaded, exchanges HELLO, then serves messages in
 * the lockstep main loop until the env closes the connection, after which it quits:
 *   RESET -> JKBot_Reset (reset.cpp), then OBS;
 *   STEP  -> each agent's usercmd becomes its held usercmd (sent by netsched.cpp in the client's
 *            packet pattern), its client command runs, one lockstep STEP, then OBS, or DONE
 *            once the round has ended (CS_INTERMISSION: fraglimit or timelimit).
 * SOCK_SEQPACKET: one message per packet (jkbot_proto.h framing). Linux only, like the sim.
 *
 * OBS per agent: the snapshot it holds (export.cpp), the frame hash, CS_LEVEL_START_TIME, both
 * duelists' scores, and the step's events read from server state: damage (a drop in health plus
 * armour, attacker from PERS_ATTACKER), frags (PERS_KILLED), respawns (PERS_SPAWN_COUNT), chat
 * (EF_TALK) and round end. Until their items arrive: predicted_ps is the held snapshot's
 * playerState (P1-ENG-11), cg_time is 0 (client clock, P1-BR-05), opponent_visible is "the
 * opponent is in the snapshot" (visibility model, P1-ENG-12), and there are no rays (P1-ENG-13).
 */
#ifdef JKBOT_AGENT

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#endif

#include "server/server.h"
#include "jkbot_agent.h"
#include "jkbot_proto.h"

#define JKB_STAT_HEALTH			0	// bg_public.h statIndex_t
#define JKB_STAT_ARMOR			5
#define JKB_PERS_SCORE			0	// bg_public.h persEnum_t
#define JKB_PERS_SPAWN_COUNT	4
#define JKB_PERS_ATTACKER		6
#define JKB_PERS_KILLED			8
#define JKB_EF_TALK				( 1 << 13 )
#define JKB_CS_LEVEL_START_TIME	21
#define JKB_CS_INTERMISSION		22
#define JKB_MAX_MESSAGE			( sizeof( jkb_msg_header_t ) + sizeof( jkb_obs_t ) )

static int bridgeFd = -1;
static qboolean bridgeFailed;
static uint32_t sendSeq;
static byte inBuf[JKB_MAX_MESSAGE];
static jkb_obs_t obs;

typedef struct {
	int health, armor, score, killed, spawns, talk;
	qboolean valid;
} jkbTrack_t;

static jkbTrack_t track[MAX_CLIENTS];
static int numAgents, agentClients[JKB_MAX_AGENTS], opponentClient = -1;
static jkb_event_t events[JKB_MAX_EVENTS];
static int numEvents;
static qboolean eventsTruncated;

// ---- transport ----

static qboolean JKB_Send( uint16_t type, const void *body, uint32_t length ) {
	static byte out[JKB_MAX_MESSAGE];
	jkb_msg_header_t h;
	h.magic = JKB_PROTO_MAGIC;
	h.version = JKB_PROTO_VERSION;
	h.type = type;
	h.length = length;
	h.seq = ++sendSeq;
	memcpy( out, &h, sizeof( h ) );
	memcpy( out + sizeof( h ), body, length );
#ifdef __linux__
	const ssize_t n = send( bridgeFd, out, sizeof( h ) + length, 0 );
	return (qboolean)( n == (ssize_t)( sizeof( h ) + length ) );
#else
	return qfalse;
#endif
}

// One message; the body follows the header in inBuf. qfalse when the env closed the connection.
static qboolean JKB_Recv( jkb_msg_header_t *h ) {
#ifdef __linux__
	const ssize_t n = recv( bridgeFd, inBuf, sizeof( inBuf ), 0 );
	if ( n <= 0 ) {
		return qfalse;
	}
	if ( (size_t)n < sizeof( *h ) ) {
		Com_Error( ERR_FATAL, "jkbot bridge: short message (%d bytes)", (int)n );
	}
	memcpy( h, inBuf, sizeof( *h ) );
	if ( h->magic != JKB_PROTO_MAGIC || h->version != JKB_PROTO_VERSION ||
		sizeof( *h ) + h->length != (size_t)n ) {
		Com_Error( ERR_FATAL, "jkbot bridge: bad message header (type %d, %d bytes)", h->type, (int)n );
	}
	return qtrue;
#else
	return qfalse;
#endif
}

static qboolean Connect( const char *path ) {
#ifdef __linux__
	bridgeFd = socket( AF_UNIX, SOCK_SEQPACKET, 0 );
	if ( bridgeFd < 0 ) {
		return qfalse;
	}
	struct sockaddr_un addr;
	Com_Memset( &addr, 0, sizeof( addr ) );
	addr.sun_family = AF_UNIX;
	Q_strncpyz( addr.sun_path, path, sizeof( addr.sun_path ) );
	if ( connect( bridgeFd, (struct sockaddr *)&addr, sizeof( addr ) ) != 0 ) {
		Com_Printf( "jkbot bridge: can't connect to %s: %s\n", path, strerror( errno ) );
		close( bridgeFd );
		bridgeFd = -1;
		return qfalse;
	}
	return qtrue;
#else
	Com_Printf( "jkbot bridge: SOCK_SEQPACKET needs Linux\n" );
	return qfalse;
#endif
}

// ---- events (server state, read after each STEP) ----

static void AddEvent( int type, int a, int b, float value ) {
	if ( numEvents == JKB_MAX_EVENTS ) {
		eventsTruncated = qtrue;
		return;
	}
	jkb_event_t *e = &events[numEvents++];
	e->type = type;
	e->time_ms = sv.time;
	e->a = a;
	e->b = b;
	e->value = value;
	e->pad0 = 0;
}

static qboolean InRound( int client ) {
	return (qboolean)( client >= 0 && client < sv_maxclients->integer &&
		svs.clients[client].state == CS_ACTIVE );
}

static void ReadTrack( int client, jkbTrack_t *t ) {
	const playerState_t *ps = SV_GameClientNum( client );
	t->health = ps->stats[JKB_STAT_HEALTH] > 0 ? ps->stats[JKB_STAT_HEALTH] : 0;
	t->armor = ps->stats[JKB_STAT_ARMOR];
	t->score = ps->persistant[JKB_PERS_SCORE];
	t->killed = ps->persistant[JKB_PERS_KILLED];
	t->spawns = ps->persistant[JKB_PERS_SPAWN_COUNT];
	t->talk = ( ps->eFlags & JKB_EF_TALK ) ? 1 : 0;
	t->valid = qtrue;
}

static void ResetTracking( void ) {
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		track[i].valid = qfalse;
		if ( i < sv_maxclients->integer && InRound( i ) ) {
			ReadTrack( i, &track[i] );
		}
	}
}

static void CollectEvents( void ) {
	numEvents = 0;
	eventsTruncated = qfalse;
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		if ( !InRound( i ) ) {
			track[i].valid = qfalse;
			continue;
		}
		jkbTrack_t now;
		ReadTrack( i, &now );
		const jkbTrack_t *was = &track[i];
		if ( was->valid ) {
			const int attacker = SV_GameClientNum( i )->persistant[JKB_PERS_ATTACKER];
			const int lost = ( was->health + was->armor ) - ( now.health + now.armor );
			if ( now.spawns == was->spawns && lost > 0 ) {
				AddEvent( JKB_EV_DAMAGE, attacker, i, (float)lost );
			}
			if ( now.killed > was->killed ) {
				AddEvent( JKB_EV_FRAG, attacker, i, 0.0f );
			}
			if ( now.spawns > was->spawns ) {
				AddEvent( JKB_EV_RESPAWN, i, 0, 0.0f );
			}
			if ( now.talk != was->talk ) {
				AddEvent( JKB_EV_CHAT, i, now.talk, 0.0f );
			}
		}
		track[i] = now;
	}
}

static int ConfigInt( int index ) {
	char buf[64];
	SV_GetConfigstring( index, buf, sizeof( buf ) );
	return atoi( buf );
}

static int Score( int client ) {
	return client >= 0 && client < sv_maxclients->integer && svs.clients[client].state >= CS_CONNECTED
		? SV_GameClientNum( client )->persistant[JKB_PERS_SCORE] : 0;
}

// ---- messages ----

static void SendHello( void ) {
	jkb_hello_t h;
	Com_Memset( &h, 0, sizeof( h ) );
	h.proto_version = JKB_PROTO_VERSION;
	h.sv_fps = Cvar_VariableIntegerValue( "sv_fps" );
	h.usercmd_ms = JKB_USERCMD_MSEC;
	h.max_agents = JKB_MAX_AGENTS;
	h.max_entities = JKB_MAX_SNAP_ENTITIES;
	Q_strncpyz( h.engine_build, Cvar_VariableString( "version" ), sizeof( h.engine_build ) );
	JKB_Send( JKB_MSG_HELLO, &h, sizeof( h ) );
}

static void SendObs( uint32_t stepIndex ) {
	Com_Memset( &obs, 0, sizeof( obs ) );
	obs.step_index = stepIndex;
	obs.num_agents = numAgents;
	const uint64_t hash = JKBot_FrameHash();
	obs.frame_hash[0] = (uint32_t)hash;
	obs.frame_hash[1] = (uint32_t)( hash >> 32 );
	obs.level_start_time = ConfigInt( JKB_CS_LEVEL_START_TIME );
	obs.scores[0] = numAgents ? Score( agentClients[0] ) : 0;
	obs.scores[1] = Score( opponentClient );
	for ( int k = 0; k < numAgents; k++ ) {
		jkb_agent_obs_t *a = &obs.agents[k];
		const int c = agentClients[k];
		a->client = c;
		JKBot_ExportSnapshot( c, a, NULL );  // leaves zeros until a snapshot has arrived
		memcpy( a->predicted_ps, a->ps, sizeof( a->ps ) );  // until prediction (P1-ENG-11)
		a->cg_time = 0;  // until the client clock (P1-BR-05)
		for ( int e = 0; e < a->num_entities; e++ ) {
			if ( (int)a->entities[e].fields[0] == opponentClient ) {
				a->opponent_visible = 1;  // until the visibility model (P1-ENG-12)
			}
		}
		a->num_rays = 0;  // until P1-ENG-13
		a->num_events = numEvents;
		memcpy( a->events, events, sizeof( events[0] ) * numEvents );
		if ( eventsTruncated ) {
			a->flags |= JKB_OBS_EVENTS_TRUNCATED;
		}
	}
	JKB_Send( JKB_MSG_OBS, &obs, sizeof( obs ) );
}

static void SendDone( uint32_t stepIndex, int reason ) {
	jkb_done_t d;
	Com_Memset( &d, 0, sizeof( d ) );
	d.step_index = stepIndex;
	d.reason = reason;
	d.scores[0] = numAgents ? Score( agentClients[0] ) : 0;
	d.scores[1] = Score( opponentClient );
	JKB_Send( JKB_MSG_DONE, &d, sizeof( d ) );
}

static void HandleReset( const jkb_reset_t *r ) {
	int bot = -1;
	numAgents = 0;
	opponentClient = -1;
	if ( !JKBot_Reset( r, agentClients, &bot ) ) {
		SendDone( 0, JKB_DONE_ERROR );
		return;
	}
	numAgents = r->num_agents;
	for ( int k = 0; k < numAgents; k++ ) {
		if ( agentClients[k] != r->agents[k].client ) {
			Com_Printf( "jkbot bridge: agent %d took client %d, RESET asked for %d\n", k,
				agentClients[k], r->agents[k].client );
			SendDone( 0, JKB_DONE_ERROR );
			return;
		}
	}
	opponentClient = r->opponent_kind == JKB_OPPONENT_STOCK_BOT ? bot :
		numAgents > 1 ? agentClients[1] : -1;
	Cbuf_Execute();
	ResetTracking();
	numEvents = 0;
	eventsTruncated = qfalse;
	SendObs( 0 );
}

static void HandleStep( const jkb_step_t *s ) {
	if ( !numAgents ) {
		SendDone( s->step_index, JKB_DONE_ERROR );
		return;
	}
	for ( int k = 0; k < s->num_agents && k < JKB_MAX_AGENTS; k++ ) {
		const jkb_agent_step_t *a = &s->agents[k];
		if ( !JKBot_IsAgent( a->client ) ) {
			continue;
		}
		usercmd_t *cmd = JKBot_AgentCmd( a->client );
		cmd->angles[0] = a->cmd.angles[0];
		cmd->angles[1] = a->cmd.angles[1];
		cmd->angles[2] = a->cmd.angles[2];
		cmd->buttons = a->cmd.buttons;
		cmd->weapon = a->cmd.weapon;
		cmd->forcesel = a->cmd.forcesel;
		cmd->invensel = a->cmd.invensel;
		cmd->generic_cmd = a->cmd.generic_cmd;
		cmd->forwardmove = a->cmd.forwardmove;
		cmd->rightmove = a->cmd.rightmove;
		cmd->upmove = a->cmd.upmove;
		if ( a->has_command ) {
			char text[JKB_COMMAND_LEN + 1];
			memcpy( text, a->client_command, JKB_COMMAND_LEN );
			text[JKB_COMMAND_LEN] = 0;
			SV_ExecuteClientCommand( &svs.clients[a->client], text, qtrue );
		}
	}
	JKBot_Step( 1 );
	Cbuf_Execute();
	CollectEvents();
	if ( ConfigInt( JKB_CS_INTERMISSION ) ) {
		const int top = Score( agentClients[0] ) > Score( opponentClient ) ? Score( agentClients[0] ) : Score( opponentClient );
		const int fraglimit = Cvar_VariableIntegerValue( "fraglimit" );
		SendDone( s->step_index, fraglimit > 0 && top >= fraglimit ? JKB_DONE_FRAGLIMIT : JKB_DONE_TIMELIMIT );
		numAgents = 0;  // the next message must be a RESET
		return;
	}
	SendObs( s->step_index );
}

// From SV_Frame while lockstep is idle: connect once the map is up, then serve the env until it
// closes the connection; then quit.
void JKBot_BridgeService( void ) {
	const char *path = Cvar_VariableString( "jkbot_bridge" );
	if ( !path[0] || bridgeFailed || sv.state != SS_GAME ) {
		return;
	}
	if ( bridgeFd < 0 ) {
		if ( !Connect( path ) ) {
			bridgeFailed = qtrue;
			Cbuf_AddText( "quit\n" );
			return;
		}
		SendHello();
		jkb_msg_header_t h;
		if ( !JKB_Recv( &h ) || h.type != JKB_MSG_HELLO ) {
			Com_Error( ERR_FATAL, "jkbot bridge: the env didn't answer HELLO" );
		}
		Com_Printf( "jkbot bridge: connected to %s\n", path );
	}
	jkb_msg_header_t h;
	while ( JKB_Recv( &h ) ) {
		const void *body = inBuf + sizeof( h );
		if ( h.type == JKB_MSG_RESET && h.length == sizeof( jkb_reset_t ) ) {
			static jkb_reset_t r;
			memcpy( &r, body, sizeof( r ) );
			HandleReset( &r );
		} else if ( h.type == JKB_MSG_STEP && h.length == sizeof( jkb_step_t ) ) {
			static jkb_step_t s;
			memcpy( &s, body, sizeof( s ) );
			HandleStep( &s );
		} else {
			Com_Error( ERR_FATAL, "jkbot bridge: unexpected message type %d (%d bytes)", h.type, h.length );
		}
	}
	Com_Printf( "jkbot bridge: the env closed the connection\n" );
#ifdef __linux__
	close( bridgeFd );
#endif
	bridgeFd = -1;
	bridgeFailed = qtrue;
	Cbuf_AddText( "quit\n" );
}

#endif // JKBOT_AGENT
