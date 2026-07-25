/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#include "g_dynbsp.h"

enum {
	RUNTIME_ROOM_NONE = -1
};

#define RUNTIME_WARP_POLICY_FILE "rwarp_maps.cfg"
#define RUNTIME_WARP_MAX_POLICY_RULES 256

typedef enum runtimeWarpPolicyRuleType_e {
	RUNTIME_WARP_POLICY_ALLOW,
	RUNTIME_WARP_POLICY_DENY
} runtimeWarpPolicyRuleType_t;

typedef struct runtimeWarpPolicyRule_s {
	runtimeWarpPolicyRuleType_t type;
	char pattern[MAX_QPATH];
} runtimeWarpPolicyRule_t;

static runtimeWarpPolicyRule_t g_runtimeWarpPolicyRules[RUNTIME_WARP_MAX_POLICY_RULES];
static int g_runtimeWarpPolicyRuleCount = 0;
static qboolean g_runtimeWarpPolicyLoaded = qfalse;

static void G_DynBSP_Print( int clientNum, const char *message )
{
	if ( clientNum >= 0 )
	{
		char text[MAX_STRING_CHARS];

		Q_strncpyz( text, message, sizeof( text ) );
		trap->SendServerCommand( clientNum, va( "print \"%s\"", text ) );
	}
	else
	{
		trap->Print( message );
	}
}

qboolean G_DynBSP_NormalizeMapName( const char *in, char *out, size_t outSize )
{
	size_t bspLen;

	if ( !in || !in[0] || !out || outSize < 1 )
	{
		return qfalse;
	}

	Q_strncpyz( out, in, outSize );
	if ( !Q_stricmpn( out, "maps/", 5 ) )
	{
		memmove( out, out + 5, strlen( out + 5 ) + 1 );
	}
	bspLen = strlen( out );
	if ( bspLen > 4 && !Q_stricmp( out + bspLen - 4, ".bsp" ) )
	{
		out[bspLen - 4] = 0;
	}

	if ( !out[0] || strchr( out, ';' ) || strchr( out, '"' ) || strchr( out, '\\' ) || strstr( out, ".." ) )
	{
		out[0] = 0;
		return qfalse;
	}

	return qtrue;
}

static char *G_RuntimeWarpTrim( char *text )
{
	char *end;

	while ( text && *text && ( *text == ' ' || *text == '\t' || *text == '\r' || *text == '\n' ) )
	{
		text++;
	}

	if ( !text || !*text )
	{
		return text;
	}

	end = text + strlen( text ) - 1;
	while ( end >= text && ( *end == ' ' || *end == '\t' || *end == '\r' || *end == '\n' ) )
	{
		*end = 0;
		end--;
	}

	return text;
}

static qboolean G_RuntimeWarpPatternHasWildcards( const char *pattern )
{
	return pattern && ( strchr( pattern, '*' ) || strchr( pattern, '?' ) ) ? qtrue : qfalse;
}

static int G_RuntimeWarpLowerChar( int c )
{
	if ( c >= 'A' && c <= 'Z' )
	{
		return c + ( 'a' - 'A' );
	}
	return c;
}

static qboolean G_RuntimeWarpWildcardMatch( const char *pattern, const char *text )
{
	while ( pattern && *pattern )
	{
		if ( *pattern == '*' )
		{
			while ( *pattern == '*' )
			{
				pattern++;
			}
			if ( !*pattern )
			{
				return qtrue;
			}
			while ( text && *text )
			{
				if ( G_RuntimeWarpWildcardMatch( pattern, text ) )
				{
					return qtrue;
				}
				text++;
			}
			return qfalse;
		}

		if ( !text || !*text )
		{
			return qfalse;
		}

		if ( *pattern != '?' && G_RuntimeWarpLowerChar( *pattern ) != G_RuntimeWarpLowerChar( *text ) )
		{
			return qfalse;
		}

		pattern++;
		text++;
	}

	return ( !text || !*text ) ? qtrue : qfalse;
}

static qboolean G_RuntimeWarpPatternMatchesMap( const char *pattern, const char *mapName )
{
	if ( !pattern || !pattern[0] || !mapName || !mapName[0] )
	{
		return qfalse;
	}

	if ( G_RuntimeWarpPatternHasWildcards( pattern ) )
	{
		return G_RuntimeWarpWildcardMatch( pattern, mapName );
	}

	return !Q_stricmp( pattern, mapName ) ? qtrue : qfalse;
}

static void G_RuntimeWarpPolicyAddRule( runtimeWarpPolicyRuleType_t type, const char *rawPattern )
{
	char normalized[MAX_QPATH];

	if ( g_runtimeWarpPolicyRuleCount >= RUNTIME_WARP_MAX_POLICY_RULES )
	{
		return;
	}
	if ( !G_DynBSP_NormalizeMapName( rawPattern, normalized, sizeof( normalized ) ) )
	{
		return;
	}

	g_runtimeWarpPolicyRules[g_runtimeWarpPolicyRuleCount].type = type;
	Q_strncpyz( g_runtimeWarpPolicyRules[g_runtimeWarpPolicyRuleCount].pattern, normalized,
		sizeof( g_runtimeWarpPolicyRules[g_runtimeWarpPolicyRuleCount].pattern ) );
	g_runtimeWarpPolicyRuleCount++;
}

static void G_RuntimeWarpPolicyParseLine( char *line )
{
	char *text;
	char *comment;
	char *command;
	char *pattern;
	runtimeWarpPolicyRuleType_t type = RUNTIME_WARP_POLICY_DENY;

	text = G_RuntimeWarpTrim( line );
	if ( !text || !text[0] || text[0] == '#' )
	{
		return;
	}

	comment = strstr( text, "//" );
	if ( comment )
	{
		*comment = 0;
	}
	text = G_RuntimeWarpTrim( text );
	if ( !text || !text[0] )
	{
		return;
	}

	command = text;
	while ( *text && *text != ' ' && *text != '\t' )
	{
		text++;
	}
	if ( *text )
	{
		*text = 0;
		text++;
	}
	pattern = G_RuntimeWarpTrim( text );

	if ( !Q_stricmp( command, "allow" ) )
	{
		type = RUNTIME_WARP_POLICY_ALLOW;
	}
	else if ( !Q_stricmp( command, "deny" ) || !Q_stricmp( command, "blacklist" ) )
	{
		type = RUNTIME_WARP_POLICY_DENY;
	}
	else
	{
		pattern = command;
	}

	if ( !pattern || !pattern[0] )
	{
		return;
	}

	G_RuntimeWarpPolicyAddRule( type, pattern );
}

static void G_RuntimeWarpPolicyLoad( void )
{
	fileHandle_t f = 0;
	int len;
	char *buffer;
	char *line;
	char *next;

	g_runtimeWarpPolicyRuleCount = 0;
	g_runtimeWarpPolicyLoaded = qtrue;

	len = trap->FS_Open( RUNTIME_WARP_POLICY_FILE, &f, FS_READ );
	if ( len <= 0 || !f )
	{
		if ( f )
		{
			trap->FS_Close( f );
		}
		return;
	}

	buffer = (char *)G_Alloc( len + 1 );
	trap->FS_Read( buffer, len, f );
	trap->FS_Close( f );
	buffer[len] = 0;

	line = buffer;
	while ( line && line[0] )
	{
		next = strchr( line, '\n' );
		if ( next )
		{
			*next = 0;
			next++;
		}
		G_RuntimeWarpPolicyParseLine( line );
		line = next;
	}
}

qboolean G_DynBSP_MapAllowedByPolicy( const char *bspModel, char *reason, int reasonSize )
{
	int i;
	qboolean hasAllow = qfalse;
	qboolean matchedAllow = qfalse;
	int policy = g_rwarpMapPolicy.integer;

	if ( reason && reasonSize > 0 )
	{
		reason[0] = 0;
	}

	if ( policy <= 0 )
	{
		return qtrue;
	}

	if ( !g_runtimeWarpPolicyLoaded )
	{
		G_RuntimeWarpPolicyLoad();
	}

	for ( i = 0; i < g_runtimeWarpPolicyRuleCount; i++ )
	{
		runtimeWarpPolicyRule_t *rule = &g_runtimeWarpPolicyRules[i];

		if ( rule->type == RUNTIME_WARP_POLICY_ALLOW )
		{
			hasAllow = qtrue;
			if ( G_RuntimeWarpPatternMatchesMap( rule->pattern, bspModel ) )
			{
				matchedAllow = qtrue;
			}
			continue;
		}

		if ( G_RuntimeWarpPatternMatchesMap( rule->pattern, bspModel ) )
		{
			if ( reason && reasonSize > 0 )
			{
				Com_sprintf( reason, reasonSize, "Runtime map %s is denied by %s.", bspModel, RUNTIME_WARP_POLICY_FILE );
			}
			return qfalse;
		}
	}

	if ( policy >= 2 && ( !hasAllow || !matchedAllow ) )
	{
		if ( reason && reasonSize > 0 )
		{
			Com_sprintf( reason, reasonSize, "Runtime map %s is not allowed by %s.", bspModel, RUNTIME_WARP_POLICY_FILE );
		}
		return qfalse;
	}

	return qtrue;
}

static void G_RuntimeRoomReset( runtimeRoom_t *room, int roomIndex )
{
	if ( !room )
	{
		return;
	}

	memset( room, 0, sizeof( *room ) );
	room->state = RUNTIME_ROOM_EMPTY;
	room->roomIndex = roomIndex;
	room->subBSPIndex = -1;
	room->modelIndex = -1;
	room->metaSlot = -1;
	room->runtimeBSPInstance = -1;
	room->holderEntNum = -1;
}

void G_RuntimeRoomsInit( void )
{
	int i;

	g_runtimeWarpPolicyLoaded = qfalse;
	g_runtimeWarpPolicyRuleCount = 0;

	level.runtimeWarpUsage.mapHasRooms = qfalse;

	for ( i = 0; i < MAX_CLIENTS; i++ )
	{
		level.runtimeWarpUsage.clientMapNames[i][0] = 0;
		level.runtimeWarpUsage.clientRoomIndex[i] = RUNTIME_ROOM_NONE;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		G_RuntimeRoomReset( &level.runtimeWarpUsage.rooms[i], i );
	}
}

static qboolean G_RuntimeRoomIndexValid( int roomIndex )
{
	return roomIndex >= 0 && roomIndex < MAX_RUNTIME_BSP_INSTANCES ? qtrue : qfalse;
}

static int G_RuntimeRoomFindIndexForMap( const char *mapName )
{
	int i;

	if ( !mapName || !mapName[0] )
	{
		return RUNTIME_ROOM_NONE;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		runtimeRoom_t *room = &level.runtimeWarpUsage.rooms[i];

		if ( room->state == RUNTIME_ROOM_EMPTY || !room->mapName[0] )
		{
			continue;
		}
		if ( !Q_stricmp( room->mapName, mapName ) )
		{
			return i;
		}
	}

	return RUNTIME_ROOM_NONE;
}

static int G_RuntimeRoomFindFreeIndex( void )
{
	int i;

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		if ( level.runtimeWarpUsage.rooms[i].state == RUNTIME_ROOM_EMPTY )
		{
			return i;
		}
	}

	return RUNTIME_ROOM_NONE;
}

static int G_RuntimeRoomRegisterMap( const char *mapName, int metaSlot, gentity_t *holder )
{
	int roomIndex;
	runtimeRoom_t *room;
	int occupantCount;
	int spectatorCount;

	if ( !mapName || !mapName[0] )
	{
		return RUNTIME_ROOM_NONE;
	}

	roomIndex = G_RuntimeRoomFindIndexForMap( mapName );
	if ( roomIndex == RUNTIME_ROOM_NONE )
	{
		if ( G_RuntimeRoomIndexValid( metaSlot ) && level.runtimeWarpUsage.rooms[metaSlot].state == RUNTIME_ROOM_EMPTY )
		{
			roomIndex = metaSlot;
		}
		else
		{
			roomIndex = G_RuntimeRoomFindFreeIndex();
		}
	}

	if ( roomIndex == RUNTIME_ROOM_NONE )
	{
		return RUNTIME_ROOM_NONE;
	}

	room = &level.runtimeWarpUsage.rooms[roomIndex];
	occupantCount = room->occupantCount;
	spectatorCount = room->spectatorCount;

	G_RuntimeRoomReset( room, roomIndex );
	room->state = RUNTIME_ROOM_ACTIVE;
	Q_strncpyz( room->mapName, mapName, sizeof( room->mapName ) );
	room->metaSlot = metaSlot;
	room->occupantCount = occupantCount;
	room->spectatorCount = spectatorCount;
	room->lastUsedTime = level.time;
	room->emptySinceTime = occupantCount > 0 ? 0 : level.time;

	if ( holder )
	{
		room->holderEntNum = holder->s.number;
		room->runtimeBSPInstance = holder->runtimeBSPInstance;
		room->modelIndex = holder->s.modelindex;
	}

	return roomIndex;
}

static void G_RuntimeRoomLeaveClient( int clientNum )
{
	int roomIndex;
	runtimeRoom_t *room;

	if ( clientNum < 0 || clientNum >= MAX_CLIENTS )
	{
		return;
	}

	roomIndex = level.runtimeWarpUsage.clientRoomIndex[clientNum];
	if ( G_RuntimeRoomIndexValid( roomIndex ) )
	{
		room = &level.runtimeWarpUsage.rooms[roomIndex];
		if ( room->occupantCount > 0 )
		{
			room->occupantCount--;
		}
		if ( room->occupantCount == 0 )
		{
			room->emptySinceTime = level.time;
		}
	}

	level.runtimeWarpUsage.clientRoomIndex[clientNum] = RUNTIME_ROOM_NONE;
	level.runtimeWarpUsage.clientMapNames[clientNum][0] = 0;
}

void G_RuntimeWarpSetClientMap( int clientNum, const char *mapName )
{
	int oldRoomIndex;
	int newRoomIndex;
	runtimeRoom_t *room;

	if ( clientNum < 0 || clientNum >= MAX_CLIENTS )
	{
		return;
	}

	if ( !mapName || !mapName[0] )
	{
		G_RuntimeRoomLeaveClient( clientNum );
		return;
	}

	oldRoomIndex = level.runtimeWarpUsage.clientRoomIndex[clientNum];
	newRoomIndex = G_RuntimeRoomFindIndexForMap( mapName );

	if ( oldRoomIndex == newRoomIndex && G_RuntimeRoomIndexValid( newRoomIndex ) )
	{
		room = &level.runtimeWarpUsage.rooms[newRoomIndex];
		room->lastUsedTime = level.time;
		Q_strncpyz( level.runtimeWarpUsage.clientMapNames[clientNum], mapName, sizeof( level.runtimeWarpUsage.clientMapNames[clientNum] ) );
		return;
	}

	G_RuntimeRoomLeaveClient( clientNum );

	if ( G_RuntimeRoomIndexValid( newRoomIndex ) )
	{
		room = &level.runtimeWarpUsage.rooms[newRoomIndex];
		room->occupantCount++;
		room->lastUsedTime = level.time;
		room->emptySinceTime = 0;
		level.runtimeWarpUsage.clientRoomIndex[clientNum] = newRoomIndex;
	}

	Q_strncpyz( level.runtimeWarpUsage.clientMapNames[clientNum], mapName, sizeof( level.runtimeWarpUsage.clientMapNames[clientNum] ) );
}

void G_RuntimeWarpClearClientMap( int clientNum )
{
	G_RuntimeRoomLeaveClient( clientNum );
}

qboolean G_RuntimeWarpClearClientActiveMap( int clientNum )
{
	gentity_t *ent;

	if ( clientNum < 0 || clientNum >= MAX_CLIENTS )
	{
		return qfalse;
	}

	ent = &g_entities[clientNum];
	if ( !G_SetClientMap( clientNum, "clear" ) )
	{
		return qfalse;
	}

	G_RuntimeWarpClearClientMap( clientNum );
	if ( ent->client )
	{
		G_SetRuntimeBSPInstance( ent, -1 );
	}
	return qtrue;
}

const char *G_RuntimeWarpClientMapName( int clientNum )
{
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS )
	{
		return "";
	}

	return level.runtimeWarpUsage.clientMapNames[clientNum];
}

qboolean G_RuntimeWarpClientInMainMap( int clientNum )
{
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS )
	{
		return qtrue;
	}

	return level.runtimeWarpUsage.clientMapNames[clientNum][0] ? qfalse : qtrue;
}

qboolean G_RuntimeWarpClientInMap( int clientNum, const char *mapName )
{
	if ( clientNum < 0 || clientNum >= MAX_CLIENTS || !mapName || !mapName[0] )
	{
		return qfalse;
	}

	return !Q_stricmp( level.runtimeWarpUsage.clientMapNames[clientNum], mapName ) ? qtrue : qfalse;
}

int G_RuntimeWarpRuntimeBSPInstanceForMap( const char *mapName )
{
	int roomIndex;

	if ( !mapName || !mapName[0] )
	{
		return -1;
	}

	roomIndex = G_RuntimeRoomFindIndexForMap( mapName );
	if ( !G_RuntimeRoomIndexValid( roomIndex ) )
	{
		return -1;
	}

	return level.runtimeWarpUsage.rooms[roomIndex].runtimeBSPInstance;
}

qboolean G_RuntimeWarpMapOccupied( const char *mapName )
{
	int i;
	int roomIndex;

	if ( !mapName || !mapName[0] )
	{
		return qfalse;
	}

	roomIndex = G_RuntimeRoomFindIndexForMap( mapName );
	if ( G_RuntimeRoomIndexValid( roomIndex ) && level.runtimeWarpUsage.rooms[roomIndex].occupantCount > 0 )
	{
		return qtrue;
	}

	for ( i = 0; i < level.maxclients; i++ )
	{
		gclient_t *client = &level.clients[i];

		if ( client->pers.connected == CON_DISCONNECTED )
		{
			continue;
		}
		if ( level.runtimeWarpUsage.clientMapNames[i][0]
			&& !Q_stricmp( level.runtimeWarpUsage.clientMapNames[i], mapName ) )
		{
			return qtrue;
		}
	}

	return qfalse;
}

int G_RuntimeWarpBuildOccupantList( const char *mapName, char *buffer, int bufferSize )
{
	int i;
	int count = 0;
	int mapRoomIndex;

	if ( buffer && bufferSize > 0 )
	{
		buffer[0] = 0;
	}

	if ( !mapName || !mapName[0] || !buffer || bufferSize < 1 )
	{
		return 0;
	}

	mapRoomIndex = G_RuntimeRoomFindIndexForMap( mapName );

	for ( i = 0; i < level.maxclients; i++ )
	{
		gclient_t *client = &level.clients[i];
		char cleanName[MAX_NETNAME];
		int clientRoomIndex;
		qboolean inMap = qfalse;

		if ( client->pers.connected == CON_DISCONNECTED )
		{
			continue;
		}

		clientRoomIndex = level.runtimeWarpUsage.clientRoomIndex[i];
		if ( G_RuntimeRoomIndexValid( mapRoomIndex ) && clientRoomIndex == mapRoomIndex )
		{
			inMap = qtrue;
		}
		else if ( level.runtimeWarpUsage.clientMapNames[i][0]
			&& !Q_stricmp( level.runtimeWarpUsage.clientMapNames[i], mapName ) )
		{
			inMap = qtrue;
		}

		if ( !inMap )
		{
			continue;
		}

		Q_strncpyz( cleanName, client->pers.netname, sizeof( cleanName ) );
		Q_strstrip( cleanName, "\"\n\r", "   " );
		Q_strcat( buffer, bufferSize, cleanName );
		Q_strcat( buffer, bufferSize, "\n" );
		count++;
	}

	return count;
}

static int G_DynBSPFindFreeMetaSlot( void )
{
	int i;
	char meta[MAX_STRING_CHARS];

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		trap->GetConfigstring( CS_RUNTIME_BSP_META + i, meta, sizeof( meta ) );
		if ( !meta[0] )
		{
			return i;
		}
	}

	return -1;
}

static qboolean G_DynBSPMetaMatchesMap( const char *meta, const char *bspModel )
{
	const char *separator;
	size_t mapLen;

	if ( !meta[0] )
	{
		return qfalse;
	}

	separator = strchr( meta, ';' );
	mapLen = separator ? (size_t)( separator - meta ) : strlen( meta );

	return strlen( bspModel ) == mapLen && !Q_stricmpn( meta, bspModel, mapLen ) ? qtrue : qfalse;
}

static qboolean G_DynBSPMapAlreadyLoaded( const char *bspModel )
{
	int i;
	char meta[MAX_STRING_CHARS];

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		trap->GetConfigstring( CS_RUNTIME_BSP_META + i, meta, sizeof( meta ) );
		if ( G_DynBSPMetaMatchesMap( meta, bspModel ) )
		{
			return qtrue;
		}
	}

	return qfalse;
}

static qboolean G_DynBSPMapFileExists( const char *bspModel )
{
	char path[MAX_QPATH];
	fileHandle_t f = 0;
	int len;

	if ( !bspModel || !bspModel[0] )
	{
		return qfalse;
	}

	Com_sprintf( path, sizeof( path ), "maps/%s.bsp", bspModel );
	len = trap->FS_Open( path, &f, FS_READ );
	if ( f )
	{
		trap->FS_Close( f );
	}

	return len >= 0 ? qtrue : qfalse;
}

static int G_RuntimeRoomTrackExistingMap( const char *bspModel )
{
	int i;
	char meta[MAX_STRING_CHARS];

	if ( !bspModel || !bspModel[0] )
	{
		return RUNTIME_ROOM_NONE;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		trap->GetConfigstring( CS_RUNTIME_BSP_META + i, meta, sizeof( meta ) );
		if ( G_DynBSPMetaMatchesMap( meta, bspModel ) )
		{
			return G_RuntimeRoomRegisterMap( bspModel, i, NULL );
		}
	}

	return RUNTIME_ROOM_NONE;
}

static void G_DynBSPSetMeta( int slot, const char *bspModel, const vec3_t origin )
{
	if ( slot < 0 || slot >= MAX_RUNTIME_BSP_INSTANCES )
	{
		return;
	}

	trap->SetConfigstring( CS_RUNTIME_BSP_META + slot, va( "%s;%.0f,%.0f,%.0f", bspModel, origin[0], origin[1], origin[2] ) );

	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game runtime metadata slot=%i configstring=%i value='%s;%.0f,%.0f,%.0f'\n",
			slot, CS_RUNTIME_BSP_META + slot, bspModel, origin[0], origin[1], origin[2] ) );
	}
}

void G_DynBSPSetRuntimeAmbient( int runtimeBSPInstance, const char *ambientSet )
{
	int i;
	char meta[BIG_INFO_STRING];
	char base[BIG_INFO_STRING];
	char *ambientSep;

	if ( runtimeBSPInstance < 0 || !ambientSet || !ambientSet[0] )
	{
		return;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		runtimeRoom_t *room = &level.runtimeWarpUsage.rooms[i];

		if ( room->state == RUNTIME_ROOM_EMPTY || room->runtimeBSPInstance != runtimeBSPInstance )
		{
			continue;
		}
		if ( room->metaSlot < 0 || room->metaSlot >= MAX_RUNTIME_BSP_INSTANCES )
		{
			return;
		}

		trap->GetConfigstring( CS_RUNTIME_BSP_META + room->metaSlot, meta, sizeof( meta ) );
		if ( !meta[0] )
		{
			return;
		}

		Q_strncpyz( base, meta, sizeof( base ) );
		ambientSep = strchr( base, ';' );
		if ( ambientSep )
		{
			ambientSep = strchr( ambientSep + 1, ';' );
			if ( ambientSep )
			{
				*ambientSep = 0;
			}
		}

		trap->SetConfigstring( CS_RUNTIME_BSP_META + room->metaSlot, va( "%s;%s", base, ambientSet ) );
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPDEBUG game runtime ambient instance=%i slot=%i configstring=%i value='%s;%s'\n",
				runtimeBSPInstance, room->metaSlot, CS_RUNTIME_BSP_META + room->metaSlot, base, ambientSet ) );
		}
		return;
	}
}

static gentity_t *G_SetupBSPInstance( gentity_t *ent, const char *bspModel, const vec3_t origin, float yaw, const char *teamFilter, qboolean networkSubEntities )
{
	char	temp[MAX_QPATH];
	int		bspConfigIndex;
	int		oldNumEntities;
	int		runtimeBSPInstance;
	int		setupStartTime = trap->Milliseconds();
	int		phaseStartTime;
	vec3_t	savedOriginAdjust;
	float	savedRotationAdjust;
	char	*savedTargetAdjust;
	char	savedTeamFilter[MAX_QPATH];

	if ( !bspModel || !bspModel[0] )
	{
		trap->Print( "G_SpawnBSPInstance: missing bsp model\n" );
		return NULL;
	}

	if ( !ent )
	{
		trap->Print( "G_SpawnBSPInstance: missing entity\n" );
		return NULL;
	}

	ent->classname = "misc_bsp";
	VectorCopy(origin, ent->s.origin);
	ent->s.angles[1] = yaw;
	ent->s.angles[0] = 0.0;
	ent->s.angles[2] = 0.0;

	ent->s.eFlags = EF_PERMANENT;

	Com_sprintf(temp, MAX_QPATH, "#%s", bspModel);
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game setup begin ent=%i bsp='%s' brush='%s' origin=(%.1f %.1f %.1f) yaw=%.1f eFlags=0x%x level.num_entities=%i\n",
			ent->s.number, bspModel, temp, ent->s.origin[0], ent->s.origin[1], ent->s.origin[2], ent->s.angles[1], ent->s.eFlags, level.num_entities ) );
	}
	phaseStartTime = trap->Milliseconds();
	trap->SetBrushModel( (sharedEntity_t *)ent, temp );
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game setup SetBrushModel map='%s' ent=%i ms=%i total=%i\n",
			bspModel, ent->s.number, trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - setupStartTime ) );
	}
	bspConfigIndex = G_BSPIndex(temp);
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game brushmodel ent=%i modelindex=%i bspConfigIndex=%i contents=0x%x bmodel=%i mins=(%.1f %.1f %.1f) maxs=(%.1f %.1f %.1f)\n",
			ent->s.number, ent->s.modelindex, bspConfigIndex, ent->r.contents, ent->r.bmodel,
			ent->r.mins[0], ent->r.mins[1], ent->r.mins[2], ent->r.maxs[0], ent->r.maxs[1], ent->r.maxs[2] ) );
	}

	level.mNumBSPInstances++;
	runtimeBSPInstance = level.mNumBSPInstances;
	G_SetRuntimeBSPInstance( ent, runtimeBSPInstance );
	Com_sprintf(temp, MAX_QPATH, "%d-", level.mNumBSPInstances);
	VectorCopy(level.mOriginAdjust, savedOriginAdjust);
	savedRotationAdjust = level.mRotationAdjust;
	savedTargetAdjust = level.mTargetAdjust;
	Q_strncpyz(savedTeamFilter, level.mTeamFilter, sizeof(savedTeamFilter));
	VectorClear(level.mOriginAdjust);
	level.mRotationAdjust = 0.0f;
	level.mTargetAdjust = temp;
	level.mBSPInstanceDepth++;

	if ( teamFilter && teamFilter[0] )
	{
		Q_strncpyz(level.mTeamFilter, teamFilter, sizeof(level.mTeamFilter));
	}
	else
	{
		level.mTeamFilter[0] = 0;
	}

	VectorCopy( ent->s.origin, ent->s.pos.trBase );
	VectorCopy( ent->s.origin, ent->r.currentOrigin );
	VectorCopy( ent->s.angles, ent->s.apos.trBase );
	VectorCopy( ent->s.angles, ent->r.currentAngles );

	ent->s.eType = ET_MOVER;

	phaseStartTime = trap->Milliseconds();
	trap->LinkEntity ((sharedEntity_t *)ent);
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game setup LinkEntity holder map='%s' ent=%i ms=%i total=%i\n",
			bspModel, ent->s.number, trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - setupStartTime ) );
	}
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game linked ent=%i linked=%i eType=%i svFlags=0x%x currentOrigin=(%.1f %.1f %.1f) absmin=(%.1f %.1f %.1f) absmax=(%.1f %.1f %.1f)\n",
			ent->s.number, ent->r.linked, ent->s.eType, ent->r.svFlags,
			ent->r.currentOrigin[0], ent->r.currentOrigin[1], ent->r.currentOrigin[2],
			ent->r.absmin[0], ent->r.absmin[1], ent->r.absmin[2], ent->r.absmax[0], ent->r.absmax[1], ent->r.absmax[2] ) );
	}

	trap->SetActiveSubBSP(ent->s.modelindex);
	oldNumEntities = level.num_entities;
	phaseStartTime = trap->Milliseconds();
	G_SpawnEntitiesFromString(qtrue);
	G_SpawnMapBoxFixes( bspModel, runtimeBSPInstance );
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game setup SpawnEntities map='%s' ent=%i oldEntities=%i newEntities=%i added=%i ms=%i total=%i\n",
			bspModel, ent->s.number, oldNumEntities, level.num_entities, level.num_entities - oldNumEntities,
			trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - setupStartTime ) );
	}
	if ( networkSubEntities )
	{
		int i;
		int networkedSubEntities = 0;

		phaseStartTime = trap->Milliseconds();
		for ( i = oldNumEntities; i < level.num_entities; i++ )
		{
			gentity_t *subEnt = &g_entities[i];

			if ( !subEnt->inuse )
			{
				continue;
			}

			G_SetRuntimeBSPInstance( subEnt, runtimeBSPInstance );
			if ( subEnt->isLogical )
			{
				continue;
			}

			if ( subEnt->classname
				&& !Q_stricmp( subEnt->classname, "target_speaker" )
				&& subEnt->s.soundSetIndex )
			{
				subEnt->s.eType = ET_MOVER;
				subEnt->s.eFlags2 |= EF2_HYPERSPACE;
				subEnt->s.loopIsSoundset = qtrue;
				subEnt->s.loopSound = BMS_MID;
				subEnt->s.solid = 0;
				subEnt->r.contents = 0;
			}

			subEnt->s.eFlags &= ~EF_PERMANENT;
			trap->LinkEntity( (sharedEntity_t *)subEnt );
			networkedSubEntities++;
		}

		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPDEBUG game runtime subentities networked parent=%i count=%i range=%i..%i\n",
				ent->s.number, networkedSubEntities, oldNumEntities, level.num_entities - 1 ) );
			trap->Print( va( "BSPTIME game setup NetworkSubEntities map='%s' ent=%i count=%i ms=%i total=%i\n",
				bspModel, ent->s.number, networkedSubEntities,
				trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - setupStartTime ) );
		}
	}
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game spawned subentities ent=%i modelindex=%i entitiesBefore=%i entitiesAfter=%i added=%i\n",
			ent->s.number, ent->s.modelindex, oldNumEntities, level.num_entities, level.num_entities - oldNumEntities ) );
	}
	trap->SetActiveSubBSP(-1);

	level.mBSPInstanceDepth--;
	VectorCopy(savedOriginAdjust, level.mOriginAdjust);
	level.mRotationAdjust = savedRotationAdjust;
	level.mTargetAdjust = savedTargetAdjust;
	Q_strncpyz(level.mTeamFilter, savedTeamFilter, sizeof(level.mTeamFilter));

	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game setup total map='%s' ent=%i entitiesAdded=%i total=%i\n",
			bspModel, ent->s.number, level.num_entities - oldNumEntities, trap->Milliseconds() - setupStartTime ) );
	}

	return ent;
}

static gentity_t *G_DynBSP_SpawnInstance( const char *bspModel, const vec3_t origin, float yaw, const char *teamFilter, int clientNum )
{
	gentity_t *ent;
	gentity_t *instance;
	int metaSlot;
	int spawnStartTime = trap->Milliseconds();
	int phaseStartTime;

	if ( G_DynBSPMapAlreadyLoaded( bspModel ) )
	{
		G_DynBSP_Print( clientNum, va( "Runtime BSP '%s' is already loaded.\n", bspModel ) );
		return NULL;
	}

	phaseStartTime = trap->Milliseconds();
	if ( !G_DynBSPMapFileExists( bspModel ) )
	{
		G_DynBSP_Print( clientNum, va( "Runtime BSP '%s' not found.\n", bspModel ) );
		return NULL;
	}
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game spawn FileExists map='%s' ms=%i total=%i\n",
			bspModel, trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - spawnStartTime ) );
	}

	phaseStartTime = trap->Milliseconds();
	metaSlot = G_DynBSPFindFreeMetaSlot();
	if ( metaSlot < 0 )
	{
		G_DynBSP_Print( clientNum, va( "Runtime BSP limit reached (%i).\n", MAX_RUNTIME_BSP_INSTANCES ) );
		return NULL;
	}
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game spawn FindFreeMeta map='%s' slot=%i ms=%i total=%i\n",
			bspModel, metaSlot, trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - spawnStartTime ) );
	}

	phaseStartTime = trap->Milliseconds();
	ent = G_Spawn(qtrue);
	if ( !ent )
	{
		G_DynBSP_Print( clientNum, "G_SpawnBSPInstance: G_Spawn failed\n" );
		return NULL;
	}
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game spawn G_Spawn map='%s' ent=%i ms=%i total=%i\n",
			bspModel, ent->s.number, trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - spawnStartTime ) );
	}

	phaseStartTime = trap->Milliseconds();
	instance = G_SetupBSPInstance(ent, bspModel, origin, yaw, teamFilter, qtrue);
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game spawn SetupInstance map='%s' ent=%i success=%i ms=%i total=%i\n",
			bspModel, ent->s.number, instance ? 1 : 0,
			trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - spawnStartTime ) );
	}
	if ( instance )
	{
		instance->s.eFlags &= ~EF_PERMANENT;
		instance->r.svFlags |= SVF_BROADCAST;
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPDEBUG game runtime instance ent=%i cleared EF_PERMANENT set SVF_BROADCAST eFlags=0x%x svFlags=0x%x modelindex=%i\n",
				instance->s.number, instance->s.eFlags, instance->r.svFlags, instance->s.modelindex ) );
		}
		phaseStartTime = trap->Milliseconds();
		G_DynBSPSetMeta( metaSlot, bspModel, origin );
		G_RuntimeRoomRegisterMap( bspModel, metaSlot, instance );
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPTIME game spawn MetaAndRoom map='%s' ent=%i slot=%i ms=%i total=%i\n",
				bspModel, instance->s.number, metaSlot,
				trap->Milliseconds() - phaseStartTime, trap->Milliseconds() - spawnStartTime ) );
		}
	}

	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game spawn total map='%s' success=%i total=%i\n",
			bspModel, instance ? 1 : 0, trap->Milliseconds() - spawnStartTime ) );
	}

	return instance;
}

gentity_t *G_SpawnBSPInstance( const char *bspModel, const vec3_t origin, float yaw, const char *teamFilter )
{
	return G_DynBSP_SpawnInstance( bspModel, origin, yaw, teamFilter, -1 );
}

qboolean G_DynBSP_SpawnMap( const char *bspModel, const vec3_t origin, int clientNum )
{
	if ( G_DynBSP_SpawnInstance( bspModel, origin, 0.0f, NULL, clientNum ) )
	{
		G_DynBSP_Print( clientNum, va( "Loaded BSP instance '%s' at %.0f %.0f %.0f\n", bspModel, origin[0], origin[1], origin[2] ) );
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPDEBUG game loadBSP normalized='%s' origin=(%.1f %.1f %.1f) yaw=0.0 lazyGamestate=1\n",
				bspModel, origin[0], origin[1], origin[2] ) );
		}
		return qtrue;
	}

	return qfalse;
}

qboolean G_DynBSP_EnsureMap( const char *bspModel, const vec3_t origin, int clientNum )
{
	int ensureStartTime = trap->Milliseconds();

	if ( G_DynBSPMapAlreadyLoaded( bspModel ) )
	{
		if ( G_RuntimeRoomFindIndexForMap( bspModel ) == RUNTIME_ROOM_NONE )
		{
			G_RuntimeRoomTrackExistingMap( bspModel );
		}
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPTIME game ensure map='%s' alreadyLoaded=1 total=%i\n",
				bspModel, trap->Milliseconds() - ensureStartTime ) );
		}
		return qtrue;
	}

	{
		qboolean spawned = G_DynBSP_SpawnMap( bspModel, origin, clientNum );
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPTIME game ensure map='%s' alreadyLoaded=0 success=%i total=%i\n",
				bspModel, spawned, trap->Milliseconds() - ensureStartTime ) );
		}
		return spawned;
	}
}

qboolean G_RuntimeRoomEnsureMap( const char *mapName, const vec3_t origin, int clientNum )
{
	int ensureStartTime = trap->Milliseconds();
	qboolean ensured;
	qboolean registered;

	if ( !g_gameImportHasRuntimeBSP )
	{
		if ( clientNum >= 0 && clientNum < MAX_CLIENTS )
		{
			trap->SendServerCommand( clientNum, "print \"Runtime BSP is not supported by this executable.\n\"" );
		}
		return qfalse;
	}

	if ( !mapName || !mapName[0] )
	{
		return qfalse;
	}

	ensured = G_DynBSP_EnsureMap( mapName, origin, clientNum );
	if ( !ensured )
	{
		if ( g_debugBSPInstances.integer )
		{
			trap->Print( va( "BSPTIME game roomEnsure map='%s' ensured=0 registered=0 total=%i\n",
				mapName, trap->Milliseconds() - ensureStartTime ) );
		}
		return qfalse;
	}

	registered = G_RuntimeRoomFindIndexForMap( mapName ) != RUNTIME_ROOM_NONE ? qtrue : qfalse;
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPTIME game roomEnsure map='%s' ensured=1 registered=%i total=%i\n",
			mapName, registered, trap->Milliseconds() - ensureStartTime ) );
	}
	return registered;
}

static qboolean G_DynBSPIdInList( int runtimeBSPInstance, const int *runtimeIds, int runtimeIdCount )
{
	int i;

	for ( i = 0; i < runtimeIdCount; i++ )
	{
		if ( runtimeIds[i] == runtimeBSPInstance )
		{
			return qtrue;
		}
	}

	return qfalse;
}

static int G_DynBSPCollectDynamicRuntimeIds( int *runtimeIds, int runtimeIdCapacity )
{
	int i;
	int runtimeIdCount = 0;

	for ( i = 0; i < level.num_entities; i++ )
	{
		gentity_t *ent = &g_entities[i];

		if ( !ent->inuse || ent->runtimeBSPInstance < 0 )
		{
			continue;
		}
		if ( !ent->classname || Q_stricmp( ent->classname, "misc_bsp" ) )
		{
			continue;
		}
		if ( ent->s.eFlags & EF_PERMANENT )
		{
			continue;
		}
		if ( G_DynBSPIdInList( ent->runtimeBSPInstance, runtimeIds, runtimeIdCount ) )
		{
			continue;
		}
		if ( runtimeIdCount >= runtimeIdCapacity )
		{
			break;
		}

		runtimeIds[runtimeIdCount++] = ent->runtimeBSPInstance;
	}

	return runtimeIdCount;
}

void G_DynBSP_ClearCommand( void )
{
	int runtimeIds[MAX_RUNTIME_BSP_INSTANCES];
	int runtimeIdCount;
	int freedEntities = 0;
	int freedLogicalEntities = 0;
	int clearedTargets = 0;
	int i;

	runtimeIdCount = G_DynBSPCollectDynamicRuntimeIds( runtimeIds, ARRAY_LEN( runtimeIds ) );

	for ( i = level.num_entities - 1; i >= MAX_CLIENTS; i-- )
	{
		gentity_t *ent = &g_entities[i];

		if ( !ent->inuse || ent->runtimeBSPInstance < 0 )
		{
			continue;
		}
		if ( !G_DynBSPIdInList( ent->runtimeBSPInstance, runtimeIds, runtimeIdCount ) )
		{
			continue;
		}

		G_FreeEntity( ent );
		freedEntities++;
	}

	for ( i = level.num_logicalents - 1; i >= 0; i-- )
	{
		gentity_t *ent = &g_logicalents[i];

		if ( !ent->inuse || ent->runtimeBSPInstance < 0 )
		{
			continue;
		}
		if ( !G_DynBSPIdInList( ent->runtimeBSPInstance, runtimeIds, runtimeIdCount ) )
		{
			continue;
		}

		G_FreeEntity( ent );
		freedLogicalEntities++;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ )
	{
		trap->SetConfigstring( CS_RUNTIME_BSP_META + i, "" );
	}

	G_RuntimeRoomsInit();

	clearedTargets = G_RuntimeWarpClearTargets();

	trap->Print( va( "Cleared %i runtime BSP instance%s, %i entities, %i logical entities, %i runtime warp target%s.\n",
		runtimeIdCount, runtimeIdCount == 1 ? "" : "s", freedEntities, freedLogicalEntities,
		clearedTargets, clearedTargets == 1 ? "" : "s" ) );

	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game clearBSPs runtimeIds=%i freedEntities=%i freedLogical=%i clearedTargets=%i\n",
			runtimeIdCount, freedEntities, freedLogicalEntities, clearedTargets ) );
	}
}

void SP_misc_bsp(gentity_t *ent)
{
	char	*out;
	char	*teamFilter;
	float	newAngle;
	int		tempint;

	G_SpawnFloat( "angle", "0", &newAngle );
	G_SpawnString("bspmodel", "", &out);
	G_SpawnString("teamfilter", "", &teamFilter);

	G_SpawnInt( "spacing", "0", &tempint);
	ent->s.time2 = tempint;
	G_SpawnInt( "flatten", "0", &tempint);
	ent->s.time = tempint;

	G_SetupBSPInstance(ent, out, ent->s.origin, newAngle, teamFilter, qfalse);
}

void G_DynBSP_LoadCommand( void )
{
	char bsp[MAX_QPATH];
	char arg[MAX_TOKEN_CHARS];
	vec3_t origin;
	float yaw = 0.0f;

	if ( trap->Argc() < 5 )
	{
		trap->Print( "Usage: loadBSP <bsp> <x> <y> <z>\n" );
		trap->Print( "Example: loadBSP q3dm17 20000 0 0\n" );
		return;
	}

	trap->Argv( 1, arg, sizeof( arg ) );
	if ( g_debugBSPInstances.integer )
	{
		trap->Print( va( "BSPDEBUG game loadBSP rawArg='%s' argc=%i\n", arg, trap->Argc() ) );
	}
	if ( !G_DynBSP_NormalizeMapName( arg, bsp, sizeof( bsp ) ) )
	{
		trap->Print( "Invalid BSP map name.\n" );
		return;
	}

	trap->Argv( 2, arg, sizeof( arg ) );
	origin[0] = atof( arg );
	trap->Argv( 3, arg, sizeof( arg ) );
	origin[1] = atof( arg );
	trap->Argv( 4, arg, sizeof( arg ) );
	origin[2] = atof( arg );

	if ( trap->Argc() >= 6 )
	{
		trap->Argv( 5, arg, sizeof( arg ) );
		yaw = atof( arg );
		if ( yaw != 0.0f )
		{
			trap->Print( "Runtime BSP rotation is not supported; loadBSP yaw must be 0.\n" );
			return;
		}
	}

	G_DynBSP_SpawnMap( bsp, origin, -1 );
}
