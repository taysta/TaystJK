/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#pragma once

#include "server.h"

typedef struct svWorldContext_s {
	int worldId;
	int bspIndex;
	int bspModelIndex;
	int runtimeBSPInstance;
	vec3_t origin;
	qboolean projected;
} svWorldContext_t;

typedef struct svInteractionContext_s {
	int groupId;
	int ownerClientNum;
	int partnerClientNum;
	int team;
	int flags;
} svInteractionContext_t;

// Precomputed viewer state so per-entity loops (snapshot build, entity state
// copy) don't re-derive the viewer's world/interaction context per target.
typedef struct svDimensionView_s {
	qboolean valid;
	sharedEntity_t *viewerEnt;
	svWorldContext_t world;
	svInteractionContext_t interaction;
} svDimensionView_t;

qboolean SV_DimensionIsolationEnabled( void );
qboolean SV_GetEntityWorldContext( sharedEntity_t *ent, svWorldContext_t *out );
qboolean SV_GetClientViewWorldContext( client_t *client, svWorldContext_t *out );
qboolean SV_GetEntityInteractionContext( sharedEntity_t *ent, svInteractionContext_t *out );
qboolean SV_CanEntitiesInteract( sharedEntity_t *viewer, sharedEntity_t *target, svIsolationPurpose_t purpose );
qboolean SV_CanClientViewEntityInteract( client_t *viewer, sharedEntity_t *target, svIsolationPurpose_t purpose );
void SV_BeginEntityDimension( sharedEntity_t *viewer, svDimensionView_t *view );
void SV_BeginClientViewDimension( client_t *viewer, svDimensionView_t *view );
qboolean SV_ViewCanInteract( const svDimensionView_t *view, sharedEntity_t *target, svIsolationPurpose_t purpose );
const char *SV_IsolationPurposeName( svIsolationPurpose_t purpose );
