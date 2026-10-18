/*
 * JKBot static-geometry rays (P1-ENG-13; environment.md §4: "omnidirectional ray traces against
 * static geometry only (map memory is human-equivalent)").
 *
 * From the eye, `count` rays spread evenly over the sphere (a Fibonacci lattice) in the player's
 * yaw frame, so they turn with the player but not with its pitch. Each is a point trace of
 * `length` units against what blocks a player's movement in the world model (brushes and patches,
 * JKB_RAYS_MASK), and reports the hit fraction. Count and length are config placeholders
 * (config/v1.toml observation.ray_count, ray_length).
 *
 * Compiled as C++ in the agent server (it's the common subset of C and C++).
 */
#ifdef JKBOT_AGENT

#include <math.h>

#include "qcommon/q_shared.h"
#include "rays.h"

#define GOLDEN_ANGLE 2.39996322972865332  // pi * (3 - sqrt(5))

void JKBRays_Eye( const playerState_t *ps, vec3_t eye ) {
	VectorCopy( ps->origin, eye );
	eye[2] += ps->viewheight;
}

// In double, then rounded: the azimuth reaches ~150 radians at 64 rays, past float precision.
void JKBRays_Direction( int i, int count, float yaw, vec3_t dir ) {
	const double z = 1.0 - ( 2.0 * i + 1.0 ) / count;
	const double r = sqrt( 1.0 - z * z );
	const double a = i * GOLDEN_ANGLE + yaw * ( M_PI / 180.0 );  // azimuth 0 = the player's forward
	VectorSet( dir, (float)( r * cos( a ) ), (float)( r * sin( a ) ), (float)z );
}

void JKBRays_Cast( const vec3_t eye, float yaw, int count, float length, jkbRaysTrace_t trace,
	float *fractions ) {
	for ( int i = 0; i < count; i++ ) {
		vec3_t dir, end;
		trace_t tr;
		JKBRays_Direction( i, count, yaw, dir );
		VectorMA( eye, length, dir, end );
		trace( &tr, eye, end, JKB_RAYS_MASK );
		fractions[i] = tr.fraction;
	}
}

#endif // JKBOT_AGENT
