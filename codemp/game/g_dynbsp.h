/*
===========================================================================
Copyright (C) 2013 - 2015 OpenJK contributors

This file is part of the OpenJK source code.
===========================================================================
*/

#pragma once

#include "g_local.h"

gentity_t *G_SpawnBSPInstance( const char *bspModel, const vec3_t origin, float yaw, const char *teamFilter );
qboolean G_DynBSP_NormalizeMapName( const char *in, char *out, size_t outSize );
qboolean G_DynBSP_MapAllowedByPolicy( const char *bspModel, char *reason, int reasonSize );
qboolean G_DynBSP_SpawnMap( const char *bspModel, const vec3_t origin, int clientNum );
qboolean G_DynBSP_EnsureMap( const char *bspModel, const vec3_t origin, int clientNum );
void G_DynBSP_LoadCommand( void );
void G_DynBSP_ClearCommand( void );
void G_RuntimeRoomsInit( void );
qboolean G_RuntimeRoomEnsureMap( const char *mapName, const vec3_t origin, int clientNum );
void G_RuntimeWarpSetClientMap( int clientNum, const char *mapName );
void G_RuntimeWarpClearClientMap( int clientNum );
qboolean G_RuntimeWarpClearClientActiveMap( int clientNum );
const char *G_RuntimeWarpClientMapName( int clientNum );
qboolean G_RuntimeWarpClientInMainMap( int clientNum );
qboolean G_RuntimeWarpClientInMap( int clientNum, const char *mapName );
int G_RuntimeWarpRuntimeBSPInstanceForMap( const char *mapName );
void G_DynBSPSetRuntimeAmbient( int runtimeBSPInstance, const char *ambientSet );
qboolean G_RuntimeWarpMapOccupied( const char *mapName );
int G_RuntimeWarpBuildOccupantList( const char *mapName, char *buffer, int bufferSize );
