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

// cg_scoreboard -- draw the scoreboard on top of the game screen
#include "cg_local.h"
#include "ui/ui_shared.h"
#include "game/bg_saga.h"

#define	SCOREBOARD_X		(0)

#if NEW_SCOREBOARD
#define SB_HEADER			86
#define SB_TOP				(SB_HEADER+32)

// Where the status bar starts, so we don't overwrite it
#define SB_STATUSBAR		(cg_newScoreBoard.integer ? (SCREEN_HEIGHT - 45) : (SCREEN_HEIGHT - 60))

#define SB_NORMAL_HEIGHT	25
#define SB_INTER_HEIGHT		15 // interleaved height
//#define SB_INTER_HEIGHT		(cg_newScoreBoard.integer ? 16 : 15) // grr this would be better but i don't want to redo my hacky solution to getting lines between each listing
#define SB_INTER_HEIGHT_NEW 16

#define SB_MAXCLIENTS_NORMAL  ((SB_STATUSBAR - SB_TOP) / SB_NORMAL_HEIGHT)
#define SB_MAXCLIENTS_INTER   (cg_newScoreBoard.integer ? ((SB_STATUSBAR - SB_TOP) / SB_INTER_HEIGHT - 2) : ((SB_STATUSBAR - SB_TOP) / SB_INTER_HEIGHT - 1)) // Used when interleaved
#else
#define SB_HEADER			86
#define SB_TOP				(SB_HEADER+32)

// Where the status bar starts, so we don't overwrite it
#define SB_STATUSBAR		420

#define SB_NORMAL_HEIGHT	25
#define SB_INTER_HEIGHT		15 // interleaved height

#define SB_MAXCLIENTS_NORMAL  ((SB_STATUSBAR - SB_TOP) / SB_NORMAL_HEIGHT)
#define SB_MAXCLIENTS_INTER   ((SB_STATUSBAR - SB_TOP) / SB_INTER_HEIGHT - 1)

// Used when interleaved
#endif


#define SB_LEFT_BOTICON_X	(SCOREBOARD_X+0)
#define SB_LEFT_HEAD_X		(SCOREBOARD_X+32)
#define SB_RIGHT_BOTICON_X	(SCOREBOARD_X+64)
#define SB_RIGHT_HEAD_X		(SCOREBOARD_X+96)
// Normal
#define SB_BOTICON_X		(SCOREBOARD_X+32)
#define SB_HEAD_X			(SCOREBOARD_X+64)

#define SB_SCORELINE_X		100
#define SB_SCORELINE_WIDTH	(SCREEN_WIDTH - SB_SCORELINE_X * 2)

#define SB_RATING_WIDTH	    0 // (6 * BIGCHAR_WIDTH)
#define SB_NAME_X			(SB_SCORELINE_X)
#define SB_SCORE_X			(SB_SCORELINE_X + .55 * SB_SCORELINE_WIDTH)
#define SB_PING_X			(SB_SCORELINE_X + .70 * SB_SCORELINE_WIDTH)
#define SB_TIME_X			(SB_SCORELINE_X + .85 * SB_SCORELINE_WIDTH)

// The new and improved score board
//
// In cases where the number of clients is high, the score board heads are interleaved
// here's the layout

//
//	0   32   80  112  144   240  320  400   <-- pixel position
//  bot head bot head score ping time name
//
//  wins/losses are drawn on bot icon now

static qboolean localClient; // true if local client has been displayed


							 /*
=================
CG_DrawScoreboard
=================
*/
static void CG_DrawClientScore( int y, score_t *score, float *color, float fade, qboolean largeFormat )
{
	//vec3_t	headAngles;
	clientInfo_t	*ci;
	int				iconx = SB_BOTICON_X + (SB_RATING_WIDTH / 2);
	float			scale = (largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF)) ? 1.0f : 0.75f,
					iconSize = (largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF)) ? SB_NORMAL_HEIGHT : SB_INTER_HEIGHT;

	if ( score->client < 0 || score->client >= cgs.maxclients ) {
		Com_Printf( "Bad score->client: %i\n", score->client );
		return;
	}

	ci = &cgs.clientinfo[score->client];

	// draw the handicap or bot skill marker (unless player has flag)
	if ( ci->powerups & (1<<PW_NEUTRALFLAG) )
	{
		if ( largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF))//JAPRO - Clientside - Small Scoreboard
			CG_DrawFlagModel( iconx, y - (32 - BIGCHAR_HEIGHT) / 2, iconSize, iconSize, TEAM_FREE, qfalse );
		else
			CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_FREE, qfalse );
	}

	else if ( ci->powerups & ( 1 << PW_REDFLAG ) )
		CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_RED, qfalse );

	else if ( ci->powerups & ( 1 << PW_BLUEFLAG ) )
		CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_BLUE, qfalse );

	else if ( cgs.gametype == GT_POWERDUEL && (ci->duelTeam == DUELTEAM_LONE || ci->duelTeam == DUELTEAM_DOUBLE) )
	{
		CG_DrawPic( iconx, y, iconSize, iconSize, trap->R_RegisterShaderNoMip(
			(ci->duelTeam == DUELTEAM_LONE) ? "gfx/mp/pduel_icon_lone" : "gfx/mp/pduel_icon_double" ) );
	}

	else if (cgs.gametype == GT_SIEGE)
	{ //try to draw the shader for this class on the scoreboard
		if (ci->siegeIndex != -1)
		{
			siegeClass_t *scl = &bgSiegeClasses[ci->siegeIndex];

			if (scl->classShader)
			{
				CG_DrawPic (iconx, y, (((largeFormat && !cg_smallScoreboard.integer && cgs.gametype != GT_CTF))?24:12), ((largeFormat && !cg_smallScoreboard.integer)?24:12), scl->classShader);//JAPRO - Clientside - Small Scoreboard.
			}
		}
	}

	// highlight your position
	if ( score->client == cg.snap->ps.clientNum )
	{
		float	hcolor[4];
		int		rank;

		localClient = qtrue;

		if ( cg.snap->ps.persistant[PERS_TEAM] == TEAM_SPECTATOR
			|| cgs.gametype >= GT_TEAM ) {
			rank = -1;
		} else {
			rank = cg.snap->ps.persistant[PERS_RANK] & ~RANK_TIED_FLAG;
		}
		if ( rank == 0 ) {
			hcolor[0] = 0;
			hcolor[1] = 0;
			hcolor[2] = 0.7f;
		} else if ( rank == 1 ) {
			hcolor[0] = 0.7f;
			hcolor[1] = 0;
			hcolor[2] = 0;
		} else if ( rank == 2 ) {
			hcolor[0] = 0.7f;
			hcolor[1] = 0.7f;
			hcolor[2] = 0;
		} else {
			hcolor[0] = 0.7f;
			hcolor[1] = 0.7f;
			hcolor[2] = 0.7f;
		}

		hcolor[3] = fade * 0.7;
		CG_FillRect( SB_SCORELINE_X - 5, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, (largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF))?SB_NORMAL_HEIGHT:SB_INTER_HEIGHT, hcolor );//JAPRO - Clientside - Small Scoreboard
	}

	if (!cg_drawScoreboardIcons.integer) {
	CG_Text_Paint (SB_NAME_X, y, 0.9f * scale, colorWhite, ci->name,0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else {
		if (largeFormat) {
			if (ci->modelIcon) CG_DrawPic(SB_NAME_X-5, y+2, 25*cgs.widthRatioCoef, 25, ci->modelIcon);
			CG_Text_Paint(SB_NAME_X+24*cgs.widthRatioCoef, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
		}
		else {
			if (ci->modelIcon) CG_DrawPic(SB_NAME_X-5, y+2, 15*cgs.widthRatioCoef, 15, ci->modelIcon);
			CG_Text_Paint(SB_NAME_X+12*cgs.widthRatioCoef, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
		}
	}
	//CG_Text_Paint (SB_NAME_X, y, 0.9f * scale, colorWhite, ci->name,0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );

	if ( score->ping != -1 )
	{
		if ( ci->team != TEAM_SPECTATOR || cgs.gametype == GT_DUEL || cgs.gametype == GT_POWERDUEL )
		{
			if ((cgs.gametype == GT_DUEL && cgs.fraglimit > 0) || cgs.gametype == GT_POWERDUEL)
			{
				CG_Text_Paint (SB_SCORE_X, y, 1.0f * scale, colorWhite, va("%i/%i", ci->wins, ci->losses),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL );
			}
			else if (cgs.gametype == GT_CTF)
			{
				CG_Text_Paint(SB_SCORELINE_X + 0.47f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->score),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
				CG_Text_Paint(SB_SCORELINE_X + 0.59f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->captures),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
				CG_Text_Paint(SB_SCORELINE_X + 0.66f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->assistCount),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
				CG_Text_Paint(SB_SCORELINE_X + 0.73f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->defendCount),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);//loda
			}
			else
			{
//JAPRO - Clientside - Scoreboard Deaths - Start
				if ((cg_scoreDeaths.integer == 2 && (cgs.serverMod < SVMOD_JAPLUS || !cgs.pluginSet)) || cg_scoreDeaths.integer == 3) //3 shows local count always (debugging)
					score->deaths = ci->deaths;
				if (cg_scoreDeaths.integer && (cg_scoreDeaths.integer == 2 || (cgs.serverMod >= SVMOD_JAPLUS && cgs.pluginSet) || cg_scoreDeaths.integer == 3) && (cgs.gametype != GT_CTF && cgs.gametype != GT_DUEL))
					CG_Text_Paint(SB_SCORE_X, y, 1.0f * scale, colorWhite, va("%i/%i", score->score, score->deaths), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
				else
					CG_Text_Paint(SB_SCORE_X, y, 1.0f * scale, colorWhite, va("%i", score->score), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
//JAPRO - Clientside - Scoreboard Deaths - End
			}
		}
		
		if (cgs.gametype == GT_CTF)
		{
			if (ci->botSkill != -1)
				CG_Text_Paint(SB_SCORELINE_X + 0.80 * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "BOT", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
			else
				CG_Text_Paint(SB_SCORELINE_X + 0.80 * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->ping),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);	
			CG_Text_Paint(SB_SCORELINE_X + 0.90 * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, va("%i", score->time),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		}
		else
		{
			if ( ci->botSkill != -1 )
				CG_Text_Paint(SB_PING_X, y, 1.0f * scale, colorWhite, "BOT", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
			else
				CG_Text_Paint(SB_PING_X, y, 1.0f * scale, colorWhite, va("%i", score->ping),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);

			CG_Text_Paint(SB_TIME_X, y, 1.0f * scale, colorWhite, va("%i", score->time),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		}
	}
	else if (cgs.gametype == GT_CTF)
	{
		CG_Text_Paint (SB_SCORELINE_X + 0.47f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //score
		CG_Text_Paint (SB_SCORELINE_X + 0.59f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //caps
		CG_Text_Paint (SB_SCORELINE_X + 0.66f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //assists
		CG_Text_Paint (SB_SCORELINE_X + 0.73f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //defends
		CG_Text_Paint (SB_SCORELINE_X + 0.80f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //ping
		CG_Text_Paint(SB_SCORELINE_X + 0.90f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //time
	}
	else
	{
		CG_Text_Paint(SB_SCORE_X, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		CG_Text_Paint(SB_PING_X, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		CG_Text_Paint(SB_TIME_X, y, 1.0f * scale, colorWhite, "-",0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
	}

	// add the "ready" marker for intermission exiting
	if ( cg.snap->ps.stats[ STAT_CLIENTS_READY ] & ( 1 << score->client ) )
	{
		CG_Text_Paint (SB_NAME_X - 64, y + 2, 0.7f * scale, colorWhite, CG_GetStringEdString("MP_INGAME", "READY"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
}

#if NEW_SCOREBOARD
static void CG_DrawClientScore2( int y, score_t *score, float *color, float fade, qboolean largeFormat, qboolean lastClient )
{
	//vec3_t	headAngles;
	clientInfo_t	*ci;
	int				iconx = SB_BOTICON_X + (SB_RATING_WIDTH / 2);
	float			scale = /*(largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF)) ? 1.0f :*/ 0.75f,
					iconSize = SB_INTER_HEIGHT_NEW;
	qhandle_t		iconShader = 0;
					//iconSize = (largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF)) ? SB_NORMAL_HEIGHT : SB_INTER_HEIGHT_NEW;
	//float			*pingColor = colorTable[CT_WHITE];
	//vec4_t			pingColor;
	//vec4_t			pingColor = { 1.0f, 1.0f, 1.0f, 1.0f };
	vec4_t			pingColor = { 1.0f, 1.0f, 1.0f, fade };
	vec4_t			greyColor = { 0.42f, 0.42f, 0.42f, fade * 0.42f }; //color used for backdrop

	if ( score->client < 0 || score->client >= cgs.maxclients ) {
		Com_Printf( "Bad score->client: %i\n", score->client );
		return;
	}

	ci = &cgs.clientinfo[score->client];

	// draw the handicap or bot skill marker (unless player has flag)
	if ( ci->powerups & (1<<PW_NEUTRALFLAG) )
	{
		/*if ( largeFormat && (!cg_smallScoreboard.integer && cgs.gametype != GT_CTF))//JAPRO - Clientside - Small Scoreboard.
			CG_DrawFlagModel( iconx, y - (32 - BIGCHAR_HEIGHT) / 2, iconSize, iconSize, TEAM_FREE, qfalse );
		else*/
			CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_FREE, qfalse );
	}

	else if ( ci->powerups & ( 1 << PW_REDFLAG ) )
		CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_RED, qfalse );

	else if ( ci->powerups & ( 1 << PW_BLUEFLAG ) )
		CG_DrawFlagModel( iconx, y, iconSize, iconSize, TEAM_BLUE, qfalse );

	else if ( cgs.gametype == GT_POWERDUEL && (ci->duelTeam == DUELTEAM_LONE || ci->duelTeam == DUELTEAM_DOUBLE) )
	{
		CG_DrawPic( iconx, y, iconSize, iconSize, trap->R_RegisterShaderNoMip(
			(ci->duelTeam == DUELTEAM_LONE) ? "gfx/mp/pduel_icon_lone" : "gfx/mp/pduel_icon_double" ) );
	}

	else if (cgs.gametype == GT_SIEGE)
	{ //try to draw the shader for this class on the scoreboard
		if (ci->siegeIndex != -1)
		{
			siegeClass_t *scl = &bgSiegeClasses[ci->siegeIndex];

			if (scl->classShader)
			{
				CG_DrawPic(iconx, y, 12, 12, scl->classShader);
				//CG_DrawPic (iconx, y, (((largeFormat && !cg_smallScoreboard.integer && cgs.gametype != GT_CTF))?24:12), ((largeFormat && !cg_smallScoreboard.integer)?24:12), scl->classShader);//JAPRO - Clientside - Small Scoreboard
			}
		}
	}

	iconx = SB_SCORELINE_X - 5;
	//iconShader = (score->ping >= 999 ? trap->R_RegisterShaderNoMip("gfx/2d/net.tga") : ci->modelIcon);
	iconShader = ci->modelIcon;

	// highlight your position
	if ( score->client == cg.snap->ps.clientNum )
	{
		vec4_t	hcolor;
		int		rank;

		localClient = qtrue;

		if ( cg.snap->ps.persistant[PERS_TEAM] == TEAM_SPECTATOR
			|| cgs.gametype >= GT_TEAM ) {
			rank = -1;
		} else {
			rank = cg.snap->ps.persistant[PERS_RANK] & ~RANK_TIED_FLAG;
		}
		if ( rank == 0 ) {
			hcolor[0] = 0;
			hcolor[1] = 0;
			hcolor[2] = 0.5f;
		} else if ( rank == 1 ) {
			hcolor[0] = 0.5f;
			hcolor[1] = 0;
			hcolor[2] = 0;
		} else if ( rank == 2 ) {
			hcolor[0] = 0.5f;
			hcolor[1] = 0.5f;
			hcolor[2] = 0;
		} else {
			hcolor[0] = 0.5f;
			hcolor[1] = 0.5f;
			hcolor[2] = 0;
		}
		/*if ( rank == 0 ) {
			hcolor[0] = 0;
			hcolor[1] = 0;
			hcolor[2] = 0.7f;
		} else if ( rank == 1 ) {
			hcolor[0] = 0.7f;
			hcolor[1] = 0;
			hcolor[2] = 0;
		} else if ( rank == 2 ) {
			hcolor[0] = 0.7f;
			hcolor[1] = 0.7f;
			hcolor[2] = 0;
		} else {
			hcolor[0] = 0.7f;
			hcolor[1] = 0.7f;
			hcolor[2] = 0.7f;
		} */

		//hcolor[3] = fade * 0.7;
		hcolor[3] = fade * 0.5f;
		//CG_FillRect( SB_SCORELINE_X - 5, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW, hcolor );
		if (!lastClient) {
			trap->R_SetColor( greyColor );
			trap->R_DrawStretchPic( iconx, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, 2, 0, 0, 0, 0, cgs.media.whiteShader );
			trap->R_DrawStretchPic( iconx, y + 1 + SB_INTER_HEIGHT_NEW, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, 1, 0, 0, 0, 0, cgs.media.whiteShader );
			trap->R_SetColor( hcolor );
			trap->R_DrawStretchPic( iconx, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW+1, 0, 0, 0, 0, cgs.media.whiteShader );
			trap->R_SetColor( NULL );
		}
		else {
			CG_FillRect(iconx, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW, hcolor);
		}
	}
	else// if (cg_newScoreBoard.integer)
	{//grey background - TODO: refactor this so the divider lines are drawn separately
		//CG_FillRect( SB_SCORELINE_X - 5, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW+1, hcolor );
		if (!lastClient)
			CG_FillRect( iconx, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW+1, greyColor );
		else
			CG_FillRect( iconx, y + 2, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, SB_INTER_HEIGHT_NEW, greyColor );
	}

#if 0
	if (!cg_drawScoreboardIcons.integer && !cg_newScoreBoard.integer) {
		CG_Text_Paint(SB_NAME_X, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
	}
	else {
		if (largeFormat) {
			if (ci->modelIcon) CG_DrawPic(SB_NAME_X-5, y+2, 25*cgs.widthRatioCoef, 25, ci->modelIcon);
			CG_Text_Paint(SB_NAME_X+24*cgs.widthRatioCoef, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
		}
		else {
			if (ci->modelIcon) CG_DrawPic(SB_NAME_X-5, y+2, 15*cgs.widthRatioCoef, 15, ci->modelIcon);
			CG_Text_Paint(SB_NAME_X+12*cgs.widthRatioCoef, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
		}
	}
#else
	CG_FillRect(SB_NAME_X-(7*cgs.widthRatioCoef), y+2, SB_INTER_HEIGHT_NEW*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW, colorTable[CT_BLACK]);
	//if (ci->modelIcon) CG_DrawPic(SB_NAME_X-(6*cgs.widthRatioCoef), y+3, (SB_INTER_HEIGHT_NEW-2)*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW-2, ci->modelIcon);
	if (!iconShader)
	{
		switch (ci->team)
		{
			default:
				iconShader = trap->R_RegisterShaderNoMip("icons/icon_default_rgb.jpg");
				break;
			case TEAM_FREE:
			case TEAM_SPECTATOR:
				iconShader = trap->R_RegisterShaderNoMip("icons/icon_default_unknown.jpg");
				break;
			case TEAM_RED:
				iconShader = trap->R_RegisterShaderNoMip("icons/icon_red_unknown.jpg");
				break;
			case TEAM_BLUE:
				iconShader = trap->R_RegisterShaderNoMip("icons/icon_blue_unknown.jpg");
				break;
		}
	}
	//if (iconShader) CG_DrawPic(SB_NAME_X-(6*cgs.widthRatioCoef), y+3, (SB_INTER_HEIGHT_NEW-2)*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW-2, iconShader);
	if (iconShader) {
		CG_DrawPic(SB_NAME_X-(6*cgs.widthRatioCoef), y+3, (SB_INTER_HEIGHT_NEW-2)*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW-2, iconShader);
	}

	if (score->ping >= 999) {
		CG_FillRect(SB_NAME_X-(SB_INTER_HEIGHT_NEW*cgs.widthRatioCoef)-(7*cgs.widthRatioCoef), y+2, SB_INTER_HEIGHT_NEW*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW, colorTable[CT_BLACK]);
		CG_DrawPic(SB_NAME_X-(SB_INTER_HEIGHT_NEW*cgs.widthRatioCoef)-(6*cgs.widthRatioCoef), y+3, (SB_INTER_HEIGHT_NEW-2)*cgs.widthRatioCoef, SB_INTER_HEIGHT_NEW-2, trap->R_RegisterShaderNoMip("gfx/2d/net.tga"));
	}

	CG_Text_Paint(SB_NAME_X+(12*cgs.widthRatioCoef), y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
#endif
	//CG_Text_Paint (SB_NAME_X, y, 0.9f * scale, colorWhite, ci->name,0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );

	if (score->ping != -1)
	{
		if (ci->botSkill == -1 && score->ping > 0) {
			//fpsColour = { 1.0f, 1.0f, 1.0f, 1.0f }, fpsGood = { 0.0f, 1.0f, 0.0f, 1.0f }, fpsBad = { 1.0f, 0.0f, 0.0f, 1.0f };
			//CG_LerpColour( &fpsBad, &fpsGood, &fpsColour,
				//std::min( std::max( 0.0f, static_cast<float>( fps ) ) / std::max( IDEAL_FPS, static_cast<float>( maxFPS ) ), 1.0f ) );

			//vec4_t pingGood = { 0.0f, 1.0f, 0.0f, 1.0f }, pingBad = { 1.0f, 0.0f, 0.0f, 1.0f };
			vec4_t pingGood = { 0.0f, 1.0f, 0.2f, 1.0f }, pingBad = { 1.0f, 0.0f, 0.0f, 1.0f };
			float point = Q_min((48.0f / Q_max(48.0f, (float)score->ping)), 1.0f);

			CG_LerpColour(pingBad, pingGood, pingColor, point);
			pingColor[3] = fade;
			//Com_Printf("%i %f %f %f %f\n", score->ping, pingColor[0], pingColor[1], pingColor[2], pingColor[3]);
		}
		else {
			//VectorCopy4(colorTable[CT_WHITE], pingColor);
		}
		if ( ci->team != TEAM_SPECTATOR || cgs.gametype == GT_DUEL || cgs.gametype == GT_POWERDUEL )
		{
			if ((cgs.gametype == GT_DUEL && cgs.fraglimit > 0) || cgs.gametype == GT_POWERDUEL)
			{
				CG_Text_Paint(SB_SCORE_X, y + 1, 1.25f * scale, colorWhite, va("%i/%i", ci->wins, ci->losses),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
			}
			else if (cgs.gametype == GT_CTF)
			{
				CG_Text_Paint(SB_SCORELINE_X + 0.47f * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, va("%i", score->score),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
				CG_Text_Paint(SB_SCORELINE_X + 0.59f * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, va("%i", score->captures),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
				CG_Text_Paint(SB_SCORELINE_X + 0.66f * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, va("%i", score->assistCount),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
				CG_Text_Paint(SB_SCORELINE_X + 0.73f * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, va("%i", score->defendCount),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);//loda
			}
			else
			{
//JAPRO - Clientside - Scoreboard Deaths - Start
				if ((cg_scoreDeaths.integer == 2 && (cgs.serverMod < SVMOD_JAPLUS || !cgs.pluginSet)) || cg_scoreDeaths.integer == 3) //3 shows local count always (debugging)
					score->deaths = ci->deaths;
				if (cg_scoreDeaths.integer && (cg_scoreDeaths.integer == 2 || (cgs.serverMod >= SVMOD_JAPLUS && cgs.pluginSet) || cg_scoreDeaths.integer == 3) && (cgs.gametype != GT_CTF && cgs.gametype != GT_DUEL))
					CG_Text_Paint(SB_SCORE_X, y + 2, 1.25f * scale, colorWhite, va("%i/%i", score->score, score->deaths), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
				else
					CG_Text_Paint(SB_SCORE_X, y + 2, 1.25f * scale, colorWhite, va("%i", score->score), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
//JAPRO - Clientside - Scoreboard Deaths - End
			}
		}

		if (cgs.gametype == GT_CTF)
		{
			if (ci->botSkill != -1)
				CG_Text_Paint(SB_SCORELINE_X + 0.80 * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, "BOT", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
			else
				CG_Text_Paint(SB_SCORELINE_X + 0.80 * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, pingColor, va("%i", score->ping), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
			CG_Text_Paint(SB_SCORELINE_X + 0.90 * SB_SCORELINE_WIDTH, y + 2, 1.25f * scale, colorWhite, va("%i", score->time), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
		}
		else
		{
			if ( ci->botSkill != -1 )
				CG_Text_Paint(SB_PING_X, y + 2, 1.25f * scale, colorWhite, "BOT", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
			else
				CG_Text_Paint(SB_PING_X, y + 2, 1.25f * scale, pingColor, va("%i", score->ping), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);

			CG_Text_Paint(SB_TIME_X, y + 2, 1.25f * scale, colorWhite, va("%i", score->time), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL2);
		}
	}

	else if (cgs.gametype == GT_CTF)
	{
		CG_Text_Paint (SB_SCORELINE_X + 0.47f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //score
		CG_Text_Paint (SB_SCORELINE_X + 0.59f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //caps
		CG_Text_Paint (SB_SCORELINE_X + 0.66f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //assists
		CG_Text_Paint (SB_SCORELINE_X + 0.73f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //defends
		CG_Text_Paint (SB_SCORELINE_X + 0.80f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //ping
		CG_Text_Paint(SB_SCORELINE_X + 0.90f * SB_SCORELINE_WIDTH, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL); //time
	}
	else
	{
		CG_Text_Paint(SB_SCORE_X, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		CG_Text_Paint(SB_PING_X, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
		CG_Text_Paint(SB_TIME_X, y, 1.0f * scale, colorWhite, "-", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
}

	// add the "ready" marker for intermission exiting
	if ( cg.snap->ps.stats[ STAT_CLIENTS_READY ] & ( 1 << score->client ) )
	{
		CG_Text_Paint (SB_NAME_X - 64, y + 2, 0.7f * scale, colorWhite, CG_GetStringEdString("MP_INGAME", "READY"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
}
#endif

/*
=================
CG_TeamScoreboard
=================
*/
#if !NEW_SCOREBOARD
static int CG_TeamScoreboard( int y, team_t team, float fade, int maxClients, int lineHeight, qboolean countOnly )
{
	int		i;
	score_t	*score;
	float	color[4];
	int		count;
	clientInfo_t	*ci;

	color[0] = color[1] = color[2] = 1.0;
	color[3] = fade;

	count = 0;
	for ( i = 0 ; i < cg.numScores && count < maxClients ; i++ ) {
		score = &cg.scores[i];
		ci = &cgs.clientinfo[ score->client ];

		if ( team != ci->team ) {
			continue;
		}

		if ( !countOnly )
		{
			CG_DrawClientScore( y + lineHeight * count, score, color, fade, lineHeight == SB_NORMAL_HEIGHT );
		}

		count++;
	}

	return count;
}
#endif

int	CG_GetClassCount(team_t team,int siegeClass )
{
	int i = 0;
	int count = 0;
	clientInfo_t	*ci;
	siegeClass_t *scl;

	for ( i = 0 ; i < cgs.maxclients ; i++ )
	{
		ci = &cgs.clientinfo[ i ];

		if ((!ci->infoValid) || ( team != ci->team ))
		{
			continue;
		}

		scl = &bgSiegeClasses[ci->siegeIndex];

		// Correct class?
		if ( siegeClass != scl->classShader )
		{
			continue;
		}

		count++;
	}

 	return count;

}

int CG_GetTeamNonScoreCount(team_t team)
{
	int i = 0,count=0;
	clientInfo_t	*ci;

	for ( i = 0 ; i < cgs.maxclients ; i++ )
	{
		ci = &cgs.clientinfo[ i ];

		if ( (!ci->infoValid) || (team != ci->team && team != ci->siegeDesiredTeam) )
		{
			continue;
		}

		count++;
	}

 	return count;
}

int CG_GetTeamCount(team_t team, int maxClients)
{
	int i = 0;
	int count = 0;
	clientInfo_t	*ci;
	score_t	*score;

	for ( i = 0 ; i < cg.numScores && count < maxClients ; i++ )
	{
		score = &cg.scores[i];
		ci = &cgs.clientinfo[ score->client ];

		if ( team != ci->team )
		{
			continue;
		}

		count++;
	}

	return count;
}

int CG_GetTeamCountFromClientInfo(team_t team)
{
	int i = 0;
	int count = 0;
	clientInfo_t *ci = NULL;

	for ( i = 0 ; i < cgs.maxclients ; i++ )
	{
		ci = &cgs.clientinfo[i];

		if (!ci || !ci->infoValid)
			continue;

		if (team != ci->team)
			continue;

		count++;
	}

	return count;
}

#if NEW_SCOREBOARD
static QINLINE int CG_TeamScoreboard( int y, team_t team, float fade, int maxClients, int lineHeight, qboolean countOnly )
{
	int				i;
	score_t			*score;
	vec4_t			color;
	//vec4_t			greyColor = { 0.42f, 0.42f, 0.42f, fade * 0.42f };
	int				count = 0, teamTotal;
	clientInfo_t	*ci;
	qboolean		lastClient;

	if (cg_newScoreBoard.integer) {
		teamTotal = CG_GetTeamCount(team, maxClients);
	}

	color[0] = color[1] = color[2] = 1.0f;
	color[3] = fade;

	for ( i = 0 ; i < cg.numScores && count < maxClients ; i++ ) {
		score = &cg.scores[i];
		ci = &cgs.clientinfo[ score->client ];

		if ( team != ci->team ) {
			continue;
		}


		if ( !countOnly )
		{
			if (!cg_newScoreBoard.integer) {
				CG_DrawClientScore( y + lineHeight * count, score, color, fade, lineHeight == SB_NORMAL_HEIGHT );
			}
			else {
				lastClient = (qboolean)(count+1 == teamTotal);
				/*if (lastClient && teamTotal > 1)
					CG_FillRect(SB_SCORELINE_X - 5, y + 1 + SB_INTER_HEIGHT_NEW, SCREEN_WIDTH - SB_SCORELINE_X * 2 + 10, 2, greyColor);*/
				CG_DrawClientScore2( y + lineHeight * count, score, color, fade, qfalse, lastClient);
			}
		}

		count++;
	}

	return count;
}
#endif

/*
=================
CG_DrawScoreboard

Draw the normal in-game scoreboard
=================
*/
int cg_siegeWinTeam = 0;
qboolean CG_DrawOldScoreboard( void ) {
	int		x, y, i, n1, n2;
	float	fade;
	float	*fadeColor;
	char	*s;
	int maxClients, realMaxClients;
	int lineHeight;
	int topBorderSize, bottomBorderSize;

	// don't draw amuthing if the menu or console is up
	if ( cl_paused.integer ) {
		cg.deferredPlayerLoading = 0;
		return qfalse;
	}

	// don't draw scoreboard during death while warmup up
	if ( cg.warmup && !cg.showScores ) {
		return qfalse;
	}

	if ( cg.showScores || cg.predictedPlayerState.pm_type == PM_DEAD ||
		 cg.predictedPlayerState.pm_type == PM_INTERMISSION ) {
		fade = 1.0;
		fadeColor = colorWhite;
	} else {
		fadeColor = CG_FadeColor( cg.scoreFadeTime, FADE_TIME );

		if ( !fadeColor ) {
			// next time scoreboard comes up, don't print killer
			cg.deferredPlayerLoading = 0;
			cg.killerName[0] = 0;
			return qfalse;
		}
		fade = *fadeColor;
	}

	// fragged by ... line
	// or if in intermission and duel, prints the winner of the duel round
	if ((cgs.gametype == GT_DUEL || cgs.gametype == GT_POWERDUEL) && cgs.duelWinner != -1 &&
		cg.predictedPlayerState.pm_type == PM_INTERMISSION)
	{
		s = va("%s^7 %s", cgs.clientinfo[cgs.duelWinner].name, CG_GetStringEdString("MP_INGAME", "DUEL_WINS") );
		/*w = CG_DrawStrlen( s ) * BIGCHAR_WIDTH;
		x = ( SCREEN_WIDTH - w ) / 2;
		y = 40;
		CG_DrawBigString( x, y, s, fade );
		*/
		x = ( SCREEN_WIDTH ) / 2;
		y = 40;
		CG_Text_Paint ( x - CG_Text_Width ( s, 1.0f, FONT_MEDIUM ) / 2, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else if ((cgs.gametype == GT_DUEL || cgs.gametype == GT_POWERDUEL) && cgs.duelist1 != -1 && cgs.duelist2 != -1 &&
		cg.predictedPlayerState.pm_type == PM_INTERMISSION)
	{
		if (cgs.gametype == GT_POWERDUEL && cgs.duelist3 != -1)
		{
			s = va("%s^7 %s %s^7 %s %s", cgs.clientinfo[cgs.duelist1].name, CG_GetStringEdString("MP_INGAME", "SPECHUD_VERSUS"), cgs.clientinfo[cgs.duelist2].name, CG_GetStringEdString("MP_INGAME", "AND"), cgs.clientinfo[cgs.duelist3].name );
		}
		else
		{
			s = va("%s^7 %s %s", cgs.clientinfo[cgs.duelist1].name, CG_GetStringEdString("MP_INGAME", "SPECHUD_VERSUS"), cgs.clientinfo[cgs.duelist2].name );
		}
		/*w = CG_DrawStrlen( s ) * BIGCHAR_WIDTH;
		x = ( SCREEN_WIDTH - w ) / 2;
		y = 40;
		CG_DrawBigString( x, y, s, fade );
		*/
		x = ( SCREEN_WIDTH ) / 2;
		y = 40;
		CG_Text_Paint ( x - CG_Text_Width ( s, 1.0f, FONT_MEDIUM ) / 2, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else if ( cg.killerName[0] ) {
		s = va("%s %s", CG_GetStringEdString("MP_INGAME", "KILLEDBY"), cg.killerName );
		/*w = CG_DrawStrlen( s ) * BIGCHAR_WIDTH;
		x = ( SCREEN_WIDTH - w ) / 2;
		y = 40;
		CG_DrawBigString( x, y, s, fade );
		*/
		x = ( SCREEN_WIDTH ) / 2;
		y = 40;
		CG_Text_Paint ( x - CG_Text_Width ( s, 1.0f, FONT_MEDIUM ) / 2, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else if (cg_drawScoreboardPlayerCount.integer)
	{
		if (cgs.gametype >= GT_TEAM) {
			/*if (cgs.isCTFMod && cgs.CTF3ModeActive)
				s = va("%i vs. %i vs %i", CG_GetTeamCountFromClientInfo(TEAM_RED), CG_GetTeamCountFromClientInfo(TEAM_BLUE), CG_GetTeamCountFromClientInfo(TEAM_FREE, cgs.maxclients));
			else {*/
				switch (cg.snap->ps.persistant[PERS_TEAM])
				{
					default:
					case TEAM_SPECTATOR:
						if (cg.teamScores[0] < cg.teamScores[1])
							s = va("%i vs. %i", CG_GetTeamCountFromClientInfo(TEAM_BLUE), CG_GetTeamCountFromClientInfo(TEAM_RED));
						else
							s = va("%i vs. %i", CG_GetTeamCountFromClientInfo(TEAM_RED), CG_GetTeamCountFromClientInfo(TEAM_BLUE));
						break;
					case TEAM_RED:
						s = va("%i vs. %i", CG_GetTeamCountFromClientInfo(TEAM_RED), CG_GetTeamCountFromClientInfo(TEAM_BLUE));
						break;
					case TEAM_BLUE:
						s = va("%i vs. %i", CG_GetTeamCountFromClientInfo(TEAM_BLUE), CG_GetTeamCountFromClientInfo(TEAM_RED));
						break;
				}
			//}

		}
		else if (cg_drawScoreboardPlayerCount.integer >= 2) {
			s = va("Players: %i/%i", (CG_GetTeamCountFromClientInfo(TEAM_FREE)+CG_GetTeamCountFromClientInfo(TEAM_SPECTATOR)), cgs.maxclients);
		}
		else {
			/*s = ui_about_hostname.string;
			x = (SCREEN_WIDTH / 2) - (CG_Text_Width(s, 1.0f, FONT_MEDIUM) / 2);
			y = 40 - (CG_Text_Height(s, 1.0f, FONT_MEDIUM));
			CG_Text_Paint(x, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);*/

			s = va("%s " S_COLOR_WHITE "(%i/%i)", ui_about_hostname.string, (CG_GetTeamCountFromClientInfo(TEAM_FREE)+CG_GetTeamCountFromClientInfo(TEAM_SPECTATOR)), cgs.maxclients);
		}

		//x = 0.5f * (cgs.screenWidth - CG_Text_Width(s, 1.0f, FONT_MEDIUM));
		x = (SCREEN_WIDTH / 2) - (CG_Text_Width(s, 1.0f, FONT_MEDIUM) / 2);
		y = 40;
		CG_Text_Paint(x, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);

#if 0//NEW_SCOREBOARD
		if (/*cg_drawScoreboardPlayerCount.integer >= 2 && */cg_newScoreBoard.integer) {
			s = ui_about_hostname.string;
			x = (SCREEN_WIDTH / 2) - (CG_Text_Width(s, 1.0f, FONT_MEDIUM) / 2);
			y = 40 - (CG_Text_Height(s, 1.0f, FONT_MEDIUM));
			CG_Text_Paint(x, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
		}
#endif
	}

	// current rank
	if (cgs.gametype == GT_POWERDUEL)
	{ //do nothing?
	}
#if NEW_SCOREBOARD
	else if ( cgs.gametype < GT_TEAM )
	{
		if (cg_newScoreBoard.integer) {
			s = va("Map: %s", cgs.rawmapname);
			x = ( SCREEN_WIDTH ) / 2;
			y = 60;
			//CG_DrawBigString( x, y, s, fade );
			CG_DrawProportionalString(x, y, s, UI_CENTER|UI_DROPSHADOW, colorTable[CT_WHITE]);
		}
		else if (cg.snap->ps.persistant[PERS_TEAM] != TEAM_SPECTATOR)
		{
			char sPlace[256];
			char sOf[256];
			char sWith[256];

			trap->SE_GetStringTextString("MP_INGAME_PLACE",	sPlace,	sizeof(sPlace));
			trap->SE_GetStringTextString("MP_INGAME_OF",		sOf,	sizeof(sOf));
			trap->SE_GetStringTextString("MP_INGAME_WITH",	sWith,	sizeof(sWith));

			s = va("%s %s (%s %i) %s %i",
				CG_PlaceString( cg.snap->ps.persistant[PERS_RANK] + 1 ),
				sPlace,
				sOf,
				cg.numScores,
				sWith,
				cg.snap->ps.persistant[PERS_SCORE] );
		//	w = CG_DrawStrlen( s ) * BIGCHAR_WIDTH;
			x = ( SCREEN_WIDTH ) / 2;
			y = 60;
			//CG_DrawBigString( x, y, s, fade );
			CG_DrawProportionalString(x, y, s, UI_CENTER|UI_DROPSHADOW, colorTable[CT_WHITE]);
		}
	}
#else
	else if ( cgs.gametype < GT_TEAM) {
		if (cg.snap->ps.persistant[PERS_TEAM] != TEAM_SPECTATOR )
		{
			char sPlace[256];
			char sOf[256];
			char sWith[256];

			trap->SE_GetStringTextString("MP_INGAME_PLACE",	sPlace,	sizeof(sPlace));
			trap->SE_GetStringTextString("MP_INGAME_OF",		sOf,	sizeof(sOf));
			trap->SE_GetStringTextString("MP_INGAME_WITH",	sWith,	sizeof(sWith));

			s = va("%s %s (%s %i) %s %i",
				CG_PlaceString( cg.snap->ps.persistant[PERS_RANK] + 1 ),
				sPlace,
				sOf,
				cg.numScores,
				sWith,
				cg.snap->ps.persistant[PERS_SCORE] );
		//	w = CG_DrawStrlen( s ) * BIGCHAR_WIDTH;
			x = ( SCREEN_WIDTH ) / 2;
			y = 60;
			//CG_DrawBigString( x, y, s, fade );
			CG_DrawProportionalString(x, y, s, UI_CENTER|UI_DROPSHADOW, colorTable[CT_WHITE]);
		}
	}
#endif
	else if (cgs.gametype != GT_SIEGE)
	{
		if ( cg.teamScores[0] == cg.teamScores[1] ) {
			s = va("%s %i", CG_GetStringEdString("MP_INGAME", "TIEDAT"), cg.teamScores[0] );
		} else if ( cg.teamScores[0] >= cg.teamScores[1] ) {
			s = va("%s, %i / %i", CG_GetStringEdString("MP_INGAME", "RED_LEADS"), cg.teamScores[0], cg.teamScores[1] );
		} else {
			s = va("%s, %i / %i", CG_GetStringEdString("MP_INGAME", "BLUE_LEADS"), cg.teamScores[1], cg.teamScores[0] );
		}

		x = ( SCREEN_WIDTH ) / 2;
		y = 60;

		CG_Text_Paint ( x - CG_Text_Width ( s, 1.0f, FONT_MEDIUM ) / 2, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else if (cgs.gametype == GT_SIEGE && (cg_siegeWinTeam == 1 || cg_siegeWinTeam == 2))
	{
		if (cg_siegeWinTeam == 1)
		{
			s = va("%s", CG_GetStringEdString("MP_INGAME", "SIEGETEAM1WIN") );
		}
		else
		{
			s = va("%s", CG_GetStringEdString("MP_INGAME", "SIEGETEAM2WIN") );
		}

		x = ( SCREEN_WIDTH ) / 2;
		y = 60;

		CG_Text_Paint ( x - CG_Text_Width ( s, 1.0f, FONT_MEDIUM ) / 2, y, 1.0f, colorWhite, s, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}

	// scoreboard
	y = SB_HEADER;

#if NEW_SCOREBOARD
	if (cg_newScoreBoard.integer) {
		qhandle_t header = (cg_newScoreBoard.integer == 1 ? trap->R_RegisterShaderNoMip("gfx/Unbenannt-2.png") : trap->R_RegisterShaderNoMip("gfx/menus/menu_buttonback.tga"));

		if (!header && cg_newScoreBoard.integer == 1) {
			header = trap->R_RegisterShaderNoMip("gfx/menus/menu_buttonback.tga");
			//trap->Cvar_Set("cg_newScoreBoard", "2");
		}

		trap->R_DrawStretchPic( SB_SCORELINE_X - 40, y - 5, SB_SCORELINE_WIDTH + 80, 40, 0, 0, 1, 1, header);
		//CG_Text_Paint( (cg_smallScoreboard.integer ? SB_NAME_X+24 : SB_NAME_X), y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "NAME"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
		CG_Text_Paint( SB_NAME_X+15*cgs.widthRatioCoef, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "NAME"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else {
	CG_DrawPic ( SB_SCORELINE_X - 40, y - 5, SB_SCORELINE_WIDTH + 80, 40, trap->R_RegisterShaderNoMip ( "gfx/menus/menu_buttonback.tga" ) );
		CG_Text_Paint( SB_NAME_X, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "NAME"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
#else
	CG_DrawPic ( SB_SCORELINE_X - 40, y - 5, SB_SCORELINE_WIDTH + 80, 40, trap->R_RegisterShaderNoMip ( "gfx/menus/menu_buttonback.tga" ) );

	CG_Text_Paint ( SB_NAME_X, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "NAME"),0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
#endif
	if ((cgs.gametype == GT_DUEL && cgs.fraglimit > 0) || cgs.gametype == GT_POWERDUEL)
	{
		char sWL[100];
		trap->SE_GetStringTextString("MP_INGAME_W_L", sWL,	sizeof(sWL));

		CG_Text_Paint ( SB_SCORE_X, y, 1.0f, colorWhite, sWL, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else if (cgs.gametype == GT_CTF)
	{
		CG_Text_Paint ( SB_SCORELINE_X + 0.47f * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "SCORE"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );

		CG_Text_Paint ( SB_SCORELINE_X + 0.59f * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, "C", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
		CG_Text_Paint ( SB_SCORELINE_X + 0.66f * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, "A", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );//loda
		CG_Text_Paint ( SB_SCORELINE_X + 0.73f * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, "D", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );

		CG_Text_Paint ( SB_SCORELINE_X + 0.80 * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "PING"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
		CG_Text_Paint ( SB_SCORELINE_X + 0.90 * SB_SCORELINE_WIDTH, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "TIME"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}
	else
	{
		CG_Text_Paint ( SB_SCORE_X, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "SCORE"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
		CG_Text_Paint ( SB_PING_X, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "PING"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
		CG_Text_Paint ( SB_TIME_X, y, 1.0f, colorWhite, CG_GetStringEdString("MP_INGAME", "TIME"), 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM );
	}

	y = SB_TOP;

	// If there are more than SB_MAXCLIENTS_NORMAL, use the interleaved scores
#if NEW_SCOREBOARD
	if ( cg.numScores > SB_MAXCLIENTS_NORMAL || (cg_smallScoreboard.integer || cgs.gametype == GT_CTF || cg_newScoreBoard.integer)) {//JAPRO - Clientside - Small Scoreboard
#else
	if ( cg.numScores > SB_MAXCLIENTS_NORMAL || (cg_smallScoreboard.integer || cgs.gametype == GT_CTF)) {//JAPRO - Clientside - Small Scoreboard
#endif
		maxClients = SB_MAXCLIENTS_INTER;
		lineHeight = SB_INTER_HEIGHT;
		topBorderSize = 8;
		bottomBorderSize = 16;
	} else {
		maxClients = SB_MAXCLIENTS_NORMAL;
		lineHeight = SB_NORMAL_HEIGHT;
		topBorderSize = 8;
		bottomBorderSize = 8;
	}
	realMaxClients = maxClients;

	localClient = qfalse;


	//I guess this should end up being able to display 19 clients at once.
	//In a team game, if there are 9 or more clients on the team not in the lead,
	//we only want to show 10 of the clients on the team in the lead, so that we
	//have room to display the clients in the lead on the losing team.

	//I guess this can be accomplished simply by printing the first teams score with a maxClients
	//value passed in related to how many players are on both teams.
	if ( cgs.gametype >= GT_TEAM ) {
		//
		// teamplay scoreboard
		//
		y += lineHeight/2;

		if ( cg.teamScores[0] >= cg.teamScores[1] ) {
			int team1MaxCl = CG_GetTeamCount(TEAM_RED, maxClients);
			int team2MaxCl = CG_GetTeamCount(TEAM_BLUE, maxClients);

			if (team1MaxCl > 10 && (team1MaxCl+team2MaxCl) > maxClients)
			{
				team1MaxCl -= team2MaxCl;
				//subtract as many as you have to down to 10, once we get there
				//we just set it to 10

				if (team1MaxCl < 10)
				{
					team1MaxCl = 10;
				}
			}

			team2MaxCl = (maxClients-team1MaxCl); //team2 can display however many is left over after team1's display

			n1 = CG_TeamScoreboard( y, TEAM_RED, fade, team1MaxCl, lineHeight, qtrue );
			CG_DrawTeamBackground( SB_SCORELINE_X - 5, y - topBorderSize, 640 - SB_SCORELINE_X * 2 + 10, n1 * lineHeight + bottomBorderSize, 0.33f, TEAM_RED );
			CG_TeamScoreboard( y, TEAM_RED, fade, team1MaxCl, lineHeight, qfalse );
			y += (n1 * lineHeight) + BIGCHAR_HEIGHT;

			//maxClients -= n1;

			n2 = CG_TeamScoreboard( y, TEAM_BLUE, fade, team2MaxCl, lineHeight, qtrue );
			CG_DrawTeamBackground( SB_SCORELINE_X - 5, y - topBorderSize, 640 - SB_SCORELINE_X * 2 + 10, n2 * lineHeight + bottomBorderSize, 0.33f, TEAM_BLUE );
			CG_TeamScoreboard( y, TEAM_BLUE, fade, team2MaxCl, lineHeight, qfalse );
			y += (n2 * lineHeight) + BIGCHAR_HEIGHT;

			//maxClients -= n2;

			maxClients -= (team1MaxCl+team2MaxCl);
		} else {
			int team1MaxCl = CG_GetTeamCount(TEAM_BLUE, maxClients);
			int team2MaxCl = CG_GetTeamCount(TEAM_RED, maxClients);

			if (team1MaxCl > 10 && (team1MaxCl+team2MaxCl) > maxClients)
			{
				team1MaxCl -= team2MaxCl;
				//subtract as many as you have to down to 10, once we get there
				//we just set it to 10

				if (team1MaxCl < 10)
				{
					team1MaxCl = 10;
				}
			}

			team2MaxCl = (maxClients-team1MaxCl); //team2 can display however many is left over after team1's display

			n1 = CG_TeamScoreboard( y, TEAM_BLUE, fade, team1MaxCl, lineHeight, qtrue );
			CG_DrawTeamBackground( SB_SCORELINE_X - 5, y - topBorderSize, 640 - SB_SCORELINE_X * 2 + 10, n1 * lineHeight + bottomBorderSize, 0.33f, TEAM_BLUE );
			CG_TeamScoreboard( y, TEAM_BLUE, fade, team1MaxCl, lineHeight, qfalse );
			y += (n1 * lineHeight) + BIGCHAR_HEIGHT;

			//maxClients -= n1;

			n2 = CG_TeamScoreboard( y, TEAM_RED, fade, team2MaxCl, lineHeight, qtrue );
			CG_DrawTeamBackground( SB_SCORELINE_X - 5, y - topBorderSize, 640 - SB_SCORELINE_X * 2 + 10, n2 * lineHeight + bottomBorderSize, 0.33f, TEAM_RED );
			CG_TeamScoreboard( y, TEAM_RED, fade, team2MaxCl, lineHeight, qfalse );
			y += (n2 * lineHeight) + BIGCHAR_HEIGHT;

			//maxClients -= n2;

			maxClients -= (team1MaxCl+team2MaxCl);
		}
		maxClients = realMaxClients;

		if (cgs.serverMod == SVMOD_JAPRO && (cgs.gametype == GT_TEAM || cgs.gametype == GT_CTF)) { 	//how do we tell if server has racemode set. meme..
			//Check if someone is in team free?
			//Loop through each player, if they are in team free, break and set a flag
			//if flag is set, do this stuff VVV
			n1 = CG_TeamScoreboard( y, TEAM_FREE, fade, maxClients, lineHeight, qfalse );
			y += (n1 * lineHeight) + BIGCHAR_HEIGHT;
		}

		n1 = CG_TeamScoreboard( y, TEAM_SPECTATOR, fade, maxClients, lineHeight, qfalse );
		y += (n1 * lineHeight) + BIGCHAR_HEIGHT;
#if NEW_SCOREBOARD
	} else {
		//
		// free for all scoreboard
		//
		n1 = CG_TeamScoreboard( y, TEAM_FREE, fade, maxClients, lineHeight, qfalse );
		y += (n1 * lineHeight) + BIGCHAR_HEIGHT;
		if (cg_newScoreBoard.integer != 1 || cg.numScores < 20) {
			n2 = CG_TeamScoreboard( y, TEAM_SPECTATOR, fade, maxClients - n1, lineHeight, qfalse );
			y += (n2 * lineHeight) + BIGCHAR_HEIGHT;
		}
		else {
			int y2 = 90;
			clientInfo_t *spec = NULL;
			qboolean drewHeader = qfalse;
			for (i = 0; i < MAX_CLIENTS; i++) {
				spec = &cgs.clientinfo[i];
				//CG_Text_Paint(SB_NAME_X, y, 0.9f * scale, colorWhite, ci->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
				if (spec && spec->infoValid && spec->team == TEAM_SPECTATOR && VALIDSTRING(spec->name) &&
					(spec->botSkill == -1 || cg_newScoreBoard.integer >= 3))
				{
					if (!drewHeader) {
						CG_Text_Paint(2*cgs.widthRatioCoef, y2, 0.5f, colorWhite, "Spectators:", 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
						y2 += CG_Text_Height("Spectators:", 0.55f, FONT_MEDIUM);
						drewHeader = qtrue;
					}
					CG_Text_Paint(2*cgs.widthRatioCoef, y2, 0.5f, colorWhite, spec->name, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_MEDIUM);
					y2 += CG_Text_Height(spec->name, 0.55f, FONT_MEDIUM);
				}
			}
		}
	}
    if(cg_scoreboardTime.integer) {
        char numberStr[MAX_SAY_TEXT] = {0};
        struct tm *newtime;
        qboolean AM = qtrue;
        time_t rawtime;
        time(&rawtime);
        newtime = localtime(&rawtime);
        if (newtime->tm_hour >= 12) AM = qfalse;
        if (newtime->tm_hour > 12) newtime->tm_hour -= 12;
        if (newtime->tm_hour == 0) newtime->tm_hour = 12;
        Com_sprintf(numberStr, sizeof(numberStr), "%i:%02i %s", newtime->tm_hour, newtime->tm_min, AM ? "AM" : "PM");
        CG_Text_Paint(SB_NAME_X, y, 0.6f, colorWhite, numberStr, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
    }
	if (!localClient) {
		// draw local client at the bottom
		for ( i = 0 ; i < cg.numScores ; i++ ) {
			if ( cg.scores[i].client == cg.snap->ps.clientNum ) {
				if (!cg_newScoreBoard.integer)
					CG_DrawClientScore( y, &cg.scores[i], fadeColor, fade, lineHeight == SB_NORMAL_HEIGHT );
				else
					CG_DrawClientScore2( y, &cg.scores[i], fadeColor, fade, qfalse, qtrue );
				//CG_DrawClientScore2( y, &cg.scores[i], fadeColor, fade, qfalse );
				//CG_DrawClientScore2( y, &cg.scores[i], fadeColor, fade, lineHeight == SB_NORMAL_HEIGHT );
				break;
			}
		}
	}
#else
	} else {
		//
		// free for all scoreboard
		//
		n1 = CG_TeamScoreboard( y, TEAM_FREE, fade, maxClients, lineHeight, qfalse );
		y += (n1 * lineHeight) + BIGCHAR_HEIGHT;
		n2 = CG_TeamScoreboard( y, TEAM_SPECTATOR, fade, maxClients - n1, lineHeight, qfalse );
		y += (n2 * lineHeight) + BIGCHAR_HEIGHT;
	}

    if(cg_scoreboardTime.integer) {
        char numberStr[MAX_SAY_TEXT] = {0};
        struct tm *newtime;
        qboolean AM = qtrue;
        time_t rawtime;
        time(&rawtime);
        newtime = localtime(&rawtime);
        if (newtime->tm_hour >= 12) AM = qfalse;
        if (newtime->tm_hour > 12) newtime->tm_hour -= 12;
        if (newtime->tm_hour == 0) newtime->tm_hour = 12;
        Com_sprintf(numberStr, sizeof(numberStr), "%i:%02i %s", newtime->tm_hour, newtime->tm_min, AM ? "AM" : "PM");
        CG_Text_Paint(SB_NAME_X, y, 0.6f, colorWhite, numberStr, 0, 0, ITEM_TEXTSTYLE_OUTLINED, FONT_SMALL);
    }
	if (!localClient) {
		// draw local client at the bottom
		for ( i = 0 ; i < cg.numScores ; i++ ) {
			if ( cg.scores[i].client == cg.snap->ps.clientNum ) {
				CG_DrawClientScore( y, &cg.scores[i], fadeColor, fade, lineHeight == SB_NORMAL_HEIGHT );
				break;
			}
		}
	}
#endif

	// load any models that have been deferred
	if ( ++cg.deferredPlayerLoading > 10 ) {
		CG_LoadDeferredPlayers();
	}
	return qtrue;
}

//================================================================================

