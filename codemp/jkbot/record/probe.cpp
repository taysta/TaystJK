/*
 * Client probes (JKBot P1-M-08, P1-M-21). Report only: no input endpoint, so they may ship in
 * release builds (see README.md).
 *
 * `+set jkbot_probeRefdef 1`: every refdef the cgame renders the world with (not
 * RDF_NOWORLDMODEL scenes such as UI models) is printed when it changes, as
 * "refdef: width W height H fov_x X fov_y Y", so a measurement reads the field of view the
 * client actually renders, not one computed from source.
 *
 * `+set jkbot_probePixels "R G B"`: while a demo plays, the pixels of exactly that colour in every
 * presented frame (read back just before the buffer swap) are counted and printed as
 * "pixels <count> <x0> <y0> <x1> <y1> <tinted>", with their bounding box from the top left (-1s
 * when there are none). tinted counts the pixels an additive surface in front has brightened: the
 * colour's 255 channels still 255, not exact and not white, inside jkbot_probeRect "x0 y0 x1 y1"
 * (from the top left; set by the agent cgame's visibility probe), and none without it. With
 * `jkbot_probeShots N`, up to N frames whose presence (count + tinted > 0) differs from
 * jkbot_probeExpect (set by the agent cgame's visibility probe) are saved as half-size PPMs under
 * the game dir as jkbot_probeShotDir/shot<n>.ppm, at least jkbot_probeShotGap frames apart, and
 * "pixels shot <path>" is printed after the frame's line.
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

#ifdef _WIN32
#define PROBE_APIENTRY __stdcall
#else
#define PROBE_APIENTRY
#endif
#define PROBE_GL_RGBA 0x1908
#define PROBE_GL_UNSIGNED_BYTE 0x1401

typedef void ( PROBE_APIENTRY *probeReadPixels_t )( int x, int y, int width, int height, unsigned format,
	unsigned type, void *pixels );

static void ProbeShot( const byte *rgba, int w, int h, int n ) {
	const char *dir = Cvar_VariableString( "jkbot_probeShotDir" );
	const char *path = va( "%s/shot%04d.ppm", dir[0] ? dir : "probeshots", n );
	const int sw = w / 2, sh = h / 2;
	const char *header = va( "P6\n%d %d\n255\n", sw, sh );
	byte *out = (byte *)Z_Malloc( sw * sh * 3, TAG_TEMP_WORKSPACE, qfalse );
	for ( int y = 0; y < sh; y++ ) {
		const byte *row = rgba + ( h - 1 - y * 2 ) * w * 4;  // GL rows run bottom up
		for ( int x = 0; x < sw; x++ ) {
			memcpy( out + ( y * sw + x ) * 3, row + x * 2 * 4, 3 );
		}
	}
	const fileHandle_t f = FS_FOpenFileWrite( path );
	if ( f ) {
		FS_Write( header, (int)strlen( header ), f );
		FS_Write( out, sw * sh * 3, f );
		FS_FCloseFile( f );
		Com_Printf( "pixels shot %s\n", path );
	}
	Z_Free( out );
}

void CL_ProbePixels( void ) {
	static cvar_t *probe, *shots, *gap;
	static probeReadPixels_t readPixels;
	static byte *buf;
	static int bufSize, numShots, lastShot = -1000000, frame;
	if ( !probe ) {
		probe = Cvar_Get( "jkbot_probePixels", "", CVAR_TEMP, "Count a colour's pixels in every demo frame" );
		shots = Cvar_Get( "jkbot_probeShots", "0", CVAR_TEMP, "Frames to save when presence differs from jkbot_probeExpect" );
		gap = Cvar_Get( "jkbot_probeShotGap", "30", CVAR_TEMP, "Fewest frames between saved frames" );
		Cvar_Get( "jkbot_probeShotDir", "probeshots", CVAR_TEMP, "Where saved frames go, under the game dir" );
		Cvar_Get( "jkbot_probeExpect", "0", CVAR_TEMP, "Expected presence for the current frame" );
		Cvar_Get( "jkbot_probeRect", "", CVAR_TEMP, "Where brightened pixels of the colour count (x0 y0 x1 y1)" );
	}
	int r, g, b;
	if ( !probe->string[0] || !clc.demoplaying || cls.state != CA_ACTIVE ||
		sscanf( probe->string, "%d %d %d", &r, &g, &b ) != 3 ) {
		return;
	}
	if ( !readPixels ) {
		readPixels = (probeReadPixels_t)WIN_GL_GetProcAddress( "glReadPixels" );
		if ( !readPixels ) {
			return;
		}
	}
	const int w = cls.glconfig.vidWidth, h = cls.glconfig.vidHeight;
	if ( w <= 0 || h <= 0 ) {
		return;
	}
	if ( bufSize < w * h * 4 ) {
		if ( buf ) {
			Z_Free( buf );
		}
		bufSize = w * h * 4;
		buf = (byte *)Z_Malloc( bufSize, TAG_CLIENTS, qfalse );
	}
	readPixels( 0, 0, w, h, PROBE_GL_RGBA, PROBE_GL_UNSIGNED_BYTE, buf );
	int rect[4] = { 0, 0, -1, -1 };
	sscanf( Cvar_VariableString( "jkbot_probeRect" ), "%d %d %d %d", &rect[0], &rect[1], &rect[2], &rect[3] );
	int count = 0, tinted = 0, x0 = w, y0 = h, x1 = -1, y1 = -1;
	for ( int y = 0; y < h; y++ ) {
		const byte *row = buf + y * w * 4;
		const int ty = h - 1 - y;
		const qboolean inRows = (qboolean)( ty >= rect[1] && ty <= rect[3] );
		for ( int x = 0; x < w; x++ ) {
			const byte *px = row + x * 4;
			if ( px[0] != r || px[1] != g || px[2] != b ) {
				if ( inRows && x >= rect[0] && x <= rect[2] &&
					( r < 255 || px[0] == 255 ) && ( g < 255 || px[1] == 255 ) && ( b < 255 || px[2] == 255 ) &&
					( r == 255 || g == 255 || b == 255 ) && !( px[0] == 255 && px[1] == 255 && px[2] == 255 ) ) {
					tinted++;
				}
				continue;
			}
			count++;
			if ( x < x0 ) x0 = x;
			if ( x > x1 ) x1 = x;
			if ( ty < y0 ) y0 = ty;
			if ( ty > y1 ) y1 = ty;
		}
	}
	if ( !count ) {
		x0 = y0 = x1 = y1 = -1;
	}
	Com_Printf( "pixels %d %d %d %d %d %d\n", count, x0, y0, x1, y1, tinted );
	frame++;
	if ( numShots < shots->integer && ( count + tinted > 0 ) != ( Cvar_VariableIntegerValue( "jkbot_probeExpect" ) != 0 ) &&
		frame - lastShot >= gap->integer ) {
		ProbeShot( buf, w, h, numShots++ );
		lastShot = frame;
	}
}
