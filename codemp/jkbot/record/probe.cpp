/*
 * Client probes (JKBot P1-M-08). Report only: no input endpoint, so they may ship in release
 * builds (see README.md).
 *
 * `+set jkbot_probeRefdef 1`: every refdef the cgame renders the world with (not
 * RDF_NOWORLDMODEL scenes such as UI models) is printed when it changes, as
 * "refdef: width W height H fov_x X fov_y Y", so a measurement reads the field of view the
 * client actually renders, not one computed from source.
 */

#include "client/client.h"

void CL_ProbeRefdef( const refdef_t *fd ) {
	static cvar_t *probe;
	static int last[2];
	static float lastFov[2];
	if ( !probe ) {
		probe = Cvar_Get( "jkbot_probeRefdef", "0", CVAR_TEMP, "Print the world refdef when it changes" );
	}
	if ( !probe->integer || ( fd->rdflags & RDF_NOWORLDMODEL ) ) {
		return;
	}
	if ( fd->width == last[0] && fd->height == last[1] && fd->fov_x == lastFov[0] && fd->fov_y == lastFov[1] ) {
		return;
	}
	last[0] = fd->width;
	last[1] = fd->height;
	lastFov[0] = fd->fov_x;
	lastFov[1] = fd->fov_y;
	Com_Printf( "refdef: width %d height %d fov_x %.6f fov_y %.6f\n", fd->width, fd->height, fd->fov_x, fd->fov_y );
}
