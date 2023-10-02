#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

#define MAX_OBITUARY 6
#define OBITUARY_TIMEOUT 2500
#define OBITUARY_FADEOUTTIME 2000

#define OBITUARY_ICON_SIZE 16.0f
#define OBITUARY_PADDING_SCALAR 0.2f
#define OBITUARY_TEXT_DOWNSCALE 32.0f

typedef struct {
	int	killer;
	int victim;
	weapon_t weapon;
	meansOfDeath_t mod;
	int time;
} obituary_t;

static obituary_t hud_obituary[MAX_OBITUARY];
static int hud_numobituary;

void hud_initobituary( void ) {
	hud_numobituary = 0;
}

static void hud_purgeobituary( void ) {
	static obituary_t obituary[MAX_OBITUARY];
	int i, numobituary;
	memcpy( obituary, hud_obituary, sizeof( obituary ) );
	numobituary = 0;
	for ( i = 0; i < hud_numobituary; i++ ) {
		if ( cg.time - obituary[i].time > OBITUARY_TIMEOUT ) {
			continue;
		}
		memcpy( &hud_obituary[numobituary], &obituary[i], sizeof( obituary_t ) );
		numobituary++;
	}
	hud_numobituary = numobituary;
}

void hud_drawobituary( void ) {
	static float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static float blueTeam[4] = { 0.0f, 0.0f, 1.0f, 0.15f };
    static float redTeam[4] = { 1.0f, 0.0f, 0.0f, 0.15f };
    static float player[4] = { 0.5f, 0.0f, 0.5f, 0.15f };
    static float neutral[4] = { 0.5f, 0.5f, 0.5f, 0.15f };

    static float x, iconSize, iconHeight, iconWidth, pad, xPad, yPad, scale;
    float wepColor[4];
    float killerColor[4], victimColor[4];
    float killerWidth, victimWidth, textHeight, y;

	obituary_t *p;
	qhandle_t deathicon;

    iconSize = OBITUARY_ICON_SIZE;
    pad = OBITUARY_PADDING_SCALAR;

    iconWidth = (iconSize * cgs.widthRatioCoef);
    iconHeight = iconSize;
    scale = (iconSize / OBITUARY_TEXT_DOWNSCALE);
    xPad = (pad * iconWidth);
    yPad = (pad * iconHeight);
    x = (SCREEN_WIDTH - (0.5f * iconWidth));
    y = (0.5f * iconHeight);

	hud_purgeobituary();

	for ( p = hud_obituary; p < hud_obituary + hud_numobituary; p++ ) { //get the icon color
        deathicon = hud_media.icon_mod[p->mod];
        wepColor[0] = hud_mod_colors[p->mod][0];
        wepColor[1] = hud_mod_colors[p->mod][1];
        wepColor[2] = hud_mod_colors[p->mod][2];

        if (cgs.gametype > GT_TEAM) { //team gametype
            if ( cgs.clientinfo[p->killer].team == TEAM_BLUE ) {
                Vector4Copy(blueTeam, killerColor);
            } else if ( cgs.clientinfo[p->killer].team == TEAM_RED) {
                Vector4Copy(redTeam, killerColor);
            }
            if ( p->killer == cg.snap->ps.clientNum ) {
                Vector4Copy(player, killerColor);
            }

            if ( cgs.clientinfo[p->victim].team == TEAM_BLUE ) {
                Vector4Copy(blueTeam, victimColor);
            } else if ( cgs.clientinfo[p->victim].team == TEAM_RED ) {
                Vector4Copy(redTeam, victimColor);
            }
            if ( p->victim == cg.snap->ps.clientNum ) {
                Vector4Copy(player, victimColor);
            }
        } else { //not team gametype
            Vector4Copy( neutral, victimColor );
            Vector4Copy( neutral, killerColor );
            if ( p->killer == cg.snap->ps.clientNum ) {
                Vector4Copy( player, killerColor );
            } else if ( p->victim == cg.snap->ps.clientNum ) {
                Vector4Copy( player, victimColor );
            }
        }


        //Fade the items
        if ( cg.time - p->time > OBITUARY_FADEOUTTIME ) {
            color[3] = 1.0f - ( (float)cg.time - (float)p->time - OBITUARY_FADEOUTTIME ) / ( OBITUARY_TIMEOUT - OBITUARY_FADEOUTTIME );
        }
        else {
            color[3] = 1.0f;
        }
        if ( color[3] < killerColor[3] ) {
            killerColor[3] = 0.25f * color[3];
        }
        if ( color[3] < victimColor[3] ) {
            victimColor[3] = 0.25f * color[3];
        }
        wepColor[3] = color[3];

        //Get text dimensions
        killerWidth = CG_Text_Width( cgs.clientinfo[p->killer].name, scale, FONT_MEDIUM );
        victimWidth = CG_Text_Width( cgs.clientinfo[p->victim].name, scale, FONT_MEDIUM );
        textHeight = (float)CG_Text_Height( "TEXT", scale, FONT_MEDIUM );

        if ( p->killer == p->victim || p->killer == ENTITYNUM_WORLD ) { //Suicide
            //victim name and backdrop
            CG_FillRect(x - ((2.0f * xPad) + iconWidth) - victimWidth - ( 0.5f * xPad), y, (victimWidth + xPad), iconHeight, victimColor );
            CG_Text_Paint( x - ((2.0f * xPad) + iconWidth) - victimWidth, y + (0.125f * (iconHeight - textHeight)), scale, color, cgs.clientinfo[p->victim].name, 0, 0, 4, FONT_MEDIUM );
            //method of death icon
            trap->R_SetColor( wepColor ); //set the icon color
            CG_DrawPic( x - (xPad + victimWidth), y, iconWidth, iconHeight, deathicon ); //draw the icon
            trap->R_SetColor( NULL );
            //move the cursor down for the next line
            y += (yPad + iconHeight);
        } else {
            //victim
            CG_FillRect( x - victimWidth - (0.5f * xPad), y, (victimWidth + xPad), iconHeight, victimColor );
            CG_Text_Paint( x - victimWidth, y + (0.125f * (iconHeight - textHeight)), scale, color, cgs.clientinfo[p->victim].name, 0, 0, 4, FONT_MEDIUM );
            //killer
            CG_FillRect( x - victimWidth - ((2.0f * xPad) + iconWidth) - killerWidth - (0.5f * xPad), y, (killerWidth + xPad), iconHeight, killerColor );
            CG_Text_Paint( x - victimWidth - ((2.0f * xPad) + iconWidth) - killerWidth, y + (0.125f * (iconHeight - textHeight)), scale, color, cgs.clientinfo[p->killer].name, 0, 0, 4, FONT_MEDIUM );
            //method of death icon
            trap->R_SetColor( wepColor );
            CG_DrawPic( x - victimWidth - (xPad + iconWidth), y, iconWidth, iconHeight, deathicon ); //draw the icon
            trap->R_SetColor( NULL );
            //move the cursor down for the next line
            y += (yPad + iconHeight);
        }
	}
	trap->R_SetColor( NULL );
}

void CG_AddObituary( int killer, int victim, weapon_t weapon, meansOfDeath_t mod ) {
	int i;

	if ( hud_numobituary == MAX_OBITUARY ) {
		for ( i = 0; i < MAX_OBITUARY - 1; i++ ) {
			memcpy( &hud_obituary[i], &hud_obituary[i + 1], sizeof( obituary_t ) );
		}
		hud_numobituary--;
	}
	hud_obituary[hud_numobituary].killer = killer;
	hud_obituary[hud_numobituary].victim = victim;
	hud_obituary[hud_numobituary].mod = mod;
	hud_obituary[hud_numobituary].weapon = weapon;
	hud_obituary[hud_numobituary].time = cg.time;
	hud_numobituary++;
}
