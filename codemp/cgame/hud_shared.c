#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

vec4_t hud_weapon_colors[WP_NUM_WEAPONS] = {
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_NONE
        { 0.0f, 1.0f, 1.0f, 1.0f }, // WP_STUN_BATON
        { 1.0f, 1.0f, 0.0f, 1.0f }, // WP_MELEE
        { 0.5f, 0.0f, 1.0f, 1.0f }, // WP_SABER
        { 0.0f, 1.0f, 1.0f, 1.0f }, // WP_BRYAR_PISTOL
        { 1.0f, 1.0f, 0.5f, 1.0f }, // WP_BLASTER
        { 0.0f, 1.0f, 0.0f, 1.0f }, // WP_DISRUPTOR
        { 0.0f, 1.0f, 0.5f, 1.0f }, // WP_BOWCASTER
        { 0.0f, 0.0f, 1.0f, 1.0f }, // WP_REPEATER
        { 0.5f, 1.0f, 0.0f, 1.0f }, // WP_DEMP2
        { 1.0f, 0.5f, 0.0f, 1.0f }, // WP_FLECHETTE
        { 1.0f, 0.0f, 0.0f, 1.0f }, // WP_ROCKET_LAUNCHER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_THERMAL
        { 1.0f, 1.0f, 0.4f, 1.0f }, // WP_TRIP_MINE
        { 1.0f, 0.4f, 0.0f, 1.0f }, // WP_DET_PACK
        { 1.0f, 0.0f, 1.0f, 1.0f }, // WP_CONCUSSION
        { 0.0f, 1.0f, 1.0f, 1.0f }, // WP_BRYAR_OLD
        { 0.0f, 0.5f, 1.0f, 1.0f }, // WP_EMPLACED_GUN
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_TURRET
};

const char *hud_weapon_icons[WP_NUM_WEAPONS] = {
        "", // WP_NONE
        "gfx/hud/w_icon_stunbaton", // WP_STUN_BATON
        "gfx/hud/w_icon_melee", // WP_MELEE
        "gfx/hud/w_icon_lightsaber", // WP_SABER
        "gfx/hud/w_icon_blaster_pistol", // WP_BRYAR_PISTOL
        "gfx/hud/w_icon_blaster", // WP_BLASTER
        "gfx/hud/w_icon_disruptor", // WP_DISRUPTOR
        "gfx/hud/w_icon_bowcaster", // WP_BOWCASTER
        "gfx/hud/w_icon_repeater", // WP_REPEATER
        "gfx/hud/w_icon_demp2", // WP_DEMP2
        "gfx/hud/w_icon_flachette", // WP_FLECHETTE
        "gfx/hud/w_icon_merrsonn", // WP_ROCKET_LAUNCHER
        "gfx/hud/w_icon_thermal", // WP_THERMAL
        "gfx/hud/w_icon_tripmine", // WP_TRIP_MINE
        "gfx/hud/w_icon_detpack", // WP_DET_PACK
        "gfx/hud/w_icon_c_rifle", // WP_CONCUSSION
        "gfx/hud/w_icon_briar", // WP_BRYAR_OLD
        "gfx/hud/w_icon_blaster", // WP_EMPLACED_GUN
        "gfx/hud/w_icon_blaster", // WP_TURRET
};

const char *hud_mod_icons[ MOD_MAX ] = {
        "hud/mod/generic", // MOD_UNKNOWN
        "hud/mod/stun", // MOD_STUN_BATON
        "hud/mod/melee", // MOD_MELEE
        "hud/mod/saber", // MOD_SABER
        "hud/mod/pistol", // MOD_BRYAR_PISTOL
        "hud/mod/pistol", // MOD_BRYAR_PISTOL_ALT
        "hud/mod/rifle", // MOD_BLASTER
        "hud/mod/rifle", // MOD_TURBLAST
        "hud/mod/disruptor", // MOD_DISRUPTOR
        "hud/mod/disruptor", // MOD_DISRUPTOR_SPLASH
        "hud/mod/disruptor_alt", // MOD_DISRUPTOR_SNIPER
        "hud/mod/bowcaster", // MOD_BOWCASTER
        "hud/mod/repeater", // MOD_REPEATER
        "hud/mod/repeater_alt", // MOD_REPEATER_ALT
        "hud/mod/repeater_alt", // MOD_REPEATER_ALT_SPLASH
        "hud/mod/demp2", // MOD_DEMP2
        "hud/mod/demp2_alt", // MOD_DEMP2_ALT
        "hud/mod/flachette", // MOD_FLECHETTE
        "hud/mod/flachette_alt", // MOD_FLECHETTE_ALT_SPLASH
        "hud/mod/merrsonn", // MOD_ROCKET
        "hud/mod/merrsonn", // MOD_ROCKET_SPLASH
        "hud/mod/merrsonn_alt", // MOD_ROCKET_HOMING
        "hud/mod/merrsonn_alt", // MOD_ROCKET_HOMING_SPLASH
        "hud/mod/thermal", // MOD_THERMAL
        "hud/mod/thermal_alt", // MOD_THERMAL_SPLASH
        "hud/mod/mine", // MOD_TRIP_MINE_SPLASH
        "hud/mod/mine", // MOD_TIMED_MINE_SPLASH
        "hud/mod/detpack", // MOD_DET_PACK_SPLASH
        "hud/mod/swoop", // MOD_VEHICLE
        "hud/mod/concussion", // MOD_CONC
        "hud/mod/concussion_alt", // MOD_CONC_ALT
        "hud/mod/force", // MOD_FORCE_DARK
        "hud/mod/portable_turret", // MOD_SENTRY
        "hud/mod/water", // MOD_WATER
        "hud/mod/ooze", // MOD_SLIME
        "hud/mod/lava", // MOD_LAVA
        "hud/mod/crushed", // MOD_CRUSH
        "hud/mod/telefrag", // MOD_TELEFRAG
        "hud/mod/fall", // MOD_FALLING
        "hud/mod/generic", // MOD_SUICIDE
        "hud/mod/generic", // MOD_TARGET_LASER
        "hud/mod/generic", // MOD_TRIGGER_HURT
        "hud/mod/generic", // MOD_TEAM_CHANGE
};

hud_media_t hud_media;

// get all the required assets
void hud_initmedia( void ) {
	int i;

	for ( i = 0; i < WP_NUM_WEAPONS; i++ ) {
		hud_media.icon_weapon[i] = trap->R_RegisterShaderNoMip( hud_weapon_icons[i] );
	}
	for ( i = 0; i < MOD_MAX; i++ ) {
		hud_media.icon_mod[i] = trap->R_RegisterShaderNoMip( hud_mod_icons[i] );
	}

	for ( i = 0; i < bg_numItems; i++ ) {
		if ( bg_itemlist[i].icon != NULL && bg_itemlist[i].icon[0] )
		{
			hud_media.itemicons[i] = trap->R_RegisterShaderNoMip( bg_itemlist[i].icon );
		}
		else {
			hud_media.itemicons[i] = -1;
		}
	}
}

