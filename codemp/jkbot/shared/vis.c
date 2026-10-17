/*
 * JKBot visibility model (P1-ENG-12; environment.md §5.2, ruleset §3.3).
 *
 * 1. The camera, as the TaystJK cgame computes its third-person view (cg_view.c
 *    CG_CalcViewValues and CG_OffsetThirdPersonView): the ideal target above the player's head
 *    and location `range` behind it, both damped (cg_cameraFPS's frame-rate independent damping)
 *    and clipped with a +-4 box against MASK_CAMERACLIP, so it stays out of walls. Not ported, as
 *    they don't arise for a duelist: vehicles, the action cam, a rancor's grip, the fall vector,
 *    zoom, the strafe helper and prediction-error smoothing.
 * 2. The frustum: in front of the camera and within half the rendered FOV each way.
 * 3. Sight: a segment from the camera to a point is clear unless it crosses a world brush whose
 *    contents block sight (MASK_OPAQUE) and whose shader isn't one a human sees through or one
 *    that's never drawn, or one of the drawn surfaces that block sight without blocking traces
 *    (triangle soups, e.g. misc_models). The lists come from measurements/sightsurfaces.json.
 *    Brushes are clipped exactly (Cyrus-Beck over their planes), triangles by Moller-Trumbore.
 *
 * Compiled as C++ in the agent server (it's the common subset of C and C++).
 */
#ifdef JKBOT_AGENT

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "qcommon/q_shared.h"
#include "qcommon/qfiles.h"
#include "game/bg_public.h"  // the contents masks, DEFAULT_MINS_2/MAXS_2
#include "vis.h"

#define CAMERA_SIZE 4  // cg_view.c
#define MASK_CAMERACLIP ( MASK_SOLID | CONTENTS_PLAYERCLIP )
#define CAMERA_MIN_FPS 15  // cg_local.h

static const vec3_t cameramins = { -CAMERA_SIZE, -CAMERA_SIZE, -CAMERA_SIZE };
static const vec3_t cameramaxs = { CAMERA_SIZE, CAMERA_SIZE, CAMERA_SIZE };

void JKBVis_DefaultParams( jkbVisParams_t *p ) {
	p->range = 80.0f;  // ruleset §3.3 (the TaystJK default is 100)
	p->angle = 0.0f;
	p->vertOffset = 16.0f;
	p->pitchOffset = 0.0f;
	p->horzOffset = 0.0f;
	p->targetDamp = 0.5f;
	p->cameraDamp = 0.3f;
	p->cameraFPS = 125.0f;
	p->fovX = 112.867958f;  // measurements/fov.json
	p->fovY = 80.577271f;
}

// ---- the camera (cg_view.c) ----

void JKBVis_CameraReset( jkbVisCamera_t *cam ) {
	memset( cam, 0, sizeof( *cam ) );
}

static void CalcIdealTarget( jkbVisCamera_t *cam, const jkbVisParams_t *p, const playerState_t *ps,
	const vec3_t vieworg ) {
	VectorCopy( vieworg, cam->focus );
	cam->focus[2] += ps->viewheight;
	VectorCopy( cam->focus, cam->target.ideal );
	cam->target.ideal[2] += p->vertOffset + ps->standheight - 40;  // up for bigger models
}

static void CalcIdealLocation( jkbVisCamera_t *cam, const jkbVisParams_t *p ) {
	VectorMA( cam->target.ideal, -p->range, cam->fwd, cam->loc.ideal );
}

static void ResetDamp( jkbVisCamera_t *cam, const jkbVisParams_t *p, const playerState_t *ps,
	const vec3_t vieworg, jkbVisTrace_t trace ) {
	trace_t tr;
	vec3_t target;
	CalcIdealTarget( cam, p, ps, vieworg );
	CalcIdealLocation( cam, p );
	VectorClear( cam->loc.damp );
	VectorClear( cam->target.damp );
	VectorCopy( cam->loc.ideal, cam->loc.prevIdeal );
	VectorCopy( cam->target.ideal, cam->target.prevIdeal );
	trace( &tr, cam->focus, cameramins, cameramaxs, cam->target.ideal, MASK_CAMERACLIP );
	if ( tr.fraction <= 1.0f ) {
		VectorSubtract( tr.endpos, cam->target.ideal, cam->target.damp );
	}
	VectorAdd( cam->target.ideal, cam->target.damp, target );
	trace( &tr, target, cameramins, cameramaxs, cam->loc.ideal, MASK_CAMERACLIP );
	if ( tr.fraction <= 1.0f ) {
		VectorSubtract( tr.endpos, cam->loc.ideal, cam->loc.damp );
	}
}

static void DampPosition( jkbVisDamp_t *pos, const jkbVisParams_t *p, float dampfactor, float dtime ) {
	vec3_t idealDelta;
	if ( dtime <= 0.0f ) {
		return;
	}
	VectorSubtract( pos->ideal, pos->prevIdeal, idealDelta );
	VectorCopy( pos->ideal, pos->prevIdeal );
	if ( p->cameraFPS >= CAMERA_MIN_FPS ) {
		vec3_t shift;
		dtime *= p->cameraFPS / 1000.0f;
		const float invdtime = 1.0f / dtime;
		const float timeadjfactor = powf( dampfactor, dtime );
		const float codampfactor = dampfactor / ( 1.0f - dampfactor );
		VectorScale( idealDelta, invdtime, shift );
		VectorScale( shift, codampfactor, shift );
		for ( int i = 0; i < 3; i++ ) {
			pos->damp[i] = timeadjfactor * ( pos->damp[i] + shift[i] ) - shift[i];
		}
	} else {
		VectorSubtract( pos->damp, idealDelta, pos->damp );
		VectorScale( pos->damp, dampfactor, pos->damp );
	}
}

static void UpdateTargetDamp( jkbVisCamera_t *cam, const jkbVisParams_t *p, const playerState_t *ps,
	const vec3_t vieworg, float dtime, jkbVisTrace_t trace ) {
	trace_t tr;
	vec3_t target;
	CalcIdealTarget( cam, p, ps, vieworg );
	if ( p->targetDamp >= 1.0f ) {
		VectorClear( cam->target.damp );
		cam->lastTime = 0;
	} else if ( p->targetDamp > 0.0f ) {
		DampPosition( &cam->target, p, 1.0f - p->targetDamp, dtime );
	} else {
		VectorSubtract( cam->target.prevIdeal, cam->target.ideal, cam->target.damp );
	}
	VectorAdd( cam->target.ideal, cam->target.damp, target );
	trace( &tr, cam->focus, cameramins, cameramaxs, target, MASK_CAMERACLIP );
	if ( tr.fraction < 1.0f ) {
		VectorSubtract( tr.endpos, cam->target.ideal, cam->target.damp );
	}
}

static void UpdateCameraDamp( jkbVisCamera_t *cam, const jkbVisParams_t *p, float dtime,
	float stiffFactor, float pitch, jkbVisTrace_t trace ) {
	trace_t tr;
	vec3_t location, target;
	float dampfactor = 0.0f;
	CalcIdealLocation( cam, p );
	if ( p->cameraDamp != 0.0f ) {
		const float dFactor = p->cameraDamp;
		pitch /= 115.0f;
		dampfactor = ( 1.0f - dFactor ) * ( pitch * pitch ) + dFactor;
		if ( stiffFactor > 0.0f ) {
			dampfactor += ( 1.0f - dampfactor ) * stiffFactor;
		}
	}
	if ( dampfactor >= 1.0f ) {
		VectorClear( cam->loc.damp );
		cam->lastTime = 0;
	} else if ( dampfactor > 0.0f ) {
		DampPosition( &cam->loc, p, 1.0f - dampfactor, dtime );
	} else {
		VectorSubtract( cam->loc.prevIdeal, cam->loc.ideal, cam->loc.damp );
	}
	VectorAdd( cam->loc.ideal, cam->loc.damp, location );
	VectorAdd( cam->target.ideal, cam->target.damp, target );
	trace( &tr, target, cameramins, cameramaxs, location, MASK_CAMERACLIP );
	if ( tr.fraction < 1.0f ) {
		VectorSubtract( tr.endpos, cam->loc.ideal, cam->loc.damp );
	}
}

void JKBVis_Camera( jkbVisCamera_t *cam, const jkbVisParams_t *p, const playerState_t *ps,
	jkbVisTrace_t trace, vec3_t viewOrg, vec3_t viewAngles ) {
	vec3_t vieworg, focusAngles, target, location, diff;
	VectorCopy( ps->origin, vieworg );  // CG_CalcViewValues
	VectorCopy( ps->viewangles, focusAngles );
	if ( ps->stats[STAT_HEALTH] <= 0 ) {
		focusAngles[YAW] = ps->stats[STAT_DEAD_YAW];  // dead: look at the killer
	} else {
		focusAngles[YAW] += p->angle;
		focusAngles[PITCH] += p->pitchOffset;
	}
	if ( focusAngles[PITCH] > 80.0f ) {
		focusAngles[PITCH] = 80.0f;
	} else if ( focusAngles[PITCH] < -80.0f ) {
		focusAngles[PITCH] = -80.0f;
	}
	AngleVectors( focusAngles, cam->fwd, NULL, NULL );

	const float dtime = (float)( ps->commandTime - cam->lastTime );
	if ( cam->lastTime == 0 || dtime < 0.0f ) {
		ResetDamp( cam, p, ps, vieworg, trace );
	} else {
		float deltayaw = fabsf( focusAngles[YAW] - cam->lastYaw );
		if ( deltayaw > 180.0f ) {
			deltayaw = fabsf( deltayaw - 360.0f );
		}
		float stiffFactor;
		if ( p->cameraFPS >= CAMERA_MIN_FPS ) {
			stiffFactor = dtime > 0.0f ? deltayaw / dtime : 0.0f;
		} else {
			stiffFactor = deltayaw / 8.0f;  // cg.time - cg.oldTime at 125 fps
		}
		if ( stiffFactor < 1.0f ) {
			stiffFactor = 0.0f;
		} else if ( stiffFactor > 2.5f ) {
			stiffFactor = 0.75f;
		} else {
			stiffFactor = ( stiffFactor - 1.0f ) * 0.5f;
		}
		const float pitch = fabsf( focusAngles[PITCH] );
		UpdateTargetDamp( cam, p, ps, vieworg, dtime, trace );
		UpdateCameraDamp( cam, p, dtime, stiffFactor, pitch, trace );
	}

	VectorAdd( cam->target.ideal, cam->target.damp, target );
	VectorAdd( cam->loc.ideal, cam->loc.damp, location );
	VectorSubtract( target, location, diff );
	if ( VectorLengthSquared( diff ) < 0.01f * 0.01f ) {
		VectorCopy( cam->fwd, diff );
	}
	vectoangles( diff, viewAngles );
	if ( p->horzOffset != 0.0f ) {
		vec3_t axis[3];
		AnglesToAxis( viewAngles, axis );
		VectorMA( location, p->horzOffset, axis[1], location );
	}
	VectorCopy( location, viewOrg );
	cam->lastTime = ps->commandTime;
	cam->lastYaw = focusAngles[YAW];
}

// ---- the frustum ----

qboolean JKBVis_InFrustum( const jkbVisParams_t *p, const vec3_t viewOrg, const vec3_t viewAngles,
	const vec3_t point ) {
	vec3_t fwd, right, up, d;
	AngleVectors( viewAngles, fwd, right, up );
	VectorSubtract( point, viewOrg, d );
	const float x = DotProduct( d, fwd );
	if ( x <= 0.0f ) {
		return qfalse;
	}
	const float tx = tanf( DEG2RAD( p->fovX * 0.5f ) ), ty = tanf( DEG2RAD( p->fovY * 0.5f ) );
	return (qboolean)( fabsf( DotProduct( d, right ) ) <= x * tx && fabsf( DotProduct( d, up ) ) <= x * ty );
}

// ---- sight geometry ----

static qboolean Named( const char *shader, const char **names, int n ) {
	for ( int i = 0; i < n; i++ ) {
		if ( !Q_stricmp( shader, names[i] ) ) {
			return qtrue;
		}
	}
	return qfalse;
}

void JKBVis_FreeSight( jkbVisSight_t *s ) {
	free( s->brushes );
	free( s->planes );
	free( s->tris );
	memset( s, 0, sizeof( *s ) );
}

#define LUMP( h, n, type, count ) \
	( ( count ) = ( h )->lumps[n].filelen / (int)sizeof( type ), \
	  (const type *)( (const byte *)( h ) + ( h )->lumps[n].fileofs ) )

qboolean JKBVis_LoadSight( jkbVisSight_t *s, const char *map, const void *bsp, int length,
	int mask, const char **ignore, int numIgnore, const char **occluders, int numOccluders ) {
	const dheader_t *h = (const dheader_t *)bsp;
	int numShaders, numPlanes, numModels, numBrushes, numSides, numSurfs, numVerts, numIndexes;
	memset( s, 0, sizeof( *s ) );
	Q_strncpyz( s->map, map, sizeof( s->map ) );
	if ( length < (int)sizeof( dheader_t ) || LittleLong( h->ident ) != BSP_IDENT ||
		LittleLong( h->version ) != BSP_VERSION ) {
		return qfalse;
	}
	for ( int i = 0; i < HEADER_LUMPS; i++ ) {
		if ( h->lumps[i].fileofs < 0 || h->lumps[i].filelen < 0 ||
			h->lumps[i].fileofs + h->lumps[i].filelen > length ) {
			return qfalse;
		}
	}
	const dshader_t *shaders = LUMP( h, LUMP_SHADERS, dshader_t, numShaders );
	const dplane_t *planes = LUMP( h, LUMP_PLANES, dplane_t, numPlanes );
	const dmodel_t *models = LUMP( h, LUMP_MODELS, dmodel_t, numModels );
	const dbrush_t *brushes = LUMP( h, LUMP_BRUSHES, dbrush_t, numBrushes );
	const dbrushside_t *sides = LUMP( h, LUMP_BRUSHSIDES, dbrushside_t, numSides );
	const dsurface_t *surfs = LUMP( h, LUMP_SURFACES, dsurface_t, numSurfs );
	const mapVert_t *verts = LUMP( h, LUMP_DRAWVERTS, mapVert_t, numVerts );
	const int *indexes = LUMP( h, LUMP_DRAWINDEXES, int, numIndexes );
	if ( numModels < 1 ) {
		return qfalse;
	}

	// the world's brushes (model 0; entity brush models aren't in the sight geometry)
	const dmodel_t *world = &models[0];
	s->brushes = (jkbVisBrush_t *)malloc( sizeof( jkbVisBrush_t ) * ( world->numBrushes + 1 ) );
	int totalSides = 0;
	for ( int b = world->firstBrush; b < world->firstBrush + world->numBrushes; b++ ) {
		totalSides += brushes[b].numSides;
	}
	s->planes = (vec4_t *)malloc( sizeof( vec4_t ) * ( totalSides + 1 ) );
	for ( int b = world->firstBrush; b < world->firstBrush + world->numBrushes && b < numBrushes; b++ ) {
		const dbrush_t *br = &brushes[b];
		if ( br->shaderNum < 0 || br->shaderNum >= numShaders ) {
			continue;
		}
		const dshader_t *sh = &shaders[br->shaderNum];
		if ( !( sh->contentFlags & mask ) || Named( sh->shader, ignore, numIgnore ) ) {
			continue;
		}
		jkbVisBrush_t *vb = &s->brushes[s->numBrushes++];
		vb->firstPlane = s->numPlanes;
		vb->numPlanes = 0;
		VectorSet( vb->mins, -MAX_WORLD_COORD, -MAX_WORLD_COORD, -MAX_WORLD_COORD );
		VectorSet( vb->maxs, MAX_WORLD_COORD, MAX_WORLD_COORD, MAX_WORLD_COORD );
		for ( int k = 0; k < br->numSides; k++ ) {
			const int side = br->firstSide + k;
			if ( side < 0 || side >= numSides || sides[side].planeNum < 0 || sides[side].planeNum >= numPlanes ) {
				continue;
			}
			const dplane_t *pl = &planes[sides[side].planeNum];
			float *out = s->planes[s->numPlanes++];
			VectorCopy( pl->normal, out );
			out[3] = pl->dist;
			vb->numPlanes++;
			for ( int a = 0; a < 3; a++ ) {  // the axial sides give the bounds
				if ( pl->normal[a] == 1.0f ) {
					vb->maxs[a] = pl->dist;
				} else if ( pl->normal[a] == -1.0f ) {
					vb->mins[a] = -pl->dist;
				}
			}
		}
	}

	// drawn surfaces that block sight but not traces
	int numTris = 0;
	for ( int i = 0; i < numSurfs; i++ ) {
		if ( surfs[i].shaderNum >= 0 && surfs[i].shaderNum < numShaders &&
			( surfs[i].surfaceType == MST_TRIANGLE_SOUP || surfs[i].surfaceType == MST_PLANAR ) &&
			Named( shaders[surfs[i].shaderNum].shader, occluders, numOccluders ) ) {
			numTris += surfs[i].numIndexes / 3;
		}
	}
	s->tris = (vec3_t *)malloc( sizeof( vec3_t ) * 3 * ( numTris + 1 ) );
	ClearBounds( s->trisMins, s->trisMaxs );
	for ( int i = 0; i < numSurfs; i++ ) {
		const dsurface_t *sf = &surfs[i];
		if ( sf->shaderNum < 0 || sf->shaderNum >= numShaders ||
			!( sf->surfaceType == MST_TRIANGLE_SOUP || sf->surfaceType == MST_PLANAR ) ||
			!Named( shaders[sf->shaderNum].shader, occluders, numOccluders ) ) {
			continue;
		}
		for ( int k = 0; k + 2 < sf->numIndexes; k += 3 ) {
			for ( int v = 0; v < 3; v++ ) {
				const int ix = sf->firstIndex + k + v;
				const int vi = ix >= 0 && ix < numIndexes ? sf->firstVert + indexes[ix] : -1;
				if ( vi < 0 || vi >= numVerts ) {
					return qfalse;
				}
				VectorCopy( verts[vi].xyz, s->tris[s->numTris * 3 + v] );
				AddPointToBounds( verts[vi].xyz, s->trisMins, s->trisMaxs );
			}
			s->numTris++;
		}
	}
	return qtrue;
}

static qboolean SegmentBoxOverlap( const vec3_t a, const vec3_t b, const vec3_t mins, const vec3_t maxs ) {
	for ( int i = 0; i < 3; i++ ) {
		if ( ( a[i] < mins[i] && b[i] < mins[i] ) || ( a[i] > maxs[i] && b[i] > maxs[i] ) ) {
			return qfalse;
		}
	}
	return qtrue;
}

// Cyrus-Beck: does the segment pass through the brush's interior?
static qboolean SegmentHitsBrush( const jkbVisSight_t *s, const jkbVisBrush_t *b, const vec3_t a, const vec3_t e ) {
	float enter = 0.0f, leave = 1.0f;
	for ( int i = 0; i < b->numPlanes; i++ ) {
		const float *pl = s->planes[b->firstPlane + i];
		const float d0 = DotProduct( a, pl ) - pl[3];
		const float d1 = DotProduct( e, pl ) - pl[3];
		if ( d0 > 0.0f && d1 > 0.0f ) {
			return qfalse;  // wholly outside this side
		}
		if ( d0 <= 0.0f && d1 <= 0.0f ) {
			continue;
		}
		const float t = d0 / ( d0 - d1 );
		if ( d0 > 0.0f ) {
			if ( t > enter ) enter = t;
		} else {
			if ( t < leave ) leave = t;
		}
		if ( enter >= leave ) {
			return qfalse;
		}
	}
	return qtrue;
}

// Moller-Trumbore, two-sided, strictly between the endpoints
static qboolean SegmentHitsTri( const vec3_t a, const vec3_t dir, const float *v0, const float *v1, const float *v2 ) {
	vec3_t e1, e2, pv, tv, qv;
	VectorSubtract( v1, v0, e1 );
	VectorSubtract( v2, v0, e2 );
	CrossProduct( dir, e2, pv );
	const float det = DotProduct( e1, pv );
	if ( fabsf( det ) < 1e-8f ) {
		return qfalse;
	}
	const float inv = 1.0f / det;
	VectorSubtract( a, v0, tv );
	const float u = DotProduct( tv, pv ) * inv;
	if ( u < 0.0f || u > 1.0f ) {
		return qfalse;
	}
	CrossProduct( tv, e1, qv );
	const float v = DotProduct( dir, qv ) * inv;
	if ( v < 0.0f || u + v > 1.0f ) {
		return qfalse;
	}
	const float t = DotProduct( e2, qv ) * inv;
	return (qboolean)( t > 1e-4f && t < 1.0f - 1e-4f );
}

qboolean JKBVis_SegmentClear( const jkbVisSight_t *s, const vec3_t a, const vec3_t b ) {
	for ( int i = 0; i < s->numBrushes; i++ ) {
		const jkbVisBrush_t *br = &s->brushes[i];
		if ( SegmentBoxOverlap( a, b, br->mins, br->maxs ) && SegmentHitsBrush( s, br, a, b ) ) {
			return qfalse;
		}
	}
	if ( s->numTris && SegmentBoxOverlap( a, b, s->trisMins, s->trisMaxs ) ) {
		vec3_t dir;
		VectorSubtract( b, a, dir );
		for ( int i = 0; i < s->numTris; i++ ) {
			const float *t = s->tris[i * 3];
			if ( SegmentHitsTri( a, dir, t, s->tris[i * 3 + 1], s->tris[i * 3 + 2] ) ) {
				return qfalse;
			}
		}
	}
	return qtrue;
}

// ---- the test ----

qboolean JKBVis_Visible( const jkbVisSight_t *s, const jkbVisParams_t *p, const vec3_t viewOrg,
	const vec3_t viewAngles, const vec3_t origin, const vec3_t mins, const vec3_t maxs,
	int *inView, int *clear ) {
	static const float sx[5] = { 0.0f, 0.8f, -0.8f, 0.0f, 0.0f };
	static const float sy[5] = { 0.0f, 0.0f, 0.0f, 0.8f, -0.8f };
	int seen = 0, open = 0, n = 0;
	for ( int h = 0; h < 3; h++ ) {
		const float z = h == 0 ? mins[2] + 4.0f : h == 1 ? ( mins[2] + maxs[2] ) * 0.5f : maxs[2] - 4.0f;
		for ( int k = 0; k < 5; k++, n++ ) {
			vec3_t pt;
			pt[0] = origin[0] + sx[k] * maxs[0];
			pt[1] = origin[1] + sy[k] * maxs[1];
			pt[2] = origin[2] + z;
			if ( JKBVis_InFrustum( p, viewOrg, viewAngles, pt ) ) {
				seen |= 1 << n;
			}
			if ( JKBVis_SegmentClear( s, viewOrg, pt ) ) {
				open |= 1 << n;
			}
		}
	}
	if ( inView ) {
		*inView = seen;
	}
	if ( clear ) {
		*clear = open;
	}
	return (qboolean)( ( seen & open ) != 0 );
}

#endif // JKBOT_AGENT
