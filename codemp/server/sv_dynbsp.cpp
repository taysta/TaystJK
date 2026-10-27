/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#include "server/sv_dynbsp.h"
#include "qcommon/cm_public.h"

int SV_DynBSPDebugLevel( void ) {
	static cvar_t *sv_debugBSPInstances = NULL;

	if ( !sv_debugBSPInstances ) {
		sv_debugBSPInstances = Cvar_Get( "sv_debugBSPInstances", "1", 0 );
	}

	return sv_debugBSPInstances->integer;
}

qboolean SV_DynBSPDebugEnabled( void ) {
	return SV_DynBSPDebugLevel() ? qtrue : qfalse;
}

static qboolean SV_DynBSPIsBSPModelConfigstring( int index ) {
	return index >= CS_BSP_MODELS && index < CS_BSP_MODELS + MAX_SUB_BSP ? qtrue : qfalse;
}

static qboolean SV_DynBSPIsRuntimeMetaConfigstring( int index ) {
	return index >= CS_RUNTIME_BSP_META && index < CS_RUNTIME_BSP_META + MAX_RUNTIME_BSP_INSTANCES ? qtrue : qfalse;
}

static void SV_DynBSPClientRuntimeConfigMap( client_t *client, char *out, int outSize );

static void SV_DynBSPNormalizeConfigMapName( const char *in, char *out, int outSize ) {
	size_t len;

	if ( !out || outSize <= 0 ) {
		return;
	}

	out[0] = 0;
	if ( !in || !in[0] ) {
		return;
	}

	if ( in[0] == '#' ) {
		in++;
	}
	if ( !Q_stricmpn( in, "maps/", 5 ) ) {
		in += 5;
	}

	Q_strncpyz( out, in, outSize );
	len = strlen( out );
	if ( len > 4 && !Q_stricmp( out + len - 4, ".bsp" ) ) {
		out[len - 4] = 0;
	}
}

static qboolean SV_DynBSPRuntimeMetaMatchesMap( const char *meta, const char *mapName ) {
	const char *separator;
	size_t mapLen;

	if ( !meta || !meta[0] || !mapName || !mapName[0] ) {
		return qfalse;
	}

	separator = strchr( meta, ';' );
	mapLen = separator ? (size_t)( separator - meta ) : strlen( meta );

	return strlen( mapName ) == mapLen && !Q_stricmpn( meta, mapName, mapLen ) ? qtrue : qfalse;
}

static qboolean SV_DynBSPRuntimeMetaAmbientForMap( const char *mapName, char *out, int outSize ) {
	int i;

	if ( !out || outSize <= 0 ) {
		return qfalse;
	}

	out[0] = 0;
	if ( !mapName || !mapName[0] ) {
		return qfalse;
	}

	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ ) {
		const char *meta = sv.configstrings[CS_RUNTIME_BSP_META + i];
		const char *separator;

		if ( !SV_DynBSPRuntimeMetaMatchesMap( meta, mapName ) ) {
			continue;
		}

		separator = strchr( meta, ';' );
		if ( !separator ) {
			return qfalse;
		}

		separator = strchr( separator + 1, ';' );
		if ( !separator || !separator[1] ) {
			return qfalse;
		}

		Q_strncpyz( out, separator + 1, outSize );
		return qtrue;
	}

	return qfalse;
}

static qboolean SV_DynBSPClientRuntimeItems( client_t *client, char *out, int outSize ) {
	char targetMap[MAX_QPATH];
	sharedEntity_t *holder;
	int runtimeBSPInstance;
	int itemCount;
	int i;
	const char *baseItems;

	if ( !client || !out || outSize <= 0 ) {
		return qfalse;
	}

	SV_DynBSPClientRuntimeConfigMap( client, targetMap, sizeof( targetMap ) );
	if ( !targetMap[0] ) {
		return qfalse;
	}

	holder = SV_DynBSPInstanceForMap( targetMap );
	if ( !holder ) {
		return qfalse;
	}

	runtimeBSPInstance = SV_RuntimeBSPInstanceForGentity( holder );
	if ( runtimeBSPInstance < 0 ) {
		return qfalse;
	}

	itemCount = MAX_ITEMS;
	if ( itemCount >= outSize ) {
		itemCount = outSize - 1;
	}
	if ( itemCount <= 0 ) {
		out[0] = 0;
		return qfalse;
	}

	baseItems = sv.configstrings[CS_ITEMS] ? sv.configstrings[CS_ITEMS] : "";
	for ( i = 0; i < itemCount; i++ ) {
		out[i] = baseItems[i] == '1' ? '1' : '0';
	}
	out[itemCount] = 0;

	for ( i = 0; i < sv.num_entities; i++ ) {
		sharedEntity_t *ent = SV_GentityNum( i );
		int itemIndex;

		if ( !ent || ent->s.eType != ET_ITEM ) {
			continue;
		}
		if ( SV_RuntimeBSPInstanceForGentity( ent ) != runtimeBSPInstance ) {
			continue;
		}

		itemIndex = ent->s.modelindex;
		if ( itemIndex > 0 && itemIndex < itemCount ) {
			out[itemIndex] = '1';
		}
	}

	return qtrue;
}

static qboolean SV_DynBSPInfoTokenExists( const char *list, const char *token ) {
	const char *p;
	size_t tokenLen;

	if ( !list || !token || !token[0] ) {
		return qfalse;
	}

	tokenLen = strlen( token );
	p = list;
	while ( *p ) {
		while ( *p == ' ' ) {
			p++;
		}
		if ( !*p ) {
			break;
		}

		if ( !Q_stricmpn( p, token, tokenLen ) && ( p[tokenLen] == ' ' || p[tokenLen] == '\0' ) ) {
			return qtrue;
		}

		while ( *p && *p != ' ' ) {
			p++;
		}
	}

	return qfalse;
}

static void SV_DynBSPAppendInfoToken( char *info, int infoSize, const char *key, const char *token ) {
	char value[BIG_INFO_VALUE];

	if ( !info || infoSize <= 0 || !key || !token || !token[0] ) {
		return;
	}

	Q_strncpyz( value, Info_ValueForKey( info, key ), sizeof( value ) );
	if ( SV_DynBSPInfoTokenExists( value, token ) ) {
		return;
	}

	if ( value[0] ) {
		Q_strcat( value, sizeof( value ), " " );
	}
	Q_strcat( value, sizeof( value ), token );
	Info_SetValueForKey_Big( info, key, value );
}

static void SV_DynBSPAppendRuntimeMapPakRefs( char *info, int infoSize, const char *mapName ) {
	char path[MAX_QPATH];
	char pakName[MAX_OSPATH];
	char checksumString[32];
	int checksum;

	if ( !info || infoSize <= 0 || !mapName || !mapName[0] ) {
		return;
	}

	Com_sprintf( path, sizeof( path ), "maps/%s.bsp", mapName );
	if ( !FS_PakInfoForFile( path, pakName, sizeof( pakName ), &checksum ) ) {
		return;
	}

	Com_sprintf( checksumString, sizeof( checksumString ), "%i", checksum );
	SV_DynBSPAppendInfoToken( info, infoSize, "sv_referencedPaks", checksumString );
	SV_DynBSPAppendInfoToken( info, infoSize, "sv_referencedPakNames", pakName );
}

static void SV_DynBSPClientRuntimeConfigMap( client_t *client, char *out, int outSize ) {
	playerState_t *ps;

	if ( !out || outSize <= 0 ) {
		return;
	}

	out[0] = 0;
	if ( !client ) {
		return;
	}

	if ( client->runtimeMapName[0] ) {
		Q_strncpyz( out, client->runtimeMapName, outSize );
		return;
	}

	ps = SV_GameClientNum( client - svs.clients );
	if ( ps && ( ps->pm_flags & PMF_FOLLOW )
		&& ps->clientNum >= 0
		&& ps->clientNum < sv_maxclients->integer
		&& svs.clients[ps->clientNum].runtimeMapName[0] ) {
		Q_strncpyz( out, svs.clients[ps->clientNum].runtimeMapName, outSize );
		return;
	}

	if ( client->spectatorRuntimeMapName[0] ) {
		Q_strncpyz( out, client->spectatorRuntimeMapName, outSize );
	}
}

static qboolean SV_DynBSPShouldSendRuntimeConfigstring( client_t *client, int index ) {
	char targetMap[MAX_QPATH];
	char configMap[MAX_QPATH];

	if ( !client || client->sendBSPModelsGeneration != sv.bspModelsGeneration ) {
		return qfalse;
	}

	SV_DynBSPClientRuntimeConfigMap( client, targetMap, sizeof( targetMap ) );
	if ( !targetMap[0] ) {
		return qfalse;
	}

	if ( SV_DynBSPIsRuntimeMetaConfigstring( index ) ) {
		return SV_DynBSPRuntimeMetaMatchesMap( sv.configstrings[index], targetMap );
	}

	if ( SV_DynBSPIsBSPModelConfigstring( index ) ) {
		SV_DynBSPNormalizeConfigMapName( sv.configstrings[index], configMap, sizeof( configMap ) );
		return configMap[0] && !Q_stricmp( configMap, targetMap ) ? qtrue : qfalse;
	}

	return qfalse;
}

void SV_DynBSPConfigstringChanged( int index ) {
	if ( SV_DynBSPIsBSPModelConfigstring( index ) ) {
		if ( sv.state == SS_GAME || sv.restarting ) {
			if ( !sv.firstRuntimeBSPModelConfigstring || index < sv.firstRuntimeBSPModelConfigstring ) {
				sv.firstRuntimeBSPModelConfigstring = index;
			}
			sv.bspModelsGeneration++;
		}
		return;
	}

	if ( SV_DynBSPIsRuntimeMetaConfigstring( index ) ) {
		if ( sv.state == SS_GAME || sv.restarting ) {
			sv.bspModelsGeneration++;
		}
	}
}

qboolean SV_DynBSPShouldSendConfigstring( client_t *client, int index ) {
	if ( SV_DynBSPIsRuntimeMetaConfigstring( index ) ) {
		return SV_DynBSPShouldSendRuntimeConfigstring( client, index );
	}

	if ( !SV_DynBSPIsBSPModelConfigstring( index ) ) {
		return qtrue;
	}
	if ( !sv.firstRuntimeBSPModelConfigstring || index < sv.firstRuntimeBSPModelConfigstring ) {
		return qtrue;
	}

	return SV_DynBSPShouldSendRuntimeConfigstring( client, index );
}

const char *SV_DynBSPClientConfigstring( client_t *client, int index, char *buffer, int bufferSize ) {
	if ( index == CS_ITEMS && buffer && bufferSize > 0 ) {
		if ( SV_DynBSPClientRuntimeItems( client, buffer, bufferSize ) ) {
			return buffer;
		}
	}

	if ( index == CS_GLOBAL_AMBIENT_SET && buffer && bufferSize > 0 ) {
		char targetMap[MAX_QPATH];

		SV_DynBSPClientRuntimeConfigMap( client, targetMap, sizeof( targetMap ) );
		if ( targetMap[0] && SV_DynBSPRuntimeMetaAmbientForMap( targetMap, buffer, bufferSize ) ) {
			return buffer;
		}
	}

	if ( client && buffer && bufferSize > 0 ) {
		if ( index == CS_SYSTEMINFO ) {
			char targetMap[MAX_QPATH];

			Q_strncpyz( buffer, sv.configstrings[index], bufferSize );
			if ( client->runtimeMapName[0] ) {
				Info_SetValueForKey_Big( buffer, "sv_serverid", va( "%i", SV_DynBSPClientServerId( client ) ) );
			}
			SV_DynBSPClientRuntimeConfigMap( client, targetMap, sizeof( targetMap ) );
			SV_DynBSPAppendRuntimeMapPakRefs( buffer, bufferSize, targetMap );
			return buffer;
		}

		if ( client->runtimeMapName[0] && index == CS_SERVERINFO ) {
			Q_strncpyz( buffer, sv.configstrings[index], bufferSize );
			Info_SetValueForKey( buffer, "mapname", client->runtimeMapName );
			return buffer;
		}
	}

	return sv.configstrings[index];
}

int SV_DynBSPClientServerId( client_t *client ) {
	if ( client && client->runtimeMapName[0] && client->runtimeMapServerId ) {
		return client->runtimeMapServerId;
	}

	return sv.serverId;
}

void SV_DynBSPSetClientMap( client_t *client, const char *mapName, int bspIndex ) {
	// Real serverIds are non-negative (derived from frame time), so a negative
	// counter can never collide with a serverId a lagging client still holds.
	static int runtimeServerIdCounter = 0;

	if ( !client || !mapName || !mapName[0] ) {
		return;
	}

	runtimeServerIdCounter = runtimeServerIdCounter <= -0x7FFFFFFE ? -1 : runtimeServerIdCounter - 1;

	Q_strncpyz( client->runtimeMapName, mapName, sizeof( client->runtimeMapName ) );
	client->runtimeMapServerId = runtimeServerIdCounter;
	client->runtimeMapBSPIndex = bspIndex;
}

void SV_DynBSPClearClientMap( client_t *client ) {
	if ( !client ) {
		return;
	}

	client->runtimeMapName[0] = 0;
	client->runtimeMapServerId = 0;
	client->runtimeMapBSPIndex = -1;
	client->spectatorRuntimeMapName[0] = 0;
	if ( client->gentity ) {
		SV_SetRuntimeBSPInstanceForGentity( client->gentity, -1 );
	}
}

void SV_DynBSPClearAllClientMaps( void ) {
	int i;

	if ( !svs.clients ) {
		return;
	}

	for ( i = 0; i < sv_maxclients->integer; i++ ) {
		SV_DynBSPClearClientMap( &svs.clients[i] );
		svs.clients[i].loadedBSPModelsGeneration = -1;
		svs.clients[i].sendBSPModelsGeneration = -1;
	}
}

int SV_DynBSPClientBSPIndex( client_t *client ) {
	if ( client && client->runtimeMapName[0] ) {
		return client->runtimeMapBSPIndex;
	}

	return -1;
}

static int SV_DynBSPMapBSPIndex( const char *mapName ) {
	char expanded[MAX_QPATH];
	int modelIndex;

	if ( !mapName || !mapName[0] ) {
		return -1;
	}

	Com_sprintf( expanded, sizeof( expanded ), "maps/%s.bsp", mapName );
	modelIndex = CM_LoadSubBSP( expanded, qfalse );
	if ( modelIndex <= 0 ) {
		return -1;
	}

	return CM_FindSubBSP( modelIndex );
}

int SV_DynBSPClientCollisionBSPIndex( client_t *client ) {
	playerState_t *ps;

	if ( !client ) {
		return -1;
	}

	if ( client->runtimeMapName[0] ) {
		return client->runtimeMapBSPIndex;
	}

	if ( !client->spectatorRuntimeMapName[0] ) {
		return -1;
	}

	ps = SV_GameClientNum( client - svs.clients );
	if ( !ps || ( ps->pm_flags & PMF_FOLLOW )
		|| ( ps->pm_type != PM_SPECTATOR && ps->persistant[PERS_TEAM] != TEAM_SPECTATOR ) ) {
		return -1;
	}

	return SV_DynBSPMapBSPIndex( client->spectatorRuntimeMapName );
}

// Positive-result caches so per-entity hot loops (snapshot build, trace clip,
// entity linking) don't rescan the entity list for runtime BSP holders.
// Entries are validated against the live entity on every hit, so a freed or
// replaced holder simply falls back to the full scan.
typedef struct dynBSPHolderCacheEntry_s {
	int key;	// modelIndex or runtimeBSPInstance depending on cache
	int entNum;
} dynBSPHolderCacheEntry_t;

#define DYNBSP_HOLDER_CACHE_SIZE ( MAX_SUB_BSP * 2 )

static dynBSPHolderCacheEntry_t dynBSPMapHolderCache[DYNBSP_HOLDER_CACHE_SIZE];
static dynBSPHolderCacheEntry_t dynBSPInstanceHolderCache[DYNBSP_HOLDER_CACHE_SIZE];

static sharedEntity_t *SV_DynBSPHolderCacheLookup( dynBSPHolderCacheEntry_t *cache, int key,
	qboolean (*validate)( sharedEntity_t *ent, int key ) ) {
	dynBSPHolderCacheEntry_t *entry = &cache[( key >= 0 ? key : -key ) % DYNBSP_HOLDER_CACHE_SIZE];
	sharedEntity_t *ent;

	if ( entry->key != key || entry->entNum < 0 || entry->entNum >= sv.num_entities ) {
		return NULL;
	}

	ent = SV_GentityNum( entry->entNum );
	if ( !validate( ent, key ) ) {
		return NULL;
	}

	return ent;
}

static void SV_DynBSPHolderCacheStore( dynBSPHolderCacheEntry_t *cache, int key, int entNum ) {
	dynBSPHolderCacheEntry_t *entry = &cache[( key >= 0 ? key : -key ) % DYNBSP_HOLDER_CACHE_SIZE];

	entry->key = key;
	entry->entNum = entNum;
}

static qboolean SV_DynBSPValidateMapHolder( sharedEntity_t *ent, int modelIndex ) {
	return ent && ent->r.linked && !( ent->s.eFlags & EF_PERMANENT )
		&& SV_DynBSPIsInstanceEntity( ent ) && ent->s.modelindex == modelIndex ? qtrue : qfalse;
}

static qboolean SV_DynBSPValidateInstanceHolder( sharedEntity_t *ent, int runtimeBSPInstance ) {
	return ent && SV_DynBSPIsInstanceEntity( ent )
		&& SV_RuntimeBSPInstanceForGentity( ent ) == runtimeBSPInstance ? qtrue : qfalse;
}

sharedEntity_t *SV_DynBSPInstanceForMap( const char *mapName ) {
	char expanded[MAX_QPATH];
	int modelIndex;
	int e;
	sharedEntity_t *cached;

	if ( !mapName || !mapName[0] ) {
		return NULL;
	}

	Com_sprintf( expanded, sizeof( expanded ), "maps/%s.bsp", mapName );
	modelIndex = CM_LoadSubBSP( expanded, qfalse );
	if ( modelIndex <= 0 ) {
		return NULL;
	}

	cached = SV_DynBSPHolderCacheLookup( dynBSPMapHolderCache, modelIndex, SV_DynBSPValidateMapHolder );
	if ( cached ) {
		return cached;
	}

	for ( e = 0; e < sv.num_entities; e++ ) {
		sharedEntity_t *ent = SV_GentityNum( e );

		if ( !SV_DynBSPValidateMapHolder( ent, modelIndex ) ) {
			continue;
		}

		SV_DynBSPHolderCacheStore( dynBSPMapHolderCache, modelIndex, e );
		return ent;
	}

	return NULL;
}

sharedEntity_t *SV_DynBSPHolderForInstance( int runtimeBSPInstance ) {
	int e;
	sharedEntity_t *cached;

	if ( runtimeBSPInstance < 0 ) {
		return NULL;
	}

	cached = SV_DynBSPHolderCacheLookup( dynBSPInstanceHolderCache, runtimeBSPInstance, SV_DynBSPValidateInstanceHolder );
	if ( cached ) {
		return cached;
	}

	for ( e = 0; e < sv.num_entities; e++ ) {
		sharedEntity_t *ent = SV_GentityNum( e );

		if ( !SV_DynBSPValidateInstanceHolder( ent, runtimeBSPInstance ) ) {
			continue;
		}

		SV_DynBSPHolderCacheStore( dynBSPInstanceHolderCache, runtimeBSPInstance, e );
		return ent;
	}

	return NULL;
}

qboolean SV_DynBSPSpectatorProjectPlayerState( client_t *client, playerState_t *ps ) {
	client_t *targetClient;
	sharedEntity_t *holder;
	const char *mapName;
	int clientNum;

	if ( !client || !ps ) {
		return qfalse;
	}

	if ( client->runtimeMapName[0] ) {
		return qfalse;
	}

	clientNum = (int)( client - svs.clients );
	if ( ps->pm_flags & PMF_FOLLOW ) {
		if ( ps->clientNum < 0 || ps->clientNum >= sv_maxclients->integer || ps->clientNum == clientNum ) {
			client->spectatorRuntimeMapName[0] = 0;
			return qfalse;
		}

		targetClient = &svs.clients[ps->clientNum];
		if ( !targetClient->runtimeMapName[0] ) {
			client->spectatorRuntimeMapName[0] = 0;
			return qfalse;
		}

		mapName = targetClient->runtimeMapName;
	}
	else {
		if ( ps->pm_type != PM_SPECTATOR && ps->persistant[PERS_TEAM] != TEAM_SPECTATOR ) {
			client->spectatorRuntimeMapName[0] = 0;
			return qfalse;
		}

		if ( !client->spectatorRuntimeMapName[0] ) {
			return qfalse;
		}
		mapName = client->spectatorRuntimeMapName;
	}

	holder = SV_DynBSPInstanceForMap( mapName );
	if ( !holder ) {
		if ( ps->pm_flags & PMF_FOLLOW ) {
			client->spectatorRuntimeMapName[0] = 0;
		}
		return qfalse;
	}

	Q_strncpyz( client->spectatorRuntimeMapName, mapName, sizeof( client->spectatorRuntimeMapName ) );

	// Diagnostic spectator projection: active runtime maps are yaw-only unsupported,
	// so local clientMap coords project into the matching runtime BSP holder by origin.
	VectorAdd( ps->origin, holder->r.currentOrigin, ps->origin );
	return qtrue;
}

void SV_DynBSPClientEnteredWorld( client_t *client ) {
	if ( client->sendBSPModelsGeneration == sv.bspModelsGeneration ) {
		client->loadedBSPModelsGeneration = sv.bspModelsGeneration;
	}
}

void SV_DynBSPPrepareClientGameState( client_t *client ) {
	if ( client && SV_DynBSPDebugEnabled() ) {
		playerState_t *ps = SV_GameClientNum( client - svs.clients );
		int followTarget = -1;
		const char *followTargetMap = "";

		if ( ps && ( ps->pm_flags & PMF_FOLLOW )
			&& ps->clientNum >= 0
			&& ps->clientNum < sv_maxclients->integer ) {
			followTarget = ps->clientNum;
			followTargetMap = svs.clients[followTarget].runtimeMapName;
		}

		Com_Printf( "BSPDEBUG prepare gamestate client=%li name='%s' runtimeMap='%s' spectatorMap='%s' followTarget=%i followTargetMap='%s' loadedGen=%i oldSendGen=%i newSendGen=%i currentGen=%i firstRuntimeCS=%i\n",
			(long)( client - svs.clients ), client->name,
			client->runtimeMapName, client->spectatorRuntimeMapName,
			followTarget, followTargetMap,
			client->loadedBSPModelsGeneration, client->sendBSPModelsGeneration,
			sv.bspModelsGeneration, sv.bspModelsGeneration, sv.firstRuntimeBSPModelConfigstring );
	}
	client->sendBSPModelsGeneration = sv.bspModelsGeneration;
}

qboolean SV_DynBSPIsInstanceEntity( sharedEntity_t *ent ) {
	if ( !ent || !ent->classname ) {
		return qfalse;
	}

	return !Q_stricmp( ent->classname, "misc_bsp" ) ? qtrue : qfalse;
}

static qboolean SV_DynBSPPointInEntityBounds( const vec3_t point, sharedEntity_t *ent ) {
	if ( !ent ) {
		return qfalse;
	}

	return point[0] >= ent->r.absmin[0] && point[0] <= ent->r.absmax[0]
		&& point[1] >= ent->r.absmin[1] && point[1] <= ent->r.absmax[1]
		&& point[2] >= ent->r.absmin[2] && point[2] <= ent->r.absmax[2] ? qtrue : qfalse;
}

sharedEntity_t *SV_DynBSPInstanceForPoint( const vec3_t point ) {
	int e;

	for ( e = 0; e < sv.num_entities; e++ ) {
		sharedEntity_t *ent = SV_GentityNum( e );

		if ( !ent->r.linked || ( ent->s.eFlags & EF_PERMANENT ) ) {
			continue;
		}

		if ( SV_DynBSPIsInstanceEntity( ent ) && SV_DynBSPPointInEntityBounds( point, ent ) ) {
			return ent;
		}
	}

	return NULL;
}

void SV_DynBSPWorldToLocalPoint( sharedEntity_t *holder, const vec3_t in, vec3_t out ) {
	vec3_t local;
	vec3_t forward, right, up;

	VectorSubtract( in, holder->r.currentOrigin, local );
	AngleVectors( holder->r.currentAngles, forward, right, up );

	out[0] = DotProduct( local, forward );
	out[1] = -DotProduct( local, right );
	out[2] = DotProduct( local, up );
}

qboolean SV_DynBSPEntityVisibleInPVS( svEntity_t *svEnt, byte *pvs ) {
	int i, l;

	if ( !svEnt->numClusters ) {
		return qfalse;
	}

	l = 0;
	for ( i = 0; i < svEnt->numClusters; i++ ) {
		l = svEnt->clusternums[i];
		if ( pvs[l >> 3] & ( 1 << ( l & 7 ) ) ) {
			return qtrue;
		}
	}

	if ( svEnt->lastCluster ) {
		for ( ; l <= svEnt->lastCluster; l++ ) {
			if ( pvs[l >> 3] & ( 1 << ( l & 7 ) ) ) {
				return qtrue;
			}
		}
	}

	return qfalse;
}

void SV_DynBSPSnapshotDebug( sharedEntity_t *ent, int entNum, clientSnapshot_t *frame, const char *reason ) {
	static int nextPrintTime[MAX_GENTITIES];
	svEntity_t *svEnt;
	int debugLevel = SV_DynBSPDebugLevel();

	if ( !debugLevel || !SV_DynBSPIsInstanceEntity( ent ) ) {
		return;
	}
	if ( debugLevel < 2 && reason && !Q_stricmpn( reason, "add-", 4 ) ) {
		return;
	}
	if ( debugLevel < 2 && reason
		&& ( !Q_stricmp( reason, "skip-runtime-bsp-client-unloaded" )
			|| !Q_stricmp( reason, "skip-clientMap-holder" )
			|| !Q_stricmp( reason, "skip-dimension-snapshot" ) ) ) {
		return;
	}
	if ( entNum < 0 || entNum >= MAX_GENTITIES ) {
		return;
	}

	if ( svs.time < nextPrintTime[entNum] ) {
		return;
	}
	nextPrintTime[entNum] = svs.time + 1000;

	svEnt = SV_SvEntityForGentity( ent );
	Com_Printf( "BSPDEBUG snapshot client=%i ent=%i reason=%s linked=%i eFlags=0x%x svFlags=0x%x modelindex=%i eType=%i origin=(%.1f %.1f %.1f) absmin=(%.1f %.1f %.1f) absmax=(%.1f %.1f %.1f) area=%i/%i clusters=%i lastCluster=%i\n",
		frame ? frame->ps.clientNum : -1, entNum, reason ? reason : "unknown", ent->r.linked, ent->s.eFlags, ent->r.svFlags, ent->s.modelindex, ent->s.eType,
		ent->s.origin[0], ent->s.origin[1], ent->s.origin[2],
		ent->r.absmin[0], ent->r.absmin[1], ent->r.absmin[2], ent->r.absmax[0], ent->r.absmax[1], ent->r.absmax[2],
		svEnt->areanum, svEnt->areanum2, svEnt->numClusters, svEnt->lastCluster );
}

qboolean SV_DynBSPClientNeedsGameState( client_t *client ) {
	playerState_t *ps;

	if ( client->state != CS_ACTIVE || client->netchan.remoteAddress.type == NA_BOT ) {
		return qfalse;
	}
	if ( client->loadedBSPModelsGeneration == sv.bspModelsGeneration ) {
		return qfalse;
	}

	ps = SV_GameClientNum( client - svs.clients );
	if ( !ps ) {
		return qfalse;
	}

	if ( ( ps->pm_flags & PMF_FOLLOW )
		&& ps->clientNum >= 0
		&& ps->clientNum < sv_maxclients->integer
		&& svs.clients[ps->clientNum].runtimeMapName[0] ) {
		Q_strncpyz( client->spectatorRuntimeMapName, svs.clients[ps->clientNum].runtimeMapName, sizeof( client->spectatorRuntimeMapName ) );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPDEBUG server lazy spectator gamestate client=%i name='%s' target=%i map='%s' generation=%i\n",
				(int)( client - svs.clients ), client->name, ps->clientNum,
				client->spectatorRuntimeMapName, sv.bspModelsGeneration );
		}
		return qtrue;
	}

	if ( ps->pm_type != PM_SPECTATOR ) {
		if ( ps->persistant[PERS_TEAM] == TEAM_SPECTATOR ) {
			if ( client->spectatorRuntimeMapName[0] && SV_DynBSPInstanceForMap( client->spectatorRuntimeMapName ) ) {
				return qtrue;
			}
		}

		client->spectatorRuntimeMapName[0] = 0;
		return qfalse;
	}

	if ( client->spectatorRuntimeMapName[0] ) {
		if ( SV_DynBSPInstanceForMap( client->spectatorRuntimeMapName ) ) {
			return qtrue;
		}

		client->spectatorRuntimeMapName[0] = 0;
	}

	return qfalse;
}
