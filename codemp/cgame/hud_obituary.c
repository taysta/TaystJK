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

static int killfeedAlignment;
static obituary_t hudObituary[MAX_OBITUARY];
static int hudNumObituary;
static float kfXOffset, kfYOffset, kfTextSize, kfIconSize;
void HUD_InitObituary(void) {
    hudNumObituary = 0;
}

void HUD_InitKFAlignment(void) {
    killfeedAlignment = cg_killfeedAlignment.integer;
    kfXOffset = cg_killfeedX.value;
    kfYOffset = cg_killfeedY.value;
    kfIconSize = cg_killfeedIconSize.value;
    kfTextSize = cg_killfeedTextSize.value;
}

static void HUD_PurgeObituary(void) {
    static obituary_t obituary[MAX_OBITUARY];
    int i, numObituary;
    memcpy(obituary, hudObituary, sizeof(obituary));
    numObituary = 0;
    for (i = 0; i < hudNumObituary; i++) {
        if (cg.time - obituary[i].time > OBITUARY_TIMEOUT) {
            continue;
        }
        memcpy( &hudObituary[numObituary], &obituary[i], sizeof(obituary_t));
        numObituary++;
    }
    hudNumObituary = numObituary;
}

void HUD_DrawObituary(void) {
    static float color[4] = {1.0f,1.0f,1.0f,1.0f};
    static float blueTeam[4] = {0.0f,0.0f,1.0f,0.15f};
    static float redTeam[4] = {1.0f,0.0f,0.0f,0.15f};
    static float playerColor[4] = {0.0f,1.0f,0.0f,0.15f};
    static float neutralColor[4] = {0.6f,0.6f,0.6f, 0.15f };
    float x, y, iconSize, iconHeight, iconWidth, padding, xPadding, yPadding, textScale, textHeight, leftTextHeight, rightTextHeight, boxCenterY, boxCenterX;
    float wepColor[4] = { 0 }, leftColor[4] = { 0 }, rightColor[4] = { 0 };
    float leftTextWidth, rightTextWidth, totalWidth, maxHeight, rightTextStartY, leftTextStartY;
    int leftClient, rightClient, c;
    qboolean suicide, reverse;
    obituary_t *p;
    qhandle_t deathIcon;

	if (!cg.snap)
		return;

    HUD_PurgeObituary();

    // "victim killed by killer" reads right to left, which is what most JKA players are used to
    reverse = cg_killfeedReverse.integer ? qtrue : qfalse;

    // Set up the killfeed
    if(cg_killfeedIconSize.value)
        iconSize = kfIconSize;
    else
        iconSize = OBITUARY_ICON_SIZE;

    if(cg_killfeedTextSize.value)
        textScale = kfTextSize;
    else
        textScale = OBITUARY_TEXT_SIZE;

    y = 10.0f + kfYOffset;
    padding = OBITUARY_PADDING_SCALAR;
    iconWidth = (iconSize * cgs.widthRatioCoef);
    iconHeight = iconSize;

    for (p = hudObituary; p < hudObituary + hudNumObituary; p++) {
        // Set the method of death icon
        if(hm.modIcon[p->mod])
            deathIcon = hm.modIcon[p->mod];
        else
            deathIcon = hm.modIcon[MOD_UNKNOWN];
        // Set the icons' color
        if(cg_killfeedColors.integer){
            wepColor[0] = hudModColors[p->mod][0];
            wepColor[1] = hudModColors[p->mod][1];
            wepColor[2] = hudModColors[p->mod][2];
        } else {
            wepColor[0] = color[0];
            wepColor[1] = color[0];
            wepColor[2] = color[0];
        }

        suicide = ((p->killer == p->victim) || (p->killer == ENTITYNUM_WORLD)) ? qtrue : qfalse;

        if (suicide) {
            leftClient = rightClient = p->victim;
        } else {
            leftClient  = reverse ? p->victim : p->killer;
            rightClient = reverse ? p->killer : p->victim;
        }

        // Set the box colors based on game type
        for (c = 0; c < 2; c++) {
            int client = c ? rightClient : leftClient;
            float *slotColor = c ? rightColor : leftColor;

            // Use a neutral grey color
            Vector4Copy(neutralColor, slotColor);

            if (client == ENTITYNUM_WORLD) {
                continue;
            }

            if (cgs.gametype >= GT_TEAM) {
                if (cgs.clientinfo[client].team == TEAM_BLUE) {
                    Vector4Copy(blueTeam, slotColor);
                } else if (cgs.clientinfo[client].team == TEAM_RED) {
                    Vector4Copy(redTeam, slotColor);
                }
            }

            // Check if it's the local player
            if (client == cg.snap->ps.clientNum) {
                Vector4Copy(playerColor, slotColor);
            }
        }

        // Fade the obituaries
        if (cg.time - p->time > OBITUARY_FADEOUTTIME) {
            color[3] = 1.0f - ((float)cg.time - (float)p->time - OBITUARY_FADEOUTTIME) / (OBITUARY_TIMEOUT - OBITUARY_FADEOUTTIME);
        } else {
            color[3] = 1.0f;
        }
        // Only fade the boxes if the new fade is less than our current opacity
        leftColor[3] = fminf(0.25f * color[3], leftColor[3]);
        rightColor[3] = fminf(0.25f * color[3], rightColor[3]);
        wepColor[3] = color[3];

        //Get the sizes of everything
        rightTextWidth = CG_Text_Width(cgs.clientinfo[rightClient].name, textScale, FONT_MEDIUM);
        rightTextHeight = (float)CG_Text_Height(cgs.clientinfo[rightClient].name, textScale, FONT_MEDIUM);

        if (suicide) {
            leftTextWidth = 0.0f;
            leftTextHeight = 0.0f;
            textHeight = rightTextHeight;
        } else {
            leftTextWidth = CG_Text_Width(cgs.clientinfo[leftClient].name, textScale, FONT_MEDIUM);
            leftTextHeight = (float)CG_Text_Height(cgs.clientinfo[leftClient].name, textScale, FONT_MEDIUM);
            textHeight = fmaxf(leftTextHeight, rightTextHeight);
        }

        maxHeight = fmaxf(iconHeight, textHeight);
        xPadding = (padding * maxHeight * cgs.widthRatioCoef);
        yPadding = (padding * maxHeight);
        boxCenterY = y + ((maxHeight + yPadding) / 2.0f);
        rightTextStartY = boxCenterY - 0.75f * rightTextHeight;
        boxCenterX = ((maxHeight * cgs.widthRatioCoef + xPadding) / 2.0f);
        if(!suicide) {
            leftTextStartY = boxCenterY - 0.75f * leftTextHeight;
            totalWidth = leftTextWidth + rightTextWidth + (3.0f * xPadding) + (2.0f * boxCenterX);
        } else {
            leftTextStartY = 0.0f;
            totalWidth = rightTextWidth + (1.5f * xPadding) + (2.0f * boxCenterX);
        }
        //offset the allignment
        switch (killfeedAlignment){
            case KF_RIGHT:
                x = SCREEN_WIDTH - totalWidth - (10.0f + kfXOffset) * cgs.widthRatioCoef;
                break;
            case KF_LEFT:
                x = (10.0f + kfXOffset) * cgs.widthRatioCoef;
                break;
            case KF_CENTER:
                x = (SCREEN_WIDTH - totalWidth) * 0.5f + kfXOffset;
                break;
            default:
                x = kfXOffset;
        }

        //Draw the killfeed
        if(!suicide) {
            CG_FillRect(x, y, leftTextWidth + xPadding, maxHeight + yPadding, leftColor);
            CG_Text_Paint(x + 0.5f * xPadding, leftTextStartY, textScale, color, cgs.clientinfo[leftClient].name, 0, 0, 0, FONT_MEDIUM);
            x += leftTextWidth + xPadding;
        }
        trap->R_SetColor(wepColor);
        CG_DrawPic(x + boxCenterX - 0.5f * iconWidth, boxCenterY - 0.5f * iconHeight, iconWidth, iconHeight, deathIcon);
        trap->R_SetColor(NULL);
        x += (boxCenterX * 2.0f);
        CG_FillRect(x, y, rightTextWidth + xPadding, maxHeight + yPadding, rightColor);
        CG_Text_Paint(x + (0.5f * xPadding), rightTextStartY, textScale, color, cgs.clientinfo[rightClient].name, 0, 0, 0, FONT_MEDIUM);

        y += maxHeight + yPadding;
    }
}

void CG_AddObituary(int killer, int victim, meansOfDeath_t mod) {
    int i;
    HUD_InitKFAlignment();
    if (hudNumObituary == MAX_OBITUARY) {
        for (i = 0; i < MAX_OBITUARY - 1; i++) {
            memcpy(&hudObituary[i], &hudObituary[i + 1], sizeof(obituary_t));
        }
        hudNumObituary--;
    }
    hudObituary[hudNumObituary].killer = killer;
    hudObituary[hudNumObituary].victim = victim;
    hudObituary[hudNumObituary].mod = mod;
    hudObituary[hudNumObituary].time = cg.time;
    hudNumObituary++;
}