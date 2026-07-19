/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#pragma once

#include "server.h"

int SV_DynBSPDebugLevel( void );
qboolean SV_DynBSPDebugEnabled( void );

void SV_DynBSPConfigstringChanged( int index );
qboolean SV_DynBSPShouldSendConfigstring( client_t *client, int index );
const char *SV_DynBSPClientConfigstring( client_t *client, int index, char *buffer, int bufferSize );
int SV_DynBSPClientServerId( client_t *client );
void SV_DynBSPSetClientMap( client_t *client, const char *mapName, int bspIndex );
void SV_DynBSPClearClientMap( client_t *client );
void SV_DynBSPClearAllClientMaps( void );
int SV_DynBSPClientBSPIndex( client_t *client );
int SV_DynBSPClientCollisionBSPIndex( client_t *client );
qboolean SV_DynBSPSpectatorProjectPlayerState( client_t *client, playerState_t *ps );
void SV_DynBSPClientEnteredWorld( client_t *client );
void SV_DynBSPPrepareClientGameState( client_t *client );
qboolean SV_DynBSPClientNeedsGameState( client_t *client );

qboolean SV_DynBSPIsInstanceEntity( sharedEntity_t *ent );
sharedEntity_t *SV_DynBSPInstanceForMap( const char *mapName );
sharedEntity_t *SV_DynBSPHolderForInstance( int runtimeBSPInstance );
sharedEntity_t *SV_DynBSPInstanceForPoint( const vec3_t point );
void SV_DynBSPWorldToLocalPoint( sharedEntity_t *holder, const vec3_t in, vec3_t out );
qboolean SV_DynBSPEntityVisibleInPVS( svEntity_t *svEnt, byte *pvs );
void SV_DynBSPSnapshotDebug( sharedEntity_t *ent, int entNum, clientSnapshot_t *frame, const char *reason );
