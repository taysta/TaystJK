/*
 * JKBot state hash and snapshot-equivalent export (simulator only). See README.md here.
 *
 * Frame hash: after every game frame (GVM_RunFrame in SV_Frame), xxh64 over the frame's game time
 * (G_RunFrame sets level.time to it), each connected client's number and playerState_t, the
 * entity count and every entityState_t up to sv.num_entities, as raw bytes. The structs hold only
 * 4-byte members (no padding), and the agent build's snap never yields -0.0 (snapvector.cpp), so
 * equal states hash equal across processes.
 *
 * Snapshot export: an agent's snapshot is the one it holds (the newest arrived over its link,
 * netsched.cpp) as SV_BuildClientSnapshot built it (cl->frames): the same playerState and entity
 * set (PVS, SVF_* rules) the wire carries. Fields go
 * out in RawFrame order (jkbot_fields.h) with the network encoding applied: integers truncated to
 * their wire width (sign-extended when signed) and -0.0 sent as an integral 0, i.e. +0.0.
 *
 * Seed: jkbot_seed, when set, replaces the wall-clock randomSeed GVM_InitGame passes to G_InitGame
 * (P1-ENG-09 extends this to RESET).
 *
 * Console commands (until the bridge carries OBS, P1-BR-04):
 *   jkbot_export <path> | stop   write each agent's new snapshots to <path> after every STEP
 *   jkbot_xxh64 [text]           xxh64 of the text (self-test)
 */
#ifdef JKBOT_AGENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server/server.h"
#include "jkbot_agent.h"
#include "jkbot_fields.h"
#include "jkbot_proto.h"

// ---- xxh64 (Yann Collet's XXH64, from the published specification) ----

static const uint64_t XXH_P1 = 0x9E3779B185EBCA87ULL;
static const uint64_t XXH_P2 = 0xC2B2AE3D27D4EB4FULL;
static const uint64_t XXH_P3 = 0x165667B19E3779F9ULL;
static const uint64_t XXH_P4 = 0x85EBCA77C2B2AE63ULL;
static const uint64_t XXH_P5 = 0x27D4EB2F165667C5ULL;

static uint64_t XXH_Rotl( uint64_t x, int r ) {
	return ( x << r ) | ( x >> ( 64 - r ) );
}

static uint64_t XXH_Read64( const byte *p ) {
	uint64_t v;
	memcpy( &v, p, 8 );
	return v;  // little-endian host (x86)
}

static uint32_t XXH_Read32( const byte *p ) {
	uint32_t v;
	memcpy( &v, p, 4 );
	return v;
}

static uint64_t XXH_Round( uint64_t acc, uint64_t input ) {
	acc += input * XXH_P2;
	acc = XXH_Rotl( acc, 31 );
	return acc * XXH_P1;
}

static uint64_t XXH_Merge( uint64_t acc, uint64_t val ) {
	acc ^= XXH_Round( 0, val );
	return acc * XXH_P1 + XXH_P4;
}

uint64_t JKBot_XXH64( const void *data, size_t len, uint64_t seed ) {
	const byte *p = (const byte *)data;
	const byte *end = p + len;
	uint64_t h;
	if ( len >= 32 ) {
		uint64_t v1 = seed + XXH_P1 + XXH_P2, v2 = seed + XXH_P2, v3 = seed, v4 = seed - XXH_P1;
		const byte *limit = end - 32;
		do {
			v1 = XXH_Round( v1, XXH_Read64( p ) ); p += 8;
			v2 = XXH_Round( v2, XXH_Read64( p ) ); p += 8;
			v3 = XXH_Round( v3, XXH_Read64( p ) ); p += 8;
			v4 = XXH_Round( v4, XXH_Read64( p ) ); p += 8;
		} while ( p <= limit );
		h = XXH_Rotl( v1, 1 ) + XXH_Rotl( v2, 7 ) + XXH_Rotl( v3, 12 ) + XXH_Rotl( v4, 18 );
		h = XXH_Merge( h, v1 );
		h = XXH_Merge( h, v2 );
		h = XXH_Merge( h, v3 );
		h = XXH_Merge( h, v4 );
	} else {
		h = seed + XXH_P5;
	}
	h += (uint64_t)len;
	while ( p + 8 <= end ) {
		h ^= XXH_Round( 0, XXH_Read64( p ) );
		h = XXH_Rotl( h, 27 ) * XXH_P1 + XXH_P4;
		p += 8;
	}
	if ( p + 4 <= end ) {
		h ^= (uint64_t)XXH_Read32( p ) * XXH_P1;
		h = XXH_Rotl( h, 23 ) * XXH_P2 + XXH_P3;
		p += 4;
	}
	while ( p < end ) {
		h ^= (*p) * XXH_P5;
		h = XXH_Rotl( h, 11 ) * XXH_P1;
		p++;
	}
	h ^= h >> 33;
	h *= XXH_P2;
	h ^= h >> 29;
	h *= XXH_P3;
	h ^= h >> 32;
	return h;
}

// ---- frame hash ----

static byte hashBuf[sizeof( int ) * ( 2 + MAX_CLIENTS ) + MAX_CLIENTS * sizeof( playerState_t ) +
	MAX_GENTITIES * sizeof( entityState_t )];
static uint64_t frameHash;

static size_t Put( size_t n, const void *data, size_t len ) {
	memcpy( hashBuf + n, data, len );
	return n + len;
}

void JKBot_HashFrame( int gameTime ) {
	size_t n = Put( 0, &gameTime, sizeof( gameTime ) );
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		if ( svs.clients[i].state < CS_CONNECTED ) {
			continue;
		}
		n = Put( n, &i, sizeof( i ) );
		n = Put( n, SV_GameClientNum( i ), sizeof( playerState_t ) );
	}
	n = Put( n, &sv.num_entities, sizeof( sv.num_entities ) );
	for ( int i = 0; i < sv.num_entities; i++ ) {
		n = Put( n, &SV_GentityNum( i )->s, sizeof( entityState_t ) );
	}
	frameHash = JKBot_XXH64( hashBuf, n, 0 );
}

uint64_t JKBot_FrameHash( void ) {
	return frameHash;
}

// ---- snapshot export ----

static uint32_t WireValue( const void *base, const jkbField_t *f ) {
	uint32_t v;
	memcpy( &v, (const byte *)base + f->offset, 4 );
	if ( f->bits == 0 ) {
		return v == 0x80000000u ? 0u : v;  // -0.0 is integral: sent as the integer 0
	}
	int width = f->bits < 0 ? -f->bits : f->bits;
	if ( width >= 32 ) {
		return v;
	}
	uint32_t mask = ( 1u << width ) - 1;
	v &= mask;
	if ( f->bits < 0 && ( v & ( 1u << ( width - 1 ) ) ) ) {
		v |= ~mask;
	}
	return v;
}

// The snapshot the agent holds: the newest that has arrived over its link (netsched.cpp), as
// SV_BuildClientSnapshot built it.
qboolean JKBot_ExportSnapshot( int clientNum, jkb_agent_obs_t *out, int *messageNum ) {
	if ( clientNum < 0 || clientNum >= sv_maxclients->integer ) {
		return qfalse;
	}
	client_t *cl = &svs.clients[clientNum];
	int serverTime;
	const int seq = JKBot_NetHeld( clientNum, &serverTime );
	if ( cl->state < CS_PRIMED || seq < 0 ) {
		return qfalse;
	}
	if ( cl->netchan.outgoingSequence - seq > PACKET_BACKUP ) {
		Com_Error( ERR_DROP, "jkbot export: held snapshot %d is older than the frame backup", seq );
	}
	const clientSnapshot_t *frame = &cl->frames[seq & PACKET_MASK];
	out->client = clientNum;
	out->snap_server_time = serverTime;
	out->flags = 0;
	for ( int i = 0; i < JKB_PS_NUM_FIELDS; i++ ) {
		out->ps[i] = WireValue( &frame->ps, &jkbPsFields[i] );
	}
	int n = frame->num_entities;
	if ( n > JKB_MAX_SNAP_ENTITIES ) {
		n = JKB_MAX_SNAP_ENTITIES;
		out->flags |= JKB_OBS_ENTITIES_TRUNCATED;
	}
	out->num_entities = n;
	for ( int e = 0; e < n; e++ ) {
		const entityState_t *es =
			&svs.snapshotEntities[( frame->first_entity + e ) % svs.numSnapshotEntities];
		for ( int i = 0; i < JKB_ES_NUM_FIELDS; i++ ) {
			out->entities[e].fields[i] = WireValue( es, &jkbEsFields[i] );
		}
	}
	if ( messageNum ) {
		*messageNum = seq;
	}
	return qtrue;
}

// ---- dump (test harness until the bridge) ----

static FILE *exportFile;
static int lastExported[MAX_CLIENTS];
static jkb_agent_obs_t exportObs;

#define JKB_EXPORT_MAGIC 0x584B424Au  // "JBKX"

// After every STEP: each agent client's snapshot, if it's new. Record: magic, client, serverTime,
// messageNum, flags, num_entities, ps[JKB_PS_NUM_FIELDS], entities[num_entities][JKB_ES_NUM_FIELDS],
// all little-endian 32-bit.
void JKBot_ExportStep( void ) {
	if ( !exportFile ) {
		return;
	}
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		int messageNum;
		if ( !JKBot_IsAgent( i ) || !JKBot_ExportSnapshot( i, &exportObs, &messageNum ) ) {
			continue;
		}
		if ( messageNum == lastExported[i] ) {
			continue;
		}
		lastExported[i] = messageNum;
		const int32_t head[6] = { (int32_t)JKB_EXPORT_MAGIC, i, exportObs.snap_server_time, messageNum,
			(int32_t)exportObs.flags, exportObs.num_entities };
		fwrite( head, sizeof( head ), 1, exportFile );
		fwrite( exportObs.ps, sizeof( exportObs.ps ), 1, exportFile );
		fwrite( exportObs.entities, sizeof( jkb_entity_t ), exportObs.num_entities, exportFile );
	}
}

static void JKBot_Export_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_export <path> | stop\n" );
		return;
	}
	if ( exportFile ) {
		fclose( exportFile );
		exportFile = NULL;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		Com_Printf( "jkbot_export stopped\n" );
		return;
	}
	exportFile = fopen( Cmd_Argv( 1 ), "wb" );
	for ( int i = 0; i < MAX_CLIENTS; i++ ) {
		lastExported[i] = -1;
	}
	Com_Printf( exportFile ? "jkbot_export started\n" : "jkbot_export: can't open the file\n" );
}

static void JKBot_XXH64_f( void ) {
	const char *text = Cmd_Argc() > 1 ? Cmd_ArgsFrom( 1 ) : "";
	unsigned long long h = JKBot_XXH64( text, strlen( text ), 0 );
	Com_Printf( "jkbot_xxh64 %016llx\n", h );
}

// ---- seed ----

static cvar_t *jkbot_seed;

int JKBot_RandomSeed( int fallback ) {
	if ( jkbot_seed && jkbot_seed->string[0] ) {
		return jkbot_seed->integer;
	}
	return fallback;
}

void JKBot_ExportInit( void ) {
	jkbot_seed = Cvar_Get( "jkbot_seed", "", 0, "JKBot: G_InitGame random seed; empty uses the clock (agent builds only)" );
	Cmd_AddCommand( "jkbot_export", JKBot_Export_f, "JKBot: dump agents' snapshots after each STEP (agent builds only)" );
	Cmd_AddCommand( "jkbot_xxh64", JKBot_XXH64_f, "JKBot: xxh64 of a string (agent builds only)" );
}

#endif // JKBOT_AGENT
