#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

vec4_t hud_weapon_colors[WP_NUM_WEAPONS] = {
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_NONE
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_STUN_BATON
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_MELEE
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_SABER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_BRYAR_PISTOL
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_BLASTER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_DISRUPTOR
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_BOWCASTER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_REPEATER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_DEMP2
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_FLECHETTE
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_ROCKET_LAUNCHER
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_THERMAL
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_TRIP_MINE
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_DET_PACK
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_CONCUSSION
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_BRYAR_OLD
        { 1.0f, 1.0f, 1.0f, 1.0f }, // WP_EMPLACED_GUN
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
        "gfx/hud/w_icon_stunbaton", // MOD_STUN_BATON
        "gfx/hud/w_icon_melee", // MOD_MELEE
        "gfx/hud/w_icon_lightsaber", // MOD_SABER
        "gfx/hud/w_icon_blaster_pistol", // MOD_BRYAR_PISTOL
        "gfx/hud/w_icon_blaster_pistol", // MOD_BRYAR_PISTOL_ALT
        "gfx/hud/w_icon_blaster", // MOD_BLASTER
        "gfx/hud/w_icon_blaster", // MOD_TURBLAST
        "gfx/hud/w_icon_disruptor", // MOD_DISRUPTOR
        "gfx/hud/w_icon_disruptor", // MOD_DISRUPTOR_SPLASH
        "gfx/hud/w_icon_disruptor", // MOD_DISRUPTOR_SNIPER
        "gfx/hud/w_icon_bowcaster", // MOD_BOWCASTER
        "gfx/hud/w_icon_repeater", // MOD_REPEATER
        "gfx/hud/w_icon_repeater", // MOD_REPEATER_ALT
        "gfx/hud/w_icon_repeater", // MOD_REPEATER_ALT_SPLASH
        "gfx/hud/w_icon_demp2", // MOD_DEMP2
        "gfx/hud/w_icon_demp2", // MOD_DEMP2_ALT
        "gfx/hud/w_icon_flachette", // MOD_FLECHETTE
        "gfx/hud/w_icon_flachette", // MOD_FLECHETTE_ALT_SPLASH
        "gfx/hud/w_icon_merrsonn", // MOD_ROCKET
        "gfx/hud/w_icon_merrsonn", // MOD_ROCKET_SPLASH
        "gfx/hud/w_icon_merrsonn", // MOD_ROCKET_HOMING
        "gfx/hud/w_icon_merrsonn", // MOD_ROCKET_HOMING_SPLASH
        "gfx/hud/w_icon_thermal", // MOD_THERMAL
        "gfx/hud/w_icon_thermal", // MOD_THERMAL_SPLASH
        "gfx/hud/w_icon_tripmine", // MOD_TRIP_MINE_SPLASH
        "gfx/hud/w_icon_tripmine", // MOD_TIMED_MINE_SPLASH
        "gfx/hud/w_icon_detpack", // MOD_DET_PACK_SPLASH
        "hud/mod/generic", // MOD_VEHICLE
        "gfx/hud/w_icon_melee", // MOD_CONC
        "gfx/hud/w_icon_melee", // MOD_CONC_ALT
        "hud/mod/generic", // MOD_FORCE_DARK
        "hud/mod/i_icon_sentrygun", // MOD_SENTRY
        "hud/mod/generic", // MOD_WATER
        "hud/mod/generic", // MOD_SLIME
        "hud/mod/generic", // MOD_LAVA
        "hud/mod/generic", // MOD_CRUSH
        "hud/mod/telefrag", // MOD_TELEFRAG
        "hud/mod/generic", // MOD_FALLING
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

