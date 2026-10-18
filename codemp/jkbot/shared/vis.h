/*
 * JKBot visibility model (P1-ENG-12; environment.md §5.2, ruleset §3.3). See vis.c.
 *
 * Plain computation over a playerState and the map's BSP bytes, with no engine state: the agent
 * server uses it now (visibility.cpp) and the client dump is meant to (P2-DM-05).
 */
#pragma once

#ifdef JKBOT_AGENT

#include "qcommon/q_shared.h"

// The bot's camera and view (environment.md §5.2): cg_thirdPersonRange 80, everything else at
// the TaystJK client's defaults, and the FOV the client renders at cg_fov 97, cg_fovAspectAdjust
// 1, 16:9 (measurements/fov.json).
typedef struct jkbVisParams_s {
	float range;  // cg_thirdPersonRange
	float angle;  // cg_thirdPersonAngle
	float vertOffset;  // cg_thirdPersonVertOffset
	float pitchOffset;  // cg_thirdPersonPitchOffset
	float horzOffset;  // cg_thirdPersonHorzOffset
	float targetDamp;  // cg_thirdPersonTargetDamp
	float cameraDamp;  // cg_thirdPersonCameraDamp
	float cameraFPS;  // cg_cameraFPS
	float fovX, fovY;  // degrees
} jkbVisParams_t;

void JKBVis_DefaultParams( jkbVisParams_t *p );

// The cgame's third-person camera state (cg_view.c `cam`), one per viewer.
typedef struct jkbVisDamp_s {
	vec3_t ideal, prevIdeal, damp;
} jkbVisDamp_t;

typedef struct jkbVisCamera_s {
	jkbVisDamp_t target, loc;
	vec3_t fwd, focus;
	float lastYaw;
	int lastTime;
} jkbVisCamera_t;

// The camera's collision trace: MASK_CAMERACLIP with a +-4 box (CG_Trace).
typedef void ( *jkbVisTrace_t )( trace_t *result, const vec3_t start, const vec3_t mins,
	const vec3_t maxs, const vec3_t end, int mask );

void JKBVis_CameraReset( jkbVisCamera_t *cam );
// CG_CalcViewValues + CG_OffsetThirdPersonView for the (predicted) playerState: the camera's
// origin and angles, as the client renders them.
void JKBVis_Camera( jkbVisCamera_t *cam, const jkbVisParams_t *p, const playerState_t *ps,
	jkbVisTrace_t trace, vec3_t viewOrg, vec3_t viewAngles );

// Sight geometry for one map: the world's brushes that block sight and the extra occluding
// triangles (measurements/sightsurfaces.json: MASK_OPAQUE brushes but those with an ignored
// shader, plus drawn surfaces that block sight but not traces).
typedef struct jkbVisBrush_s {
	int firstPlane, numPlanes;
	vec3_t mins, maxs;
} jkbVisBrush_t;

typedef struct jkbVisSight_s {
	char map[MAX_QPATH];
	int numBrushes, numPlanes, numTris;
	jkbVisBrush_t *brushes;
	vec4_t *planes;  // normal, dist (outward)
	vec3_t *tris;  // 3 vertices each
	vec3_t trisMins, trisMaxs;
} jkbVisSight_t;

// Builds sight geometry from BSP bytes; shader lists are names, mask the brush contents that
// block sight. Returns qfalse (and an empty sight) on a bad file. Memory from malloc.
qboolean JKBVis_LoadSight( jkbVisSight_t *s, const char *map, const void *bsp, int length,
	int mask, const char **ignore, int numIgnore, const char **occluders, int numOccluders );
void JKBVis_FreeSight( jkbVisSight_t *s );

// Whether nothing in the sight geometry lies on the segment a-b.
qboolean JKBVis_SegmentClear( const jkbVisSight_t *s, const vec3_t a, const vec3_t b );

// Whether a point is inside the view frustum (in front, within fovX/2 and fovY/2).
qboolean JKBVis_InFrustum( const jkbVisParams_t *p, const vec3_t viewOrg, const vec3_t viewAngles,
	const vec3_t point );

// A player entity's box: the packed solid (BG_PlayerStateToEntityState), else a player's default
// box.
void JKBVis_PlayerBox( int solid, vec3_t mins, vec3_t maxs );

#define JKB_VIS_SAMPLES 15

// The visibility test (environment.md §5.2, placeholder method): sample points on the target's
// bounding box (3 heights x the centre and 4 sides); visible if any one is in the frustum with a
// clear line from the camera. inView/clear (optional) get per-sample bit masks.
qboolean JKBVis_Visible( const jkbVisSight_t *s, const jkbVisParams_t *p, const vec3_t viewOrg,
	const vec3_t viewAngles, const vec3_t origin, const vec3_t mins, const vec3_t maxs,
	int *inView, int *clear );

#endif // JKBOT_AGENT
