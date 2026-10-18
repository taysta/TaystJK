/*
 * JKBot static-geometry rays (P1-ENG-13; environment.md §4). See rays.c.
 *
 * Plain computation over a playerState and a trace function, with no engine state: the agent
 * server casts them with CM traces against the world model (geometry.cpp), and the client dump is
 * meant to, after loading the map's clip model (P2-DM-05).
 */
#pragma once

#ifdef JKBOT_AGENT

#include "qcommon/q_shared.h"

// What a ray stops at: the world brushes and patches that block a player's movement. Entities
// (players, movers) aren't traced: the trace function covers the world model only.
#define JKB_RAYS_MASK ( CONTENTS_SOLID | CONTENTS_PLAYERCLIP | CONTENTS_TERRAIN )

// A point trace (no box) from start to end against the world model only.
typedef void ( *jkbRaysTrace_t )( trace_t *result, const vec3_t start, const vec3_t end, int mask );

// The eye: the playerState's origin raised by its viewheight.
void JKBRays_Eye( const playerState_t *ps, vec3_t eye );

// Ray i of count: a Fibonacci sphere in the player's yaw frame (pitch and roll ignored), from
// straight up (i = 0) to straight down (i = count - 1), unit length.
void JKBRays_Direction( int i, int count, float yaw, vec3_t dir );

// Each ray's hit fraction of length from the eye (1 when nothing is hit within length).
void JKBRays_Cast( const vec3_t eye, float yaw, int count, float length, jkbRaysTrace_t trace,
	float *fractions );

#endif // JKBOT_AGENT
