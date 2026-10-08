/*
 * Demo dump (JKBot P2-DM-01). Records only: no input endpoint, so it may ship in release builds
 * (see README.md). After aufau's jedi_ai snapshot serialiser (JKBot ROADMAP [39]), which walks
 * the playerState and entityState netfields at CL_ParseSnapshot; here as buffered append of every
 * snapshot instead of a rewritten 10-snapshot window.
 *
 * `+set jkbot_dump <out> +demo <name>`: the demo command reads the whole demo through the client's
 * own parser (CL_ReadDemoMessage, CL_ParseServerMessage) in one go. The gamestate hook stops it
 * before downloads and cgame, so the map is never loaded and the client stays connected until the
 * demo ends. The output is zstd-compressed ndjson, one record per line, keys in a fixed order:
 *
 *   {"type":"header","decoder":"taystjk","format":1,"engine":"<sha>","zstd":"<version>",
 *    "file":"<demo file name>"}
 *   {"type":"gamestate","serverCommandSequence":S,"clientNum":C,"checksumFeed":F,
 *    "configstrings":{"<index>":"<string>",...},"baselines":[{...},...]}
 *   {"type":"configstrings","serverTime":T,"set":{"<index>":"<string>",...}}
 *   {"type":"snapshot","serverTime":T,"messageNum":N,"snapFlags":F,"ps":{...},
 *    "entities":[{...},...],"commands":["...",...]}
 *   {"type":"end","snapshots":N,"error":null}
 *
 * - gamestate: every svc_gamestate (a demo can hold more than one). Configstrings in index order;
 *   baselines are the non-zero entity baselines in number order.
 * - snapshot: every valid snapshot the client keeps (cl.snap), in parse order. ps and entity
 *   fields use the RawFrame names and order (jkbot.features.raw, via dump_fields.h). A zero field
 *   is left out (RawFrame reads a missing field as 0), except an entity's number. Integers are
 *   the values the client stores (wire width, sign-extended when signed); floats are the float32
 *   value printed exactly (%.17g), null if not finite.
 * - commands: the server commands that arrived since the previous snapshot (up to the snapshot's
 *   serverCommandNum), as received.
 * - configstrings: before a snapshot whose commands changed configstrings (cs, and bcs0/1/2
 *   reassembled), the changed ones, applied as CL_GetServerCommand would ("" = cleared). The
 *   dump keeps its own copy; the client's gameState isn't touched.
 * - end: written when the demo ends (CL_DemoCompleted), then the client quits with status 0. Any
 *   Com_Error while the dump cvar is set ends the dump with "error":"<message>" and is made
 *   fatal, so the client exits nonzero.
 *
 * Strings are escaped byte for byte ('"' and '\' with a backslash, bytes below 0x20 or from 0x7f
 * as \u00XX), so the output is deterministic and matches the DemoTools decoder
 * (scripts/demotools/jkbot_decode.cpp). The engine SHA comes from the build
 * (scripts/build_client.sh); zstd from the pinned source tree it fetches.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <map>
#include <string>

#include "client/client.h"
#include "dump_fields.h"

#ifdef DEMO_DUMP_ZSTD
#include "zstd.h"
#endif

#ifndef DEMO_DUMP_ENGINE_SHA
#define DEMO_DUMP_ENGINE_SHA "unknown"
#endif

#define DUMP_FORMAT			1
#define DUMP_ZSTD_LEVEL		9
#define DUMP_FLUSH_BYTES	( 1 << 20 )

static FILE							*dumpFile;
static qboolean						dumpFinishing;	// a write error while finishing doesn't finish again
static std::string					dumpPending;	// ndjson not yet compressed
static long							dumpSnapshots;
static int							dumpLastCommand;	// last server command written
static std::map<int, std::string>	dumpConfigstrings;
static char							dumpBigConfigString[BIG_INFO_STRING];
#ifdef DEMO_DUMP_ZSTD
static ZSTD_CCtx					*dumpCctx;
#endif

static const char *DumpPath( void ) {
	return Cvar_VariableString( "jkbot_dump" );
}

static qboolean Dumping( void ) {
	return (qboolean)( clc.demoplaying && DumpPath()[0] );
}

// ---- output ----

static void Put( const char *s ) {
	dumpPending += s;
}

static void Putf( const char *fmt, ... ) {
	char buf[512];  // the longest use, the gamestate prefix, is about 120 characters
	va_list ap;
	va_start( ap, fmt );
	Q_vsnprintf( buf, sizeof( buf ), fmt, ap );
	va_end( ap );
	dumpPending += buf;
}

static void PutString( const char *s ) {
	dumpPending += '"';
	for ( const unsigned char *p = (const unsigned char *)s; *p; p++ ) {
		const unsigned c = *p;
		if ( c == '"' || c == '\\' ) {
			dumpPending += '\\';
			dumpPending += (char)c;
		} else if ( c < 0x20 || c >= 0x7f ) {
			Putf( "\\u%04x", c );
		} else {
			dumpPending += (char)c;
		}
	}
	dumpPending += '"';
}

static void Flush( qboolean end ) {
#ifdef DEMO_DUMP_ZSTD
	static byte out[1 << 16];
	ZSTD_inBuffer in = { dumpPending.data(), dumpPending.size(), 0 };
	for ( ;; ) {
		ZSTD_outBuffer o = { out, sizeof( out ), 0 };
		const size_t left = ZSTD_compressStream2( dumpCctx, &o, &in, end ? ZSTD_e_end : ZSTD_e_continue );
		if ( ZSTD_isError( left ) ) {
			Com_Error( ERR_DROP, "demo dump: zstd: %s", ZSTD_getErrorName( left ) );
		}
		if ( o.pos && fwrite( out, 1, o.pos, dumpFile ) != o.pos ) {
			Com_Error( ERR_DROP, "demo dump: write to %s failed", DumpPath() );
		}
		if ( end ? left == 0 : in.pos == in.size ) {
			break;
		}
	}
#endif
	dumpPending.clear();
}

static void EndLine( void ) {
	dumpPending += '\n';
	if ( dumpPending.size() >= DUMP_FLUSH_BYTES ) {
		Flush( qfalse );
	}
}

static void PutFields( const void *base, const dumpField_t *fields, size_t n ) {
	Put( "{" );
	qboolean first = qtrue;
	for ( size_t i = 0; i < n; i++ ) {
		const byte *p = (const byte *)base + fields[i].offset;
		char value[64];
		if ( fields[i].bits == 0 ) {
			float v;
			memcpy( &v, p, sizeof( v ) );
			if ( v == 0.0f ) {
				continue;
			}
			if ( !isfinite( v ) ) {
				Q_strncpyz( value, "null", sizeof( value ) );
			} else {
				Com_sprintf( value, sizeof( value ), "%.17g", (double)v );
			}
		} else {
			int v;
			memcpy( &v, p, sizeof( v ) );
			if ( v == 0 && strcmp( fields[i].name, "number" ) ) {
				continue;
			}
			Com_sprintf( value, sizeof( value ), "%d", v );
		}
		Putf( "%s\"%s\":", first ? "" : ",", fields[i].name );
		Put( value );
		first = qfalse;
	}
	Put( "}" );
}

// ---- begin and end ----

static void Begin( void ) {
	if ( dumpFile ) {
		return;
	}
#ifndef DEMO_DUMP_ZSTD
	Com_Error( ERR_DROP, "demo dump: this client was built without zstd (scripts/build_client.sh)" );
#else
	dumpFile = fopen( DumpPath(), "wb" );
	if ( !dumpFile ) {
		Com_Error( ERR_DROP, "demo dump: can't open %s", DumpPath() );
	}
	dumpCctx = ZSTD_createCCtx();
	ZSTD_CCtx_setParameter( dumpCctx, ZSTD_c_compressionLevel, DUMP_ZSTD_LEVEL );
	ZSTD_CCtx_setParameter( dumpCctx, ZSTD_c_checksumFlag, 1 );
	dumpPending.clear();
	dumpSnapshots = 0;
	dumpLastCommand = 0;
	dumpConfigstrings.clear();
	dumpBigConfigString[0] = '\0';

	const char *name = strrchr( clc.demoName, '/' );
	Putf( "{\"type\":\"header\",\"decoder\":\"taystjk\",\"format\":%d,\"engine\":", DUMP_FORMAT );
	PutString( DEMO_DUMP_ENGINE_SHA );
	Put( ",\"zstd\":" );
	PutString( ZSTD_versionString() );
	Put( ",\"file\":" );
	PutString( name ? name + 1 : clc.demoName );
	Put( "}" );
	EndLine();
#endif
}

static void Finish( const char *error ) {
	Putf( "{\"type\":\"end\",\"snapshots\":%ld,\"error\":", dumpSnapshots );
	if ( error ) {
		PutString( error );
	} else {
		Put( "null" );
	}
	Put( "}" );
	EndLine();
	dumpFinishing = qtrue;
	Flush( qtrue );
	fclose( dumpFile );
	dumpFile = NULL;
	dumpFinishing = qfalse;
#ifdef DEMO_DUMP_ZSTD
	ZSTD_freeCCtx( dumpCctx );
	dumpCctx = NULL;
#endif
}

// ---- hooks ----

qboolean CL_DemoDumpGamestate( void ) {
	if ( !Dumping() ) {
		return qfalse;
	}
	Begin();

	dumpConfigstrings.clear();
	dumpLastCommand = clc.serverCommandSequence;
	Putf( "{\"type\":\"gamestate\",\"serverCommandSequence\":%d,\"clientNum\":%d,\"checksumFeed\":%d,"
		"\"configstrings\":{", clc.serverCommandSequence, clc.clientNum, clc.checksumFeed );
	qboolean first = qtrue;
	for ( int i = 0; i < MAX_CONFIGSTRINGS; i++ ) {
		const int off = cl.gameState.stringOffsets[i];
		if ( !off ) {
			continue;
		}
		const char *s = cl.gameState.stringData + off;
		dumpConfigstrings[i] = s;
		Putf( "%s\"%d\":", first ? "" : ",", i );
		PutString( s );
		first = qfalse;
	}
	Put( "},\"baselines\":[" );
	static const entityState_t zero = {};
	first = qtrue;
	for ( int i = 0; i < MAX_GENTITIES; i++ ) {
		if ( !memcmp( &cl.entityBaselines[i], &zero, sizeof( zero ) ) ) {
			continue;
		}
		if ( !first ) {
			Put( "," );
		}
		PutFields( &cl.entityBaselines[i], dumpEsFields, ARRAY_LEN( dumpEsFields ) );
		first = qfalse;
	}
	Put( "]}" );
	EndLine();
	return qtrue;
}

// Applies a configstring change as CL_GetServerCommand and CL_ConfigstringModified would, to the
// dump's copy; records it in changed.
static void ConfigstringCommand( const char *command, std::map<int, std::string> &changed ) {
	Cmd_TokenizeString( command );
	const char *cmd = Cmd_Argv( 0 );
	if ( !strcmp( cmd, "bcs0" ) ) {
		Com_sprintf( dumpBigConfigString, BIG_INFO_STRING, "cs %s \"%s", Cmd_Argv( 1 ), Cmd_Argv( 2 ) );
		return;
	}
	if ( !strcmp( cmd, "bcs1" ) || !strcmp( cmd, "bcs2" ) ) {
		const qboolean last = (qboolean)!strcmp( cmd, "bcs2" );
		const char *s = Cmd_Argv( 2 );
		if ( strlen( dumpBigConfigString ) + strlen( s ) + last >= BIG_INFO_STRING ) {
			Com_Error( ERR_DROP, "bcs exceeded BIG_INFO_STRING" );
		}
		Q_strcat( dumpBigConfigString, sizeof( dumpBigConfigString ), s );
		if ( !last ) {
			return;
		}
		Q_strcat( dumpBigConfigString, sizeof( dumpBigConfigString ), "\"" );
		Cmd_TokenizeString( dumpBigConfigString );
		cmd = Cmd_Argv( 0 );
	}
	if ( strcmp( cmd, "cs" ) ) {
		return;
	}
	const int index = atoi( Cmd_Argv( 1 ) );
	if ( index < 0 || index >= MAX_CONFIGSTRINGS ) {
		Com_Error( ERR_DROP, "CL_ConfigstringModified: bad index %i", index );
	}
	const char *s = Cmd_ArgsFrom( 2 );
	auto it = dumpConfigstrings.find( index );
	const std::string old = it == dumpConfigstrings.end() ? "" : it->second;
	if ( old == s ) {
		return;
	}
	if ( s[0] ) {
		dumpConfigstrings[index] = s;
	} else {
		dumpConfigstrings.erase( index );
	}
	changed[index] = s;
}

void CL_DemoDumpSnapshot( void ) {
	if ( !Dumping() ) {
		return;
	}
	Begin();
	const clSnapshot_t &snap = cl.snap;

	// The tokenizer is shared, but in a dump the demo command no longer reads its arguments.
	std::map<int, std::string> changed;
	const int seq = snap.serverCommandNum;
	int start = dumpLastCommand + 1;
	if ( start < seq - MAX_RELIABLE_COMMANDS + 1 ) {
		start = seq - MAX_RELIABLE_COMMANDS + 1;
	}
	for ( int i = start; i <= seq; i++ ) {
		ConfigstringCommand( clc.serverCommands[i & ( MAX_RELIABLE_COMMANDS - 1 )], changed );
	}
	if ( !changed.empty() ) {
		Putf( "{\"type\":\"configstrings\",\"serverTime\":%d,\"set\":{", snap.serverTime );
		qboolean first = qtrue;
		for ( auto &kv : changed ) {
			Putf( "%s\"%d\":", first ? "" : ",", kv.first );
			PutString( kv.second.c_str() );
			first = qfalse;
		}
		Put( "}}" );
		EndLine();
	}

	Putf( "{\"type\":\"snapshot\",\"serverTime\":%d,\"messageNum\":%d,\"snapFlags\":%d,\"ps\":",
		snap.serverTime, snap.messageNum, snap.snapFlags );
	PutFields( &snap.ps, dumpPsFields, ARRAY_LEN( dumpPsFields ) );
	Put( ",\"entities\":[" );
	for ( int i = 0; i < snap.numEntities; i++ ) {
		if ( i ) {
			Put( "," );
		}
		const entityState_t *es = &cl.parseEntities[( snap.parseEntitiesNum + i ) & ( MAX_PARSE_ENTITIES - 1 )];
		PutFields( es, dumpEsFields, ARRAY_LEN( dumpEsFields ) );
	}
	Put( "],\"commands\":[" );
	for ( int i = start; i <= seq; i++ ) {
		if ( i > start ) {
			Put( "," );
		}
		PutString( clc.serverCommands[i & ( MAX_RELIABLE_COMMANDS - 1 )] );
	}
	Put( "]}" );
	EndLine();
	if ( seq > dumpLastCommand ) {
		dumpLastCommand = seq;
	}
	dumpSnapshots++;
}

void CL_DemoDumpCompleted( void ) {
	if ( !Dumping() ) {
		return;
	}
	Begin();  // a demo without a gamestate or snapshot still gets a header and an end
	const long snapshots = dumpSnapshots;
	Finish( NULL );
	Com_Printf( "demo dump: %ld snapshots to %s\n", snapshots, DumpPath() );
	Com_Quit_f();
}

qboolean CL_DemoDumpError( const char *message ) {
	if ( !DumpPath()[0] ) {
		return qfalse;
	}
	if ( dumpFile && !dumpFinishing ) {
		Finish( message );
	}
	Com_Printf( "demo dump failed: %s\n", message );
	return qtrue;
}
