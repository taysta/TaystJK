/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#include "server/sv_dimension.h"
#include "server/sv_dynbsp.h"
#include "qcommon/cm_public.h"

#define SV_DIM_WORLD_BASE 0
#define SV_DIM_WORLD_RUNTIME_BASE 1
#define SV_DIM_WORLD_CLIENTMAP_BASE 1000

#define SV_DIM_GROUP_FFA 0
#define SV_DIM_GROUP_DUEL_BASE 1000
#define SV_DIM_GROUP_RACE_SOLO_BASE 2000

#define SV_DIM_FLAG_DUEL 0x00000001
#define SV_DIM_FLAG_RACE 0x00000002
#define SV_DIM_FLAG_COOP 0x00000004
#define SV_DIM_FLAG_SPECTATOR 0x00000008

qboolean SV_DimensionIsolationEnabled( void ) {
	return sv_engineDimensions && sv_engineDimensions->integer ? qtrue : qfalse;
}

static void SV_ClearWorldContext( svWorldContext_t *out ) {
	out->worldId = SV_DIM_WORLD_BASE;
	out->bspIndex = -1;
	out->bspModelIndex = 0;
	out->runtimeBSPInstance = -1;
	VectorClear( out->origin );
	out->projected = qfalse;
}

static void SV_ClearInteractionContext( svInteractionContext_t *out ) {
	out->groupId = SV_DIM_GROUP_FFA;
	out->ownerClientNum = ENTITYNUM_NONE;
	out->partnerClientNum = ENTITYNUM_NONE;
	out->team = TEAM_FREE;
	out->flags = 0;
}

static qboolean SV_DimIsPlayer( sharedEntity_t *ent ) {
	return ent && ent->s.eType == ET_PLAYER ? qtrue : qfalse;
}

static qboolean SV_DimIsNPC( sharedEntity_t *ent ) {
	return ent && ent->s.eType == ET_NPC ? qtrue : qfalse;
}

static qboolean SV_DimIsMover( sharedEntity_t *ent ) {
	return ent && ent->s.eType == ET_MOVER ? qtrue : qfalse;
}

static qboolean SV_DimIsRacePassableMover( sharedEntity_t *ent ) {
	if ( !SV_DimIsMover( ent ) || !ent->classname ) {
		return qfalse;
	}

	return !Q_stricmp( ent->classname, "func_door" ) || !Q_stricmp( ent->classname, "func_plat" ) ? qtrue : qfalse;
}

static qboolean SV_DimIsRaceContext( const svInteractionContext_t *context ) {
	return context && ( context->flags & SV_DIM_FLAG_RACE ) ? qtrue : qfalse;
}

static qboolean SV_DimIsDuelContext( const svInteractionContext_t *context ) {
	return context && ( context->flags & SV_DIM_FLAG_DUEL ) ? qtrue : qfalse;
}

static sharedEntity_t *SV_DimGentityNumIfValid( int entNum ) {
	if ( entNum < 0 || entNum >= sv.num_entities ) {
		return NULL;
	}

	return SV_GentityNum( entNum );
}

static sharedEntity_t *SV_DimEntityOwner( sharedEntity_t *ent ) {
	if ( !ent ) {
		return NULL;
	}

	if ( ent->s.eType == ET_MISSILE ) {
		return SV_DimGentityNumIfValid( ent->r.ownerNum );
	}

	if ( ent->classname
		&& ( !Q_stricmp( ent->classname, "lightsaber" ) || !Q_stricmp( ent->classname, "deadsaber" ) ) ) {
		return SV_DimGentityNumIfValid( ent->r.ownerNum );
	}

	if ( ent->classname
		&& ( !Q_stricmp( ent->classname, "laserTrap" ) || !Q_stricmp( ent->classname, "detpack" ) ) ) {
		return SV_DimGentityNumIfValid( ent->r.ownerNum );
	}

	if ( ent->s.eType == ET_EVENTS + EV_SABER_HIT
		|| ent->s.eType == ET_EVENTS + EV_SABER_BLOCK ) {
		return SV_DimGentityNumIfValid( ent->s.otherEntityNum2 == ENTITYNUM_NONE ? ent->s.otherEntityNum : ent->s.otherEntityNum2 );
	}

	if ( ent->s.eType == ET_EVENTS + EV_SHIELD_HIT ) {
		return SV_DimGentityNumIfValid( ent->s.otherEntityNum );
	}

	if ( ent->s.eType == ET_EVENTS + EV_GENERAL_SOUND ) {
		return SV_DimGentityNumIfValid( ent->r.ownerNum );
	}

	if ( ent->s.eType == ET_EVENTS + EV_ENTITY_SOUND ) {
		return SV_DimGentityNumIfValid( ent->s.clientNum );
	}

	if ( ent->s.eFlags & EF_PLAYER_EVENT ) {
		return SV_DimGentityNumIfValid( ent->r.singleClient );
	}

	if ( ent->s.eType == ET_EVENTS + EV_PLAYER_TELEPORT_IN
		|| ent->s.eType == ET_EVENTS + EV_PLAYER_TELEPORT_OUT ) {
		return SV_DimGentityNumIfValid( ent->s.clientNum );
	}

	if ( ( ent->s.event & ~EV_EVENT_BITS ) == EV_GRENADE_BOUNCE ) {
		return SV_DimGentityNumIfValid( ent->r.ownerNum );
	}

	return ent;
}

static playerState_t *SV_DimPlayerStateForEntity( sharedEntity_t *ent ) {
	sharedEntity_t *owner = SV_DimEntityOwner( ent );
	int entNum;

	if ( !owner ) {
		return NULL;
	}

	entNum = SV_NumForGentity( owner );
	if ( entNum < 0 || entNum >= sv_maxclients->integer || !SV_DimIsPlayer( owner ) ) {
		return NULL;
	}

	return SV_GameClientNum( entNum );
}

static qboolean SV_DimEntityIsActor( sharedEntity_t *ent ) {
	sharedEntity_t *owner = SV_DimEntityOwner( ent );

	if ( SV_DimIsMover( ent ) ) {
		return qfalse;
	}

	return SV_DimIsPlayer( owner ) || SV_DimIsNPC( owner ) ? qtrue : qfalse;
}

static int SV_DimEntityClientNum( sharedEntity_t *ent ) {
	sharedEntity_t *owner = SV_DimEntityOwner( ent );
	int entNum;

	if ( !owner || !SV_DimIsPlayer( owner ) ) {
		return ENTITYNUM_NONE;
	}

	entNum = SV_NumForGentity( owner );
	if ( entNum < 0 || entNum >= sv_maxclients->integer ) {
		return ENTITYNUM_NONE;
	}

	return entNum;
}

static qboolean SV_DimClientRuntimeWorld( client_t *client, svWorldContext_t *out ) {
	sharedEntity_t *holder;

	if ( !client || !client->runtimeMapName[0] ) {
		return qfalse;
	}

	out->bspIndex = client->runtimeMapBSPIndex;
	out->worldId = SV_DIM_WORLD_CLIENTMAP_BASE + ( out->bspIndex >= 0 ? out->bspIndex : (int)( client - svs.clients ) );

	holder = SV_DynBSPInstanceForMap( client->runtimeMapName );
	if ( holder ) {
		int runtimeBSPInstance = SV_RuntimeBSPInstanceForGentity( holder );
		out->worldId = SV_DIM_WORLD_RUNTIME_BASE + runtimeBSPInstance;
		out->bspModelIndex = holder->s.modelindex;
		out->runtimeBSPInstance = runtimeBSPInstance;
		VectorCopy( holder->r.currentOrigin, out->origin );
	}

	return qtrue;
}

static qboolean SV_DimRuntimeWorldForInstance( int runtimeBSPInstance, svWorldContext_t *out ) {
	sharedEntity_t *holder;

	if ( runtimeBSPInstance < 0 ) {
		return qfalse;
	}

	out->worldId = SV_DIM_WORLD_RUNTIME_BASE + runtimeBSPInstance;
	out->runtimeBSPInstance = runtimeBSPInstance;

	holder = SV_DynBSPHolderForInstance( runtimeBSPInstance );
	if ( holder ) {
		out->bspModelIndex = holder->s.modelindex;
		out->bspIndex = CM_FindSubBSP( holder->s.modelindex );
		VectorCopy( holder->r.currentOrigin, out->origin );
	}

	return qtrue;
}

static int SV_DimPairGroupId( int a, int b ) {
	int lo = a < b ? a : b;
	int hi = a < b ? b : a;

	if ( lo < 0 || hi < 0 || lo >= MAX_CLIENTS || hi >= MAX_CLIENTS ) {
		return SV_DIM_GROUP_FFA;
	}

	return SV_DIM_GROUP_DUEL_BASE + lo * MAX_CLIENTS + hi;
}

const char *SV_IsolationPurposeName( svIsolationPurpose_t purpose ) {
	switch ( purpose ) {
	case SVISO_TRACE:
		return "trace";
	case SVISO_POINT_CONTENTS:
		return "pointContents";
	case SVISO_SNAPSHOT:
		return "snapshot";
	case SVISO_DAMAGE:
		return "damage";
	case SVISO_EVENT:
		return "event";
	case SVISO_SOUND:
		return "sound";
	case SVISO_USE:
		return "use";
	default:
		return "unknown";
	}
}

qboolean SV_GetEntityWorldContext( sharedEntity_t *ent, svWorldContext_t *out ) {
	svEntity_t *svEnt;
	int clientNum;

	if ( !ent || !out ) {
		return qfalse;
	}

	SV_ClearWorldContext( out );

	clientNum = SV_DimEntityClientNum( ent );
	if ( clientNum != ENTITYNUM_NONE && SV_DimClientRuntimeWorld( &svs.clients[clientNum], out ) ) {
		return qtrue;
	}

	svEnt = SV_SvEntityForGentity( ent );
	if ( svEnt && SV_DimRuntimeWorldForInstance( svEnt->runtimeBSPInstance, out ) ) {
		return qtrue;
	}

	return qtrue;
}

qboolean SV_GetClientViewWorldContext( client_t *client, svWorldContext_t *out ) {
	playerState_t *ps;

	if ( !client || !out ) {
		return qfalse;
	}

	SV_ClearWorldContext( out );

	if ( SV_DimClientRuntimeWorld( client, out ) ) {
		return qtrue;
	}

	// note: spectatorRuntimeMapName reset for non-spectators happens once per
	// snapshot in SV_DynBSPSpectatorProjectPlayerState, not in this query
	ps = SV_GameClientNum( client - svs.clients );
	if ( !ps || ( !( ps->pm_flags & PMF_FOLLOW )
		&& ps->pm_type != PM_SPECTATOR
		&& ps->persistant[PERS_TEAM] != TEAM_SPECTATOR ) ) {
		return qtrue;
	}

	if ( ps->pm_flags & PMF_FOLLOW ) {
		client_t *target = &svs.clients[ps->clientNum];

		if ( ps->clientNum >= 0 && ps->clientNum < sv_maxclients->integer
			&& SV_DimClientRuntimeWorld( target, out ) ) {
			out->projected = qtrue;
			return qtrue;
		}
	}

	if ( client->spectatorRuntimeMapName[0] ) {
		sharedEntity_t *holder = SV_DynBSPInstanceForMap( client->spectatorRuntimeMapName );

		if ( holder && SV_DimRuntimeWorldForInstance( SV_RuntimeBSPInstanceForGentity( holder ), out ) ) {
			out->projected = qtrue;
			return qtrue;
		}
	}

	return qtrue;
}

qboolean SV_GetEntityInteractionContext( sharedEntity_t *ent, svInteractionContext_t *out ) {
	playerState_t *ps;
	int clientNum;

	if ( !ent || !out ) {
		return qfalse;
	}

	SV_ClearInteractionContext( out );

	clientNum = SV_DimEntityClientNum( ent );
	if ( clientNum == ENTITYNUM_NONE ) {
		return qtrue;
	}

	ps = SV_DimPlayerStateForEntity( ent );
	out->ownerClientNum = clientNum;
	if ( !ps ) {
		return qtrue;
	}

	if ( ps->persistant[PERS_TEAM] >= TEAM_FREE && ps->persistant[PERS_TEAM] < TEAM_NUM_TEAMS ) {
		out->team = ps->persistant[PERS_TEAM];
	}

	if ( ps->duelInProgress && ps->duelIndex >= 0 && ps->duelIndex < MAX_CLIENTS ) {
		out->partnerClientNum = ps->duelIndex;
		out->groupId = SV_DimPairGroupId( clientNum, ps->duelIndex );
		out->flags |= SV_DIM_FLAG_DUEL;
		if ( ps->stats[STAT_RACEMODE] && ps->stats[STAT_MOVEMENTSTYLE] == MV_COOP_JKA ) {
			out->flags |= SV_DIM_FLAG_COOP;
		}
		return qtrue;
	}

	if ( ps->stats[STAT_RACEMODE] ) {
		out->groupId = SV_DIM_GROUP_RACE_SOLO_BASE + clientNum;
		out->flags |= SV_DIM_FLAG_RACE;
		return qtrue;
	}

	if ( ps->pm_type == PM_SPECTATOR ) {
		out->flags |= SV_DIM_FLAG_SPECTATOR;
	}

	return qtrue;
}

static qboolean SV_CanContextsInteract( sharedEntity_t *viewer, const svWorldContext_t *viewerWorld, const svInteractionContext_t *viewerInteractionIn, sharedEntity_t *target, svIsolationPurpose_t purpose ) {
	svWorldContext_t targetWorld;
	svInteractionContext_t viewerInteractionLocal;
	svInteractionContext_t viewerInteraction;
	svInteractionContext_t targetInteraction;

	if ( !viewer || !viewerWorld || !target ) {
		return qtrue;
	}

	if ( !SV_GetEntityWorldContext( target, &targetWorld ) ) {
		return qtrue;
	}

	if ( viewerWorld->worldId != targetWorld.worldId ) {
		return qfalse;
	}

	if ( viewerInteractionIn ) {
		viewerInteraction = *viewerInteractionIn;
	}
	else if ( !SV_GetEntityInteractionContext( viewer, &viewerInteractionLocal ) ) {
		return qtrue;
	}
	else {
		viewerInteraction = viewerInteractionLocal;
	}

	if ( !SV_GetEntityInteractionContext( target, &targetInteraction ) ) {
		return qtrue;
	}

	if ( purpose == SVISO_TRACE || purpose == SVISO_POINT_CONTENTS ) {
		if ( ( SV_DimIsRaceContext( &viewerInteraction ) && SV_DimIsRacePassableMover( target ) )
			|| ( SV_DimIsRaceContext( &targetInteraction ) && SV_DimIsRacePassableMover( viewer ) ) ) {
			return qfalse;
		}
	}

	if ( !SV_DimEntityIsActor( viewer ) || !SV_DimEntityIsActor( target ) ) {
		return qtrue;
	}

	if ( viewerInteraction.groupId == targetInteraction.groupId ) {
		return qtrue;
	}

	if ( viewerInteraction.groupId == SV_DIM_GROUP_FFA && targetInteraction.groupId == SV_DIM_GROUP_FFA ) {
		return qtrue;
	}

	if ( purpose == SVISO_SNAPSHOT ) {
		if ( SV_DimIsDuelContext( &viewerInteraction ) ) {
			return qfalse;
		}
		return qtrue;
	}

	switch ( purpose ) {
	case SVISO_TRACE:
	case SVISO_POINT_CONTENTS:
	case SVISO_DAMAGE:
	case SVISO_EVENT:
	case SVISO_SOUND:
	case SVISO_USE:
	default:
		return qfalse;
	}
}

qboolean SV_CanEntitiesInteract( sharedEntity_t *viewer, sharedEntity_t *target, svIsolationPurpose_t purpose ) {
	svWorldContext_t viewerWorld;

	if ( !viewer || !target ) {
		return qtrue;
	}

	if ( !SV_GetEntityWorldContext( viewer, &viewerWorld ) ) {
		return qtrue;
	}

	return SV_CanContextsInteract( viewer, &viewerWorld, NULL, target, purpose );
}

qboolean SV_CanClientViewEntityInteract( client_t *viewer, sharedEntity_t *target, svIsolationPurpose_t purpose ) {
	svWorldContext_t viewerWorld;

	if ( !viewer || !viewer->gentity || !target ) {
		return qtrue;
	}

	if ( !SV_GetClientViewWorldContext( viewer, &viewerWorld ) ) {
		return qtrue;
	}

	return SV_CanContextsInteract( viewer->gentity, &viewerWorld, NULL, target, purpose );
}

void SV_BeginEntityDimension( sharedEntity_t *viewer, svDimensionView_t *view ) {
	if ( !view ) {
		return;
	}

	view->valid = qfalse;
	view->viewerEnt = NULL;

	if ( !SV_DimensionIsolationEnabled() || !viewer ) {
		return;
	}

	if ( !SV_GetEntityWorldContext( viewer, &view->world ) ) {
		return;
	}
	if ( !SV_GetEntityInteractionContext( viewer, &view->interaction ) ) {
		return;
	}

	view->viewerEnt = viewer;
	view->valid = qtrue;
}

void SV_BeginClientViewDimension( client_t *viewer, svDimensionView_t *view ) {
	if ( !view ) {
		return;
	}

	view->valid = qfalse;
	view->viewerEnt = NULL;

	if ( !SV_DimensionIsolationEnabled() || !viewer || !viewer->gentity ) {
		return;
	}

	if ( !SV_GetClientViewWorldContext( viewer, &view->world ) ) {
		return;
	}
	if ( !SV_GetEntityInteractionContext( viewer->gentity, &view->interaction ) ) {
		return;
	}

	view->viewerEnt = viewer->gentity;
	view->valid = qtrue;
}

qboolean SV_ViewCanInteract( const svDimensionView_t *view, sharedEntity_t *target, svIsolationPurpose_t purpose ) {
	if ( !view || !view->valid || !target ) {
		return qtrue;
	}

	return SV_CanContextsInteract( view->viewerEnt, &view->world, &view->interaction, target, purpose );
}
