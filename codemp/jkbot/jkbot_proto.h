/*
 * JKBot bridge protocol (simulator only). See README.md in this directory.
 *
 * Every message is a jkb_msg_header_t followed by one body. Little-endian, packed, fixed-width
 * fields only, every field on a 4-byte boundary; sizes are asserted below so the 32-bit engine
 * and the 64-bit Python side agree. The Python mirror (training/src/jkbot/bridge/proto_gen.py)
 * is generated from this file by `jkbot dev gen-proto`; bump JKB_PROTO_VERSION on any change.
 *
 * playerState and entityState values travel as 32-bit patterns (int32, or float32 for float
 * netfields) in netfield order: the protocol 26 msg.cpp playerStateFields table followed by
 * stats[16], persistant[16], ammo[16], powerups[16]; and the entity number followed by the
 * entityStateFields table. This is jkbot.features.raw's PLAYER_STATE / ENTITY_STATE order.
 */
#pragma once

#ifdef JKBOT_AGENT

#include <stdint.h>

#ifdef __cplusplus
#define JKB_STATIC_ASSERT( cond, msg ) static_assert( cond, msg )
#else
#define JKB_STATIC_ASSERT( cond, msg ) _Static_assert( cond, msg )
#endif

#define JKB_PROTO_MAGIC			0x31424B4A	// "JKB1"
#define JKB_PROTO_VERSION		5

#define JKB_MAX_AGENTS			2
#define JKB_MAX_CHAT_EVENTS		32
#define JKB_MAX_SNAP_ENTITIES	64
#define JKB_MAX_RAYS			64
#define JKB_MAX_EVENTS			32
#define JKB_MAX_COMMAND_BYTES	16384	// server commands per OBS, NUL-terminated each
#define JKB_PS_NUM_FIELDS		201		// 137 netfields + 64 array entries
#define JKB_ES_NUM_FIELDS		133		// number + 132 netfields
#define JKB_NAME_LEN			32
#define JKB_COMMAND_LEN			64

// jkb_msg_header_t.type
#define JKB_MSG_HELLO			1	// both ways, once per connection
#define JKB_MSG_RESET			2	// python -> engine: start an episode
#define JKB_MSG_STEP			3	// python -> engine: one usercmd per agent
#define JKB_MSG_OBS				4	// engine -> python: after RESET and every STEP
#define JKB_MSG_DONE			5	// engine -> python: the episode (round) ended

// jkb_event_t.type
#define JKB_EV_DAMAGE			1	// a = attacker, b = target, value = health + shields removed
#define JKB_EV_FRAG				2	// a = killer, b = victim
#define JKB_EV_RESPAWN			3	// a = client
#define JKB_EV_CHAT				4	// a = client, b = 1 opened / 0 closed
#define JKB_EV_ROUND_END		5	// a = winner client or -1

// jkb_agent_obs_t.flags
#define JKB_OBS_ENTITIES_TRUNCATED	1	// the snapshot held more than JKB_MAX_SNAP_ENTITIES
#define JKB_OBS_EVENTS_TRUNCATED	2
#define JKB_OBS_COMMANDS_TRUNCATED	4	// the rest come in the next OBS

// jkb_reset_t opponent kind
#define JKB_OPPONENT_AGENT		0
#define JKB_OPPONENT_STOCK_BOT	1
#define JKB_OPPONENT_HUMAN		2	// a real client that connects over the network (play mode)

// jkb_done_t.reason
#define JKB_DONE_FRAGLIMIT		1
#define JKB_DONE_TIMELIMIT		2
#define JKB_DONE_ERROR			3

#pragma pack( push, 1 )

typedef struct jkb_msg_header_s {
	uint32_t	magic;
	uint16_t	version;
	uint16_t	type;
	uint32_t	length;			// body bytes after the header
	uint32_t	seq;
} jkb_msg_header_t;
JKB_STATIC_ASSERT( sizeof( jkb_msg_header_t ) == 16, "jkb_msg_header_t size" );

typedef struct jkb_hello_s {
	uint32_t	proto_version;
	uint32_t	flags;
	int32_t		sv_fps;
	int32_t		usercmd_ms;
	int32_t		max_agents;
	int32_t		max_entities;
	char		engine_build[JKB_NAME_LEN];
} jkb_hello_t;
JKB_STATIC_ASSERT( sizeof( jkb_hello_t ) == 56, "jkb_hello_t size" );

typedef struct jkb_chat_event_s {
	int32_t		start_ms;		// from round start
	int32_t		duration_ms;
} jkb_chat_event_t;
JKB_STATIC_ASSERT( sizeof( jkb_chat_event_t ) == 8, "jkb_chat_event_t size" );

// A demo-state start (P4-DSR-01): where a client is put once the episode's round has begun.
typedef struct jkb_start_s {
	int32_t		active;			// 0: the game's own spawn
	float		origin[3];
	float		velocity[3];
	float		angles[2];		// view pitch, yaw (degrees)
} jkb_start_t;
JKB_STATIC_ASSERT( sizeof( jkb_start_t ) == 36, "jkb_start_t size" );

typedef struct jkb_agent_setup_s {
	int32_t		client;			// client slot
	int32_t		ping_up_ms;
	int32_t		ping_down_ms;
	int32_t		num_chat_events;	// scripted chat (stock bot only; agents chat by command)
	char		name[JKB_NAME_LEN];
	char		model[JKB_NAME_LEN];
	char		saber1[JKB_NAME_LEN];
	jkb_chat_event_t	chat[JKB_MAX_CHAT_EVENTS];
	jkb_start_t	start;
} jkb_agent_setup_t;
JKB_STATIC_ASSERT( sizeof( jkb_agent_setup_t ) == 404, "jkb_agent_setup_t size" );

typedef struct jkb_reset_s {
	uint32_t	engine_seed;
	uint32_t	episode_index;
	int32_t		num_agents;
	int32_t		opponent_kind;	// JKB_OPPONENT_*
	float		bot_skill;		// for JKB_OPPONENT_STOCK_BOT
	int32_t		fraglimit;
	int32_t		timelimit_min;
	int32_t		pad0;
	jkb_agent_setup_t	agents[JKB_MAX_AGENTS];
	jkb_agent_setup_t	bot;	// the stock bot when opponent_kind is JKB_OPPONENT_STOCK_BOT
} jkb_reset_t;
JKB_STATIC_ASSERT( sizeof( jkb_reset_t ) == 1244, "jkb_reset_t size" );

typedef struct jkb_usercmd_s {	// usercmd_t, fixed width
	int32_t		server_time;
	int32_t		angles[3];
	int32_t		buttons;
	uint8_t		weapon;
	uint8_t		forcesel;
	uint8_t		invensel;
	uint8_t		generic_cmd;
	int8_t		forwardmove;
	int8_t		rightmove;
	int8_t		upmove;
	uint8_t		pad0;
} jkb_usercmd_t;
JKB_STATIC_ASSERT( sizeof( jkb_usercmd_t ) == 28, "jkb_usercmd_t size" );

typedef struct jkb_agent_step_s {
	int32_t		client;
	int32_t		has_command;	// 1: send client_command this step
	jkb_usercmd_t	cmd;
	char		client_command[JKB_COMMAND_LEN];
} jkb_agent_step_t;
JKB_STATIC_ASSERT( sizeof( jkb_agent_step_t ) == 100, "jkb_agent_step_t size" );

typedef struct jkb_step_s {
	uint32_t	step_index;
	int32_t		num_agents;
	jkb_agent_step_t	agents[JKB_MAX_AGENTS];
	int32_t		has_server_command;	// 1: run server_command on the console before this step
	char		server_command[JKB_COMMAND_LEN];	// e.g. svrecord (the console isn't read in bridge mode)
} jkb_step_t;
JKB_STATIC_ASSERT( sizeof( jkb_step_t ) == 276, "jkb_step_t size" );

typedef struct jkb_entity_s {
	uint32_t	fields[JKB_ES_NUM_FIELDS];
} jkb_entity_t;
JKB_STATIC_ASSERT( sizeof( jkb_entity_t ) == 532, "jkb_entity_t size" );

typedef struct jkb_event_s {
	int32_t		type;			// JKB_EV_*
	int32_t		time_ms;		// server time
	int32_t		a;
	int32_t		b;
	float		value;
	int32_t		pad0;
} jkb_event_t;
JKB_STATIC_ASSERT( sizeof( jkb_event_t ) == 24, "jkb_event_t size" );

typedef struct jkb_agent_obs_s {
	int32_t		client;
	int32_t		snap_server_time;	// serverTime of the snapshot the client holds
	int32_t		cg_time;			// render time (cl.serverTime)
	uint32_t	flags;				// JKB_OBS_*
	int32_t		opponent_visible;	// visibility model (environment §5.2)
	int32_t		num_entities;
	int32_t		num_rays;
	int32_t		num_events;
	int32_t		snap_message_num;	// the held snapshot's message number (0: none yet): a new one
									// is a new snapshot even at the same serverTime
	float		view_origin[3];		// the client's camera (refdef vieworg; zeros before a view)
	float		view_angles[3];		// and its angles (pitch, yaw, roll)
	uint32_t	ps[JKB_PS_NUM_FIELDS];			// snapshot playerState
	uint32_t	predicted_ps[JKB_PS_NUM_FIELDS];	// client-predicted playerState
	jkb_entity_t	entities[JKB_MAX_SNAP_ENTITIES];
	float		rays[JKB_MAX_RAYS];		// hit fraction of ray_length
	jkb_event_t	events[JKB_MAX_EVENTS];
	int32_t		num_commands;	// the server commands the held snapshot brought (netsched.cpp)
	int32_t		commands_len;	// bytes used in commands
	char		commands[JKB_MAX_COMMAND_BYTES];
} jkb_agent_obs_t;
JKB_STATIC_ASSERT( sizeof( jkb_agent_obs_t ) == 53132, "jkb_agent_obs_t size" );

typedef struct jkb_obs_s {
	uint32_t	step_index;
	int32_t		num_agents;
	uint32_t	frame_hash[2];	// state hash of the server frame (P1-ENG-07), low word first
	int32_t		level_start_time;	// configstring CS_LEVEL_START_TIME
	int32_t		pad0;
	int32_t		scores[2];		// duelist scores: [0] agents[0]'s client, [1] the other duelist
	jkb_agent_obs_t	agents[JKB_MAX_AGENTS];
} jkb_obs_t;
JKB_STATIC_ASSERT( sizeof( jkb_obs_t ) == 106296, "jkb_obs_t size" );

typedef struct jkb_done_s {
	uint32_t	step_index;
	int32_t		reason;			// JKB_DONE_*
	int32_t		scores[JKB_MAX_AGENTS];
} jkb_done_t;
JKB_STATIC_ASSERT( sizeof( jkb_done_t ) == 16, "jkb_done_t size" );

#pragma pack( pop )

#endif // JKBOT_AGENT
