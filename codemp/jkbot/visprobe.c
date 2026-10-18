/*
 * JKBot visibility probe (P1-M-21; environment.md §5.2 and appendix): checks the visibility model
 * (shared/vis.c) against what the client renders. Built into the cgame of agent client builds only
 * (`scripts/build_client.sh --agent`), and active only while a demo plays.
 *
 * With `jkbot_visProbe <file>` (a sight list in the game dir, one jkbot_sight item per line:
 * mask <contents> | ignore <shader> | occluder <shader>; see visibility.cpp):
 * - every other player is drawn with the shader jkbot/visprobe (a flat colour; the measurement
 *   writes it next to the list), and saber blades, trails and their effects and the spheres around
 *   players (spawn invulnerability) aren't drawn: they're translucent, so they hide nothing from a
 *   human, but they'd tint the flat colour;
 * - after each rendered frame the model tests the other player's box at its rendered origin, from
 *   two cameras: the one the frame was rendered with (cg.refdef), and the model's own camera
 *   following the frame's playerState as the agent server's does (visibility.cpp). It prints
 *     visprobe <time> <targets> <target> <eFlags> <drawn> <ref: visible inView clear>
 *       <model: visible inView clear> ref <x y z pitch yaw> cam <x y z pitch yaw> org <x y z>
 *       box <mins maxs> own <x y z> <pm_type> <health>
 *   (drawn: CG_Player drew the target's model this frame; own: the frame's playerState) or
 *   "visprobe <time> 0" when there's no other player,
 *   and sets, for the engine's pixel probe (record/probe.cpp), jkbot_probeExpect to the rendered
 *   camera's flag and jkbot_probeRect to the screen rectangle of the target's box grown by
 *   RECT_MARGIN units (where its brightened pixels may be; the whole screen if the box reaches
 *   behind the camera).
 */
#ifdef JKBOT_AGENT

#include <stdlib.h>

#include "cgame/cg_local.h"
#include "jkbot/shared/vis.h"

#define VISPROBE_LIST 64
#define RECT_MARGIN 32.0f  // limbs and the hilt reach past the box in swings

static vmCvar_t visProbe;
static jkbVisParams_t params;
static jkbVisSight_t sight;
static jkbVisCamera_t cam;
static qhandle_t flatShader;
static qboolean loaded;
static int drawnTime = -1, drawnNum = -1;
static char loadedList[MAX_CVAR_VALUE_STRING], loadedMap[MAX_QPATH];

void CG_VisProbeInit( void ) {
	trap->Cvar_Register( &visProbe, "jkbot_visProbe", "", CVAR_TEMP );
	JKBVis_DefaultParams( &params );
	JKBVis_CameraReset( &cam );
	loaded = qfalse;
}

void CG_VisProbeShutdown( void ) {
	JKBVis_FreeSight( &sight );
	loaded = qfalse;
}

static char *ReadFile( const char *path, int *length ) {
	fileHandle_t f;
	const int len = trap->FS_Open( path, &f, FS_READ );
	if ( len <= 0 || !f ) {
		if ( f ) {
			trap->FS_Close( f );
		}
		return NULL;
	}
	char *buf = (char *)malloc( len + 1 );
	trap->FS_Read( buf, len, f );
	trap->FS_Close( f );
	buf[len] = 0;
	*length = len;
	return buf;
}

static void Load( void ) {
	static char ignore[VISPROBE_LIST][MAX_QPATH], occluders[VISPROBE_LIST][MAX_QPATH];
	const char *ignoreP[VISPROBE_LIST], *occluderP[VISPROBE_LIST];
	int numIgnore = 0, numOccluders = 0, mask = MASK_OPAQUE, len;

	JKBVis_FreeSight( &sight );
	JKBVis_CameraReset( &cam );
	loaded = qtrue;
	Q_strncpyz( loadedList, visProbe.string, sizeof( loadedList ) );
	Q_strncpyz( loadedMap, cgs.mapname, sizeof( loadedMap ) );

	char *list = ReadFile( visProbe.string, &len );
	if ( !list ) {
		trap->Print( "visprobe: can't read %s\n", visProbe.string );
		return;
	}
	const char *p = list;
	for ( ;; ) {
		const char *what = COM_ParseExt( &p, qtrue );
		if ( !what[0] ) {
			break;
		}
		if ( !Q_stricmp( what, "mask" ) ) {
			mask = atoi( COM_ParseExt( &p, qfalse ) );
		} else if ( !Q_stricmp( what, "ignore" ) && numIgnore < VISPROBE_LIST ) {
			Q_strncpyz( ignore[numIgnore], COM_ParseExt( &p, qfalse ), MAX_QPATH );
			ignoreP[numIgnore] = ignore[numIgnore];
			numIgnore++;
		} else if ( !Q_stricmp( what, "occluder" ) && numOccluders < VISPROBE_LIST ) {
			Q_strncpyz( occluders[numOccluders], COM_ParseExt( &p, qfalse ), MAX_QPATH );
			occluderP[numOccluders] = occluders[numOccluders];
			numOccluders++;
		} else if ( Q_stricmp( what, "clear" ) ) {
			trap->Print( "visprobe: bad sight list item %s\n", what );
			free( list );
			return;
		}
		SkipRestOfLine( &p );
	}
	free( list );

	char *bsp = ReadFile( cgs.mapname, &len );
	if ( !bsp ) {
		trap->Print( "visprobe: can't read %s\n", cgs.mapname );
		return;
	}
	const qboolean ok = JKBVis_LoadSight( &sight, cgs.mapname, bsp, len, mask, ignoreP, numIgnore,
		occluderP, numOccluders );
	free( bsp );
	flatShader = trap->R_RegisterShader( "jkbot/visprobe" );
	trap->Print( "visprobe: %s: mask %d, %d ignored, %d occluder shaders: %d brushes, %d occluding triangles%s\n",
		cgs.mapname, mask, numIgnore, numOccluders, sight.numBrushes, sight.numTris, ok ? "" : " (bad BSP)" );
}

static qboolean Active( void ) {
	if ( !cg.demoPlayback || !visProbe.string[0] ) {
		return qfalse;
	}
	if ( !loaded || strcmp( loadedList, visProbe.string ) || Q_stricmp( loadedMap, cgs.mapname ) ) {
		Load();
	}
	return (qboolean)( sight.numBrushes > 0 );
}

// The flat colour for every other player's model (CG_Player, before its main refEntity is added).
void CG_VisProbePlayer( const centity_t *cent, refEntity_t *legs ) {
	if ( cent->currentState.eType != ET_PLAYER || cent->currentState.number == cg.snap->ps.clientNum ||
		!Active() ) {
		return;
	}
	drawnTime = cg.time;
	drawnNum = cent->currentState.number;
	legs->customShader = flatShader;
	legs->renderfx &= ~( RF_RGB_TINT | RF_FORCE_ENT_ALPHA );
	legs->shaderRGBA[0] = legs->shaderRGBA[1] = legs->shaderRGBA[2] = legs->shaderRGBA[3] = 255;
}

// Whether translucent overlays are left undrawn: saber blades and their effects (CG_AddSaberBlade's
// dontDraw) and the spheres around players (CG_DrawPlayerSphere, e.g. spawn invulnerability).
qboolean CG_VisProbeHideOverlays( void ) {
	return Active();
}

static void CameraTrace( trace_t *result, const vec3_t start, const vec3_t mins, const vec3_t maxs,
	const vec3_t end, int mask ) {
	// world brushes only, as the agent server's camera (visibility.cpp)
	trap->CM_Trace( result, start, end, mins, maxs, 0, mask, 0 );
}

static void PlayerBox( const entityState_t *es, vec3_t mins, vec3_t maxs ) {
	if ( es->solid && es->solid != SOLID_BMODEL ) {  // the packed box (BG_PlayerStateToEntityState)
		const int x = es->solid & 255, zd = ( es->solid >> 8 ) & 255, zu = ( ( es->solid >> 16 ) & 255 ) - 32;
		VectorSet( mins, -x, -x, -zd );
		VectorSet( maxs, x, x, zu );
	} else {  // a player's default box
		VectorSet( mins, -15, -15, DEFAULT_MINS_2 );
		VectorSet( maxs, 15, 15, DEFAULT_MAXS_2 );
	}
}

// The screen rectangle (pixels from the top left) of a box seen with the frame's refdef: its corners
// in front of the camera and the points where its edges cross the near plane (x = 1). Empty
// (x1 < x0) when the box is wholly behind.
static void ScreenRect( const vec3_t org, const vec3_t mins, const vec3_t maxs, float margin, int rect[4] ) {
	const refdef_t *rd = &cg.refdef;
	const float tx = tanf( DEG2RAD( rd->fov_x * 0.5f ) ), ty = tanf( DEG2RAD( rd->fov_y * 0.5f ) );
	vec3_t v[8];  // x forward, y left, z up
	float x0 = 1e9f, y0 = 1e9f, x1 = -1e9f, y1 = -1e9f;
	for ( int c = 0; c < 8; c++ ) {
		vec3_t p, d;
		p[0] = org[0] + ( ( c & 1 ) ? maxs[0] + margin : mins[0] - margin );
		p[1] = org[1] + ( ( c & 2 ) ? maxs[1] + margin : mins[1] - margin );
		p[2] = org[2] + ( ( c & 4 ) ? maxs[2] + margin : mins[2] - margin );
		VectorSubtract( p, rd->vieworg, d );
		VectorSet( v[c], DotProduct( d, rd->viewaxis[0] ), DotProduct( d, rd->viewaxis[1] ), DotProduct( d, rd->viewaxis[2] ) );
	}
	for ( int c = 0; c < 8; c++ ) {
		for ( int e = -1; e < 3; e++ ) {  // the corner itself, then its edges to corners c ^ (1 << e)
			vec3_t q;
			if ( e < 0 ) {
				if ( v[c][0] < 1.0f ) {
					continue;
				}
				VectorCopy( v[c], q );
			} else {
				const float *a = v[c], *b = v[c ^ ( 1 << e )];
				if ( a[0] >= 1.0f || b[0] < 1.0f ) {  // each crossing once, from its behind end
					continue;
				}
				const float t = ( 1.0f - a[0] ) / ( b[0] - a[0] );
				for ( int k = 0; k < 3; k++ ) {
					q[k] = a[k] + t * ( b[k] - a[k] );
				}
			}
			const float sx = rd->width * 0.5f * ( 1.0f - q[1] / ( q[0] * tx ) );
			const float sy = rd->height * 0.5f * ( 1.0f - q[2] / ( q[0] * ty ) );
			x0 = Q_min( x0, sx );
			y0 = Q_min( y0, sy );
			x1 = Q_max( x1, sx );
			y1 = Q_max( y1, sy );
		}
	}
	if ( x1 < x0 ) {
		rect[0] = rect[1] = 0;
		rect[2] = rect[3] = -1;
		return;
	}
	rect[0] = (int)Q_max( floorf( x0 ), 0.0f );
	rect[1] = (int)Q_max( floorf( y0 ), 0.0f );
	rect[2] = (int)Q_min( ceilf( x1 ), rd->width - 1.0f );
	rect[3] = (int)Q_min( ceilf( y1 ), rd->height - 1.0f );
}

// After the frame's scene is rendered (CG_DrawActiveFrame).
void CG_VisProbeFrame( void ) {
	trap->Cvar_Update( &visProbe );
	if ( !cg.snap || !Active() ) {
		return;
	}
	vec3_t camOrg, camAngles;
	JKBVis_Camera( &cam, &params, &cg.predictedPlayerState, CameraTrace, camOrg, camAngles );

	int targets = 0;
	const centity_t *target = NULL;
	for ( int i = 0; i < cg.snap->numEntities; i++ ) {
		const entityState_t *es = &cg.snap->entities[i];
		if ( es->eType == ET_PLAYER && es->number < MAX_CLIENTS && es->number != cg.snap->ps.clientNum ) {
			if ( !targets++ ) {
				target = &cg_entities[es->number];
			}
		}
	}
	if ( !target ) {
		trap->Print( "visprobe %d 0\n", cg.time );
		trap->Cvar_Set( "jkbot_probeExpect", "0" );
		trap->Cvar_Set( "jkbot_probeRect", "" );
		return;
	}
	vec3_t mins, maxs;
	int refIn, refClear, camIn, camClear;
	const playerState_t *ps = &cg.predictedPlayerState;
	const qboolean drawn = (qboolean)( drawnTime == cg.time && drawnNum == target->currentState.number );
	PlayerBox( &target->currentState, mins, maxs );
	const qboolean refVis = JKBVis_Visible( &sight, &params, cg.refdef.vieworg, cg.refdef.viewangles,
		target->lerpOrigin, mins, maxs, &refIn, &refClear );
	const qboolean camVis = JKBVis_Visible( &sight, &params, camOrg, camAngles, target->lerpOrigin, mins,
		maxs, &camIn, &camClear );
	trap->Print( "visprobe %d %d %d %d %d %d %d %d %d %d %d ref %.3f %.3f %.3f %.3f %.3f cam %.3f %.3f %.3f %.3f %.3f "
		"org %.3f %.3f %.3f box %.0f %.0f %.0f %.0f %.0f %.0f own %.3f %.3f %.3f %d %d\n",
		cg.time, targets, target->currentState.number, target->currentState.eFlags, drawn, refVis, refIn, refClear,
		camVis, camIn, camClear, cg.refdef.vieworg[0], cg.refdef.vieworg[1], cg.refdef.vieworg[2],
		cg.refdef.viewangles[PITCH], cg.refdef.viewangles[YAW], camOrg[0], camOrg[1], camOrg[2],
		camAngles[PITCH], camAngles[YAW], target->lerpOrigin[0], target->lerpOrigin[1], target->lerpOrigin[2],
		mins[0], mins[1], mins[2], maxs[0], maxs[1], maxs[2], ps->origin[0], ps->origin[1], ps->origin[2],
		ps->pm_type, ps->stats[STAT_HEALTH] );
	int rect[4];
	ScreenRect( target->lerpOrigin, mins, maxs, RECT_MARGIN, rect );
	trap->Cvar_Set( "jkbot_probeExpect", refVis ? "1" : "0" );
	trap->Cvar_Set( "jkbot_probeRect", va( "%d %d %d %d", rect[0], rect[1], rect[2], rect[3] ) );
}

#endif // JKBOT_AGENT
