/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2005 - 2015, ioquake3 contributors
Copyright (C) 2013 - 2015, OpenJK contributors
Copyright (C) 2015 - 2021, EternalJK contributors
Copyright (C) 2015 - 2023, TaystJK contributors


This file is part of the TaystJK source code.

TaystJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <https://www.gnu.org/licenses/>.
===========================================================================
*/

#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

typedef struct {
	int	killer;
	int victim;
	meansOfDeath_t mod;
	int time;
} obituary_t;

static obituary_t hudObituary[MAX_OBITUARY];
static int hudNumObituary;

void HUD_InitObituary( void ) {
    hudNumObituary = 0;
}

static void HUD_PurgeObituary( void ) {
	static obituary_t obituary[MAX_OBITUARY];
	int i, numObituary;
	memcpy( obituary, hudObituary, sizeof( obituary ) );
    numObituary = 0;
	for ( i = 0; i < hudNumObituary; i++ ) {
		if ( cg.time - obituary[i].time > OBITUARY_TIMEOUT ) {
			continue;
		}
		memcpy( &hudObituary[numObituary], &obituary[i], sizeof( obituary_t ) );
        numObituary++;
	}
    hudNumObituary = numObituary;
}

void HUD_DrawObituary( void ) {
	static float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static float blueTeam[4] = { 0.0f, 0.0f, 1.0f, 0.15f };
    static float redTeam[4] = { 1.0f, 0.0f, 0.0f, 0.15f };
    static float player[4] = { 0.5f, 0.0f, 0.5f, 0.15f };
    static float neutral[4] = { 0.5f, 0.5f, 0.5f, 0.15f };
    static float x, y, iconSize, iconHeight, iconWidth, padding, xPadding, yPadding, textScale, textHeight;
    float wepColor[4], killerColor[4], victimColor[4];
    float killerWidth, victimWidth;
	obituary_t *p;
	qhandle_t deathicon;

    HUD_PurgeObituary();

    //set up the killfeed
    iconSize = OBITUARY_ICON_SIZE;
    padding = OBITUARY_PADDING_SCALAR;
    iconWidth = (iconSize * cgs.widthRatioCoef);
    iconHeight = iconSize;
    textScale = (iconSize / OBITUARY_TEXT_DOWNSCALE);
    xPadding = (padding * iconWidth);
    yPadding = (padding * iconHeight);
    x = (SCREEN_WIDTH - (0.5f * iconWidth));
    y = (0.5f * iconHeight);

	for ( p = hudObituary; p < hudObituary + hudNumObituary; p++ ) { //get the icon color
        //set the method of death icon
        deathicon = hm.modIcon[p->mod];
        //set the icons color
        wepColor[0] = hudModColors[p->mod][0];
        wepColor[1] = hudModColors[p->mod][1];
        wepColor[2] = hudModColors[p->mod][2];
        //set the box colors
        if (cgs.gametype >= GT_TEAM) { //team gametype
            //get killers team color
            if ( cgs.clientinfo[p->killer].team == TEAM_BLUE ) {
                Vector4Copy(blueTeam, killerColor);
            } else if ( cgs.clientinfo[p->killer].team == TEAM_RED) {
                Vector4Copy(redTeam, killerColor);
            }
            //check if it's us
            if ( p->killer == cg.snap->ps.clientNum ) {
                Vector4Copy(player, killerColor);
            }
            //get victims team color
            if ( cgs.clientinfo[p->victim].team == TEAM_BLUE ) {
                Vector4Copy(blueTeam, victimColor);
            } else if ( cgs.clientinfo[p->victim].team == TEAM_RED ) {
                Vector4Copy(redTeam, victimColor);
            }
            //check if it's us
            if ( p->victim == cg.snap->ps.clientNum ) {
                Vector4Copy(player, victimColor);
            }
        } else { //not team gametype
            //use a neutral grey color
            Vector4Copy( neutral, victimColor );
            Vector4Copy( neutral, killerColor );
            //unless it's us
            if ( p->killer == cg.snap->ps.clientNum ) {
                Vector4Copy( player, killerColor );
            } else if ( p->victim == cg.snap->ps.clientNum ) {
                Vector4Copy( player, victimColor );
            }
        }
        //Fade the obituaries
        if ( cg.time - p->time > OBITUARY_FADEOUTTIME ) {
            color[3] = 1.0f - ( (float)cg.time - (float)p->time - OBITUARY_FADEOUTTIME ) / ( OBITUARY_TIMEOUT - OBITUARY_FADEOUTTIME );
        }
        else {
            color[3] = 1.0f;
        }
        //only fade the boxes if the new fade is less than our current opacity
        if ( color[3] < killerColor[3] ) {
            killerColor[3] = 0.25f * color[3];
        }
        if ( color[3] < victimColor[3] ) {
            victimColor[3] = 0.25f * color[3];
        }
        wepColor[3] = color[3];
        //Get text dimensions
        killerWidth = CG_Text_Width( cgs.clientinfo[p->killer].name, textScale, FONT_MEDIUM );
        victimWidth = CG_Text_Width( cgs.clientinfo[p->victim].name, textScale, FONT_MEDIUM );
        textHeight = (float)CG_Text_Height( "TEXT", textScale, FONT_MEDIUM );
        //Draw the killfeed
        if ( p->killer == p->victim || p->killer == ENTITYNUM_WORLD ) { //Suicide
            //victim name and backdrop
            CG_FillRect(x - ((2.0f * xPadding) + iconWidth) - victimWidth - ( 0.5f * xPadding), y, (victimWidth + xPadding), iconHeight, victimColor );
            CG_Text_Paint( x - ((2.0f * xPadding) + iconWidth) - victimWidth, y + (0.125f * (iconHeight - textHeight)), textScale, color, cgs.clientinfo[p->victim].name, 0, 0, 4, FONT_MEDIUM );
            //method of death icon
            trap->R_SetColor( wepColor ); //set the icon color
            CG_DrawPic( x - (xPadding + iconWidth), y, iconWidth, iconHeight, deathicon ); //draw the icon
            trap->R_SetColor( NULL );
            //move the cursor down for the next line
            y += (yPadding + iconHeight);
        } else { //Not a suicide
            //victim
            CG_FillRect( x - victimWidth - (0.5f * xPadding), y, (victimWidth + xPadding), iconHeight, victimColor );
            CG_Text_Paint( x - victimWidth, y + (0.125f * (iconHeight - textHeight)), textScale, color, cgs.clientinfo[p->victim].name, 0, 0, 4, FONT_MEDIUM );
            //killer
            CG_FillRect( x - victimWidth - ((2.0f * xPadding) + iconWidth) - killerWidth - (0.5f * xPadding), y, (killerWidth + xPadding), iconHeight, killerColor );
            CG_Text_Paint( x - victimWidth - ((2.0f * xPadding) + iconWidth) - killerWidth, y + (0.125f * (iconHeight - textHeight)), textScale, color, cgs.clientinfo[p->killer].name, 0, 0, 4, FONT_MEDIUM );
            //method of death icon
            trap->R_SetColor( wepColor );
            CG_DrawPic( x - victimWidth - (xPadding + iconWidth), y, iconWidth, iconHeight, deathicon ); //draw the icon
            trap->R_SetColor( NULL );
            //move the cursor down for the next line
            y += (yPadding + iconHeight);
        }
	}
	trap->R_SetColor( NULL );
}

void CG_AddObituary( int killer, int victim, meansOfDeath_t mod ) {
	int i;

	if ( hudNumObituary == MAX_OBITUARY ) {
		for ( i = 0; i < MAX_OBITUARY - 1; i++ ) {
			memcpy( &hudObituary[i], &hudObituary[i + 1], sizeof( obituary_t ) );
		}
        hudNumObituary--;
	}
    hudObituary[hudNumObituary].killer = killer;
    hudObituary[hudNumObituary].victim = victim;
    hudObituary[hudNumObituary].mod = mod;
    hudObituary[hudNumObituary].time = cg.time;
    hudNumObituary++;
}
