#ifndef ETERNALJK_HUD_TRIBES_H
#define ETERNALJK_HUD_TRIBES_H

//includes
#include "cg_local.h"
#include "../ui/ui_shared.h"
#include "../game/bg_public.h"
#include "hud_local.h"

//defines
#define JETFUEL_H			4.0f
#define JETFUEL_W			120.0f
#define JETFUEL_X			(SCREEN_WIDTH * 0.5f)
#define JETFUEL_Y			(SCREEN_HEIGHT-JETFUEL_H*8.0f)
#define JETPACK_NUM_BARS 	5
#define JETPACK_BAR_GAP		0.6f
#define LERP_JETPACK 		0.04f

#define HEALTH_H			12
#define HEALTH_W			16
#define HEALTH_X			64
#define HEALTH_Y			420
#define HEALTH_GAP			0.8f

//abilities
#define COST_GRAPPLE_TRIBES 30
#define COST_PROTECT_TRIBES 50

#define ABILITY_OUTER_BOX_SIZE 	22
#define ABILITY_ICON_SIZE 		15
#define ABILITY_CENTER_OFFSET 	0.8f

static const char* keyCodeNames[MAX_KEYS] = {
		NULL , //A_NULL
		"SHIFT" , //A_SHIFT
		"CTRL" , //A_CTRL
		"ALT" , //A_ALT
		"CAPSLOCK" , //A_CAPSLOCK
		"KP_NUMLOCK" , //A_NUMLOCK
		"SCROLLLOCK" , //A_SCROLLLOCK
		"PAUSE" , //A_PAUSE
		"BACKSPACE" , //A_BACKSPACE
		"TAB" , //A_TAB
		"ENTER" , //A_ENTER
		"KP_PLUS" , //A_KP_PLUS
		"KP_MINUS" , //A_KP_MINUS
		"KP_ENTER" , //A_KP_ENTER
		"KP_DEL" , //A_KP_PERIOD
		"PRNTSCRN" , //A_PRINTSCREEN
		"KP_INS" , //A_KP_0
		"KP_END" , //A_KP_1
		"KP_DOWNARROW" , //A_KP_2
		"KP_PGDN" , //A_KP_3
		"KP_LEFTARROW" , //A_KP_4
		"KP_5" , //A_KP_5
		"KP_RIGHTARROW" , //A_KP_6
		"KP_HOME" , //A_KP_7
		"KP_UPARROW" , //A_KP_8
		"KP_PGUP" , //A_KP_9,
		"CONSOLE" , //A_CONSOLE
		"ESCAPE" , //A_ESCAPE
		"F1" , //A_F1
		"F2" , //A_F2
		"F3" , //A_F3,
		"F4" , //A_F4
		"SPACE" , //A_SPACE
		"!" , //A_PLING
		"''" , //A_DOUBLE_QUOTE
		"#" , ////A_HASH
		"$" , //A_STRING
		"%" , //A_PERCENT
		"&" , //A_AND
		"'" , //A_SINGLE_QUOTE
		"(" , //A_OPEN_BRACKET
		")" , //A_CLOSE_BRACKET
		"*" , //A_STAR
		"+" , //A_PLUS
		"," , //A_COMMA
		"-" , //A_MINUS
		"." , //A_PERIOD
		"/" , //A_FORWARD_SLASH
		"0" , //A_0
		"1" , //A_1
		"2" , //A_2
		"3" , //A_3
		"4" , //A_4
		"5" , //A_5
		"6" , //A_6
		"7" , //A_7
		"8" , //A_8
		"9" , //A_9
		":" , //A_COLON
		";" , //A_SEMICOLON
		"<" , //A_LESSTHAN
		"=" , //A_EQUALS
		">" , //A_GREATERTHAN
		"?" , //A_QUESTION
		"@" , //A_AT
		"A" , //A_CAP_A
		"B" , //A_CAP_B
		"C" , //A_CAP_C
		"D" , //A_CAP_D
		"E" , //A_CAP_E
		"F" , //A_CAP_F
		"G" , //A_CAP_G
		"H" , //A_CAP_H
		"I" , //A_CAP_I
		"J" , //A_CAP_J
		"K" , //A_CAP_K
		"L" , //A_CAP_L
		"M" , //A_CAP_M
		"N" , //A_CAP_N
		"O" , //A_CAP_O
		"P" , //A_CAP_P
		"Q" , //A_CAP_Q
		"R" , //A_CAP_R
		"S" , //A_CAP_S
		"T" , //A_CAP_T
		"U" , //A_CAP_U
		"V" , //A_CAP_V
		"W" , //A_CAP_W
		"X" , //A_CAP_X
		"Y" , //A_CAP_Y
		"Z" , //A_CAP_Z
		"[" , //A_OPEN_SQUARE
		"" , //A_BACKSLASH
		"]" , //A_CLOSE_SQUARE
		"^" , //A_CARET
		"_" , //A_UNDERSCORE
		"'" , //A_LEFT_SINGLE_QUOTE
		"A" , //A_LOW_A
		"B" , //A_LOW_B
		"C" , //A_LOW_C
		"D" , //A_LOW_D
		"E" , //A_LOW_E
		"F" , //A_LOW_F
		"G" , //A_LOW_G
		"H" , //A_LOW_H
		"I" , //A_LOW_I
		"J" , //A_LOW_J
		"K" , //A_LOW_K
		"L" , //A_LOW_L
		"M" , //A_LOW_M
		"N" , //A_LOW_N
		"O" , //A_LOW_O
		"P" , //A_LOW_P
		"Q" , //A_LOW_Q
		"R" , //A_LOW_R
		"S" , //A_LOW_S
		"T" , //A_LOW_T
		"U" , //A_LOW_U
		"V" , //A_LOW_V
		"W" , //A_LOW_W
		"X" , //A_LOW_X
		"Y" , //A_LOW_Y
		"Z" , //A_LOW_Z
		"" , //A_OPEN_BRACE
		"|" , //A_BAR
		"" , //A_CLOSE_BRACE
		"~" , //A_TILDE
		"DEL" , //A_DELETE
		"EURO" , //A_EURO
		"RSHIFT" , //A_SHIFT2
		"RCTRL" , //A_CTRL2
		"RALT" , //A_ALT2
		"F5" , //A_F5
		"F6" , //A_F6
		"F7" , //A_F7
		"F8" , //A_F8
		"CIRCUMFLEX" , //A_CIRCUMFLEX
		"MWHEELUP" , //A_MWHEELUP
		"CAPS SCARON" , //A_CAP_SCARON
		"MWHEELDOWN" , //A_MWHEELDOWN
		"CAPS OE" , //A_CAP_OE
		"MOUSE1" , //A_MOUSE1
		"MOUSE2" , //A_MOUSE2
		"INS" , //A_INSERT
		"HOME" , //A_HOME
		"PGUP" , //A_PAGE_UP
		"''" , //A_RIGHT_SINGLE_QUOTE
		"''" , //A_LEFT_DOUBLE_QUOTE
		"''" , //A_RIGHT_DOUBLE_QUOTE
		"F9" , //A_F9,
		"F10" , //A_F10
		"F11" , //A_F11
		"F12" , //A_F12
		NULL , //A_TRADEMARK,
		NULL , //A_LOW_SCARON,
		"SHIFT_ENTER" , //A_ENTER
		NULL , //A_LOW_OE
		"END" , //A_END
		"PGDN" , //A_PAGE_DOWN,
		NULL , //A_CAP_YDIERESIS
		"SHIFT_SPACE" , //A_SPACE
		NULL , //A_EXCLAMDOWN
		NULL , //A_CENT
		NULL , //A_POUND
		"SHIFT_KP_ENTER" , //A_KP_ENTER
		NULL , //A_YEN
		"MOUSE3" , //A_MOUSE3
		"MOUSE4" , //A_MOUSE4
		"MOUSE5" , //A_MOUSE5
		NULL , //A_COPYRIGHT
		"UPARROW" , //A_CURSOR_UP
		"DOWNARROW" , //A_CURSOR_DOWN
		"LEFTARROW" , //A_CURSOR_LEFT
		"RIGHTARROW" , //A_CURSOR_RIGHT
		NULL , //A_REGISTERED
		NULL , //A_UNDEFINED_7
		NULL , //A_UNDEFINED_8
		NULL , //A_UNDEFINED_9
		NULL , //A_UNDEFINED_10
		NULL , //A_UNDEFINED_11
		NULL , //A_UNDEFINED_12
		NULL , //A_UNDEFINED_13
		NULL , //A_UNDEFINED_14
		NULL , //A_UNDEFINED_15
		NULL , //A_UNDEFINED_16
		NULL , //A_UNDEFINED_17
		NULL , //A_UNDEFINED_18
		NULL , //A_UNDEFINED_19
		NULL , //A_UNDEFINED_20
		NULL , //A_UNDEFINED_21
		NULL , //A_UNDEFINED_22
		NULL , //A_QUESTION_DOWN
		NULL , //A_CAP_AGRAVE
		NULL , //A_CAP_AACUTE
		NULL , //A_CAP_ACIRCUMFLEX
		NULL , //A_CAP_ATILDE
		NULL , //A_CAP_ADIERESIS
		NULL , //A_CAP_ARING
		NULL , //A_CAP_AE
		NULL , //A_CAP_CCEDILLA
		NULL , //A_CAP_EGRAVE
		NULL , //A_CAP_EACUTE
		NULL , //A_CAP_ECIRCUMFLEX
		NULL , //A_CAP_EDIERESIS
		NULL , //A_CAP_IGRAVE
		NULL , //A_CAP_IACUTE
		NULL , //A_CAP_ICIRCUMFLEX
		NULL , //A_CAP_IDIERESIS
		NULL , //A_CAP_ETH
		NULL , //A_CAP_NTILDE
		NULL , //A_CAP_OGRAVE
		NULL , //A_CAP_OACUTE
		NULL , //A_CAP_OCIRCUMFLEX
		NULL , //A_CAP_OTILDE
		NULL , //A_CAP_ODIERESIS
		"KP_STAR" , //A_MULTIPLY
		NULL , //A_CAP_OSLASH
		NULL , //A_CAP_UGRAVE
		NULL , //A_CAP_UACUTE
		NULL , //A_CAP_UCIRCUMFLEX
		NULL , //A_CAP_UDIERESIS
		NULL , //A_CAP_YACUTE
		NULL , //A_CAP_THORN
		NULL , //A_GERMANDBLS
		NULL , //A_LOW_AGRAVE
		NULL , //A_LOW_AACUTE
		NULL , //A_LOW_ACIRCUMFLEX
		NULL , //A_LOW_ATILDE
		NULL , //A_LOW_ADIERESIS
		NULL , //A_LOW_ARING
		NULL , //A_LOW_AE
		NULL , //A_LOW_CCEDILLA
		NULL , //A_LOW_EGRAVE
		NULL , //A_LOW_EACUTE
		NULL , //A_LOW_ECIRCUMFLEX
		NULL , //A_LOW_EDIERESIS
		NULL , //A_LOW_IGRAVE
		NULL , //A_LOW_IACUTE
		NULL , //A_LOW_ICIRCUMFLEX
		NULL , //A_LOW_IDIERESIS
		NULL , //A_LOW_ETH
		NULL , //A_LOW_NTILDE
		NULL , //A_LOW_OGRAVE
		NULL , //A_LOW_OACUTE
		NULL , //A_LOW_OCIRCUMFLEX
		NULL , //A_LOW_OTILDE
		NULL , //A_LOW_ODIERESIS
		"KP_SLASH" , //A_DIVIDE
		NULL , //A_LOW_OSLASH
		NULL , //A_LOW_UGRAVE
		NULL , //A_LOW_UACUTE
		NULL , //A_LOW_UCIRCUMFLEX
		NULL , //A_LOW_UDIERESIS
		NULL , //A_LOW_YACUTE
		NULL , //A_LOW_THORN
		NULL , //A_LOW_YDIERESIS
		"JOY0"  , //A_JOY0
		"JOY1"  , //A_JOY1
		"JOY2"  , //A_JOY2
		"JOY3"  , //A_JOY3
		"JOY4"  , //A_JOY4
		"JOY5"  , //A_JOY5
		"JOY6"  , //A_JOY6
		"JOY7"  , //A_JOY7
		"JOY8"  , //A_JOY8
		"JOY9"  , //A_JOY9
		"JOY10"  , //A_JOY10
		"JOY11"  , //A_JOY11
		"JOY12"  , //A_JOY12
		"JOY13"  , //A_JOY13
		"JOY14"  , //A_JOY14
		"JOY15"  , //A_JOY15
		"JOY16"  , //A_JOY16
		"JOY17"  , //A_JOY17
		"JOY18"  , //A_JOY18
		"JOY19"  , //A_JOY19
		"JOY20"  , //A_JOY20
		"JOY21"  , //A_JOY21
		"JOY22"  , //A_JOY22
		"JOY23"  , //A_JOY23
		"JOY24"  , //A_JOY24
		"JOY25"  , //A_JOY25
		"JOY26"  , //A_JOY26
		"JOY27"  , //A_JOY27
		"JOY28"  , //A_JOY28
		"JOY29"  , //A_JOY29
		"JOY30"  , //A_JOY30
		"JOY31"  , //A_JOY31
		"AUX0"  , //A_AUX0
		"AUX1"  , //A_AUX1
		"AUX2"  , //A_AUX2
		"AUX3"  , //A_AUX3
		"AUX4"  , //A_AUX4
		"AUX5"  , //A_AUX5
		"AUX6"  , //A_AUX6
		"AUX7"  , //A_AUX7
		"AUX8"  , //A_AUX8
		"AUX9"  , //A_AUX9
		"AUX10"  , //A_AUX10
		"AUX11"  , //A_AUX11
		"AUX12"  , //A_AUX12
		"AUX13"  , //A_AUX13
		"AUX14"  , //A_AUX14
		"AUX15"  , //A_AUX15
		"AUX16"  , //A_AUX16
		"AUX17"  , //A_AUX17
		"AUX18"  , //A_AUX18
		"AUX19"  , //A_AUX19
		"AUX20"  , //A_AUX20
		"AUX21"  , //A_AUX21
		"AUX22"  , //A_AUX22
		"AUX23"  , //A_AUX23
		"AUX24"  , //A_AUX24
		"AUX25"  , //A_AUX25
		"AUX26"  , //A_AUX26
		"AUX27"  , //A_AUX27
		"AUX28"  , //A_AUX28
		"AUX29"  , //A_AUX29
		"AUX30"  , //A_AUX30
		"AUX31"  , //A_AUX31
};

//functions
void CG_DrawJetpackFuelTribes();
void CG_TribesLabels();
void CG_TribesIFF(centity_t* cent, qhandle_t shader, float size);

void CG_DrawHudTribes(void);

typedef struct {
	int 		icon;
	int 		cost;
	qboolean 	isActive;
	qboolean 	isOnCooldown;
	int 		power;
} tribesPack;

#define PACK_SHIELD 	2
#define PACK_THRUST 	3
#define PACK_BLINK 		4
#define PACK_OVERDRIVE 	5

#define CYCLE_FIRST_WEAPON 1
#define CYCLE_LAST_USEABLE_WEAPON WP_NUM_WEAPONS
#define CYCLE_SMALL_ICON_SIZE 30
#define CYCLE_BIG_ICON_SIZE 40
#define CYCLE_PAD (-8)
#define CYCLE_X_POS 585
#define CYCLE_Y_POS 450
#define CYCLE_TEXT_SIZE 0.6f
void CG_DrawWeaponSelectTribes();
qboolean IsWeaponSelectable(int weapon);
#if 0
static const int weaponCycleOrder[] = {
		WP_STUN_BATON,
		WP_MELEE,
		WP_SABER,
		WP_BRYAR_PISTOL,
		WP_BLASTER,
		WP_DISRUPTOR,
		WP_BOWCASTER,
		WP_REPEATER,
		WP_DEMP2,
		WP_FLECHETTE,
		WP_CONCUSSION,
		WP_ROCKET_LAUNCHER,
		WP_THERMAL,
		WP_TRIP_MINE,
		WP_DET_PACK,
		WP_BRYAR_OLD,
		WP_EMPLACED_GUN,
		WP_TURRET
};
#endif

static const int weaponCycleOrder[] = {
		//slot1
		WP_BOWCASTER, //light
		WP_CONCUSSION, //medium
		WP_ROCKET_LAUNCHER, //heavy
		//slot2
		WP_BRYAR_OLD,
		WP_BLASTER,
		WP_REPEATER,
		//slot3
		WP_DISRUPTOR,
		WP_FLECHETTE,
		WP_DEMP2,
		//throwable
		WP_THERMAL,
		WP_STUN_BATON,
		WP_TRIP_MINE,
		//saber
		WP_SABER,
};

static float currentFuel = 100.0f;

#endif //HUD_TRIBES_H
