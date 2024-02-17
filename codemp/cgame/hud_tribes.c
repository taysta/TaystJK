#include "hud_tribes.h"

void CG_DrawJetpackFuelTribes(void)
{
	vec4_t aColor;
	float x = JETFUEL_X - (JETFUEL_W * 0.5f);

	float targetPercent = ((float)cg.predictedPlayerState.fd.forcePower / 100);

	currentFuel += (targetPercent - currentFuel) * LERP_JETPACK;
	float percent = fmaxf(fminf(currentFuel, 1.0f), 0);

	if (percent < 0.2f) {
		aColor[0] = 0.651f;
		aColor[1] = 0.188f;
		aColor[2] = 0.173f;
		aColor[3] = 1.0f;
	}
	else {
		aColor[0] = 0.098f;
		aColor[1] = 0.506f;
		aColor[2] = 0.667f;
		aColor[3] = 1.0f;
	}

	int numBars = JETPACK_NUM_BARS;
	float barGap = JETPACK_BAR_GAP;
	float totalSpacing = barGap * (float)(numBars - 1);
	float barWidth = (JETFUEL_W - totalSpacing) / (float)numBars;
	for (int i = 0; i < numBars; i++) {
		float barX = x + (float)i * (barWidth + barGap);
		float barThreshold = (float)(i + 1) / (float)numBars;
		float filledWidth;

		if (percent >= barThreshold) {
			filledWidth = barWidth;
		}
		else if (percent > (float)i / (float)numBars) {
			filledWidth = barWidth * (percent * (float)numBars - (float)i);
		}
		else {
			continue;
		}

		CG_FillRect(barX, JETFUEL_Y, filledWidth, JETFUEL_H, aColor);
	}
#if 0
	trap->R_SetColor(aColor);
	CG_DrawNumField(JETFUEL_X - 12, JETFUEL_Y + 5.0f * JETFUEL_H, 3, Q_max(Q_min(cg.predictedPlayerState.jetpackFuel, 100), 0), 3, 8, NUM_FONT_SMALL, qfalse);
	trap->R_SetColor(NULL);
#endif
}

/* TRIBES IFFS */

//draw the health bar based on current "health" and maxhealth
void CG_DrawTribesHealthBar(centity_t* cent, float chX, float chY, float chW, float chH)
{
	vec4_t aColor;
	vec4_t cColor;

	float x = chX + ((chW / 2) - (50.0f / 2)) * cgs.widthRatioCoef;
	float y = (chY + chH) + 8.0f;
	float percent;

	if (cent->currentState.maxhealth)
		percent = ((float)cent->currentState.health / (float)cent->currentState.maxhealth) * 50.0f * cgs.widthRatioCoef;
	else
		percent = 49.0f * cgs.widthRatioCoef;

	if (percent <= 0)
	{
		return;
	}

	//color of the bar
	if (!cent->currentState.teamowner || cgs.gametype < GT_TEAM)
	{ //not owned by a team or teamplay
		aColor[0] = 1.0f;
		aColor[1] = 1.0f;
		aColor[2] = 0.0f;
		aColor[3] = 0.4f;
	}
	else if (cent->currentState.teamowner == cg.predictedPlayerState.persistant[PERS_TEAM])
	{ //owned by my team
		aColor[0] = 0.0f;
		aColor[1] = 1.0f;
		aColor[2] = 0.0f;
		aColor[3] = 0.4f;
	}
	else
	{ //hostile
		aColor[0] = 1.0f;
		aColor[1] = 0.0f;
		aColor[2] = 0.0f;
		aColor[3] = 0.4f;
	}

	//color of greyed out "missing health"
	cColor[0] = 0.5f;
	cColor[1] = 0.5f;
	cColor[2] = 0.5f;
	cColor[3] = 0.4f;

	//draw the background (black)
	CG_DrawRect(x, y, 50.0f * cgs.widthRatioCoef, 5.0f, 1.0f, colorTable[CT_BLACK]);

	//now draw the part to show how much health there is in the color specified
	//-2.0 instead of -1.0. regular healthbar function has border overlap so fix it
	CG_FillRect(x + 1.0f * cgs.widthRatioCoef, y + 1.0f, percent - 1.0f * cgs.widthRatioCoef, 5.0f - 2.0f, aColor);

	//then draw the other part greyed out
	CG_FillRect(x + percent, y + 1.0f, (50.0f - 1.0f) * cgs.widthRatioCoef - percent, 5.0f - 1.0f, cColor);
}

void CG_TribesLabels(void) { //Todo, set a flag in cg_players to base this on, so we don't have to calculate all this?
	int i;

	for (i = 0; i < MAX_CLIENTS; i++) {
		vec3_t pos;
		float x, y;
		trace_t trace;
		centity_t *cent = &cg_entities[i];

		if (!cent || !cent->currentValid || !cent->drawingIFF)
			continue;

		if (CG_IsMindTricked(cent->currentState.trickedentindex,
							 cent->currentState.trickedentindex2,
							 cent->currentState.trickedentindex3,
							 cent->currentState.trickedentindex4,
							 cg.snap->ps.clientNum))
			continue;

		CG_Trace(&trace, cg.predictedPlayerState.origin, NULL, NULL, cent->lerpOrigin, cg.clientNum,
				 CONTENTS_SOLID | CONTENTS_BODY);
		if (trace.entityNum == ENTITYNUM_WORLD)
			continue;

		VectorCopy(cent->lerpOrigin, pos);
		pos[2] += 64;

		if (!CG_WorldCoordToScreenCoord(pos, &x, &y)) //off-screen, don't draw it
			continue;

		CG_DrawScaledProportionalString(x, y, cgs.clientinfo[i].name, UI_CENTER, colorTable[CT_WHITE],
										cg_drawPlayerNamesScale.value);

		CG_DrawTribesHealthBar(cent, x, y - 16, 1, 1);
	}
}

void CG_TribesIFF(centity_t* cent, qhandle_t shader, float size) {
	int				rf;
	refEntity_t		ent;
	float offset = size * 2.5f;
	if (offset < 42)
		offset = 42;

	if (cent->currentState.number == cg.snap->ps.clientNum && !cg.renderingThirdPerson) {
		rf = RF_THIRD_PERSON;		// only show in mirrors
	}
	else {
		rf = 0;
	}

	memset(&ent, 0, sizeof(ent));
	VectorCopy(cent->lerpOrigin, ent.origin);
	ent.origin[2] += offset;
	ent.reType = RT_SPRITE;
	ent.customShader = shader;
	ent.radius = size;
	ent.renderfx = rf;
	ent.shaderRGBA[0] = 255;
	ent.shaderRGBA[1] = 255;
	ent.shaderRGBA[2] = 255;
	ent.shaderRGBA[3] = 255;
	trap->R_AddRefEntityToScene(&ent);
}

/* Weapon Cycle */

qboolean WeaponCheck(int weap) {
    return (cg.snap->ps.ammo[weaponData[weap].ammoIndex] >= weaponData[weap].energyPerShot ||
            cg.snap->ps.ammo[weaponData[weap].ammoIndex] >= weaponData[weap].altEnergyPerShot) ? qtrue : qfalse;
}

qboolean IsWeaponSelectable(int weapon) {
    return (cg.predictedPlayerState.stats[STAT_WEAPONS] & (1 << weapon)) ? qtrue : qfalse;
}

int CountWeapons(int bits) {
    int count = 0;
    for (int i = CYCLE_FIRST_WEAPON; i < CYCLE_LAST_USEABLE_WEAPON; i++) {
        if (bits & (1 << i)) {
            count++;
        }
    }
    return count;
}

int WeaponIcon(int i) {
    if (i == WP_SABER) {
        if (cg.predictedPlayerState.fd.saberDrawAnimLevel == SS_STAFF) {
            return cgs.media.weaponIconsStaff;
        } else if (cg.predictedPlayerState.fd.saberDrawAnimLevel == SS_DUAL) {
            return cgs.media.weaponIconsAkimbo;
        }
    }
    return cgs.media.weaponIcons[i];
}

void DrawWeaponIcon(int weapon, int posX, int posY, int size, int slotNumber) {
	vec4_t onColor, offColor, noAmmoColor;

	onColor[0] = 1.0f;
	onColor[1] = 1.0f;
	onColor[2] = 1.0f;
	onColor[3] = 1.0f;

	offColor[0] = 0.5f;
	offColor[1] = 0.5f;
	offColor[2] = 0.5f;
	offColor[3] = 0.8f;

	noAmmoColor[0] = 0.0f;
	noAmmoColor[1] = 0.0f;
	noAmmoColor[2] = 0.0f;
	noAmmoColor[3] = 0.8f;

    if (!cgs.media.weaponIcons[weapon]) {
        return; // If no icon exists for this weapon, don't draw anything
    }

    CG_RegisterWeapon(weapon);
	if(weapon != cg.weaponSelect){
		trap->R_SetColor(offColor);
	} else {
		trap->R_SetColor(onColor);
	}

    if (!WeaponCheck(weapon)) {
        CG_DrawPic((float)posX, (float)posY, (float)size * cgs.widthRatioCoef,
				   (float)size, cgs.media.weaponIcons_NA[weapon]);
    } else {
        CG_DrawPic((float)posX, (float)posY, (float)size * cgs.widthRatioCoef,
				   (float)size, WeaponIcon(weapon));
    }

    if ((weapon != WP_SABER) && (weapon != WP_MELEE) && (weapon != WP_STUN_BATON) && (weapon != WP_BRYAR_PISTOL)
		&& cg_weaponCycleAmmo.integer) {
        int value = cg.predictedPlayerState.ammo[weaponData[weapon].ammoIndex];
        char ammoStr[MAX_QPATH];
        Com_sprintf(ammoStr, sizeof(ammoStr), "%i", value);

        float scale = (float)size / CYCLE_SMALL_ICON_SIZE; // Calculate the scale factor
        float textSize = CYCLE_TEXT_SIZE * scale; // Apply the scale factor to the text size

        vec4_t color;
        if (!WeaponCheck(weapon))
		{
			if(weapon != cg.weaponSelect){
				Vector4Copy(noAmmoColor, color);
			} else {
				Vector4Copy(onColor, color);
			}
        } else
		{
			if(weapon != cg.weaponSelect){
				Vector4Copy(offColor, color);
			} else {
				Vector4Copy(onColor, color);
			}
		}

        CG_Text_Paint((float)posX - 1.5f * CG_Text_Width(ammoStr, textSize, FONT_SMALL2),
					  (float)posY + 0.5f * (float)size - 0.5f * (float)CG_Text_Height(ammoStr, textSize, FONT_SMALL2),
			  textSize,
			  color,
			  ammoStr,
			  0.0f,
			  0,
			  3,
			  FONT_SMALL2);
    }

	char slotCommand[MAX_QPATH];
	Com_sprintf(slotCommand, sizeof(slotCommand), "slot %d", slotNumber);

	if (keyCodeNames[trap->Key_GetKey(slotCommand)] != NULL) {
		char keyStr[MAX_QPATH];
		Com_sprintf(keyStr, sizeof(keyStr), "%s", keyCodeNames[trap->Key_GetKey(slotCommand)]);

		CG_Text_Paint(CYCLE_X_POS + 2.0f,
					  (float)posY + 0.5f * (float)size - 0.5f * (float)CG_Text_Height(keyStr, 0.5f, FONT_SMALL2),
					  0.5f,
					  colorWhite,
					  keyStr,
					  0.0f,
					  0,
					  3,
					  FONT_SMALL2);
	}

	if(weapon == cg.weaponSelect) {
		char fireModeCommand[MAX_QPATH];
		char fireCommand[MAX_QPATH];
		Com_sprintf(fireModeCommand, sizeof(fireModeCommand), "selectfiremode", slotNumber);
		Com_sprintf(fireCommand, sizeof(fireCommand), "+singlefire", slotNumber);
		if ((keyCodeNames[trap->Key_GetKey(fireModeCommand)] != NULL)
			&& (keyCodeNames[trap->Key_GetKey(fireCommand)] != NULL) ) {
			char keyStr[MAX_QPATH];
			char modeStr[MAX_QPATH];
			if ((!cg.singlefireAlt && (weapon != WP_BOWCASTER)
			|| (cg.singlefireAlt && (weapon == WP_BOWCASTER))
			|| (weapon == WP_THERMAL))) {
				//primary fire text
				Com_sprintf(modeStr, sizeof(modeStr), "Primary Fire");
				//primary fire image
				CG_DrawPic((float)posX,
						   (float)posY - (float)CYCLE_PAD + 0.5f * (float)size - 0.5f * 12.0f,
						   12.0f * cgs.widthRatioCoef,
						   12.0f,
						   cgs.media.keyAttackOn2);
			} else {
				Com_sprintf(modeStr, sizeof(modeStr), "Alternate Fire");
				CG_DrawPic((float)posX,
						   (float)posY - (float)CYCLE_PAD + 0.5f * (float)size - 0.5f * 12.0f,
						   12.0f * cgs.widthRatioCoef,
						   12.0f,
						   cgs.media.keyAltOn2);

			}
			Com_sprintf(keyStr, sizeof(keyStr), "%s", keyCodeNames[trap->Key_GetKey(fireModeCommand)]);

			//keybind text
			CG_Text_Paint((float)posX - CG_Text_Width(keyStr, 0.4f, FONT_SMALL2),
						  (float)posY - (float)CYCLE_PAD + 0.5f * (float)size -
						  0.5f * (float)CG_Text_Height(keyStr, 0.4f, FONT_SMALL2),
						  0.4f,
						  colorWhite,
						  keyStr,
						  0.0f,
						  0,
						  3,
						  FONT_SMALL2);

			//firemode text
			CG_Text_Paint((float)posX + 0.5f * (float)size - 0.5f * CG_Text_Width(modeStr, 0.4f, FONT_SMALL2),
						  (float)posY - (float)CYCLE_PAD + 0.5f * (float)size -
						  0.5f * (float)CG_Text_Height(modeStr, 0.4f, FONT_SMALL2),
						  0.4f,
						  colorWhite,
						  modeStr,
						  0.0f,
						  0,
						  3,
						  FONT_SMALL2);
		}
	}
	trap->R_SetColor(NULL);
}

void CG_DrawWeaponSelectTribes(void) {
	if (cg.predictedPlayerState.stats[STAT_HEALTH] <= 0) {
		return; // Don't display if dead
	}

	int bits = cg.predictedPlayerState.stats[STAT_WEAPONS];
	int count = CountWeapons(bits);
	if (count <= 1) {
		return; // If only the current weapon is available, don't draw additional slots
	}

	int smallIconSize = CYCLE_SMALL_ICON_SIZE;
	int bigIconSize = CYCLE_BIG_ICON_SIZE;
	int pad = CYCLE_PAD;
	int xRightMost = CYCLE_X_POS; // Rightmost position
	int totalHeight = 0;

	int weaponOrderSize = sizeof(weaponCycleOrder) / sizeof(weaponCycleOrder[0]);

	// Calculate the total height required for all weapon icons
	for (int i = 0; i < weaponOrderSize; i++) {
		int weapon = weaponCycleOrder[i];
		if ((bits & (1 << weapon)) && IsWeaponSelectable(weapon)) {
			totalHeight += (weapon == cg.weaponSelect) ? bigIconSize : smallIconSize;
			totalHeight += pad; // Add padding between icons
		}
	}

	// Starting y position from the bottom
	int yStart = CYCLE_Y_POS - totalHeight;

	int slotNumber = 1;  // Start from slot 1
	for (int i = 0; i < weaponOrderSize; i++) {
		int weapon = weaponCycleOrder[i];
		if ((bits & (1 << weapon)) && IsWeaponSelectable(weapon)) {
			int iconSize = (weapon == cg.weaponSelect) ? bigIconSize : smallIconSize;
			int xPosition = xRightMost - iconSize; // Align to the right
			DrawWeaponIcon(weapon, xPosition, yStart, iconSize, slotNumber);
			yStart += iconSize + pad; // Move up for the next icon
			slotNumber++;  // Increment slot number for next weapon
		}
	}
}

tribesPack CG_TribesPack() {
	tribesPack packOut;
	int powerSelected = cg.predictedPlayerState.fd.forcePowerSelected;
	int iconOut;
	int costOut;
	int powerOut;
	qboolean isActiveOut = qfalse; 	//isActive
	qboolean isOnCooldownOut = qfalse; 	//isOnCooldown
	switch(powerSelected){
		default:
		case PACK_SHIELD:
			powerOut = FP_PROTECT;
			iconOut = FP_PROTECT;
			costOut = 40;
			break;
		case PACK_THRUST:
			powerOut = FP_SPEED;
			iconOut = FP_SPEED;
			costOut = 0;
			break;
		case PACK_BLINK:
			powerOut = FP_RAGE;
			iconOut = FP_PUSH;
			costOut = 25;
			break;
		case PACK_OVERDRIVE:
			powerOut = FP_ABSORB;
			iconOut = FP_RAGE;
			costOut = 25;
			break;
	}

	if ((cg.predictedPlayerState.fd.forcePowersActive & (1 << powerOut)) && CG_IsDurationPower(powerOut))
	{
		isActiveOut = qtrue;
	}

	if ((powerOut == FP_RAGE) && (isActiveOut == qfalse) && (cg.predictedPlayerState.fd.forceRageRecoveryTime > cg.time))
	{
		isOnCooldownOut = qtrue;
	}
	packOut.pack = powerSelected;
	packOut.power = powerOut;
	packOut.icon = iconOut;
	packOut.cost = costOut;
	packOut.isActive = isActiveOut;
	packOut.isOnCooldown = isOnCooldownOut;
	return packOut;
}

/* Tribes Ability Icons */

void CG_DrawPackTribes(void){

	float boxSize = ABILITY_OUTER_BOX_SIZE;
	float iconSize = ABILITY_ICON_SIZE;
	float x = 0.5f * SCREEN_WIDTH;
	float y = JETFUEL_Y - ( 1.5f * boxSize );
	float centerOffset = ABILITY_CENTER_OFFSET;

	char packBind[MAX_QPATH];
	Com_sprintf(packBind, sizeof(packBind), "+force_lightning");
	char grappleBind[MAX_QPATH];
	Com_sprintf(grappleBind, sizeof(grappleBind), "+grapple");

	vec4_t color;
	vec4_t iconColor;

	iconColor[0] = 1.0f;
	iconColor[1] = 1.0f;
	iconColor[2] = 1.0f;
	iconColor[3] = 0.8f;
	tribesPack pack = CG_TribesPack();

	if(pack.isActive == qtrue)
	{
		if((keyCodeNames[trap->Key_GetKey(packBind)] != NULL) && (trap->Key_IsDown(trap->Key_GetKey(packBind))))
		{
			color[0] = 0.0f;
			color[1] = 0.5f;
			color[2] = 0.0f;
			color[3] = 0.7f;
		} else {
			color[0] = 0.0f;
			color[1] = 0.3f;
			color[2] = 0.0f;
			color[3] = 0.6f;
		}
	} else if ((cg.predictedPlayerState.fd.forcePower < pack.cost) || (pack.isOnCooldown == qtrue)
	|| ((pack.pack == PACK_BLINK) && (cg.predictedPlayerState.powerups[PW_REDFLAG]
									|| cg.predictedPlayerState.powerups[PW_BLUEFLAG]
									|| cg.predictedPlayerState.powerups[PW_NEUTRALFLAG])))
	{
		if((keyCodeNames[trap->Key_GetKey(packBind)] != NULL) && (trap->Key_IsDown(trap->Key_GetKey(packBind))))
		{
			color[0] = 0.5f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			color[3] = 0.7f;
		} else {
			color[0] = 0.3f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			color[3] = 0.6f;
		}
	} else {
		if((keyCodeNames[trap->Key_GetKey(packBind)] != NULL) && (trap->Key_IsDown(trap->Key_GetKey(packBind)))) {
			color[0] = 0.3f;
			color[1] = 0.3f;
			color[2] = 0.3f;
			color[3] = 0.7f;
		} else {
			color[0] = 0.1f;
			color[1] = 0.1f;
			color[2] = 0.1f;
			color[3] = 0.6f;
		}
	}
	//pack icon
	//box
	CG_FillRect(x - ((boxSize * cgs.widthRatioCoef))
	- centerOffset, y, boxSize * cgs.widthRatioCoef, boxSize, color);
	//icon
	trap->R_SetColor(iconColor);
	CG_DrawPic(x - (boxSize * cgs.widthRatioCoef)
	+ (0.5f * (boxSize * cgs.widthRatioCoef - iconSize * cgs.widthRatioCoef)) - centerOffset,
			   y + ((0.5f * boxSize) - (0.5f * iconSize)),
			   iconSize * cgs.widthRatioCoef,
			   iconSize,
			   cgs.media.forcePowerIcons[pack.icon]);
	trap->R_SetColor(NULL);

	//bind
	if (keyCodeNames[trap->Key_GetKey(packBind)] != NULL) {
		char keyStr[MAX_QPATH];
		Com_sprintf(keyStr, sizeof(keyStr), "%s", keyCodeNames[trap->Key_GetKey(packBind)]);

		CG_Text_Paint(x - (0.5f * (boxSize * cgs.widthRatioCoef))
		- (0.5f * CG_Text_Width(keyStr, 0.5f, FONT_SMALL2) * cgs.widthRatioCoef) - centerOffset,
					  y + boxSize - (0.5f * (float)CG_Text_Height(keyStr, 0.5f, FONT_SMALL2)),
					  0.5f,
					  colorWhite,
					  keyStr,
					  0.0f,
					  0,
					  3,
					  FONT_SMALL2);
	}

	//grapple
	if(cg.predictedPlayerState.fd.forcePower < COST_GRAPPLE_TRIBES){
		if((keyCodeNames[trap->Key_GetKey(grappleBind)] != NULL) && (trap->Key_IsDown(trap->Key_GetKey(grappleBind)))){
			color[0] = 0.5f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			color[3] = 0.7f;
		} else {
			color[0] = 0.3f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			color[3] = 0.6f;
		}
	} else {
		if((keyCodeNames[trap->Key_GetKey(grappleBind)] != NULL) && (trap->Key_IsDown(trap->Key_GetKey(grappleBind)))){
			color[0] = 0.3f;
			color[1] = 0.3f;
			color[2] = 0.3f;
			color[3] = 0.7f;
		} else {
			color[0] = 0.1f;
			color[1] = 0.1f;
			color[2] = 0.1f;
			color[3] = 0.6f;
		}
	}

	//box
	CG_FillRect(x + centerOffset, y, boxSize * cgs.widthRatioCoef, boxSize, color);
	//icon
	trap->R_SetColor(iconColor);
	CG_DrawPic(x + (0.5f * (boxSize * cgs.widthRatioCoef - iconSize * cgs.widthRatioCoef)) + centerOffset,
			   y + ((0.5f * boxSize) - (0.5f * iconSize)),
			   iconSize * cgs.widthRatioCoef,
			   iconSize,
			   cgs.media.mAutomapPlayerIcon);
	trap->R_SetColor(NULL);

	//bind
	if (keyCodeNames[trap->Key_GetKey(grappleBind)] != NULL) {
		char keyStr[MAX_QPATH];
		Com_sprintf(keyStr, sizeof(keyStr), "%s", keyCodeNames[trap->Key_GetKey(grappleBind)]);

		CG_Text_Paint(x + (0.5f *
		(boxSize * cgs.widthRatioCoef - CG_Text_Width(keyStr, 0.5f, FONT_SMALL2) * cgs.widthRatioCoef)) + centerOffset,
					  y + boxSize - (0.5f * (float)CG_Text_Height(keyStr, 0.5f, FONT_SMALL2)),
					  0.5f,
					  colorWhite,
					  keyStr,
					  0.0f,
					  0,
					  3,
					  FONT_SMALL2);
	}
}

/* Tribes Health Bar */

void CG_DrawHealthTribes(void)
{
	playerState_t	*ps;
	int				healthAmt;
	float           percent;
	float 			barHeight = HEALTH_H;
	float 			x = HEALTH_X;
	float 			y = HEALTH_Y;
	char            healthStr[MAX_QPATH]= {0};
	char            maxHealthStr[MAX_QPATH]= {0};
	vec4_t			color;
	color[0] = 1.0f;
	color[1] = 1.0f;
	color[2] = 1.0f;
	color[3] = 0.7f;
	ps = &cg.predictedPlayerState;

	healthAmt = ps->stats[STAT_HEALTH];
	Com_Clampi(0, ps->stats[STAT_MAX_HEALTH], healthAmt);
	percent = ((float)healthAmt / (float)ps->stats[STAT_MAX_HEALTH]);

	int numBars = ps->stats[STAT_MAX_HEALTH] / 100;
	float barGap = HEALTH_GAP;
	float barWidth = HEALTH_W;
	for (int i = 0; i < numBars; i++) {
		float barX = x + (float)i * (barWidth + barGap);
		float  barThreshold = (float)(i + 1) / (float)numBars;
		float filledWidth;

		if (percent >= barThreshold) {
			filledWidth = barWidth;
		}
		else if (percent > (float)i / (float)numBars) {
			float partial = percent * (float)ps->stats[STAT_MAX_HEALTH] - (float)i * 100;
			filledWidth = barWidth * (partial / 100.0f);
		}
		else {
			continue;
		}

		CG_FillRect(barX * cgs.widthRatioCoef, (float)y, filledWidth * cgs.widthRatioCoef, (float)barHeight, colorWhite);
	}

	// Print the numeric amount
	if(healthAmt > 0) {
		Com_sprintf(healthStr, sizeof(healthStr), "%i", healthAmt);
		CG_Text_Paint(x * cgs.widthRatioCoef,
					  y - 1.5f * (float) CG_Text_Height(healthStr, 1.0f, FONT_MEDIUM),
					  1.0f,
					  colorTable[CT_WHITE],
					  healthStr,
					  0.0f,
					  0,
					  3,
					  FONT_MEDIUM);
		Com_sprintf(maxHealthStr, sizeof(maxHealthStr), " / %i", ps->stats[STAT_MAX_HEALTH]);
		CG_Text_Paint(x * cgs.widthRatioCoef + (float)CG_Text_Width(healthStr, 1.0f, FONT_MEDIUM),
					  y - 1.5f * (float) CG_Text_Height(maxHealthStr, 0.8f, FONT_MEDIUM),
					  0.8f,
					  color,
					  maxHealthStr,
					  0.0f,
					  0,
					  3,
					  FONT_MEDIUM);
	}
}

void CG_DrawHudTribes(void)
{
	CG_DrawJetpackFuelTribes();
	CG_DrawWeaponSelectTribes();
	CG_DrawPackTribes();
	CG_DrawHealthTribes();
}