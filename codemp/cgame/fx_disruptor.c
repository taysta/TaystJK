/*
===========================================================================
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

// Disruptor Weapon

#include "cg_local.h"
#include "fx_local.h"

/*
---------------------------
FX_DisruptorMainShot
---------------------------
*/
static vec3_t WHITE={1.0f,1.0f,1.0f};

void FX_DisruptorMainShot( vec3_t start, vec3_t end )
{
//	vec3_t	dir;
//	float	len;

	trap->FX_AddLine( start, end, 0.1f, 6.0f, 0.0f,
							1.0f, 0.0f, 0.0f,
							WHITE, WHITE, 0.0f,
							cg_disruptorMainTime.integer, trap->R_RegisterShader( "gfx/effects/redLine" ),
							FX_SIZE_LINEAR | FX_ALPHA_LINEAR );

//	VectorSubtract( end, start, dir );
//	len = VectorNormalize( dir );

//	FX_AddCylinder( start, dir, 5.0f, 5.0f, 0.0f,
//								5.0f, 5.0f, 0.0f,
//								len, len, 0.0f,
//								1.0f, 1.0f, 0.0f,
//								WHITE, WHITE, 0.0f,
//								400, cgi_R_RegisterShader( "gfx/effects/spiral" ), 0 );
}

/*
---------------------------
FX_DisruptorAltShot
---------------------------
*/
void FX_DisruptorAltShot( vec3_t start, vec3_t end, qboolean fullCharge )
{
    trap->FX_AddLine( start, end, 0.1f, 10.0f, 0.0f,
                      1.0f, 0.0f, 0.0f,
                      WHITE, WHITE, 0.0f,
                      cg_disruptorAltTime.integer, trap->R_RegisterShader( "gfx/effects/redLine" ),
                      FX_SIZE_LINEAR | FX_ALPHA_LINEAR );

    if ( fullCharge )
    {
        vec3_t	YELLER={0.8f,0.7f,0.0f};

        // add some beef
        trap->FX_AddLine( start, end, 0.1f, 7.0f, 0.0f,
                          1.0f, 0.0f, 0.0f,
                          YELLER, YELLER, 0.0f,
                          cg_disruptorAltTime.integer, trap->R_RegisterShader( "gfx/misc/whiteline2" ),
                          FX_SIZE_LINEAR | FX_ALPHA_LINEAR );
    }
}

//q3pro/QtZ code -- ported from jamme
void CG_RailTrail( clientInfo_t *ci, vec3_t start, vec3_t end, int time ) {
    localEntity_t *leCore = CG_AllocLocalEntity();
    refEntity_t   *reCore = &leCore->refEntity;
    localEntity_t *leGlow = CG_AllocLocalEntity();
    refEntity_t   *reGlow = &leGlow->refEntity;
#if 0
    vector4 color1 = { ci->color1[0], ci->color1[1], ci->color1[2], 1.0f },
			color2 = { ci->color2[0], ci->color2[1], ci->color2[2], 1.0f };
#else
    vec4_t	color1 = { ci->rgb1[0]/255.0f, ci->rgb1[1]/255.0f, ci->rgb1[2]/255.0f, 1.0f },
            color2 = { ci->rgb2[0]/255.0f, ci->rgb2[1]/255.0f, ci->rgb2[2]/255.0f, 1.0f };
#endif
    int killTime = (time < 0) ? 175 : time;

    if ( cgs.gametype >= GT_TEAM )
    {
        if ( ci->team == TEAM_RED )
        {
            VectorSet4( color1, 1.0f, 0.0f, 0.0f, 1.0f );
            VectorSet4( color2, 1.0f, 0.0f, 0.0f, 1.0f );
            //	muzzleEffect = cgs.effects.weapons.divergenceMuzzleRed;
        }
        else if ( ci->team == TEAM_BLUE )
        {
            VectorSet4( color1, 0.0f, 0.0f, 1.0f, 1.0f );
            VectorSet4( color2, 0.0f, 0.0f, 1.0f, 1.0f );
            //	muzzleEffect = cgs.effects.weapons.divergenceMuzzleBlue;
        }
    }
    else
    {
        if (cg_disruptorCoreColor.string[0] != '0') {
            Q_parseColor( cg_disruptorCoreColor.string, defaultColors, color1 );
        } else {
            VectorSet4(color1, 0.0f, 0.878431f, 1.0f, 1.0f);
            VectorSet4(color2, 0.0f, 1.0f, 1.0f, 1.0f);
        }
    }

    //Glow
    leGlow->leType = LE_FADE_RGB;
    leGlow->startTime = cg.time;
    leGlow->endTime = cg.time + killTime;
    leGlow->lifeRate = 1.0 / (leGlow->endTime - leGlow->startTime);
    reGlow->shaderTime = cg.time / 1600.0f;
    reGlow->reType = RT_LINE;
    reGlow->radius = 3.0f;
    reGlow->customShader = trap->R_RegisterShader( "gfx/misc/whiteline2" );
    VectorCopy(start, reGlow->origin);
    VectorCopy(end, reGlow->oldorigin);
    reGlow->shaderRGBA[0] = color1[0] * 255;
    reGlow->shaderRGBA[1] = color1[1] * 255;
    reGlow->shaderRGBA[2] = color1[2] * 255;
    reGlow->shaderRGBA[3] = 255;
    leGlow->color[0] = color1[0] * 0.75;
    leGlow->color[1] = color1[1] * 0.75;
    leGlow->color[2] = color1[2] * 0.75;
    leGlow->color[3] = 1.0f;

    //Core
    leCore->leType = LE_FADE_RGB;
    leCore->startTime = cg.time;
    leCore->endTime = cg.time + killTime;
    leCore->lifeRate = 1.0 / (leCore->endTime - leCore->startTime);
    reCore->shaderTime = cg.time / 1600.0f;
    reCore->reType = RT_LINE;
    reCore->radius = 1.0f;
    reCore->customShader = trap->R_RegisterShader( "gfx/misc/whiteline2" );
    VectorCopy(start, reCore->origin);
    VectorCopy(end, reCore->oldorigin);
    reCore->shaderRGBA[0] = color1[0] * 255;
    reCore->shaderRGBA[1] = color1[1] * 255;
    reCore->shaderRGBA[2] = color1[2] * 255;
    reCore->shaderRGBA[3] = 255;
    leCore->color[0] = 1.0f;
    leCore->color[1] = 1.0f;
    leCore->color[2] = 1.0f;
    leCore->color[3] = 0.6f;

    AxisClear( reCore->axis );
}


void CG_RailSpiral( clientInfo_t *ci, vec3_t start, vec3_t end, int time ) {
    vec3_t axis[36], move, move2, next_move, vec, temp;
    float  len;
    int    i, j, skip;
    vec3_t coreColor, spiralColor;
    int killTime = (time < 0) ? 175 : time;

    localEntity_t *leCore = CG_AllocLocalEntity();
    refEntity_t   *reCore = &leCore->refEntity;
    localEntity_t *leGlow = CG_AllocLocalEntity();
    refEntity_t   *reGlow = &leGlow->refEntity;

#define RADIUS   4
#define ROTATION 1
#define SPACING  5

    start[2] -= 4;
    VectorCopy (start, move);
    VectorSubtract (end, start, vec);
    len = VectorNormalize (vec);
    PerpendicularVector(temp, vec);
    for (i = 0 ; i < 36; i++)
        RotatePointAroundVector(axis[i], vec, temp, i * 10);//banshee 2.4 was 10

    if (!cg_disruptorTeamColor.integer) {
        if (cg_disruptorCoreColor.string[0] != '0') {
            Q_parseColor( cg_disruptorCoreColor.string, defaultColors, coreColor );
        } else {
            VectorCopy(ci->color1, coreColor);
        }
        if (cg_disruptorSpiralColor.string[0] != '0') {
            Q_parseColor( cg_disruptorSpiralColor.string, defaultColors, spiralColor );
        } else {
            VectorCopy(coreColor, spiralColor);	//let's take colour from core
        }
    } else {
        vec3_t color;
        //colours are stolen from saber blades
        if (ci->team == TEAM_RED) {
            VectorSet( color, 1.0f, 0.0f, 0.0f );
        } else if (ci->team == TEAM_BLUE) {
            VectorSet( color, 0.0f, 0.25f, 1.0f );
        } else {
            VectorSet( color, 1.0f, 1.0f, 0.0f );
        }
        VectorCopy(color, coreColor);
        VectorCopy(color, spiralColor);
    }

    //Glow
    leGlow->leType = LE_FADE_RGB;
    leGlow->startTime = cg.time;
    leGlow->endTime = cg.time + killTime;
    leGlow->lifeRate = 1.0 / (leGlow->endTime - leGlow->startTime);
    reGlow->shaderTime = cg.time / 1600.0f;
    reGlow->reType = RT_LINE;
    reGlow->radius = 3.0f;
    reGlow->customShader = trap->R_RegisterShader( "gfx/misc/whiteline2" );
    VectorCopy(start, reGlow->origin);
    VectorCopy(end, reGlow->oldorigin);
    reGlow->shaderRGBA[0] = coreColor[0] * 255;
    reGlow->shaderRGBA[1] = coreColor[1] * 255;
    reGlow->shaderRGBA[2] = coreColor[2] * 255;
    reGlow->shaderRGBA[3] = 255;
    leGlow->color[0] = coreColor[0] * 0.75;
    leGlow->color[1] = coreColor[1] * 0.75;
    leGlow->color[2] = coreColor[2] * 0.75;
    leGlow->color[3] = 1.0f;

    //Core
    leCore->leType = LE_FADE_RGB;
    leCore->startTime = cg.time;
    leCore->endTime = cg.time + killTime;
    leCore->lifeRate = 1.0 / (leCore->endTime - leCore->startTime);
    reCore->shaderTime = cg.time / 1600.0f;
    reCore->reType = RT_LINE;
    reCore->radius = 1.0f;
    reCore->customShader = trap->R_RegisterShader( "gfx/misc/whiteline2" );
    VectorCopy(start, reCore->origin);
    VectorCopy(end, reCore->oldorigin);
    reCore->shaderRGBA[0] = coreColor[0] * 255;
    reCore->shaderRGBA[1] = coreColor[1] * 255;
    reCore->shaderRGBA[2] = coreColor[2] * 255;
    reCore->shaderRGBA[3] = 255;
    leCore->color[0] = 1.0f;
    leCore->color[1] = 1.0f;
    leCore->color[2] = 1.0f;
    leCore->color[3] = 0.6f;

    AxisClear( reCore->axis );

    VectorMA(move, 20, vec, move);
    VectorCopy(move, next_move);
    VectorScale (vec, SPACING, vec);

    skip = -1;

    j = 18;
    for (i = 0; i < len; i += SPACING) {
        if (i != skip) {
            localEntity_t *le = CG_AllocLocalEntity();
            refEntity_t *re = &le->refEntity;

            skip = i + SPACING;
            le->leFlags = LEF_PUFF_DONT_SCALE;
            le->leType = LE_MOVE_SCALE_FADE;
            le->startTime = cg.time;
            le->endTime = cg.time + (i>>1) + killTime / 1.337f;
            le->lifeRate = 1.0 / (le->endTime - le->startTime);

            re->shaderTime = cg.time / 2000.0f;
            re->reType = RT_SPRITE;
            re->radius = 1.8f;
            re->customShader = cgs.media.enlightenmentShader;
            re->renderfx |= RF_RGB_TINT;

            re->shaderRGBA[0] = spiralColor[0] * 255;
            re->shaderRGBA[1] = spiralColor[1] * 255;
            re->shaderRGBA[2] = spiralColor[2] * 255;
            re->shaderRGBA[3] = 255;

            le->color[0] = spiralColor[0] * 0.75;
            le->color[1] = spiralColor[1] * 0.75;
            le->color[2] = spiralColor[2] * 0.75;
            le->color[3] = 1.0f;

            le->pos.trType = TR_LINEAR;
            le->pos.trTime = cg.time;

            VectorCopy( move, move2);
            VectorMA(move2, RADIUS , axis[j], move2);
            VectorCopy(move2, le->pos.trBase);

            le->pos.trDelta[0] = axis[j][0]*6;
            le->pos.trDelta[1] = axis[j][1]*6;
            le->pos.trDelta[2] = axis[j][2]*6;
        }

        VectorAdd (move, vec, move);

        j = j + ROTATION < 36 ? j + ROTATION : (j + ROTATION) % 36;
    }
}

/*
---------------------------
FX_DisruptorAltMiss
---------------------------
*/
#define FX_ALPHA_WAVE		0x00000008

void FX_DisruptorAltMiss( vec3_t origin, vec3_t normal )
{
	vec3_t pos, c1, c2;
	addbezierArgStruct_t b;

	VectorMA( origin, 4.0f, normal, c1 );
	VectorCopy( c1, c2 );
	c1[2] += 4;
	c2[2] += 12;

	VectorAdd( origin, normal, pos );
	pos[2] += 28;

	/*
	FX_AddBezier( origin, pos, c1, vec3_origin, c2, vec3_origin, 6.0f, 6.0f, 0.0f, 0.0f, 0.2f, 0.5f,
	WHITE, WHITE, 0.0f, 4000, trap->R_RegisterShader( "gfx/effects/smokeTrail" ), FX_ALPHA_WAVE );
	*/

	VectorCopy(origin, b.start);
	VectorCopy(pos, b.end);
	VectorCopy(c1, b.control1);
	VectorCopy(vec3_origin, b.control1Vel);
	VectorCopy(c2, b.control2);
	VectorCopy(vec3_origin, b.control2Vel);

	b.size1 = 6.0f;
	b.size2 = 6.0f;
	b.sizeParm = 0.0f;
	b.alpha1 = 0.0f;
	b.alpha2 = 0.2f;
	b.alphaParm = 0.5f;

	VectorCopy(WHITE, b.sRGB);
	VectorCopy(WHITE, b.eRGB);

	b.rgbParm = 0.0f;
	b.killTime = 4000;
	b.shader = trap->R_RegisterShader( "gfx/effects/smokeTrail" );
	b.flags = FX_ALPHA_WAVE;

	trap->FX_AddBezier(&b);

	trap->FX_PlayEffectID( cgs.effects.disruptorAltMissEffect, origin, normal, -1, -1, qfalse );
}

/*
---------------------------
FX_DisruptorAltHit
---------------------------
*/

void FX_DisruptorAltHit( vec3_t origin, vec3_t normal )
{
	trap->FX_PlayEffectID( cgs.effects.disruptorAltHitEffect, origin, normal, -1, -1, qfalse );
}



/*
---------------------------
FX_DisruptorHitWall
---------------------------
*/

void FX_DisruptorHitWall( vec3_t origin, vec3_t normal )
{
	trap->FX_PlayEffectID( cgs.effects.disruptorWallImpactEffect, origin, normal, -1, -1, qfalse );
}

/*
---------------------------
FX_DisruptorHitPlayer
---------------------------
*/

void FX_DisruptorHitPlayer( vec3_t origin, vec3_t normal, qboolean humanoid )
{
	trap->FX_PlayEffectID( cgs.effects.disruptorFleshImpactEffect, origin, normal, -1, -1, qfalse );
}
