#include "../qcommon/q_shared.h"
#include "cg_local.h"
#include "hud_local.h"

vec4_t hud_mod_colors[MOD_MAX] = {
        { 1.0f, 1.0f, 1.0f, 1.0f }, // MOD_UNKNOWN
        { 0.0f, 1.0f, 1.0f, 1.0f }, // MOD_STUN_BATON
        { 1.0f, 1.0f, 0.0f, 1.0f }, // MOD_MELEE
        { 0.5f, 0.0f, 1.0f, 1.0f }, // MOD_SABER
        { 0.0f, 1.0f, 1.0f, 1.0f }, // MOD_BRYAR_PISTOL
        { 0.0f, 1.0f, 1.0f, 1.0f }, // MOD_BRYAR_PISTOL_ALT
        { 0.0f, 1.0f, 0.5f, 1.0f }, // MOD_BLASTER
        { 0.0f, 1.0f, 0.5f, 1.0f }, // MOD_TURBLAST
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_DISRUPTOR
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_DISRUPTOR_SPLASH
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_DISRUPTOR_SNIPER
        { 0.0f, 1.0f, 0.5f, 1.0f }, // MOD_BOWCASTER
        { 0.0f, 0.0f, 1.0f, 1.0f }, // MOD_REPEATER
        { 0.0f, 0.0f, 1.0f, 1.0f }, // MOD_REPEATER_ALT
        { 0.0f, 0.0f, 1.0f, 1.0f }, // MOD_REPEATER_ALT_SPLASH
        { 0.5f, 1.0f, 0.0f, 1.0f }, // MOD_DEMP2
        { 0.5f, 1.0f, 0.0f, 1.0f }, // MOD_DEMP2_ALT
        { 1.0f, 0.5f, 0.0f, 1.0f }, // MOD_FLECHETTE
        { 1.0f, 0.5f, 0.0f, 1.0f }, // MOD_FLECHETTE_ALT_SPLASH
        { 1.0f, 0.0f, 0.0f, 1.0f }, // MOD_ROCKET
        { 1.0f, 0.0f, 0.0f, 1.0f }, // MOD_ROCKET_SPLASH
        { 1.0f, 0.0f, 0.0f, 1.0f }, // MOD_ROCKET_HOMING
        { 1.0f, 0.0f, 0.0f, 1.0f }, // MOD_ROCKET_HOMING_SPLASH
        { 1.0f, 0.4f, 0.0f, 1.0f }, // MOD_THERMAL
        { 1.0f, 0.4f, 0.0f, 1.0f }, // MOD_THERMAL_SPLASH
        { 1.0f, 1.0f, 0.4f, 1.0f }, // MOD_TRIP_MINE_SPLASH
        { 1.0f, 1.0f, 0.4f, 1.0f }, // MOD_TIMED_MINE_SPLASH
        { 1.0f, 0.4f, 0.0f, 1.0f }, // MOD_DET_PACK_SPLASH
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_VEHICLE
        { 1.0f, 0.0f, 1.0f, 1.0f }, // MOD_CONC
        { 1.0f, 0.0f, 1.0f, 1.0f }, // MOD_CONC_ALT
        { 1.0f, 0.4f, 0.0f, 1.0f }, // MOD_FORCE_DARK
        { 1.0f, 1.0f, 1.0f, 1.0f }, // MOD_SENTRY
        { 0.0f, 0.0f, 1.0f, 1.0f }, // MOD_WATER
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_SLIME
        { 1.0f, 0.0f, 0.0f, 1.0f }, // MOD_LAVA
        { 0.0f, 0.0f, 0.0f, 1.0f }, // MOD_CRUSH
        { 0.4f, 0.2f, 0.3f, 1.0f }, // MOD_TELEFRAG
        { 1.0f, 1.0f, 0.6f, 1.0f }, // MOD_FALLING
        { 0.5f, 0.2f, 0.7f, 1.0f }, // MOD_SUICIDE
        { 0.0f, 1.0f, 0.0f, 1.0f }, // MOD_TARGET_LASER
        { 1.0f, 1.0f, 0.6f, 1.0f }, // MOD_TRIGGER_HURT
        { 1.0f, 1.0f, 1.0f, 1.0f }  // MOD_TEAM_CHANGE
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
        "hud/mod/thermal", // MOD_THERMAL_SPLASH
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
	for ( i = 0; i < MOD_MAX; i++ ) {
		hud_media.icon_mod[i] = trap->R_RegisterShaderNoMip( hud_mod_icons[i] );
	}
}

