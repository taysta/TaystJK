#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

#define MAX_OBITUARY 16
#define OBITUARY_TIMEOUT 2500
#define OBITUARY_FADEOUTTIME 2000

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
	static float wepcolor[4];
	float dim, y, x;
	obituary_t *p;
	qhandle_t deathicon;

	if ( cg.showScores ) {
		return;
	}

	hud_purgeobituary();

	x = 15;
	y = 25;

	for ( p = hud_obituary; p < hud_obituary + hud_numobituary; p++ ) {
		if ( p->weapon > WP_NONE && p->weapon < WP_NUM_WEAPONS ) {
			deathicon = hud_media.icon_weapon[p->weapon];
			wepcolor[0] = hud_weapon_colors[p->weapon][0];
			wepcolor[1] = hud_weapon_colors[p->weapon][1];
			wepcolor[2] = hud_weapon_colors[p->weapon][2];
			wepcolor[3] = color[3];
		} else {
			deathicon = hud_media.icon_mod[p->mod];
			wepcolor[0] = wepcolor[1] = wepcolor[2] = 1.0f;
			wepcolor[3] = color[3];
		}

		if ( cg.time - p->time > OBITUARY_FADEOUTTIME ) {
			color[3] = 1.0f - ( (float)cg.time - p->time - OBITUARY_FADEOUTTIME ) / ( OBITUARY_TIMEOUT - OBITUARY_FADEOUTTIME );
		}
		else {
			color[3] = 1.0f;
		}
		trap->R_SetColor( color );
		if ( p->killer == p->victim || p->killer == ENTITYNUM_WORLD ) {
            CG_Text_Paint( x, y, 0.4f, colorWhite, va( "%s ^7%s", cgs.clientinfo[p->victim].name, "suicides" ), 0, 2, 2, FONT_MEDIUM);

			y += 24;
			continue;
		}
		dim = CG_Text_Width( cgs.clientinfo[p->killer].name, 0.4f, FONT_MEDIUM);
        CG_Text_Paint( x, y, 0.4f, colorWhite, cgs.clientinfo[p->killer].name, 0, 0, 4, FONT_MEDIUM );
        CG_Text_Paint( x + dim + 30 , y, 0.4f, colorWhite, cgs.clientinfo[p->victim].name, 0, 0, 4, FONT_MEDIUM );
        trap->R_SetColor( NULL );
        CG_DrawPic( x + dim + 6, y - 2, 18, 18, deathicon );
		y += 24;
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
