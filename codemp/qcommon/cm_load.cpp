/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

// cmodel.c -- model loading
#include "cm_local.h"
#include "qcommon/qfiles.h"

#ifndef BSPC
#include <cstdlib>
#include <mutex>
#include <string>
#include <thread>
#endif

#ifdef BSPC

#include "../bspc/l_qfiles.h"

void SetPlaneSignbits (cplane_t *out) {
	int	bits, j;

	// for fast box on planeside test
	bits = 0;
	for (j=0 ; j<3 ; j++) {
		if (out->normal[j] < 0) {
			bits |= 1<<j;
		}
	}
	out->signbits = bits;
}
#endif //BSPC

// to allow boxes to be treated as brush models, we allocate
// some extra indexes along with those needed by the map
#define	BOX_BRUSHES		1
#define	BOX_SIDES		6
#define	BOX_LEAFS		2
#define	BOX_PLANES		12

#define	LL(x) x=LittleLong(x)


clipMap_t	cmg; //rwwRMG - changed from cm
int			c_pointcontents;
int			c_traces, c_brush_traces, c_patch_traces;


byte		*cmod_base;

#ifndef BSPC
cvar_t		*cm_noAreas;
cvar_t		*cm_noCurves;
cvar_t		*cm_playerCurveClip;
cvar_t		*cm_extraVerbose;
#endif

cmodel_t	box_model;
cplane_t	*box_planes;
cbrush_t	*box_brush;



void	CM_InitBoxHull (void);
void	CM_FloodAreaConnections (clipMap_t &cm);

//rwwRMG - added:
clipMap_t	SubBSP[MAX_SUB_BSP];
int			NumSubBSP, TotalSubModels;

#ifndef BSPC
enum {
	CM_ASYNC_BSP_NONE = 0,
	CM_ASYNC_BSP_PENDING = 1,
	CM_ASYNC_BSP_READY = 2,
	CM_ASYNC_BSP_FAILED = 3
};

typedef struct asyncSubBSPRead_s {
	char	name[MAX_OSPATH];
	void	*buffer;
	int		len;
	int		status;
	int		startTime;
	int		endTime;
	qboolean preparedHeader;
	int		checksum;
	dheader_t header;
} asyncSubBSPRead_t;

static std::mutex cm_asyncSubBSPLock;
static asyncSubBSPRead_t cm_asyncSubBSPReads[4];

static int CM_AsyncReadSubBSPFindSlot( const char *name ) {
	int i;

	for ( i = 0; i < ARRAY_LEN( cm_asyncSubBSPReads ); i++ ) {
		if ( cm_asyncSubBSPReads[i].name[0] && !Q_stricmp( cm_asyncSubBSPReads[i].name, name ) ) {
			return i;
		}
	}

	return -1;
}

static void CM_AsyncReadSubBSPWorker( int slot, std::string name ) {
	fileHandle_t h = 0;
	int len;
	void *buffer = NULL;
	int status = CM_ASYNC_BSP_FAILED;
	int endTime;
	qboolean preparedHeader = qfalse;
	int checksum = 0;
	dheader_t header;

	Com_Memset( &header, 0, sizeof( header ) );

	len = FS_FOpenFileRead( name.c_str(), &h, qfalse );
	if ( h && len > 0 ) {
		buffer = std::malloc( len );
		if ( buffer ) {
			FS_Read( buffer, len, h );
			status = CM_ASYNC_BSP_READY;
			if ( len >= sizeof( dheader_t ) ) {
				checksum = LittleLong( Com_BlockChecksum( buffer, len ) );
				header = *(dheader_t *)buffer;
				for ( size_t i = 0; i < sizeof( dheader_t ) / 4; i++ ) {
					( (int *)&header )[i] = LittleLong( ( (int *)&header )[i] );
				}
				preparedHeader = qtrue;
			}
		}
		FS_FCloseFile( h );
	}

	endTime = Sys_Milliseconds();
	{
		std::lock_guard<std::mutex> lock( cm_asyncSubBSPLock );
		if ( slot >= 0 && slot < ARRAY_LEN( cm_asyncSubBSPReads )
			&& !Q_stricmp( cm_asyncSubBSPReads[slot].name, name.c_str() ) ) {
			cm_asyncSubBSPReads[slot].buffer = buffer;
			cm_asyncSubBSPReads[slot].len = status == CM_ASYNC_BSP_READY ? len : -1;
			cm_asyncSubBSPReads[slot].status = status;
			cm_asyncSubBSPReads[slot].endTime = endTime;
			cm_asyncSubBSPReads[slot].preparedHeader = preparedHeader;
			cm_asyncSubBSPReads[slot].checksum = checksum;
			cm_asyncSubBSPReads[slot].header = header;
			buffer = NULL;
		}
	}

	if ( buffer ) {
		std::free( buffer );
	}
}

qboolean CM_BeginAsyncReadSubBSP( const char *name ) {
	int i;
	int slot = -1;
	std::string threadName;

	if ( !name || !name[0] ) {
		return qfalse;
	}

	{
		std::lock_guard<std::mutex> lock( cm_asyncSubBSPLock );

		i = CM_AsyncReadSubBSPFindSlot( name );
		if ( i >= 0 ) {
			return cm_asyncSubBSPReads[i].status != CM_ASYNC_BSP_FAILED ? qtrue : qfalse;
		}

		for ( i = 0; i < ARRAY_LEN( cm_asyncSubBSPReads ); i++ ) {
			if ( !cm_asyncSubBSPReads[i].name[0] || cm_asyncSubBSPReads[i].status == CM_ASYNC_BSP_FAILED ) {
				if ( cm_asyncSubBSPReads[i].buffer ) {
					std::free( cm_asyncSubBSPReads[i].buffer );
				}
				slot = i;
				break;
			}
		}
		if ( slot < 0 ) {
			return qfalse;
		}

		Com_Memset( &cm_asyncSubBSPReads[slot], 0, sizeof( cm_asyncSubBSPReads[slot] ) );
		Q_strncpyz( cm_asyncSubBSPReads[slot].name, name, sizeof( cm_asyncSubBSPReads[slot].name ) );
		cm_asyncSubBSPReads[slot].status = CM_ASYNC_BSP_PENDING;
		cm_asyncSubBSPReads[slot].startTime = Sys_Milliseconds();
		threadName = cm_asyncSubBSPReads[slot].name;
	}

	try {
		std::thread( CM_AsyncReadSubBSPWorker, slot, threadName ).detach();
	}
	catch ( ... ) {
		std::lock_guard<std::mutex> lock( cm_asyncSubBSPLock );
		cm_asyncSubBSPReads[slot].status = CM_ASYNC_BSP_FAILED;
		cm_asyncSubBSPReads[slot].endTime = Sys_Milliseconds();
		return qfalse;
	}

	return qtrue;
}

int CM_AsyncReadSubBSPStatus( const char *name ) {
	int slot;

	if ( !name || !name[0] ) {
		return CM_ASYNC_BSP_NONE;
	}

	std::lock_guard<std::mutex> lock( cm_asyncSubBSPLock );
	slot = CM_AsyncReadSubBSPFindSlot( name );
	if ( slot < 0 ) {
		return CM_ASYNC_BSP_NONE;
	}

	return cm_asyncSubBSPReads[slot].status;
}

static qboolean CM_TakeAsyncReadSubBSP( const char *name, void **buffer, int *len, int *elapsed, int *checksum, dheader_t *header, qboolean *preparedHeader ) {
	int slot;

	if ( buffer ) {
		*buffer = NULL;
	}
	if ( len ) {
		*len = 0;
	}
	if ( elapsed ) {
		*elapsed = 0;
	}
	if ( checksum ) {
		*checksum = 0;
	}
	if ( header ) {
		Com_Memset( header, 0, sizeof( *header ) );
	}
	if ( preparedHeader ) {
		*preparedHeader = qfalse;
	}
	if ( !name || !name[0] || !buffer || !len ) {
		return qfalse;
	}

	std::lock_guard<std::mutex> lock( cm_asyncSubBSPLock );
	slot = CM_AsyncReadSubBSPFindSlot( name );
	if ( slot < 0 || cm_asyncSubBSPReads[slot].status != CM_ASYNC_BSP_READY || !cm_asyncSubBSPReads[slot].buffer ) {
		return qfalse;
	}

	*buffer = cm_asyncSubBSPReads[slot].buffer;
	*len = cm_asyncSubBSPReads[slot].len;
	if ( elapsed ) {
		*elapsed = cm_asyncSubBSPReads[slot].endTime - cm_asyncSubBSPReads[slot].startTime;
	}
	if ( checksum ) {
		*checksum = cm_asyncSubBSPReads[slot].checksum;
	}
	if ( header ) {
		*header = cm_asyncSubBSPReads[slot].header;
	}
	if ( preparedHeader ) {
		*preparedHeader = cm_asyncSubBSPReads[slot].preparedHeader;
	}
	cm_asyncSubBSPReads[slot].buffer = NULL;
	cm_asyncSubBSPReads[slot].len = 0;
	cm_asyncSubBSPReads[slot].status = CM_ASYNC_BSP_NONE;
	cm_asyncSubBSPReads[slot].name[0] = 0;
	return qtrue;
}
#endif

/*
===============================================================================

					MAP LOADING

===============================================================================
*/

/*
=================
CMod_LoadShaders
=================
*/
static void CMod_LoadShaders( const lump_t *l, clipMap_t &cm )
{
	dshader_t	*in;
	int			i, count;
	CCMShader	*out;

	in = (dshader_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in)) {
		Com_Error (ERR_DROP, "CMod_LoadShaders: funny lump size");
	}
	count = l->filelen / sizeof(*in);

	if (count < 1) {
		Com_Error (ERR_DROP, "Map with no shaders");
	}
	cm.shaders = (CCMShader *)Hunk_Alloc( (1+count) * sizeof( *cm.shaders ), h_high );
	cm.numShaders = count;

	out = cm.shaders;
	for ( i = 0; i < count; i++, in++, out++ )
	{
		Q_strncpyz(out->shader, in->shader, MAX_QPATH);
		out->contentFlags = LittleLong( in->contentFlags );
		out->surfaceFlags = LittleLong( in->surfaceFlags );
	}
}


/*
=================
CMod_LoadSubmodels
=================
*/
static void CMod_LoadSubmodels( const lump_t *l, clipMap_t &cm ) {
	dmodel_t	*in;
	cmodel_t	*out;
	int			i, j, count;
	int			*indexes;

	in = (dmodel_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadSubmodels: funny lump size");
	count = l->filelen / sizeof(*in);

	if (count < 1)
		Com_Error (ERR_DROP, "Map with no models");
	cm.cmodels = (struct cmodel_s *)Hunk_Alloc( count * sizeof( *cm.cmodels ), h_high );
	cm.numSubModels = count;

	if ( count > MAX_SUBMODELS ) {
		Com_Error( ERR_DROP, "MAX_SUBMODELS exceeded" );
	}

	for ( i=0 ; i<count ; i++, in++, out++)
	{
		out = &cm.cmodels[i];

		for (j=0 ; j<3 ; j++)
		{	// spread the mins / maxs by a pixel
			out->mins[j] = LittleFloat (in->mins[j]) - 1;
			out->maxs[j] = LittleFloat (in->maxs[j]) + 1;
		}

		//rwwRMG - sof2 doesn't have to add this &cm == &cmg check.
		//Are they getting leaf data elsewhere? (the reason this needs to be done is
		//in sub bsp instances the first brush model isn't necessary a world model and might be
		//real architecture)
		if ( i == 0 && &cm == &cmg ) {
			out->firstNode = 0;
			continue;	// world model doesn't need other info
		}

		// make a "leaf" just to hold the model's brushes and surfaces
		out->firstNode = -1;

		// make a "leaf" just to hold the model's brushes and surfaces
		out->leaf.numLeafBrushes = LittleLong( in->numBrushes );
		indexes = (int *)Hunk_Alloc( out->leaf.numLeafBrushes * 4, h_high );
		out->leaf.firstLeafBrush = indexes - cm.leafbrushes;
		for ( j = 0 ; j < out->leaf.numLeafBrushes ; j++ ) {
			indexes[j] = LittleLong( in->firstBrush ) + j;
		}

		out->leaf.numLeafSurfaces = LittleLong( in->numSurfaces );
		indexes = (int *)Hunk_Alloc( out->leaf.numLeafSurfaces * 4, h_high );
		out->leaf.firstLeafSurface = indexes - cm.leafsurfaces;
		for ( j = 0 ; j < out->leaf.numLeafSurfaces ; j++ ) {
			indexes[j] = LittleLong( in->firstSurface ) + j;
		}
	}
}


/*
=================
CMod_LoadNodes

=================
*/
static void CMod_LoadNodes( const lump_t *l, clipMap_t &cm ) {
	dnode_t		*in;
	int			child;
	cNode_t		*out;
	int			i, j, count;

	in = (dnode_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadNodes: funny lump size");
	count = l->filelen / sizeof(*in);

	if (count < 1)
		Com_Error (ERR_DROP, "Map has no nodes");
	cm.nodes = (cNode_t *)Hunk_Alloc( count * sizeof( *cm.nodes ), h_high );
	cm.numNodes = count;

	out = cm.nodes;

	for (i=0 ; i<count ; i++, out++, in++)
	{
		out->plane = cm.planes + LittleLong( in->planeNum );
		for (j=0 ; j<2 ; j++)
		{
			child = LittleLong (in->children[j]);
			out->children[j] = child;
		}
	}

}

/*
=================
CM_BoundBrush

=================
*/
void CM_BoundBrush( cbrush_t *b ) {
	b->bounds[0][0] = -b->sides[0].plane->dist;
	b->bounds[1][0] = b->sides[1].plane->dist;

	b->bounds[0][1] = -b->sides[2].plane->dist;
	b->bounds[1][1] = b->sides[3].plane->dist;

	b->bounds[0][2] = -b->sides[4].plane->dist;
	b->bounds[1][2] = b->sides[5].plane->dist;
}


/*
=================
CMod_LoadBrushes

=================
*/
void CMod_LoadBrushes( const lump_t *l, clipMap_t &cm ) {
	dbrush_t	*in;
	cbrush_t	*out;
	int			i, count;

	in = (dbrush_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in)) {
		Com_Error (ERR_DROP, "CMod_LoadBrushes: funny lump size");
	}
	count = l->filelen / sizeof(*in);

	cm.brushes = (cbrush_t *)Hunk_Alloc( ( BOX_BRUSHES + count ) * sizeof( *cm.brushes ), h_high );
	cm.numBrushes = count;

	out = cm.brushes;

	for ( i=0 ; i<count ; i++, out++, in++ ) {
		out->sides = cm.brushsides + LittleLong(in->firstSide);
		out->numsides = LittleLong(in->numSides);

		out->shaderNum = LittleLong( in->shaderNum );
		if ( out->shaderNum < 0 || out->shaderNum >= cm.numShaders ) {
			Com_Error( ERR_DROP, "CMod_LoadBrushes: bad shaderNum: %i", out->shaderNum );
		}
		out->contents = cm.shaders[out->shaderNum].contentFlags;

		CM_BoundBrush( out );
	}

}

/*
=================
CMod_LoadLeafs
=================
*/
static void CMod_LoadLeafs (const lump_t *l, clipMap_t &cm)
{
	int			i;
	cLeaf_t		*out;
	dleaf_t 	*in;
	int			count;

	in = (dleaf_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadLeafs: funny lump size");
	count = l->filelen / sizeof(*in);

	if (count < 1)
		Com_Error (ERR_DROP, "Map with no leafs");

	cm.leafs = (cLeaf_t *)Hunk_Alloc( ( BOX_LEAFS + count ) * sizeof( *cm.leafs ), h_high );
	cm.numLeafs = count;

	out = cm.leafs;
	for ( i=0 ; i<count ; i++, in++, out++)
	{
		out->cluster = LittleLong (in->cluster);
		out->area = LittleLong (in->area);
		out->firstLeafBrush = LittleLong (in->firstLeafBrush);
		out->numLeafBrushes = LittleLong (in->numLeafBrushes);
		out->firstLeafSurface = LittleLong (in->firstLeafSurface);
		out->numLeafSurfaces = LittleLong (in->numLeafSurfaces);

		if (out->cluster >= cm.numClusters)
			cm.numClusters = out->cluster + 1;
		if (out->area >= cm.numAreas)
			cm.numAreas = out->area + 1;
	}

	cm.areas = (cArea_t *)Hunk_Alloc( cm.numAreas * sizeof( *cm.areas ), h_high );
	cm.areaPortals = (int *)Hunk_Alloc( cm.numAreas * cm.numAreas * sizeof( *cm.areaPortals ), h_high );
}

/*
=================
CMod_LoadPlanes
=================
*/
static void CMod_LoadPlanes (const lump_t *l, clipMap_t &cm)
{
	int			i, j;
	cplane_t	*out;
	dplane_t 	*in;
	int			count;
	int			bits;

	in = (dplane_t *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadPlanes: funny lump size");
	count = l->filelen / sizeof(*in);

	if (count < 1)
		Com_Error (ERR_DROP, "Map with no planes");
	cm.planes = (struct cplane_s *)Hunk_Alloc( ( BOX_PLANES + count ) * sizeof( *cm.planes ), h_high );
	cm.numPlanes = count;

	out = cm.planes;

	for ( i=0 ; i<count ; i++, in++, out++)
	{
		bits = 0;
		for (j=0 ; j<3 ; j++)
		{
			out->normal[j] = LittleFloat (in->normal[j]);
			if (out->normal[j] < 0)
				bits |= 1<<j;
		}

		out->dist = LittleFloat (in->dist);
		out->type = PlaneTypeForNormal( out->normal );
		out->signbits = bits;
	}
}

/*
=================
CMod_LoadLeafBrushes
=================
*/
static void CMod_LoadLeafBrushes (const lump_t *l, clipMap_t &cm)
{
	int			i;
	int			*out;
	int		 	*in;
	int			count;

	in = (int *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadLeafBrushes: funny lump size");
	count = l->filelen / sizeof(*in);

	cm.leafbrushes = (int *)Hunk_Alloc( (count + BOX_BRUSHES) * sizeof( *cm.leafbrushes ), h_high );
	cm.numLeafBrushes = count;

	out = cm.leafbrushes;

	for ( i=0 ; i<count ; i++, in++, out++) {
		*out = LittleLong (*in);
	}
}

/*
=================
CMod_LoadLeafSurfaces
=================
*/
static void CMod_LoadLeafSurfaces( const lump_t *l, clipMap_t &cm )
{
	int			i;
	int			*out;
	int		 	*in;
	int			count;

	in = (int *)(cmod_base + l->fileofs);
	if (l->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "CMod_LoadLeafSurfaces: funny lump size");
	count = l->filelen / sizeof(*in);

	cm.leafsurfaces = (int *)Hunk_Alloc( count * sizeof( *cm.leafsurfaces ), h_high );
	cm.numLeafSurfaces = count;

	out = cm.leafsurfaces;

	for ( i=0 ; i<count ; i++, in++, out++) {
		*out = LittleLong (*in);
	}
}

/*
=================
CMod_LoadBrushSides
=================
*/
static void CMod_LoadBrushSides (const lump_t *l, clipMap_t &cm)
{
	int				i;
	cbrushside_t	*out;
	dbrushside_t 	*in;
	int				count;
	int				num;

	in = (dbrushside_t *)(cmod_base + l->fileofs);
	if ( l->filelen % sizeof(*in) ) {
		Com_Error (ERR_DROP, "CMod_LoadBrushSides: funny lump size");
	}
	count = l->filelen / sizeof(*in);

	cm.brushsides = (cbrushside_t *)Hunk_Alloc( ( BOX_SIDES + count ) * sizeof( *cm.brushsides ), h_high );
	cm.numBrushSides = count;

	out = cm.brushsides;

	for ( i=0 ; i<count ; i++, in++, out++) {
		num = LittleLong( in->planeNum );
		out->plane = &cm.planes[num];
		out->shaderNum = LittleLong( in->shaderNum );
		if ( out->shaderNum < 0 || out->shaderNum >= cm.numShaders ) {
			Com_Error( ERR_DROP, "CMod_LoadBrushSides: bad shaderNum: %i", out->shaderNum );
		}
	}
}


/*
=================
CMod_LoadEntityString
=================
*/
static void CMod_LoadEntityString( const lump_t *l, clipMap_t &cm, const char* name ) {
	fileHandle_t h;
	char entName[MAX_QPATH];

	// Attempt to load entities from an external .ent file if available
	Q_strncpyz(entName, name, sizeof(entName));
	const size_t entNameLen = strlen(entName);
	entName[entNameLen - 3] = 'e';
	entName[entNameLen - 2] = 'n';
	entName[entNameLen - 1] = 't';
	const int iEntityFileLen = FS_FOpenFileRead(entName, &h, qfalse);
	if (h)
	{
		cm.entityString = (char *)Hunk_Alloc(iEntityFileLen + 1, h_high);
		cm.numEntityChars = iEntityFileLen + 1;
		FS_Read(cm.entityString, iEntityFileLen, h);
		FS_FCloseFile(h);
		cm.entityString[iEntityFileLen] = '\0';
		Com_Printf("Loaded entities from %s\n", entName);
		return;
	}

	cm.entityString = (char *)Hunk_Alloc( l->filelen, h_high );
	cm.numEntityChars = l->filelen;
	Com_Memcpy (cm.entityString, cmod_base + l->fileofs, l->filelen);
}

/*
=================
CMod_LoadVisibility
=================
*/
#define	VIS_HEADER	8
static void CMod_LoadVisibility( const lump_t *l, clipMap_t &cm ) {
	int		len;
	byte	*buf;

    len = l->filelen;
	if ( !len ) {
		cm.clusterBytes = ( cm.numClusters + 31 ) & ~31;
		cm.visibility = (unsigned char *)Hunk_Alloc( cm.clusterBytes, h_high );
		Com_Memset( cm.visibility, 255, cm.clusterBytes );
		return;
	}
	buf = cmod_base + l->fileofs;

	cm.vised = qtrue;
	cm.visibility = (unsigned char *)Hunk_Alloc( len, h_high );
	cm.numClusters = LittleLong( ((int *)buf)[0] );
	cm.clusterBytes = LittleLong( ((int *)buf)[1] );
	Com_Memcpy (cm.visibility, buf + VIS_HEADER, len - VIS_HEADER );
}

//==================================================================


/*
=================
CMod_LoadPatches
=================
*/
#define	MAX_PATCH_VERTS		1024
static void CMod_LoadPatches( const lump_t *surfs, const lump_t *verts, clipMap_t &cm ) {
	drawVert_t	*dv, *dv_p;
	dsurface_t	*in;
	int			count;
	int			i, j;
	int			c;
	cPatch_t	*patch;
	vec3_t		points[MAX_PATCH_VERTS];
	int			width, height;
	int			shaderNum;

	in = (dsurface_t *)(cmod_base + surfs->fileofs);
	if (surfs->filelen % sizeof(*in))
		Com_Error (ERR_DROP, "MOD_LoadBmodel: funny lump size");
	cm.numSurfaces = count = surfs->filelen / sizeof(*in);
	cm.surfaces = (cPatch_t ** )Hunk_Alloc( cm.numSurfaces * sizeof( cm.surfaces[0] ), h_high );

	dv = (drawVert_t *)(cmod_base + verts->fileofs);
	if (verts->filelen % sizeof(*dv))
		Com_Error (ERR_DROP, "MOD_LoadBmodel: funny lump size");

	// scan through all the surfaces, but only load patches,
	// not planar faces
	for ( i = 0 ; i < count ; i++, in++ ) {
		if ( LittleLong( in->surfaceType ) != MST_PATCH ) {
			continue;		// ignore other surfaces
		}
		// FIXME: check for non-colliding patches

		cm.surfaces[ i ] = patch = (cPatch_t *)Hunk_Alloc( sizeof( *patch ), h_high );

		// load the full drawverts onto the stack
		width = LittleLong( in->patchWidth );
		height = LittleLong( in->patchHeight );
		c = width * height;
		if ( c > MAX_PATCH_VERTS ) {
			Com_Error( ERR_DROP, "ParseMesh: MAX_PATCH_VERTS" );
		}

		dv_p = dv + LittleLong( in->firstVert );
		for ( j = 0 ; j < c ; j++, dv_p++ ) {
			points[j][0] = LittleFloat( dv_p->xyz[0] );
			points[j][1] = LittleFloat( dv_p->xyz[1] );
			points[j][2] = LittleFloat( dv_p->xyz[2] );
		}

		shaderNum = LittleLong( in->shaderNum );
		patch->contents = cm.shaders[shaderNum].contentFlags;
		patch->surfaceFlags = cm.shaders[shaderNum].surfaceFlags;

		// create the internal facet structure
		patch->pc = CM_GeneratePatchCollide( width, height, points );
	}
}

//==================================================================

/*
==================
CM_LoadMap

Loads in the map and all submodels
==================
*/
void *gpvCachedMapDiskImage = NULL;
char  gsCachedMapDiskImage[MAX_QPATH];
qboolean gbUsingCachedMapDataRightNow = qfalse;	// if true, signifies that you can't delete this at the moment!! (used during z_malloc()-fail recovery attempt)

// called in response to a "devmapbsp blah" or "devmapall blah" command, do NOT use inside CM_Load unless you pass in qtrue
//
// new bool return used to see if anything was freed, used during z_malloc failure re-try
//
qboolean CM_DeleteCachedMap(qboolean bGuaranteedOkToDelete)
{
	qboolean bActuallyFreedSomething = qfalse;

	if (bGuaranteedOkToDelete || !gbUsingCachedMapDataRightNow)
	{
		// dump cached disk image...
		//
		if (gpvCachedMapDiskImage)
		{
			Z_Free(	gpvCachedMapDiskImage );
					gpvCachedMapDiskImage = NULL;

			bActuallyFreedSomething = qtrue;
		}
		gsCachedMapDiskImage[0] = '\0';

		// force map loader to ignore cached internal BSP structures for next level CM_LoadMap() call...
		//
		cmg.name[0] = '\0';
	}

	return bActuallyFreedSomething;
}





static void CM_LoadMap_Actual( const char *name, qboolean clientload, int *checksum, clipMap_t &cm )
{ //rwwRMG - function needs heavy modification
	int				*buf;
	dheader_t		header;
	static unsigned	last_checksum;
	char			origName[MAX_OSPATH];
	void			*newBuff = 0;
	qboolean		asyncDiskImage = qfalse;
	int				iBSPLen = 0;
#ifndef BSPC
	const qboolean	timingBSP = ( clientload || &cm != &cmg ) ? qtrue : qfalse;
	int				timingStart = Sys_Milliseconds();
	int				timingPhase = timingStart;
	qboolean		asyncPreparedHeader = qfalse;
	int				asyncChecksum = 0;
	dheader_t		asyncHeader;
#endif

	if ( !name || !name[0] ) {
		Com_Error( ERR_DROP, "CM_LoadMap: NULL name" );
	}

#ifndef BSPC
	cm_noAreas = Cvar_Get ("cm_noAreas", "0", CVAR_CHEAT);
	cm_noCurves = Cvar_Get ("cm_noCurves", "0", CVAR_CHEAT);
	cm_playerCurveClip = Cvar_Get ("cm_playerCurveClip", "1", CVAR_ARCHIVE_ND|CVAR_CHEAT );
	cm_extraVerbose = Cvar_Get ("cm_extraVerbose", "0", CVAR_TEMP );
#endif
	Com_DPrintf( "CM_LoadMap( %s, %i )\n", name, clientload );

	if ( !strcmp( cm.name, name ) && clientload ) {
		if ( checksum )
			*checksum = last_checksum;
		return;
	}

	strcpy(origName, name);

	if (&cm == &cmg)
	{
		// free old stuff
		CM_ClearMap();
		CM_ClearLevelPatches();
	}

	// free old stuff
	Com_Memset( &cm, 0, sizeof( cm ) );

	if ( !name[0] ) {
		cm.numLeafs = 1;
		cm.numClusters = 1;
		cm.numAreas = 1;
		cm.cmodels = (struct cmodel_s *)Hunk_Alloc( sizeof( *cm.cmodels ), h_high );
		if ( checksum )
			*checksum = 0;
		return;
	}

	//
	// load the file
	//
	//rww - Doesn't this sort of defeat the purpose? We're clearing it even if the map is the same as the last one!
	//Not touching it though in case I'm just overlooking something.
	if (gpvCachedMapDiskImage && &cm == &cmg)	// MP code: this'll only be NZ if we got an ERR_DROP during last map load,
	{							//	so it's really just a safety measure.
		Z_Free(	gpvCachedMapDiskImage);
				gpvCachedMapDiskImage = NULL;
	}

	buf = NULL;
#ifndef BSPC
	timingPhase = Sys_Milliseconds();
	//
	// load the file into a buffer that we either discard as usual at the bottom, or if we've got enough memory
	//	then keep it long enough to save the renderer re-loading it (if not dedicated server),
	//	then discard it after that...
	//
	{
		int asyncElapsed = 0;
		if ( CM_TakeAsyncReadSubBSP( name, &newBuff, &iBSPLen, &asyncElapsed, &asyncChecksum, &asyncHeader, &asyncPreparedHeader ) ) {
			buf = (int*) newBuff;
			asyncDiskImage = qtrue;
			Com_Printf( "BSPTIME qcommon CM_LoadMap asyncDiskImage name='%s' bytes=%i asyncMs=%i prepared=%i\n",
				name, iBSPLen, asyncElapsed, asyncPreparedHeader );
		}
	}

	if ( !buf )
	{
	fileHandle_t h;
	iBSPLen = FS_FOpenFileRead( name, &h, qfalse );
	if (h)
	{
		newBuff = Z_Malloc( iBSPLen, TAG_BSP_DISKIMAGE );
		FS_Read( newBuff, iBSPLen, h);
		FS_FCloseFile( h );

		buf = (int*) newBuff;	// so the rest of the code works as normal
		if (&cm == &cmg)
		{
			gpvCachedMapDiskImage = newBuff;
			newBuff = 0;
		}

		// carry on as before...
		//
	}
	}
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap DiskImageReady name='%s' source=%s bytes=%i ms=%i total=%i\n",
			name, asyncDiskImage ? "async" : "sync", iBSPLen, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#else
	iBSPLen = LoadQuakeFile((quakefile_t *) name, (void **)&buf);
#endif

	if ( !buf ) {
		Com_Error (ERR_DROP, "Couldn't load %s", name);
	}

#ifndef BSPC
	if ( asyncDiskImage && asyncPreparedHeader ) {
		last_checksum = asyncChecksum;
	}
	else
#endif
	{
		last_checksum = LittleLong (Com_BlockChecksum (buf, iBSPLen));
	}
	if ( checksum )
		*checksum = last_checksum;
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Checksum name='%s' source=%s ms=%i total=%i\n",
			name, ( asyncDiskImage && asyncPreparedHeader ) ? "async" : "sync", now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif

#ifndef BSPC
	if ( asyncDiskImage && asyncPreparedHeader ) {
		header = asyncHeader;
	}
	else
#endif
	{
		header = *(dheader_t *)buf;
		for (size_t i=0 ; i<sizeof(dheader_t)/4 ; i++) {
			((int *)&header)[i] = LittleLong ( ((int *)&header)[i]);
		}
	}

	if ( header.version != BSP_VERSION ) {
		Z_Free(	gpvCachedMapDiskImage);
				gpvCachedMapDiskImage = NULL;

		Com_Error (ERR_DROP, "CM_LoadMap: %s has wrong version number (%i should be %i)"
		, name, header.version, BSP_VERSION );
	}
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Header name='%s' ms=%i total=%i\n",
			name, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif

	cmod_base = (byte *)buf;

	// load into heap
	CMod_LoadShaders( &header.lumps[LUMP_SHADERS], cm );
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Shaders name='%s' count=%i ms=%i total=%i\n",
			name, cm.numShaders, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadLeafs (&header.lumps[LUMP_LEAFS], cm);
	CMod_LoadLeafBrushes (&header.lumps[LUMP_LEAFBRUSHES], cm);
	CMod_LoadLeafSurfaces (&header.lumps[LUMP_LEAFSURFACES], cm);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Leafs name='%s' leafs=%i leafBrushes=%i leafSurfaces=%i ms=%i total=%i\n",
			name, cm.numLeafs, cm.numLeafBrushes, cm.numLeafSurfaces, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadPlanes (&header.lumps[LUMP_PLANES], cm);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Planes name='%s' count=%i ms=%i total=%i\n",
			name, cm.numPlanes, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadBrushSides (&header.lumps[LUMP_BRUSHSIDES], cm);
	CMod_LoadBrushes (&header.lumps[LUMP_BRUSHES], cm);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Brushes name='%s' brushes=%i brushSides=%i ms=%i total=%i\n",
			name, cm.numBrushes, cm.numBrushSides, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadSubmodels (&header.lumps[LUMP_MODELS], cm);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Submodels name='%s' count=%i ms=%i total=%i\n",
			name, cm.numSubModels, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadNodes (&header.lumps[LUMP_NODES], cm);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Nodes name='%s' count=%i ms=%i total=%i\n",
			name, cm.numNodes, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadEntityString (&header.lumps[LUMP_ENTITIES], cm, name);
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap EntityString name='%s' bytes=%i ms=%i total=%i\n",
			name, cm.numEntityChars, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadVisibility( &header.lumps[LUMP_VISIBILITY], cm );
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Visibility name='%s' vised=%i clusters=%i ms=%i total=%i\n",
			name, cm.vised, cm.numClusters, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif
	CMod_LoadPatches( &header.lumps[LUMP_SURFACES], &header.lumps[LUMP_DRAWVERTS], cm );
#ifndef BSPC
	if ( timingBSP ) {
		const int now = Sys_Milliseconds();
		Com_Printf( "BSPTIME qcommon CM_LoadMap Patches name='%s' surfaces=%i ms=%i total=%i\n",
			name, cm.numSurfaces, now - timingPhase, now - timingStart );
		timingPhase = now;
	}
#endif

	TotalSubModels += cm.numSubModels;

	if (&cm == &cmg)
	{
		// Load in the shader text - return instantly if already loaded
		CM_InitBoxHull ();
	}

#ifndef BSPC	// I hope we can lose this crap soon
	//
	// if we've got enough memory, and it's not a dedicated-server, then keep the loaded map binary around
	//	for the renderer to chew on... (but not if this gets ported to a big-endian machine, because some of the
	//	map data will have been Little-Long'd, but some hasn't).
	//
	// For sub BSPs, always free immediately since caching only applies to main maps
	if ( asyncDiskImage && newBuff )
	{
		std::free( newBuff );
	}
	else if ( newBuff && newBuff != gpvCachedMapDiskImage )
	{
		Z_Free(newBuff);
	}
	else if (Sys_LowPhysicalMemory()
		|| com_dedicated->integer
//		|| we're on a big-endian machine
		)
	{
		Z_Free(	gpvCachedMapDiskImage );
				gpvCachedMapDiskImage = NULL;
	}
	else
	{
		// ... do nothing, and let the renderer free it after it's finished playing with it...
		//
	}
#else
	FS_FreeFile (buf);
#endif

	CM_FloodAreaConnections (cm);

	// allow this to be cached if it is loaded by the server
	if ( !clientload ) {
		Q_strncpyz( cm.name, origName, sizeof( cm.name ) );
	}
}


// need a wrapper function around this because of multiple returns, need to ensure bool is correct...
//
void CM_LoadMap( const char *name, qboolean clientload, int *checksum )
{
	gbUsingCachedMapDataRightNow = qtrue;	// !!!!!!!!!!!!!!!!!!

		CM_LoadMap_Actual( name, clientload, checksum, cmg );

	gbUsingCachedMapDataRightNow = qfalse;	// !!!!!!!!!!!!!!!!!!
}



/*
==================
CM_ClearMap
==================
*/
void CM_ClearMap( void )
{
	int		i;

	Com_Memset( &cmg, 0, sizeof( cmg ) );
	CM_ClearLevelPatches();

	for(i = 0; i < NumSubBSP; i++)
	{
		memset(&SubBSP[i], 0, sizeof(SubBSP[0]));
	}
	NumSubBSP = 0;
	TotalSubModels = 0;
}

/*
==================
CM_ClipHandleToModel
==================
*/
cmodel_t	*CM_ClipHandleToModel( clipHandle_t handle, clipMap_t **clipMap ) {
	int		i;
	int		count;

	if ( handle < 0 )
	{
		Com_Error( ERR_DROP, "CM_ClipHandleToModel: bad handle %i", handle );
	}
	if ( handle < cmg.numSubModels )
	{
		if (clipMap)
		{
			*clipMap = &cmg;
		}
		return &cmg.cmodels[handle];
	}
	if ( handle == BOX_MODEL_HANDLE )
	{
		if (clipMap)
		{
			*clipMap = &cmg;
		}
		return &box_model;
	}

	count = cmg.numSubModels;
	for(i = 0; i < NumSubBSP; i++)
	{
		if (handle < count + SubBSP[i].numSubModels)
		{
			if (clipMap)
			{
				*clipMap = &SubBSP[i];
			}
			return &SubBSP[i].cmodels[handle - count];
		}
		count += SubBSP[i].numSubModels;
	}

	if ( handle < MAX_SUBMODELS )
	{
		Com_Error( ERR_DROP, "CM_ClipHandleToModel: bad handle (count: %i) < (handle: %i) < (max: %i)",
			cmg.numSubModels, handle, MAX_SUBMODELS );
	}
	Com_Error( ERR_DROP, "CM_ClipHandleToModel: bad handle %i", handle + MAX_SUBMODELS );

	return NULL;
}

/*
==================
CM_InlineModel
==================
*/
clipHandle_t	CM_InlineModel( int index ) {
	if ( index < 0 || index >= TotalSubModels ) {
		int count = cmg.numSubModels;

		Com_Printf( "CM_InlineModel debug: requested=%i total=%i main='%s' mainModels=%i subBSPs=%i\n",
			index, TotalSubModels, cmg.name, cmg.numSubModels, NumSubBSP );
		for ( int i = 0; i < NumSubBSP; i++ ) {
			Com_Printf( "CM_InlineModel debug: sub[%i] base=%i name='%s' models=%i\n",
				i, count, SubBSP[i].name, SubBSP[i].numSubModels );
			count += SubBSP[i].numSubModels;
		}
		Com_Error( ERR_DROP, "CM_InlineModel: bad number: %d >= %d (may need to re-BSP map?)", index, TotalSubModels );
	}
	return index;
}

int		CM_NumInlineModels( void ) {
	return cmg.numSubModels;
}

char	*CM_EntityString( void ) {
	return cmg.entityString;
}

char *CM_SubBSPEntityString( int index )
{
	return SubBSP[index].entityString;
}

int		CM_LeafCluster( int leafnum ) {
	if (leafnum < 0 || leafnum >= cmg.numLeafs) {
		Com_Error (ERR_DROP, "CM_LeafCluster: bad number");
	}
	return cmg.leafs[leafnum].cluster;
}

int		CM_LeafArea( int leafnum ) {
	if ( leafnum < 0 || leafnum >= cmg.numLeafs ) {
		Com_Error (ERR_DROP, "CM_LeafArea: bad number");
	}
	return cmg.leafs[leafnum].area;
}

//=======================================================================


/*
===================
CM_InitBoxHull

Set up the planes and nodes so that the six floats of a bounding box
can just be stored out and get a proper clipping hull structure.
===================
*/
void CM_InitBoxHull (void)
{
	int			i;
	int			side;
	cplane_t	*p;
	cbrushside_t	*s;

	box_planes = &cmg.planes[cmg.numPlanes];

	box_brush = &cmg.brushes[cmg.numBrushes];
	box_brush->numsides = 6;
	box_brush->sides = cmg.brushsides + cmg.numBrushSides;
	box_brush->contents = CONTENTS_BODY;

	box_model.firstNode = -1;
	box_model.leaf.numLeafBrushes = 1;
//	box_model.leaf.firstLeafBrush = cmg.numBrushes;
	box_model.leaf.firstLeafBrush = cmg.numLeafBrushes;
	cmg.leafbrushes[cmg.numLeafBrushes] = cmg.numBrushes;

	for (i=0 ; i<6 ; i++)
	{
		side = i&1;

		// brush sides
		s = &cmg.brushsides[cmg.numBrushSides+i];
		s->plane = 	cmg.planes + (cmg.numPlanes+i*2+side);
		s->shaderNum = cmg.numShaders;

		// planes
		p = &box_planes[i*2];
		p->type = i>>1;
		p->signbits = 0;
		VectorClear (p->normal);
		p->normal[i>>1] = 1;

		p = &box_planes[i*2+1];
		p->type = 3 + (i>>1);
		p->signbits = 0;
		VectorClear (p->normal);
		p->normal[i>>1] = -1;

		SetPlaneSignbits( p );
	}
}

/*
===================
CM_TempBoxModel

To keep everything totally uniform, bounding boxes are turned into small
BSP trees instead of being compared directly.
Capsules are handled differently though.
===================
*/
clipHandle_t CM_TempBoxModel( const vec3_t mins, const vec3_t maxs, int capsule ) {

	VectorCopy( mins, box_model.mins );
	VectorCopy( maxs, box_model.maxs );

	if ( capsule ) {
		return CAPSULE_MODEL_HANDLE;
	}

	box_planes[0].dist = maxs[0];
	box_planes[1].dist = -maxs[0];
	box_planes[2].dist = mins[0];
	box_planes[3].dist = -mins[0];
	box_planes[4].dist = maxs[1];
	box_planes[5].dist = -maxs[1];
	box_planes[6].dist = mins[1];
	box_planes[7].dist = -mins[1];
	box_planes[8].dist = maxs[2];
	box_planes[9].dist = -maxs[2];
	box_planes[10].dist = mins[2];
	box_planes[11].dist = -mins[2];

	VectorCopy( mins, box_brush->bounds[0] );
	VectorCopy( maxs, box_brush->bounds[1] );

	return BOX_MODEL_HANDLE;
}

/*
===================
CM_ModelBounds
===================
*/
void CM_ModelBounds( clipHandle_t model, vec3_t mins, vec3_t maxs ) {
	cmodel_t	*cmod;

	cmod = CM_ClipHandleToModel( model );
	VectorCopy( cmod->mins, mins );
	VectorCopy( cmod->maxs, maxs );
}

int CM_LoadSubBSP(const char *name, qboolean clientload)
{
	int		i;
	int		checksum;
	int		count;

	count = cmg.numSubModels;
	for(i = 0; i < NumSubBSP; i++)
	{
		if (!Q_stricmp(name, SubBSP[i].name))
		{
			return count;
		}
		count += SubBSP[i].numSubModels;
	}

	if (NumSubBSP == MAX_SUB_BSP)
	{
		Com_Error (ERR_DROP, "CM_LoadSubBSP: too many unique sub BSPs");
	}

	CM_LoadMap_Actual(name, clientload, &checksum, SubBSP[NumSubBSP] );
	NumSubBSP++;

	return count;
}

int CM_FindSubBSP(int modelIndex)
{
	int		i;
	int		count;

	count = cmg.numSubModels;
	if (modelIndex < count)
	{	// belongs to the main bsp
		return -1;
	}

	for(i = 0; i < NumSubBSP; i++)
	{
		count += SubBSP[i].numSubModels;
		if (modelIndex < count)
		{
			return i;
		}
	}
	return -1;
}

int CM_SubBSPModelIndex( int bspIndex )
{
	int i;
	int count;

	if ( bspIndex < 0 || bspIndex >= NumSubBSP )
	{
		return -1;
	}

	count = cmg.numSubModels;
	for ( i = 0; i < bspIndex; i++ )
	{
		count += SubBSP[i].numSubModels;
	}

	return count;
}

void CM_GetWorldBounds ( vec3_t mins, vec3_t maxs )
{
	VectorCopy ( cmg.cmodels[0].mins, mins );
	VectorCopy ( cmg.cmodels[0].maxs, maxs );
}

int CM_ModelContents_Actual( clipHandle_t model, clipMap_t *cm )
{
	cmodel_t	*cmod;
	int			contents = 0;
	int			i;

	if (!cm)
	{
		cm = &cmg;
	}

	cmod = CM_ClipHandleToModel( model, &cm );

	//MCG ADDED - return the contents, too

	for ( i = 0; i < cmod->leaf.numLeafBrushes; i++ )
	{
		int brushNum = cm->leafbrushes[cmod->leaf.firstLeafBrush + i];
		contents |= cm->brushes[brushNum].contents;
	}

	for ( i = 0; i < cmod->leaf.numLeafSurfaces; i++ )
	{
		int surfaceNum = cm->leafsurfaces[cmod->leaf.firstLeafSurface + i];
		if ( cm->surfaces[surfaceNum] != NULL )
		{//HERNH?  How could we have a null surf within our cmod->leaf.numLeafSurfaces?
			contents |= cm->surfaces[surfaceNum]->contents;
		}
	}

	return contents;
}

int CM_ModelContents(  clipHandle_t model, int subBSPIndex )
{
	if (subBSPIndex < 0)
	{
		return CM_ModelContents_Actual(model, NULL);
	}

	return CM_ModelContents_Actual(model, &SubBSP[subBSPIndex]);
}
