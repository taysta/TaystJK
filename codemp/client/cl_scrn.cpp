/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2005 - 2015, ioquake3 contributors
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

// cl_scrn.c -- master for refresh, status bar, console, chat, notify, etc

#include "client.h"
#include "cl_uiapi.h"

extern console_t con;
qboolean	scr_initialized;		// ready to draw

cvar_t		*cl_timegraph;
cvar_t		*cl_debuggraph;
cvar_t		*cl_graphheight;
cvar_t		*cl_graphscale;
cvar_t		*cl_graphshift;

vec2_t		cgamefov = { 112.867958f, 80.577278f };

cvar_t		*scr_hud_snap_draw, *scr_hud_snap_rgba1, *scr_hud_snap_rgba2, *scr_hud_snap_y, *scr_hud_snap_h, *scr_hud_snap_auto, *scr_hud_snap_def, *scr_hud_snap_speed;
cvar_t		*scr_hud_pitch, *scr_hud_pitch_rgba, *scr_hud_pitch_thickness, *scr_hud_pitch_width, *scr_hud_pitch_x;

/*
================
SCR_DrawNamedPic

Coordinates are 640*480 virtual values
=================
*/
void SCR_DrawNamedPic( float x, float y, float width, float height, const char *picname ) {
	qhandle_t	hShader;

	assert( width != 0 );

	hShader = re->RegisterShader( picname );
	re->DrawStretchPic( x, y, width, height, 0, 0, 1, 1, hShader );
}


/*
================
SCR_FillRect

Coordinates are 640*480 virtual values
=================
*/
void SCR_FillRect( float x, float y, float width, float height, const float *color ) {
	re->SetColor( color );

	re->DrawStretchPic( x, y, width, height, 0, 0, 0, 0, cls.whiteShader );

	re->SetColor( NULL );
}

//snaphud start
/*
================
SCR_AdjustFrom640
Adjusted for resolution and screen aspect ratio
================
*/
void SCR_AdjustFrom640(float *x, float *y, float *w, float *h) {
	float	xscale;
	float	yscale;

#if 0
	// adjust for wide screens
	if (cls.glconfig.vidWidth * 480 > cls.glconfig.vidHeight * 640) {
		*x += 0.5 * (cls.glconfig.vidWidth - (cls.glconfig.vidHeight * 640 / 480));
	}
#endif

	// scale for screen sizes
	xscale = cls.glconfig.vidWidth / SCREEN_WIDTH;
	yscale = cls.glconfig.vidHeight / SCREEN_HEIGHT;
	if (x) {
		*x *= xscale;
	}
	if (y) {
		*y *= yscale;
	}
	if (w) {
		*w *= xscale;
	}
	if (h) {
		*h *= yscale;
	}
}

/*
================
SCR_FillAngle, SCR_MarkAngle
=================
*/
void SCR_FillAngleYaw(float start, float end, float viewangle, float y, float height, const float *color) {
	float x, width, fovscale;
	fovscale = tan(DEG2RAD(cgamefov[0] / 2));
	x = SCREEN_WIDTH / 2 + tan(DEG2RAD(viewangle + start)) / fovscale*SCREEN_WIDTH / 2;
	width = abs(SCREEN_WIDTH*(tan(DEG2RAD(viewangle + end)) - tan(DEG2RAD(viewangle + start))) / (fovscale * 2)) + 1;

	re->SetColor(color);
	//SCR_AdjustFrom640(&x, &y, &width, &height);
	re->DrawStretchPic(x, y, width, height, 0, 0, 0, 0, cls.whiteShader);
	re->SetColor(NULL);
}

void SCR_MarkAnglePitch(float angle, float height, float viewangle, float x, float width, const float *color) {
	float y, fovscale;

	if (-cl.snap.ps.viewangles[PITCH] + angle > cgamefov[1] / 2 + 5) return;
	fovscale = tan(DEG2RAD(cgamefov[1] / 2));
	y = SCREEN_HEIGHT / 2 + tan(DEG2RAD(viewangle + angle)) / fovscale*SCREEN_HEIGHT / 2;

	re->SetColor(color);
	//SCR_AdjustFrom640(&x, &y, &width, &height);
	re->DrawStretchPic(x - width / 2, y - height / 2, width, height, 0, 0, 0, 0, cls.whiteShader);
	re->SetColor(NULL);
}
//snaphud end


/*
================
SCR_DrawPic

Coordinates are 640*480 virtual values
=================
*/
void SCR_DrawPic( float x, float y, float width, float height, qhandle_t hShader ) {
	re->DrawStretchPic( x, y, width, height, 0, 0, 1, 1, hShader );
}



/*
** SCR_DrawChar
** chars are drawn at 640*480 virtual screen size
*/
static void SCR_DrawChar( int x, int y, float size, int ch ) {
	int row, col;
	float frow, fcol;
	float	ax, ay, aw, ah;

	ch &= 255;

	if ( ch == ' ' ) {
		return;
	}

	if ( y < -size ) {
		return;
	}

	ax = x;
	ay = y;
	aw = size;
	ah = size;

	row = ch>>4;
	col = ch&15;

	float size2;

	frow = row*0.0625;
	fcol = col*0.0625;
	size = 0.03125;
	size2 = 0.0625;

	re->DrawStretchPic( ax, ay, aw, ah,
					   fcol, frow,
					   fcol + size, frow + size2,
					   cls.charSetShader );
}
void SCR_DrawChar2(float x, float y, float width, float height, int ch) {
	int row, col;
	float frow, fcol;
	float ax, ay, aw, ah;
	float size, size2;

	ch &= 255;

	if (ch == ' ') {
		return;
	}

	ax = x;
	ay = y;
	aw = width;
	ah = height;

	row = ch >> 4;
	col = ch & 15;

	frow = row*0.0625;
	fcol = col*0.0625;
	size = 0.03125;
	size2 = 0.0625;

	re->DrawStretchPic(ax, ay, aw, ah,
		fcol, frow,
		fcol + size, frow + size2,
		cls.charSetShader);
}

/*
** SCR_DrawSmallChar
** small chars are drawn at native screen resolution
*/
void SCR_DrawSmallChar( int x, int y, int ch ) {
	int row, col;
	float frow, fcol;
	float size;

	ch &= 255;

	if ( ch == ' ' ) {
		return;
	}

	if ( y < -con.charHeight ) {
		return;
	}

	row = ch>>4;
	col = ch&15;

	float size2;

	frow = row*0.0625;
	fcol = col*0.0625;

	size = 0.03125;
//	size = 0.0625;

	size2 = 0.0625;

	re->DrawStretchPic( x * con.xadjust, y * con.yadjust,
						con.charWidth * con.xadjust, con.charHeight * con.yadjust,
					   fcol, frow,
					   fcol + size, frow + size2,
					   cls.charSetShader );
}


/*
==================
SCR_DrawBigString[Color]

Draws a multi-colored string with a drop shadow, optionally forcing
to a fixed color.

Coordinates are at 640 by 480 virtual resolution
==================
*/
void SCR_DrawStringExt( int x, int y, float size, const char *string, float *setColor, qboolean forceColor, qboolean noColorEscape ) {
	vec4_t		color;
	const char	*s;
	int			xx;

	// draw the drop shadow
	color[0] = color[1] = color[2] = 0;
	color[3] = setColor[3];
	re->SetColor( color );
	s = string;
	xx = x;
	while ( *s ) {
		if ( !noColorEscape && Q_IsColorString( s ) ) {
			s += 2;
			continue;
		}
		SCR_DrawChar( xx+2*cls.widthRatioCoef, y+2, size, *s );
		xx += size;
		s++;
	}


	// draw the colored text
	s = string;
	xx = x;
	re->SetColor( setColor );
	while ( *s ) {
		if ( Q_IsColorString( s ) ) {
			if ( !forceColor ) {
				Com_Memcpy( color, g_color_table[ColorIndex(*(s+1))], sizeof( color ) );
				color[3] = setColor[3];
				re->SetColor( color );
			}
			if ( !noColorEscape ) {
				s += 2;
				continue;
			}
		}
		SCR_DrawChar( xx, y, size, *s );
		xx += size;
		s++;
	}
	re->SetColor( NULL );
}
void SCR_DrawStringExt2(float x, float y, float charWidth, float charHeight, const char *string, float *setColor, qboolean forceColor, qboolean noColorEscape) {
	vec4_t		color;
	const char	*s;
	float		xx;

	// draw the drop shadow
	color[0] = color[1] = color[2] = 0;
	color[3] = setColor[3];
	re->SetColor(color);
	s = string;
	xx = x;
	while (*s) {
		if (!noColorEscape && Q_IsColorString(s)) {
			s += 2;
			continue;
		}
		SCR_DrawChar2(xx + 2, y + 2, charWidth, charHeight, *s);
		xx += charWidth;
		s++;
	}


	// draw the colored text
	s = string;
	xx = x;
	re->SetColor(setColor);
	while (*s) {
		if (Q_IsColorString(s)) {
			if (!forceColor) {
				Com_Memcpy(color, g_color_table[ColorIndex(*(s + 1))], sizeof(color));
				color[3] = setColor[3];
				re->SetColor(color);
			}
			if (!noColorEscape) {
				s += 2;
				continue;
			}
		}
		SCR_DrawChar2(xx, y, charWidth, charHeight, *s);
		xx += charWidth;
		s++;
	}
	re->SetColor(NULL);
}

void SCR_DrawBigString( int x, int y, const char *s, float alpha, qboolean noColorEscape ) {
	float	color[4];

	color[0] = color[1] = color[2] = 1.0;
	color[3] = alpha;
	SCR_DrawStringExt( x, y, BIGCHAR_WIDTH, s, color, qfalse, noColorEscape );
}

void SCR_DrawBigStringColor( int x, int y, const char *s, vec4_t color, qboolean noColorEscape ) {
	SCR_DrawStringExt( x, y, BIGCHAR_WIDTH, s, color, qtrue, noColorEscape );
}


/*
==================
SCR_DrawSmallString[Color]

Draws a multi-colored string with a drop shadow, optionally forcing
to a fixed color.

Coordinates are at 640 by 480 virtual resolution
==================
*/
void SCR_DrawSmallStringExt( int x, int y, const char *string, float *setColor, qboolean forceColor, qboolean noColorEscape ) {
	vec4_t		color;
	const char	*s;
	int			xx;

	// draw the colored text
	s = string;
	xx = x;
	re->SetColor( setColor );
	while ( *s ) {
		if ( Q_IsColorString( s ) ) {
			if ( !forceColor ) {
				Com_Memcpy( color, g_color_table[ColorIndex(*(s+1))], sizeof( color ) );
				color[3] = setColor[3];
				re->SetColor( color );
			}
			if ( !noColorEscape ) {
				s += 2;
				continue;
			}
		}
		SCR_DrawSmallChar( xx, y, *s );
		xx += con.charWidth;
		s++;
	}
	re->SetColor( NULL );
}



/*
** SCR_Strlen -- skips color escape codes
*/
static int SCR_Strlen( const char *str ) {
	const char *s = str;
	int count = 0;

	while ( *s ) {
		if ( Q_IsColorString( s ) ) {
			s += 2;
		} else {
			count++;
			s++;
		}
	}

	return count;
}

/*
** SCR_GetBigStringWidth
*/
int	SCR_GetBigStringWidth( const char *str ) {
	return SCR_Strlen( str ) * BIGCHAR_WIDTH;
}


//===============================================================================

/*
=================
SCR_DrawDemoRecording
=================
*/

void SCR_DrawDemoRecording( void ) {
	char	string[1024];
	int		pos, xpos, ypos;

#ifndef TOURNAMENT_CLIENT
	if (com_renderfps->integer > 0) //Draw render FPS - Sad hack sortof
	{
		char	string2[32];
		Com_sprintf(string2, sizeof(string2), "%i", 1000 / cls.frametime);
		SCR_DrawStringExt2(SCREEN_WIDTH - 128 - strlen(string2), 2.0f, 8.0f*cls.widthRatioCoef, 8.0f, string2, g_color_table[7], qtrue, qfalse);
	}
#endif

	if ( !clc.demorecording ) {
		return;
	}
	if ( clc.spDemoRecording ) {
		return;
	}
	if (!cl_drawRecording->integer) {
		return;
	}
	pos = FS_FTell( clc.demofile );

	if (cl_drawRecording->integer == 1)
		Com_sprintf( string, sizeof(string), "RECORDING %s: %ik", clc.demoName, pos / 1024 );
	else if (cl_drawRecording->integer == 2)
		Com_sprintf( string, sizeof(string), "%s: %ik", clc.demoName, pos / 1024 );
	else if (cl_drawRecording->integer == 3)
		Com_sprintf( string, sizeof(string), "%s", clc.demoName );
	else if (cl_drawRecording->integer > 3)
		Com_sprintf( string, sizeof(string), "REC" );

	if (cl_drawRecording->integer > 4) {
		xpos = 5;
		ypos = 36;
	}
	else {
		xpos = SCREEN_WIDTH / 2.0f - strlen(string)*(8.0f / 2.0f)*cls.widthRatioCoef;
		ypos = 20.0f;
	}

	SCR_DrawStringExt2(xpos, ypos, 8.0f*cls.widthRatioCoef, 8.0f, string, g_color_table[7], qtrue, qfalse);
}



/*
===============================================================================

DEBUG GRAPH

===============================================================================
*/

typedef struct graphsamp_s {
	float	value;
	int		color;
} graphsamp_t;

static	int			current;
static	graphsamp_t	values[1024];

/*
==============
SCR_DebugGraph
==============
*/
void SCR_DebugGraph (float value, int color)
{
	values[current&1023].value = value;
	values[current&1023].color = color;
	current++;
}

/*
==============
SCR_DrawDebugGraph
==============
*/
void SCR_DrawDebugGraph (void)
{
	int		a, x, y, w, i, h;
	float	v;

	//
	// draw the graph
	//
	w = 640;
	x = 0;
	y = 480;
	re->SetColor( g_color_table[0] );
	re->DrawStretchPic(x, y - cl_graphheight->integer,
		w, cl_graphheight->integer, 0, 0, 0, 0, cls.whiteShader );
	re->SetColor( NULL );

	for (a=0 ; a<w ; a++)
	{
		i = (current-1-a+1024) & 1023;
		v = values[i].value;
		v = v * cl_graphscale->integer + cl_graphshift->integer;

		if (v < 0)
			v += cl_graphheight->integer * (1+(int)(-v / cl_graphheight->integer));
		h = (int)v % cl_graphheight->integer;
		re->DrawStretchPic( x+w-1-a, y - h, 1, h, 0, 0, 0, 0, cls.whiteShader );
	}
}

 //need 2 port all of this shit to cgame...
//=============================================================================
static int QDECL sortzones(const void *a, const void *b) {
	return *(float *)a - *(float *)b;
}
void SCR_UpdateHudSettings(float speed) {
	float		step;
	const char	*info;
	cl.snappinghud.speed = speed;
	//speed /= Cvar_VariableIntegerValue("com_maxfps");
	speed /= com_maxfps->integer;
	cl.snappinghud.count = 0;
	for (step = floor(speed + 0.5) - 0.5; step>0 && cl.snappinghud.count<SNAPHUD_MAXZONES - 2; step--) {
		cl.snappinghud.zones[cl.snappinghud.count] = RAD2DEG(acos(step / speed));
		cl.snappinghud.count++;
		cl.snappinghud.zones[cl.snappinghud.count] = RAD2DEG(asin(step / speed));
		cl.snappinghud.count++;
	}
	qsort(cl.snappinghud.zones, cl.snappinghud.count, sizeof(cl.snappinghud.zones[0]), sortzones);
	cl.snappinghud.zones[cl.snappinghud.count] = cl.snappinghud.zones[0] + 90;
	info = cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO];
	//cl.snappinghud.promode = atoi(Info_ValueForKey(info, "df_promode"));
}
/*
==============
SCR_DrawHud
==============
*/
void SCR_DrawHud(void)
{
	int i, y, h;
	//char *t;
	const char *t; //?
	vec2_t va;
	float mark;
	vec4_t	color[3];
	float speed;
	int colorid = 0;
	if (cl.snap.ps.pm_flags & PMF_FOLLOW || clc.demoplaying) {
		va[YAW] = cl.snap.ps.viewangles[YAW];
		va[PITCH] = -cl.snap.ps.viewangles[PITCH];
		cl.snappinghud.m[0] = (cl.snap.ps.stats[13] & 1) - (cl.snap.ps.stats[13] & 2);
		cl.snappinghud.m[1] = (cl.snap.ps.stats[13] & 8) - (cl.snap.ps.stats[13] & 16);
	}
	else if (cl.snap.ps.pm_type == 0) {
		va[YAW] = cl.viewangles[YAW] + SHORT2ANGLE(cl.snap.ps.delta_angles[YAW]);
		va[PITCH] = -(cl.viewangles[PITCH] + SHORT2ANGLE(cl.snap.ps.delta_angles[PITCH]));
	}
	else {
		return;
	}
	if (!Cvar_VariableIntegerValue("cg_draw2D")) {
		return;
	}
	t = scr_hud_pitch_rgba->string;
	color[2][0] = atof(COM_Parse(&t));
	color[2][1] = atof(COM_Parse(&t));
	color[2][2] = atof(COM_Parse(&t));
	color[2][3] = atof(COM_Parse(&t));
	/*color[2][0] = 0.8f;
	color[2][1] = 0.8f;
	color[2][2] = 0.8f;
	color[2][3] = 0.8f;*/
	t = scr_hud_pitch->string;
	mark = atof(COM_Parse(&t));
	while (mark) {
		SCR_MarkAnglePitch(mark, scr_hud_pitch_thickness->value, va[PITCH], scr_hud_pitch_x->value, scr_hud_pitch_width->value, color[2]);
		mark = atof(COM_Parse(&t));
	}

	speed = scr_hud_snap_speed->integer ? scr_hud_snap_speed->integer : cl.snap.ps.speed;
	if (speed != cl.snappinghud.speed)
		SCR_UpdateHudSettings(speed);

	y = scr_hud_snap_y->value;
	h = scr_hud_snap_h->value;
	switch (scr_hud_snap_auto->integer) {
	case 0:
		va[YAW] += scr_hud_snap_def->value;
		break;
	case 1:
		if (cl.snappinghud.promode || (cl.snappinghud.m[0] != 0 && cl.snappinghud.m[1] != 0)) {
			va[YAW] += 45;
		}
		else if (cl.snappinghud.m[0] == 0 && cl.snappinghud.m[1] == 0) {
			va[YAW] += scr_hud_snap_def->value;
		}
		break;
	case 2:
		if (cl.snappinghud.m[0] != 0 && cl.snappinghud.m[1] != 0) {
			va[YAW] += 45;
		}
		else if (cl.snappinghud.m[0] == 0 && cl.snappinghud.m[1] == 0) {
			va[YAW] += scr_hud_snap_def->value;
		}
		break;
	}
	t = scr_hud_snap_rgba2->string;
	color[1][0] = atof(COM_Parse(&t));
	color[1][1] = atof(COM_Parse(&t));
	color[1][2] = atof(COM_Parse(&t));
	color[1][3] = atof(COM_Parse(&t));
	/*color[1][0] = 0.05f;
	color[1][1] = 0.05f;
	color[1][2] = 0.05f;
	color[1][3] = 0.1f;*/
	t = scr_hud_snap_rgba1->string;
	color[0][0] = atof(COM_Parse(&t));
	color[0][1] = atof(COM_Parse(&t));
	color[0][2] = atof(COM_Parse(&t));
	color[0][3] = atof(COM_Parse(&t));
	/*color[0][0] = 0.02f;
	color[0][1] = 0.1f;
	color[0][2] = 0.02f;
	color[0][3] = 0.4f;*/
	for (i = 0; i<cl.snappinghud.count; i++) {
		SCR_FillAngleYaw(cl.snappinghud.zones[i], cl.snappinghud.zones[i + 1], va[YAW], y, h, color[colorid]);
		SCR_FillAngleYaw(cl.snappinghud.zones[i] + 90, cl.snappinghud.zones[i + 1] + 90, va[YAW], y, h, color[colorid]);
		colorid ^= 1;
	}
	//Com_Printf("drawing snaphud\n");
}

//=============================================================================

/*
==================
SCR_Init
==================
*/
void SCR_Init( void ) {
	cl_timegraph = Cvar_Get ("timegraph", "0", CVAR_CHEAT);
	cl_debuggraph = Cvar_Get ("debuggraph", "0", CVAR_CHEAT);
	cl_graphheight = Cvar_Get ("graphheight", "32", CVAR_CHEAT);
	cl_graphscale = Cvar_Get ("graphscale", "1", CVAR_CHEAT);
	cl_graphshift = Cvar_Get ("graphshift", "0", CVAR_CHEAT);

	//snaphud stuff
	scr_hud_snap_draw = Cvar_Get("scr_hud_snap_draw", "0", CVAR_ARCHIVE);
	scr_hud_snap_rgba1 = Cvar_Get("scr_hud_snap_rgba1", ".02 .1 .02 .4", CVAR_ARCHIVE);
	scr_hud_snap_rgba2 = Cvar_Get("scr_hud_snap_rgba2", ".05 .05 .05 .1", CVAR_ARCHIVE);
	scr_hud_snap_y = Cvar_Get("scr_hud_snap_y", "248", CVAR_ARCHIVE);
	scr_hud_snap_h = Cvar_Get("scr_hud_snap_h", "8", CVAR_ARCHIVE);
	scr_hud_snap_auto = Cvar_Get("scr_hud_snap_auto", "1", CVAR_ARCHIVE);
	scr_hud_snap_def = Cvar_Get("scr_hud_snap_def", "45", CVAR_ARCHIVE);
	scr_hud_snap_speed = Cvar_Get("scr_hud_snap_speed", "0", CVAR_ARCHIVE);
	scr_hud_pitch = Cvar_Get("scr_hud_pitch", "", CVAR_ARCHIVE);
	scr_hud_pitch_thickness = Cvar_Get("scr_hud_pitch_thickness", "2", CVAR_ARCHIVE);
	scr_hud_pitch_x = Cvar_Get("scr_hud_pitch_x", "320", CVAR_ARCHIVE);
	scr_hud_pitch_width = Cvar_Get("scr_hud_pitch_width", "10", CVAR_ARCHIVE);
	scr_hud_pitch_rgba = Cvar_Get("scr_hud_pitch_rgba", ".8 .8 .8 .8", CVAR_ARCHIVE);

	scr_initialized = qtrue;
}


//=======================================================

/*
==================
SCR_DrawScreenField

This will be called twice if rendering in stereo mode
==================
*/
void SCR_DrawScreenField( stereoFrame_t stereoFrame ) {
	re->BeginFrame( stereoFrame );

	qboolean uiFullscreen = (qboolean)(cls.uiStarted && UIVM_IsFullscreen());

	if ( !cls.uiStarted ) {
		Com_DPrintf("draw screen without UI loaded\n");
		return;
	}

	// if the menu is going to cover the entire screen, we
	// don't need to render anything under it
	//actually, yes you do, unless you want clients to cycle out their reliable
	//commands from sitting in the menu. -rww
	if ( (cls.uiStarted && !uiFullscreen) || (!(cls.framecount&7) && cls.state == CA_ACTIVE) ) {
		switch( cls.state ) {
		default:
			Com_Error( ERR_FATAL, "SCR_DrawScreenField: bad cls.state" );
			break;
		case CA_CINEMATIC:
			SCR_DrawCinematic();
			break;
		case CA_DISCONNECTED:
			// force menu up
			S_StopAllSounds();
			UIVM_SetActiveMenu( UIMENU_MAIN );
			break;
		case CA_CONNECTING:
		case CA_CHALLENGING:
		case CA_CONNECTED:
			// connecting clients will only show the connection dialog
			// refresh to update the time
			UIVM_Refresh( cls.realtime );
			UIVM_DrawConnectScreen( qfalse );
			break;
		case CA_LOADING:
		case CA_PRIMED:
			// draw the game information screen and loading progress
			CL_CGameRendering( stereoFrame );

			// also draw the connection information, so it doesn't
			// flash away too briefly on local or lan games
			// refresh to update the time
			UIVM_Refresh( cls.realtime );
			UIVM_DrawConnectScreen( qtrue );
			break;
		case CA_ACTIVE:
			CL_CGameRendering( stereoFrame );
			SCR_DrawDemoRecording();
			if (scr_hud_snap_draw->integer)
				SCR_DrawHud();
			break;
		}
	}

	// the menu draws next
	if ( cls.uiStarted && (Key_GetCatcher( ) & KEYCATCH_UI) ) {
		UIVM_Refresh( cls.realtime );
	}

	// console draws next
	Con_DrawConsole ();

	// debug graph can be drawn on top of anything
	if ( cl_debuggraph->integer || cl_timegraph->integer || cl_debugMove->integer ) {
		SCR_DrawDebugGraph ();
	}
}

/*
==================
SCR_UpdateScreen

This is called every frame, and can also be called explicitly to flush
text to the screen.
==================
*/
void SCR_UpdateScreen( void ) {
	static int	recursive;

	if ( !scr_initialized ) {
		return;				// not initialized yet
	}

	if ( ++recursive > 2 ) {
		Com_Error( ERR_FATAL, "SCR_UpdateScreen: recursively called" );
	}
	recursive = 1;

	// If there is no VM, there are also no rendering commands issued. Stop the renderer in
	// that case.
	if( cls.uiStarted || com_dedicated->integer )
	{
		// if running in stereo, we need to draw the frame twice
		if ( cls.glconfig.stereoEnabled ) {
			SCR_DrawScreenField( STEREO_LEFT );
			SCR_DrawScreenField( STEREO_RIGHT );
		} else {
			SCR_DrawScreenField( STEREO_CENTER );
		}

		if ( com_speeds->integer ) {
			re->EndFrame( &time_frontend, &time_backend );
		} else {
			re->EndFrame( NULL, NULL );
		}
	}

	recursive = 0;
}

extern void IN_Frame(void);
void SCR_UpdateScreenAndInput(void) {
	if (!com_dedicated->integer && (cls.state >= CA_CONNECTED && cls.state <= CA_ACTIVE)) {
		IN_Frame();
	}
	SCR_UpdateScreen();
}
