/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
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

// bg_pmove.c -- both games player movement code
// takes a playerstate and a usercmd as input and returns a modifed playerstate

#include "qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_local.h"
#include "ghoul2/G2.h"

#ifdef _GAME
	#include "g_local.h"
#elif _CGAME
	#include "cgame/cg_local.h"
#elif UI_BUILD
	#include "ui/ui_local.h"
#endif

#define MAX_WEAPON_CHARGE_TIME 5000

#ifdef _GAME
	extern void G_CheapWeaponFire(int entNum, int ev);
	extern qboolean TryGrapple(gentity_t *ent); //g_cmds.c
#elif defined _CGAME
	extern int cg_dueltypes[MAX_CLIENTS];//JAPRO - Serverside - Fullforce Dueling
#endif

extern qboolean BG_FullBodyTauntAnim( int anim );
extern float PM_WalkableGroundDistance(void);
extern qboolean PM_GroundSlideOkay( float zNormal );
extern saberInfo_t *BG_MySaber( int clientNum, int saberNum );

#ifdef _GAME
extern void G_TestLine(vec3_t start, vec3_t end, int color, int time);
#endif

pmove_t		*pm;
pml_t		pml;

bgEntity_t *pm_entSelf = NULL;
bgEntity_t *pm_entVeh = NULL;

qboolean gPMDoSlowFall = qfalse;

qboolean pm_cancelOutZoom = qfalse;

// movement parameters
const float	pm_stopspeed = 100.0f;
const float	pm_duckScale = 0.50f;
const float	pm_swimScale = 0.50f;
const float	pm_wadeScale = 0.70f;

const float	pm_vehicleaccelerate = 36.0f;
const float	pm_accelerate = 10.0f;
const float	pm_airaccelerate = 1.0f;
const float	pm_wateraccelerate = 4.0f;
const float	pm_flyaccelerate = 8.0f;

const float pm_sp_accelerate = 12.0f;
const float pm_sp_airaccelerate = 4.0f;
const float pm_sp_airDecelRate = 1.35f;

const float	pm_friction = 6.0f;
const float	pm_waterfriction = 1.0f;
const float	pm_flightfriction = 3.0f;
const float	pm_spectatorfriction = 5.0f;

//japro/dfmania movement parameters
const float pm_vq3_duckScale = 0.25f;
const float pm_vq3_friction = 8.0f;

const float	pm_cpm_accelerate = 15.0f;
const float	pm_cpm_airaccelerate = 1.0f;
const float	pm_cpm_airstopaccelerate = 2.5f;
const float	pm_cpm_airstrafeaccelerate = 70.0f;
const float	pm_cpm_airstrafewishspeed = 30.0f;

const float	pm_cpm_aircontrol = 150.0f;

const float pm_wsw_accelerate = 12.0f;
const float pm_wsw_duckScale = 0.3125f;

const float pm_slick_accelerate = 30.0f;
const float	pm_slick_airstrafeaccelerate = 100.0f;
const float	pm_slick_friction = 0.0f;

const float	pm_jetpack_airaccelerate = 1.4f;

const float pm_qw_airaccelerate = 0.7f;
const float pm_qw_friction = 4.0f;
const float	pm_qw_airstrafewishspeed = 30.0f;

const float pm_tribes_accelerate = 2.5f;
const float pm_tribes_airaccelerate = 0.25f;
const float pm_tribes_groundfriction = 0.5f;
const float pm_tribes_airfriction = 1.9f;
const float	pm_tribes_groundstrafewishspeed = 30.0f;

const float pm_surf_accelerate = 12.0f;
const float pm_surf_airaccelerate = 100.0f;
const float pm_surf_wishspeed = 250.0f;

// lumaya: Lugormod
float scaleh;

//japro/dfmania movement parameters

int		c_pmove = 0;

float forceSpeedLevels[4] =
{
	1, //rank 0?
	1.25,
	1.5,
	1.75
};

int forcePowerNeeded[NUM_FORCE_POWER_LEVELS][NUM_FORCE_POWERS] =
{
	{ //nothing should be usable at rank 0..
		999,//FP_HEAL,//instant
		999,//FP_LEVITATION,//hold/duration
		999,//FP_SPEED,//duration
		999,//FP_PUSH,//hold/duration
		999,//FP_PULL,//hold/duration
		999,//FP_TELEPATHY,//instant
		999,//FP_GRIP,//hold/duration
		999,//FP_LIGHTNING,//hold/duration
		999,//FP_RAGE,//duration
		999,//FP_PROTECT,//duration
		999,//FP_ABSORB,//duration
		999,//FP_TEAM_HEAL,//instant
		999,//FP_TEAM_FORCE,//instant
		999,//FP_DRAIN,//hold/duration
		999,//FP_SEE,//duration
		999,//FP_SABER_OFFENSE,
		999,//FP_SABER_DEFENSE,
		999//FP_SABERTHROW,
		//NUM_FORCE_POWERS
	},
	{
		65,//FP_HEAL,//instant //was 25, but that was way too little
		10,//FP_LEVITATION,//hold/duration
		50,//FP_SPEED,//duration
		20,//FP_PUSH,//hold/duration
		20,//FP_PULL,//hold/duration
		20,//FP_TELEPATHY,//instant
		30,//FP_GRIP,//hold/duration
		1,//FP_LIGHTNING,//hold/duration
		50,//FP_RAGE,//duration
		50,//FP_PROTECT,//duration
		50,//FP_ABSORB,//duration
		50,//FP_TEAM_HEAL,//instant
		50,//FP_TEAM_FORCE,//instant
		20,//FP_DRAIN,//hold/duration
		20,//FP_SEE,//duration
		0,//FP_SABER_OFFENSE,
		2,//FP_SABER_DEFENSE,
		20//FP_SABERTHROW,
		//NUM_FORCE_POWERS
	},
	{
		60,//FP_HEAL,//instant
		10,//FP_LEVITATION,//hold/duration
		50,//FP_SPEED,//duration
		20,//FP_PUSH,//hold/duration
		20,//FP_PULL,//hold/duration
		20,//FP_TELEPATHY,//instant
		30,//FP_GRIP,//hold/duration
		1,//FP_LIGHTNING,//hold/duration
		50,//FP_RAGE,//duration
		25,//FP_PROTECT,//duration
		25,//FP_ABSORB,//duration
		33,//FP_TEAM_HEAL,//instant
		33,//FP_TEAM_FORCE,//instant
		20,//FP_DRAIN,//hold/duration
		20,//FP_SEE,//duration
		0,//FP_SABER_OFFENSE,
		1,//FP_SABER_DEFENSE,
		20//FP_SABERTHROW,
		//NUM_FORCE_POWERS
	},
	{
		50,//FP_HEAL,//instant //You get 5 points of health.. for 50 force points!
		10,//FP_LEVITATION,//hold/duration
		50,//FP_SPEED,//duration
		20,//FP_PUSH,//hold/duration
		20,//FP_PULL,//hold/duration
		20,//FP_TELEPATHY,//instant
		60,//FP_GRIP,//hold/duration
		1,//FP_LIGHTNING,//hold/duration
		50,//FP_RAGE,//duration
		10,//FP_PROTECT,//duration
		10,//FP_ABSORB,//duration
		25,//FP_TEAM_HEAL,//instant
		25,//FP_TEAM_FORCE,//instant
		20,//FP_DRAIN,//hold/duration
		20,//FP_SEE,//duration
		0,//FP_SABER_OFFENSE,
		0,//FP_SABER_DEFENSE,
		20//FP_SABERTHROW,
		//NUM_FORCE_POWERS
	}
};

float forceJumpHeight[NUM_FORCE_POWER_LEVELS + 2] =
{
	32,//normal jump (+stepheight+crouchdiff = 66)
	96,//(+stepheight+crouchdiff = 130)
	192,//(+stepheight+crouchdiff = 226)
	384,//(+stepheight+crouchdiff = 418)
	1570,
	1570
};

float forceJumpStrength[NUM_FORCE_POWER_LEVELS + 2] =
{
	JUMP_VELOCITY,//normal jump
	420,
	590,
	840,
	840,
	960
};

static int GetFlipkick(playerState_t *ps) {
#if _GAME
		if (ps->duelInProgress) {
			if (dueltypes[ps->clientNum] == 0) { //NF.. man this sucks.. fucks up JA+ nf duels
				return 0;
			}
		}
		return g_flipKick.integer;
#else
		if (cgs.serverMod == SVMOD_JAPRO) {
			if (ps->duelInProgress) {
				if (cg_dueltypes[ps->clientNum] == 1) { //NF
					return 0;
				}
			}
			if (cgs.jcinfo & JAPRO_CINFO_FLIPKICK) {
				if (cgs.jcinfo & JAPRO_CINFO_FIXSIDEKICK)
					return 3;
				return 2; //1 ans 2 are the same thing clientside...hmm
			}
		}
		if (cgs.serverMod == SVMOD_JAPLUS && (cgs.cinfo & JAPLUS_CINFO_FLIPKICK))
			return 1;

		return 0;
#endif
}

static int GetFixRoll(playerState_t *ps) {
	//If we are dueling saber only and duels are SP damages and FFA is mp damages..
		//return 0
	//If we are dueling force and duels are MP damages and FFA is sp damages
		//return 3 ?

	//Problem: client does not know what damages are set..
	//Would have to network this.. if we want to let servers do jk2 roll in NF duels, or shortroll in FF duels..

#if _GAME
		if (ps->stats[STAT_RACEMODE])
			return 3;
		if (ps->duelInProgress) {
			if (dueltypes[ps->clientNum] == 0) { //NF
				return 0;
			}
			if (dueltypes[ps->clientNum] == 1) { //FF
				return 3;
			}
		}
		return g_fixRoll.integer;
#else
		if (cgs.serverMod == SVMOD_JAPRO) {
			if (ps->stats[STAT_RACEMODE])
				return 3;
			if (ps->duelInProgress) {
				if (cg_dueltypes[ps->clientNum] == 1) { //NF
					return 0;
				}
				if (cg_dueltypes[ps->clientNum] == 2) { //FF
					return 3;
				}
			}
		}

		if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL3) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL3))
			return 3;
		if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL2) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL2) || cgs.legacyProtocol)
			return 2;
		if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL1) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL1))
			return 1;

		return 0;
#endif
}


//rww - Get a pointer to the bgEntity by the index
bgEntity_t *PM_BGEntForNum( int num )
{
	bgEntity_t *ent;

	if (!pm)
	{
		assert(!"You cannot call PM_BGEntForNum outside of pm functions!");
		return NULL;
	}

	if (!pm->baseEnt)
	{
		assert(!"Base entity address not set");
		return NULL;
	}

	if (!pm->entSize)
	{
		assert(!"sizeof(ent) is 0, impossible (not set?)");
		return NULL;
	}

	assert(num >= 0 && num < MAX_GENTITIES);

    ent = (bgEntity_t *)((byte *)pm->baseEnt + pm->entSize*(num));

	return ent;
}

qboolean BG_SabersOff( playerState_t *ps )
{
	if ( !ps->saberHolstered )
	{
		return qfalse;
	}
	if ( ps->fd.saberAnimLevelBase == SS_DUAL
		|| ps->fd.saberAnimLevelBase == SS_STAFF )
	{
		if ( ps->saberHolstered < 2 )
		{
			return qfalse;
		}
	}
	return qtrue;
}

qboolean BG_KnockDownable(playerState_t *ps)
{
	if (!ps)
	{ //just for safety
		return qfalse;
	}

	if (ps->m_iVehicleNum)
	{ //riding a vehicle, don't knock me down
		return qfalse;
	}

	if (ps->emplacedIndex)
	{ //using emplaced gun or eweb, can't be knocked down
		return qfalse;
	}

	//ok, I guess?
	return qtrue;
}

extern qboolean BG_InKnockDown(int anim);
qboolean BG_CanJetpack(playerState_t *ps)
{
	//Need a debouncer
	if (!(ps->stats[STAT_HOLDABLE_ITEMS] & (1 << HI_JETPACK)))
		return qfalse;
	if (ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && ps->fd.forcePower < 10)
		return qfalse;
	if (ps->stats[STAT_MOVEMENTSTYLE] != MV_TRIBES && ps->jetpackFuel < 10)
		return qfalse;
	if (BG_SaberInSpecial(ps->saberMove))
		return qfalse;
	if (BG_InRoll(ps, ps->legsAnim))
		return qfalse;
	if (BG_InSpecialJump(ps->legsAnim))
		return qfalse;
	if (BG_InKnockDown(ps->legsAnim))
		return qfalse;
	if (pm->waterlevel > 1)
		return qfalse;
	//if (ps->stats[STAT_JUMPTIME] > 0) //revert until bot jetpack behaviour is fixed
		//return qfalse;
	return qtrue;
}

static QINLINE qboolean BG_IsNewJetpacking(playerState_t *ps) {
	if (pm_entSelf->m_pVehicle)
		return qfalse;
	if (pm->ps->eFlags & EF_JETPACK_ACTIVE)
		return qtrue;
	return qfalse;
}

//hacky assumption check, assume any client non-humanoid is a rocket trooper
static QINLINE qboolean PM_IsRocketTrooper(void)
{
	/*
	if (pm->ps->clientNum < MAX_CLIENTS &&
		pm->gametype == GT_SIEGE &&
		pm->nonHumanoid)
	{
		return qtrue;
	}
	*/

	return qfalse;
}

QINLINE int PM_GetMovePhysics(void)
{
#if _GAME
	if (pm->ps->stats[STAT_RACEMODE])
		return (pm->ps->stats[STAT_MOVEMENTSTYLE]);
	else if ((g_movementStyle.integer >= MV_SIEGE && g_movementStyle.integer <= MV_WSW) || (g_movementStyle.integer == MV_SP || g_movementStyle.integer == MV_SLICK || g_movementStyle.integer == MV_OCPM || g_movementStyle.integer == MV_TRIBES))
		return (g_movementStyle.integer);
	else if (g_movementStyle.integer < MV_SIEGE)
		return MV_SIEGE;
	else if (g_movementStyle.integer >= MV_NUMSTYLES)
		return MV_JKA;
#else
	if (cgs.serverMod == SVMOD_JAPRO) {
			if (!pm)
				return MV_JKA;

		if (pm->ps->m_iVehicleNum)
			return MV_SWOOP;
		return pm->ps->stats[STAT_MOVEMENTSTYLE];
	}
	else if (cgs.gametype == GT_SIEGE) {
		return MV_SIEGE;
	}
#endif
	return MV_JKA;
}

int PM_GetSaberStance(void)
{
	int anim = BOTH_STAND2;
	saberInfo_t *saber1 = BG_MySaber( pm->ps->clientNum, 0 );
	saberInfo_t *saber2 = BG_MySaber( pm->ps->clientNum, 1 );

	if (!pm->ps->saberEntityNum)
	{ //lost it
		return BOTH_STAND1;
	}

	if ( BG_SabersOff( pm->ps ) )
	{
		return BOTH_STAND1;
	}

	if ( saber1
		&& saber1->readyAnim != -1 )
	{
		return saber1->readyAnim;
	}

	if ( saber2
		&& saber2->readyAnim != -1 )
	{
		return saber2->readyAnim;
	}

	if ( saber1
		&& saber2
		&& !pm->ps->saberHolstered )
	{//dual sabers, both on
		return BOTH_SABERDUAL_STANCE;
	}

	switch ( pm->ps->fd.saberAnimLevel )
	{
	case SS_DUAL:
		anim = BOTH_SABERDUAL_STANCE;
		break;
	case SS_STAFF:
		anim = BOTH_SABERSTAFF_STANCE;
		break;
	case SS_FAST:
	case SS_TAVION:
		anim = BOTH_SABERFAST_STANCE;
		break;
	case SS_STRONG:
		anim = BOTH_SABERSLOW_STANCE;
		break;
	case SS_NONE:
	case SS_MEDIUM:
	case SS_DESANN:
	default:
		anim = BOTH_STAND2;
		break;
	}
	return anim;
}

qboolean PM_DoSlowFall(void)
{
	if ( ( (pm->ps->legsAnim) == BOTH_WALL_RUN_RIGHT || (pm->ps->legsAnim) == BOTH_WALL_RUN_LEFT ) && pm->ps->legsTimer > 500 )
	{
		return qtrue;
	}

	return qfalse;
}

//begin vehicle functions crudely ported from sp -rww
/*
====================================================================
void pitch_roll_for_slope (edict_t *forwhom, vec3_t *slope, vec3_t storeAngles )

MG

This will adjust the pitch and roll of a monster to match
a given slope - if a non-'0 0 0' slope is passed, it will
use that value, otherwise it will use the ground underneath
the monster.  If it doesn't find a surface, it does nothinh\g
and returns.
====================================================================
*/

void PM_pitch_roll_for_slope( bgEntity_t *forwhom, vec3_t pass_slope, vec3_t storeAngles )
{
	vec3_t	slope;
	vec3_t	nvf, ovf, ovr, startspot, endspot, new_angles = { 0, 0, 0 };
	float	pitch, mod, dot;

	//if we don't have a slope, get one
	if( !pass_slope || VectorCompare( vec3_origin, pass_slope ) )
	{
		trace_t trace;

		VectorCopy( pm->ps->origin, startspot );
		startspot[2] += pm->mins[2] + 4;
		VectorCopy( startspot, endspot );
		endspot[2] -= 300;
		pm->trace( &trace, pm->ps->origin, vec3_origin, vec3_origin, endspot, forwhom->s.number, MASK_SOLID );
//		if(trace_fraction>0.05&&forwhom.movetype==MOVETYPE_STEP)
//			forwhom.flags(-)FL_ONGROUND;

		if ( trace.fraction >= 1.0 )
			return;

		if ( VectorCompare( vec3_origin, trace.plane.normal ) )
			return;

		VectorCopy( trace.plane.normal, slope );
	}
	else
	{
		VectorCopy( pass_slope, slope );
	}

	if ( forwhom->s.NPC_class == CLASS_VEHICLE )
	{//special code for vehicles
		Vehicle_t *pVeh = forwhom->m_pVehicle;
		vec3_t tempAngles;

		tempAngles[PITCH] = tempAngles[ROLL] = 0;
		tempAngles[YAW] = pVeh->m_vOrientation[YAW];
		AngleVectors( tempAngles, ovf, ovr, NULL );
	}
	else
	{
		AngleVectors( pm->ps->viewangles, ovf, ovr, NULL );
	}

	vectoangles( slope, new_angles );
	pitch = new_angles[PITCH] + 90;
	new_angles[ROLL] = new_angles[PITCH] = 0;

	AngleVectors( new_angles, nvf, NULL, NULL );

	mod = DotProduct( nvf, ovr );

	if ( mod<0 )
		mod = -1;
	else
		mod = 1;

	dot = DotProduct( nvf, ovf );

	if ( storeAngles )
	{
		storeAngles[PITCH] = dot * pitch;
		storeAngles[ROLL] = ((1-Q_fabs(dot)) * pitch * mod);
	}
	else //if ( forwhom->client )
	{
		float oldmins2;

		pm->ps->viewangles[PITCH] = dot * pitch;
		pm->ps->viewangles[ROLL] = ((1-Q_fabs(dot)) * pitch * mod);
		oldmins2 = pm->mins[2];
		pm->mins[2] = -24 + 12 * fabs(pm->ps->viewangles[PITCH])/180.0f;
		//FIXME: if it gets bigger, move up
		if ( oldmins2 > pm->mins[2] )
		{//our mins is now lower, need to move up
			//FIXME: trace?
			pm->ps->origin[2] += (oldmins2 - pm->mins[2]);
			//forwhom->currentOrigin[2] = forwhom->client->ps.origin[2];
			//trap->linkentity( forwhom );
		}
	}
	/*
	else
	{
		forwhom->currentAngles[PITCH] = dot * pitch;
		forwhom->currentAngles[ROLL] = ((1-Q_fabs(dot)) * pitch * mod);
	}
	*/
}

#define		FLY_NONE	0
#define		FLY_NORMAL	1
#define		FLY_VEHICLE	2
#define		FLY_HOVER	3
static int pm_flying = FLY_NONE;

void PM_SetSpecialMoveValues (void)
{
	bgEntity_t *pEnt;

	if (pm->ps->clientNum < MAX_CLIENTS)
	{ //we know that real players aren't vehs
		pm_flying = FLY_NONE;
		return;
	}

	//default until we decide otherwise
	pm_flying = FLY_NONE;

	pEnt = pm_entSelf;

	if ( pEnt )
	{
		if ( (pm->ps->eFlags2&EF2_FLYING) )// pm->gent->client->moveType == MT_FLYSWIM )
		{
			pm_flying = FLY_NORMAL;
		}
		else if ( pEnt->s.NPC_class == CLASS_VEHICLE )
		{
			if ( pEnt->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER )
			{
				pm_flying = FLY_VEHICLE;
			}
			else if ( pEnt->m_pVehicle->m_pVehicleInfo->hoverHeight > 0 )
			{
				pm_flying = FLY_HOVER;
			}
		}
	}
}

static void PM_SetVehicleAngles( vec3_t normal )
{
	bgEntity_t *pEnt = pm_entSelf;
	Vehicle_t *pVeh;
	vec3_t	vAngles;
	float vehicleBankingSpeed;
	float pitchBias;
	int i;

	if ( !pEnt || pEnt->s.NPC_class != CLASS_VEHICLE )
	{
		return;
	}

	pVeh = pEnt->m_pVehicle;

	//float	curVehicleBankingSpeed;
	vehicleBankingSpeed = (pVeh->m_pVehicleInfo->bankingSpeed*32.0f)*pml.frametime;//0.25f

	if ( vehicleBankingSpeed <= 0
		|| ( pVeh->m_pVehicleInfo->pitchLimit == 0 && pVeh->m_pVehicleInfo->rollLimit == 0 ) )
	{//don't bother, this vehicle doesn't bank
		return;
	}
	//FIXME: do 3 traces to define a plane and use that... smoothes it out some, too...
	//pitch_roll_for_slope( pm->gent, normal, vAngles );
	//FIXME: maybe have some pitch control in water and/or air?

	if ( pVeh->m_pVehicleInfo->type == VH_FIGHTER )
	{
		pitchBias = 0.0f;
	}
	else
	{
		//FIXME: gravity does not matter in SPACE!!!
		//center of gravity affects pitch in air/water (FIXME: what about roll?)
		pitchBias = 90.0f*pVeh->m_pVehicleInfo->centerOfGravity[0];//if centerOfGravity is all the way back (-1.0f), vehicle pitches up 90 degrees when in air
	}

	VectorClear( vAngles );
	if ( pm->waterlevel > 0 )
	{//in water
		//view pitch has some influence when in water
		//FIXME: take center of gravity into account?
		vAngles[PITCH] += (pm->ps->viewangles[PITCH]-vAngles[PITCH])*0.75f + (pitchBias*0.5);
	}
	else if ( normal )
	{//have a valid surface below me
		PM_pitch_roll_for_slope( pEnt, normal, vAngles );
		if ( (pml.groundTrace.contents&(CONTENTS_WATER|CONTENTS_SLIME|CONTENTS_LAVA)) )
		{//on water
			//view pitch has some influence when on a fluid surface
			//FIXME: take center of gravity into account
			vAngles[PITCH] += (pm->ps->viewangles[PITCH]-vAngles[PITCH])*0.5f + (pitchBias*0.5f);
		}
	}
	else
	{//in air, let pitch match view...?
		//FIXME: take center of gravity into account
		vAngles[PITCH] = pm->ps->viewangles[PITCH]*0.5f + pitchBias;
		//don't bank so fast when in the air
		vehicleBankingSpeed *= (0.125f*pml.frametime);
	}
	//NOTE: if angles are flat and we're moving through air (not on ground),
	//		then pitch/bank?
	if ( pVeh->m_pVehicleInfo->rollLimit > 0 )
	{
		//roll when banking
		vec3_t	velocity;
		float	speed;
		VectorCopy( pm->ps->velocity, velocity );
		velocity[2] = 0.0f;
		speed = VectorNormalize( velocity );
		if ( speed > 32.0f || speed < -32.0f )
		{
			vec3_t	rt, tempVAngles;
			float	side;
			float	dp;

			// Magic number fun!  Speed is used for banking, so modulate the speed by a sine wave
			//FIXME: this banks too early
			speed *= sin( (150 + pml.frametime) * 0.003 );

			// Clamp to prevent harsh rolling
			if ( speed > 60 )
				speed = 60;

			VectorCopy( pVeh->m_vOrientation, tempVAngles );
			tempVAngles[ROLL] = 0;
			AngleVectors( tempVAngles, NULL, rt, NULL );
			dp = DotProduct( velocity, rt );
			side = speed * dp;
			vAngles[ROLL] -= side;
		}
	}

	//cap
	if ( pVeh->m_pVehicleInfo->pitchLimit != -1 )
	{
		if ( vAngles[PITCH] > pVeh->m_pVehicleInfo->pitchLimit )
		{
			vAngles[PITCH] = pVeh->m_pVehicleInfo->pitchLimit;
		}
		else if ( vAngles[PITCH] < -pVeh->m_pVehicleInfo->pitchLimit )
		{
			vAngles[PITCH] = -pVeh->m_pVehicleInfo->pitchLimit;
		}
	}

	if ( vAngles[ROLL] > pVeh->m_pVehicleInfo->rollLimit )
	{
		vAngles[ROLL] = pVeh->m_pVehicleInfo->rollLimit;
	}
	else if ( vAngles[ROLL] < -pVeh->m_pVehicleInfo->rollLimit )
	{
		vAngles[ROLL] = -pVeh->m_pVehicleInfo->rollLimit;
	}

	//do it
	for ( i = 0; i < 3; i++ )
	{
		if ( i == YAW )
		{//yawing done elsewhere
			continue;
		}
		//bank faster the higher the difference is
		/*
		else if ( i == PITCH )
		{
			curVehicleBankingSpeed = vehicleBankingSpeed*fabs(AngleNormalize180(AngleSubtract( vAngles[PITCH], pVeh->m_vOrientation[PITCH] )))/(g_vehicleInfo[pm->ps->vehicleIndex].pitchLimit/2.0f);
		}
		else if ( i == ROLL )
		{
			curVehicleBankingSpeed = vehicleBankingSpeed*fabs(AngleNormalize180(AngleSubtract( vAngles[ROLL], pVeh->m_vOrientation[ROLL] )))/(g_vehicleInfo[pm->ps->vehicleIndex].rollLimit/2.0f);
		}

		if ( curVehicleBankingSpeed )
		*/
		{
			if ( pVeh->m_vOrientation[i] >= vAngles[i] + vehicleBankingSpeed )
			{
				pVeh->m_vOrientation[i] -= vehicleBankingSpeed;
			}
			else if ( pVeh->m_vOrientation[i] <= vAngles[i] - vehicleBankingSpeed )
			{
				pVeh->m_vOrientation[i] += vehicleBankingSpeed;
			}
			else
			{
				pVeh->m_vOrientation[i] = vAngles[i];
			}
		}
	}
}

void BG_VehicleTurnRateForSpeed( Vehicle_t *pVeh, float speed, float *mPitchOverride, float *mYawOverride )
{
	if ( pVeh && pVeh->m_pVehicleInfo )
	{
		float speedFrac = 1.0f;
		if ( pVeh->m_pVehicleInfo->speedDependantTurning )
		{
			if ( pVeh->m_LandTrace.fraction >= 1.0f
				|| pVeh->m_LandTrace.plane.normal[2] < MIN_LANDING_SLOPE  )
			{
				speedFrac = (speed/(pVeh->m_pVehicleInfo->speedMax*0.75f));
				if ( speedFrac < 0.25f )
				{
					speedFrac = 0.25f;
				}
				else if ( speedFrac > 1.0f )
				{
					speedFrac = 1.0f;
				}
			}
		}
		if ( pVeh->m_pVehicleInfo->mousePitch )
		{
			*mPitchOverride = pVeh->m_pVehicleInfo->mousePitch*speedFrac;
		}
		if ( pVeh->m_pVehicleInfo->mouseYaw )
		{
			*mYawOverride = pVeh->m_pVehicleInfo->mouseYaw*speedFrac;
		}
	}
}


// Following couple things don't belong in the DLL namespace!
#ifdef _GAME
	#if !defined(MACOS_X) && !defined(__GCC__) && !defined(__GNUC__)
		typedef struct gentity_s gentity_t;
	#endif
	gentity_t *G_PlayEffectID( const int fxID, vec3_t org, vec3_t ang );
#endif


static void PM_GroundTraceMissed( void );
void PM_HoverTrace( void )
{
	Vehicle_t *pVeh;
	float hoverHeight;
	vec3_t		point, vAng, fxAxis[3];
	trace_t		*trace;
	float relativeWaterLevel;

	bgEntity_t *pEnt = pm_entSelf;
	if ( !pEnt || pEnt->s.NPC_class != CLASS_VEHICLE )
	{
		return;
	}

	pVeh = pEnt->m_pVehicle;
	hoverHeight = pVeh->m_pVehicleInfo->hoverHeight;
	trace = &pml.groundTrace;

	pml.groundPlane = qfalse;

	//relativeWaterLevel = (pm->ps->waterheight - (pm->ps->origin[2]+pm->mins[2]));
	relativeWaterLevel = pm->waterlevel; //I.. guess this works
	if ( pm->waterlevel && relativeWaterLevel >= 0 )
	{//in water
		if ( pVeh->m_pVehicleInfo->bouyancy <= 0.0f )
		{//sink like a rock
		}
		else
		{//rise up
			float floatHeight = (pVeh->m_pVehicleInfo->bouyancy * ((pm->maxs[2]-pm->mins[2])*0.5f)) - (hoverHeight*0.5f);//1.0f should make you float half-in, half-out of water
			if ( relativeWaterLevel > floatHeight )
			{//too low, should rise up
				pm->ps->velocity[2] += (relativeWaterLevel - floatHeight) * pVeh->m_fTimeModifier;
			}
		}
		//if ( pm->ps->waterheight < pm->ps->origin[2]+pm->maxs[2] )
		if (pm->waterlevel <= 1)
		{//part of us is sticking out of water
			if ( fabs(pm->ps->velocity[0]) + fabs(pm->ps->velocity[1]) > 100 )
			{//moving at a decent speed
				if ( Q_irand( pml.frametime, 100 ) >= 50 )
				{//splash
					vec3_t wakeOrg;

					vAng[PITCH] = vAng[ROLL] = 0;
					vAng[YAW] = pVeh->m_vOrientation[YAW];
					AngleVectors( vAng, fxAxis[2], fxAxis[1], fxAxis[0] );
					VectorCopy( pm->ps->origin, wakeOrg );
					//wakeOrg[2] = pm->ps->waterheight;
					if (pm->waterlevel >= 2)
					{
						wakeOrg[2] = pm->ps->origin[2]+16;
					}
					else
					{
						wakeOrg[2] = pm->ps->origin[2];
					}
					#ifdef _GAME //yeah, this is kind of crappy and makes no use of prediction whatsoever
						if ( pVeh->m_pVehicleInfo->iWakeFX )
						{
							//G_PlayEffectID( pVeh->m_pVehicleInfo->iWakeFX, wakeOrg, fxAxis[0] );
							//tempent use bad!
							G_AddEvent((gentity_t *)pEnt, EV_PLAY_EFFECT_ID, pVeh->m_pVehicleInfo->iWakeFX);
						}
					#endif
				}
			}
		}
	}
	else
	{
		int traceContents;
		float minNormal = pVeh->m_pVehicleInfo->maxSlope;
		float realMinNormal = 0.5f;
		int curTime;
#ifdef _GAME
		curTime = level.time;
#else
		curTime = pm->cmd.serverTime;
#endif

		if (pm->ps->stats[STAT_RACEMODE]) {//Its a vehicle in racemode, let it climb steeper things because this is annoying. RACESWOOP
			minNormal = 0.5f; //Max slope steepness before it stops hovoring you up - used to be 0.65
			realMinNormal = 0.7f; //Max slope steepness before you are unable to climb it at all - used to be 0.5
			//Before, any slope that you could climb up, you could also hovor boost up..?
			//now you can only hovor boost up slopes that you could already climb before? and you can now climb steeper slopes than before?
		}

		point[0] = pm->ps->origin[0];
		point[1] = pm->ps->origin[1];
		point[2] = pm->ps->origin[2] - hoverHeight;

		//FIXME: check for water, too?  If over water, go slower and make wave effect
		//		If *in* water, go really slow and use bouyancy stat to determine how far below surface to float

		//NOTE: if bouyancy is 2.0f or higher, you float over water like it's solid ground.
		//		if it's 1.0f, you sink halfway into water.  If it's 0, you sink...
		traceContents = pm->tracemask;
		if ( pVeh->m_pVehicleInfo->bouyancy >= 2.0f )
		{//sit on water
			traceContents |= (CONTENTS_WATER|CONTENTS_SLIME|CONTENTS_LAVA);
		}
		pm->trace( trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, traceContents );
		if ((trace->plane.normal[0] > realMinNormal || trace->plane.normal[0] < -realMinNormal ||
			trace->plane.normal[1] > realMinNormal || trace->plane.normal[1] < -realMinNormal) && (!pVeh->m_iGravTime || curTime >= pVeh->m_iGravTime))
		{ //steep slanted hill, don't go up it.
			float d = fabs(trace->plane.normal[0]);
			float e = fabs(trace->plane.normal[1]);
			if (e > d)
			{
				d = e;
			}
			pm->ps->velocity[2] = -300.0f*d;
		}
		else if ( trace->plane.normal[2] >= minNormal )
		{//not a steep slope, so push us up
			if ( trace->fraction < 1.0f )
			{//push up off ground
				float hoverForce = pVeh->m_pVehicleInfo->hoverStrength;
				if ( trace->fraction > 0.5f )
				{
					pm->ps->velocity[2] += (1.0f-trace->fraction)*hoverForce*pVeh->m_fTimeModifier;
				}
				else
				{
					pm->ps->velocity[2] += (0.5f-(trace->fraction*trace->fraction))*hoverForce*2.0f*pVeh->m_fTimeModifier;
				}
				if ( (trace->contents&(CONTENTS_WATER|CONTENTS_SLIME|CONTENTS_LAVA)) )
				{//hovering on water, make a spash if moving
					if ( fabs(pm->ps->velocity[0]) + fabs(pm->ps->velocity[1]) > 100 )
					{//moving at a decent speed
						if ( Q_irand( pml.frametime, 100 ) >= 50 )
						{//splash
							vAng[PITCH] = vAng[ROLL] = 0;
							vAng[YAW] = pVeh->m_vOrientation[YAW];
							AngleVectors( vAng, fxAxis[2], fxAxis[1], fxAxis[0] );
#ifdef _GAME
							if ( pVeh->m_pVehicleInfo->iWakeFX )
							{
								G_PlayEffectID( pVeh->m_pVehicleInfo->iWakeFX, trace->endpos, fxAxis[0] );
							}
#endif
						}
					}
				}
				pml.groundPlane = qtrue;
			}
		}
	}
	if ( pml.groundPlane )
	{
		PM_SetVehicleAngles( pml.groundTrace.plane.normal );
		// We're on the ground.
		pVeh->m_ulFlags &= ~VEH_FLYING;

		pVeh->m_vAngularVelocity = 0.0f;
	}
	else
	{
		PM_SetVehicleAngles( NULL );
		// We're flying in the air.
		pVeh->m_ulFlags |= VEH_FLYING;
		//groundTrace

		if (pVeh->m_vAngularVelocity==0.0f)
		{
			pVeh->m_vAngularVelocity = pVeh->m_vOrientation[YAW] - pVeh->m_vPrevOrientation[YAW];
			if (pVeh->m_vAngularVelocity<-15.0f)
			{
				pVeh->m_vAngularVelocity = -15.0f;
			}
			if (pVeh->m_vAngularVelocity> 15.0f)
			{
				pVeh->m_vAngularVelocity =  15.0f;
			}
		}
		//pVeh->m_vAngularVelocity *= 0.95f;		// Angular Velocity Decays Over Time
		if (pVeh->m_vAngularVelocity > 0.0f)
		{
			pVeh->m_vAngularVelocity -= pml.frametime;
			if (pVeh->m_vAngularVelocity < 0.0f)
			{
				pVeh->m_vAngularVelocity = 0.0f;
			}
		}
		else if (pVeh->m_vAngularVelocity < 0.0f)
		{
			pVeh->m_vAngularVelocity += pml.frametime;
			if (pVeh->m_vAngularVelocity > 0.0f)
			{
				pVeh->m_vAngularVelocity = 0.0f;
			}
		}
	}
	PM_GroundTraceMissed();
}
//end vehicle functions crudely ported from sp -rww

/*
===============
PM_AddEvent

===============
*/
void PM_AddEvent( int newEvent ) {
	BG_AddPredictableEventToPlayerstate( newEvent, 0, pm->ps );
}

void PM_AddEventWithParm( int newEvent, int parm )
{
	BG_AddPredictableEventToPlayerstate( newEvent, parm, pm->ps );
}

/*
===============
PM_AddTouchEnt
===============
*/
void PM_AddTouchEnt( int entityNum ) {
	int		i;

	if ( entityNum == ENTITYNUM_WORLD ) {
		return;
	}
	if ( pm->numtouch >= MAXTOUCH ) {
		return;
	}

	// see if it is already added
	for ( i = 0 ; i < pm->numtouch ; i++ ) {
		if ( pm->touchents[ i ] == entityNum ) {
			return;
		}
	}

	// add it
	pm->touchents[pm->numtouch++] = entityNum;
}


/*
==================
PM_ClipVelocity

Slide off of the impacting surface
==================
*/
void PM_ClipVelocity( vec3_t in, vec3_t normal, vec3_t out, float overbounce ) {
	float	backoff;
	float	change;
	float	oldInZ;
	int		i;

	//pass in entitynum of hit entity?
	//dotproduct instead of clipvelocity to the normal?

	if ( (pm->ps->pm_flags&PMF_STUCK_TO_WALL) )
	{//no sliding!
		VectorCopy( in, out );
		return;
	}
	oldInZ = in[2];

	backoff = DotProduct (in, normal);

	if ( backoff < 0 ) {
		backoff *= overbounce;
	} else {
		backoff /= overbounce;
	}

	for ( i=0 ; i<3 ; i++ ) {
		change = normal[i]*backoff;
		out[i] = in[i] - change;
	}
	if ( pm->stepSlideFix && pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_TRIBES && pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_SLICK)
	{
		if ( pm->ps->clientNum < MAX_CLIENTS//normal player
			&& pm->ps->groundEntityNum != ENTITYNUM_NONE//on the ground
			&& normal[2] < MIN_WALK_NORMAL )//sliding against a steep slope
		{//if walking on the ground, don't slide up slopes that are too steep to walk on
			out[2] = oldInZ;
		}
	}
}


/*
==================
PM_Friction

Handles both ground friction and water friction
==================
*/
static void PM_Friction( void ) {
	vec3_t	vec;
	float	*vel;
	float	speed, newspeed, control, drop, realfriction = pm_friction;
	bgEntity_t *pEnt = NULL;
	const int moveStyle = PM_GetMovePhysics();

	vel = pm->ps->velocity;

	VectorCopy( vel, vec );
	if ( pml.walking ) {
		vec[2] = 0;	// ignore slope movement
	}

	speed = VectorLength(vec);
	if (speed < 1) {
		vel[0] = 0;
		vel[1] = 0;		// allow sinking underwater
		if (pm->ps->pm_type == PM_SPECTATOR)
		{
			vel[2] = 0;
		}
		// FIXME: still have z friction underwater?
		return;
	}

	drop = 0;

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		pEnt = pm_entSelf;
	}

	if (moveStyle == MV_CPM || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM)
		realfriction = pm_vq3_friction;

	// apply ground friction, even if on ladder
	if (pm_flying != FLY_VEHICLE &&
		pEnt &&
		pEnt->s.NPC_class == CLASS_VEHICLE &&
		pEnt->m_pVehicle &&
		pEnt->m_pVehicle->m_pVehicleInfo->type != VH_ANIMAL &&
		pEnt->m_pVehicle->m_pVehicleInfo->type != VH_WALKER &&
		pEnt->m_pVehicle->m_pVehicleInfo->friction )
	{
		float friction = pEnt->m_pVehicle->m_pVehicleInfo->friction;
		if ( !(pm->ps->pm_flags & PMF_TIME_KNOCKBACK) /*&& !(pm->ps->pm_flags & PMF_TIME_NOFRICTION)*/ )
		{
			control = speed < pm_stopspeed ? pm_stopspeed : speed;
			drop += control*friction*pml.frametime;
			/*
			if ( Flying == FLY_HOVER )
			{
				if ( pm->cmd.rightmove )
				{//if turning, increase friction
					control *= 2.0f;
				}
				if ( pm->ps->groundEntityNum < ENTITYNUM_NONE )
				{//on the ground
					drop += control*friction*pml.frametime;
				}
				else if ( pml.groundPlane )
				{//on a slope
					drop += control*friction*2.0f*pml.frametime;
				}
				else
				{//in air
					drop += control*2.0f*friction*pml.frametime;
				}
			}
			*/
		}
	}
	else if ( pm_flying != FLY_NORMAL && pm_flying != FLY_VEHICLE )
	{
		// apply ground friction
		if ( pm->waterlevel <= 1 ) {
			if (pml.walking && !(pml.groundTrace.surfaceFlags & SURF_SLICK) && ((moveStyle != MV_SLICK || (pm->cmd.buttons & BUTTON_WALKING)) && (moveStyle != MV_TRIBES || !(pm->cmd.buttons & BUTTON_DASH)) && (moveStyle != MV_TRIBES || pm->ps->clientNum < MAX_CLIENTS || (pm->ps->eFlags2 & EF2_NOT_USED_1 && !pm->waterlevel) || !(pm->cmd.buttons & BUTTON_WALKING))) ) { //Slick style here potentially
				//do this unless its (slick and walking) or unless its (tribes and not walking)
										
				// if getting knocked back, no friction
				if ( ! (pm->ps->pm_flags & PMF_TIME_KNOCKBACK) ) { //GB?
					control = speed < pm_stopspeed ? pm_stopspeed : speed;
					drop += control*realfriction*pml.frametime;
				}

				if (moveStyle == MV_TRIBES && pm->ps->eFlags2 & EF2_NOT_USED_1 && !pm->waterlevel && pm->ps->clientNum >= MAX_CLIENTS) {//tribes props should have some friction here. speed based?
					drop *= 0.1f;
				}
			}
		}
	}

	if ( pm_flying == FLY_VEHICLE )
	{
		if ( !(pm->ps->pm_flags & PMF_TIME_KNOCKBACK) )
		{
			control = speed;// < pm_stopspeed ? pm_stopspeed : speed;
			drop += control*pm_friction*pml.frametime;
		}
	}

	// apply water friction even if just wading
	if ( pm->waterlevel ) {
		drop += speed*pm_waterfriction*pm->waterlevel*pml.frametime;
	}
	// If on a client then there is no friction
	else if ( pm->ps->groundEntityNum < MAX_CLIENTS )
	{
#ifdef _GAME
		if (g_slideOnPlayer.integer)
#else
		if ((cgs.serverMod == SVMOD_JAPRO && !(cgs.jcinfo & JAPRO_CINFO_HEADSLIDE)) || (cgs.serverMod == SVMOD_JAPLUS && !(cgs.cinfo & JAPLUS_CINFO_HEADSLIDE)) || cgs.serverMod == SVMOD_BASEENHANCED)
		{//no headslide, so do nothing
		}
		else
#endif
		{
			drop = 0;
		}
	}

	if ( pm->ps->pm_type == PM_SPECTATOR || pm->ps->pm_type == PM_FLOAT )
	{
		if (pm->ps->pm_type == PM_FLOAT)
		{ //almost no friction while floating
			drop += speed*0.1*pml.frametime;
		}
		else
		{
			drop += speed*pm_spectatorfriction*pml.frametime;
		}
	}

#ifdef _GAME
	if (pm->ps->pm_type != PM_SPECTATOR && (pm->ps->powerups[PW_REDFLAG] || pm->ps->powerups[PW_BLUEFLAG] || pm->ps->powerups[PW_NEUTRALFLAG])) {
		if ( !pml.groundTrace.contents )
			drop = speed*g_flagDrag.value*0.1*pml.frametime;
	}
#endif

	//MV_tRIBES air drag
#if 0
	if (pm->ps->pm_type != PM_SPECTATOR && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
		if (speed > pm->ps->speed * 1.44f)
			drop = speed*g_flagDrag.value*0.1*pml.frametime;
	}
#endif

	// scale the velocity
	newspeed = speed - drop;
	if (newspeed < 0) {
		newspeed = 0;
	}
	newspeed /= speed;

	VectorScale( vel, newspeed, vel );
}

void PM_AirAccelerate (vec3_t wishdir, float wishspeed, float accel)
{
        int		i;
		float	addspeed, accelspeed, currentspeed, wishspd = wishspeed;

		if (pm->ps->pm_type == PM_DEAD)
			return;
		if (pm->ps->pm_flags & PMF_TIME_WATERJUMP)
			return;

        if (wishspd > pm_qw_airstrafewishspeed)
                wishspd = pm_qw_airstrafewishspeed;

        currentspeed = DotProduct (pm->ps->velocity, wishdir);
        addspeed = wishspd - currentspeed;// See how much to add
        if (addspeed <= 0)// If not adding any, done.
                return;

        accelspeed = accel * wishspeed * pml.frametime * pm_qw_friction;// QUAKECLASSIC: accelspeed = accel * wishspeed * pmove->frametime * pmove->friction;

        if (accelspeed > addspeed) // Cap it
                accelspeed = addspeed;

        for (i=0 ; i<3 ; i++)// Adjust pmove vel.
               pm->ps->velocity[i] += accelspeed*wishdir[i];
}

void PM_AirAccelerateTribes(vec3_t wishdir, float wishspeed)
{
	int		i;
	float	addspeed, accelspeed, currentspeed, wishspd = wishspeed;

	if (pm->ps->pm_type == PM_DEAD)
		return;
	if (pm->ps->pm_flags & PMF_TIME_WATERJUMP)
		return;


	currentspeed = DotProduct(pm->ps->velocity, wishdir);
	addspeed = wishspd - currentspeed;// See how much to add
	if (addspeed <= 0)// If not adding any, done.
		return;

	accelspeed = pm_tribes_airaccelerate * wishspeed * pml.frametime * pm_tribes_airfriction;// QUAKECLASSIC: accelspeed = accel * wishspeed * pmove->frametime * pmove->friction;

	if (accelspeed > addspeed) // Cap it
		accelspeed = addspeed;

	//for (i = 0; i<3; i++)// Adjust pmove vel.


	if (0)
	{

		vec3_t tmpVel, oldVel;
		float oldSpeed, newSpeed;
		VectorCopy(pm->ps->velocity, tmpVel);
		oldVel[2] = 0;
		VectorCopy(tmpVel, oldVel);

		tmpVel[0] += accelspeed*wishdir[0];
		tmpVel[1] += accelspeed*wishdir[1];

		oldSpeed = oldVel[0] * oldVel[0] + oldVel[1] * oldVel[1];
		newSpeed = tmpVel[0] * tmpVel[0] + tmpVel[1] * tmpVel[1];

		if (newSpeed > oldSpeed) {
			//Com_Printf("Cutting by %.2f\n", (oldSpeed / newSpeed));   //why does this fuck up jetpack speed? we need to isolate the scaling to speed just created by this not jetpack
			//VectorScale(tmpVel, (oldSpeed / newSpeed), tmpVel);
		}

		tmpVel[2] = pm->ps->velocity[2];
		VectorCopy(tmpVel, pm->ps->velocity);

		pm->ps->velocity[2] += accelspeed*wishdir[2];
	}
	else {
		for (i = 0; i < 3; i++)// Adjust pmove vel.
			pm->ps->velocity[i] += accelspeed*wishdir[i];
	}





}

void PM_GroundAccelerateTribes(vec3_t wishdir, float wishspeed, float accel)
{
	int		i;
	float	addspeed, accelspeed, currentspeed, wishspd = wishspeed;

	if (pm->ps->pm_type == PM_DEAD)
		return;
	if (pm->ps->pm_flags & PMF_TIME_WATERJUMP)
		return;

	if (wishspd > pm_tribes_groundstrafewishspeed)
		wishspd = pm_tribes_groundstrafewishspeed;

	currentspeed = DotProduct(pm->ps->velocity, wishdir);
	addspeed = wishspd - currentspeed;// See how much to add
	if (addspeed <= 0)// If not adding any, done.
		return;

	accelspeed = accel * wishspeed * pml.frametime * pm_tribes_groundfriction;// QUAKECLASSIC: accelspeed = accel * wishspeed * pmove->frametime * pmove->friction;

	if (accelspeed > addspeed) // Cap it
		accelspeed = addspeed;

	for (i = 0; i<3; i++)// Adjust pmove vel.
		pm->ps->velocity[i] += accelspeed*wishdir[i];
}

/*
==============
PM_Accelerate

Handles user intended acceleration
==============
*/
static void PM_Accelerate( vec3_t wishdir, float wishspeed, float accel )
{
	if ((PM_GetMovePhysics() != MV_SIEGE) || pm->ps->m_iVehicleNum || pm->ps->clientNum >= MAX_CLIENTS || pm->ps->pm_type != PM_NORMAL)
	{ //standard method, allows "bunnyhopping" and whatnot
		int			i;
		float		addspeed, accelspeed, currentspeed;

		currentspeed = DotProduct (pm->ps->velocity, wishdir);
		addspeed = wishspeed - currentspeed;
		if (addspeed <= 0 && pm->ps->clientNum < MAX_CLIENTS) {
			return;
		}

		if (addspeed < 0)
		{
			accelspeed = (-accel)*pml.frametime*wishspeed;
			if (accelspeed < addspeed) {
				accelspeed = addspeed;
			}
		}
		else
		{
			accelspeed = accel*pml.frametime*wishspeed;
			if (accelspeed > addspeed) {
				accelspeed = addspeed;
			}
		}

		for (i=0 ; i<3 ; i++) {
			pm->ps->velocity[i] += accelspeed*wishdir[i];
		}
	}
	else
	{ //use the proper way for siege
		vec3_t		wishVelocity;
		vec3_t		pushDir;
		float		pushLen;
		float		canPush;

		VectorScale( wishdir, wishspeed, wishVelocity );
		VectorSubtract( wishVelocity, pm->ps->velocity, pushDir );
		pushLen = VectorNormalize( pushDir );

		canPush = accel*pml.frametime*wishspeed;
		if (canPush > pushLen) {
			canPush = pushLen;
		}

		VectorMA( pm->ps->velocity, canPush, pushDir, pm->ps->velocity );
	}
}

void CPM_PM_Aircontrol (pmove_t *pm, vec3_t wishdir, float wishspeed )
{
	float	zspeed, speed, dot, k;
	int		i;

	if ( (pm->ps->movementDir && pm->ps->movementDir !=4) || wishspeed == 0.0)
		return; // can't control movement if not moveing forward or backward

	zspeed = pm->ps->velocity[2];
	pm->ps->velocity[2] = 0;
	speed = VectorNormalize(pm->ps->velocity);

	dot = DotProduct(pm->ps->velocity,wishdir);
	k = 32;
	k *= pm_cpm_aircontrol*dot*dot*pml.frametime;


	if (dot > 0) {	// we can't change direction while slowing down
		for (i=0; i < 2; i++)
			pm->ps->velocity[i] = pm->ps->velocity[i]*speed + wishdir[i]*k;
		VectorNormalize(pm->ps->velocity);
	}

	for (i=0; i < 2; i++)
		pm->ps->velocity[i] *=speed;

	pm->ps->velocity[2] = zspeed;
}

/*
============
PM_CS_AirAccelerate

Gives you acceleration in-air looking a lot like CSGO.
============
*/
void PM_CS_AirAccelerate(vec3_t wishdir, float wishspeed, float accel)
{
	int i;
	float addspeed, accelspeed, currentspeed;
	float wishspd;

	wishspd = wishspeed;

	// Cap speed
	if (wishspd > 30.0f)
		wishspd = 30.0f;

	// Determine veer amount
	currentspeed = DotProduct(pm->ps->velocity, wishdir);

	// See how much to add
	addspeed = wishspd - currentspeed;

	// If not adding any, done.
	if (addspeed <= 0)
		return;

	// Determine acceleration speed after acceleration
	accelspeed = accel * wishspeed * pml.frametime * pm_friction;

	// Cap it
	if (accelspeed > addspeed)
		accelspeed = addspeed;

	// Adjust pmove vel.
	for (i = 0; i<3; i++)
	{
		pm->ps->velocity[i] += accelspeed*wishdir[i];
	}
}

/*
============
PM_CmdScale

Returns the scale factor to apply to cmd movements
This allows the clients to use axial -127 to 127 values for all directions
without getting a sqrt(2) distortion in speed.
============
*/
static float PM_CmdScale( usercmd_t *cmd ) {
	int		max;
	float	total;
	float	scale;
	int		umove = 0; //cmd->upmove;
			//don't factor upmove into scaling speed
	const int moveStyle = PM_GetMovePhysics();

	if (moveStyle == MV_OCPM || moveStyle == MV_TRIBES || moveStyle == MV_JETPACK) {
		umove = cmd->upmove;
	}
#if _SPPHYSICS
	else if (moveStyle == MV_SP) { //Oh no..
		umove = cmd->upmove;
	}
#endif

	max = abs( cmd->forwardmove );
	if ( abs( cmd->rightmove ) > max ) {
		max = abs( cmd->rightmove );
	}
	if ( abs( umove ) > max ) {
		max = abs( umove );
	}
	if ( !max ) {
		return 0;
	}

	total = sqrt((float)(cmd->forwardmove * cmd->forwardmove + cmd->rightmove * cmd->rightmove + umove * umove));
	scale = (float)pm->ps->speed * max / ( 127.0 * total );

	return scale;
}


/*
================
PM_SetMovementDir

Determine the rotation of the legs reletive
to the facing dir
================
*/
static void PM_SetMovementDir( void ) {
	if ( pm->cmd.forwardmove || pm->cmd.rightmove ) {
		if ( pm->cmd.rightmove == 0 && pm->cmd.forwardmove > 0 ) {
			pm->ps->movementDir = 0;
		} else if ( pm->cmd.rightmove < 0 && pm->cmd.forwardmove > 0 ) {
			pm->ps->movementDir = 1;
		} else if ( pm->cmd.rightmove < 0 && pm->cmd.forwardmove == 0 ) {
			pm->ps->movementDir = 2;
		} else if ( pm->cmd.rightmove < 0 && pm->cmd.forwardmove < 0 ) {
			pm->ps->movementDir = 3;
		} else if ( pm->cmd.rightmove == 0 && pm->cmd.forwardmove < 0 ) {
			pm->ps->movementDir = 4;
		} else if ( pm->cmd.rightmove > 0 && pm->cmd.forwardmove < 0 ) {
			pm->ps->movementDir = 5;
		} else if ( pm->cmd.rightmove > 0 && pm->cmd.forwardmove == 0 ) {
			pm->ps->movementDir = 6;
		} else if ( pm->cmd.rightmove > 0 && pm->cmd.forwardmove > 0 ) {
			pm->ps->movementDir = 7;
		}
	} else {
		// if they aren't actively going directly sideways,
		// change the animation to the diagonal so they
		// don't stop too crooked
		if ( pm->ps->movementDir == 2 ) {
			pm->ps->movementDir = 1;
		} else if ( pm->ps->movementDir == 6 ) {
			pm->ps->movementDir = 7;
		}
	}
}

#define METROID_JUMP 1

qboolean PM_ForceJumpingUp(void)
{
	int moveStyle;
	if ( !(pm->ps->fd.forcePowersActive&(1<<FP_LEVITATION)) && pm->ps->fd.forceJumpCharge )
	{//already jumped and let go
		return qfalse;
	}

	if ( BG_InSpecialJump( pm->ps->legsAnim ) )
	{
		return qfalse;
	}

	if (BG_SaberInSpecial(pm->ps->saberMove))
	{
		return qfalse;
	}

	if (BG_SaberInSpecialAttack(pm->ps->legsAnim))
	{
		return qfalse;
	}

	if (BG_HasYsalamiri(pm->gametype, pm->ps))
	{
		return qfalse;
	}

	moveStyle = PM_GetMovePhysics();

	if (moveStyle == MV_CPM || moveStyle == MV_Q3 || moveStyle == MV_WSW || moveStyle == MV_RJQ3 || moveStyle == MV_RJCPM || moveStyle == MV_JETPACK || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM || moveStyle == MV_OCPM || moveStyle == MV_TRIBES || moveStyle == MV_SURF)
		return qfalse;

	if (!BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION))
	{
		return qfalse;
	}

	if ( pm->ps->groundEntityNum == ENTITYNUM_NONE && //in air
		(pm->ps->pm_flags & PMF_JUMP_HELD) && //jumped
		pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_0 && //force-jump capable
		(pm->ps->velocity[2] > 0 || pm->ps->fd.forcePowerLevel[FP_LEVITATION] == FORCE_LEVEL_5) )//going up
	{
		return qtrue;
	}
	return qfalse;
}

static void PM_JumpForDir( void )
{
	int anim = BOTH_JUMP1;
	if ( pm->cmd.forwardmove > 0 )
	{
		anim = BOTH_JUMP1;
		pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
	}
	else if ( pm->cmd.forwardmove < 0 )
	{
		anim = BOTH_JUMPBACK1;
		pm->ps->pm_flags |= PMF_BACKWARDS_JUMP;
	}
	else if ( pm->cmd.rightmove > 0 )
	{
		anim = BOTH_JUMPRIGHT1;
		pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
	}
	else if ( pm->cmd.rightmove < 0 )
	{
		anim = BOTH_JUMPLEFT1;
		pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
	}
	else
	{
		anim = BOTH_JUMP1;
		pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
	}
	if(!BG_InDeathAnim(pm->ps->legsAnim))
	{
		PM_SetAnim(SETANIM_LEGS,anim,SETANIM_FLAG_OVERRIDE);
	}
}

void PM_SetPMViewAngle(playerState_t *ps, vec3_t angle, usercmd_t *ucmd)
{
	int			i;

	for (i=0 ; i<3 ; i++)
	{ // set the delta angle
		int		cmdAngle;

		cmdAngle = ANGLE2SHORT(angle[i]);
		ps->delta_angles[i] = cmdAngle - ucmd->angles[i];
	}
	VectorCopy (angle, ps->viewangles);
}

qboolean PM_AdjustAngleForWallRun( playerState_t *ps, usercmd_t *ucmd, qboolean doMove )
{
	if (( (ps->legsAnim) == BOTH_WALL_RUN_RIGHT || (ps->legsAnim) == BOTH_WALL_RUN_LEFT ) && ps->legsTimer > 500 )
	{//wall-running and not at end of anim
		//stick to wall, if there is one
		vec3_t	fwd, rt, traceTo, mins, maxs, fwdAngles;
		trace_t	trace;
		float	dist, yawAdjust;

		VectorSet(mins, -15, -15, 0);
		VectorSet(maxs, 15, 15, 24);
		VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

		AngleVectors( fwdAngles, fwd, rt, NULL );
		if ( (ps->legsAnim) == BOTH_WALL_RUN_RIGHT )
		{
			dist = 128;
			yawAdjust = -90;
		}
		else
		{
			dist = -128;
			yawAdjust = 90;
		}
		VectorMA( ps->origin, dist, rt, traceTo );

		pm->trace( &trace, ps->origin, mins, maxs, traceTo, ps->clientNum, MASK_PLAYERSOLID );

		if ( trace.fraction < 1.0f
			&& (trace.plane.normal[2] >= 0.0f && trace.plane.normal[2] <= 0.4f) )//&& ent->client->ps.groundEntityNum == ENTITYNUM_NONE )
		{
			trace_t	trace2;
			vec3_t traceTo2;
			vec3_t	wallRunFwd, wallRunAngles;

			VectorClear( wallRunAngles );
			wallRunAngles[YAW] = vectoyaw( trace.plane.normal )+yawAdjust;
			AngleVectors( wallRunAngles, wallRunFwd, NULL, NULL );

			VectorMA( pm->ps->origin, 32, wallRunFwd, traceTo2 );
			pm->trace( &trace2, pm->ps->origin, mins, maxs, traceTo2, pm->ps->clientNum, MASK_PLAYERSOLID );
			if ( trace2.fraction < 1.0f && DotProduct( trace2.plane.normal, wallRunFwd ) <= -0.999f )
			{//wall we can't run on in front of us
				trace.fraction = 1.0f;//just a way to get it to kick us off the wall below
			}
		}

		if ( trace.fraction < 1.0f
			&& (trace.plane.normal[2] >= 0.0f&&trace.plane.normal[2] <= 0.4f/*MAX_WALL_RUN_Z_NORMAL*/) )
		{//still a wall there
			if ( (ps->legsAnim) == BOTH_WALL_RUN_RIGHT )
			{
				ucmd->rightmove = 127;
			}
			else
			{
				ucmd->rightmove = -127;
			}
			if ( ucmd->upmove < 0 )
			{
				ucmd->upmove = 0;
			}
			//make me face perpendicular to the wall
			ps->viewangles[YAW] = vectoyaw( trace.plane.normal )+yawAdjust;

			PM_SetPMViewAngle(ps, ps->viewangles, ucmd);

			ucmd->angles[YAW] = ANGLE2SHORT( ps->viewangles[YAW] ) - ps->delta_angles[YAW];
			if ( doMove )
			{
				//push me forward
				float	zVel = ps->velocity[2];
				if ( ps->legsTimer > 500 )
				{//not at end of anim yet
					float speed = 175;
					if ( ucmd->forwardmove < 0 )
					{//slower
						speed = 100;
					}
					else if ( ucmd->forwardmove > 0 )
					{
						speed = 250;//running speed
					}
					VectorScale( fwd, speed, ps->velocity );
				}
				ps->velocity[2] = zVel;//preserve z velocity
				//pull me toward the wall, too
				VectorMA( ps->velocity, dist, rt, ps->velocity );
			}
			ucmd->forwardmove = 0;
			return qtrue;
		}
		else if ( doMove )
		{//stop it
			if ( (ps->legsAnim) == BOTH_WALL_RUN_RIGHT )
			{
				PM_SetAnim(SETANIM_BOTH, BOTH_WALL_RUN_RIGHT_STOP, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			}
			else if ( (ps->legsAnim) == BOTH_WALL_RUN_LEFT )
			{
				PM_SetAnim(SETANIM_BOTH, BOTH_WALL_RUN_LEFT_STOP, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			}
		}
	}

	return qfalse;
}

qboolean PM_AdjustAnglesForWallRunUpFlipAlt( usercmd_t *ucmd )
{
//	ucmd->angles[PITCH] = ANGLE2SHORT( pm->ps->viewangles[PITCH] ) - pm->ps->delta_angles[PITCH];
//	ucmd->angles[YAW] = ANGLE2SHORT( pm->ps->viewangles[YAW] ) - pm->ps->delta_angles[YAW];
	PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, ucmd);
	return qtrue;
}

qboolean PM_AdjustAngleForWallRunUp( playerState_t *ps, usercmd_t *ucmd, qboolean doMove )
{
	if ( ps->legsAnim == BOTH_FORCEWALLRUNFLIP_START )
	{//wall-running up
		//stick to wall, if there is one
		vec3_t	fwd, traceTo, mins, maxs, fwdAngles;
		trace_t	trace;
		float	dist = 128;

		VectorSet(mins, -15,-15,0);
		VectorSet(maxs, 15,15,24);
		VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

		AngleVectors( fwdAngles, fwd, NULL, NULL );
		VectorMA( ps->origin, dist, fwd, traceTo );
		pm->trace( &trace, ps->origin, mins, maxs, traceTo, ps->clientNum, MASK_PLAYERSOLID );
		if ( trace.fraction > 0.5f )
		{//hmm, some room, see if there's a floor right here
			trace_t	trace2;
			vec3_t	top, bottom;

			VectorCopy( trace.endpos, top );
			top[2] += (pm->mins[2]*-1) + 4.0f;
			VectorCopy( top, bottom );
			bottom[2] -= 64.0f;
			pm->trace( &trace2, top, pm->mins, pm->maxs, bottom, ps->clientNum, MASK_PLAYERSOLID );
			if ( !trace2.allsolid
				&& !trace2.startsolid
				&& trace2.fraction < 1.0f
				&& trace2.plane.normal[2] > 0.7f )//slope we can stand on
			{//cool, do the alt-flip and land on whetever it is we just scaled up
				VectorScale( fwd, 100, pm->ps->velocity );
				pm->ps->velocity[2] += 400;
				PM_SetAnim(SETANIM_BOTH, BOTH_FORCEWALLRUNFLIP_ALT, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
				pm->ps->pm_flags |= PMF_JUMP_HELD;
				//ent->client->ps.pm_flags |= PMF_JUMPING|PMF_SLOW_MO_FALL;
				//ent->client->ps.forcePowersActive |= (1<<FP_LEVITATION);
				//G_AddEvent( ent, EV_JUMP, 0 );
				PM_AddEvent(EV_JUMP);
				ucmd->upmove = 0;
				return qfalse;
			}
		}

		//Forwardmove is 0 here when it shouldnt be with lowfps due to chopping
		if ( //ucmd->upmove <= 0 &&
			ps->legsTimer > 0 &&
			ucmd->forwardmove > 0 &&
			trace.fraction < 1.0f &&
			(trace.plane.normal[2] >= 0.0f&&trace.plane.normal[2]<=0.4f/*MAX_WALL_RUN_Z_NORMAL*/) )
		{//still a vertical wall there
			//make sure there's not a ceiling above us!
			trace_t	trace2;
			VectorCopy( ps->origin, traceTo );
			traceTo[2] += 64;
			pm->trace( &trace2, ps->origin, mins, maxs, traceTo, ps->clientNum, MASK_PLAYERSOLID );
			if ( trace2.fraction < 1.0f )
			{//will hit a ceiling, so force jump-off right now
				//NOTE: hits any entity or clip brush in the way, too, not just architecture!
			}
			else
			{//all clear, keep going
				//FIXME: don't pull around 90 turns
				//FIXME: simulate stepping up steps here, somehow?
				ucmd->forwardmove = 127;
				if ( ucmd->upmove < 0 )
				{
					ucmd->upmove = 0;
				}
				//make me face the wall
				ps->viewangles[YAW] = vectoyaw( trace.plane.normal )+180;
				PM_SetPMViewAngle(ps, ps->viewangles, ucmd);
				/*
				if ( ent->client->ps.viewEntity <= 0 || ent->client->ps.viewEntity >= ENTITYNUM_WORLD )
				{//don't clamp angles when looking through a viewEntity
					SetClientViewAngle( ent, ent->client->ps.viewangles );
				}
				*/
				ucmd->angles[YAW] = ANGLE2SHORT( ps->viewangles[YAW] ) - ps->delta_angles[YAW];
				//if ( ent->s.number || !player_locked )
				if (1) //aslkfhsakf
				{
					if ( doMove )
					{
						//pull me toward the wall
						VectorScale( trace.plane.normal, -dist*trace.fraction, ps->velocity );
						//push me up
						if ( ps->legsTimer > 200 )
						{//not at end of anim yet
							float speed = 300;
							/*
							if ( ucmd->forwardmove < 0 )
							{//slower
								speed = 100;
							}
							else if ( ucmd->forwardmove > 0 )
							{
								speed = 250;//running speed
							}
							*/
							ps->velocity[2] = speed;//preserve z velocity
						}
					}
				}
				if (pmove_fixed.integer || (ps->stats[STAT_RACEMODE] && pml.msec == 16)) { //chopping, chopped
				}
				else//JAPRO Fix Pmove Wallrun, only if they are in pmove or racemode
					ucmd->forwardmove = 0;
				return qtrue;
			}
		}
		//failed!
		if ( doMove )
		{//stop it
			VectorScale( fwd, -300.0f, ps->velocity );
			ps->velocity[2] += 200;
			//NPC_SetAnim( ent, SETANIM_BOTH, BOTH_FORCEWALLRUNFLIP_END, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
			//why?!?#?#@!%$R@$KR#F:Hdl;asfm
			PM_SetAnim(SETANIM_BOTH, BOTH_FORCEWALLRUNFLIP_END, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			ps->pm_flags |= PMF_JUMP_HELD;
			//ent->client->ps.pm_flags |= PMF_JUMPING|PMF_SLOW_MO_FALL;

			//FIXME do I need this in mp?
			//ent->client->ps.forcePowersActive |= (1<<FP_LEVITATION);
			PM_AddEvent(EV_JUMP);
			ucmd->upmove = 0;
			//return qtrue;
		}
	}
	return qfalse;
}

#define	JUMP_OFF_WALL_SPEED	200.0f
//nice...
static float BG_ForceWallJumpStrength( void )
{
	return (forceJumpStrength[FORCE_LEVEL_3]/2.5f);
}

qboolean PM_AdjustAngleForWallJump( playerState_t *ps, usercmd_t *ucmd, qboolean doMove )
{
	if ( ( ( BG_InReboundJump( ps->legsAnim ) || BG_InReboundHold( ps->legsAnim ) )
			&& ( BG_InReboundJump( ps->torsoAnim ) || BG_InReboundHold( ps->torsoAnim ) ) )
		|| (pm->ps->pm_flags&PMF_STUCK_TO_WALL) )
	{//hugging wall, getting ready to jump off
		//stick to wall, if there is one
		vec3_t	checkDir, traceTo, mins, maxs, fwdAngles;
		trace_t	trace;
		float	dist = 128.0f, yawAdjust;

		VectorSet(mins, pm->mins[0],pm->mins[1],0);
		VectorSet(maxs, pm->maxs[0],pm->maxs[1],24);
		VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

		switch ( ps->legsAnim )
		{
		case BOTH_FORCEWALLREBOUND_RIGHT:
		case BOTH_FORCEWALLHOLD_RIGHT:
			AngleVectors( fwdAngles, NULL, checkDir, NULL );
			yawAdjust = -90;
			break;
		case BOTH_FORCEWALLREBOUND_LEFT:
		case BOTH_FORCEWALLHOLD_LEFT:
			AngleVectors( fwdAngles, NULL, checkDir, NULL );
			VectorScale( checkDir, -1, checkDir );
			yawAdjust = 90;
			break;
		case BOTH_FORCEWALLREBOUND_FORWARD:
		case BOTH_FORCEWALLHOLD_FORWARD:
			AngleVectors( fwdAngles, checkDir, NULL, NULL );
			yawAdjust = 180;
			break;
		case BOTH_FORCEWALLREBOUND_BACK:
		case BOTH_FORCEWALLHOLD_BACK:
			AngleVectors( fwdAngles, checkDir, NULL, NULL );
			VectorScale( checkDir, -1, checkDir );
			yawAdjust = 0;
			break;
		default:
			//WTF???
			pm->ps->pm_flags &= ~PMF_STUCK_TO_WALL;
			return qfalse;
			break;
		}
//[JAPRO - Serverside + Clientside - Physics - Change g_debugmelee 1 so that it has kungfu moves but keeps normal wallgrab.  Create g_debugmelee 2 for kung fu moves and infinite wallgrab - Start]
#ifdef _GAME
		if (1) //uhhh
#else
		if (cgs.serverMod >= SVMOD_JAPLUS)
#endif
		{
			if ( pm->debugMelee > 1)
			{//uber-skillz
				if ( ucmd->upmove > 0 )
				{//hold on until you let go manually
					if ( BG_InReboundHold( ps->legsAnim ) )
					{//keep holding
						if ( ps->legsTimer < 150 )
						{
							ps->legsTimer = 150;
						}
					}
					else
					{//if got to hold part of anim, play hold anim
						if ( ps->legsTimer <= 300 )
						{
							ps->saberHolstered = 2;
							PM_SetAnim( SETANIM_BOTH, BOTH_FORCEWALLRELEASE_FORWARD+(ps->legsAnim-BOTH_FORCEWALLHOLD_FORWARD), SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
							ps->legsTimer = ps->torsoTimer = 150;
						}
					}
				}
			}
#ifdef _CGAME
			if (cgs.serverMod == SVMOD_JAPLUS)
				PM_UpdateViewAngles(ps, ucmd); //update here for vertical freelook prediction
#endif
		}
		else if ( pm->debugMelee )
		{//uber-skillz
			if ( ucmd->upmove > 0 )
			{//hold on until you let go manually
				if ( BG_InReboundHold( ps->legsAnim ) )
				{//keep holding
					if ( ps->legsTimer < 150 )
					{
						ps->legsTimer = 150;
					}
				}
				else
				{//if got to hold part of anim, play hold anim
					if ( ps->legsTimer <= 300 )
					{
						ps->saberHolstered = 2;
						PM_SetAnim( SETANIM_BOTH, BOTH_FORCEWALLRELEASE_FORWARD+(ps->legsAnim-BOTH_FORCEWALLHOLD_FORWARD), SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						ps->legsTimer = ps->torsoTimer = 150;
					}
				}
			}
		}
//[JAPRO - Serverside + Clientside - Physics - Change g_debugmelee 1 so that it has kungfu moves but keeps normal wallgrab.  Create g_debugmelee 2 for kung fu moves and infinite wallgrab - End]
		VectorMA( ps->origin, dist, checkDir, traceTo );
		pm->trace( &trace, ps->origin, mins, maxs, traceTo, ps->clientNum, MASK_PLAYERSOLID );
		if ( //ucmd->upmove <= 0 &&
			ps->legsTimer > 100 &&
			trace.fraction < 1.0f &&
			fabs(trace.plane.normal[2]) <= 0.2f/*MAX_WALL_GRAB_SLOPE*/ )
		{//still a vertical wall there
			//FIXME: don't pull around 90 turns
			/*
			if ( ent->s.number || !player_locked )
			{
				ucmd->forwardmove = 127;
			}
			*/
			if ( ucmd->upmove < 0 )
			{
				ucmd->upmove = 0;
			}
			//align me to the wall
			ps->viewangles[YAW] = vectoyaw( trace.plane.normal )+yawAdjust;
			PM_SetPMViewAngle(ps, ps->viewangles, ucmd);
			/*
			if ( ent->client->ps.viewEntity <= 0 || ent->client->ps.viewEntity >= ENTITYNUM_WORLD )
			{//don't clamp angles when looking through a viewEntity
				SetClientViewAngle( ent, ent->client->ps.viewangles );
			}
			*/
			ucmd->angles[YAW] = ANGLE2SHORT( ps->viewangles[YAW] ) - ps->delta_angles[YAW];
			//if ( ent->s.number || !player_locked )
			if (1)
			{
				if ( doMove )
				{
					//pull me toward the wall
					VectorScale( trace.plane.normal, -128.0f, ps->velocity );
				}
			}
			ucmd->upmove = 0;
			ps->pm_flags |= PMF_STUCK_TO_WALL;
			return qtrue;
		}
		else if ( doMove
			&& (ps->pm_flags&PMF_STUCK_TO_WALL))
		{//jump off - loda - MV_JETPACK spiderman
			//push off of it!
			ps->pm_flags &= ~PMF_STUCK_TO_WALL;
			ps->velocity[0] = ps->velocity[1] = 0;
			if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_JETPACK)
				VectorScale(checkDir, -JUMP_OFF_WALL_SPEED*2.5f, ps->velocity);
			else
				VectorScale( checkDir, -JUMP_OFF_WALL_SPEED, ps->velocity );
			ps->velocity[2] = BG_ForceWallJumpStrength();
			ps->pm_flags |= PMF_JUMP_HELD;//PMF_JUMPING|PMF_JUMP_HELD;
			//G_SoundOnEnt( ent, CHAN_BODY, "sound/weapons/force/jump.wav" );
			ps->fd.forceJumpSound = 1; //this is a stupid thing, i should fix it.
			//ent->client->ps.forcePowersActive |= (1<<FP_LEVITATION);
			if (ps->origin[2] < ps->fd.forceJumpZStart)
			{
				ps->fd.forceJumpZStart = ps->origin[2];
			}
			//FIXME do I need this?

			BG_ForcePowerDrain( ps, FP_LEVITATION, 10 );
			//no control for half a second
			ps->pm_flags |= PMF_TIME_KNOCKBACK;
			ps->pm_time = 500;
			ucmd->forwardmove = 0;
			ucmd->rightmove = 0;
			ucmd->upmove = 127;

			if ( BG_InReboundHold( ps->legsAnim ) )
			{//if was in hold pose, release now
				PM_SetAnim( SETANIM_BOTH, BOTH_FORCEWALLRELEASE_FORWARD+(ps->legsAnim-BOTH_FORCEWALLHOLD_FORWARD), SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
			}
			else
			{
				//PM_JumpForDir();
				PM_SetAnim(SETANIM_LEGS,BOTH_FORCEJUMP1,SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_RESTART);
			}

			//return qtrue;
		}
	}
	ps->pm_flags &= ~PMF_STUCK_TO_WALL;
	return qfalse;
}

//Set the height for when a force jump was started. If it's 0, nuge it up (slight hack to prevent holding jump over slopes)
void PM_SetForceJumpZStart(float value)
{
	pm->ps->fd.forceJumpZStart = value;
	if (!pm->ps->fd.forceJumpZStart)
	{
		pm->ps->fd.forceJumpZStart -= 0.1f;
	}
}

float forceJumpHeightMax[NUM_FORCE_POWER_LEVELS] =
{
	66,//normal jump (32+stepheight(18)+crouchdiff(24) = 74)
	130,//(96+stepheight(18)+crouchdiff(24) = 138)
	226,//(192+stepheight(18)+crouchdiff(24) = 234)
	418//(384+stepheight(18)+crouchdiff(24) = 426)
};

void PM_GrabWallForJump( int anim )
{//NOTE!!! assumes an appropriate anim is being passed in!!!
	PM_SetAnim( SETANIM_BOTH, anim, SETANIM_FLAG_RESTART|SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
	PM_AddEvent( EV_JUMP );//make sound for grab
	pm->ps->pm_flags |= PMF_STUCK_TO_WALL;
}



static qboolean PM_CheckJumpLugormod( void ) 
{
	qboolean allowFlips = qtrue;

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		bgEntity_t *pEnt = pm_entSelf;

		if (pEnt->s.eType == ET_NPC &&
			pEnt->s.NPC_class == CLASS_VEHICLE)
		{ //no!
			return qfalse;
		}
	}

	if (pm->ps->forceHandExtend == HANDEXTEND_KNOCKDOWN ||
		pm->ps->forceHandExtend == HANDEXTEND_PRETHROWN ||
		pm->ps->forceHandExtend == HANDEXTEND_POSTTHROWN)
	{
		return qfalse;
	}

	if (pm->ps->pm_type == PM_JETPACK)
	{ //there's no actual jumping while we jetpack
		return qfalse;
	}

	//Don't allow jump until all buttons are up
	if ( pm->ps->pm_flags & PMF_RESPAWNED ) {
		return qfalse;		
	}

	if ( PM_InKnockDown( pm->ps ) || BG_InRoll( pm->ps, pm->ps->legsAnim ) ) 
	{//in knockdown
		return qfalse;		
	}

	if ( pm->ps->weapon == WP_SABER )
	{
		saberInfo_t *saber1 = BG_MySaber( pm->ps->clientNum, 0 );
		saberInfo_t *saber2 = BG_MySaber( pm->ps->clientNum, 1 );
		if ( saber1
			&& (saber1->saberFlags&SFL_NO_FLIPS) )
		{
			allowFlips = qfalse;
		}
		if ( saber2
			&& (saber2->saberFlags&SFL_NO_FLIPS) )
		{
			allowFlips = qfalse;
		}
	}

	if (pm->ps->groundEntityNum != ENTITYNUM_NONE 
		|| (pm->ps->origin[2] < pm->ps->fd.forceJumpZStart 
		&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] < FORCE_LEVEL_5))
	{
		pm->ps->fd.forcePowersActive &= ~(1<<FP_LEVITATION);
	}

	if (pm->ps->fd.forcePowersActive & (1 << FP_LEVITATION))
	{ //Force jump is already active.. continue draining power appropriately until we land.

		if (pm->ps->fd.forcePowerDebounce[FP_LEVITATION] < pm->cmd.serverTime)
		{
			if ( pm->gametype == GT_DUEL 
				|| pm->gametype == GT_POWERDUEL )
			{//jump takes less power
				BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 1 );
			}
			else
			{
				BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );
			}
			if (pm->ps->fd.forcePowerLevel[FP_LEVITATION] >= FORCE_LEVEL_2)
			{
				pm->ps->fd.forcePowerDebounce[FP_LEVITATION] = pm->cmd.serverTime + 300;
			}
			else
			{
				pm->ps->fd.forcePowerDebounce[FP_LEVITATION] = pm->cmd.serverTime + 200;
			}
		}
	}

	if (pm->ps->forceJumpFlip)
	{ //Forced jump anim
		int anim = BOTH_FORCEINAIR1;
		int	parts = SETANIM_BOTH;
		if ( allowFlips )
		{
			if ( pm->cmd.forwardmove > 0 )
			{
				anim = BOTH_FLIP_F;
			}
			else if ( pm->cmd.forwardmove < 0 )
			{
				anim = BOTH_FLIP_B;
			}
			else if ( pm->cmd.rightmove > 0 )
			{
				anim = BOTH_FLIP_R;
			}
			else if ( pm->cmd.rightmove < 0 )
			{
				anim = BOTH_FLIP_L;
			}
		}
		else
		{
			if ( pm->cmd.forwardmove > 0 )
			{
				anim = BOTH_FORCEINAIR1;
			}
			else if ( pm->cmd.forwardmove < 0 )
			{
				anim = BOTH_FORCEINAIRBACK1;
			}
			else if ( pm->cmd.rightmove > 0 )
			{
				anim = BOTH_FORCEINAIRRIGHT1;
			}
			else if ( pm->cmd.rightmove < 0 )
			{
				anim = BOTH_FORCEINAIRLEFT1;
			}
		}
		if ( pm->ps->weaponTime )
		{//FIXME: really only care if we're in a saber attack anim...
			parts = SETANIM_LEGS;
		}

		PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
		pm->ps->forceJumpFlip = qfalse;
		return qtrue;
	}
#if METROID_JUMP
	if ( pm->waterlevel < 2 ) 
	{
		if ( pm->ps->gravity > 0 )
		{//can't do this in zero-G
			if ( PM_ForceJumpingUp() )
			{//holding jump in air
				float curHeight = pm->ps->origin[2] - pm->ps->fd.forceJumpZStart;
				//Lugormod size scale stuff
				curHeight /= scaleh;

				//check for max force jump level and cap off & cut z vel
				if ( ( curHeight<=forceJumpHeight[0] ||//still below minimum jump height
					(pm->ps->fd.forcePower&&pm->cmd.upmove>=10) ) &&////still have force power available and still trying to jump up 
					curHeight < forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] &&
					pm->ps->fd.forceJumpZStart)//still below maximum jump height
				{//can still go up
					if ( curHeight > forceJumpHeight[0] )
					{//passed normal jump height  *2?
						if ( !(pm->ps->fd.forcePowersActive&(1<<FP_LEVITATION)) )//haven't started forcejump yet
						{
							//start force jump
							pm->ps->fd.forcePowersActive |= (1<<FP_LEVITATION);
							pm->ps->fd.forceJumpSound = 1;
							//play flip
							if ((pm->cmd.forwardmove || pm->cmd.rightmove) && //pushing in a dir
								(pm->ps->legsAnim) != BOTH_FLIP_F &&//not already flipping
								(pm->ps->legsAnim) != BOTH_FLIP_B &&
								(pm->ps->legsAnim) != BOTH_FLIP_R &&
								(pm->ps->legsAnim) != BOTH_FLIP_L 
								&& allowFlips )
							{ 
								int anim = BOTH_FORCEINAIR1;
								int	parts = SETANIM_BOTH;

								if ( pm->cmd.forwardmove > 0 )
								{
									anim = BOTH_FLIP_F;
								}
								else if ( pm->cmd.forwardmove < 0 )
								{
									anim = BOTH_FLIP_B;
								}
								else if ( pm->cmd.rightmove > 0 )
								{
									anim = BOTH_FLIP_R;
								}
								else if ( pm->cmd.rightmove < 0 )
								{
									anim = BOTH_FLIP_L;
								}
								if ( pm->ps->weaponTime )
								{
									parts = SETANIM_LEGS;
								}

								PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
							}
							else if ( pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
							{
								vec3_t facingFwd, facingRight, facingAngles;
								int	anim = -1;
								float dotR, dotF;

								VectorSet(facingAngles, 0, pm->ps->viewangles[YAW], 0);

								AngleVectors( facingAngles, facingFwd, facingRight, NULL );
								dotR = DotProduct( facingRight, pm->ps->velocity );
								dotF = DotProduct( facingFwd, pm->ps->velocity );

								if ( fabs(dotR) > fabs(dotF) * 1.5 )
								{
									if ( dotR > 150 )
									{
										anim = BOTH_FORCEJUMPRIGHT1;
									}
									else if ( dotR < -150 )
									{
										anim = BOTH_FORCEJUMPLEFT1;
									}
								}
								else
								{
									if ( dotF > 150 )
									{
										anim = BOTH_FORCEJUMP1;
									}
									else if ( dotF < -150 )
									{
										anim = BOTH_FORCEJUMPBACK1;
									}
								}
								if ( anim != -1 )
								{
									int parts = SETANIM_BOTH;
									if ( pm->ps->weaponTime )
									{//FIXME: really only care if we're in a saber attack anim...
										parts = SETANIM_LEGS;
									}

									PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
								}
							}
						}
						else
						{ //jump is already active (the anim has started)
							if ( pm->ps->legsTimer < 1 )
							{//not in the middle of a legsAnim
								int anim = (pm->ps->legsAnim);
								int newAnim = -1;
								switch ( anim )
								{
								case BOTH_FORCEJUMP1:
									newAnim = BOTH_FORCELAND1;//BOTH_FORCEINAIR1;
									break;
								case BOTH_FORCEJUMPBACK1:
									newAnim = BOTH_FORCELANDBACK1;//BOTH_FORCEINAIRBACK1;
									break;
								case BOTH_FORCEJUMPLEFT1:
									newAnim = BOTH_FORCELANDLEFT1;//BOTH_FORCEINAIRLEFT1;
									break;
								case BOTH_FORCEJUMPRIGHT1:
									newAnim = BOTH_FORCELANDRIGHT1;//BOTH_FORCEINAIRRIGHT1;
									break;
								}
								if ( newAnim != -1 )
								{
									int parts = SETANIM_BOTH;
									if ( pm->ps->weaponTime )
									{
										parts = SETANIM_LEGS;
									}

									PM_SetAnim( parts, newAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
								}
							}
						}
					}

					//need to scale this down, start with height velocity (based on max force jump height) and scale down to regular jump vel
					//Lugormod
					if (pm->ps->fd.forcePowerLevel[FP_LEVITATION] == FORCE_LEVEL_5
						&& pm->ps->groundEntityNum == ENTITYNUM_NONE) {
							vec_t velocity = (forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]-curHeight)/forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]*forceJumpStrength[pm->ps->fd.forcePowerLevel[FP_LEVITATION]];//JUMP_VELOCITY;
							velocity /= 10;
							velocity += JUMP_VELOCITY;
							//Lugormod scale
							//pm->ps->velocity[2] *= scaleh;
							velocity *= sqrt(scaleh);
							//pm->ps->pm_flags |= PMF_JUMP_HELD;
							if (pm->ps->velocity[2] < velocity) {
								pm->ps->velocity[2] += pm->ps->gravity * pml.frametime + JUMP_VELOCITY/2;
							} else {
								pm->ps->velocity[2] = velocity;
							}
					} 
					else
					{
						pm->ps->velocity[2] = (forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]-curHeight)/forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]*forceJumpStrength[pm->ps->fd.forcePowerLevel[FP_LEVITATION]];//JUMP_VELOCITY;
						pm->ps->velocity[2] /= 10;
						pm->ps->velocity[2] += JUMP_VELOCITY;
						//Lugormod scale
						//pm->ps->velocity[2] *= scaleh;
						pm->ps->velocity[2] *= sqrt(scaleh);
					}
					if (!(pm->ps->pm_flags & PMF_JUMP_HELD)) {
						BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );
					}


				}
				else if ( curHeight > forceJumpHeight[0] && curHeight < forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] - forceJumpHeight[0] )
				{//still have some headroom, don't totally stop it
					if ( pm->ps->velocity[2] > JUMP_VELOCITY )
					{
						pm->ps->velocity[2] = JUMP_VELOCITY;
					}
				}
				else
				{
					//pm->ps->velocity[2] = 0;
					//rww - changed for the sake of balance in multiplayer

					if ( pm->ps->velocity[2] > JUMP_VELOCITY )
					{
						pm->ps->velocity[2] = JUMP_VELOCITY;
					}
				}
				pm->cmd.upmove = 0;
				return qfalse;
			}
		}
	}

#endif

	//Not jumping
	if ( pm->cmd.upmove < 10 && pm->ps->groundEntityNum != ENTITYNUM_NONE) {
		return qfalse;
	}

	// must wait for jump to be released
	if ( pm->ps->pm_flags & PMF_JUMP_HELD )
	{
		// clear upmove so cmdscale doesn't lower running speed
		pm->cmd.upmove = 0;
		return qfalse;
	}

	if ( pm->ps->gravity <= 0 )
	{//in low grav, you push in the dir you're facing as long as there is something behind you to shove off of
		vec3_t	forward, back;
		trace_t	trace;

		AngleVectors( pm->ps->viewangles, forward, NULL, NULL );
		VectorMA( pm->ps->origin, -8, forward, back );
		pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, back, pm->ps->clientNum, pm->tracemask );

		if ( trace.fraction <= 1.0f )
		{
			VectorMA( pm->ps->velocity, JUMP_VELOCITY*2, forward, pm->ps->velocity );
			PM_SetAnim(SETANIM_LEGS,BOTH_FORCEJUMP1,SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_RESTART);
		}//else no surf close enough to push off of
		pm->cmd.upmove = 0;
	}
	else if ( pm->cmd.upmove > 0 && pm->waterlevel < 2 &&
		pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_0 &&
		!(pm->ps->pm_flags&PMF_JUMP_HELD) &&
		(pm->ps->weapon == WP_SABER || pm->ps->weapon == WP_MELEE) &&
		!PM_IsRocketTrooper() &&
		!BG_HasYsalamiri(pm->gametype, pm->ps) &&
		BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION) )
	{
		qboolean allowWallRuns = qtrue;
		qboolean allowWallFlips = qtrue;
		qboolean allowFlips = qtrue;
		qboolean allowWallGrabs = qtrue;
		if ( pm->ps->weapon == WP_SABER )
		{
			saberInfo_t *saber1 = BG_MySaber( pm->ps->clientNum, 0 );
			saberInfo_t *saber2 = BG_MySaber( pm->ps->clientNum, 1 );

			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_RUNS) )
			{
				allowWallRuns = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_RUNS) )
			{
				allowWallRuns = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_FLIPS) )
			{
				allowWallFlips = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_FLIPS) )
			{
				allowWallFlips = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_FLIPS) )
			{
				allowFlips = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_FLIPS) )
			{
				allowFlips = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_GRAB) )
			{
				allowWallGrabs = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_GRAB) )
			{
				allowWallGrabs = qfalse;
			}
		}

		if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
		{//on the ground
			//check for left-wall and right-wall special jumps
			int anim = -1;
			float	vertPush = 0;
			if ( pm->cmd.rightmove > 0 && pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
			{//strafing right
				if ( pm->cmd.forwardmove > 0 )
				{//wall-run
					if ( allowWallRuns )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.0f;
						anim = BOTH_WALL_RUN_RIGHT;
					}
				}
				else if ( pm->cmd.forwardmove == 0 )
				{//wall-flip
					if ( allowWallFlips )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
						anim = BOTH_WALL_FLIP_RIGHT;
					}
				}
			}
			else if ( pm->cmd.rightmove < 0 && pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
			{//strafing left
				if ( pm->cmd.forwardmove > 0 )
				{//wall-run
					if ( allowWallRuns )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.0f;
						anim = BOTH_WALL_RUN_LEFT;
					}
				}
				else if ( pm->cmd.forwardmove == 0 )
				{//wall-flip
					if ( allowWallFlips )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
						anim = BOTH_WALL_FLIP_LEFT;
					}
				}
			}
			else if ( pm->cmd.forwardmove < 0 && !(pm->cmd.buttons&BUTTON_ATTACK) )
			{//backflip
				if ( allowFlips )
				{
					vertPush = JUMP_VELOCITY;
					anim = BOTH_FLIP_BACK1;//BG_PickAnim( BOTH_FLIP_BACK1, BOTH_FLIP_BACK3 );
				}
			}

			vertPush += 128; //give them an extra shove

			if ( anim != -1 )
			{
				vec3_t fwd, right, traceto, mins, maxs, fwdAngles;
				vec3_t	idealNormal={0}, wallNormal={0};
				trace_t	trace;
				qboolean doTrace = qfalse;
				int contents = MASK_SOLID;//MASK_PLAYERSOLID;

				VectorSet(mins, pm->mins[0],pm->mins[1],0);
				//Lugormod scale here ?
				VectorSet(maxs, pm->maxs[0],pm->maxs[1],24);// * scaleh);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				memset(&trace, 0, sizeof(trace)); //to shut the compiler up

				AngleVectors( fwdAngles, fwd, right, NULL );

				//trace-check for a wall, if necc.
				switch ( anim )
				{
				case BOTH_WALL_FLIP_LEFT:
					//NOTE: purposely falls through to next case!
				case BOTH_WALL_RUN_LEFT:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, -16, right, traceto );
					break;

				case BOTH_WALL_FLIP_RIGHT:
					//NOTE: purposely falls through to next case!
				case BOTH_WALL_RUN_RIGHT:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, 16, right, traceto );
					break;

				case BOTH_WALL_FLIP_BACK1:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, 16, fwd, traceto );
					break;
				}

				if ( doTrace )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, contents );
					VectorCopy( trace.plane.normal, wallNormal );
					VectorNormalize( wallNormal );
					VectorSubtract( pm->ps->origin, traceto, idealNormal );
					VectorNormalize( idealNormal );
				}

				if ( !doTrace || (trace.fraction < 1.0f && (trace.entityNum < MAX_CLIENTS || DotProduct(wallNormal,idealNormal) > 0.7)) )
				{//there is a wall there.. or hit a client
					if ( (anim != BOTH_WALL_RUN_LEFT 
						&& anim != BOTH_WALL_RUN_RIGHT
						&& anim != BOTH_FORCEWALLRUNFLIP_START) 
						|| (wallNormal[2] >= 0.0f&&wallNormal[2]<=0.4f/*MAX_WALL_RUN_Z_NORMAL*/) )
					{//wall-runs can only run on perfectly flat walls, sorry. 
						int parts;
						//move me to side
						if ( anim == BOTH_WALL_FLIP_LEFT )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, 150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_WALL_FLIP_RIGHT )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, -150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_FLIP_BACK1 
							|| anim == BOTH_FLIP_BACK2 
							|| anim == BOTH_FLIP_BACK3 
							|| anim == BOTH_WALL_FLIP_BACK1 )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
						}

						//Ufo: restoring flipkicks
						if ( doTrace /*&& anim != BOTH_WALL_RUN_LEFT && anim != BOTH_WALL_RUN_RIGHT*/ )
						{
						if (trace.entityNum < MAX_CLIENTS)
						{
						pm->ps->forceKickFlip = trace.entityNum+1; //let the server know that this person gets kicked by this client
						}
						}
						

						//up
						if ( vertPush )
						{
							pm->ps->velocity[2] = vertPush;
							pm->ps->fd.forcePowersActive |= (1 << FP_LEVITATION);
						}
						//animate me
						parts = SETANIM_LEGS;
						if ( anim == BOTH_BUTTERFLY_LEFT )
						{
							parts = SETANIM_BOTH;
							pm->cmd.buttons&=~BUTTON_ATTACK;
							pm->ps->saberMove = LS_NONE;
						}
						else if ( !pm->ps->weaponTime )
						{
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						if ( anim == BOTH_BUTTERFLY_LEFT )
						{
							pm->ps->weaponTime = pm->ps->torsoTimer;
						}
						PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
						pm->ps->pm_flags |= PMF_JUMP_HELD;
						pm->cmd.upmove = 0;
						pm->ps->fd.forceJumpSound = 1;
					}
				}
			}
		}
		else 
		{//in the air
			int legsAnim = pm->ps->legsAnim;

			if ( legsAnim == BOTH_WALL_RUN_LEFT || legsAnim == BOTH_WALL_RUN_RIGHT )
			{//running on a wall
				vec3_t right, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				int		anim = -1;

				VectorSet(mins, pm->mins[0], pm->mins[0], 0);
				//Lugormod scale here ?
				VectorSet(maxs, pm->maxs[0], pm->maxs[0], 24);// * scaleh);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				AngleVectors( fwdAngles, NULL, right, NULL );

				if ( legsAnim == BOTH_WALL_RUN_LEFT )
				{
					if ( pm->ps->legsTimer > 400 )
					{//not at the end of the anim
						float animLen = PM_AnimLength( 0, (animNumber_t)BOTH_WALL_RUN_LEFT );
						if ( pm->ps->legsTimer < animLen - 400 )
						{//not at start of anim
							VectorMA( pm->ps->origin, -16, right, traceto );
							anim = BOTH_WALL_RUN_LEFT_FLIP;
						}
					}
				}
				else if ( legsAnim == BOTH_WALL_RUN_RIGHT )
				{
					if ( pm->ps->legsTimer > 400 )
					{//not at the end of the anim
						float animLen = PM_AnimLength( 0, (animNumber_t)BOTH_WALL_RUN_RIGHT );
						if ( pm->ps->legsTimer < animLen - 400 )
						{//not at start of anim
							VectorMA( pm->ps->origin, 16, right, traceto );
							anim = BOTH_WALL_RUN_RIGHT_FLIP;
						}
					}
				}
				if ( anim != -1 )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID|CONTENTS_BODY );
					if ( trace.fraction < 1.0f )
					{//flip off wall
						int parts = 0;

						if ( anim == BOTH_WALL_RUN_LEFT_FLIP )
						{
							pm->ps->velocity[0] *= 0.5f;
							pm->ps->velocity[1] *= 0.5f;
							VectorMA( pm->ps->velocity, 150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_WALL_RUN_RIGHT_FLIP )
						{
							pm->ps->velocity[0] *= 0.5f;
							pm->ps->velocity[1] *= 0.5f;
							VectorMA( pm->ps->velocity, -150, right, pm->ps->velocity );
						}
						parts = SETANIM_LEGS;
						if ( !pm->ps->weaponTime )
						{
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
						pm->cmd.upmove = 0;
					}
				}
				if ( pm->cmd.upmove != 0 )
				{//jump failed, so don't try to do normal jump code, just return
					return qfalse;
				}
			}
			//NEW JKA
			else if ( pm->ps->legsAnim == BOTH_FORCEWALLRUNFLIP_START )
			{
				vec3_t fwd, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				int		anim = -1;
				float animLen;

				VectorSet(mins, pm->mins[0], pm->mins[0], 0.0f);
				//Lugormod scale here ?
				VectorSet(maxs, pm->maxs[0], pm->maxs[0], 24.0f);// * scaleh);
				//hmm, did you mean [1] and [1]?
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);
				AngleVectors( fwdAngles, fwd, NULL, NULL );

				assert(pm_entSelf); //null pm_entSelf would be a Bad Thing<tm>
				animLen = BG_AnimLength( pm_entSelf->localAnimIndex, BOTH_FORCEWALLRUNFLIP_START );
				if ( pm->ps->legsTimer < animLen - 400 )
				{//not at start of anim
					VectorMA( pm->ps->origin, 16, fwd, traceto );
					anim = BOTH_FORCEWALLRUNFLIP_END;
				}
				if ( anim != -1 )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID|CONTENTS_BODY );
					if ( trace.fraction < 1.0f )
					{//flip off wall
						int parts = SETANIM_LEGS;

						pm->ps->velocity[0] *= 0.5f;
						pm->ps->velocity[1] *= 0.5f;
						VectorMA( pm->ps->velocity, -300, fwd, pm->ps->velocity );
						pm->ps->velocity[2] += 200;
						if ( !pm->ps->weaponTime )
						{//not attacking, set anim on both
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						//FIXME: do damage to traceEnt, like above?
						//pm->ps->pm_flags |= PMF_JUMPING|PMF_SLOW_MO_FALL;
						//ha ha, so silly with your silly jumpy fally flags.
						pm->cmd.upmove = 0;
						PM_AddEvent( EV_JUMP );
					}
				}
				if ( pm->cmd.upmove != 0 )
				{//jump failed, so don't try to do normal jump code, just return
					return qfalse;
				}
			}
			//Ufo: restoring flipkicks
			else if ( pm->cmd.forwardmove > 0 //pushing forward
			&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1
			&& pm->ps->velocity[2] > 200
			&& PM_GroundDistance() <= 80 //unfortunately we do not have a happy ground timer like SP (this would use up more bandwidth if we wanted prediction workign right), so we'll just use the actual ground distance.
			&& !BG_InSpecialJump(pm->ps->legsAnim)
			&& pm->ps->duelInProgress)
			{//run up wall, flip backwards
			vec3_t fwd, traceto, mins, maxs, fwdAngles;
			trace_t	trace;
			vec3_t	idealNormal;

			VectorSet(mins, pm->mins[0],pm->mins[1],pm->mins[2]);
			VectorSet(maxs, pm->maxs[0],pm->maxs[1],pm->maxs[2]);
			VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

			AngleVectors( fwdAngles, fwd, NULL, NULL );
			VectorMA( pm->ps->origin, 32, fwd, traceto );

			pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, MASK_PLAYERSOLID );//FIXME: clip brushes too?
			VectorSubtract( pm->ps->origin, traceto, idealNormal );
			VectorNormalize( idealNormal );

			if ( trace.fraction < 1.0f )
			{//there is a wall there
			int parts = SETANIM_LEGS;

			pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
			VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
			pm->ps->velocity[2] += 128;

			if ( !pm->ps->weaponTime )
			{
			parts = SETANIM_BOTH;
			}
			PM_SetAnim( parts, BOTH_WALL_FLIP_BACK1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );

			pm->ps->legsTimer -= 600; //I force this anim to play to the end to prevent landing on your head and suddenly flipping over.
			//It is a bit too long at the end though, so I'll just shorten it.

			PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
			pm->cmd.upmove = 0;
			pm->ps->fd.forceJumpSound = 1;
			BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );

			if (trace.entityNum < MAX_CLIENTS)
			{
				pm->ps->forceKickFlip = trace.entityNum+1; //let the server know that this person gets kicked by this client
			}
			}
			}
			//Ufo: *more* or *less* a duplicate... hopefully it can be merged at some point
			else if (abs(pm->cmd.rightmove) > 0 //left or right flipkicks
				&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1
				&& pm->ps->velocity[2] > 200
				&& PM_GroundDistance() <= 80 //unfortunately we do not have a happy ground timer like SP (this would use up more bandwidth if we wanted prediction workign right), so we'll just use the actual ground distance.
				&& !BG_InSpecialJump(pm->ps->legsAnim)
				&& pm->ps->duelInProgress)
			{
				vec3_t fwd, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				vec3_t	idealNormal;

				VectorSet(mins, pm->mins[0], pm->mins[1], pm->mins[2]);
				VectorSet(maxs, pm->maxs[0], pm->maxs[1], pm->maxs[2]);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				AngleVectors(fwdAngles, NULL, fwd, NULL);

				if (pm->cmd.rightmove < 0) {
					VectorScale(fwd, -1, fwd);
				}
				VectorMA(pm->ps->origin, 32, fwd, traceto);

				pm->trace(&trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, MASK_PLAYERSOLID);//FIXME: clip brushes too?
				VectorSubtract(pm->ps->origin, traceto, idealNormal);
				VectorNormalize(idealNormal);

				if (trace.fraction < 1.0f)
				{//there is a wall there
					int parts = SETANIM_LEGS;

					pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
					VectorMA(pm->ps->velocity, -150, fwd, pm->ps->velocity);
					pm->ps->velocity[2] += 128;

					if (!pm->ps->weaponTime)
					{
						parts = SETANIM_BOTH;
					}
					PM_SetAnim(parts, pm->cmd.rightmove > 0 ? BOTH_WALL_FLIP_RIGHT : BOTH_WALL_FLIP_LEFT, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);

					pm->ps->legsTimer -= 600; //I force this anim to play to the end to prevent landing on your head and suddenly flipping over.
					//It is a bit too long at the end though, so I'll just shorten it.

					PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
					pm->cmd.upmove = 0;
					pm->ps->fd.forceJumpSound = 1;
					BG_ForcePowerDrain(pm->ps, FP_LEVITATION, 5);

					if (trace.entityNum < MAX_CLIENTS)
					{
						pm->ps->forceKickFlip = trace.entityNum + 1; //let the server know that this person gets kicked by this client
					}
				}
			}
			else if ( pm->cmd.forwardmove > 0 //pushing forward
				&& pm->ps->fd.forceRageRecoveryTime < pm->cmd.serverTime	//not in a force Rage recovery period
				&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 
				&& PM_WalkableGroundDistance() <= 80 //unfortunately we do not have a happy ground timer like SP (this would use up more bandwidth if we wanted prediction workign right), so we'll just use the actual ground distance.
				&& (pm->ps->legsAnim == BOTH_JUMP1 || pm->ps->legsAnim == BOTH_INAIR1 ) )//not in a flip or spin or anything
			{//run up wall, flip backwards
				if ( allowWallRuns )
				{
					//FIXME: have to be moving... make sure it's opposite the wall... or at least forward?
					int wallWalkAnim = BOTH_WALL_FLIP_BACK1;
					int parts = SETANIM_LEGS;
					int contents = MASK_SOLID;//MASK_PLAYERSOLID;//CONTENTS_SOLID;
					//qboolean kick = qtrue;
					if ( pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_2 )
					{
						wallWalkAnim = BOTH_FORCEWALLRUNFLIP_START;
						parts = SETANIM_BOTH;
						//kick = qfalse;
					}
					else
					{
						if ( !pm->ps->weaponTime )
						{
							parts = SETANIM_BOTH;
						}
					}
					//if ( PM_HasAnimation( pm->gent, wallWalkAnim ) )
					if (1) //sure, we have it! Because I SAID SO.
					{
						vec3_t fwd, traceto, mins, maxs, fwdAngles;
						trace_t	trace;
						vec3_t	idealNormal;
						bgEntity_t *traceEnt;

						VectorSet(mins, pm->mins[0], pm->mins[1], 0.0f);
						//Lugormod scale here ?
						VectorSet(maxs, pm->maxs[0], pm->maxs[1], 24.0f);// * scaleh);
						VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);

						AngleVectors( fwdAngles, fwd, NULL, NULL );
						VectorMA( pm->ps->origin, 32, fwd, traceto );

						pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, contents );//FIXME: clip brushes too?
						VectorSubtract( pm->ps->origin, traceto, idealNormal );
						VectorNormalize( idealNormal );
						traceEnt = PM_BGEntForNum(trace.entityNum);

						if ( trace.fraction < 1.0f
							&&((trace.entityNum<ENTITYNUM_WORLD&&traceEnt&&traceEnt->s.solid!=SOLID_BMODEL)||DotProduct(trace.plane.normal,idealNormal)>0.7) )
						{//there is a wall there
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							if ( wallWalkAnim == BOTH_FORCEWALLRUNFLIP_START )
							{
								pm->ps->velocity[2] = forceJumpStrength[FORCE_LEVEL_3]/2.0f;
							}
							else
							{
								VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
								pm->ps->velocity[2] += 150.0f;
							}
							//animate me
							PM_SetAnim( parts, wallWalkAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
							//						pm->ps->pm_flags |= PMF_JUMPING|PMF_SLOW_MO_FALL;
							//again with the flags!
							//G_SoundOnEnt( pm->gent, CHAN_BODY, "sound/weapons/force/jump.wav" );
							//yucky!
							PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
							pm->cmd.upmove = 0;
							pm->ps->fd.forceJumpSound = 1;
							BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );

							//kick if jumping off an ent
							/*if ( kick && traceEnt && (traceEnt->s.eType == ET_PLAYER || traceEnt->s.eType == ET_NPC) )
							{ //kick that thang!
							pm->ps->forceKickFlip = traceEnt->s.number+1;
							}*/
							
							pm->cmd.rightmove = pm->cmd.forwardmove= 0;
						}
					}
				}
			}
			else if ( (!BG_InSpecialJump( legsAnim )//not in a special jump anim 
				||BG_InReboundJump( legsAnim )//we're already in a rebound
				||BG_InBackFlip( legsAnim ) )//a backflip (needed so you can jump off a wall behind you)
				//&& pm->ps->velocity[2] <= 0 
				&& pm->ps->velocity[2] > -1200 //not falling down very fast
				&& !(pm->ps->pm_flags&PMF_JUMP_HELD)//have to have released jump since last press
				&& (pm->cmd.forwardmove||pm->cmd.rightmove)//pushing in a direction
				//&& pm->ps->forceRageRecoveryTime < pm->cmd.serverTime	//not in a force Rage recovery period
				&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_2//level 3 jump or better
				//&& WP_ForcePowerAvailable( pm->gent, FP_LEVITATION, 10 )//have enough force power to do another one
				&& BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION)
				&& (pm->ps->origin[2]-pm->ps->fd.forceJumpZStart) < (forceJumpHeightMax[FORCE_LEVEL_3]-(BG_ForceWallJumpStrength()/2.0f)) //can fit at least one more wall jump in (yes, using "magic numbers"... for now)
				//&& (pm->ps->legsAnim == BOTH_JUMP1 || pm->ps->legsAnim == BOTH_INAIR1 ) )//not in a flip or spin or anything
				)
			{//see if we're pushing at a wall and jump off it if so
				if ( allowWallGrabs )
				{
					//FIXME: make sure we have enough force power
					//FIXME: check  to see if we can go any higher
					//FIXME: limit to a certain number of these in a row?
					//FIXME: maybe don't require a ucmd direction, just check all 4?
					//FIXME: should stick to the wall for a second, then push off...
					vec3_t checkDir, traceto, mins, maxs, fwdAngles;
					trace_t	trace;
					vec3_t	idealNormal;
					int		anim = -1;

					VectorSet(mins, pm->mins[0], pm->mins[1], 0.0f);
					//Lugormod scale here ?
					VectorSet(maxs, pm->maxs[0], pm->maxs[1], 24.0f);// * scaleh);
					VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);

					if ( pm->cmd.rightmove )
					{
						if ( pm->cmd.rightmove > 0 )
						{
							anim = BOTH_FORCEWALLREBOUND_RIGHT;
							AngleVectors( fwdAngles, NULL, checkDir, NULL );
						}
						else if ( pm->cmd.rightmove < 0 )
						{
							anim = BOTH_FORCEWALLREBOUND_LEFT;
							AngleVectors( fwdAngles, NULL, checkDir, NULL );
							VectorScale( checkDir, -1, checkDir );
						}
					}
					else if ( pm->cmd.forwardmove > 0 )
					{
						anim = BOTH_FORCEWALLREBOUND_FORWARD;
						AngleVectors( fwdAngles, checkDir, NULL, NULL );
					}
					else if ( pm->cmd.forwardmove < 0 )
					{
						anim = BOTH_FORCEWALLREBOUND_BACK;
						AngleVectors( fwdAngles, checkDir, NULL, NULL );
						VectorScale( checkDir, -1, checkDir );
					}
					if ( anim != -1 )
					{//trace in the dir we're pushing in and see if there's a vertical wall there
						bgEntity_t *traceEnt;

						VectorMA( pm->ps->origin, 8, checkDir, traceto );
						pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID );//FIXME: clip brushes too?
						VectorSubtract( pm->ps->origin, traceto, idealNormal );
						VectorNormalize( idealNormal );
						traceEnt = PM_BGEntForNum(trace.entityNum);
						if ( trace.fraction < 1.0f
							&&fabs(trace.plane.normal[2]) <= 0.2f/*MAX_WALL_GRAB_SLOPE*/
							&&((trace.entityNum<ENTITYNUM_WORLD&&traceEnt&&traceEnt->s.solid!=SOLID_BMODEL)||DotProduct(trace.plane.normal,idealNormal)>0.7) )
						{//there is a wall there
							float dot = DotProduct( pm->ps->velocity, trace.plane.normal );
							if ( dot < 1.0f )
							{//can't be heading *away* from the wall!
								//grab it!
								PM_GrabWallForJump( anim );
							}
						}
					}
				}
			}
			else
			{
				//FIXME: if in a butterfly, kick people away?
			}
			//END NEW JKA
		}
	}

	/*
	if ( pm->cmd.upmove > 0 
	&& (pm->ps->weapon == WP_SABER || pm->ps->weapon == WP_MELEE)
	&& !PM_IsRocketTrooper()
	&& (pm->ps->weaponTime > 0||pm->cmd.buttons&BUTTON_ATTACK) )
	{//okay, we just jumped and we're in an attack
	if ( !BG_InRoll( pm->ps, pm->ps->legsAnim )
	&& !PM_InKnockDown( pm->ps )
	&& !BG_InDeathAnim(pm->ps->legsAnim)
	&& !BG_FlippingAnim( pm->ps->legsAnim )
	&& !PM_SpinningAnim( pm->ps->legsAnim )
	&& !BG_SaberInSpecialAttack( pm->ps->torsoAnim )
	&& ( BG_SaberInAttack( pm->ps->saberMove ) ) )
	{//not in an anim we shouldn't interrupt
	//see if it's not too late to start a special jump-attack
	float animLength = PM_AnimLength( 0, (animNumber_t)pm->ps->torsoAnim );
	if ( animLength - pm->ps->torsoTimer < 500 )
	{//just started the saberMove
	//check for special-case jump attacks
	if ( pm->ps->fd.saberAnimLevel == FORCE_LEVEL_2 )
	{//using medium attacks
	if (PM_GroundDistance() < 32 &&
	!BG_InSpecialJump(pm->ps->legsAnim))
	{ //FLIP AND DOWNWARD ATTACK
	//trace_t tr;

	//if (PM_SomeoneInFront(&tr))
	{
	PM_SetSaberMove(PM_SaberFlipOverAttackMove());
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
	pm->ps->pm_flags |= PMF_JUMP_HELD;
	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	VectorClear(pml.groundTrace.plane.normal);

	pm->ps->weaponTime = pm->ps->torsoTimer;
	}
	}
	}
	else if ( pm->ps->fd.saberAnimLevel == FORCE_LEVEL_3 )
	{//using strong attacks
	if ( pm->cmd.forwardmove > 0 && //going forward
	(pm->cmd.buttons & BUTTON_ATTACK) && //must be holding attack still
	PM_GroundDistance() < 32 &&
	!BG_InSpecialJump(pm->ps->legsAnim))
	{//strong attack: jump-hack
	PM_SetSaberMove( PM_SaberJumpAttackMove() );
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
	pm->ps->pm_flags |= PMF_JUMP_HELD;
	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	VectorClear(pml.groundTrace.plane.normal);

	pm->ps->weaponTime = pm->ps->torsoTimer;
	}
	}
	}
	}
	}
	*/
	if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
	{
		if (pm->cmd.upmove > 0 &&
			pm->ps->fd.forcePowerLevel[FP_LEVITATION] 
		== FORCE_LEVEL_5)
		{ //Lugormod Jump in air

			if (!(pm->ps->pm_flags & PMF_JUMP_HELD)) {
				if ( pm->ps->fd.forcePower < 5 )
				{
					return qfalse;
				}
				pm->ps->fd.forcePower -= 5;
				pm->ps->pm_flags |= PMF_JUMP_HELD;
				pm->ps->fd.forcePowersActive |= (1 << FP_LEVITATION);
			}

			//Set the animations
			if ( pm->ps->gravity > 0 && !BG_InSpecialJump( pm->ps->legsAnim ) )
			{
				PM_JumpForDir();
			}
			//PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height

			return qtrue;
		}

		return qfalse;
	}
	if ( pm->cmd.upmove > 0 )
	{//no special jumps
		pm->ps->velocity[2] = JUMP_VELOCITY;
	}

	//Jumping
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
	pm->ps->pm_flags |= PMF_JUMP_HELD;
	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	PM_SetForceJumpZStart(pm->ps->origin[2]);

	PM_AddEvent( EV_JUMP );

	//Set the animations
	if ( pm->ps->gravity > 0 && !BG_InSpecialJump( pm->ps->legsAnim ) )
	{
		PM_JumpForDir();
	}

	return qtrue;
}

/*
=============
PM_CheckJump
=============
*/
static qboolean PM_CheckJump( void )
{
	qboolean allowFlips = qtrue;
	bgEntity_t	*kickedEnt;//JAPRO - Serverside - Allow npcs to be flipkicked
	int moveStyle;

//JAPRO - Serverside - Set up client to check for lastkicktime flood protect - Start
#ifdef _GAME
    gclient_t *client = NULL;
    {
		int clientNum = pm->ps->clientNum;
		if (0 <= clientNum && clientNum < MAX_CLIENTS) {
			client = g_entities[clientNum].client;
		}
	}
#endif
//JAPRO - Serverside - Set up client to check for lastkicktime flood protect - End

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		bgEntity_t *pEnt = pm_entSelf;

		if (pEnt->s.eType == ET_NPC &&
			pEnt->s.NPC_class == CLASS_VEHICLE)
		{ //no!
			return qfalse;
		}
	}

	moveStyle = PM_GetMovePhysics();

	if (pm->ps->forceHandExtend == HANDEXTEND_KNOCKDOWN ||
		pm->ps->forceHandExtend == HANDEXTEND_PRETHROWN ||
		pm->ps->forceHandExtend == HANDEXTEND_POSTTHROWN)
	{
		return qfalse;
	}

	if (pm->ps->pm_type == PM_JETPACK)
	{ //there's no actual jumping while we jetpack
		return qfalse;
	}

	if (BG_IsNewJetpacking(pm->ps)) { //New Jetpack
		return qfalse;
	}

	//Don't allow jump until all buttons are up
	if ( pm->ps->pm_flags & PMF_RESPAWNED ) {
		return qfalse;
	}

	if ( PM_InKnockDown( pm->ps ) || BG_InRoll( pm->ps, pm->ps->legsAnim ) )
	{//in knockdown
		return qfalse;
	}

	//Devy cs jump delay here?

	if ( pm->ps->weapon == WP_SABER )
	{
		saberInfo_t *saber1 = BG_MySaber( pm->ps->clientNum, 0 );
		saberInfo_t *saber2 = BG_MySaber( pm->ps->clientNum, 1 );
		if ( saber1
			&& (saber1->saberFlags&SFL_NO_FLIPS) )
		{
			allowFlips = qfalse;
		}
		if ( saber2
			&& (saber2->saberFlags&SFL_NO_FLIPS) )
		{
			allowFlips = qfalse;
		}
	}

	if (pm->ps->groundEntityNum != ENTITYNUM_NONE || pm->ps->origin[2] < pm->ps->fd.forceJumpZStart)
	{
		pm->ps->fd.forcePowersActive &= ~(1<<FP_LEVITATION);
	}

	if (pm->ps->fd.forcePowersActive & (1 << FP_LEVITATION))
	{ //Force jump is already active.. continue draining power appropriately until we land.
		if (pm->ps->fd.forcePowerDebounce[FP_LEVITATION] < pm->cmd.serverTime)
		{
			if ( pm->gametype == GT_DUEL
				|| pm->gametype == GT_POWERDUEL )
			{//jump takes less power
				BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 1 );
			}
			else
			{
				BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );
			}
			if (pm->ps->fd.forcePowerLevel[FP_LEVITATION] >= FORCE_LEVEL_2)
			{
				pm->ps->fd.forcePowerDebounce[FP_LEVITATION] = pm->cmd.serverTime + 300;
			}
			else
			{
				pm->ps->fd.forcePowerDebounce[FP_LEVITATION] = pm->cmd.serverTime + 200;
			}
		}
	}

	if (pm->ps->forceJumpFlip)
	{ //Forced jump anim
		int anim = BOTH_FORCEINAIR1;
		int	parts = SETANIM_BOTH;
		if ( allowFlips )
		{
			if ( pm->cmd.forwardmove > 0 )
			{
				anim = BOTH_FLIP_F;
			}
			else if ( pm->cmd.forwardmove < 0 )
			{
				anim = BOTH_FLIP_B;
			}
			else if ( pm->cmd.rightmove > 0 )
			{
				anim = BOTH_FLIP_R;
			}
			else if ( pm->cmd.rightmove < 0 )
			{
				anim = BOTH_FLIP_L;
			}
		}
		else
		{
			if ( pm->cmd.forwardmove > 0 )
			{
				anim = BOTH_FORCEINAIR1;
			}
			else if ( pm->cmd.forwardmove < 0 )
			{
				anim = BOTH_FORCEINAIRBACK1;
			}
			else if ( pm->cmd.rightmove > 0 )
			{
				anim = BOTH_FORCEINAIRRIGHT1;
			}
			else if ( pm->cmd.rightmove < 0 )
			{
				anim = BOTH_FORCEINAIRLEFT1;
			}
		}
		if ( pm->ps->weaponTime )
		{//FIXME: really only care if we're in a saber attack anim...
			parts = SETANIM_LEGS;
		}

		PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
		pm->ps->forceJumpFlip = qfalse;
		return qtrue;
	}

#if _GAME
	if (g_showJumpSpot.integer) {
		if ((pm->ps->origin[2] - pm->ps->fd.forceJumpZStart) == 0 && pm->cmd.upmove>=10) {
			vec3_t start;
			vec3_t end;
			VectorCopy(pm->ps->origin, end);
			VectorCopy(pm->ps->origin, start);
			start[2] -= 64;
			end[2] += 256;

			G_TestLine(start, end, 0x00000ff, 60000);
		}
	}
#endif

#if METROID_JUMP
	if ( pm->waterlevel < 2 )
	{
		if ( pm->ps->gravity > 0 )
		{//can't do this in zero-G
			if ( PM_ForceJumpingUp() )
			{//holding jump in air
				float curHeight = pm->ps->origin[2] - pm->ps->fd.forceJumpZStart;
				float realForceJumpHeight = forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]];
				if (moveStyle == MV_QW || moveStyle == MV_PJK) { //If we have forcejump rampjump, we should be able to jump higher
					realForceJumpHeight = forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] * (pm->ps->stats[STAT_LASTJUMPSPEED] / (float)JUMP_VELOCITY);
					//Com_Printf("Max Jump Height %.1f\n", realForceJumpHeight);
				}
				//check for max force jump level and cap off & cut z vel
				if ( ( curHeight<=forceJumpHeight[0] ||//still below minimum jump height
						(pm->ps->fd.forcePower&&pm->cmd.upmove>=10) ) &&////still have force power available and still trying to jump up
					curHeight < realForceJumpHeight &&
					pm->ps->fd.forceJumpZStart)//still below maximum jump height
				{//can still go up
#ifdef _CGAME
					if (cg_jumpHeight.integer && curHeight + (pm->ps->velocity[2] * (float)cg.frametime / 1000.0f) > cg_jumpHeight.integer) //idk
						trap->SendConsoleCommand("-moveup\n");
#endif
					if ( curHeight > forceJumpHeight[0] )
					{//passed normal jump height  *2?
						if ( !(pm->ps->fd.forcePowersActive&(1<<FP_LEVITATION)) )//haven't started forcejump yet
						{
//JAPRO - Serverside - OnlyBhop - Start
#ifdef _GAME
							if (g_onlyBhop.integer == 1 || (client != NULL && ((g_onlyBhop.integer > 1 && client->pers.onlyBhop) || (client->ps.stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP))))
#else
							if (cgs.serverMod == SVMOD_JAPRO && ((cgs.jcinfo & JAPRO_CINFO_BHOP1) || ((cgs.jcinfo & JAPRO_CINFO_BHOP2) && (cp_pluginDisable.integer & JAPRO_PLUGIN_BHOP)) || (pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP)))
#endif
							{
								pm->cmd.upmove = 0;
								return qfalse;
							}
							else
//JAPRO - Serverside - OnlyBhop - End
							{
								//start force jump
							pm->ps->fd.forcePowersActive |= (1<<FP_LEVITATION);
							pm->ps->fd.forceJumpSound = 1;
							//play flip
							if ((pm->cmd.forwardmove || pm->cmd.rightmove) && //pushing in a dir
								(pm->ps->legsAnim) != BOTH_FLIP_F &&//not already flipping
								(pm->ps->legsAnim) != BOTH_FLIP_B &&
								(pm->ps->legsAnim) != BOTH_FLIP_R &&
								(pm->ps->legsAnim) != BOTH_FLIP_L
								&& allowFlips )
							{
								int anim = BOTH_FORCEINAIR1;
								int	parts = SETANIM_BOTH;

								if ( pm->cmd.forwardmove > 0 )
								{
									anim = BOTH_FLIP_F;
								}
								else if ( pm->cmd.forwardmove < 0 )
								{
									anim = BOTH_FLIP_B;
								}
								else if ( pm->cmd.rightmove > 0 )
								{
									anim = BOTH_FLIP_R;
								}
								else if ( pm->cmd.rightmove < 0 )
								{
									anim = BOTH_FLIP_L;
								}
								if ( pm->ps->weaponTime )
								{
									parts = SETANIM_LEGS;
								}

								PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
							}
							else if ( pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
							{
								vec3_t facingFwd, facingRight, facingAngles;
								int	anim = -1;
								float dotR, dotF;

								VectorSet(facingAngles, 0, pm->ps->viewangles[YAW], 0);

								AngleVectors( facingAngles, facingFwd, facingRight, NULL );
								dotR = DotProduct( facingRight, pm->ps->velocity );
								dotF = DotProduct( facingFwd, pm->ps->velocity );

								if ( fabs(dotR) > fabs(dotF) * 1.5 )
								{
									if ( dotR > 150 )
									{
										anim = BOTH_FORCEJUMPRIGHT1;
									}
									else if ( dotR < -150 )
									{
										anim = BOTH_FORCEJUMPLEFT1;
									}
								}
								else
								{
									if ( dotF > 150 )
									{
										anim = BOTH_FORCEJUMP1;
									}
									else if ( dotF < -150 )
									{
										anim = BOTH_FORCEJUMPBACK1;
									}
								}
								if ( anim != -1 )
								{
									int parts = SETANIM_BOTH;
									if ( pm->ps->weaponTime )
									{//FIXME: really only care if we're in a saber attack anim...
										parts = SETANIM_LEGS;
									}

									PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
								}
							}
						}
					}
						else
						{ //jump is already active (the anim has started)
							if ( pm->ps->legsTimer < 1 )
							{//not in the middle of a legsAnim
								int anim = (pm->ps->legsAnim);
								int newAnim = -1;
								switch ( anim )
								{
								case BOTH_FORCEJUMP1:
									newAnim = BOTH_FORCELAND1;//BOTH_FORCEINAIR1;
									break;
								case BOTH_FORCEJUMPBACK1:
									newAnim = BOTH_FORCELANDBACK1;//BOTH_FORCEINAIRBACK1;
									break;
								case BOTH_FORCEJUMPLEFT1:
									newAnim = BOTH_FORCELANDLEFT1;//BOTH_FORCEINAIRLEFT1;
									break;
								case BOTH_FORCEJUMPRIGHT1:
									newAnim = BOTH_FORCELANDRIGHT1;//BOTH_FORCEINAIRRIGHT1;
									break;
								}
								if ( newAnim != -1 )
								{
									int parts = SETANIM_BOTH;
									if ( pm->ps->weaponTime )
									{
										parts = SETANIM_LEGS;
									}

									PM_SetAnim( parts, newAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
								}
							}
						}
					}

					if (moveStyle == MV_QW || moveStyle == MV_PJK) {//Forcejump rampjump
						//need to scale this down, start with height velocity (based on max force jump height) and scale down to regular jump vel
						float realForceJumpHeight = forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] * (pm->ps->stats[STAT_LASTJUMPSPEED] / (float)JUMP_VELOCITY);

						pm->ps->velocity[2] = (realForceJumpHeight-curHeight)/realForceJumpHeight*forceJumpStrength[pm->ps->fd.forcePowerLevel[FP_LEVITATION]];//JUMP_VELOCITY;
						pm->ps->velocity[2] /= 10;//need to scale this down, start with height velocity (based on max force jump height) and scale down to regular jump vel

						pm->ps->velocity[2] += pm->ps->stats[STAT_LASTJUMPSPEED];
					}
					else {
						pm->ps->velocity[2] = (forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]-curHeight)/forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]]*forceJumpStrength[pm->ps->fd.forcePowerLevel[FP_LEVITATION]];//JUMP_VELOCITY;
						pm->ps->velocity[2] /= 10;
						pm->ps->velocity[2] += JUMP_VELOCITY;
					}
					pm->ps->pm_flags |= PMF_JUMP_HELD;
				}
				/*
				else if ( curHeight > forceJumpHeight[0] && curHeight < forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] - forceJumpHeight[0] )
				{//still have some headroom, don't totally stop it
					if ( pm->ps->velocity[2] > JUMP_VELOCITY )
					{
						pm->ps->velocity[2] = JUMP_VELOCITY;
					}
				}
				*/
				else
				{
					if ( pm->ps->velocity[2] > JUMP_VELOCITY) //Also add a check for pjk/wsw?
						//At the end of a forcejump, if we are still going up super fast we dont want to immediately slow down.. would take like 5000 speed rampjump for this to show up though
					{
							pm->ps->velocity[2] = JUMP_VELOCITY;
					}
				}
#ifdef _GAME
				if ((pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_CROUCHJUMP) && ((pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP) ||
					(g_onlyBhop.integer == 1) || ((g_onlyBhop.integer > 1) && client->pers.onlyBhop)))
#else
				if (cgs.serverMod == SVMOD_JAPRO && (pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_CROUCHJUMP) &&
					((pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP) || (cgs.jcinfo & JAPRO_CINFO_BHOP1) || ((cgs.jcinfo & JAPRO_CINFO_BHOP2) && (cp_pluginDisable.integer & JAPRO_PLUGIN_BHOP))))
#endif
				{ // so we can force different jump heights with ONLYBHOP restrict
					pm->cmd.upmove = 0;
					pm->ps->pm_flags &= ~PMF_JUMP_HELD;
				}

				if (moveStyle != MV_QW && moveStyle != MV_CPM && moveStyle != MV_Q3 && moveStyle != MV_PJK && moveStyle != MV_WSW && moveStyle != MV_RJQ3 && moveStyle != MV_RJCPM && moveStyle != MV_JETPACK && moveStyle != MV_SLICK && moveStyle != MV_BOTCPM) {
					{
						pm->cmd.upmove = 0; // change this to allow hold to jump?
						return qfalse;
					}
				}
			}
		}
	}

#endif

	//Not jumping
	if ( pm->cmd.upmove < 10 && pm->ps->groundEntityNum != ENTITYNUM_NONE) {
		return qfalse;
	}

	if (moveStyle == MV_PJK && pm->ps->stats[STAT_JUMPTIME] > 375) //400 = Just jumped.  Should probably floodprotect all styles but w.e.
		return qfalse;

	// must wait for jump to be released
	if ( pm->ps->pm_flags & PMF_JUMP_HELD )
	{
		// clear upmove so cmdscale doesn't lower running speed - LODA FIXME - no idea what this does lol
		if (moveStyle != MV_QW && moveStyle != MV_CPM && moveStyle != MV_Q3 && moveStyle != MV_PJK && moveStyle != MV_WSW && moveStyle != MV_RJQ3 && moveStyle != MV_RJCPM && moveStyle != MV_JETPACK && moveStyle != MV_SLICK && moveStyle != MV_BOTCPM)
		{
			pm->cmd.upmove = 0;
			return qfalse;
		}
		//hold to jump?
	}

	if ( pm->ps->gravity <= 0 )
	{//in low grav, you push in the dir you're facing as long as there is something behind you to shove off of
		vec3_t	forward, back;
		trace_t	trace;

		AngleVectors( pm->ps->viewangles, forward, NULL, NULL );
		VectorMA( pm->ps->origin, -8, forward, back );
		pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, back, pm->ps->clientNum, pm->tracemask );

		if ( trace.fraction <= 1.0f )
		{
			VectorMA( pm->ps->velocity, JUMP_VELOCITY*2, forward, pm->ps->velocity );
			PM_SetAnim(SETANIM_LEGS,BOTH_FORCEJUMP1,SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD|SETANIM_FLAG_RESTART);
		}//else no surf close enough to push off of
		pm->cmd.upmove = 0;
	}
	else if ( pm->cmd.upmove > 0 && pm->waterlevel < 2 &&
		pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_0 &&
		!(pm->ps->pm_flags&PMF_JUMP_HELD) &&
		(pm->ps->weapon == WP_SABER || pm->ps->weapon == WP_MELEE) &&
		!PM_IsRocketTrooper() &&
		!BG_HasYsalamiri(pm->gametype, pm->ps) &&
		(moveStyle != MV_CPM) &&
		(moveStyle != MV_OCPM) &&
		(moveStyle != MV_Q3) &&
		(moveStyle != MV_WSW) &&
		(moveStyle != MV_RJQ3) &&
		(moveStyle != MV_RJCPM) &&
		(moveStyle != MV_SLICK) &&
		(moveStyle != MV_BOTCPM) &&
		BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION) )
	{
		qboolean allowWallRuns = qtrue;
		qboolean allowWallFlips = qtrue;
	//	qboolean allowFlips = qtrue; //loda fixme, why is this commented
		qboolean allowWallGrabs = qtrue;

#ifdef _GAME
		if (pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP)
#else
		if (cgs.serverMod == SVMOD_JAPRO && pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_BHOP)
#endif
		{
			allowWallRuns = qfalse;
			allowWallFlips = qfalse;
			allowFlips = qfalse;
			allowWallGrabs = qfalse;
		}

		if ( pm->ps->weapon == WP_SABER )
		{
			saberInfo_t *saber1 = BG_MySaber( pm->ps->clientNum, 0 );
			saberInfo_t *saber2 = BG_MySaber( pm->ps->clientNum, 1 );
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_RUNS) )
			{
				allowWallRuns = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_RUNS) )
			{
				allowWallRuns = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_FLIPS) )
			{
				allowWallFlips = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_FLIPS) )
			{
				allowWallFlips = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_FLIPS) )
			{
				allowFlips = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_FLIPS) )
			{
				allowFlips = qfalse;
			}
			if ( saber1
				&& (saber1->saberFlags&SFL_NO_WALL_GRAB) )
			{
				allowWallGrabs = qfalse;
			}
			if ( saber2
				&& (saber2->saberFlags&SFL_NO_WALL_GRAB) )
			{
				allowWallGrabs = qfalse;
			}
		}

		if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
		{//on the ground
			//check for left-wall and right-wall special jumps
			int anim = -1;
			float	vertPush = 0;
			if ( pm->cmd.rightmove > 0 && pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
			{//strafing right
				if ( pm->cmd.forwardmove > 0 )
				{//wall-run
					if ( allowWallRuns )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.0f;
						anim = BOTH_WALL_RUN_RIGHT;
					}
				}
//JAPRO - Serverside + Clientside - Sidekick options - Start
				else if ( pm->cmd.forwardmove == 0 )
				{//wall-flip japro
					#ifdef _GAME
						if ((g_flipKick.integer < 2) && allowWallFlips)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_RIGHT;
						}
						else if ((g_flipKick.integer == 2) && allowWallFlips && (client->lastKickTime + 50 < level.time))
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_RIGHT;
							client->lastKickTime = level.time;
						}
						else if ((g_flipKick.integer > 2) && allowWallFlips && pm->ps->legsAnim != BOTH_WALL_FLIP_RIGHT && pm->ps->legsAnim != BOTH_WALL_FLIP_LEFT)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_RIGHT;
						}
					#else
						if (cgs.serverMod == SVMOD_JAPRO && (cgs.jcinfo & JAPRO_CINFO_FIXSIDEKICK) && allowWallFlips && pm->ps->legsAnim != BOTH_WALL_FLIP_RIGHT && pm->ps->legsAnim != BOTH_WALL_FLIP_LEFT)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_RIGHT;
						}
						else if (allowWallFlips)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_RIGHT;
						}
					#endif
				}
//JAPRO - Serverside + Clientside - Sidekick options - End
			}
			else if ( pm->cmd.rightmove < 0 && pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1 )
			{//strafing left
				if ( pm->cmd.forwardmove > 0 )
				{//wall-run
					if ( allowWallRuns )
					{
						vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.0f;
						anim = BOTH_WALL_RUN_LEFT;
					}
				}
//JAPRO - Serverside + Clientside - Sidekick options - Start
				else if ( pm->cmd.forwardmove == 0 )
				{//wall-flip japro
					#ifdef _GAME
						if ((g_flipKick.integer < 2) && allowWallFlips)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_LEFT;
						}
						else if ((g_flipKick.integer == 2) && allowWallFlips && (client->lastKickTime + 50 < level.time))
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_LEFT;
							client->lastKickTime = level.time;
						}
						else if ((g_flipKick.integer > 2) && allowWallFlips && pm->ps->legsAnim != BOTH_WALL_FLIP_LEFT && pm->ps->legsAnim != BOTH_WALL_FLIP_RIGHT)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_LEFT;
						}
					#else
						if (cgs.serverMod == SVMOD_JAPRO && (cgs.jcinfo & JAPRO_CINFO_FIXSIDEKICK) && allowWallFlips && pm->ps->legsAnim != BOTH_WALL_FLIP_LEFT && pm->ps->legsAnim != BOTH_WALL_FLIP_RIGHT)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_LEFT;
						}
						else if (allowWallFlips)
						{
							vertPush = forceJumpStrength[FORCE_LEVEL_2]/2.25f;
							anim = BOTH_WALL_FLIP_LEFT;
						}
					#endif
				}
//JAPRO - Serverside + Clientside - Sidekick options - End
			}
			else if ( pm->cmd.forwardmove < 0 && !(pm->cmd.buttons&BUTTON_ATTACK) )
			{//backflip
				if ( allowFlips )
				{
					vertPush = JUMP_VELOCITY;
					anim = BOTH_FLIP_BACK1;//BG_PickAnim( BOTH_FLIP_BACK1, BOTH_FLIP_BACK3 );
				}
			}

			vertPush += 128; //give them an extra shove

			if ( anim != -1 )
			{
				vec3_t fwd, right, traceto, mins, maxs, fwdAngles;
				vec3_t	idealNormal={0}, wallNormal={0};
				trace_t	trace;
				qboolean doTrace = qfalse;
//JAPRO - Serverside + Clientside - Re add flipkick sidekick - Start
				int contents;// = MASK_SOLID;//MASK_PLAYERSOLID;

				if (GetFlipkick(pm->ps) > 0)
					contents = MASK_PLAYERSOLID;
				else
					contents = MASK_SOLID;
/*
#ifdef _GAME
				if (g_flipKick.integer > 0)
					contents = MASK_PLAYERSOLID;//MASK_PLAYERSOLID;
				else
					contents = MASK_SOLID;

#else
				if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FLIPKICK) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FLIPKICK))
					contents = MASK_PLAYERSOLID;//MASK_PLAYERSOLID;
				else
					contents = MASK_SOLID;//MASK_PLAYERSOLID;
#endif
*/
//JAPRO - Serverside + Clientside - Re add flipkick sidekick - End

				VectorSet(mins, pm->mins[0],pm->mins[1],0);
				VectorSet(maxs, pm->maxs[0],pm->maxs[1],24);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				memset(&trace, 0, sizeof(trace)); //to shut the compiler up

				AngleVectors( fwdAngles, fwd, right, NULL );

				//trace-check for a wall, if necc.
				switch ( anim )
				{
				case BOTH_WALL_FLIP_LEFT:
					//NOTE: purposely falls through to next case!
				case BOTH_WALL_RUN_LEFT:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, -16, right, traceto );
					break;

				case BOTH_WALL_FLIP_RIGHT:
					//NOTE: purposely falls through to next case!
				case BOTH_WALL_RUN_RIGHT:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, 16, right, traceto );
					break;

				case BOTH_WALL_FLIP_BACK1:
					doTrace = qtrue;
					VectorMA( pm->ps->origin, 16, fwd, traceto );
					break;
				}

				if ( doTrace )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, contents );
					VectorCopy( trace.plane.normal, wallNormal );
					VectorNormalize( wallNormal );
					VectorSubtract( pm->ps->origin, traceto, idealNormal );
					VectorNormalize( idealNormal );
				}

				if ( !doTrace || (trace.fraction < 1.0f && (trace.entityNum < MAX_CLIENTS || DotProduct(wallNormal,idealNormal) > 0.7)) )
				{//there is a wall there.. or hit a client
					if ( (anim != BOTH_WALL_RUN_LEFT
							&& anim != BOTH_WALL_RUN_RIGHT
							&& anim != BOTH_FORCEWALLRUNFLIP_START)
						|| (wallNormal[2] >= 0.0f&&wallNormal[2]<=0.4f/*MAX_WALL_RUN_Z_NORMAL*/) )
					{//wall-runs can only run on perfectly flat walls, sorry.
						int parts;
						//move me to side
						if ( anim == BOTH_WALL_FLIP_LEFT )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, 150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_WALL_FLIP_RIGHT )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, -150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_FLIP_BACK1
							|| anim == BOTH_FLIP_BACK2
							|| anim == BOTH_FLIP_BACK3
							|| anim == BOTH_WALL_FLIP_BACK1 )
						{
							pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
							VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
						}

//JAPRO - Serverside + Clientside - Re add flipkick - Start
						if ( doTrace && anim != BOTH_WALL_RUN_LEFT && anim != BOTH_WALL_RUN_RIGHT )
						{
							kickedEnt = PM_BGEntForNum(trace.entityNum);
/*
#ifdef _GAME
							if ((trace.entityNum < MAX_CLIENTS) || (g_flipKick.integer && kickedEnt->s.eType == ET_NPC))
#else
							if ((trace.entityNum < MAX_CLIENTS) || ((cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FLIPKICK) && kickedEnt->s.eType == ET_NPC))
#endif
*/

							if ((trace.entityNum < MAX_CLIENTS) || (GetFlipkick(pm->ps) && kickedEnt->s.eType == ET_NPC))

							{
								pm->ps->forceKickFlip = trace.entityNum+1; //let the server know that this person gets kicked by this client
							}
						}
//JAPRO - Serverside + Clientside - Re add flipkick - End

						//up
						if ( vertPush )
						{
							pm->ps->velocity[2] = vertPush;
							pm->ps->fd.forcePowersActive |= (1 << FP_LEVITATION);
						}
						//animate me
						parts = SETANIM_LEGS;
						if ( anim == BOTH_BUTTERFLY_LEFT )
						{
							parts = SETANIM_BOTH;
							pm->cmd.buttons&=~BUTTON_ATTACK;
							pm->ps->saberMove = LS_NONE;
						}
						else if ( !pm->ps->weaponTime )
						{
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						if ( anim == BOTH_BUTTERFLY_LEFT )
						{
							pm->ps->weaponTime = pm->ps->torsoTimer;
						}
						PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
						pm->ps->pm_flags |= PMF_JUMP_HELD;
						pm->cmd.upmove = 0;
						pm->ps->fd.forceJumpSound = 1;
					}
				}
			}
		}
		else
		{//in the air
			int legsAnim = pm->ps->legsAnim;

			if ( legsAnim == BOTH_WALL_RUN_LEFT || legsAnim == BOTH_WALL_RUN_RIGHT )
			{//running on a wall
				vec3_t right, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				int		anim = -1;

				VectorSet(mins, pm->mins[0], pm->mins[0], 0);
				VectorSet(maxs, pm->maxs[0], pm->maxs[0], 24);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				AngleVectors( fwdAngles, NULL, right, NULL );

				if ( legsAnim == BOTH_WALL_RUN_LEFT )
				{
					if ( pm->ps->legsTimer > 400 )
					{//not at the end of the anim
						float animLen = PM_AnimLength( 0, (animNumber_t)BOTH_WALL_RUN_LEFT );
						if ( pm->ps->legsTimer < animLen - 400 )
						{//not at start of anim
							VectorMA( pm->ps->origin, -16, right, traceto );
							anim = BOTH_WALL_RUN_LEFT_FLIP;
						}
					}
				}
				else if ( legsAnim == BOTH_WALL_RUN_RIGHT )
				{
					if ( pm->ps->legsTimer > 400 )
					{//not at the end of the anim
						float animLen = PM_AnimLength( 0, (animNumber_t)BOTH_WALL_RUN_RIGHT );
						if ( pm->ps->legsTimer < animLen - 400 )
						{//not at start of anim
							VectorMA( pm->ps->origin, 16, right, traceto );
							anim = BOTH_WALL_RUN_RIGHT_FLIP;
						}
					}
				}
				if ( anim != -1 )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID|CONTENTS_BODY );
					if ( trace.fraction < 1.0f )
					{//flip off wall
						int parts = 0;

						if ( anim == BOTH_WALL_RUN_LEFT_FLIP )
						{
							pm->ps->velocity[0] *= 0.5f;
							pm->ps->velocity[1] *= 0.5f;
							VectorMA( pm->ps->velocity, 150, right, pm->ps->velocity );
						}
						else if ( anim == BOTH_WALL_RUN_RIGHT_FLIP )
						{
							pm->ps->velocity[0] *= 0.5f;
							pm->ps->velocity[1] *= 0.5f;
							VectorMA( pm->ps->velocity, -150, right, pm->ps->velocity );
						}
						parts = SETANIM_LEGS;
						if ( !pm->ps->weaponTime )
						{
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						pm->cmd.upmove = 0;
					}
				}
				if ( pm->cmd.upmove != 0 )
				{//jump failed, so don't try to do normal jump code, just return
					return qfalse;
				}
			}
			//NEW JKA
			else if ( pm->ps->legsAnim == BOTH_FORCEWALLRUNFLIP_START )
			{
				vec3_t fwd, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				int		anim = -1;
				float animLen;

				VectorSet(mins, pm->mins[0], pm->mins[0], 0.0f);
				VectorSet(maxs, pm->maxs[0], pm->maxs[0], 24.0f);
				//hmm, did you mean [1] and [1]?
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);
				AngleVectors( fwdAngles, fwd, NULL, NULL );

				assert(pm_entSelf); //null pm_entSelf would be a Bad Thing<tm>
				animLen = BG_AnimLength( pm_entSelf->localAnimIndex, BOTH_FORCEWALLRUNFLIP_START );
				if ( pm->ps->legsTimer < animLen - 400 )
				{//not at start of anim
					VectorMA( pm->ps->origin, 16, fwd, traceto );
					anim = BOTH_FORCEWALLRUNFLIP_END;
				}
				if ( anim != -1 )
				{
					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID|CONTENTS_BODY );
					if ( trace.fraction < 1.0f )
					{//flip off wall
						int parts = SETANIM_LEGS;

						pm->ps->velocity[0] *= 0.5f;
						pm->ps->velocity[1] *= 0.5f;
						VectorMA( pm->ps->velocity, -300, fwd, pm->ps->velocity );
						pm->ps->velocity[2] += 200;
						if ( !pm->ps->weaponTime )
						{//not attacking, set anim on both
							parts = SETANIM_BOTH;
						}
						PM_SetAnim( parts, anim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
						//FIXME: do damage to traceEnt, like above?
						//pm->ps->pm_flags |= PMF_JUMPING|PMF_SLOW_MO_FALL;
						//ha ha, so silly with your silly jumpy fally flags.
						pm->cmd.upmove = 0;
						PM_AddEvent( EV_JUMP );
					}
				}
				if ( pm->cmd.upmove != 0 )
				{//jump failed, so don't try to do normal jump code, just return
					return qfalse;
				}
			}

#if 1
			else if ( pm->cmd.forwardmove > 0 //pushing forward -- this is used for forward flipkicks i guess
				&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1
				&& pm->ps->velocity[2] > 200
				&& PM_GroundDistance() <= 80 //unfortunately we do not have a happy ground timer like SP (this would use up more bandwidth if we wanted prediction workign right), so we'll just use the actual ground distance.
				&& !BG_InSpecialJump(pm->ps->legsAnim))
			{//run up wall, flip backwards
				vec3_t fwd, traceto, mins, maxs, fwdAngles;
				trace_t	trace;
				vec3_t	idealNormal;

				VectorSet(mins, pm->mins[0],pm->mins[1],pm->mins[2]);
				VectorSet(maxs, pm->maxs[0],pm->maxs[1],pm->maxs[2]);
				VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

				AngleVectors( fwdAngles, fwd, NULL, NULL );
				VectorMA( pm->ps->origin, 32, fwd, traceto );

				pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, MASK_PLAYERSOLID );//FIXME: clip brushes too?
				VectorSubtract( pm->ps->origin, traceto, idealNormal );
				VectorNormalize( idealNormal );

//JAPRO - Serverside + Clientside - Re add flipkick and flipkickable npcs- Start
				kickedEnt = PM_BGEntForNum(trace.entityNum);

				if (GetFlipkick(pm->ps) >= 1) {
					if ( trace.fraction < 1.0f && ((trace.entityNum < MAX_CLIENTS) || (kickedEnt->s.eType == ET_NPC)) && (pm->ps->stats[STAT_DASHTIME] <= 0)) //ass
					//Dont allow frontkicking within 200ms of being frontkicked?

//JAPRO - Serverside + Clientside - Re add flipkick and flipkickable npcs- End
					{//there is a wall there
						int parts = SETANIM_LEGS;

						pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
						VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
						pm->ps->velocity[2] += 128;

						if ( !pm->ps->weaponTime )
							parts = SETANIM_BOTH;

						PM_SetAnim( parts, BOTH_WALL_FLIP_BACK1, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );

#ifdef _GAME
						if (g_flipKick.integer > 2)
							pm->ps->legsTimer = 0;
						else
#endif
							pm->ps->legsTimer -= 600; //I force this anim to play to the end to prevent landing on your head and suddenly flipping over.
											  //It is a bit too long at the end though, so I'll just shorten it.

						PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
						pm->cmd.upmove = 0;
						pm->ps->fd.forceJumpSound = 1;
						BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );

//JAPRO - Serverside + Clientside - Re add flipkick - Start
						//if ((trace.entityNum < MAX_CLIENTS) || (GetFlipkick(pm->ps) && kickedEnt->s.eType == ET_NPC)) //well we already tested for this

/*
#ifdef _GAME
						if ((trace.entityNum < MAX_CLIENTS) || (g_flipKick.integer && kickedEnt->s.eType == ET_NPC))
#else
						if ((trace.entityNum < MAX_CLIENTS) || ((cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FLIPKICK) && kickedEnt->s.eType == ET_NPC))
#endif
*/
						pm->ps->forceKickFlip = trace.entityNum+1; //let the server know that this person gets kicked by this client
					}
//JAPRO - Serverside + Clientside - Re add flipkick - End
				}
			}
//JAPRO - Serverside + Clientside - Re add flipkick - End
#endif

#if 1
			else if ( pm->cmd.forwardmove > 0 //pushing forward -- this is used for wallruns i guess?
				//&& pm->ps->fd.forceRageRecoveryTime < pm->cmd.serverTime	//not in a force Rage recovery period //JAPRO - Serverside + Clientside - Allow wallrun in rage recovery
				&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_1
				&& PM_WalkableGroundDistance() <= 80 //unfortunately we do not have a happy ground timer like SP (this would use up more bandwidth if we wanted prediction workign right), so we'll just use the actual ground distance.
				&& (pm->ps->legsAnim == BOTH_JUMP1 || pm->ps->legsAnim == BOTH_INAIR1 ) )//not in a flip or spin or anything
			{//run up wall, flip backwards
				if ( allowWallRuns ) {
					//FIXME: have to be moving... make sure it's opposite the wall... or at least forward?
					int wallWalkAnim = BOTH_WALL_FLIP_BACK1;
					int parts = SETANIM_LEGS;
					int contents = MASK_SOLID;//MASK_PLAYERSOLID;//CONTENTS_SOLID;
					//qboolean kick = qtrue;//JAPRO - Serverside + Clientside - Re add flipkick
					vec3_t fwd, traceto, mins, maxs, fwdAngles;
					trace_t	trace;
					vec3_t	idealNormal;
					bgEntity_t *traceEnt;

					if ( pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_2 ) {
						wallWalkAnim = BOTH_FORCEWALLRUNFLIP_START;
						parts = SETANIM_BOTH;
						//kick = qfalse;//JAPRO - Serverside + Clientside - Re add flipkick
					}
					else {
						if ( !pm->ps->weaponTime )
							parts = SETANIM_BOTH;
					}

					VectorSet(mins, pm->mins[0], pm->mins[1], 0.0f);
					VectorSet(maxs, pm->maxs[0], pm->maxs[1], 24.0f);
					VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);

					AngleVectors( fwdAngles, fwd, NULL, NULL );
					VectorMA( pm->ps->origin, 32, fwd, traceto );

					pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, contents );//FIXME: clip brushes too?
					VectorSubtract( pm->ps->origin, traceto, idealNormal );
					VectorNormalize( idealNormal );
					traceEnt = PM_BGEntForNum(trace.entityNum);

					if ( trace.fraction < 1.0f && ((trace.entityNum < ENTITYNUM_WORLD && traceEnt && traceEnt->s.solid != SOLID_BMODEL) || DotProduct(trace.plane.normal,idealNormal) > 0.7))
					{//there is a wall there
						pm->ps->velocity[0] = pm->ps->velocity[1] = 0;
						if ( wallWalkAnim == BOTH_FORCEWALLRUNFLIP_START )
						{
							pm->ps->velocity[2] = forceJumpStrength[FORCE_LEVEL_3]/2.0f;
						}
						else
						{
							VectorMA( pm->ps->velocity, -150, fwd, pm->ps->velocity );
							pm->ps->velocity[2] += 150.0f;
						}
						PM_SetAnim( parts, wallWalkAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD ); //animate me
						PM_SetForceJumpZStart(pm->ps->origin[2]);//so we don't take damage if we land at same height
						pm->cmd.upmove = 0;
						pm->ps->fd.forceJumpSound = 1;
						BG_ForcePowerDrain( pm->ps, FP_LEVITATION, 5 );
//JAPRO - Serverside + Clientside - Re add flipkick - Start
#if 0
						if (GetFlipkick(pm->ps) >= 1) {
/*
#ifdef _GAME
						if (g_flipKick.integer >= 1) {
#else
						if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FLIPKICK) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FLIPKICK)) {
#endif
*/
							if (kick && traceEnt && (traceEnt->s.eType == ET_PLAYER || traceEnt->s.eType == ET_NPC)) {
								pm->ps->forceKickFlip = traceEnt->s.number+1;
								trap->SendServerCommand( -1, va("chat \"SPOT TWO Flipkick by %s, at time %i, his time %i, last kick time is %i, diff is %i\n\"", client->pers.netname, level.time, client->pers.cmd.serverTime, client->lastKickedByTime, client->lastKickedByTime - level.time));
							}
						}
#endif
//JAPRO - Serverside + Clientside - Re add flipkick - End
							pm->cmd.rightmove = pm->cmd.forwardmove= 0;
					}
				}
			}

#endif

			else if ( (!BG_InSpecialJump( legsAnim )//not in a special jump anim
						||BG_InReboundJump( legsAnim )//we're already in a rebound
						||BG_InBackFlip( legsAnim ) )//a backflip (needed so you can jump off a wall behind you)
					//&& pm->ps->velocity[2] <= 0
					&& pm->ps->velocity[2] > -1200 //not falling down very fast
					&& !(pm->ps->pm_flags&PMF_JUMP_HELD)//have to have released jump since last press
					&& (pm->cmd.forwardmove||pm->cmd.rightmove)//pushing in a direction
					//&& pm->ps->forceRageRecoveryTime < pm->cmd.serverTime	//not in a force Rage recovery period
					&& pm->ps->fd.forcePowerLevel[FP_LEVITATION] > FORCE_LEVEL_2//level 3 jump or better
					//&& WP_ForcePowerAvailable( pm->gent, FP_LEVITATION, 10 )//have enough force power to do another one
					&& BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION)
					&& (pm->ps->origin[2]-pm->ps->fd.forceJumpZStart) < (forceJumpHeightMax[FORCE_LEVEL_3]-(BG_ForceWallJumpStrength()/2.0f)) //can fit at least one more wall jump in (yes, using "magic numbers"... for now)
					//&& (pm->ps->legsAnim == BOTH_JUMP1 || pm->ps->legsAnim == BOTH_INAIR1 ) )//not in a flip or spin or anything
					)
			{//see if we're pushing at a wall and jump off it if so
				if ( allowWallGrabs )
				{
					//FIXME: make sure we have enough force power
					//FIXME: check  to see if we can go any higher
					//FIXME: limit to a certain number of these in a row?
					//FIXME: maybe don't require a ucmd direction, just check all 4?
					//FIXME: should stick to the wall for a second, then push off...
					vec3_t checkDir, traceto, mins, maxs, fwdAngles;
					trace_t	trace;
					vec3_t	idealNormal;
					int		anim = -1;

					VectorSet(mins, pm->mins[0], pm->mins[1], 0.0f);
					VectorSet(maxs, pm->maxs[0], pm->maxs[1], 24.0f);
					VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0.0f);

					if ( pm->cmd.rightmove )
					{
						if ( pm->cmd.rightmove > 0 )
						{
							anim = BOTH_FORCEWALLREBOUND_RIGHT;
							AngleVectors( fwdAngles, NULL, checkDir, NULL );
						}
						else if ( pm->cmd.rightmove < 0 )
						{
							anim = BOTH_FORCEWALLREBOUND_LEFT;
							AngleVectors( fwdAngles, NULL, checkDir, NULL );
							VectorScale( checkDir, -1, checkDir );
						}
					}
					else if ( pm->cmd.forwardmove > 0 )
					{
						anim = BOTH_FORCEWALLREBOUND_FORWARD;
						AngleVectors( fwdAngles, checkDir, NULL, NULL );
					}
					else if ( pm->cmd.forwardmove < 0 )
					{
						anim = BOTH_FORCEWALLREBOUND_BACK;
						AngleVectors( fwdAngles, checkDir, NULL, NULL );
						VectorScale( checkDir, -1, checkDir );
					}
					if ( anim != -1 )
					{//trace in the dir we're pushing in and see if there's a vertical wall there
						bgEntity_t *traceEnt;

						VectorMA( pm->ps->origin, 8, checkDir, traceto );
						pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID );//FIXME: clip brushes too?
						VectorSubtract( pm->ps->origin, traceto, idealNormal );
						VectorNormalize( idealNormal );
						traceEnt = PM_BGEntForNum(trace.entityNum);
						if ( trace.fraction < 1.0f
							&&fabs(trace.plane.normal[2]) <= 0.2f/*MAX_WALL_GRAB_SLOPE*/
							&&((trace.entityNum<ENTITYNUM_WORLD&&traceEnt&&traceEnt->s.solid!=SOLID_BMODEL)||DotProduct(trace.plane.normal,idealNormal)>0.7) )
						{//there is a wall there
							float dot = DotProduct( pm->ps->velocity, trace.plane.normal );
							if ( dot < 1.0f )
							{//can't be heading *away* from the wall!
								//grab it!
								PM_GrabWallForJump( anim );
							}
						}
					}
				}
			}
			else
			{
				//FIXME: if in a butterfly, kick people away?
			}
			//END NEW JKA
		}
	}

#ifdef _GAME
	if ((g_tweakSaber.integer & ST_JK2RDFA) && !pm->ps->stats[STAT_RACEMODE])
#else
	if ((cgs.serverMod == SVMOD_JAPRO && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo & JAPRO_CINFO_JK2DFA)) || (cgs.serverMod == SVMOD_JAPLUS && (cgs.jcinfo & JAPLUS_CINFO_JK2DFA)))
#endif
	{
		if ( pm->cmd.upmove > 0
			&& (pm->ps->weapon == WP_SABER || pm->ps->weapon == WP_MELEE)
			&& !PM_IsRocketTrooper()
			&& (pm->ps->weaponTime > 0||pm->cmd.buttons&BUTTON_ATTACK) )
		{//okay, we just jumped and we're in an attack
			if ( !BG_InRoll( pm->ps, pm->ps->legsAnim )
				&& !PM_InKnockDown( pm->ps )
				&& !BG_InDeathAnim(pm->ps->legsAnim)
				&& !BG_FlippingAnim( pm->ps->legsAnim )
				&& !PM_SpinningAnim( pm->ps->legsAnim )
				&& !BG_SaberInSpecialAttack( pm->ps->torsoAnim )
				&& ( BG_SaberInAttack( pm->ps->saberMove ) ) )
			{//not in an anim we shouldn't interrupt
				//see if it's not too late to start a special jump-attack
				float animLength = PM_AnimLength( 0, (animNumber_t)pm->ps->torsoAnim );
				if ( animLength - pm->ps->torsoTimer < 500 )
				{//just started the saberMove
					//check for special-case jump attacks
					if ( pm->ps->fd.saberAnimLevel == FORCE_LEVEL_3 )
					{//using strong attacks
						if ( pm->cmd.forwardmove > 0 && //going forward
							(pm->cmd.buttons & BUTTON_ATTACK) && //must be holding attack still
							PM_GroundDistance() < 32 &&
							!BG_InSpecialJump(pm->ps->legsAnim))
						{//strong attack: jump-hack
							PM_SetSaberMove( PM_SaberJumpAttackMove() );
							pml.groundPlane = qfalse;
							pml.walking = qfalse;
							pm->ps->pm_flags |= PMF_JUMP_HELD;
							pm->ps->groundEntityNum = ENTITYNUM_NONE;
							VectorClear(pml.groundTrace.plane.normal);

							pm->ps->weaponTime = pm->ps->torsoTimer;
						}
					}
				}
			}
		}
	}

	if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
	{
		return qfalse;
	}
	if (pm->cmd.upmove > 0)
	{//no special jumps
		if (moveStyle == MV_QW || moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_Q3 || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJQ3 || moveStyle == MV_RJCPM || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM)
		{
			vec3_t hVel;
			float added, xyspeed, realjumpvelocity = JUMP_VELOCITY;

			if (moveStyle == MV_WSW)
				realjumpvelocity = 280.0f;
			else if (moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_Q3 || moveStyle == MV_RJQ3 || moveStyle == MV_RJCPM || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM)
				realjumpvelocity = 270.0f;

			hVel[0] = pm->ps->velocity[0];
			hVel[1] = pm->ps->velocity[1];
			hVel[2] = 0;
			xyspeed = sqrt(hVel[0] * hVel[0] + hVel[1] * hVel[1]);
			added = -DotProduct(hVel, pml.groundTrace.plane.normal);
			pm->ps->velocity[2] = realjumpvelocity;

			if (added > (xyspeed * 0.5))
				added = (xyspeed * 0.5);//Sad sanity check hack

			//Dont apply if added is quite small (prevent circlejump rampjump?)

			if (added > 0) {
				if (moveStyle == MV_QW || moveStyle == MV_PJK)
					pm->ps->velocity[2] += (added * 0.75f); //Forcejump rampjump initial upspeed
				else if (moveStyle == MV_WSW)
					pm->ps->velocity[2] += (added * 0.75f);//Make rampjump weaker for wsw since no speedloss
				else
					pm->ps->velocity[2] += (added * 1.25f); //Make rampjump stronger for cpm/q3/slick
			}
			else if (pm->ps->stats[STAT_JUMPTIME] > 0) { //DOUBLEJUMP DOUBLE JUMP
				pm->ps->velocity[2] += 100.0f;
				pm->ps->pm_flags &= ~PMF_JUMP_HELD;
			}

#if 0
			{
				gentity_t *gent = (gentity_t *)pm_entSelf;
				trap->SendServerCommand(gent - g_entities, va("chat \"XYSPEED: %.2f, ZSPEED: %.2f, ADDED: %.2f, JUMPTIME: %i\n\"", xyspeed, pm->ps->velocity[2], added, pm->ps->stats[STAT_JUMPTIME]));
			}
#endif

			pm->ps->stats[STAT_JUMPTIME] = 401; //The fuck? Great to know
			pm->ps->stats[STAT_LASTJUMPSPEED] = pm->ps->velocity[2];

		}
		else if (moveStyle == MV_TRIBES) {
			pm->ps->velocity[2] = 275;
			pm->ps->stats[STAT_JUMPTIME] = 401;
		}
		else if (moveStyle == MV_SURF) {
			pm->ps->velocity[2] = 270;
		}
		else {
			pm->ps->velocity[2] = JUMP_VELOCITY;
		}

		if (pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_SUPERJUMP) {
			pm->ps->velocity[2] *= 3.0f;
		}
	}

	//Jumping
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
	pm->ps->pm_flags |= PMF_JUMP_HELD;
	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	PM_SetForceJumpZStart(pm->ps->origin[2]);

	PM_AddEvent( EV_JUMP );

	//Set the animations
	if ( pm->ps->gravity > 0 && !BG_InSpecialJump( pm->ps->legsAnim ) )
	{
		PM_JumpForDir();
	}

	return qtrue;
}
/*
=============
PM_CheckWaterJump
=============
*/
static qboolean	PM_CheckWaterJump( void ) {
	vec3_t	spot;
	int		cont;
	vec3_t	flatforward;

	if (pm->ps->pm_time) {
		return qfalse;
	}

	// check for water jump
	if ( pm->waterlevel != 2 ) {
		return qfalse;
	}

	flatforward[0] = pml.forward[0];
	flatforward[1] = pml.forward[1];
	flatforward[2] = 0;
	VectorNormalize (flatforward);

	VectorMA (pm->ps->origin, 30, flatforward, spot);
	spot[2] += 4;
	cont = pm->pointcontents (spot, pm->ps->clientNum );
	if ( !(cont & CONTENTS_SOLID) ) {
		return qfalse;
	}

	spot[2] += 16;
	cont = pm->pointcontents (spot, pm->ps->clientNum );
	if ( cont & (CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_BODY) ) {
		return qfalse;
	}

	// jump out of water
	VectorScale (pml.forward, 200, pm->ps->velocity);
	pm->ps->velocity[2] = 350;

	pm->ps->pm_flags |= PMF_TIME_WATERJUMP;
	pm->ps->pm_time = 2000;

	return qtrue;
}

//============================================================================


/*
===================
PM_WaterJumpMove

Flying out of the water
===================
*/
static void PM_WaterJumpMove( void ) {
	// waterjump has no control, but falls

	PM_StepSlideMove( qtrue );

	pm->ps->velocity[2] -= pm->ps->gravity * pml.frametime;
	if (pm->ps->velocity[2] < 0) {
		// cancel as soon as we are falling down again
		pm->ps->pm_flags &= ~PMF_ALL_TIMES;
		pm->ps->pm_time = 0;
	}
}

/*
===================
PM_WaterMove

===================
*/
static void PM_WaterMove( void ) {
	int		i;
	vec3_t	wishvel;
	float	wishspeed;
	vec3_t	wishdir;
	float	scale;
	float	vel;
	float realspeed = pm->ps->speed;

	if ( PM_CheckWaterJump() ) {
		PM_WaterJumpMove();
		return;
	}
#if 0
	// jump = head for surface
	if ( pm->cmd.upmove >= 10 ) {
		if (pm->ps->velocity[2] > -300) {
			if ( pm->watertype == CONTENTS_WATER ) {
				pm->ps->velocity[2] = 100;
			} else if (pm->watertype == CONTENTS_SLIME) {
				pm->ps->velocity[2] = 80;
			} else {
				pm->ps->velocity[2] = 50;
			}
		}
	}
#endif
	PM_Friction ();

	scale = PM_CmdScale( &pm->cmd );
	//
	// user intentions
	//
	if ( !scale ) {
		wishvel[0] = 0;
		wishvel[1] = 0;
		if (pm->ps->clientNum >= MAX_CLIENTS && pm->ps->eFlags2 & EF2_NOT_USED_1) { //don't sink)
			realspeed = 100;
			if (pm->waterlevel == 2)
				wishvel[2] = 30;		// float towards top
			else if (pm->waterlevel > 2)
				wishvel[2] = 60;		// float towards top
		}
		else {
			wishvel[2] = -60;		// sink towards bottom;
		}
	} else {
		for (i=0 ; i<3 ; i++)
			wishvel[i] = scale * pml.forward[i]*pm->cmd.forwardmove + scale * pml.right[i]*pm->cmd.rightmove;

		wishvel[2] += scale * pm->cmd.upmove;
	}

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

	if ( wishspeed > realspeed * pm_swimScale ) {
		wishspeed = realspeed * pm_swimScale;
	}

	if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES)
		wishspeed *= 2;

	PM_Accelerate (wishdir, wishspeed, pm_wateraccelerate);

	// make sure we can go up slopes easily under water
	if ( pml.groundPlane && DotProduct( pm->ps->velocity, pml.groundTrace.plane.normal ) < 0 ) {
		vel = VectorLength(pm->ps->velocity);
		// slide along the ground plane
		PM_ClipVelocity (pm->ps->velocity, pml.groundTrace.plane.normal,
			pm->ps->velocity, OVERCLIP );

		VectorNormalize(pm->ps->velocity);
		VectorScale(pm->ps->velocity, vel, pm->ps->velocity);
	}

	PM_SlideMove( qfalse );
}

/*
===================
PM_FlyVehicleMove

===================
*/
static void PM_FlyVehicleMove( void )
{
	int		i;
	vec3_t	wishvel;
	float	wishspeed;
	vec3_t	wishdir;
	float	scale;
	float	zVel;
	float	fmove = 0.0f, smove = 0.0f;

	// We don't use these here because we pre-calculate the movedir in the vehicle update anyways, and if
	// you leave this, you get strange motion during boarding (the player can move the vehicle).
	//fmove = pm->cmd.forwardmove;
	//smove = pm->cmd.rightmove;

	// normal slowdown
	if ( pm->ps->gravity && pm->ps->velocity[2] < 0 && pm->ps->groundEntityNum == ENTITYNUM_NONE )
	{//falling
		zVel = pm->ps->velocity[2];
		PM_Friction ();
		pm->ps->velocity[2] = zVel;
	}
	else
	{
		PM_Friction ();
		if ( pm->ps->velocity[2] < 0 && pm->ps->groundEntityNum != ENTITYNUM_NONE )
		{
			pm->ps->velocity[2] = 0;	// ignore slope movement
		}
	}

	scale = PM_CmdScale( &pm->cmd );

	// Get The WishVel And WishSpeed
	//-------------------------------
	if ( pm->ps->clientNum >= MAX_CLIENTS )
	{//NPC

		// If The UCmds Were Set, But Never Converted Into A MoveDir, Then Make The WishDir From UCmds
		//--------------------------------------------------------------------------------------------
		if ((fmove!=0.0f || smove!=0.0f) &&	VectorCompare(pm->ps->moveDir, vec3_origin))
		{
			//trap->Printf("Generating MoveDir\n");
			for ( i = 0 ; i < 3 ; i++ )
			{
				wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
			}

			VectorCopy( wishvel, wishdir );
			wishspeed = VectorNormalize(wishdir);
			wishspeed *= scale;
		}
		// Otherwise, Use The Move Dir
		//-----------------------------
		else
		{
			wishspeed = pm->ps->speed;
			VectorScale( pm->ps->moveDir, pm->ps->speed, wishvel );
			VectorCopy( pm->ps->moveDir, wishdir );
		}
	}
	else
	{
		for ( i = 0 ; i < 3 ; i++ ) {
			wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
		}
		// when going up or down slopes the wish velocity should Not be zero
	//	wishvel[2] = 0;

		VectorCopy (wishvel, wishdir);
		wishspeed = VectorNormalize(wishdir);
		wishspeed *= scale;
	}

	// Handle negative speed.
	if ( wishspeed < 0 )
	{
		wishspeed = wishspeed * -1.0f;
		VectorScale( wishvel, -1.0f, wishvel );
		VectorScale( wishdir, -1.0f, wishdir );
	}

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );

	PM_Accelerate( wishdir, wishspeed, 100 );

	PM_StepSlideMove( 1 );
}

/*
===================
PM_FlyMove

Only with the flight powerup
===================
*/
static void PM_FlyMove( void ) {
	int		i;
	vec3_t	wishvel;
	float	wishspeed;
	vec3_t	wishdir;
	float	scale;

	// normal slowdown
	PM_Friction ();

	scale = PM_CmdScale( &pm->cmd );

	if ( pm->ps->pm_type == PM_SPECTATOR && pm->cmd.buttons & BUTTON_ALT_ATTACK) {
		//turbo boost
		scale *= 10;
	}

	//
	// user intentions
	//
	if ( !scale ) {
		wishvel[0] = 0;
		wishvel[1] = 0;
		wishvel[2] = pm->ps->speed * (pm->cmd.upmove/127.0f);
	} else {
		for (i=0 ; i<3 ; i++) {
			wishvel[i] = scale * pml.forward[i]*pm->cmd.forwardmove + scale * pml.right[i]*pm->cmd.rightmove;
		}

		wishvel[2] += scale * pm->cmd.upmove;
	}

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

	PM_Accelerate (wishdir, wishspeed, pm_flyaccelerate);

	PM_StepSlideMove( qfalse );
}


/*
===================
PM_AirMove

===================
*/
static void PM_AirMove( void ) {
	int			i;
	vec3_t		wishvel;
	float		fmove, smove;
	vec3_t		wishdir;
	float		wishspeed;
	float		scale;
	float		accelerate;
	usercmd_t	cmd;
	Vehicle_t	*pVeh = NULL;
	const int moveStyle = PM_GetMovePhysics();

	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
		bgEntity_t	*pEnt = pm_entSelf;

		if ( pEnt && pEnt->s.NPC_class == CLASS_VEHICLE )
		{
			pVeh = pEnt->m_pVehicle;
		}
	}

	if (pm->ps->pm_type != PM_SPECTATOR)
	{
#if METROID_JUMP
#if _CGAME
		if (cgs.serverMod == SVMOD_LMD) {
			PM_CheckJumpLugormod();
		} else
#endif
		{
			PM_CheckJump();
		}
#else
		if (pm->ps->fd.forceJumpZStart &&
			pm->ps->forceJumpFlip)
		{
			PM_CheckJump();
		}
#endif
	}
	PM_Friction();

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;

	if (moveStyle == MV_SURF) {
		if (pm->cmd.forwardmove != 0 && pm->cmd.rightmove != 0)	{
			pm->cmd.rightmove = 0;
			pml.right[1] = 0;
			pml.right[0] = 0;
		}
	}

	cmd = pm->cmd;
	scale = PM_CmdScale( &cmd );

	// set the movementDir so clients can rotate the legs for strafing
	PM_SetMovementDir();

	// project moves down to flat plane
	pml.forward[2] = 0;
	pml.right[2] = 0;
	VectorNormalize (pml.forward);
	VectorNormalize (pml.right);

	if ( pVeh && pVeh->m_pVehicleInfo->hoverHeight > 0 )
	{//in a hovering vehicle, have air control
		if ( 1 )
		{
			wishspeed = pm->ps->speed;
			VectorScale( pm->ps->moveDir, pm->ps->speed, wishvel );
			VectorCopy( pm->ps->moveDir, wishdir );
			scale = 1.0f;
		}
#if 0
		else
		{
			float controlMod = 1.0f;
			vec3_t	vfwd, vrt;
			vec3_t	vAngles;
			float speed = pm->ps->speed;
			float strafeSpeed = 0;

			if ( pml.groundPlane )
			{//on a slope of some kind, shouldn't have much control and should slide a lot
				controlMod = pml.groundTrace.plane.normal[2];
			}

			VectorCopy( pVeh->m_vOrientation, vAngles );
			vAngles[ROLL] = 0;//since we're a hovercraft, we really don't want to stafe up into the air if we're banking
			AngleVectors( vAngles, vfwd, vrt, NULL );

			if ( fmove < 0 )
			{//going backwards
				if ( speed < 0 )
				{//speed is negative, but since our command is reverse, make speed positive
					speed = fabs( speed );

					if ( pml.groundPlane )
					{//on a slope, still have some control
						speed = fabs( speed );
					}
					else
					{//can't reverse in air
						speed = 0;
					}

				}
				else if ( speed > 0 )
				{//trying to move back but speed is still positive, so keep moving forward (we'll slow down eventually)
					speed = 0;
				}
			}

			if ( pm->ps->clientNum < MAX_CLIENTS )
			{//do normal adding to wishvel
				VectorScale( vfwd, speed*controlMod*(fmove/127.0f), wishvel );
				//just add strafing
				if ( pVeh->m_pVehicleInfo->strafePerc )
				{//we can strafe
					if ( smove )
					{//trying to strafe
						float minSpeed = pVeh->m_pVehicleInfo->speedMax * 0.5f * pVeh->m_pVehicleInfo->strafePerc;
						strafeSpeed = fabs(DotProduct( pm->ps->velocity, vfwd ))*pVeh->m_pVehicleInfo->strafePerc;
						if ( strafeSpeed < minSpeed )
						{
							strafeSpeed = minSpeed;
						}
						strafeSpeed *= controlMod*((float)(smove))/127.0f;
						if ( strafeSpeed < 0 )
						{//pm_accelerate does not understand negative numbers
							strafeSpeed *= -1;
							VectorScale( vrt, -1, vrt );
						}
						//now just add it to actual velocity
						PM_Accelerate( vrt, strafeSpeed, pVeh->m_pVehicleInfo->traction );
					}
				}
			}
			else
			{
				if ( pVeh->m_pVehicleInfo->strafePerc )
				{//we can strafe
					if ( pm->ps->clientNum )
					{//alternate control scheme: can strafe
						if ( smove )
						{

							if ( fmove > 0 )
							{//actively accelerating
								strafeSpeed = pm->ps->speed;
							}
							else
							{//not stepping on accelerator, only strafe based on magnitude of current forward velocity
								strafeSpeed = fabs(DotProduct( pm->ps->velocity, vfwd ));
							}

							strafeSpeed = ((float)(smove))/127.0f;
						}
					}
				}
				//strafing takes away from forward speed
				VectorScale( vfwd, (fmove/127.0f)*(1.0f-pVeh->m_pVehicleInfo->strafePerc), wishvel );
				if ( strafeSpeed )
				{
					VectorMA( wishvel, strafeSpeed*pVeh->m_pVehicleInfo->strafePerc, vrt, wishvel );
				}
				VectorNormalize( wishvel );
				VectorScale( wishvel, speed*controlMod, wishvel );
			}
		}
#endif
	}
	else if ( gPMDoSlowFall )
	{//no air-control
		VectorClear( wishvel );
	}
	else if (pm->ps->pm_type == PM_JETPACK)
	{ //reduced air control while not jetting
		for ( i = 0 ; i < 2 ; i++ )
		{
			wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
		}
		wishvel[2] = 0;

		if (pm->cmd.upmove <= 0)
		{
            VectorScale(wishvel, 0.8f, wishvel);
		}
		else
		{ //if we are jetting then we have more control than usual
            VectorScale(wishvel, 2.0f, wishvel);
		}
	}
	else if (BG_IsNewJetpacking(pm->ps)) //New Jetpack
	{ //reduced air control while not jetting
		//REDO THIS NEWJETPACK2. FM3 scales by 2.2f (spacetrooper, genosian) or 1.75f not 0.9f.  Do we want to just adjust basespeed instead? More air control kinda crosses into grapples function
		if (0 && moveStyle == MV_TRIBES) {
			for (i = 0; i < 2; i++)
			{
				wishvel[i] = 0;// pml.forward[i] * fmove + pml.right[i] * smove;
			}
			wishvel[2] = 0;
		}
		else {
			for (i = 0; i < 2; i++)
			{
				wishvel[i] = pml.forward[i] * fmove + pml.right[i] * smove;
			}
			wishvel[2] = 0;
		}


		VectorScale(wishvel, 1.75f, wishvel);
	}
	else
	{
		for ( i = 0 ; i < 2 ; i++ )
		{
			wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
		}
		wishvel[2] = 0;
	}

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

	if (moveStyle == MV_SURF) //suspect - Devy?
	{
		if (pm->cmd.forwardmove != 0 && pm->cmd.rightmove != 0)
		{
			pm->cmd.rightmove = 0;
		}

		if (wishspeed > pm_surf_wishspeed)
		{
			VectorScale(wishvel, pm_surf_wishspeed / wishspeed, wishvel);
			wishspeed = pm_surf_wishspeed;
		}
	}
	else {
		wishspeed *= scale;
	}

	accelerate = pm_airaccelerate;

#if _SPPHYSICS
	if (moveStyle == MV_SP) {
		accelerate = pm_sp_airaccelerate;

		//SP Air Decel ?
		if ((DotProduct(pm->ps->velocity, wishdir)) < 0.0f)
		{//Encourage deceleration away from the current velocity
			wishspeed *= pm_sp_airDecelRate;//pm_airDecelRate
		}
	}
#endif

	if ( pVeh && pVeh->m_pVehicleInfo->type == VH_SPEEDER )
	{//speeders have more control in air
		//in mid-air
		accelerate = pVeh->m_pVehicleInfo->traction;
		if ( pml.groundPlane )
		{//on a slope of some kind, shouldn't have much control and should slide a lot
			accelerate *= 0.5f;
		}
	}
	// not on ground, so little effect on velocity
	if (moveStyle == MV_QW) {
		PM_AirAccelerate(wishdir, wishspeed, pm_qw_airaccelerate);//pm_qw_airaccel
	} else if (moveStyle == MV_TRIBES) {
		PM_AirAccelerateTribes(wishdir, wishspeed);//pm_qw_airaccel
	} else if (moveStyle == MV_SURF) {
		PM_CS_AirAccelerate(wishdir, wishspeed, pm_surf_airaccelerate);
	}
	else if (moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM)
	{
		float		accel;
		float		wishspeed2;

		wishspeed2 = wishspeed;
		if (DotProduct(pm->ps->velocity, wishdir) < 0)
			accel = pm_cpm_airstopaccelerate;
		else
			accel = pm_airaccelerate;

		if (pm->ps->movementDir == 2 || pm->ps->movementDir == 6) {
			if (moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM) {
				if (wishspeed > pm_cpm_airstrafewishspeed)
					wishspeed = pm_cpm_airstrafewishspeed;
				accel = pm_cpm_airstrafeaccelerate;
			}
			if (moveStyle == MV_SLICK) {
				if (wishspeed > pm_cpm_airstrafewishspeed)
					wishspeed = pm_cpm_airstrafewishspeed;
				accel = pm_slick_airstrafeaccelerate;
			}
		}

		PM_Accelerate (wishdir, wishspeed, accel); // change dis?
		CPM_PM_Aircontrol (pm, wishdir, wishspeed2);
	}
	/*
	else if (pm->ps->pm_type != PM_JETPACK && BG_IsNewJetpacking(pm->ps)) //New Jetpack //newjetpack2
	{
		PM_AirAccelerate(wishdir, wishspeed, 1.4f);//jetpack air control
	}
	*/
	else // movement style is 0 or 1
	{
		PM_Accelerate(wishdir, wishspeed, accelerate);
	}

	// we may have a ground plane that is very steep, even
	// though we don't have a groundentity
	// slide along the steep plane
	if ( pml.groundPlane )
	{
		if ( !(pm->ps->pm_flags&PMF_STUCK_TO_WALL) )
		{//don't slide when stuck to a wall
			if ( PM_GroundSlideOkay( pml.groundTrace.plane.normal[2] ) )
			{
				PM_ClipVelocity (pm->ps->velocity, pml.groundTrace.plane.normal,
					pm->ps->velocity, OVERCLIP );
			}
		}
	}

	if ( (pm->ps->pm_flags&PMF_STUCK_TO_WALL) )
	{//no grav when stuck to wall
		PM_StepSlideMove( qfalse );
	}
	else
	{
		PM_StepSlideMove( qtrue );
	}
}

static void PM_DodgeMove(int forward, int right)
{
	vec3_t dodgedir;
	int DODGE_SPEED = pm->ps->speed * 1.25f;
	int DODGE_JUMP_SPEED = 180;

	VectorMA( vec3_origin, right, pml.right, dodgedir );
	VectorMA( dodgedir, forward, pml.forward, dodgedir );
	VectorNormalize( dodgedir );

	if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
		pm->ps->fd.forcePower -= 25;//validate?
		DODGE_SPEED = pm->ps->speed * 1.75f;
		DODGE_JUMP_SPEED = 0;
#ifdef _GAME
		G_PlayEffect(EFFECT_LANDING_SAND, pm->ps->origin, dodgedir);//Should be spot on wall, and wallnormal, a better, predicted way to do this?
#endif
	}

	VectorScale( dodgedir, DODGE_SPEED, dodgedir );

	VectorCopy( dodgedir, pm->ps->velocity );

	pm->ps->velocity[2] = DODGE_JUMP_SPEED;
}

static void PM_DashMove(void)
{
	vec3_t dashdir, view;
	const int DASH_SPEED = pm->ps->speed * (1.9f / 1.28f); //475... ayy
	static const int DASH_JUMP_SPEED = 280;
	float xyspeed;

	xyspeed = sqrt(pm->ps->velocity[0] * pm->ps->velocity[0] +  pm->ps->velocity[1] * pm->ps->velocity[1]);

	VectorCopy(pml.forward, view);
	view[2] = 0; //I guess this is really pitch angle

	VectorMA(vec3_origin, 1, view, dashdir);
	VectorNormalize( dashdir );

	if(xyspeed <= DASH_SPEED)
		VectorScale(dashdir, DASH_SPEED, dashdir);
	else
		VectorScale(dashdir, xyspeed, dashdir);

	VectorCopy(dashdir, pm->ps->velocity);

	pm->ps->velocity[2] = DASH_JUMP_SPEED;
	pm->ps->stats[STAT_JUMPTIME] = 401;
}

static void PM_OverDriveMove(void) {
	//Are we the overdriver?
	//if (pm->ps->fd.forcePowersActive & (1 << FP_ABSORB)) {
		//Dunno what to do clientside here
	//}

	//Check if we are being overdrive waked
	if (pm->ps->stats[STAT_DEAD_YAW]) {
		int i;
		vec3_t diff;
		float len;
		for (i = 0; i < 32; i++) {
			if ((pm->ps->stats[STAT_DEAD_YAW] & (1 << i))) { //Push away this guy
				bgEntity_t *bgEnt = PM_BGEntForNum(i);
				if (bgEnt) {
					VectorSubtract(pm->ps->origin, bgEnt->playerState->origin, diff);
					len = VectorNormalize(diff);
					if (len < 32)
						len = 32;

					VectorMA(pm->ps->velocity, 6000 / len, diff, pm->ps->velocity);
					//Break or keep looking for other people using this? how does this behave with multiple overdrivers
				}
			}
		}
	}
	pm->ps->stats[STAT_DEAD_YAW] = 0;
}

static void PM_ThrustMove(void)
{
	if (!pm->ps->stats[STAT_WJTIME] && (pm->cmd.buttons & BUTTON_FORCE_LIGHTNING)) {
		pm->ps->stats[STAT_WJTIME] = 800;
		pm->ps->fd.forcePower = pm->ps->fd.forcePower * 0.25f;
#ifdef _GAME
		gentity_t *self = (gentity_t *)pm_entSelf;
		G_PlayEffect(EFFECT_LANDING_SNOW, pm->ps->origin, pml.forward);//Should be spot on wall, and wallnormal, a better, predicted way to do this?
		G_PlayEffectID(G_EffectIndex("env/powerbolt"), pm->ps->origin, pm->ps->viewangles);
		G_Sound(self, CHAN_BODY, G_SoundIndex("sound/weapons/force/speed.wav"));
#endif
	}
	if (pm->ps->stats[STAT_WJTIME] > 500) { //500 to 0
		float strength;
		float basespeed = pm->ps->basespeed;
		float dot = DotProduct(pml.forward, pm->ps->velocity); //-1 to 1.  -1 should be strongest 1 sh ould be weakest.

		if (dot < 0)
			dot = 0;
		if (basespeed > 320)
			basespeed = 320;

		strength = basespeed / (dot + 1); //basespeed sometimes shits itself?

		//Com_Printf("Strength modifier is %.2f because dot is %.2f and speed is %.2f\n", strength, dot, basespeed);
		//Modify strength based on current vel length.  Faster we are going, less it boosts.  but define "we are going" as the vel length times the dotproduct of vel and forward.  Lower cap at 0 instead of -1.

		if (strength > 3)
			strength = 3;
		else if (strength < 0.4)
			strength = 0.4;

		strength *= pm->ps->fd.forcePower;

		VectorMA(pm->ps->velocity, 140 * strength * pml.frametime, pml.forward, pm->ps->velocity); //fall off the faster we go?

		pm->ps->fd.forcePowersActive |= (1 << FP_SPEED);
	}
	else if (pm->ps->stats[STAT_WJTIME] > 300) { //cooldown
	}
	else {
		pm->ps->fd.forcePowersActive &= ~(1 << FP_SPEED);
	}
}

static void PM_BlinkMove(void) //Just blink for now
{
	const float BLINK_DURATION = 300;
	const float BLINK_STRENGTH = 3500;
	const int	FORCE_COST = 25;

	//Todo - change bind from lightning? More restrictions? If keep as lightning, disregard actual lightning?
	//Todo - fix the trace behaviour where if it hits a plane it just stops at that spot.  Should slide along for the rest of the stepsize?  this makes it really hard to use this if you are on the ground and aimed even 1 degree down
	//Todo, rewrite so only checks if button is used.  Also way to pick a special (force profile?). Also rewrite so this calls individual special functions.

	//Maybe there is a better way to do this performance-wise.  Or a way to redesign the traces so that instead of doign 1 every frame, it does 1 every time the trace stepsize > 100 or something.
	//E.g. adding the blink stepsize each frame and only doing a trace when it hits the limit, then resetting the counter.
	//Doing time*time means the traces at start/finish are very small

	if (!pm->ps->stats[STAT_WJTIME] && (pm->ps->fd.forcePower > FORCE_COST) && (pm->cmd.buttons & BUTTON_FORCE_LIGHTNING) && (pm->ps->fd.forceRageRecoveryTime <= pm->cmd.serverTime) && !pm->ps->powerups[PW_REDFLAG] && !pm->ps->powerups[PW_NEUTRALFLAG] && !pm->ps->powerups[PW_BLUEFLAG]) {
		pm->ps->stats[STAT_WJTIME] = BLINK_DURATION;
		pm->ps->fd.forcePower -= FORCE_COST;
		if (pm->ps->fd.forcePower < 0)
			pm->ps->fd.forcePower = 0;
#ifdef _GAME
		gentity_t *self = (gentity_t *)pm_entSelf;
		G_PlayEffectID(G_EffectIndex("howler/sonic"), pm->ps->origin, pm->ps->viewangles);
		G_PlayEffectID(G_EffectIndex("env/powerbolt_long"), pm->ps->origin, pm->ps->viewangles);
		G_Sound(self, CHAN_BODY, G_SoundIndex("sound/weapons/force/teamforce.mp3"));
		pm->ps->fd.forceRageRecoveryTime = level.time + 10000; // ?
#endif
	}

	if (pm->ps->stats[STAT_WJTIME] > 0) { //500 to 0
		trace_t trace;
		vec3_t traceto;
		float time, scale;

		if (pm->ps->stats[STAT_WJTIME] > (BLINK_DURATION*0.5f)) //First half of blink
			time = (BLINK_DURATION - pm->ps->stats[STAT_WJTIME]) * 0.001f; //0 to 0.5
		else //Second half of blink
			time = (pm->ps->stats[STAT_WJTIME]) * 0.001f; //0.5 to 0

		scale = (time*time * BLINK_STRENGTH) + 1; //Time*time so this isnt linear ramping.  To make it feel smoother.

		VectorMA(pm->ps->origin, scale*pml.frametime / 0.008f, pml.forward, traceto); //blink stepsize
		pm->trace(&trace, pm->ps->origin, pm->mins, pm->maxs, traceto, pm->ps->clientNum, MASK_PLAYERSOLID); //clip messes this up?
		if (trace.fraction == 1)
			VectorCopy(trace.endpos, pm->ps->origin);

		pm->ps->fd.forcePowersActive |= (1 << FP_RAGE);
		//Com_Printf("WJTIME 2nd %i Scale %.2f\n", pm->ps->stats[STAT_WJTIME], scale);
	}
	else {
		pm->ps->fd.forcePowersActive &= ~(1 << FP_RAGE);
	}
}

static void PM_CheckDash(void)
{
	static const int DASH_DELAY = 800;
	int moveStyle = PM_GetMovePhysics();

	if (pm->ps->stats[STAT_DASHTIME] > 0)
		return;
	if (pm->ps->stats[STAT_HEALTH] <= 0) {
		return;
	}
	if (pm->ps->weaponTime > 0)
		return;
	if (moveStyle != MV_WSW && moveStyle != MV_TRIBES) {
		return;
	}

	if (moveStyle == MV_TRIBES && (((pm->ps->velocity[0]*pm->ps->velocity[0] + pm->ps->velocity[1] *pm->ps->velocity[1]) > (pm->ps->speed * pm->ps->speed * 1.48f)) || (pm->ps->fd.forcePower < 25))) {
		return;
	}

	if (moveStyle == MV_TRIBES) {
		if (pm->ps->groundEntityNum == ENTITYNUM_NONE && (PM_GroundDistance() > 2.0f)) //MV_TRIBES problem, sometimes it detects us being in the air when we are actually on ground(or like 1 unit off ground during a ski?).  Have to check ground dist instead?
			return;
	}
	else {
		if (pm->ps->groundEntityNum == ENTITYNUM_NONE) //MV_TRIBES problem, sometimes it detects us being in the air when we are actually on ground(or like 1 unit off ground during a ski?).  Have to check ground dist instead?
			return;
	}

	if (moveStyle == MV_TRIBES)
		pm->ps->stats[STAT_DASHTIME] = 1050;
	else
		pm->ps->stats[STAT_DASHTIME] = DASH_DELAY;

	//PM_AddEvent( EV_FALL );

	if (pm->cmd.buttons & BUTTON_WALKING || moveStyle == MV_TRIBES) { //Dodge move
		if (pm->cmd.forwardmove > 0) {//W
			if (pm->cmd.rightmove > 0 && moveStyle != MV_TRIBES) //D
				PM_DodgeMove(1, 1);
			else if (pm->cmd.rightmove < 0 && moveStyle != MV_TRIBES) //A
				PM_DodgeMove(1, -1);
			else
				PM_DodgeMove(1, 0);
		}
		else if (pm->cmd.forwardmove < 0 && moveStyle != MV_TRIBES) {//S
			if (pm->cmd.rightmove > 0) //D
				PM_DodgeMove(-1, 1);
			else if (pm->cmd.rightmove < 0) //A
				PM_DodgeMove(-1, -1);
			else
				PM_DodgeMove(-1, 0);
		}
		else if (moveStyle != MV_TRIBES) {
			if (pm->cmd.rightmove > 0) //D
				PM_DodgeMove(0, 1);
			else if (pm->cmd.rightmove < 0) //A
				PM_DodgeMove(0, -1);
		}
	}
	else { //Dash move
		PM_DashMove(); //Dont care what wasd keys they press, due to pussers.
	}
}

static void PlayerTouchWall(int nbTestDir, float maxZnormal, vec3_t *normal) //loda fixme, this does not detect some walls...
{
	vec3_t min, max, dir;
	int i, j;
	trace_t trace;
	float dist = 1.0;

	#define M_TWOPI	6.28318530717958647692

	for(i = 0;i < nbTestDir;i++) {
		dir[0] = pm->ps->origin[0] + ( pm->maxs[0]*cos( ( M_TWOPI/nbTestDir )*i ) + pm->ps->velocity[0] * 0.015f );
		dir[1] = pm->ps->origin[1] + ( pm->maxs[1]*sin( ( M_TWOPI/nbTestDir )*i ) + pm->ps->velocity[1] * 0.015f );
		dir[2] = pm->ps->origin[2];

		for(j = 0;j < 2; j++) {
			min[j] = pm->mins[j];
			max[j] = pm->maxs[j];
		}
		min[2] = max[2] = 0;
		//VectorScale(dir, 1.002f, dir); // ditching this fixes walljump not registering on some surfaces.. could it be vectorScale fucks with the sign somehow??

		pm->trace(&trace, pm->ps->origin, min, max, dir, pm->ps->clientNum, CONTENTS_SOLID);

		if(trace.allsolid)
			return;

		if(trace.fraction == 1)
			continue; // no wall in this direction

		if(trace.surfaceFlags & (SURF_SKY))
			continue;

		if(trace.entityNum > 0) {//!= entitynum_none? or entitynum_world ?
			bgEntity_t *bgEnt = PM_BGEntForNum(trace.entityNum);
			if (bgEnt && (bgEnt->s.eType == ET_PLAYER))
					continue;
		}

		if(trace.fraction > 0) {
			if(dist > trace.fraction && fabs( trace.plane.normal[2]) < maxZnormal) {
				dist = trace.fraction;
				VectorCopy(trace.plane.normal, *normal);
			}
		}
	}
}

static void PM_CheckWallJump( void )//loda fixme, wip
{
	vec3_t normal;
	float hspeed;
	static const int WJ_DELAY = 1600;
	static const int DODGE_SPEED = 380;
	static const int MIN_WJSPEED = 200;
	static const int WJ_UPSPEED = 370;
	static const float WJ_BOUNCEFACTOR = 0.5;//0.3?
	static const int DASH_DELAY = 800;
	trace_t trace;
	vec3_t point;
	vec3_t xyspeed;

	if (pm->ps->groundEntityNum != ENTITYNUM_NONE)//Wut? this should be entitynum_none?
		return;//only in air?
	//hm... needs a slight delay after dash i guess... idk

	if (pm->ps->weaponTime > 0)
		return;

	//if ((pm->ps->origin[2] - pm->ps->fd.forceJumpZStart) > 128)//(forceJumpHeightMax[FORCE_LEVEL_3]-(BG_ForceWallJumpStrength()/2.0f)))
		//return; //This means if we are more than 128 above our jump, abort..?

	//if (PM_ForceJumpingUp())//only for bhops loda fixme, uh use forcejumpZstartheight to only do this if we are bhop height :S?
		//return;

	if (PM_GetMovePhysics() != MV_WSW)
		return;

	if (pm->ps->stats[STAT_WJTIME] > 0)
		return;

	if (pm->ps->stats[STAT_DASHTIME] > (DASH_DELAY - 100))
		return;

	point[0] = pm->ps->origin[0];
	point[1] = pm->ps->origin[1];
	point[2] = pm->ps->origin[2] - STEPSIZE;

	// don't walljump if our height is smaller than a step
	// unless the player is moving faster than dash speed and upwards
	xyspeed[0] = pm->ps->velocity[0];
	xyspeed[1] = pm->ps->velocity[1];
	xyspeed[2] = 0;

	hspeed = VectorLength(xyspeed);

	pm->trace(&trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, CONTENTS_SOLID);

	if((hspeed > DODGE_SPEED && pm->ps->velocity[2] > 8) || (trace.fraction == 1) || /*(!ISWALKABLEPLANE(&trace.plane)*/ !trace.startsolid)
	{
		float oldupvelocity = pm->ps->velocity[2];

		VectorClear(normal);
		PlayerTouchWall( 12, 0.3f, &normal ); //0.7 ? still fucking broken
		if(!VectorLength(normal))
			return;

		//dont do this if we arnt touching a wall... FIXME?

		pm->ps->velocity[2] = 0;

		//hspeed = VectorNormalize(xyspeed); //why

		PM_ClipVelocity( pm->ps->velocity, normal, pm->ps->velocity, 1.0005f );
		VectorMA( pm->ps->velocity, WJ_BOUNCEFACTOR, normal, pm->ps->velocity );

		if( hspeed < MIN_WJSPEED )
			hspeed = MIN_WJSPEED;

		VectorNormalize( pm->ps->velocity );

		VectorScale( pm->ps->velocity, hspeed, pm->ps->velocity );
		pm->ps->velocity[2] = ( oldupvelocity > WJ_UPSPEED ) ? oldupvelocity : WJ_UPSPEED; // jal: if we had a faster upwards speed, keep it

		pm->ps->stats[STAT_WJTIME] = WJ_DELAY;

		//PM_AddEvent( EV_FALL );
#ifdef _GAME
		G_PlayEffect( EFFECT_LANDING_SAND, trace.endpos, trace.plane.normal );//Should be spot on wall, and wallnormal, a better, predicted way to do this?
#endif

	/*
#ifdef _GAME
{
    gclient_t *client = NULL;
	int clientNum = pm->ps->clientNum;
	if (0 <= clientNum && clientNum < MAX_CLIENTS) {
		client = g_entities[clientNum].client;
	}
	if (client->pers.practice)
		pm->ps->stats[STAT_JUMPTIME] = 401;
}
#endif
	*/
	}
}

#if _GRAPPLE


static void PM_GetGrappleAnim( void ) {
	vec3_t  facingFwd, facingRight, facingAngles;
	int	anim = -1;
	float dotR, dotF;

	//Set anims from raz0r
	VectorSet(facingAngles, 0, pm->ps->viewangles[YAW], 0);

	AngleVectors(facingAngles, facingFwd, facingRight, NULL);
	dotR = DotProduct(facingRight, pm->ps->velocity);
	dotF = DotProduct(facingFwd, pm->ps->velocity);

	if (fabsf(dotR) > fabsf(dotF) * 1.5f) {
		if (dotR > 150) {
			anim = BOTH_FORCEJUMPRIGHT1;
		}
		else if (dotR < -150) {
			anim = BOTH_FORCEJUMPLEFT1;
		}
	}
	else {
		if (dotF > 150) {
			anim = BOTH_FORCEJUMP1;
		}
		else if (dotF < -150) {
			anim = BOTH_FORCEJUMPBACK1;
		}
	}
	if (anim != -1) {
		int parts = SETANIM_BOTH;
		if (pm->ps->weaponTime) {//FIXME: really only care if we're in a saber attack anim...
			parts = SETANIM_LEGS;
		}

		PM_SetAnim(parts, anim, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
	}
}

static void PM_GrappleMove( void ) {
	vec3_t vel, v;
	float vlen;
#if _GAME
	int pullSpeed = g_hookStrength.integer;
#else
	int pullSpeed = cgs.hookpull ? cgs.hookpull : 800;

	if (cgs.serverMod == SVMOD_JAPLUS && (pm->cmd.buttons & BUTTON_USE)) {
		return;
	}
#endif

	VectorScale(pml.forward, -16, v);
	VectorAdd(pm->ps->lastHitLoc, v, v);
	VectorSubtract(v, pm->ps->origin, vel);

#if _GAME
	//if ( pm->ps->pm_flags & PMF_GRAPPLE_PULL_QUAKE2 )
#else
	if (cgs.serverMod == SVMOD_JAPRO)
#endif
		vel[2] = vel[2] - pm->ps->viewheight - 4;

	vlen = VectorLength(vel);
	VectorNormalize(vel);

	if (vlen <= 100.0f)
		VectorScale(vel, (pullSpeed / 80.0f) * vlen, vel);
	else
		VectorScale(vel, pullSpeed, vel);

	VectorCopy(vel, pm->ps->velocity);

	pml.groundPlane = qfalse;

	PM_GetGrappleAnim();
}

/*
===================
PM_GrappleMoveTarzan

===================
*/
static void PM_GrappleMoveTarzan( void ) {
	vec3_t vel;
	float vlen;
	int pullSpeed = 800;
	int pullStrength1 = 20;
	int pullStrength2 = 40;

#if _GAME
	if (!pm->ps->stats[STAT_RACEMODE]) {
		pullSpeed = g_hookStrength.integer;
		pullStrength1 = g_hookStrength1.integer;
		pullStrength2 = g_hookStrength2.integer;
	}
#else
	if (!pm->ps->stats[STAT_RACEMODE]) {
		pullSpeed = cgs.hookpull;
	}
#endif

	VectorSubtract(pm->ps->lastHitLoc, pm->ps->origin, vel); //Lasthitloc gets bugged?
	vlen = VectorLength(vel);
	VectorNormalize( vel );

	if (vlen < ( pullSpeed / 2 ) )
		PM_Accelerate(vel, 2 * vlen, vlen * ( pullStrength2 / (float)pullSpeed ) );
	else
		PM_Accelerate(vel, pullSpeed, pullStrength1);

	if ( vel[2] > 0.5f && pml.walking ) {
		pml.walking = qfalse;
		//PM_ForceLegsAnim( BOTH_JUMP1  ); //LEGS_JUMP
	}

	pml.groundPlane = qfalse;

	PM_GetGrappleAnim();

}

static void PM_GrappleMoveTribes(void) {
	vec3_t diff, diffNormal;
	float oldVel, newVel, pullStrength = 7;

	VectorSubtract(pm->ps->lastHitLoc, pm->ps->origin, diff);
	VectorCopy(diff, diffNormal);
	VectorNormalize(diffNormal);

	//Should class modify wishspeed or accel strength or both?  probably accel strength.
	if (pm->ps->stats[STAT_MAX_HEALTH] == 1000)
		pullStrength = 5;
	else if (pm->ps->stats[STAT_MAX_HEALTH] == 500)
		pullStrength = 9;

	if (!VectorLengthSquared(pm->ps->hyperSpaceAngles)) {//Its on a stationary target, so don't do the chase...
		//Todo: figure out how to stop them from just doing this to teammates
		//Maybe adjust the vectorscale by how fast the enemy is moving?

		oldVel = VectorLength(pm->ps->velocity);
		PM_Accelerate(diffNormal, 600, pullStrength); //600 is WishSpeed
		newVel = VectorLength(pm->ps->velocity);

		if (newVel > (pm->ps->speed * 1.75f)) {//Dont give them an advantage to grapple launching instead of dashing for gaining speed
			newVel += pml.frametime * 200; //Grapple air friction
			VectorScale(pm->ps->velocity, (oldVel / newVel), pm->ps->velocity);
		}

		//Com_Printf("^7Detecting hook is stationary\n");
	}
	else {
		float dot, wishSpeed;
		vec3_t hookVelNormal;

		VectorCopy(pm->ps->hyperSpaceAngles, hookVelNormal);
		VectorNormalize(hookVelNormal);
		dot = DotProduct(diffNormal, hookVelNormal); //Am I moving towards my target

		wishSpeed = VectorLength(pm->ps->hyperSpaceAngles) * dot * 0.9f;

		if (wishSpeed < 300)
			wishSpeed = 300;
		//else give this a max so we cant tether to people going like 300kph effectively?

		//oldVel = VectorLength(pm->ps->velocity);
		PM_Accelerate(diffNormal, wishSpeed, pullStrength); //600 is WishSpeed
		newVel = VectorLength(pm->ps->velocity);

		if (newVel > (pm->ps->speed * 1.75f))//Dont give them an advantage to grapple launching instead of dashing for gaining speed
			VectorScale(pm->ps->velocity, wishSpeed / newVel, pm->ps->velocity); //Can this speed us up?

		//Com_Printf("^3Detecting hook is moving. Hook speed is %.0f, our speed is %.0f, dist is %.2f, dot is %.2f, wishSpeed is %.0f\n", VectorLength(pm->ps->hyperSpaceAngles), VectorLength(pm->ps->velocity), VectorLength(diff), dot, wishSpeed);
	}

	if (diff[2] > 0.5f && pml.walking) {
		pml.walking = qfalse;
		//Com_Printf("^1Setting walking false\n");
		//PM_ForceLegsAnim( BOTH_JUMP1  ); //LEGS_JUMP
	}

	pml.groundPlane = qfalse;

	PM_GetGrappleAnim();
}
#endif

/*
===================
PM_WalkMove

===================
*/
static void PM_WalkMove( void ) {
	int			i;
	vec3_t		wishvel;
	float		fmove, smove;
	vec3_t		wishdir;
	float		wishspeed = 0.0f;
	float		scale;
	usercmd_t	cmd;
	float		accelerate;
	float		vel, realaccelerate = pm_accelerate, realduckscale = pm_duckScale;
	qboolean	npcMovement = qfalse;
	const int   moveStyle = PM_GetMovePhysics();


	if ( pm->waterlevel > 2 && DotProduct( pml.forward, pml.groundTrace.plane.normal ) > 0 ) {
		// begin swimming
		PM_WaterMove();
		return;
	}


	if (pm->ps->pm_type != PM_SPECTATOR)
	{
		qboolean jumped = qfalse;

#if _CGAME
		if (cgs.serverMod == SVMOD_LMD) {
			jumped = PM_CheckJumpLugormod();
		} else
#endif
		{
			jumped = PM_CheckJump();
		}

		if (jumped) {
			// jumped away
			if ( pm->waterlevel > 1 ) {
				PM_WaterMove();
			} else {
				PM_AirMove();
			}
			return;
		}
	}

	if (moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM)
		realaccelerate = pm_cpm_accelerate;
	else if (moveStyle == MV_Q3 || moveStyle == MV_RJQ3)
		realduckscale = pm_vq3_duckScale;
	else if (moveStyle == MV_WSW) {
		realaccelerate = pm_wsw_accelerate;
		realduckscale = pm_wsw_duckScale;
	}
#if _SPPHYSICS
	else if (moveStyle == MV_SP) {
		realaccelerate = pm_sp_accelerate;
	}
#endif
	else if (moveStyle == MV_SLICK) {
		realaccelerate = pm_slick_accelerate;
	}
	else if (moveStyle == MV_TRIBES && (pm->cmd.buttons & BUTTON_DASH)) {
		realaccelerate = pm_tribes_accelerate;
	}
	else if (moveStyle == MV_SURF) {
		realaccelerate = pm_surf_accelerate;
	}

	PM_Friction ();

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;

	cmd = pm->cmd;
	scale = PM_CmdScale( &cmd );

	// set the movementDir so clients can rotate the legs for strafing
	PM_SetMovementDir();

	// project moves down to flat plane
	pml.forward[2] = 0;
	pml.right[2] = 0;

	// project the forward and right directions onto the ground plane
	if (moveStyle != MV_SURF) {
		PM_ClipVelocity(pml.forward, pml.groundTrace.plane.normal, pml.forward, OVERCLIP);
		PM_ClipVelocity(pml.right, pml.groundTrace.plane.normal, pml.right, OVERCLIP);
	}
	//
	VectorNormalize (pml.forward);
	VectorNormalize (pml.right);

	// Get The WishVel And WishSpeed
	//-------------------------------
	if ( pm->ps->clientNum >= MAX_CLIENTS && !VectorCompare( pm->ps->moveDir, vec3_origin ) )
	{//NPC
		bgEntity_t *pEnt = pm_entSelf;

		if (pEnt && pEnt->s.NPC_class == CLASS_VEHICLE)
		{
			// If The UCmds Were Set, But Never Converted Into A MoveDir, Then Make The WishDir From UCmds
			//--------------------------------------------------------------------------------------------
			if ((fmove!=0.0f || smove!=0.0f) &&	VectorCompare(pm->ps->moveDir, vec3_origin))
			{
				//trap->Printf("Generating MoveDir\n");
				for ( i = 0 ; i < 3 ; i++ )
				{
					wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
				}

				VectorCopy( wishvel, wishdir );
				wishspeed = VectorNormalize(wishdir);
				wishspeed *= scale;
			}
			// Otherwise, Use The Move Dir
			//-----------------------------
			else
			{
				//wishspeed = pm->ps->speed;
				VectorScale( pm->ps->moveDir, pm->ps->speed, wishvel );
				VectorCopy (wishvel, wishdir);
				wishspeed = VectorNormalize(wishdir);
			}

			npcMovement = qtrue;
		}
	}

	if (!npcMovement)
	{
		for ( i = 0 ; i < 3 ; i++ ) {
			wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
		}
		// when going up or down slopes the wish velocity should Not be zero

		VectorCopy (wishvel, wishdir);
		wishspeed = VectorNormalize(wishdir);
		wishspeed *= scale;
	}

	if (moveStyle == MV_SURF) {
		if (wishspeed != 0 && (wishspeed > pm_surf_wishspeed)) {
			VectorScale(wishvel, pm_surf_wishspeed / wishspeed, wishvel);
			wishspeed = pm_surf_wishspeed;
		}
	}

	// clamp the speed lower if ducking
	if ( pm->ps->pm_flags & PMF_DUCKED ) {
		if ( wishspeed > pm->ps->speed * realduckscale ) {
			wishspeed = pm->ps->speed * realduckscale;
		}
	}
	else if ( (pm->ps->pm_flags & PMF_ROLLING) && !BG_InRoll(pm->ps, pm->ps->legsAnim) &&
		!PM_InRollComplete(pm->ps, pm->ps->legsAnim))
	{
		if ( wishspeed > pm->ps->speed * realduckscale ) {
			wishspeed = pm->ps->speed * realduckscale;
		}
	}

	// clamp the speed lower if wading or walking on the bottom
	if ( pm->waterlevel ) {
		float	waterScale;

		waterScale = pm->waterlevel / 3.0;
		waterScale = 1.0 - ( 1.0 - pm_swimScale ) * waterScale;
		if ( wishspeed > pm->ps->speed * waterScale ) {
			wishspeed = pm->ps->speed * waterScale;
		}
	}

	// when a player gets hit, they temporarily lose
	// full control, which allows them to be moved a bit
	if ( pm_flying == FLY_HOVER )
	{
		accelerate = pm_vehicleaccelerate;
	}
	else if (((pml.groundTrace.surfaceFlags & SURF_SLICK) && moveStyle != MV_SLICK) || pm->ps->pm_flags & PMF_TIME_KNOCKBACK)
	{//We just ignore this with slick style since we area always slick, we dont need the flag to tell us that
		accelerate = pm_airaccelerate; //this should be changed for QW and other stuff, but whatever, already done
		if (moveStyle == MV_OCPM)
			accelerate = pm_cpm_accelerate;
		else
			accelerate = pm_airaccelerate; //this should be changed for QW and other stuff, but whatever, already done
	}
	else
	{
		accelerate = realaccelerate;
	}

	if (moveStyle == MV_TRIBES && pm->cmd.buttons & BUTTON_DASH) { //Truly a terrible way to do this but let us use the old way of accel because it lets us change direction as we expect at speed, but past a point don't let us gain any magnitute of speed from it, just the turns
		accelerate = 5.0f;
		PM_GroundAccelerateTribes(wishdir, wishspeed, accelerate);
		/*
		//I should reference PM_AirAccelerate here instead of PM_Accelerate maybe.
		float oldVel = VectorLength(pm->ps->velocity);
		PM_Accelerate(wishdir, wishspeed, accelerate);
		if (oldVel > (pm->ps->speed * 1.44f)) {
			float diff = oldVel / VectorLength(pm->ps->velocity);
			VectorScale(pm->ps->velocity, diff, pm->ps->velocity);
		}
		*/
	}
	else {
		PM_Accelerate(wishdir, wishspeed, accelerate);
	}

	if (moveStyle == MV_SURF) {
		pm->ps->velocity[2] -= pm->ps->gravity * 0.5 *pml.frametime;
	}

	/*
	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
#ifdef _GAME
		Com_Printf("^1S: %f, %f\n", wishspeed, pm->ps->speed);
#else
		Com_Printf("^2C: %f, %f\n", wishspeed, pm->ps->speed);
#endif
	}
	*/

	//Com_Printf("velocity = %1.1f %1.1f %1.1f\n", pm->ps->velocity[0], pm->ps->velocity[1], pm->ps->velocity[2]);
	//Com_Printf("velocity1 = %1.1f\n", VectorLength(pm->ps->velocity));

	if (((pml.groundTrace.surfaceFlags & SURF_SLICK) || (moveStyle == MV_SLICK) || (moveStyle == MV_TRIBES && ((pm->cmd.buttons & BUTTON_DASH) || (pm->ps->clientNum >= MAX_CLIENTS && pm->cmd.buttons & BUTTON_WALKING))) || pm->ps->pm_flags & PMF_TIME_KNOCKBACK)) { //AH!!!
#ifdef _GAME
		if ((g_fixSlidePhysics.integer == 1) && (pm->ps->clientNum >= MAX_CLIENTS)) { //Fix slide physics for NPCS (inbasejka, npcs will accel to ~340 on slick surfaces for no reason)
		}
		else if (g_fixSlidePhysics.integer > 1 && !pm->ps->stats[STAT_RACEMODE]) { //Fix Slide Physics for everything not in racemode
		}
		else
#endif
			if (pm->ps->stats[STAT_RACEMODE]) {
				float adjust = pml.frametime;
				if (adjust > 0.008f) {  //w/e
					adjust = 0.008f;
				}
				pm->ps->velocity[2] -= 800.0f * adjust;
			}
			else
				pm->ps->velocity[2] -= pm->ps->gravity * pml.frametime; //cap frametime here since its capped elsewhere? or uncap? or?
	}


	vel = VectorLength(pm->ps->velocity);

	// slide along the ground plane
	PM_ClipVelocity (pm->ps->velocity, pml.groundTrace.plane.normal,
		pm->ps->velocity, OVERCLIP );

	// don't decrease velocity when going up or down a slope
	VectorNormalize(pm->ps->velocity);
	VectorScale(pm->ps->velocity, vel, pm->ps->velocity);

	// don't do anything if standing still
	if (!pm->ps->velocity[0] && !pm->ps->velocity[1]) {
		return;
	}

	PM_StepSlideMove( qfalse );

	//Com_Printf("velocity2 = %1.1f\n", VectorLength(pm->ps->velocity));
}


/*
==============
PM_DeadMove
==============
*/
static void PM_DeadMove( void ) {
	float	forward;

	if ( !pml.walking ) {
		return;
	}

	// extra friction

	forward = VectorLength (pm->ps->velocity);
	forward -= 20;
	if ( forward <= 0 ) {
		VectorClear (pm->ps->velocity);
	} else {
		VectorNormalize (pm->ps->velocity);
		VectorScale (pm->ps->velocity, forward, pm->ps->velocity);
	}
}


/*
===============
PM_NoclipMove
===============
*/
static void PM_NoclipMove( void ) {
	float	speed, drop, friction, control, newspeed;
	int			i;
	vec3_t		wishvel;
	float		fmove, smove;
	vec3_t		wishdir;
	float		wishspeed;
	float		scale;

	pm->ps->viewheight = DEFAULT_VIEWHEIGHT;

	// friction

	speed = VectorLength (pm->ps->velocity);
	if (speed < 1)
	{
		VectorCopy (vec3_origin, pm->ps->velocity);
	}
	else
	{
		drop = 0;

		friction = pm_friction*1.5;	// extra friction
		control = speed < pm_stopspeed ? pm_stopspeed : speed;
		drop += control*friction*pml.frametime;

		// scale the velocity
		newspeed = speed - drop;
		if (newspeed < 0)
			newspeed = 0;
		newspeed /= speed;

		VectorScale (pm->ps->velocity, newspeed, pm->ps->velocity);
	}

	// accelerate
	scale = PM_CmdScale( &pm->cmd );
	if (pm->cmd.buttons & BUTTON_ATTACK) {	//turbo boost
		scale *= 10;
	}
	if (pm->cmd.buttons & BUTTON_ALT_ATTACK) {	//turbo boost
		scale *= 10;
	}

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;

	for (i=0 ; i<3 ; i++)
		wishvel[i] = pml.forward[i]*fmove + pml.right[i]*smove;
	wishvel[2] += pm->cmd.upmove;

	VectorCopy (wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);
	wishspeed *= scale;

	PM_Accelerate( wishdir, wishspeed, pm_accelerate );//dont care about CPM movement when in noclip so whatever

	// move
	VectorMA (pm->ps->origin, pml.frametime, pm->ps->velocity, pm->ps->origin);
}

//============================================================================

/*
================
PM_FootstepForSurface

Returns an event number appropriate for the groundsurface
================
*/
static int PM_FootstepForSurface( void )
{
	if ( pml.groundTrace.surfaceFlags & SURF_NOSTEPS )
	{
		return 0;
	}
	return ( pml.groundTrace.surfaceFlags & MATERIAL_MASK );
}

extern qboolean PM_CanRollFromSoulCal( playerState_t *ps );
static int PM_TryRoll( void )
{
	trace_t	trace;
	int		anim = -1;
	vec3_t fwd, right, traceto, mins, maxs, fwdAngles;
	const int moveStyle = PM_GetMovePhysics();

#ifdef _GAME
	    gclient_t *client = NULL;
		{
			int clientNum = pm->ps->clientNum;
			if (0 <= clientNum && clientNum < MAX_CLIENTS) {
				client = g_entities[clientNum].client;
			}
		}

		if (client && client->pers.noRoll)
#else
		if (cgs.serverMod == SVMOD_JAPRO && (cp_pluginDisable.integer & JAPRO_PLUGIN_NOROLL))
#endif
		{
			return 0;
		}

#ifdef _GAME
	if (!(g_tweakSaber.integer & ST_ALLOW_ROLLCANCEL) || pm->ps->stats[STAT_RACEMODE]) {
#else
	if (!(cgs.jcinfo & JAPRO_CINFO_ROLLCANCEL) || pm->ps->stats[STAT_RACEMODE]) {
#endif
		if ( BG_SaberInAttack( pm->ps->saberMove ) || BG_SaberInSpecialAttack( pm->ps->torsoAnim )
			|| BG_SpinningSaberAnim( pm->ps->legsAnim )
			|| PM_SaberInStart( pm->ps->saberMove ) )
		{//attacking or spinning (or, if player, starting an attack)
			if ( PM_CanRollFromSoulCal( pm->ps ) )
			{//hehe
			}
			else
			{
				return 0;
			}
		}
	}
	else {
		if ( BG_SaberInAttack( pm->ps->saberMove ) || BG_SaberInSpecialAttack( pm->ps->torsoAnim )
			|| BG_SpinningSaberAnim( pm->ps->legsAnim ))
		{//attacking or spinning (or, if player, starting an attack)
			return 0;
		}
	}

#ifdef _GAME
	if ((pm->ps->weapon != WP_SABER && pm->ps->weapon != WP_MELEE && (!(g_tweakWeapons.integer & WT_ALLOW_GUNROLL) || pm->ps->stats[STAT_RACEMODE]) && (pm->ps->weapon != WP_STUN_BATON || !pm->ps->stats[STAT_RACEMODE])) ||
#else
	if ((pm->ps->weapon != WP_SABER && pm->ps->weapon != WP_MELEE && (!(cgs.jcinfo & JAPRO_CINFO_GUNROLL) || pm->ps->stats[STAT_RACEMODE]) && (pm->ps->weapon != WP_STUN_BATON || !pm->ps->stats[STAT_RACEMODE])) ||
#endif
		PM_IsRocketTrooper() ||
		BG_HasYsalamiri(pm->gametype, pm->ps) ||
		(moveStyle == MV_CPM) ||
		(moveStyle == MV_OCPM) ||
		(moveStyle == MV_Q3) ||
		(moveStyle == MV_WSW) ||
		(moveStyle == MV_RJQ3) ||
		(moveStyle == MV_RJCPM) ||
		(moveStyle == MV_SLICK) ||
		(moveStyle == MV_BOTCPM) ||
		(moveStyle == MV_SURF) ||
		!BG_CanUseFPNow(pm->gametype, pm->ps, pm->cmd.serverTime, FP_LEVITATION))
	{ //Not using saber, or can't use jump
		return 0;
	}

	if ( pm->ps->weapon == WP_SABER )
	{
		saberInfo_t *saber = BG_MySaber( pm->ps->clientNum, 0 );
		if ( saber
			&& (saber->saberFlags&SFL_NO_ROLLS) )
		{
			return 0;
		}
		saber = BG_MySaber( pm->ps->clientNum, 1 );
		if ( saber
			&& (saber->saberFlags&SFL_NO_ROLLS) )
		{
			return 0;
		}
	}

	VectorSet(mins, pm->mins[0],pm->mins[1],pm->mins[2]+STEPSIZE);
	VectorSet(maxs, pm->maxs[0],pm->maxs[1],pm->ps->crouchheight);

	VectorSet(fwdAngles, 0, pm->ps->viewangles[YAW], 0);

	AngleVectors( fwdAngles, fwd, right, NULL );

	if ( pm->cmd.forwardmove )
	{ //check forward/backward rolls
		if ( pm->ps->pm_flags & PMF_BACKWARDS_RUN )
		{
			anim = BOTH_ROLL_B;
			VectorMA( pm->ps->origin, -64, fwd, traceto );
		}
		else
		{
			anim = BOTH_ROLL_F;
			VectorMA( pm->ps->origin, 64, fwd, traceto );
		}
	}
	else if ( pm->cmd.rightmove > 0 )
	{ //right
		anim = BOTH_ROLL_R;
		VectorMA( pm->ps->origin, 64, right, traceto );
	}
	else if ( pm->cmd.rightmove < 0 )
	{ //left
		anim = BOTH_ROLL_L;
		VectorMA( pm->ps->origin, -64, right, traceto );
	}

	if ( anim != -1 )
	{ //We want to roll. Perform a trace to see if we can, and if so, send us into one.
		pm->trace( &trace, pm->ps->origin, mins, maxs, traceto, pm->ps->clientNum, CONTENTS_SOLID );
		if ( trace.fraction >= 1.0f )
		{
			pm->ps->saberMove = LS_NONE;
			return anim;
		}
	}
	return 0;
}

#ifdef _GAME
static void PM_CrashLandEffect( void )
{
	float delta;
	if ( pm->waterlevel )
	{
		return;
	}
	delta = fabs(pml.previous_velocity[2])/10;//VectorLength( pml.previous_velocity );?
	if ( delta >= 30 )
	{
		vec3_t bottom;
		int	effectID = -1;
		int material = (pml.groundTrace.surfaceFlags&MATERIAL_MASK);
		VectorSet( bottom, pm->ps->origin[0],pm->ps->origin[1],pm->ps->origin[2]+pm->mins[2]+1 );
		switch ( material )
		{
		case MATERIAL_MUD:
			effectID = EFFECT_LANDING_MUD;
			break;
		case MATERIAL_SAND:
			effectID = EFFECT_LANDING_SAND;
			break;
		case MATERIAL_DIRT:
			effectID = EFFECT_LANDING_DIRT;
			break;
		case MATERIAL_SNOW:
			effectID = EFFECT_LANDING_SNOW;
			break;
		case MATERIAL_GRAVEL:
			effectID = EFFECT_LANDING_GRAVEL;
			break;
		}

		if ( effectID != -1 )
		{
			G_PlayEffect( effectID, bottom, pml.groundTrace.plane.normal );
		}
	}
}
#endif

/*
=================
PM_CrashLand

Check for hard landings that generate sound events
=================
*/
static void PM_CrashLand(void) {
	float		delta;
	float		dist;
	float		vel, acc;
	float		t;
	float		a, b, c, den;
	qboolean	didRoll = qfalse;
	const int moveStyle = PM_GetMovePhysics();

	//MV_TRIBES TWEAKS NEEDED

	// calculate the exact velocity on landing
	dist = pm->ps->origin[2] - pml.previous_origin[2];
	vel = pml.previous_velocity[2];
	acc = -pm->ps->gravity;

	a = acc / 2;
	b = vel;
	c = -dist;

	den = b * b - 4 * a * c;
	if (den < 0) {
		pm->ps->inAirAnim = qfalse;
		return;
	}
	t = (-b - sqrt(den)) / (2 * a);

	delta = vel + t * acc;
	delta = delta*delta * 0.0001;

#if _SPPHYSICS
	if (pm->ps->fd.forceJumpZStart && ((int)pm->ps->origin[2] >= (int)pm->ps->fd.forceJumpZStart) && moveStyle == MV_SP) {
		//trap->Print("cutting speed in half\n");
		pm->ps->velocity[0] *= 0.5f;
		pm->ps->velocity[1] *= 0.5f;
	}
#endif

#ifdef _GAME
	PM_CrashLandEffect();
#endif
	// ducking while falling doubles damage
	if (pm->ps->pm_flags & PMF_DUCKED) {
		delta *= 2;
	}

	if (pm->ps->legsAnim == BOTH_A7_KICK_F_AIR ||
		pm->ps->legsAnim == BOTH_A7_KICK_B_AIR ||
		pm->ps->legsAnim == BOTH_A7_KICK_R_AIR ||
		pm->ps->legsAnim == BOTH_A7_KICK_L_AIR)
	{
		int landAnim = -1;
		switch (pm->ps->legsAnim)
		{
		case BOTH_A7_KICK_F_AIR:
			landAnim = BOTH_FORCELAND1;
			break;
		case BOTH_A7_KICK_B_AIR:
			landAnim = BOTH_FORCELANDBACK1;
			break;
		case BOTH_A7_KICK_R_AIR:
			landAnim = BOTH_FORCELANDRIGHT1;
			break;
		case BOTH_A7_KICK_L_AIR:
			landAnim = BOTH_FORCELANDLEFT1;
			break;
		}
		if (landAnim != -1)
		{
			if (pm->ps->torsoAnim == pm->ps->legsAnim)
			{
				PM_SetAnim(SETANIM_BOTH, landAnim, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
			}
			else
			{
				PM_SetAnim(SETANIM_LEGS, landAnim, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
			}
		}
	}
	else if (pm->ps->legsAnim == BOTH_FORCEJUMPLEFT1 ||
		pm->ps->legsAnim == BOTH_FORCEJUMPRIGHT1 ||
		pm->ps->legsAnim == BOTH_FORCEJUMPBACK1 ||
		pm->ps->legsAnim == BOTH_FORCEJUMP1)
	{
		int fjAnim;
		switch (pm->ps->legsAnim)
		{
		case BOTH_FORCEJUMPLEFT1:
			fjAnim = BOTH_LANDLEFT1;
			break;
		case BOTH_FORCEJUMPRIGHT1:
			fjAnim = BOTH_LANDRIGHT1;
			break;
		case BOTH_FORCEJUMPBACK1:
			fjAnim = BOTH_LANDBACK1;
			break;
		default:
			fjAnim = BOTH_LAND1;
			break;
		}
		PM_SetAnim(SETANIM_BOTH, fjAnim, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
	}
	// decide which landing animation to use
	else if (!BG_InRoll(pm->ps, pm->ps->legsAnim) && pm->ps->inAirAnim && !pm->ps->m_iVehicleNum)
	{ //only play a land animation if we transitioned into an in-air animation while off the ground
		if (!BG_SaberInSpecial(pm->ps->saberMove))
		{
			if (pm->ps->pm_flags & PMF_BACKWARDS_JUMP) {
				PM_ForceLegsAnim(BOTH_LANDBACK1);
			}
			else {
				PM_ForceLegsAnim(BOTH_LAND1);
			}
		}
	}

	if (pm->ps->weapon != WP_SABER && pm->ps->weapon != WP_MELEE && !PM_IsRocketTrooper())
	{ //saber handles its own anims
		//This will push us back into our weaponready stance from the land anim.
		if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
		{
			PM_StartTorsoAnim(TORSO_WEAPONREADY4);
		}
		else
		{
			if (pm->ps->weapon == WP_EMPLACED_GUN)
			{
				PM_StartTorsoAnim(BOTH_GUNSIT1);
			}
			else
			{
				PM_StartTorsoAnim(WeaponReadyAnim[pm->ps->weapon]);
			}
		}
	}

	if (!BG_InSpecialJump(pm->ps->legsAnim) ||
		pm->ps->legsTimer < 1 ||
		(pm->ps->legsAnim) == BOTH_WALL_RUN_LEFT ||
		(pm->ps->legsAnim) == BOTH_WALL_RUN_RIGHT)
	{ //Only set the timer if we're in an anim that can be interrupted (this would not be, say, a flip)
		if (!BG_InRoll(pm->ps, pm->ps->legsAnim) && pm->ps->inAirAnim)
		{
			if (!BG_SaberInSpecial(pm->ps->saberMove) || pm->ps->weapon != WP_SABER)
			{
				if (pm->ps->legsAnim != BOTH_FORCELAND1			&&	pm->ps->legsAnim != BOTH_FORCELANDBACK1 &&
					pm->ps->legsAnim != BOTH_FORCELANDRIGHT1	&&	pm->ps->legsAnim != BOTH_FORCELANDLEFT1)
				{ //don't override if we have started a force land
					pm->ps->legsTimer = TIMER_LAND;
				}
			}
		}
	}

	pm->ps->inAirAnim = qfalse;

	if (pm->ps->m_iVehicleNum)
	{ //don't do fall stuff while on a vehicle
		return;
	}

	// never take falling damage if completely underwater
	if (pm->waterlevel == 3) {
		return;
	}

	// reduce falling damage if there is standing water
	if (pm->waterlevel == 2) {
		delta *= 0.25;
	}
	if (pm->waterlevel == 1) {
		delta *= 0.5;
	}

	if (delta < 1) {
		return;
	}

	if (pm->ps->pm_flags & PMF_DUCKED)
	{
		if (delta >= 2 && !PM_InOnGroundAnim(pm->ps->legsAnim) && !PM_InKnockDown(pm->ps) && !BG_InRoll(pm->ps, pm->ps->legsAnim) &&
			pm->ps->forceHandExtend == HANDEXTEND_NONE)
		{//roll!
			int anim = PM_TryRoll();

			if (PM_InRollComplete(pm->ps, pm->ps->legsAnim))
			{
				anim = 0;
				pm->ps->legsTimer = 0;
				pm->ps->legsAnim = 0;
				PM_SetAnim(SETANIM_BOTH, BOTH_LAND1, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
				pm->ps->legsTimer = TIMER_LAND;
			}

			if (anim)
			{//absorb some impact
				pm->ps->legsTimer = 0;
				delta /= 3; // /= 2 just cancels out the above delta *= 2 when landing while crouched, the roll itself should absorb a little damage
				pm->ps->legsAnim = 0;
				if (pm->ps->torsoAnim == BOTH_A7_SOULCAL)
				{ //get out of it on torso
					pm->ps->torsoTimer = 0;
				}
				PM_SetAnim(SETANIM_BOTH, anim, SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD);
				didRoll = qtrue;
			}
		}
	}

	// SURF_NODAMAGE is used for bounce pads where you don't ever
	// want to take damage or play a crunch sound
	if (!(pml.groundTrace.surfaceFlags & SURF_NODAMAGE)) {
		if (delta > 7)
		{
			int delta_send = (int)delta;

			if (delta_send > 600)
			{ //will never need to know any value above this
				delta_send = 600;
			}

			if (pm->ps->fd.forceJumpZStart)
			{
				if ((int)pm->ps->origin[2] >= (int)pm->ps->fd.forceJumpZStart)
				{ //was force jumping, landed on higher or same level as when force jump was started
					if (delta_send > 8)
					{
						delta_send = 8;
					}
				}
				else
				{
					if (delta_send > 8)
					{
						int dif = ((int)pm->ps->fd.forceJumpZStart - (int)pm->ps->origin[2]);
						int dmgLess = (forceJumpHeight[pm->ps->fd.forcePowerLevel[FP_LEVITATION]] - dif);

						if (dmgLess < 0)
						{
							dmgLess = 0;
						}

						delta_send -= (dmgLess*0.3);

						if (delta_send < 8)
						{
							delta_send = 8;
						}

						//Com_Printf("Damage sub: %i\n", (int)((dmgLess*0.1)));
					}
				}
			}

			if (didRoll)
			{ //Add the appropriate event..
				PM_AddEventWithParm(EV_ROLL, delta_send);
			}
			else
			{
				if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
					//just do no fall dmg in tribes cuz we do impact dmg elsewhere?
				}
				//else if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && ((pm->cmd.buttons & BUTTON_DASH) || (pm->ps->clientNum >= MAX_CLIENTS && (pm->cmd.buttons & BUTTON_WALKING)))) {
				//	if (delta_send > 150)
				//		PM_AddEventWithParm(EV_FALL, 1);
				//}
				else {
					PM_AddEventWithParm(EV_FALL, delta_send);
				}
			}
		}
		else
		{
			if (didRoll)
			{
				PM_AddEventWithParm(EV_ROLL, 0);
			}
			else
			{
				if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && ((pm->cmd.buttons & BUTTON_DASH) || (pm->ps->clientNum >= MAX_CLIENTS && (pm->cmd.buttons & BUTTON_WALKING)))) {
				}
				else {
					PM_AddEventWithParm(EV_FOOTSTEP, PM_FootstepForSurface());
				}
			}
		}
	}

	// make sure velocity resets so we don't bounce back up again in case we miss the clear elsewhere
	if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && ((pm->cmd.buttons & BUTTON_DASH))) {
	}
	else {
		pm->ps->velocity[2] = 0;
	}

	if ((moveStyle == MV_CPM || moveStyle == MV_OCPM || moveStyle == MV_Q3 || moveStyle == MV_RJQ3 || moveStyle == MV_RJCPM || moveStyle == MV_SLICK || moveStyle == MV_BOTCPM || moveStyle == MV_SURF) && ((int)pm->ps->fd.forceJumpZStart > pm->ps->origin[2] + 1)) {
		if (1 > (sqrt(pm->ps->velocity[0] * pm->ps->velocity[0] + pm->ps->velocity[1] * pm->ps->velocity[1])))//No xyvel
			pm->ps->velocity[2] = -vel; //OVERBOUNCE OVER BOUNCE
	}

	// start footstep cycle over
	pm->ps->bobCycle = 0;
}

/*
=============
PM_CorrectAllSolid
=============
*/
static int PM_CorrectAllSolid( trace_t *trace ) {
	int			i, j, k;
	vec3_t		point;

	if ( pm->debugLevel ) {
		Com_Printf("%i:allsolid\n", c_pmove);
	}

	// jitter around
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			for (k = -1; k <= 1; k++) {
				VectorCopy(pm->ps->origin, point);
				point[0] += (float) i;
				point[1] += (float) j;
				point[2] += (float) k;
				pm->trace (trace, point, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask);
				if ( !trace->allsolid ) {
					point[0] = pm->ps->origin[0];
					point[1] = pm->ps->origin[1];
					point[2] = pm->ps->origin[2] - 0.25;

					pm->trace (trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask);
					pml.groundTrace = *trace;
					return qtrue;
				}
			}
		}
	}

	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	pml.groundPlane = qfalse;
	pml.walking = qfalse;

	return qfalse;
}

/*
=============
PM_GroundTraceMissed

The ground trace didn't hit a surface, so we are in freefall
=============
*/
static void PM_GroundTraceMissed( void ) {
	trace_t		trace;
	vec3_t		point;

	//rww - don't want to do this when handextend_choke, because you can be standing on the ground
	//while still holding your throat.
	if ( pm->ps->pm_type == PM_FLOAT )
	{
		//we're assuming this is because you're being choked
		int parts = SETANIM_LEGS;

		//rww - also don't use SETANIM_FLAG_HOLD, it will cause the legs to float around a bit before going into
		//a proper anim even when on the ground.
		PM_SetAnim(parts, BOTH_CHOKE3, SETANIM_FLAG_OVERRIDE);
	}
	else if ( pm->ps->pm_type == PM_JETPACK )
	{//jetpacking
		//rww - also don't use SETANIM_FLAG_HOLD, it will cause the legs to float around a bit before going into
		//a proper anim even when on the ground.
		//PM_SetAnim(SETANIM_LEGS,BOTH_FORCEJUMP1,SETANIM_FLAG_OVERRIDE);
	}
	else if (BG_IsNewJetpacking(pm->ps)) //New Jetpack
	{//Jetpacking with new jetpack
		//NEWJETPACK2

		int jetpackanim = BOTH_FORCEINAIR1;
		if (pm->cmd.rightmove<0)
			jetpackanim = BOTH_FORCEJUMPLEFT1;// left
		if (pm->cmd.rightmove>0)
			jetpackanim = BOTH_FORCEJUMPRIGHT1;// right
		if (pm->cmd.forwardmove>0)
			jetpackanim = BOTH_FORCEJUMP1;// forwards
		if (pm->cmd.forwardmove<0)
			jetpackanim = BOTH_FORCEJUMPBACK1;// backwards
		PM_SetAnim(SETANIM_LEGS, jetpackanim, SETANIM_FLAG_OVERRIDE);
	}
	//If the anim is choke3, act like we just went into the air because we aren't in a float
	else if ( pm->ps->groundEntityNum != ENTITYNUM_NONE || (pm->ps->legsAnim) == BOTH_CHOKE3 )
	{
		// we just transitioned into freefall
		if ( pm->debugLevel ) {
			Com_Printf("%i:lift\n", c_pmove);
		}

		// if they aren't in a jumping animation and the ground is a ways away, force into it
		// if we didn't do the trace, the player would be backflipping down staircases
		VectorCopy( pm->ps->origin, point );
		point[2] -= 64;

		pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask);
		if ( trace.fraction == 1.0 || pm->ps->pm_type == PM_FLOAT ) {
			if ( pm->ps->velocity[2] <= 0 && !(pm->ps->pm_flags&PMF_JUMP_HELD))
			{
				//PM_SetAnim(SETANIM_LEGS,BOTH_INAIR1,SETANIM_FLAG_OVERRIDE);
				PM_SetAnim(SETANIM_LEGS,BOTH_INAIR1,0);
				pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
			}
			else if ( pm->cmd.forwardmove >= 0 )
			{
				PM_SetAnim(SETANIM_LEGS,BOTH_JUMP1,SETANIM_FLAG_OVERRIDE);
				pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
			}
			else
			{
				PM_SetAnim(SETANIM_LEGS,BOTH_JUMPBACK1,SETANIM_FLAG_OVERRIDE);
				pm->ps->pm_flags |= PMF_BACKWARDS_JUMP;
			}

			pm->ps->inAirAnim = qtrue;
		}
	}
	else if (!pm->ps->inAirAnim)
	{
		// if they aren't in a jumping animation and the ground is a ways away, force into it
		// if we didn't do the trace, the player would be backflipping down staircases
		VectorCopy( pm->ps->origin, point );
		point[2] -= 64;

		pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask);
		if ( trace.fraction == 1.0 || pm->ps->pm_type == PM_FLOAT )
		{
			pm->ps->inAirAnim = qtrue;
		}
	}

	if (PM_InRollComplete(pm->ps, pm->ps->legsAnim))
	{ //Client won't catch an animation restart because it only checks frame against incoming frame, so if you roll when you land after rolling
	  //off of something it won't replay the roll anim unless we switch it off in the air. This fixes that.
		PM_SetAnim(SETANIM_BOTH,BOTH_INAIR1,SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
		pm->ps->inAirAnim = qtrue;
	}

	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
}


/*
=============
PM_GroundTrace
=============
*/
static void PM_GroundTrace( void ) {
	vec3_t		point;
	trace_t		trace;
	float minNormal = (float)MIN_WALK_NORMAL;

	if ( pm->ps->clientNum >= MAX_CLIENTS)
	{
		bgEntity_t *pEnt = pm_entSelf;

		if (pEnt && pEnt->s.NPC_class == CLASS_VEHICLE)
		{
			minNormal = pEnt->m_pVehicle->m_pVehicleInfo->maxSlope;
			if (pm->ps->stats[STAT_RACEMODE]) {//Its a vehicle in racemode, RACESWOOP
				minNormal = 0.5f; //Max slope steepness before it stops hovoring you up, used to be 0.65
			}
		}
	}
	else if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
		minNormal = 0.5f; //Let us walk up a bit steeper hills in tribes?
	}

	point[0] = pm->ps->origin[0];
	point[1] = pm->ps->origin[1];
	point[2] = pm->ps->origin[2] - 0.25;

	pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask);
	pml.groundTrace = trace;

	// do something corrective if the trace starts in a solid...
	if ( trace.allsolid ) {
		if ( !PM_CorrectAllSolid(&trace) )
			return;
	}

	if (pm->ps->pm_type == PM_FLOAT || pm->ps->pm_type == PM_JETPACK)
	{
		PM_GroundTraceMissed();
		pml.groundPlane = qfalse;
		pml.walking = qfalse;
		return;
	}
	if (BG_IsNewJetpacking(pm->ps)) //New Jetpack
	{
		PM_GroundTraceMissed();
		pml.groundPlane = qfalse;
		pml.walking = qfalse;
		return;
	}

	// if the trace didn't hit anything, we are in free fall
	if ( trace.fraction == 1.0 ) {
		PM_GroundTraceMissed();
		pml.groundPlane = qfalse;
		pml.walking = qfalse;
		return;
	}

	// check if getting thrown off the ground
	//Don't do this for vehicles
	if ( (!pm_entSelf || pm_entSelf->s.NPC_class != CLASS_VEHICLE) && (pm->ps->velocity[2] > 0 && DotProduct( pm->ps->velocity, trace.plane.normal ) > 10 )) {
		if ( pm->debugLevel ) {
			Com_Printf("%i:kickoff\n", c_pmove);
		}
		// go into jump animation
		if ( pm->cmd.forwardmove >= 0 ) {
			PM_ForceLegsAnim( BOTH_JUMP1 );
			pm->ps->pm_flags &= ~PMF_BACKWARDS_JUMP;
		} else {
			PM_ForceLegsAnim( BOTH_JUMPBACK1 );
			pm->ps->pm_flags |= PMF_BACKWARDS_JUMP;
		}

		pm->ps->groundEntityNum = ENTITYNUM_NONE;
		pml.groundPlane = qfalse;
		pml.walking = qfalse;
		return;
	}

	// slopes that are too steep will not be considered onground
	if ( trace.plane.normal[2] < minNormal ) {
		if ( pm->debugLevel ) {
			Com_Printf("%i:steep\n", c_pmove);
		}
		pm->ps->groundEntityNum = ENTITYNUM_NONE;
		if (pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_SURF)
			pml.groundPlane = qtrue;
		pml.walking = qfalse;
		return;
	}

	pml.groundPlane = qtrue;
	pml.walking = qtrue;

	// hitting solid ground will end a waterjump
	if (pm->ps->pm_flags & PMF_TIME_WATERJUMP)
	{
		pm->ps->pm_flags &= ~(PMF_TIME_WATERJUMP | PMF_TIME_LAND);
		pm->ps->pm_time = 0;
	}

	if ( pm->ps->groundEntityNum == ENTITYNUM_NONE ) {
		// just hit the ground
		if ( pm->debugLevel ) {
			Com_Printf("%i:Land\n", c_pmove);
		}

		//trap->SendServerCommand( -1, va("cp \"Steep landed with z vel: %f\nnormal: %f, %f, %f\n\"", pm->ps->velocity[2], trace.plane.normal[0], trace.plane.normal[1], trace.plane.normal[2] ));
		//trap->SendServerCommand( -1, va("cp \"Previous Z Vel: %f\nCurrent Z Vel: %f\"", pml.previous_velocity[2], pm->ps->velocity[2]));

		//When we land, if our Z velocity is unusually low, its probably going to result in a nospeeded ramp
		//If we compare our previous z velocity to our current z velocity, if they are close very, it probably messed up somehow..
		//Since they should be very different since we just hit the ground.
		//So if they are very close, its probably a missed ramp somehow.. so redo the clipvelocity thing here :/
		//Ideally this could be debugged further back and fixed at the source of the problem..

		//Have a pmove var "clipped" , set it to qfalse at start of every frame.
		//When clipvelocity is called near "wsw rampjump", set clipped to qtrue.
		//Right here, if clipped is qfalse, do a clipvelocity ?
		//Seems like a better solution

		if (trace.plane.normal[0] != 0.0f || trace.plane.normal[1] != 0.0f || trace.plane.normal[2] != 1.0f) { //Its actually a ramp
			if (pm->ps->stats[STAT_RACEMODE] && !pml.clipped) {
				int moveStyle = PM_GetMovePhysics();
				if (moveStyle == MV_WSW || moveStyle == MV_SLICK) { //Only change our xy speed if we hit a downramp in wsw
					vec3_t oldVel, clipped_velocity, newVel;
					float oldSpeed, newSpeed;

					VectorCopy(pm->ps->velocity, oldVel);
					oldSpeed = oldVel[0] * oldVel[0] + oldVel[1] * oldVel[1];

					PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, clipped_velocity, OVERCLIP ); //WSW RAMPJUMP 1

					VectorCopy(clipped_velocity, newVel);
					newVel[2] = 0;
					newSpeed = newVel[0] * newVel[0] + newVel[1] * newVel[1];

					if (newSpeed > oldSpeed)
						VectorCopy(clipped_velocity, pm->ps->velocity);
				}
				else {
					PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP ); //Not sure why wsw is acting weird here.. so i guess no speed ramps will still be a thing in wsw style :/
				}
/*
#ifdef _GAME
				{
					int i;
					gentity_t *specEnt = (gentity_t *)pm_entSelf;

					trap->SendServerCommand( pm->ps->clientNum, "chat \"^0nospeed ramp fixed!\"");
					for (i=0; i<MAX_CLIENTS; i++) {//Also print to anyone spectating them..
						if (!g_entities[i].inuse)
							continue;
						if ((level.clients[i].sess.sessionTeam == TEAM_SPECTATOR) && (level.clients[i].ps.pm_flags & PMF_FOLLOW) && (level.clients[i].sess.spectatorClient == specEnt->client->ps.clientNum))
							trap->SendServerCommand(i, "chat \"^0nospeed ramp fixed!\"");
					}
				}
#endif
*/
			}

#if 0
			//if (pm->ps->stats[STAT_RACEMODE] && (pm->ps->stats[STAT_MOVEMENTSTYLE] != 6) && (pm->ps->velocity[2] > (pml.previous_velocity[2] * 1.05f)) && (pm->ps->velocity[2] < (pml.previous_velocity[2] / 1.05f))) {
				/*
#ifdef _GAME
				{
					int i;
					gentity_t *specEnt = (gentity_t *)pm_entSelf;

					trap->SendServerCommand( pm->ps->clientNum, "chat \"nospeed ramp corrected!\"");
					for (i=0; i<MAX_CLIENTS; i++) {//Also print to anyone spectating them..
						if (!g_entities[i].inuse)
							continue;
						if ((level.clients[i].sess.sessionTeam == TEAM_SPECTATOR) && (level.clients[i].ps.pm_flags & PMF_FOLLOW) && (level.clients[i].sess.spectatorClient == specEnt->client->ps.clientNum))
							trap->SendServerCommand(i, "chat \"nospeed ramp corrected!\"");
					}
				}
#endif
				*/
				//PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP ); //Not sure why wsw is acting weird here.. so i guess no speed ramps will still be a thing in wsw style :/
			//}
#endif
		}

		PM_CrashLand();

#ifdef _GAME
		if (pm->ps->clientNum < MAX_CLIENTS &&
			!pm->ps->m_iVehicleNum &&
			trace.entityNum < ENTITYNUM_WORLD &&
			trace.entityNum >= MAX_CLIENTS &&
			!pm->ps->zoomMode &&
			pm_entSelf)
		{ //check if we landed on a vehicle
			gentity_t *trEnt = &g_entities[trace.entityNum];
			if (trEnt->inuse && trEnt->client && trEnt->s.eType == ET_NPC && trEnt->s.NPC_class == CLASS_VEHICLE &&
				!trEnt->client->ps.m_iVehicleNum &&
				trEnt->m_pVehicle &&
				trEnt->m_pVehicle->m_pVehicleInfo->type != VH_WALKER &&
				trEnt->m_pVehicle->m_pVehicleInfo->type != VH_FIGHTER)
			{ //it's a vehicle alright, let's board it.. if it's not an atst or ship
				if (!BG_SaberInSpecial(pm->ps->saberMove) &&
					pm->ps->forceHandExtend == HANDEXTEND_NONE &&
					pm->ps->weaponTime <= 0)
				{
					gentity_t *servEnt = (gentity_t *)pm_entSelf;
					if (level.gametype < GT_TEAM ||
						!trEnt->alliedTeam ||
						(trEnt->alliedTeam == servEnt->client->sess.sessionTeam))
					{ //not belonging to a team, or client is on same team
						trEnt->m_pVehicle->m_pVehicleInfo->Board(trEnt->m_pVehicle, pm_entSelf);
					}
				}
			}
		}
#endif

		// don't do landing time if we were just going down a slope
		if ( pml.previous_velocity[2] < -200 ) {
			// don't allow another jump for a little while
			pm->ps->pm_flags |= PMF_TIME_LAND;
			pm->ps->pm_time = 250;
		}
	}

	pm->ps->groundEntityNum = trace.entityNum;
	pm->ps->lastOnGround = pm->cmd.serverTime;

	PM_AddTouchEnt( trace.entityNum );
}


/*
=============
PM_SetWaterLevel
=============
*/
static void PM_SetWaterLevel( void ) {
	vec3_t		point;
	int			cont;
	int			sample1;
	int			sample2;

	//
	// get waterlevel, accounting for ducking
	//
	pm->waterlevel = 0;
	pm->watertype = 0;

	point[0] = pm->ps->origin[0];
	point[1] = pm->ps->origin[1];
	point[2] = pm->ps->origin[2] + MINS_Z + 1;
	cont = pm->pointcontents( point, pm->ps->clientNum );

	if ( cont & MASK_WATER ) {
		sample2 = pm->ps->viewheight - MINS_Z;
		sample1 = sample2 / 2;

		pm->watertype = cont;
		pm->waterlevel = 1;
		point[2] = pm->ps->origin[2] + MINS_Z + sample1;
		cont = pm->pointcontents (point, pm->ps->clientNum );
		if ( cont & MASK_WATER ) {
			pm->waterlevel = 2;
			point[2] = pm->ps->origin[2] + MINS_Z + sample2;
			cont = pm->pointcontents (point, pm->ps->clientNum );
			if ( cont & MASK_WATER ){
				pm->waterlevel = 3;
			}
		}
	}

}

qboolean PM_CheckDualForwardJumpDuck( void )
{
	qboolean resized = qfalse;
	if ( pm->ps->legsAnim == BOTH_JUMPATTACK6 )
	{
		//dynamically reduce bounding box to let character sail over heads of enemies
		if ( ( pm->ps->legsTimer >= 1450
				&& PM_AnimLength( 0, BOTH_JUMPATTACK6 ) - pm->ps->legsTimer >= 400 )
			||(pm->ps->legsTimer >= 400
				&& PM_AnimLength( 0, BOTH_JUMPATTACK6 ) - pm->ps->legsTimer >= 1100 ) )
		{//in a part of the anim that we're pretty much sideways in, raise up the mins
			pm->mins[2] = 0;
			pm->ps->pm_flags |= PMF_FIX_MINS;
			resized = qtrue;
		}
	}
	return resized;
}

void PM_CheckFixMins( void )
{
	if ( (pm->ps->pm_flags&PMF_FIX_MINS) )// pm->mins[2] > DEFAULT_MINS_2 )
	{//drop the mins back down
		//do a trace to make sure it's okay
		trace_t	trace;
		vec3_t end, curMins, curMaxs;

		VectorSet( end, pm->ps->origin[0], pm->ps->origin[1], pm->ps->origin[2]+MINS_Z );
		VectorSet( curMins, pm->mins[0], pm->mins[1], 0 );
		VectorSet( curMaxs, pm->maxs[0], pm->maxs[1], pm->ps->standheight );

		pm->trace( &trace, pm->ps->origin, curMins, curMaxs, end, pm->ps->clientNum, pm->tracemask );
		if ( !trace.allsolid && !trace.startsolid )
		{//should never start in solid
			if ( trace.fraction >= 1.0f )
			{//all clear
				//drop the bottom of my bbox back down
				pm->mins[2] = MINS_Z;
				pm->ps->pm_flags &= ~PMF_FIX_MINS;
			}
			else
			{//move me up so the bottom of my bbox will be where the trace ended, at least
				//need to trace up, too
				float updist = ((1.0f-trace.fraction) * -MINS_Z);
				end[2] = pm->ps->origin[2]+updist;
				pm->trace( &trace, pm->ps->origin, curMins, curMaxs, end, pm->ps->clientNum, pm->tracemask );
				if ( !trace.allsolid && !trace.startsolid )
				{//should never start in solid
					if ( trace.fraction >= 1.0f )
					{//all clear
						//move me up
						pm->ps->origin[2] += updist;
						//drop the bottom of my bbox back down
						pm->mins[2] = MINS_Z;
						pm->ps->pm_flags &= ~PMF_FIX_MINS;
					}
					else
					{//crap, no room to expand, so just crouch us
						if ( pm->ps->legsAnim != BOTH_JUMPATTACK6
							|| pm->ps->legsTimer <= 200 )
						{//at the end of the anim, and we can't leave ourselves like this
							//so drop the maxs, put the mins back and move us up
							pm->maxs[2] += MINS_Z;
							pm->ps->origin[2] -= MINS_Z;
							pm->mins[2] = MINS_Z;
							//this way we'll be in a crouch when we're done
							if ( pm->ps->legsAnim == BOTH_JUMPATTACK6 )
							{
								pm->ps->legsTimer = pm->ps->torsoTimer = 0;
							}
							pm->ps->pm_flags |= PMF_DUCKED;
							//FIXME: do we need to set a crouch anim here?
							pm->ps->pm_flags &= ~PMF_FIX_MINS;
						}
					}
				}//crap, stuck
			}
		}//crap, stuck!
	}
}

static qboolean PM_CanStand ( void )
{
    qboolean canStand = qtrue;
    float x, y;
    trace_t trace;

    const vec3_t lineMins = { -5.0f, -5.0f, -2.5f };
    const vec3_t lineMaxs = { 5.0f, 5.0f, 0.0f };

    for ( x = pm->mins[0] + 5.0f; canStand && x <= (pm->maxs[0] - 5.0f); x += 10.0f )
    {
        for ( y = pm->mins[1] + 5.0f; y <= (pm->maxs[1] - 5.0f); y += 10.0f )
        {
			vec3_t start, end;//
			VectorSet( start, x, y, pm->maxs[2] );
			VectorSet( end, x, y, pm->ps->standheight );

			VectorAdd (start, pm->ps->origin, start);
			VectorAdd (end, pm->ps->origin, end);

			pm->trace (&trace, start, lineMins, lineMaxs, end, pm->ps->clientNum, pm->tracemask);
			if ( trace.allsolid || trace.fraction < 1.0f )
			{
				canStand = qfalse;
				break;
			}
		}
	}

    return canStand;
}

/*
==============
PM_CheckDuck

Sets mins, maxs, and pm->ps->viewheight
==============
*/
static void PM_CheckDuck (void)
{
//	trace_t	trace;
	int oldHeight;

	if ( pm->ps->m_iVehicleNum > 0 && pm->ps->m_iVehicleNum < ENTITYNUM_NONE )
	{//riding a vehicle or are a vehicle
		//no ducking or rolling when on a vehicle
		//right?  not even on ones that you just ride on top of?
		pm->ps->pm_flags &= ~PMF_DUCKED;
		pm->ps->pm_flags &= ~PMF_ROLLING;
		//NOTE: we don't clear the pm->cmd.upmove here because
		//the vehicle code may need it later... but, for riders,
		//it should have already been copied over to the vehicle, right?

		if (pm->ps->clientNum >= MAX_CLIENTS)
		{
			return;
		}
		if (pm_entVeh && pm_entVeh->m_pVehicle &&
			(pm_entVeh->m_pVehicle->m_pVehicleInfo->type == VH_SPEEDER ||
			 pm_entVeh->m_pVehicle->m_pVehicleInfo->type == VH_ANIMAL))
		{
			trace_t solidTr;

			pm->mins[0] = -16;
			pm->mins[1] = -16;
			pm->mins[2] = MINS_Z;

			pm->maxs[0] = 16;
			pm->maxs[1] = 16;
			pm->maxs[2] = pm->ps->standheight;//DEFAULT_MAXS_2;
			pm->ps->viewheight = DEFAULT_VIEWHEIGHT;

			pm->trace (&solidTr, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->m_iVehicleNum, pm->tracemask);
			if (solidTr.startsolid || solidTr.allsolid || solidTr.fraction != 1.0f)
			{ //whoops, can't fit here. Down to 0!
				VectorClear(pm->mins);
				VectorClear(pm->maxs);
#ifdef _GAME
				{
					gentity_t *me = &g_entities[pm->ps->clientNum];
					if (me->inuse && me->client)
					{ //yeah, this is a really terrible hack.
						me->client->solidHack = level.time + 200;
					}
				}
#endif
			}
		}
	}
	else
	{
		if (pm->ps->clientNum < MAX_CLIENTS)
		{
			if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
				if (pm->ps->standheight == (int)(DEFAULT_MAXS_2 * 1.25f)) {
					pm->mins[0] = (int)(-15 * 1.25f);
					pm->mins[1] = (int)(-15 * 1.25f);

					pm->maxs[0] = (int)(15 * 1.25f);
					pm->maxs[1] = (int)(15 * 1.25f);
				}
				else if (pm->ps->standheight == (int)(DEFAULT_MAXS_2 * 0.94f)) {
					pm->mins[0] = (int)(-15 * 0.94f);
					pm->mins[1] = (int)(-15 * 0.94f);

					pm->maxs[0] = (int)(15 * 0.94f);
					pm->maxs[1] = (int)(15 * 0.94f);
				}
				else {
					pm->mins[0] = -15;
					pm->mins[1] = -15;

					pm->maxs[0] = 15;
					pm->maxs[1] = 15;
				}
			}
			else {
				pm->mins[0] = -15;
				pm->mins[1] = -15;

				pm->maxs[0] = 15;
				pm->maxs[1] = 15;
			}
		}

		if ( PM_CheckDualForwardJumpDuck() )
		{//special anim resizing us
		}
		else
		{
			PM_CheckFixMins();

			if ( !pm->mins[2] )
			{
				pm->mins[2] = MINS_Z;
			}
		}

		if (pm->ps->pm_type == PM_DEAD && pm->ps->clientNum < MAX_CLIENTS)
		{
			pm->maxs[2] = -8;
			pm->ps->viewheight = DEAD_VIEWHEIGHT;
			return;
		}

		oldHeight = pm->maxs[2];

		if (BG_InRoll(pm->ps, pm->ps->legsAnim) && !BG_KickingAnim(pm->ps->legsAnim))
		{
			pm->maxs[2] = pm->ps->crouchheight; //CROUCH_MAXS_2;
			pm->ps->viewheight = DEFAULT_VIEWHEIGHT;
			pm->ps->pm_flags &= ~PMF_DUCKED;
			pm->ps->pm_flags |= PMF_ROLLING;
			return;
		}
		else if (pm->ps->pm_flags & PMF_ROLLING)
		{
			if ( PM_CanStand() ) {
				pm->maxs[2] = pm->ps->standheight;
				pm->ps->pm_flags &= ~PMF_ROLLING;
			}
		}
#ifdef _GAME
		else if ((pm->ps->pm_flags & PMF_ROLLING) && dmflags.integer & DF_NO_CROUCHFIX)
#else
		else if ((pm->ps->pm_flags & PMF_ROLLING) && cgs.dmflags & DF_NO_CROUCHFIX)
#endif
		{
			trace_t	trace;
			// try to stand up
			pm->maxs[2] = pm->ps->standheight;//DEFAULT_MAXS_2;
			pm->trace(&trace, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->clientNum, pm->tracemask);
			if (!trace.allsolid)
				pm->ps->pm_flags &= ~PMF_ROLLING;
		}
		else if (pm->cmd.upmove < 0 ||
			pm->ps->forceHandExtend == HANDEXTEND_KNOCKDOWN ||
			pm->ps->forceHandExtend == HANDEXTEND_PRETHROWN ||
			pm->ps->forceHandExtend == HANDEXTEND_POSTTHROWN)
		{	// duck

			//half-life/jasp crouch climb thing
			if (pm->ps->groundEntityNum == ENTITYNUM_NONE && ((pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_CROUCHJUMP) || pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_SP || pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_SURF)) {
				trace_t sptrace;
				pm->maxs[2] = pm->ps->crouchheight;
				pm->ps->viewheight = pm->ps->crouchheight + STANDARD_VIEWHEIGHT_OFFSET; //CROUCH_VIEWHEIGHT
				pm->trace(&sptrace, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->clientNum, pm->tracemask);
				if (!(pm->ps->pm_flags & PMF_DUCKED) && !sptrace.allsolid && pm->ps->velocity[2] >= 0) {
					pm->ps->eFlags ^= EF_TELEPORT_BIT;
					//pm->ps->origin[2] += oldHeight - pm->maxs[2];
					pm->ps->origin[2] -= oldHeight - pm->maxs[2];
#ifdef _CGAME
					cg.predictedPlayerState.origin[2] += oldHeight - pm->maxs[2];
#endif
				}

			}

			pm->ps->pm_flags |= PMF_DUCKED;
		}
		else
		{	// stand up if possible
			if (pm->ps->pm_flags & PMF_DUCKED)
			{
				if ((pm->ps->stats[STAT_RESTRICTIONS] & JAPRO_RESTRICT_CROUCHJUMP) || pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_SP || pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_SURF) {
					trace_t sptrace;
					if (pm->ps->groundEntityNum == ENTITYNUM_NONE && PM_GroundDistance() >= (oldHeight - pm->maxs[2]) && pm->ps->velocity[2] >= 0) {
						pm->maxs[2] = pm->ps->standheight;
						pm->ps->origin[2] += oldHeight - pm->maxs[2];
						pm->trace(&sptrace, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->clientNum, pm->tracemask);
						if (!sptrace.allsolid) {
							pm->ps->eFlags ^= EF_TELEPORT_BIT;
							pm->ps->pm_flags &= ~PMF_DUCKED;
						}
						else {
							pm->ps->origin[2] -= oldHeight - pm->maxs[2]; //undo it so we don't clip thru the floor
						}
					}
					else {
						pm->maxs[2] = pm->ps->standheight;
						pm->trace(&sptrace, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->clientNum, pm->tracemask);
						if (!sptrace.allsolid) {
							pm->ps->pm_flags &= ~PMF_DUCKED;
						}
					}
				}
				else if ( PM_CanStand() ) {
					pm->maxs[2] = pm->ps->standheight;
					pm->ps->pm_flags &= ~PMF_DUCKED;
				}
#ifdef _GAME
				else if ((pm->ps->pm_flags & PMF_DUCKED) && dmflags.integer & DF_NO_CROUCHFIX)
#else
				else if ((pm->ps->pm_flags & PMF_DUCKED) && cgs.dmflags & DF_NO_CROUCHFIX)
#endif
				{
					trace_t	trace;
					// try to stand up
					pm->maxs[2] = pm->ps->standheight;//DEFAULT_MAXS_2;
					pm->trace(&trace, pm->ps->origin, pm->mins, pm->maxs, pm->ps->origin, pm->ps->clientNum, pm->tracemask);
					if (!trace.allsolid)
						pm->ps->pm_flags &= ~PMF_DUCKED;
				}
			}
		}
	}

	if (pm->ps->pm_flags & PMF_DUCKED)
	{
		pm->maxs[2] = pm->ps->crouchheight;//CROUCH_MAXS_2;
		pm->ps->viewheight = CROUCH_VIEWHEIGHT;
	}
	else if (pm->ps->pm_flags & PMF_ROLLING)
	{
		pm->maxs[2] = pm->ps->crouchheight;//CROUCH_MAXS_2;
		pm->ps->viewheight = DEFAULT_VIEWHEIGHT;
	}
	else
	{
		pm->maxs[2] = pm->ps->standheight;//DEFAULT_MAXS_2;
		pm->ps->viewheight = DEFAULT_VIEWHEIGHT;
	}
}



//===================================================================



/*
==============
PM_Use

Generates a use event
==============
*/
#define USE_DELAY 2000

void PM_Use( void )
{
	if ( pm->ps->useTime > 0 )
		pm->ps->useTime -= 100;//pm->cmd.msec;

	if ( pm->ps->useTime > 0 ) {
		return;
	}

	if ( ! (pm->cmd.buttons & BUTTON_USE ) )
	{
		pm->useEvent = 0;
		pm->ps->useTime = 0;
		return;
	}

	pm->useEvent = EV_USE;
	pm->ps->useTime = USE_DELAY;
}

qboolean PM_WalkingAnim( int anim )
{
	switch ( anim )
	{
	case BOTH_WALK1:				//# Normal walk
	case BOTH_WALK2:				//# Normal walk with saber
	case BOTH_WALK_STAFF:			//# Normal walk with staff
	case BOTH_WALK_DUAL:			//# Normal walk with staff
	case BOTH_WALK5:				//# Tavion taunting Kyle (cin 22)
	case BOTH_WALK6:				//# Slow walk for Luke (cin 12)
	case BOTH_WALK7:				//# Fast walk
	case BOTH_WALKBACK1:			//# Walk1 backwards
	case BOTH_WALKBACK2:			//# Walk2 backwards
	case BOTH_WALKBACK_STAFF:		//# Walk backwards with staff
	case BOTH_WALKBACK_DUAL:		//# Walk backwards with dual
		return qtrue;
		break;
	}
	return qfalse;
}
qboolean PM_RunningAnim( int anim )
{
	switch ( (anim) )
	{
	case BOTH_RUN1:
	case BOTH_RUN2:
	case BOTH_RUN_STAFF:
	case BOTH_RUN_DUAL:
	case BOTH_RUNBACK1:
	case BOTH_RUNBACK2:
	case BOTH_RUNBACK_STAFF:
	case BOTH_RUNBACK_DUAL:
	case BOTH_RUN1START:			//# Start into full run1
	case BOTH_RUN1STOP:			//# Stop from full run1
	case BOTH_RUNSTRAFE_LEFT1:	//# Sidestep left: should loop
	case BOTH_RUNSTRAFE_RIGHT1:	//# Sidestep right: should loop
		return qtrue;
	case BOTH_RUN4:
#ifdef _GAME
		return qtrue;
#else
		if (cgs.serverMod == SVMOD_JAPRO)
			return qtrue;
#endif
		break;
	}
	return qfalse;
}

qboolean PM_SwimmingAnim( int anim )
{
	switch ( anim )
	{
	case BOTH_SWIM_IDLE1:		//# Swimming Idle 1
	case BOTH_SWIMFORWARD:		//# Swim forward loop
	case BOTH_SWIMBACKWARD:		//# Swim backward loop
		return qtrue;
		break;
	}
	return qfalse;
}

qboolean PM_RollingAnim( int anim )
{
	switch ( anim )
	{
	case BOTH_ROLL_F:			//# Roll forward
	case BOTH_ROLL_B:			//# Roll backward
	case BOTH_ROLL_L:			//# Roll left
	case BOTH_ROLL_R:			//# Roll right
		return qtrue;
		break;
	}
	return qfalse;
}

void PM_AnglesForSlope( const float yaw, const vec3_t slope, vec3_t angles )
{
	vec3_t	nvf, ovf, ovr, new_angles;
	float	pitch, mod, dot;

	VectorSet( angles, 0, yaw, 0 );
	AngleVectors( angles, ovf, ovr, NULL );

	vectoangles( slope, new_angles );
	pitch = new_angles[PITCH] + 90;
	new_angles[ROLL] = new_angles[PITCH] = 0;

	AngleVectors( new_angles, nvf, NULL, NULL );

	mod = DotProduct( nvf, ovr );

	if ( mod < 0 )
		mod = -1;
	else
		mod = 1;

	dot = DotProduct( nvf, ovf );

	angles[YAW] = 0;
	angles[PITCH] = dot * pitch;
	angles[ROLL] = ((1-Q_fabs(dot)) * pitch * mod);
}

void PM_FootSlopeTrace( float *pDiff, float *pInterval )
{
	vec3_t	footLOrg, footROrg, footLBot, footRBot;
	vec3_t footLPoint, footRPoint;
	vec3_t footMins, footMaxs;
	vec3_t footLSlope, footRSlope;

	trace_t	trace;
	float	diff, interval;

	mdxaBone_t	boltMatrix;
	vec3_t		G2Angles;

	VectorSet(G2Angles, 0, pm->ps->viewangles[YAW], 0);

	interval = 4;//?

	trap->G2API_GetBoltMatrix( pm->ghoul2, 0, pm->g2Bolts_LFoot, &boltMatrix, G2Angles, pm->ps->origin, pm->cmd.serverTime, NULL, pm->modelScale );
	footLPoint[0] = boltMatrix.matrix[0][3];
	footLPoint[1] = boltMatrix.matrix[1][3];
	footLPoint[2] = boltMatrix.matrix[2][3];

	trap->G2API_GetBoltMatrix( pm->ghoul2, 0, pm->g2Bolts_RFoot, &boltMatrix, G2Angles, pm->ps->origin, pm->cmd.serverTime, NULL, pm->modelScale );
	footRPoint[0] = boltMatrix.matrix[0][3];
	footRPoint[1] = boltMatrix.matrix[1][3];
	footRPoint[2] = boltMatrix.matrix[2][3];

	//get these on the cgame and store it, save ourselves a ghoul2 construct skel call
	VectorCopy( footLPoint, footLOrg );
	VectorCopy( footRPoint, footROrg );

	//step 2: adjust foot tag z height to bottom of bbox+1
	footLOrg[2] = pm->ps->origin[2] + pm->mins[2] + 1;
	footROrg[2] = pm->ps->origin[2] + pm->mins[2] + 1;
	VectorSet( footLBot, footLOrg[0], footLOrg[1], footLOrg[2] - interval*10 );
	VectorSet( footRBot, footROrg[0], footROrg[1], footROrg[2] - interval*10 );

	//step 3: trace down from each, find difference
	VectorSet( footMins, -3, -3, 0 );
	VectorSet( footMaxs, 3, 3, 1 );

	pm->trace( &trace, footLOrg, footMins, footMaxs, footLBot, pm->ps->clientNum, pm->tracemask );
	VectorCopy( trace.endpos, footLBot );
	VectorCopy( trace.plane.normal, footLSlope );

	pm->trace( &trace, footROrg, footMins, footMaxs, footRBot, pm->ps->clientNum, pm->tracemask );
	VectorCopy( trace.endpos, footRBot );
	VectorCopy( trace.plane.normal, footRSlope );

	diff = footLBot[2] - footRBot[2];

	if ( pDiff != NULL )
	{
		*pDiff = diff;
	}
	if ( pInterval != NULL )
	{
		*pInterval = interval;
	}
}

qboolean BG_InSlopeAnim( int anim )
{
	switch ( anim )
	{
	case LEGS_LEFTUP1:			//# On a slope with left foot 4 higher than right
	case LEGS_LEFTUP2:			//# On a slope with left foot 8 higher than right
	case LEGS_LEFTUP3:			//# On a slope with left foot 12 higher than right
	case LEGS_LEFTUP4:			//# On a slope with left foot 16 higher than right
	case LEGS_LEFTUP5:			//# On a slope with left foot 20 higher than right
	case LEGS_RIGHTUP1:			//# On a slope with RIGHT foot 4 higher than left
	case LEGS_RIGHTUP2:			//# On a slope with RIGHT foot 8 higher than left
	case LEGS_RIGHTUP3:			//# On a slope with RIGHT foot 12 higher than left
	case LEGS_RIGHTUP4:			//# On a slope with RIGHT foot 16 higher than left
	case LEGS_RIGHTUP5:			//# On a slope with RIGHT foot 20 higher than left
	case LEGS_S1_LUP1:
	case LEGS_S1_LUP2:
	case LEGS_S1_LUP3:
	case LEGS_S1_LUP4:
	case LEGS_S1_LUP5:
	case LEGS_S1_RUP1:
	case LEGS_S1_RUP2:
	case LEGS_S1_RUP3:
	case LEGS_S1_RUP4:
	case LEGS_S1_RUP5:
	case LEGS_S3_LUP1:
	case LEGS_S3_LUP2:
	case LEGS_S3_LUP3:
	case LEGS_S3_LUP4:
	case LEGS_S3_LUP5:
	case LEGS_S3_RUP1:
	case LEGS_S3_RUP2:
	case LEGS_S3_RUP3:
	case LEGS_S3_RUP4:
	case LEGS_S3_RUP5:
	case LEGS_S4_LUP1:
	case LEGS_S4_LUP2:
	case LEGS_S4_LUP3:
	case LEGS_S4_LUP4:
	case LEGS_S4_LUP5:
	case LEGS_S4_RUP1:
	case LEGS_S4_RUP2:
	case LEGS_S4_RUP3:
	case LEGS_S4_RUP4:
	case LEGS_S4_RUP5:
	case LEGS_S5_LUP1:
	case LEGS_S5_LUP2:
	case LEGS_S5_LUP3:
	case LEGS_S5_LUP4:
	case LEGS_S5_LUP5:
	case LEGS_S5_RUP1:
	case LEGS_S5_RUP2:
	case LEGS_S5_RUP3:
	case LEGS_S5_RUP4:
	case LEGS_S5_RUP5:
		return qtrue;
		break;
	}
	return qfalse;
}

#define	SLOPE_RECALC_INT 100
qboolean PM_AdjustStandAnimForSlope( void )
{
	float	diff;
	float	interval;
	int		destAnim;
	int		legsAnim;
	#define SLOPERECALCVAR pm->ps->slopeRecalcTime //this is purely convenience

#ifdef _GAME
	int clientNum = pm->ps->clientNum;
	gclient_t *client = NULL;

	if (0 <= clientNum && clientNum < MAX_CLIENTS) {
		client = g_entities[clientNum].client;
	}

	if (client && client->pers.isJAPRO && (client->sess.raceMode || !g_LegDangle.integer))
		return qfalse;
#else
	if (cgs.serverMod == SVMOD_JAPRO && (pm->ps->stats[STAT_RACEMODE] || (cgs.jcinfo & JAPRO_CINFO_NOLEGDANGLE))) // Loda fixme, maybe give clients option to choose? idk why they would want to..
		return qfalse;
#endif

	if (!pm->ghoul2)
	{ //probably just changed models and not quite in sync yet
		return qfalse;
	}

	if ( pm->g2Bolts_LFoot == -1 || pm->g2Bolts_RFoot == -1 )
	{//need these bolts!
		return qfalse;
	}

	//step 1: find the 2 foot tags
	PM_FootSlopeTrace( &diff, &interval );

	//step 4: based on difference, choose one of the left/right slope-match intervals
	if ( diff >= interval*5 )
	{
		destAnim = LEGS_LEFTUP5;
	}
	else if ( diff >= interval*4 )
	{
		destAnim = LEGS_LEFTUP4;
	}
	else if ( diff >= interval*3 )
	{
		destAnim = LEGS_LEFTUP3;
	}
	else if ( diff >= interval*2 )
	{
		destAnim = LEGS_LEFTUP2;
	}
	else if ( diff >= interval )
	{
		destAnim = LEGS_LEFTUP1;
	}
	else if ( diff <= interval*-5 )
	{
		destAnim = LEGS_RIGHTUP5;
	}
	else if ( diff <= interval*-4 )
	{
		destAnim = LEGS_RIGHTUP4;
	}
	else if ( diff <= interval*-3 )
	{
		destAnim = LEGS_RIGHTUP3;
	}
	else if ( diff <= interval*-2 )
	{
		destAnim = LEGS_RIGHTUP2;
	}
	else if ( diff <= interval*-1 )
	{
		destAnim = LEGS_RIGHTUP1;
	}
	else
	{
		return qfalse;
	}

	legsAnim = pm->ps->legsAnim;
	//adjust for current legs anim
	switch ( legsAnim )
	{
	case BOTH_STAND1:

	case LEGS_S1_LUP1:
	case LEGS_S1_LUP2:
	case LEGS_S1_LUP3:
	case LEGS_S1_LUP4:
	case LEGS_S1_LUP5:
	case LEGS_S1_RUP1:
	case LEGS_S1_RUP2:
	case LEGS_S1_RUP3:
	case LEGS_S1_RUP4:
	case LEGS_S1_RUP5:
		destAnim = LEGS_S1_LUP1 + (destAnim-LEGS_LEFTUP1);
		break;
	case BOTH_STAND2:
	case BOTH_SABERFAST_STANCE:
	case BOTH_SABERSLOW_STANCE:
	case BOTH_CROUCH1IDLE:
	case BOTH_CROUCH1:
	case LEGS_LEFTUP1:			//# On a slope with left foot 4 higher than right
	case LEGS_LEFTUP2:			//# On a slope with left foot 8 higher than right
	case LEGS_LEFTUP3:			//# On a slope with left foot 12 higher than right
	case LEGS_LEFTUP4:			//# On a slope with left foot 16 higher than right
	case LEGS_LEFTUP5:			//# On a slope with left foot 20 higher than right
	case LEGS_RIGHTUP1:			//# On a slope with RIGHT foot 4 higher than left
	case LEGS_RIGHTUP2:			//# On a slope with RIGHT foot 8 higher than left
	case LEGS_RIGHTUP3:			//# On a slope with RIGHT foot 12 higher than left
	case LEGS_RIGHTUP4:			//# On a slope with RIGHT foot 16 higher than left
	case LEGS_RIGHTUP5:			//# On a slope with RIGHT foot 20 higher than left
		//fine
		break;
	case BOTH_STAND3:
	case LEGS_S3_LUP1:
	case LEGS_S3_LUP2:
	case LEGS_S3_LUP3:
	case LEGS_S3_LUP4:
	case LEGS_S3_LUP5:
	case LEGS_S3_RUP1:
	case LEGS_S3_RUP2:
	case LEGS_S3_RUP3:
	case LEGS_S3_RUP4:
	case LEGS_S3_RUP5:
		destAnim = LEGS_S3_LUP1 + (destAnim-LEGS_LEFTUP1);
		break;
	case BOTH_STAND4:
	case LEGS_S4_LUP1:
	case LEGS_S4_LUP2:
	case LEGS_S4_LUP3:
	case LEGS_S4_LUP4:
	case LEGS_S4_LUP5:
	case LEGS_S4_RUP1:
	case LEGS_S4_RUP2:
	case LEGS_S4_RUP3:
	case LEGS_S4_RUP4:
	case LEGS_S4_RUP5:
		destAnim = LEGS_S4_LUP1 + (destAnim-LEGS_LEFTUP1);
		break;
	case BOTH_STAND5:
	case LEGS_S5_LUP1:
	case LEGS_S5_LUP2:
	case LEGS_S5_LUP3:
	case LEGS_S5_LUP4:
	case LEGS_S5_LUP5:
	case LEGS_S5_RUP1:
	case LEGS_S5_RUP2:
	case LEGS_S5_RUP3:
	case LEGS_S5_RUP4:
	case LEGS_S5_RUP5:
		destAnim = LEGS_S5_LUP1 + (destAnim-LEGS_LEFTUP1);
		break;
	case BOTH_STAND6:
	default:
		return qfalse;
		break;
	}

	//step 5: based on the chosen interval and the current legsAnim, pick the correct anim
	//step 6: increment/decrement to the dest anim, not instant
	if ( (legsAnim >= LEGS_LEFTUP1 && legsAnim <= LEGS_LEFTUP5)
		|| (legsAnim >= LEGS_S1_LUP1 && legsAnim <= LEGS_S1_LUP5)
		|| (legsAnim >= LEGS_S3_LUP1 && legsAnim <= LEGS_S3_LUP5)
		|| (legsAnim >= LEGS_S4_LUP1 && legsAnim <= LEGS_S4_LUP5)
		|| (legsAnim >= LEGS_S5_LUP1 && legsAnim <= LEGS_S5_LUP5) )
	{//already in left-side up
		if ( destAnim > legsAnim && SLOPERECALCVAR < pm->cmd.serverTime )
		{
			legsAnim++;
			SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
		}
		else if ( destAnim < legsAnim && SLOPERECALCVAR < pm->cmd.serverTime )
		{
			legsAnim--;
			SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
		}
		else //if (SLOPERECALCVAR < pm->cmd.serverTime)
		{
			legsAnim = destAnim;
		}

		destAnim = legsAnim;
	}
	else if ( (legsAnim >= LEGS_RIGHTUP1 && legsAnim <= LEGS_RIGHTUP5)
		|| (legsAnim >= LEGS_S1_RUP1 && legsAnim <= LEGS_S1_RUP5)
		|| (legsAnim >= LEGS_S3_RUP1 && legsAnim <= LEGS_S3_RUP5)
		|| (legsAnim >= LEGS_S4_RUP1 && legsAnim <= LEGS_S4_RUP5)
		|| (legsAnim >= LEGS_S5_RUP1 && legsAnim <= LEGS_S5_RUP5) )
	{//already in right-side up
		if ( destAnim > legsAnim && SLOPERECALCVAR < pm->cmd.serverTime )
		{
			legsAnim++;
			SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
		}
		else if ( destAnim < legsAnim && SLOPERECALCVAR < pm->cmd.serverTime )
		{
			legsAnim--;
			SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
		}
		else //if (SLOPERECALCVAR < pm->cmd.serverTime)
		{
			legsAnim = destAnim;
		}

		destAnim = legsAnim;
	}
	else
	{//in a stand of some sort?
		switch ( legsAnim )
		{
		case BOTH_STAND1:
		case TORSO_WEAPONREADY1:
		case TORSO_WEAPONREADY2:
		case TORSO_WEAPONREADY3:
		case TORSO_WEAPONREADY10:

			if ( destAnim >= LEGS_S1_LUP1 && destAnim <= LEGS_S1_LUP5 )
			{//going into left side up
				destAnim = LEGS_S1_LUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else if ( destAnim >= LEGS_S1_RUP1 && destAnim <= LEGS_S1_RUP5 )
			{//going into right side up
				destAnim = LEGS_S1_RUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else
			{//will never get here
				return qfalse;
			}
			break;
		case BOTH_STAND2:
		case BOTH_SABERFAST_STANCE:
		case BOTH_SABERSLOW_STANCE:
		case BOTH_CROUCH1IDLE:
			if ( destAnim >= LEGS_LEFTUP1 && destAnim <= LEGS_LEFTUP5 )
			{//going into left side up
				destAnim = LEGS_LEFTUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else if ( destAnim >= LEGS_RIGHTUP1 && destAnim <= LEGS_RIGHTUP5 )
			{//going into right side up
				destAnim = LEGS_RIGHTUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else
			{//will never get here
				return qfalse;
			}
			break;
		case BOTH_STAND3:
			if ( destAnim >= LEGS_S3_LUP1 && destAnim <= LEGS_S3_LUP5 )
			{//going into left side up
				destAnim = LEGS_S3_LUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else if ( destAnim >= LEGS_S3_RUP1 && destAnim <= LEGS_S3_RUP5 )
			{//going into right side up
				destAnim = LEGS_S3_RUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else
			{//will never get here
				return qfalse;
			}
			break;
		case BOTH_STAND4:
			if ( destAnim >= LEGS_S4_LUP1 && destAnim <= LEGS_S4_LUP5 )
			{//going into left side up
				destAnim = LEGS_S4_LUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else if ( destAnim >= LEGS_S4_RUP1 && destAnim <= LEGS_S4_RUP5 )
			{//going into right side up
				destAnim = LEGS_S4_RUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else
			{//will never get here
				return qfalse;
			}
			break;
		case BOTH_STAND5:
			if ( destAnim >= LEGS_S5_LUP1 && destAnim <= LEGS_S5_LUP5 )
			{//going into left side up
				destAnim = LEGS_S5_LUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else if ( destAnim >= LEGS_S5_RUP1 && destAnim <= LEGS_S5_RUP5 )
			{//going into right side up
				destAnim = LEGS_S5_RUP1;
				SLOPERECALCVAR = pm->cmd.serverTime + SLOPE_RECALC_INT;
			}
			else
			{//will never get here
				return qfalse;
			}
			break;
		case BOTH_STAND6:
		default:
			return qfalse;
			break;
		}
	}
	//step 7: set the anim
	//PM_SetAnim( SETANIM_LEGS, destAnim, SETANIM_FLAG_NORMAL );
	PM_ContinueLegsAnim(destAnim);

	return qtrue;
}

extern int WeaponReadyLegsAnim[WP_NUM_WEAPONS];

//rww - slowly back out of slope leg anims, to prevent skipping between slope anims and general jittering
int PM_LegsSlopeBackTransition(int desiredAnim)
{
	int anim = pm->ps->legsAnim;
	int resultingAnim = desiredAnim;

	switch ( anim )
	{
	case LEGS_LEFTUP2:			//# On a slope with left foot 8 higher than right
	case LEGS_LEFTUP3:			//# On a slope with left foot 12 higher than right
	case LEGS_LEFTUP4:			//# On a slope with left foot 16 higher than right
	case LEGS_LEFTUP5:			//# On a slope with left foot 20 higher than right
	case LEGS_RIGHTUP2:			//# On a slope with RIGHT foot 8 higher than left
	case LEGS_RIGHTUP3:			//# On a slope with RIGHT foot 12 higher than left
	case LEGS_RIGHTUP4:			//# On a slope with RIGHT foot 16 higher than left
	case LEGS_RIGHTUP5:			//# On a slope with RIGHT foot 20 higher than left
	case LEGS_S1_LUP2:
	case LEGS_S1_LUP3:
	case LEGS_S1_LUP4:
	case LEGS_S1_LUP5:
	case LEGS_S1_RUP2:
	case LEGS_S1_RUP3:
	case LEGS_S1_RUP4:
	case LEGS_S1_RUP5:
	case LEGS_S3_LUP2:
	case LEGS_S3_LUP3:
	case LEGS_S3_LUP4:
	case LEGS_S3_LUP5:
	case LEGS_S3_RUP2:
	case LEGS_S3_RUP3:
	case LEGS_S3_RUP4:
	case LEGS_S3_RUP5:
	case LEGS_S4_LUP2:
	case LEGS_S4_LUP3:
	case LEGS_S4_LUP4:
	case LEGS_S4_LUP5:
	case LEGS_S4_RUP2:
	case LEGS_S4_RUP3:
	case LEGS_S4_RUP4:
	case LEGS_S4_RUP5:
	case LEGS_S5_LUP2:
	case LEGS_S5_LUP3:
	case LEGS_S5_LUP4:
	case LEGS_S5_LUP5:
	case LEGS_S5_RUP2:
	case LEGS_S5_RUP3:
	case LEGS_S5_RUP4:
	case LEGS_S5_RUP5:
		if (pm->ps->slopeRecalcTime < pm->cmd.serverTime)
		{
			resultingAnim = anim-1;
			pm->ps->slopeRecalcTime = pm->cmd.serverTime + 8;//SLOPE_RECALC_INT;
		}
		else
		{
			resultingAnim = anim;
		}
#ifdef _GAME
		if (pm->ps->groundEntityNum != ENTITYNUM_WORLD && g_slideOnPlayer.integer)
#elif _CGAME
		if (cg_legstuck.integer)
#endif
			VectorClear(pm->ps->velocity);
		break;
	}

	return resultingAnim;
}

static qboolean BG_AreRunWalkAnimsFixed(void) {
#if defined(_GAME)
	return !!g_fixRunWalkAnims.integer;
#elif defined(_CGAME)
	const char *cs = CG_ConfigString(CS_LEGACY_FIXES);
	const uint32_t legacyFixes = strtoul(cs, NULL, 0);
	return !!(legacyFixes & (1 << LEGACYFIX_RUNWALKANIMS));
#endif
}

/*
===============
PM_Footsteps
===============
*/
static void PM_Footsteps( void ) {
	float		bobmove;
	int			old;
	int			setAnimFlags = 0;

#ifdef _GAME
    gclient_t *client = NULL;
    {
		int clientNum = pm->ps->clientNum;
		if (0 <= clientNum && clientNum < MAX_CLIENTS) {
			client = g_entities[clientNum].client;
		}
	}
#endif

	if ( (PM_InSaberAnim( (pm->ps->legsAnim) ) && !BG_SpinningSaberAnim( (pm->ps->legsAnim) ))
		|| (pm->ps->legsAnim) == BOTH_STAND1
		|| (pm->ps->legsAnim) == BOTH_STAND1TO2
		|| (pm->ps->legsAnim) == BOTH_STAND2TO1
		|| (pm->ps->legsAnim) == BOTH_STAND2
		|| (pm->ps->legsAnim) == BOTH_SABERFAST_STANCE
		|| (pm->ps->legsAnim) == BOTH_SABERSLOW_STANCE
		|| (pm->ps->legsAnim) == BOTH_BUTTON_HOLD
		|| (pm->ps->legsAnim) == BOTH_BUTTON_RELEASE
		|| PM_LandingAnim( (pm->ps->legsAnim) )
		|| PM_PainAnim( (pm->ps->legsAnim) ))
	{//legs are in a saber anim, and not spinning, be sure to override it
		setAnimFlags |= SETANIM_FLAG_OVERRIDE;
	}

	//
	// calculate speed and cycle to be used for
	// all cyclic walking effects
	//
	pm->xyspeed = sqrt( pm->ps->velocity[0] * pm->ps->velocity[0]
		+  pm->ps->velocity[1] * pm->ps->velocity[1] );

	if (pm->ps->saberMove == LS_SPINATTACK)
	{
		PM_ContinueLegsAnim( pm->ps->torsoAnim );
	}
	else if ( pm->ps->groundEntityNum == ENTITYNUM_NONE ) {

		// airborne leaves position in cycle intact, but doesn't advance
		if ( pm->waterlevel > 1 )
		{
			if (pm->xyspeed > 60)
			{
				PM_ContinueLegsAnim( BOTH_SWIMFORWARD );
			}
			else
			{
				PM_ContinueLegsAnim( BOTH_SWIM_IDLE1 );
			}
		}
		return;
	}
	// if not trying to move
	else if ( !pm->cmd.forwardmove && !pm->cmd.rightmove ) {
		if (  pm->xyspeed < 5 ) {
			pm->ps->bobCycle = 0;	// start at beginning of cycle again
			if ( pm->ps->clientNum >= MAX_CLIENTS &&
				pm_entSelf &&
				pm_entSelf->s.NPC_class == CLASS_RANCOR )
			{
				if ( (pm->ps->eFlags2&EF2_USE_ALT_ANIM) )
				{//holding someone
					PM_ContinueLegsAnim( BOTH_STAND4 );
					//PM_SetAnim(pm,SETANIM_LEGS,BOTH_STAND4,SETANIM_FLAG_NORMAL);
				}
				else if ( (pm->ps->eFlags2&EF2_ALERTED) )
				{//have an enemy or have had one since we spawned
					PM_ContinueLegsAnim( BOTH_STAND2 );
					//PM_SetAnim(pm,SETANIM_LEGS,BOTH_STAND2,SETANIM_FLAG_NORMAL);
				}
				else
				{//just stand there
					PM_ContinueLegsAnim( BOTH_STAND1 );
					//PM_SetAnim(pm,SETANIM_LEGS,BOTH_STAND1,SETANIM_FLAG_NORMAL);
				}
			}
			else if ( pm->ps->clientNum >= MAX_CLIENTS &&
				pm_entSelf &&
				pm_entSelf->s.NPC_class == CLASS_WAMPA )
			{
				if ( (pm->ps->eFlags2&EF2_USE_ALT_ANIM) )
				{//holding a victim
					PM_ContinueLegsAnim( BOTH_STAND2 );
					//PM_SetAnim(pm,SETANIM_LEGS,BOTH_STAND2,SETANIM_FLAG_NORMAL);
				}
				else
				{//not holding a victim
					PM_ContinueLegsAnim( BOTH_STAND1 );
					//PM_SetAnim(pm,SETANIM_LEGS,BOTH_STAND1,SETANIM_FLAG_NORMAL);
				}
			}
			else if ( (pm->ps->pm_flags & PMF_DUCKED) || (pm->ps->pm_flags & PMF_ROLLING) ) {
				if ((pm->ps->legsAnim) != BOTH_CROUCH1IDLE)
				{
					PM_SetAnim(SETANIM_LEGS, BOTH_CROUCH1IDLE, setAnimFlags);
				}
				else
				{
					PM_ContinueLegsAnim( BOTH_CROUCH1IDLE );
				}
				if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && (pm->ps->torsoAnim != BOTH_CROUCH1IDLE)) {
					PM_SetAnim(SETANIM_TORSO, BOTH_CROUCH1IDLE, setAnimFlags);
				}
			} else {
				if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
				{
					///????  continue legs anim on a torso anim...??!!!
					//yeah.. the anim has a valid pose for the legs, it uses it (you can't move while using disruptor)
					PM_ContinueLegsAnim( TORSO_WEAPONREADY4 );
				}
				else
				{
					if (pm->ps->weapon == WP_SABER && BG_SabersOff( pm->ps ) )
					{
						if (!PM_AdjustStandAnimForSlope())
						{
							//PM_ContinueLegsAnim( BOTH_STAND1 );
							PM_ContinueLegsAnim(PM_LegsSlopeBackTransition(BOTH_STAND1));
						}
					}
					else
					{
						if (pm->ps->weapon != WP_SABER || !PM_AdjustStandAnimForSlope())
						{
							if (pm->ps->weapon == WP_SABER)
							{
								PM_ContinueLegsAnim(PM_LegsSlopeBackTransition(PM_GetSaberStance()));
							}
							else
							{
								PM_ContinueLegsAnim(PM_LegsSlopeBackTransition(WeaponReadyLegsAnim[pm->ps->weapon]));
							}
						}
					}
				}
			}
		}
		return;
	}

	if (pm->ps->saberMove == LS_SPINATTACK)
	{
		bobmove = 0.2f;
		PM_ContinueLegsAnim( pm->ps->torsoAnim );
	}
	else if ( pm->ps->pm_flags & PMF_DUCKED )
	{
		int rolled = 0;

		bobmove = 0.5;	// ducked characters bob much faster

//[JAPRO - Serverside + Clientside - Physics - Add roll types - Start]

		{
			int fixRoll = GetFixRoll(pm->ps);
			if (((fixRoll > 1 && (PM_RunningAnim(pm->ps->legsAnim) || PM_CanRollFromSoulCal(pm->ps))) ||
				((fixRoll == 1) && (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=30000)) ||
				(PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=40000)))
				rolled = PM_TryRoll();

/*
#ifdef _GAME
			if ((g_fixRoll.integer > 1) && (PM_RunningAnim(pm->ps->legsAnim) || PM_CanRollFromSoulCal(pm->ps)))
			{
				rolled = PM_TryRoll();
			}
			else if ((g_fixRoll.integer == 1) && (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=30000))
			{
				rolled = PM_TryRoll();
			}
			else if (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=40000)
			{
				rolled = PM_TryRoll();
			}
#else
			if (cgs.serverMod == SVMOD_JAPRO )
			{
				if ((cgs.jcinfo & JAPRO_CINFO_FIXROLL3 || cgs.jcinfo & JAPRO_CINFO_FIXROLL2) && (PM_RunningAnim(pm->ps->legsAnim) || PM_CanRollFromSoulCal(pm->ps)))
				{
					rolled = PM_TryRoll();
				}
				else if ((cgs.jcinfo & JAPRO_CINFO_FIXROLL1) && (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=30000))
				{
					rolled = PM_TryRoll();
				}
				else if (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=40000)
				{
					rolled = PM_TryRoll();
				}
			}
			else if (cgs.serverMod == SVMOD_JAPLUS)
			{
				if ((cgs.cinfo & JAPLUS_CINFO_FIXROLL3 || cgs.cinfo & JAPLUS_CINFO_FIXROLL2) && (PM_RunningAnim(pm->ps->legsAnim) || PM_CanRollFromSoulCal(pm->ps)))
				{
					rolled = PM_TryRoll();
				}
				else if (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=30000)
				{
					rolled = PM_TryRoll();
				}
			}
			else if (PM_RunningAnim(pm->ps->legsAnim) && VectorLengthSquared(pm->ps->velocity)>=40000)
			{
				rolled = PM_TryRoll();
			}
#endif
			*/
		}
//[JAPRO - Serverside + Clientside - Physics - Add roll types - End]

		if ( !rolled )
		{ //if the roll failed or didn't attempt, do standard crouching anim stuff.
			if ( pm->ps->pm_flags & PMF_BACKWARDS_RUN ) {
				if ((pm->ps->legsAnim) != BOTH_CROUCH1WALKBACK)
				{
					PM_SetAnim(SETANIM_LEGS, BOTH_CROUCH1WALKBACK, setAnimFlags);
				}
				else
				{
					PM_ContinueLegsAnim( BOTH_CROUCH1WALKBACK );
				}
				if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && (pm->ps->torsoAnim != BOTH_CROUCH1WALKBACK)) {
					PM_SetAnim(SETANIM_TORSO, BOTH_CROUCH1WALKBACK, setAnimFlags);
				}
			}
			else {
				if ((pm->ps->legsAnim) != BOTH_CROUCH1WALK)
				{
					PM_SetAnim(SETANIM_LEGS, BOTH_CROUCH1WALK, setAnimFlags);
				}
				else
				{
					PM_ContinueLegsAnim( BOTH_CROUCH1WALK );
				}
				if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && (pm->ps->torsoAnim != BOTH_CROUCH1WALK)) {
					PM_SetAnim(SETANIM_TORSO, BOTH_CROUCH1WALK, setAnimFlags);
				}
			}
		}
		else
		{ //otherwise send us into the roll
			pm->ps->legsTimer = 0;
			pm->ps->legsAnim = 0;
			PM_SetAnim(SETANIM_BOTH,rolled,SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			PM_AddEventWithParm( EV_ROLL, 0 );
			pm->maxs[2] = pm->ps->crouchheight;//CROUCH_MAXS_2;
			pm->ps->viewheight = DEFAULT_VIEWHEIGHT;
			pm->ps->pm_flags &= ~PMF_DUCKED;
			pm->ps->pm_flags |= PMF_ROLLING;
		}
	}
	else if ((pm->ps->pm_flags & PMF_ROLLING) && !BG_InRoll(pm->ps, pm->ps->legsAnim) &&
		!PM_InRollComplete(pm->ps, pm->ps->legsAnim))
	{
		bobmove = 0.5;	// ducked characters bob much faster

		if ( pm->ps->pm_flags & PMF_BACKWARDS_RUN )
		{
			if ((pm->ps->legsAnim) != BOTH_CROUCH1WALKBACK)
			{
				PM_SetAnim(SETANIM_LEGS, BOTH_CROUCH1WALKBACK, setAnimFlags);
			}
			else
			{
				PM_ContinueLegsAnim( BOTH_CROUCH1WALKBACK );
			}
			if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && (pm->ps->torsoAnim != BOTH_CROUCH1WALKBACK)) {
				PM_SetAnim(SETANIM_TORSO, BOTH_CROUCH1WALKBACK, setAnimFlags);
			}
		}
		else
		{
			if ((pm->ps->legsAnim) != BOTH_CROUCH1WALK)
			{
				PM_SetAnim(SETANIM_LEGS, BOTH_CROUCH1WALK, setAnimFlags);
			}
			else
			{
				PM_ContinueLegsAnim( BOTH_CROUCH1WALK );
			}
			if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && (pm->ps->torsoAnim != BOTH_CROUCH1WALK)) {
				PM_SetAnim(SETANIM_TORSO, BOTH_CROUCH1WALK, setAnimFlags);
			}
		}
	}
	else
	{
		int desiredAnim = -1;

		if ((pm->ps->legsAnim == BOTH_FORCELAND1 ||
			pm->ps->legsAnim == BOTH_FORCELANDBACK1 ||
			pm->ps->legsAnim == BOTH_FORCELANDRIGHT1 ||
			pm->ps->legsAnim == BOTH_FORCELANDLEFT1) &&
			pm->ps->legsTimer > 0)
		{ //let it finish first
			bobmove = 0.2f;
		}
		else if ((pm->cmd.buttons & BUTTON_DASH) && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {//tribes ski
			bobmove = 0.4f;
			if (pm->cmd.rightmove > 0)
				desiredAnim = BOTH_HOP_R;
			else if (pm->cmd.rightmove < 0)
				desiredAnim = BOTH_HOP_L;
			else if (pm->cmd.forwardmove > 0)
				desiredAnim = BOTH_HOP_F;
			else if (pm->cmd.forwardmove < 0)
				desiredAnim = BOTH_HOP_B;
		}
		else if ( !( pm->cmd.buttons & BUTTON_WALKING ) )
		{//running
			bobmove = 0.4f;	// faster speeds bob faster
			if ( pm->ps->clientNum >= MAX_CLIENTS &&
				pm_entSelf &&
				pm_entSelf->s.NPC_class == CLASS_WAMPA )
			{
				if ( (pm->ps->eFlags2&EF2_USE_ALT_ANIM) )
				{//full on run, on all fours
					desiredAnim = BOTH_RUN1;
				}
				else
				{//regular, upright run
					desiredAnim = BOTH_RUN2;
				}
			}
			else if ( pm->ps->clientNum >= MAX_CLIENTS &&
				pm_entSelf &&
				pm_entSelf->s.NPC_class == CLASS_RANCOR )
			{//no run anims
				if ( (pm->ps->pm_flags&PMF_BACKWARDS_RUN) )
				{
					desiredAnim = BOTH_WALKBACK1;
				}
				else
				{
					desiredAnim = BOTH_WALK1;
				}
			}
#ifdef _GAME
			else if ( pm->ps->clientNum >= MAX_CLIENTS &&
				pm_entSelf &&
				pm_entSelf->s.NPC_class == CLASS_JAWA)
			{
				// Jawa has a special run animation :D
				desiredAnim = BOTH_RUN4;
				bobmove = 0.2f;
			}
#endif
			else if ( pm->ps->pm_flags & PMF_BACKWARDS_RUN )
			{
				if ( BG_AreRunWalkAnimsFixed() && (pm->ps->weapon != WP_SABER || pm->ps->saberInFlight) )
				{
					desiredAnim = BOTH_RUNBACK1;
				}
				else
				{
				switch (pm->ps->fd.saberAnimLevel)
					{
					case SS_STAFF:
						if ( pm->ps->saberHolstered > 1 )
						{//saber off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK1;
						}
						else
						{
							//desiredAnim = BOTH_RUNBACK_STAFF;
							//hmm.. stuff runback anim is pretty messed up for some reason.
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK2;
						}
						break;
					case SS_DUAL:
						if ( pm->ps->saberHolstered > 1 )
						{//sabers off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK1;
						}
						else
						{
							//desiredAnim = BOTH_RUNBACK_DUAL;
							//and so is the dual
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK2;
						}
						break;
					default:
						if ( pm->ps->saberHolstered )
						{//saber off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK1;
						}
						else
						{
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUNBACK2;
						}
						break;
					}
				}
			}
			else
			{
				if ( pm->ps->weapon != WP_SABER || pm->ps->saberInFlight )
				{
					desiredAnim = BOTH_RUN1;
				}
				else
				{
					switch (pm->ps->fd.saberAnimLevel)
					{
					case SS_STAFF:
						if ( pm->ps->saberHolstered > 1 )
						{//blades off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN1;
						}
						else if ( pm->ps->saberHolstered == 1 )
						{//1 blade on
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN2;
						}
						else
						{
							if (pm->ps->fd.forcePowersActive & (1<<FP_SPEED))
							{
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN1;
							}
							else
							{
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN_STAFF;
							}
						}
						break;
					case SS_DUAL:
						if ( pm->ps->saberHolstered > 1 )
						{//blades off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN1;
						}
						else if ( pm->ps->saberHolstered == 1 )
						{//1 saber on
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
							desiredAnim = BOTH_RUN1;
						}
						else
						{
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN_DUAL;
						}
						break;
					default:
						if ( pm->ps->saberHolstered )
						{//saber off
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN1;
						}
						else
						{
#ifdef _GAME
							if (client && client->pers.JAWARUN && !(g_emotesDisable.integer & (1 << E_JAWARUN)))//JAPRO - Jawarun Emote
								desiredAnim = BOTH_RUN4;
							else
#else
							if (cgs.serverMod == SVMOD_JAPRO && (!(cgs.jcinfo & JAPRO_CINFO_NOJAWARUN)) && (cp_pluginDisable.integer & JAPRO_PLUGIN_JAWARUN))
								desiredAnim = BOTH_RUN4;
							else
#endif
								desiredAnim = BOTH_RUN2;
						}
						break;
					}
				}
			}
		}
		else
		{
			bobmove = 0.2f;	// walking bobs slow
			if ( pm->ps->pm_flags & PMF_BACKWARDS_RUN )
			{
				if(BG_AreRunWalkAnimsFixed() && (pm->ps->weapon != WP_SABER || pm->ps->saberInFlight ))
				{
					desiredAnim = BOTH_WALKBACK1;
				}
				else
				{
					switch (pm->ps->fd.saberAnimLevel)
					{
					case SS_STAFF:
						if ( pm->ps->saberHolstered > 1 )
						{
							desiredAnim = BOTH_WALKBACK1;
						}
						else if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALKBACK2;
						}
						else
						{
							desiredAnim = BOTH_WALKBACK_STAFF;
						}
						break;
					case SS_DUAL:
						if ( pm->ps->saberHolstered > 1 )
						{
							desiredAnim = BOTH_WALKBACK1;
						}
						else if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALKBACK2;
						}
						else
						{
							desiredAnim = BOTH_WALKBACK_DUAL;
						}
						break;
					default:
						if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALKBACK1;
						}
						else
						{
							desiredAnim = BOTH_WALKBACK2;
						}
						break;
					}
				}
			}
			else
			{
				if ( pm->ps->weapon == WP_MELEE )
				{
					desiredAnim = BOTH_WALK1;
				}
				else if ( BG_SabersOff( pm->ps ) )
				{
					desiredAnim = BOTH_WALK1;
				}
				else if ( pm->ps->weapon != WP_SABER || pm->ps->saberInFlight )
				{
					desiredAnim = BOTH_WALK1;
				}
				else
				{
					switch (pm->ps->fd.saberAnimLevel)
					{
					case SS_STAFF:
						if ( pm->ps->saberHolstered > 1 )
						{
							desiredAnim = BOTH_WALK1;
						}
						else if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALK2;
						}
						else
						{
							desiredAnim = BOTH_WALK_STAFF;
						}
						break;
					case SS_DUAL:
						if ( pm->ps->saberHolstered > 1 )
						{
							desiredAnim = BOTH_WALK1;
						}
						else if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALK2;
						}
						else
						{
							desiredAnim = BOTH_WALK_DUAL;
						}
						break;
					default:
						if ( pm->ps->saberHolstered )
						{
							desiredAnim = BOTH_WALK1;
						}
						else
						{
							desiredAnim = BOTH_WALK2;
						}
						break;
					}
				}
			}
		}

		if (desiredAnim != -1)
		{
			int ires = PM_LegsSlopeBackTransition(desiredAnim);

			if ((pm->ps->legsAnim) != desiredAnim && ires == desiredAnim)
			{
				PM_SetAnim(SETANIM_LEGS, desiredAnim, setAnimFlags);
			}
			else
			{
				PM_ContinueLegsAnim(ires);
			}

			if (BG_AreRunWalkAnimsFixed() && (pm->ps->saberInFlight) && ((pm->ps->torsoAnim) != desiredAnim && ires == desiredAnim)) { //silly hack for predicted walking anims while disarmed
				PM_SetAnim(SETANIM_TORSO, desiredAnim, setAnimFlags);
			}
		}
	}

	// check for footstep / splash sounds
	old = pm->ps->bobCycle;
	pm->ps->bobCycle = (int)( old + bobmove * pml.msec ) & 255;

	// if we just crossed a cycle boundary, play an appropriate footstep event
	if ( ( ( old + 64 ) ^ ( pm->ps->bobCycle + 64 ) ) & 128 )
	{
		pm->ps->footstepTime = pm->cmd.serverTime + 300;
		if ( pm->waterlevel == 1 ) {
			// splashing
			PM_AddEvent( EV_FOOTSPLASH );
		} else if ( pm->waterlevel == 2 ) {
			// wading / swimming at surface
			PM_AddEvent( EV_SWIM );
		} else if ( pm->waterlevel == 3 ) {
			// no sound when completely underwater
		}
	}
}

/*
==============
PM_WaterEvents

Generate sound events for entering and leaving water
==============
*/
static void PM_WaterEvents( void ) {		// FIXME?
#ifdef _GAME
	qboolean impact_splash = qfalse;
#endif
	//
	// if just entered a water volume, play a sound
	//
	if (!pml.previous_waterlevel && pm->waterlevel) {
#ifdef _GAME
		if ( VectorLengthSquared( pm->ps->velocity ) > 40000 )
		{
			impact_splash = qtrue;
		}
#endif
		PM_AddEvent( EV_WATER_TOUCH );
	}

	//
	// if just completely exited a water volume, play a sound
	//
	if (pml.previous_waterlevel && !pm->waterlevel) {
#ifdef _GAME
		if ( VectorLengthSquared( pm->ps->velocity ) > 40000 )
		{
			impact_splash = qtrue;
		}
#endif
		PM_AddEvent( EV_WATER_LEAVE );
	}

#ifdef _GAME
	if ( impact_splash )
	{
		//play the splash effect
		trace_t	tr;
		vec3_t	start, end;


		VectorCopy( pm->ps->origin, start );
		VectorCopy( pm->ps->origin, end );

		// FIXME: set start and end better
		start[2] += 10;
		end[2] -= 40;

		pm->trace( &tr, start, vec3_origin, vec3_origin, end, pm->ps->clientNum, MASK_WATER );

		if ( tr.fraction < 1.0f )
		{
			if ( (tr.contents&CONTENTS_LAVA) )
			{
				G_PlayEffect( EFFECT_LAVA_SPLASH, tr.endpos, tr.plane.normal );
			}
			else if ( (tr.contents&CONTENTS_SLIME) )
			{
				G_PlayEffect( EFFECT_ACID_SPLASH, tr.endpos, tr.plane.normal );
			}
			else //must be water
			{
				G_PlayEffect( EFFECT_WATER_SPLASH, tr.endpos, tr.plane.normal );
			}
		}
	}
#endif

	//
	// check for head just going under water
	//
	if (pml.previous_waterlevel != 3 && pm->waterlevel == 3) {
		PM_AddEvent( EV_WATER_UNDER );
	}

	//
	// check for head just coming out of water
	//
	if (pml.previous_waterlevel == 3 && pm->waterlevel != 3) {
		PM_AddEvent( EV_WATER_CLEAR );
	}
}

void BG_ClearRocketLock( playerState_t *ps )
{
	if ( ps )
	{
		ps->rocketLockIndex = ENTITYNUM_NONE;
		ps->rocketLastValidTime = 0;
		ps->rocketLockTime = -1;
		ps->rocketTargetTime = 0;
	}
}

/*
===============
PM_BeginWeaponChange
===============
*/
void PM_BeginWeaponChange( int weapon ) {
	if ( weapon <= WP_NONE || weapon >= WP_NUM_WEAPONS ) {
		return;
	}

	if ( !( pm->ps->stats[STAT_WEAPONS] & ( 1 << weapon ) ) ) {
		return;
	}

	if ( pm->ps->weaponstate == WEAPON_DROPPING ) {
		return;
	}

	// turn of any kind of zooming when weapon switching.
	if (pm->ps->zoomMode)
	{
		pm->ps->zoomMode = 0;
		pm->ps->zoomTime = pm->ps->commandTime;
	}

	PM_AddEventWithParm( EV_CHANGE_WEAPON, weapon );
	pm->ps->weaponstate = WEAPON_DROPPING;
	pm->ps->weaponTime += 200;

#if _GAME
#if _SPECIFICWEAPONTIME
	if ((g_tweakWeapons.integer & WT_TRIBES) && !pm->ps->stats[STAT_RACEMODE]) {
		int i;
		for (i = 0; i < MAX_WEAPONS; i++) {
			((gentity_t *)pm_entSelf)->client->specificWeaponTime[i] += 50;
		}
	}
#endif
#endif

	//PM_StartTorsoAnim( TORSO_DROPWEAP1 );
	PM_SetAnim(SETANIM_TORSO, TORSO_DROPWEAP1, SETANIM_FLAG_OVERRIDE);

	BG_ClearRocketLock( pm->ps );
}


/*
===============
PM_FinishWeaponChange
===============
*/
void PM_FinishWeaponChange( void ) {
	int		weapon;

	weapon = pm->cmd.weapon;
	if ( weapon < WP_NONE || weapon >= WP_NUM_WEAPONS ) {
		weapon = WP_NONE;
	}

	if ( !( pm->ps->stats[STAT_WEAPONS] & ( 1 << weapon ) ) ) {
		weapon = WP_NONE;
	}

	if (weapon == WP_SABER)
	{
		PM_SetSaberMove(LS_DRAW);
	}
	else
	{
		//PM_StartTorsoAnim( TORSO_RAISEWEAP1);
		PM_SetAnim(SETANIM_TORSO, TORSO_RAISEWEAP1, SETANIM_FLAG_OVERRIDE);
	}
	pm->ps->weapon = weapon;
	pm->ps->weaponstate = WEAPON_RAISING;
#ifdef _GAME
	if (!pm->ps->stats[STAT_RACEMODE] && (g_tweakSaber.integer & ST_FIXED_SABERSWITCH) && weapon == WP_SABER) {//fix saber switch glitch if we want
		pm->ps->weaponTime += 1250;
		((gentity_t *)pm_entSelf)->client->saberDelayCount += 1000; //Ait.. this is the delay past 250 that is added, we wil subract this from weapontime later when checking forcepower use
		//saberDelay can never be negative. Saber delay can never be more than weapontime-250.
	}
	else if (!pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_FAST_WEAPONSWITCH))
		pm->ps->weaponTime += 25;
	else
		pm->ps->weaponTime += 50;
#else
		pm->ps->weaponTime += 250;
#endif

#if _GAME
#if _SPECIFICWEAPONTIME
		if ((g_tweakWeapons.integer & WT_TRIBES) && !pm->ps->stats[STAT_RACEMODE]) {
			int i;
			for (i = 0; i < MAX_WEAPONS; i++) {
				((gentity_t *)pm_entSelf)->client->specificWeaponTime[i] += 100;
			}
		}
#endif
#endif

}

#ifdef _GAME
extern void WP_GetVehicleCamPos( gentity_t *ent, gentity_t *pilot, vec3_t camPos );
#else
extern void CG_GetVehicleCamPos( vec3_t camPos );
#endif
#define MAX_XHAIR_DIST_ACCURACY	20000.0f
int BG_VehTraceFromCamPos( trace_t *camTrace, bgEntity_t *bgEnt, const vec3_t entOrg, const vec3_t shotStart, const vec3_t end, vec3_t newEnd, vec3_t shotDir, float bestDist )
{
	//NOTE: this MUST stay up to date with the method used in CG_ScanForCrosshairEntity (where it checks the doExtraVehTraceFromViewPos bool)
	vec3_t	viewDir2End, extraEnd, camPos;
	float	minAutoAimDist;

#ifdef _GAME
	WP_GetVehicleCamPos( (gentity_t *)bgEnt, (gentity_t *)bgEnt->m_pVehicle->m_pPilot, camPos );
#else
	CG_GetVehicleCamPos( camPos );
#endif

	minAutoAimDist = Distance( entOrg, camPos ) + (bgEnt->m_pVehicle->m_pVehicleInfo->length/2.0f) + 200.0f;

	VectorCopy( end, newEnd );
	VectorSubtract( end, camPos, viewDir2End );
	VectorNormalize( viewDir2End );
	VectorMA( camPos, MAX_XHAIR_DIST_ACCURACY, viewDir2End, extraEnd );

	pm->trace( camTrace, camPos, vec3_origin, vec3_origin, extraEnd, bgEnt->s.number, CONTENTS_SOLID|CONTENTS_BODY );

	if ( !camTrace->allsolid
		&& !camTrace->startsolid
		&& camTrace->fraction < 1.0f
		&& (camTrace->fraction*MAX_XHAIR_DIST_ACCURACY) > minAutoAimDist
		&& ((camTrace->fraction*MAX_XHAIR_DIST_ACCURACY)-Distance( entOrg, camPos )) < bestDist )
	{//this trace hit *something* that's closer than the thing the main trace hit, so use this result instead
		VectorCopy( camTrace->endpos, newEnd );
		VectorSubtract( newEnd, shotStart, shotDir );
		VectorNormalize( shotDir );
		return (camTrace->entityNum+1);
	}
	return 0;
}

void PM_RocketLock( float lockDist, qboolean vehicleLock )
{
	// Not really a charge weapon, but we still want to delay fire until the button comes up so that we can
	//	implement our alt-fire locking stuff
	vec3_t		ang;
	trace_t		tr;

	vec3_t muzzleOffPoint, muzzlePoint, forward, right, up;

	if ( vehicleLock )
	{
		AngleVectors( pm->ps->viewangles, forward, right, up );
		VectorCopy( pm->ps->origin, muzzlePoint );
		VectorMA( muzzlePoint, lockDist, forward, ang );
	}
	else
	{
		AngleVectors( pm->ps->viewangles, forward, right, up );

		AngleVectors(pm->ps->viewangles, ang, NULL, NULL);

		VectorCopy( pm->ps->origin, muzzlePoint );
		VectorCopy(WP_MuzzlePoint[WP_ROCKET_LAUNCHER], muzzleOffPoint);

		VectorMA(muzzlePoint, muzzleOffPoint[0], forward, muzzlePoint);
		VectorMA(muzzlePoint, muzzleOffPoint[1], right, muzzlePoint);
		muzzlePoint[2] += pm->ps->viewheight + muzzleOffPoint[2];
		ang[0] = muzzlePoint[0] + ang[0]*lockDist;
		ang[1] = muzzlePoint[1] + ang[1]*lockDist;
		ang[2] = muzzlePoint[2] + ang[2]*lockDist;
	}


	pm->trace(&tr, muzzlePoint, NULL, NULL, ang, pm->ps->clientNum, MASK_PLAYERSOLID);

	if ( vehicleLock )
	{//vehicles also do a trace from the camera point if the main one misses
		if ( tr.fraction >= 1.0f )
		{
			trace_t camTrace;
			vec3_t newEnd, shotDir;
			if ( BG_VehTraceFromCamPos( &camTrace, PM_BGEntForNum(pm->ps->clientNum), pm->ps->origin, muzzlePoint, tr.endpos, newEnd, shotDir, (tr.fraction*lockDist) ) )
			{
				memcpy( &tr, &camTrace, sizeof(tr) );
			}
		}
	}

	if (tr.fraction != 1 && tr.entityNum < ENTITYNUM_NONE && tr.entityNum != pm->ps->clientNum)
	{
		bgEntity_t *bgEnt = PM_BGEntForNum(tr.entityNum);
		if ( bgEnt && (bgEnt->s.powerups&PW_CLOAKED) )
		{
			pm->ps->rocketLockIndex = ENTITYNUM_NONE;
			pm->ps->rocketLockTime = 0;
		}
		else if (bgEnt && (bgEnt->s.eType == ET_PLAYER || bgEnt->s.eType == ET_NPC))
		{
			if (pm->ps->rocketLockIndex == ENTITYNUM_NONE)
			{
				pm->ps->rocketLockIndex = tr.entityNum;
				pm->ps->rocketLockTime = pm->cmd.serverTime;
			}
			else if (pm->ps->rocketLockIndex != tr.entityNum && pm->ps->rocketTargetTime < pm->cmd.serverTime)
			{
				pm->ps->rocketLockIndex = tr.entityNum;
				pm->ps->rocketLockTime = pm->cmd.serverTime;
			}
			else if (pm->ps->rocketLockIndex == tr.entityNum)
			{
				if (pm->ps->rocketLockTime == -1)
				{
					pm->ps->rocketLockTime = pm->ps->rocketLastValidTime;
				}
			}

			if (pm->ps->rocketLockIndex == tr.entityNum)
			{
				pm->ps->rocketTargetTime = pm->cmd.serverTime + 500;
			}
		}
		else if (!vehicleLock)
		{
			if (pm->ps->rocketTargetTime < pm->cmd.serverTime)
			{
				pm->ps->rocketLockIndex = ENTITYNUM_NONE;
				pm->ps->rocketLockTime = 0;
			}
		}
	}
	else if (pm->ps->rocketTargetTime < pm->cmd.serverTime)
	{
		pm->ps->rocketLockIndex = ENTITYNUM_NONE;
		pm->ps->rocketLockTime = 0;
	}
	else
	{
		if (pm->ps->rocketLockTime != -1)
		{
			pm->ps->rocketLastValidTime = pm->ps->rocketLockTime;
		}
		pm->ps->rocketLockTime = -1;
	}
}

//---------------------------------------
static qboolean PM_DoChargedWeapons( qboolean vehicleRocketLock, bgEntity_t *veh )
//---------------------------------------
{
	qboolean	charging = qfalse,
				altFire = qfalse;

	if (pm->ps->stats[STAT_RACEMODE])
		return qfalse;

	if ( vehicleRocketLock )
	{
		if ( (pm->cmd.buttons&(BUTTON_ATTACK|BUTTON_ALT_ATTACK)) )
		{//actually charging
			if ( veh
				&& veh->m_pVehicle )
			{//just make sure we have this veh info
				if ( ( (pm->cmd.buttons&BUTTON_ATTACK)
						&&g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[0].ID].fHoming
						&&pm->ps->ammo[0]>=g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[0].ID].iAmmoPerShot )
						||
					( (pm->cmd.buttons&BUTTON_ALT_ATTACK)
						&&g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[1].ID].fHoming
						&&pm->ps->ammo[1]>=g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[1].ID].iAmmoPerShot ) )
				{//pressing the appropriate fire button for the lock-on/charging weapon
					PM_RocketLock(16384, qtrue);
					charging = qtrue;
				}
				if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
				{
					altFire = qtrue;
				}
			}
		}
		//else, let go and should fire now
	}
	else
	{
		// If you want your weapon to be a charging weapon, just set this bit up
		switch( pm->ps->weapon )
		{
		//------------------
		case WP_BRYAR_PISTOL:

			// alt-fire charges the weapon
			//if ( pm->gametype == GT_SIEGE )
			if (1)
			{
				if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
				{
					charging = qtrue;
					altFire = qtrue;
				}
			}
			break;

		case WP_CONCUSSION:
			if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
			{
				altFire = qtrue;
			}
			break;

		case WP_BRYAR_OLD:

			// alt-fire charges the weapon
			if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
			{
				charging = qtrue;
				altFire = qtrue;
			}
			break;

		//------------------
		case WP_BOWCASTER:

			// primary fire charges the weapon
			if ( pm->cmd.buttons & BUTTON_ATTACK )
			{
				charging = qtrue;
			}
			break;

		//------------------
		case WP_ROCKET_LAUNCHER:
			if ( (pm->cmd.buttons & BUTTON_ALT_ATTACK)
				&& pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] >= weaponData[pm->ps->weapon].altEnergyPerShot )
			{
#ifdef _GAME
				if (pm->ps->stats[STAT_RACEMODE]) {
					PM_RocketLock(2048, qfalse);
					charging = qtrue;
				}
				altFire = qtrue;
#else
				PM_RocketLock(2048,qfalse);
				charging = qtrue;
				altFire = qtrue;
#endif
			}
			break;

		//------------------
		case WP_THERMAL:

			if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
			{
				altFire = qtrue; // override default of not being an alt-fire
				charging = qtrue;
			}
			else if ( pm->cmd.buttons & BUTTON_ATTACK )
			{
				charging = qtrue;
			}
			break;

		case WP_DEMP2:
			if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
			{
				altFire = qtrue; // override default of not being an alt-fire
				charging = qtrue;
			}
			break;

		case WP_DISRUPTOR:
			if ((pm->cmd.buttons & BUTTON_ATTACK) &&
				pm->ps->zoomMode == 1 &&
				pm->ps->zoomLocked)
			{
				if (!pm->cmd.forwardmove &&
					!pm->cmd.rightmove &&
					pm->cmd.upmove <= 0)
				{
					charging = qtrue;
					altFire = qtrue;
				}
				else
				{
					charging = qfalse;
					altFire = qfalse;
				}
			}

			if (pm->ps->zoomMode != 1 &&
				pm->ps->weaponstate == WEAPON_CHARGING_ALT)
			{
				pm->ps->weaponstate = WEAPON_READY;
				charging = qfalse;
				altFire = qfalse;
			}

		} // end switch
	}

	// set up the appropriate weapon state based on the button that's down.
	//	Note that we ALWAYS return if charging is set ( meaning the buttons are still down )
	if ( charging )
	{
		if ( altFire )
		{
			if ( pm->ps->weaponstate != WEAPON_CHARGING_ALT )
			{
				// charge isn't started, so do it now
				pm->ps->weaponstate = WEAPON_CHARGING_ALT;
				pm->ps->weaponChargeTime = pm->cmd.serverTime;
				pm->ps->weaponChargeSubtractTime = pm->cmd.serverTime + weaponData[pm->ps->weapon].altChargeSubTime;

#ifdef _DEBUG
			//	Com_Printf("Starting charge\n");
#endif
				assert(pm->ps->weapon > WP_NONE);
				BG_AddPredictableEventToPlayerstate(EV_WEAPON_CHARGE_ALT, pm->ps->weapon, pm->ps);
			}

			if ( vehicleRocketLock )
			{//check vehicle ammo
				if ( veh && pm->ps->ammo[1] < g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[1].ID].iAmmoPerShot )
				{
					pm->ps->weaponstate = WEAPON_CHARGING_ALT;
					goto rest;
				}
			}
			else if (pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] < (weaponData[pm->ps->weapon].altChargeSub+weaponData[pm->ps->weapon].altEnergyPerShot))
			{
				pm->ps->weaponstate = WEAPON_CHARGING_ALT;

				goto rest;
			}
			else if ((pm->cmd.serverTime - pm->ps->weaponChargeTime) < weaponData[pm->ps->weapon].altMaxCharge)
			{
				if (pm->ps->weaponChargeSubtractTime < pm->cmd.serverTime)
				{
#ifdef _GAME
					if (!pm->ps->stats[STAT_RACEMODE] && !(g_tweakWeapons.integer & WT_INFINITE_AMMO))
#endif
						pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] -= weaponData[pm->ps->weapon].altChargeSub;
					pm->ps->weaponChargeSubtractTime = pm->cmd.serverTime + weaponData[pm->ps->weapon].altChargeSubTime;
				}
			}
		}
		else
		{
			if ( pm->ps->weaponstate != WEAPON_CHARGING )
			{
				// charge isn't started, so do it now
				pm->ps->weaponstate = WEAPON_CHARGING;
				pm->ps->weaponChargeTime = pm->cmd.serverTime;
				pm->ps->weaponChargeSubtractTime = pm->cmd.serverTime + weaponData[pm->ps->weapon].chargeSubTime;

#ifdef _DEBUG
			//	Com_Printf("Starting charge\n");
#endif
				BG_AddPredictableEventToPlayerstate(EV_WEAPON_CHARGE, pm->ps->weapon, pm->ps);
			}

			if ( vehicleRocketLock )
			{
				if ( veh && pm->ps->ammo[0] < g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[0].ID].iAmmoPerShot )
				{//check vehicle ammo
					pm->ps->weaponstate = WEAPON_CHARGING;
					goto rest;
				}
			}
			else if (pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] < (weaponData[pm->ps->weapon].chargeSub+weaponData[pm->ps->weapon].energyPerShot))
			{
				pm->ps->weaponstate = WEAPON_CHARGING;

				goto rest;
			}
			else if ((pm->cmd.serverTime - pm->ps->weaponChargeTime) < weaponData[pm->ps->weapon].maxCharge)
			{
				if (pm->ps->weaponChargeSubtractTime < pm->cmd.serverTime)
				{
#ifdef _GAME
					if (!pm->ps->stats[STAT_RACEMODE] && !(g_tweakWeapons.integer & WT_INFINITE_AMMO))
#endif
						pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] -= weaponData[pm->ps->weapon].chargeSub;
					pm->ps->weaponChargeSubtractTime = pm->cmd.serverTime + weaponData[pm->ps->weapon].chargeSubTime;
				}
			}
		}

		return qtrue; // short-circuit rest of weapon code
	}
rest:
	// Only charging weapons should be able to set these states...so....
	//	let's see which fire mode we need to set up now that the buttons are up
	if ( pm->ps->weaponstate == WEAPON_CHARGING )
	{
		// weapon has a charge, so let us do an attack
#ifdef _DEBUG
	//	Com_Printf("Firing.  Charge time=%d\n", pm->cmd.serverTime - pm->ps->weaponChargeTime);
#endif

		// dumb, but since we shoot a charged weapon on button-up, we need to repress this button for now
		pm->cmd.buttons |= BUTTON_ATTACK;
		pm->ps->eFlags |= EF_FIRING;
	}
	else if ( pm->ps->weaponstate == WEAPON_CHARGING_ALT )
	{
		// weapon has a charge, so let us do an alt-attack
#ifdef _DEBUG
	//	Com_Printf("Firing.  Charge time=%d\n", pm->cmd.serverTime - pm->ps->weaponChargeTime);
#endif

		// dumb, but since we shoot a charged weapon on button-up, we need to repress this button for now
		pm->cmd.buttons |= BUTTON_ALT_ATTACK;
		pm->ps->eFlags |= (EF_FIRING|EF_ALT_FIRING);
	}

	return qfalse; // continue with the rest of the weapon code
}


#define BOWCASTER_CHARGE_UNIT	200.0f	// bowcaster charging gives us one more unit every 200ms--if you change this, you'll have to do the same in g_weapon
#define BRYAR_CHARGE_UNIT		200.0f	// bryar charging gives us one more unit every 200ms--if you change this, you'll have to do the same in g_weapon

int PM_ItemUsable(playerState_t *ps, int forcedUse)
{
	vec3_t fwd, fwdorg, dest, pos;
	vec3_t yawonly;
	vec3_t mins, maxs;
	vec3_t trtest;
	trace_t tr;

	if (ps->m_iVehicleNum)
	{
		return 0;
	}

	if (ps->pm_flags & PMF_USE_ITEM_HELD)
	{ //force to let go first
		return 0;
	}

	if (ps->duelInProgress)
	{ //not allowed to use holdables while in a private duel.
		return 0;
	}

	if (!forcedUse)
	{
		forcedUse = bg_itemlist[ps->stats[STAT_HOLDABLE_ITEM]].giTag;
	}

	if (!BG_IsItemSelectable(ps, forcedUse))
	{
		return 0;
	}

	switch (forcedUse)
	{
	case HI_MEDPAC:
	case HI_MEDPAC_BIG:
		if (ps->stats[STAT_HEALTH] >= ps->stats[STAT_MAX_HEALTH])
		{
			return 0;
		}
		if (ps->stats[STAT_HEALTH] <= 0 ||
			(ps->eFlags & EF_DEAD))
		{
			return 0;
		}

		return 1;
	case HI_SEEKER:
		if (ps->eFlags & EF_SEEKERDRONE)
		{
			PM_AddEventWithParm(EV_ITEMUSEFAIL, SEEKER_ALREADYDEPLOYED);
			return 0;
		}

		return 1;
	case HI_SENTRY_GUN:
		if (ps->fd.sentryDeployed)
		{
			PM_AddEventWithParm(EV_ITEMUSEFAIL, SENTRY_ALREADYPLACED);
			return 0;
		}

		yawonly[ROLL] = 0;
		yawonly[PITCH] = 0;
		yawonly[YAW] = ps->viewangles[YAW];

		VectorSet( mins, -8, -8, 0 );
		VectorSet( maxs, 8, 8, 24 );

		AngleVectors(yawonly, fwd, NULL, NULL);

		fwdorg[0] = ps->origin[0] + fwd[0]*64;
		fwdorg[1] = ps->origin[1] + fwd[1]*64;
		fwdorg[2] = ps->origin[2] + fwd[2]*64;

		trtest[0] = fwdorg[0] + fwd[0]*16;
		trtest[1] = fwdorg[1] + fwd[1]*16;
		trtest[2] = fwdorg[2] + fwd[2]*16;

		pm->trace(&tr, ps->origin, mins, maxs, trtest, ps->clientNum, MASK_PLAYERSOLID);

		if ((tr.fraction != 1 && tr.entityNum != ps->clientNum) || tr.startsolid || tr.allsolid)
		{
			PM_AddEventWithParm(EV_ITEMUSEFAIL, SENTRY_NOROOM);
			return 0;
		}

		return 1;
	case HI_SHIELD:
		mins[0] = -8;
		mins[1] = -8;
		mins[2] = 0;

		maxs[0] = 8;
		maxs[1] = 8;
		maxs[2] = 8;

		AngleVectors (ps->viewangles, fwd, NULL, NULL);
		fwd[2] = 0;
		VectorMA(ps->origin, 64, fwd, dest);
		pm->trace(&tr, ps->origin, mins, maxs, dest, ps->clientNum, MASK_SHOT );
		if (tr.fraction > 0.9 && !tr.startsolid && !tr.allsolid)
		{
			VectorCopy(tr.endpos, pos);
			VectorSet( dest, pos[0], pos[1], pos[2] - 4096 );
			pm->trace( &tr, pos, mins, maxs, dest, ps->clientNum, MASK_SOLID );
			if ( !tr.startsolid && !tr.allsolid )
			{
				return 1;
			}
		}
		PM_AddEventWithParm(EV_ITEMUSEFAIL, SHIELD_NOROOM);
		return 0;
	case HI_JETPACK: //check for stuff here?
		return 1;
	case HI_HEALTHDISP:
		return 1;
	case HI_AMMODISP:
		return 1;
	case HI_EWEB:
		return 1;
	case HI_CLOAK: //check for stuff here?
		return 1;
	default:
		return 1;
	}
}

//cheesy vehicle weapon hackery
qboolean PM_CanSetWeaponAnims(void)
{
    if (pm->ps->m_iVehicleNum)
	{
		return qfalse;
	}

	return qtrue;
}

//perform player anim overrides while on vehicle.
extern int PM_irand_timesync(int val1, int val2);
void PM_VehicleWeaponAnimate(void)
{
	bgEntity_t *veh = pm_entVeh;
	Vehicle_t *pVeh;
	int iFlags = 0, Anim = -1;

	if (!veh ||
		!veh->m_pVehicle ||
		!veh->m_pVehicle->m_pPilot ||
		!veh->m_pVehicle->m_pPilot->playerState ||
		pm->ps->clientNum != veh->m_pVehicle->m_pPilot->playerState->clientNum)
	{ //make sure the vehicle exists, and its pilot is this player
		return;
	}

	pVeh = veh->m_pVehicle;

	if (pVeh->m_pVehicleInfo->type == VH_WALKER ||
		pVeh->m_pVehicleInfo->type == VH_FIGHTER)
	{ //slightly hacky I guess, but whatever.
		return;
	}
backAgain:
	// If they're firing, play the right fire animation.
	if ( pm->cmd.buttons & ( BUTTON_ATTACK | BUTTON_ALT_ATTACK ) )
	{
		iFlags = SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD;

		switch ( pm->ps->weapon )
		{
			case WP_SABER:
				if ( pm->cmd.buttons & BUTTON_ALT_ATTACK )
				{ //don't do anything.. I guess.
					pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
					goto backAgain;
				}
				// If we're already in an attack animation, leave (let it continue).
				if (pm->ps->torsoTimer <= 0)
				{ //we'll be starting a new attack
					PM_AddEvent(EV_SABER_ATTACK);
				}

				//just set it to something so we have a proper trail. This is a stupid
				//hack (much like the rest of this function)
				pm->ps->saberMove = LS_R_TL2BR;

				if ( pm->ps->torsoTimer > 0 && (pm->ps->torsoAnim == BOTH_VS_ATR_S ||
						pm->ps->torsoAnim == BOTH_VS_ATL_S) )
				{
					/*
					//FIXME: no need to even call the PM_SetAnim at all in this case
					Anim = (animNumber_t)pm->ps->torsoAnim;
					iFlags = SETANIM_FLAG_NORMAL;
					break;
					*/
					return;
				}

				// Start the attack.
				if ( pm->cmd.rightmove > 0 )	//right side attack
				{
					Anim = BOTH_VS_ATR_S;
				}
				else if ( pm->cmd.rightmove < 0 )	//left-side attack
				{
					Anim = BOTH_VS_ATL_S;
				}
				else	//random
				{
					//FIXME: alternate back and forth or auto-aim?
					//if ( !Q_irand( 0, 1 ) )
					if (!PM_irand_timesync(0, 1))
					{
						Anim = BOTH_VS_ATR_S;
					}
					else
					{
						Anim = BOTH_VS_ATL_S;
					}
				}

				if (pm->ps->torsoTimer <= 0)
				{ //restart the anim if we are already in it (and finished)
					iFlags |= SETANIM_FLAG_RESTART;
				}
				break;

			case WP_BLASTER:
				// Override the shoot anim.
				if ( pm->ps->torsoAnim == BOTH_ATTACK3 )
				{
					if ( pm->cmd.rightmove > 0 )			//right side attack
					{
						Anim = BOTH_VS_ATR_G;
					}
					else if ( pm->cmd.rightmove < 0 )	//left side
					{
						Anim = BOTH_VS_ATL_G;
					}
					else	//frontal
					{
						Anim = BOTH_VS_ATF_G;
					}
				}
				break;

			default:
				Anim = BOTH_VS_IDLE;
				break;
		}
	}
	else if (veh->playerState && veh->playerState->speed < 0 &&
		pVeh->m_pVehicleInfo->type == VH_ANIMAL)
	{ //tauntaun is going backwards
		Anim = BOTH_VT_WALK_REV;
	}
	else if (veh->playerState && veh->playerState->speed < 0 &&
		pVeh->m_pVehicleInfo->type == VH_SPEEDER)
	{ //speeder is going backwards
		Anim = BOTH_VS_REV;
	}
	// They're not firing so play the Idle for the weapon.
	else
	{
		iFlags = SETANIM_FLAG_NORMAL;

		switch ( pm->ps->weapon )
		{
			case WP_SABER:
				if ( BG_SabersOff( pm->ps ) )
				{ //saber holstered, normal idle
					Anim = BOTH_VS_IDLE;
				}
				// In the Air.
				//else if ( pVeh->m_ulFlags & VEH_FLYING )
				else if (0)
				{
					Anim = BOTH_VS_AIR_G;
					iFlags = SETANIM_FLAG_OVERRIDE;
				}
				// Crashing.
				//else if ( pVeh->m_ulFlags & VEH_CRASHING )
				else if (0)
				{
					pVeh->m_ulFlags &= ~VEH_CRASHING;	// Remove the flag, we are doing the animation.
					Anim = BOTH_VS_LAND_SR;
					iFlags = SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD;
				}
				else
				{
					Anim = BOTH_VS_IDLE_SR;
				}
				break;

			case WP_BLASTER:
				// In the Air.
				//if ( pVeh->m_ulFlags & VEH_FLYING )
				if (0)
				{
					Anim = BOTH_VS_AIR_G;
					iFlags = SETANIM_FLAG_OVERRIDE;
				}
				// Crashing.
				//else if ( pVeh->m_ulFlags & VEH_CRASHING )
				else if (0)
				{
					pVeh->m_ulFlags &= ~VEH_CRASHING;	// Remove the flag, we are doing the animation.
					Anim = BOTH_VS_LAND_G;
					iFlags = SETANIM_FLAG_OVERRIDE | SETANIM_FLAG_HOLD;
				}
				else
				{
					Anim = BOTH_VS_IDLE_G;
				}
				break;

			default:
				Anim = BOTH_VS_IDLE;
				break;
		}
	}

	if (Anim != -1)
	{ //override it
		if (pVeh->m_pVehicleInfo->type == VH_ANIMAL)
		{ //agh.. remap anims for the tauntaun
			switch (Anim)
			{
			case BOTH_VS_IDLE:
				if (veh->playerState && veh->playerState->speed > 0)
				{
					if (veh->playerState->speed > pVeh->m_pVehicleInfo->speedMax)
					{ //turbo
						Anim = BOTH_VT_TURBO;
					}
					else
					{
						Anim = BOTH_VT_RUN_FWD;
					}
				}
				else
				{
					Anim = BOTH_VT_IDLE;
				}
				break;
			case BOTH_VS_ATR_S:
				Anim = BOTH_VT_ATR_S;
				break;
			case BOTH_VS_ATL_S:
				Anim = BOTH_VT_ATL_S;
				break;
			case BOTH_VS_ATR_G:
                Anim = BOTH_VT_ATR_G;
				break;
			case BOTH_VS_ATL_G:
				Anim = BOTH_VT_ATL_G;
				break;
			case BOTH_VS_ATF_G:
				Anim = BOTH_VT_ATF_G;
				break;
			case BOTH_VS_IDLE_SL:
				Anim = BOTH_VT_IDLE_S;
				break;
			case BOTH_VS_IDLE_SR:
				Anim = BOTH_VT_IDLE_S;
				break;
			case BOTH_VS_IDLE_G:
				Anim = BOTH_VT_IDLE_G;
				break;

			//should not happen for tauntaun:
			case BOTH_VS_AIR_G:
			case BOTH_VS_LAND_SL:
			case BOTH_VS_LAND_SR:
			case BOTH_VS_LAND_G:
				return;
			default:
				break;
			}
		}

		PM_SetAnim(SETANIM_BOTH, Anim, iFlags);
	}
}

/*
==============
PM_Weapon

Generates weapon events and modifes the weapon counter
==============
*/
extern int PM_KickMoveForConditions(void);
static void PM_Weapon( void )
{
	int		addTime;
	int amount;
	int		killAfterItem = 0;
	bgEntity_t *veh = NULL;
	qboolean vehicleRocketLock = qfalse;

#ifdef _GAME
	if (pm->ps->clientNum >= MAX_CLIENTS &&
		pm->ps->weapon == WP_NONE &&
		pm->cmd.weapon == WP_NONE &&
		pm_entSelf)
	{ //npc with no weapon
		gentity_t *gent = (gentity_t *)pm_entSelf;
		if (gent->inuse && gent->client &&
			!gent->localAnimIndex)
		{ //humanoid
			pm->ps->torsoAnim = pm->ps->legsAnim;
			pm->ps->torsoTimer = pm->ps->legsTimer;
			return;
		}
	}
	else if (pm->ps->clientNum < MAX_CLIENTS) { //Human
		gentity_t* gent = (gentity_t*)pm_entSelf;

		if (gent && gent->inuse && gent->client) {
			if (gent->client->forcedFireMode == 2 && (pm->cmd.buttons & BUTTON_ATTACK)) {
				pm->cmd.buttons &= ~BUTTON_ATTACK;
				pm->cmd.buttons |= BUTTON_ALT_ATTACK;
			}
			else if (gent->client->forcedFireMode == 1 && (pm->cmd.buttons & BUTTON_ALT_ATTACK)) {
				pm->cmd.buttons |= BUTTON_ATTACK;
				pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			}
		}

	}
#endif

	if (!pm->ps->emplacedIndex &&
		pm->ps->weapon == WP_EMPLACED_GUN)
	{ //oh no!
		int i = 0;
		int weap = -1;

		while (i < WP_NUM_WEAPONS)
		{
			if ((pm->ps->stats[STAT_WEAPONS] & (1 << i)) && i != WP_NONE)
			{ //this one's good
				weap = i;
				break;
			}
			i++;
		}

		if (weap != -1)
		{
			pm->cmd.weapon = weap;
			pm->ps->weapon = weap;
			return;
		}
	}

	if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&&pm->ps->m_iVehicleNum)
	{ //riding a vehicle
		if ( (veh = pm_entVeh) &&
			(veh->m_pVehicle && (veh->m_pVehicle->m_pVehicleInfo->type == VH_WALKER || veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER) ) )
		{//riding a walker/fighter
			//keep saber off, do no weapon stuff at all!
			pm->ps->saberHolstered = 2;
#ifdef _GAME
			pm->cmd.buttons &= ~(BUTTON_ATTACK|BUTTON_ALT_ATTACK);
#else
			if ( g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[0].ID].fHoming
				||  g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[1].ID].fHoming )
			{//our vehicle uses a rocket launcher, so do the normal checks
				vehicleRocketLock = qtrue;
				pm->cmd.buttons &= ~BUTTON_ATTACK;
			}
			else
			{
				pm->cmd.buttons &= ~(BUTTON_ATTACK|BUTTON_ALT_ATTACK);
			}
#endif
		}
	}

	if (pm->ps->weapon != WP_DISRUPTOR //not using disruptor
		&& pm->ps->weapon != WP_ROCKET_LAUNCHER//not using rocket launcher
		&& pm->ps->weapon != WP_THERMAL//not using thermals
		&& !pm->ps->m_iVehicleNum )//not a vehicle or in a vehicle
	{ //check for exceeding max charge time if not using disruptor or rocket launcher or thermals
		if ( pm->ps->weaponstate == WEAPON_CHARGING_ALT )
		{
			int timeDif = (pm->cmd.serverTime - pm->ps->weaponChargeTime);

			if (timeDif > MAX_WEAPON_CHARGE_TIME)
			{
				pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			}
		}

		if ( pm->ps->weaponstate == WEAPON_CHARGING )
		{
			int timeDif = (pm->cmd.serverTime - pm->ps->weaponChargeTime);

			if (timeDif > MAX_WEAPON_CHARGE_TIME)
			{
				pm->cmd.buttons &= ~BUTTON_ATTACK;
			}
		}
	}

	if (pm->ps->forceHandExtend == HANDEXTEND_WEAPONREADY &&
		PM_CanSetWeaponAnims())
	{ //reset into weapon stance
		if (pm->ps->weapon != WP_SABER && pm->ps->weapon != WP_MELEE && !PM_IsRocketTrooper())
		{ //saber handles its own anims
			if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
			{
				//PM_StartTorsoAnim( TORSO_WEAPONREADY4 );
				PM_StartTorsoAnim( TORSO_RAISEWEAP1);
			}
			else
			{
				if (pm->ps->weapon == WP_EMPLACED_GUN)
				{
					PM_StartTorsoAnim( BOTH_GUNSIT1 );
				}
				else
				{
					//PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
					PM_StartTorsoAnim( TORSO_RAISEWEAP1);
				}
			}
		}

		//we now go into a weapon raise anim after every force hand extend.
		//this is so that my holster-view-weapon-when-hand-extend stuff works.
		pm->ps->weaponstate = WEAPON_RAISING;
#ifdef _GAME
	if (!pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_FAST_WEAPONSWITCH))
		pm->ps->weaponTime += 25;
	else
		pm->ps->weaponTime += 250;
#else
		pm->ps->weaponTime += 250;
#endif
		pm->ps->forceHandExtend = HANDEXTEND_NONE;
	}
	else if (pm->ps->forceHandExtend != HANDEXTEND_NONE)
	{ //nothing else should be allowed to happen during this time, including weapon fire
		int desiredAnim = 0;
		qboolean seperateOnTorso = qfalse;
		qboolean playFullBody = qfalse;
		int desiredOnTorso = 0;

		switch(pm->ps->forceHandExtend)
		{
		case HANDEXTEND_FORCEPUSH:
			desiredAnim = BOTH_FORCEPUSH;
			break;
		case HANDEXTEND_FORCEPULL:
			desiredAnim = BOTH_FORCEPULL;
			break;
		case HANDEXTEND_FORCE_HOLD:
			if ( (pm->ps->fd.forcePowersActive&(1<<FP_GRIP)) )
			{//gripping
				desiredAnim = BOTH_FORCEGRIP_HOLD;
			}
			else if ( (pm->ps->fd.forcePowersActive&(1<<FP_LIGHTNING)) )
			{//lightning
				if ( pm->ps->weapon == WP_MELEE
					&& pm->ps->activeForcePass > FORCE_LEVEL_2 )
				{//2-handed lightning
					desiredAnim = BOTH_FORCE_2HANDEDLIGHTNING_HOLD;
				}
				else
				{
					desiredAnim = BOTH_FORCELIGHTNING_HOLD;
				}
			}
			else if ( (pm->ps->fd.forcePowersActive&(1<<FP_DRAIN)) )
			{//draining
				desiredAnim = BOTH_FORCEGRIP_HOLD;
			}
			else
			{//???
				desiredAnim = BOTH_FORCEGRIP_HOLD;
			}
			break;
		case HANDEXTEND_SABERPULL:
			desiredAnim = BOTH_SABERPULL;
			break;
		case HANDEXTEND_CHOKE:
			desiredAnim = BOTH_CHOKE3; //left-handed choke
			break;
		case HANDEXTEND_DODGE:
			desiredAnim = pm->ps->forceDodgeAnim;
			break;
		case HANDEXTEND_KNOCKDOWN:
			if (pm->ps->forceDodgeAnim)
			{
				if (pm->ps->forceDodgeAnim > 4)
				{ //this means that we want to play a sepereate anim on the torso
					int originalDAnim = pm->ps->forceDodgeAnim-8; //-8 is the original legs anim
					if (originalDAnim == 2)
					{
						desiredAnim = BOTH_FORCE_GETUP_B1;
					}
					else if (originalDAnim == 3)
					{
						desiredAnim = BOTH_FORCE_GETUP_B3;
					}
					else
					{
						desiredAnim = BOTH_GETUP1;
					}

					//now specify the torso anim
					seperateOnTorso = qtrue;
					desiredOnTorso = BOTH_FORCEPUSH;
				}
				else if (pm->ps->forceDodgeAnim == 2)
				{
					desiredAnim = BOTH_FORCE_GETUP_B1;
				}
				else if (pm->ps->forceDodgeAnim == 3)
				{
					desiredAnim = BOTH_FORCE_GETUP_B3;
				}
				else
				{
					desiredAnim = BOTH_GETUP1;
				}
			}
			else
			{
				desiredAnim = BOTH_KNOCKDOWN1;
			}
			break;
		case HANDEXTEND_DUELCHALLENGE:
			desiredAnim = BOTH_ENGAGETAUNT;
			break;
		case HANDEXTEND_TAUNT:
			desiredAnim = pm->ps->forceDodgeAnim;
			if ( desiredAnim != BOTH_ENGAGETAUNT
				&& VectorCompare( pm->ps->velocity, vec3_origin )
				&& pm->ps->groundEntityNum != ENTITYNUM_NONE )
			{
				playFullBody = qtrue;
			}
			break;
		case HANDEXTEND_PRETHROW:
			desiredAnim = BOTH_A3_TL_BR;
			playFullBody = qtrue;
			break;
		case HANDEXTEND_POSTTHROW:
			desiredAnim = BOTH_D3_TL___;
			playFullBody = qtrue;
			break;
		case HANDEXTEND_PRETHROWN:
			desiredAnim = BOTH_KNEES1;
			playFullBody = qtrue;
			break;
		case HANDEXTEND_POSTTHROWN:
			if (pm->ps->forceDodgeAnim)
			{
				desiredAnim = BOTH_FORCE_GETUP_F2;
			}
			else
			{
				desiredAnim = BOTH_KNOCKDOWN5;
			}
			playFullBody = qtrue;
			break;
		case HANDEXTEND_DRAGGING:
			desiredAnim = BOTH_B1_BL___;
			break;
		case HANDEXTEND_JEDITAUNT:
			desiredAnim = BOTH_GESTURE1;
			//playFullBody = qtrue;
			break;
			//Hmm... maybe use these, too?
			//BOTH_FORCEHEAL_QUICK //quick heal (SP level 2 & 3)
			//BOTH_MINDTRICK1 // wave (maybe for mind trick 2 & 3 - whole area, and for force seeing)
			//BOTH_MINDTRICK2 // tap (maybe for mind trick 1 - one person)
			//BOTH_FORCEGRIP_START //start grip
			//BOTH_FORCEGRIP_HOLD //hold grip
			//BOTH_FORCEGRIP_RELEASE //release grip
			//BOTH_FORCELIGHTNING //quick lightning burst (level 1)
			//BOTH_FORCELIGHTNING_START //start lightning
			//BOTH_FORCELIGHTNING_HOLD //hold lightning
			//BOTH_FORCELIGHTNING_RELEASE //release lightning
		default:
			desiredAnim = BOTH_FORCEPUSH;
			break;
		}

		if (!seperateOnTorso)
		{ //of seperateOnTorso, handle it after setting the legs
			PM_SetAnim(SETANIM_TORSO, desiredAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			pm->ps->torsoTimer = 1;
		}

		if (playFullBody)
		{ //sorry if all these exceptions are getting confusing. This one just means play on both legs and torso.
			PM_SetAnim(SETANIM_BOTH, desiredAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
			pm->ps->legsTimer = pm->ps->torsoTimer = 1;
		}
		else if (pm->ps->forceHandExtend == HANDEXTEND_DODGE || pm->ps->forceHandExtend == HANDEXTEND_KNOCKDOWN ||
			(pm->ps->forceHandExtend == HANDEXTEND_CHOKE && pm->ps->groundEntityNum == ENTITYNUM_NONE) )
		{ //special case, play dodge anim on whole body, choke anim too if off ground
			if (seperateOnTorso)
			{
				PM_SetAnim(SETANIM_LEGS, desiredAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
				pm->ps->legsTimer = 1;

				PM_SetAnim(SETANIM_TORSO, desiredOnTorso, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
				pm->ps->torsoTimer = 1;
			}
			else
			{
				PM_SetAnim(SETANIM_LEGS, desiredAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
				pm->ps->legsTimer = 1;
			}
		}

		return;
	}

	if (BG_InSpecialJump(pm->ps->legsAnim) ||
		BG_InRoll(pm->ps, pm->ps->legsAnim) ||
		PM_InRollComplete(pm->ps, pm->ps->legsAnim))
	{
		/*
		if (pm->cmd.weapon != WP_MELEE &&
			pm->ps->weapon != WP_MELEE &&
			(pm->ps->stats[STAT_WEAPONS] & (1<<WP_SABER)))
		{ //it's alright also if we are melee
			pm->cmd.weapon = WP_SABER;
			pm->ps->weapon = WP_SABER;
		}
		*/
		if (pm->ps->weaponTime < pm->ps->legsTimer)
		{
			pm->ps->weaponTime = pm->ps->legsTimer;
		}
	}

if (pm->ps->duelInProgress)
	{
#ifdef _CGAME
		if (cg_dueltypes[pm->ps->clientNum] > 2) {
			if (cg_dueltypes[pm->ps->clientNum] == 20) {
			}
			else if (cg_dueltypes[pm->ps->clientNum] == 19) {
				pm->cmd.weapon = WP_STUN_BATON;
				pm->ps->weapon = WP_STUN_BATON;
			}
			else {
				pm->cmd.weapon = cg_dueltypes[pm->ps->clientNum] - 2; //gunduel 1
				pm->ps->weapon = cg_dueltypes[pm->ps->clientNum] - 2;
			}
		}
#else
		if (dueltypes[pm->ps->clientNum] > 2) {
			if (dueltypes[pm->ps->clientNum] == 20) {
			}
			else if (dueltypes[pm->ps->clientNum] == 19) {
				pm->cmd.weapon = WP_STUN_BATON;
				pm->ps->weapon = WP_STUN_BATON;
			}
			else {
				pm->cmd.weapon = dueltypes[pm->ps->clientNum] - 2;
				pm->ps->weapon = dueltypes[pm->ps->clientNum] - 2;
			}
		}
#endif
		else {//Japro - gun duels start
			pm->cmd.weapon = WP_SABER;
			pm->ps->weapon = WP_SABER;
		}

		if (pm->ps->duelTime >= pm->cmd.serverTime)//gun duel - why isnt this working?
		{
			pm->cmd.upmove = 0;
			pm->cmd.forwardmove = 0;
			pm->cmd.rightmove = 0;
		}
	}

	if (pm->ps->weapon == WP_SABER && pm->ps->saberMove != LS_READY && pm->ps->saberMove != LS_NONE)
	{
		pm->cmd.weapon = WP_SABER; //don't allow switching out mid-attack
	}

	if (pm->ps->weapon == WP_SABER)
	{
		//rww - we still need the item stuff, so we won't return immediately
		PM_WeaponLightsaber();
		killAfterItem = 1;
	}
	else if (pm->ps->weapon != WP_EMPLACED_GUN)
	{
		pm->ps->saberHolstered = 0;
	}

	if (PM_CanSetWeaponAnims())
	{
		if (pm->ps->weapon == WP_THERMAL ||
			pm->ps->weapon == WP_TRIP_MINE ||
			pm->ps->weapon == WP_DET_PACK)
		{
			if (pm->ps->weapon == WP_THERMAL)
			{
				if ((pm->ps->torsoAnim) == WeaponAttackAnim[pm->ps->weapon] &&
					(pm->ps->weaponTime-200) <= 0)
				{
					PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
				}
			}
			else
			{
				if ((pm->ps->torsoAnim) == WeaponAttackAnim[pm->ps->weapon] &&
					(pm->ps->weaponTime-700) <= 0)
				{
					PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
				}
			}
		}
	}

	// don't allow attack until all buttons are up
	if ( pm->ps->pm_flags & PMF_RESPAWNED ) {
		return;
	}

	// ignore if spectator
	if ( pm->ps->clientNum < MAX_CLIENTS && pm->ps->persistant[PERS_TEAM] == TEAM_SPECTATOR ) {
			return;
	}

	// check for dead player
	if ( pm->ps->stats[STAT_HEALTH] <= 0 ) {
		pm->ps->weapon = WP_NONE;
		return;
	}

	// check for item using
	if ( pm->cmd.buttons & BUTTON_USE_HOLDABLE ) {
		// fix: rocket lock bug, one of many...
		BG_ClearRocketLock( pm->ps );

		if ( ! ( pm->ps->pm_flags & PMF_USE_ITEM_HELD ) ) {

			if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
				&& pm->ps->m_iVehicleNum)
			{//riding a vehicle, can't use holdable items, this button operates as the weapon link/unlink toggle
				return;
			}

			if (!pm->ps->stats[STAT_HOLDABLE_ITEM])
			{
				return;
			}

			if (!PM_ItemUsable(pm->ps, 0))
			{
				pm->ps->pm_flags |= PMF_USE_ITEM_HELD;
				return;
			}
			else
			{
				if (pm->ps->stats[STAT_HOLDABLE_ITEMS] & (1 << bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag))
				{
					if (bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_BINOCULARS &&
						bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_JETPACK &&
						bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_HEALTHDISP &&
						bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_AMMODISP &&
						bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_CLOAK &&
						bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_EWEB)
					{ //never use up the binoculars or jetpack or dispensers or cloak or ...
						pm->ps->stats[STAT_HOLDABLE_ITEMS] -= (1 << bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag);
					}
				}
				else
				{
					return; //this should not happen...
				}

				pm->ps->pm_flags |= PMF_USE_ITEM_HELD;
				PM_AddEvent( EV_USE_ITEM0 + bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag );

				if (bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_BINOCULARS &&
					bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_JETPACK &&
					bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_HEALTHDISP &&
					bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_AMMODISP &&
					bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_CLOAK &&
					bg_itemlist[pm->ps->stats[STAT_HOLDABLE_ITEM]].giTag != HI_EWEB)
				{
					pm->ps->stats[STAT_HOLDABLE_ITEM] = 0;
					BG_CycleInven(pm->ps, 1);
				}
			}
			return;
		}
	} else {
		pm->ps->pm_flags &= ~PMF_USE_ITEM_HELD;
	}

	/*
	if (pm->ps->weapon == WP_SABER || pm->ps->weapon == WP_MELEE)
	{ //we can't toggle zoom while using saber (for obvious reasons) so make sure it's always off
		pm->ps->zoomMode = 0;
		pm->ps->zoomFov = 0;
		pm->ps->zoomLocked = qfalse;
		pm->ps->zoomLockTime = 0;
	}
	*/

#if _GAME
	if (g_tweakWeapons.integer & WT_TRIBES) { //Chaingun overheat
#else
	if (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES) {
#endif
		if (pm->ps->clientNum < MAX_CLIENTS && (pm->ps->weapon == WP_BLASTER || pm->ps->weapon == WP_BRYAR_OLD) && !pm->ps->jetpackFuel)
			return;
	}


	if (killAfterItem)
	{
		return;
	}

	// make weapon function
	if ( pm->ps->weaponTime > 0 ) {
		pm->ps->weaponTime -= pml.msec;
	}
#if _GAME
#if _SPECIFICWEAPONTIME
	if (g_tweakWeapons.integer & WT_TRIBES) { //Bug where this doesnt get called if wp_saber is out? but maybe thats fine to limit nades if holding saber?
		int i;
		for (i = 0; i < MAX_WEAPONS; i++) {
			if (((gentity_t *)pm_entSelf)->client->specificWeaponTime[i] > 0)
				((gentity_t *)pm_entSelf)->client->specificWeaponTime[i] -= pml.msec;
		}
	}
#endif
#endif

	if (pm->ps->isJediMaster && pm->ps->emplacedIndex)
	{
		pm->ps->emplacedIndex = 0;
		pm->ps->saberHolstered = 0;
	}

	if (pm->ps->duelInProgress && pm->ps->emplacedIndex)
	{
		pm->ps->emplacedIndex = 0;
		pm->ps->saberHolstered = 0;
	}

	if (pm->ps->weapon == WP_EMPLACED_GUN && pm->ps->emplacedIndex)
	{
		pm->cmd.weapon = WP_EMPLACED_GUN; //No switch for you!
		PM_StartTorsoAnim( BOTH_GUNSIT1 );
	}

	if (pm->ps->isJediMaster || (pm->ps->duelInProgress && !pm->ps->stats[STAT_RACEMODE]) || pm->ps->trueJedi) //_coop uses duelinprogress for semi isolation but we dont want it to actually do any of this stuff
	{
#ifdef _CGAME
		if (cg_dueltypes[pm->ps->clientNum] > 2) {
			if (cg_dueltypes[pm->ps->clientNum] == 20) {
			}
			else if (cg_dueltypes[pm->ps->clientNum] == 19) {
				pm->cmd.weapon = WP_STUN_BATON;
				pm->ps->weapon = WP_STUN_BATON;
			}
			else {
				pm->cmd.weapon = cg_dueltypes[pm->ps->clientNum] - 2; //gunduel 2
				pm->ps->weapon = cg_dueltypes[pm->ps->clientNum] - 2;
			}
		}
#else
		if (dueltypes[pm->ps->clientNum] > 2) {
			if (dueltypes[pm->ps->clientNum] == 20) {
			}
			else if (dueltypes[pm->ps->clientNum] == 19) {
				pm->cmd.weapon = WP_STUN_BATON;
				pm->ps->weapon = WP_STUN_BATON;
			}
			else {
				pm->cmd.weapon = dueltypes[pm->ps->clientNum] - 2;
				pm->ps->weapon = dueltypes[pm->ps->clientNum] - 2;
			}
		}
#endif
		else {
#if _CGAME
			if (cgs.serverMod != SVMOD_LMD) {
#endif
				pm->cmd.weapon = WP_SABER;
				pm->ps->weapon = WP_SABER;
#if _CGAME
			}
#endif
		}

		if (pm->ps->isJediMaster || pm->ps->trueJedi)
		{
#if _CGAME
			if (cgs.serverMod != SVMOD_LMD)
#endif
				pm->ps->stats[STAT_WEAPONS] = (1 << WP_SABER);
		}
	}

	amount = weaponData[pm->ps->weapon].energyPerShot;

	// take an ammo away if not infinite
	if ( pm->ps->weapon != WP_NONE &&
		pm->ps->weapon == pm->cmd.weapon &&
#ifdef _GAME
		!(g_tweakWeapons.integer & WT_INFINITE_AMMO) &&
#endif
		(pm->ps->weaponTime <= 0 || pm->ps->weaponstate != WEAPON_FIRING) )
	{
		if ( pm->ps->clientNum < MAX_CLIENTS && pm->ps->ammo[ weaponData[pm->ps->weapon].ammoIndex ] != -1 )
		{
			// enough energy to fire this weapon?
			if (pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] < weaponData[pm->ps->weapon].energyPerShot &&
				pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] < weaponData[pm->ps->weapon].altEnergyPerShot
#ifdef _GAME
				&& (!(g_tweakWeapons.integer & WT_STAKE_GUN) || (pm->ps->weapon != WP_FLECHETTE)) //I guess we have to make the stake gun
#endif
				)
			{ //the weapon is out of ammo essentially because it cannot fire primary or secondary, so do the switch
			  //regardless of if the player is attacking or not
				PM_AddEventWithParm( EV_NOAMMO, WP_NUM_WEAPONS+pm->ps->weapon );

				if (pm->ps->weaponTime < 500)
				{
					pm->ps->weaponTime += 500;
				}
				return;
			}

			if (pm->ps->weapon == WP_DET_PACK && !pm->ps->hasDetPackPlanted && pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] < 1)
			{
				PM_AddEventWithParm( EV_NOAMMO, WP_NUM_WEAPONS+pm->ps->weapon );

				if (pm->ps->weaponTime < 500)
				{
					pm->ps->weaponTime += 500;
				}
				return;
			}
		}
	}

	// check for weapon change
	// can't change if weapon is firing, but can change
	// again if lowering or raising
#if _GAME
#if _SPECIFICWEAPONTIME
	if ((g_tweakWeapons.integer & WT_TRIBES) && !pm->ps->stats[STAT_RACEMODE]) {
		if (pm->ps->weapon != pm->cmd.weapon) {
			if (((gentity_t *)pm_entSelf)->client->specificWeaponTime[pm->ps->weapon] <= 0)
			PM_BeginWeaponChange(pm->cmd.weapon);
		}
	}
 	else
#endif
#endif
	if ( pm->ps->weaponTime <= 0 || pm->ps->weaponstate != WEAPON_FIRING ) {
		if ( pm->ps->weapon != pm->cmd.weapon ) {
			PM_BeginWeaponChange( pm->cmd.weapon );
		}
	}
	
#if _GAME
#if _SPECIFICWEAPONTIME
	if ((g_tweakWeapons.integer & WT_TRIBES) && !pm->ps->stats[STAT_RACEMODE])
	{
		if (((gentity_t *)pm_entSelf)->client->specificWeaponTime[pm->ps->weapon] > 0) {
			if (pm->ps->weapon != pm->cmd.weapon) {
				PM_FinishWeaponChange();
			}
			return;
		}
	}
	else
#endif
#endif
	if (pm->ps->weaponTime > 0) {
		//This is the saddest hack we have seen yet
		if (pm->ps->stats[STAT_RACEMODE] && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_JETPACK && pm->ps->weapon == WP_DET_PACK && pm->ps->hasDetPackPlanted && /*!(pm->cmd.buttons & BUTTON_ATTACK) &&*/ pm->cmd.buttons & BUTTON_ALT_ATTACK) {
		}
		else {
			return;
		}
	}

	if (pm->ps->weapon == WP_DISRUPTOR &&
		pm->ps->zoomMode == 1)
	{
		if (pm_cancelOutZoom)
		{
			pm->ps->zoomMode = 0;
			pm->ps->zoomFov = 0;
			pm->ps->zoomLocked = qfalse;
			pm->ps->zoomLockTime = 0;
			PM_AddEvent( EV_DISRUPTOR_ZOOMSOUND );
			return;
		}

		if (pm->cmd.forwardmove ||
			pm->cmd.rightmove ||
			pm->cmd.upmove > 0)
		{
			return;
		}
	}

	// change weapon if time
	if ( pm->ps->weaponstate == WEAPON_DROPPING ) {
		PM_FinishWeaponChange();
		return;
	}

	if ( pm->ps->weaponstate == WEAPON_RAISING ) {
		pm->ps->weaponstate = WEAPON_READY;
		if (PM_CanSetWeaponAnims())
		{
			if ( pm->ps->weapon == WP_SABER )
			{
				PM_StartTorsoAnim( PM_GetSaberStance() );
			}
			else if (pm->ps->weapon == WP_MELEE || PM_IsRocketTrooper())
			{
				PM_StartTorsoAnim( pm->ps->legsAnim );
			}
			else
			{
				if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
				{
					PM_StartTorsoAnim( TORSO_WEAPONREADY4 );
				}
				else
				{
					if (pm->ps->weapon == WP_EMPLACED_GUN)
					{
						PM_StartTorsoAnim( BOTH_GUNSIT1 );
					}
					else
					{
						PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
					}
				}
			}
		}
		return;
	}

	if (PM_CanSetWeaponAnims() &&
		!PM_IsRocketTrooper() &&
		pm->ps->weaponstate == WEAPON_READY && pm->ps->weaponTime <= 0 &&
		(pm->ps->weapon >= WP_BRYAR_PISTOL || pm->ps->weapon == WP_STUN_BATON) &&
		pm->ps->torsoTimer <= 0 &&
		(pm->ps->torsoAnim) != WeaponReadyAnim[pm->ps->weapon] &&
		pm->ps->torsoAnim != TORSO_WEAPONIDLE3 &&
		pm->ps->weapon != WP_EMPLACED_GUN)
	{
		PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
	}
	else if (PM_CanSetWeaponAnims() &&
		pm->ps->weapon == WP_MELEE)
	{
		if (pm->ps->weaponTime <= 0 &&
			pm->ps->forceHandExtend == HANDEXTEND_NONE)
		{
			int desTAnim = pm->ps->legsAnim;

			if (desTAnim == BOTH_STAND1 ||
				desTAnim == BOTH_STAND2)
			{ //remap the standard standing anims for melee stance
				desTAnim = BOTH_STAND6;
			}

			if (!(pm->cmd.buttons & (BUTTON_ATTACK|BUTTON_ALT_ATTACK)))
			{ //don't do this while holding attack
				if (pm->ps->torsoAnim != desTAnim)
				{
					PM_StartTorsoAnim( desTAnim );
				}
			}
		}
	}
	else if (PM_CanSetWeaponAnims() && PM_IsRocketTrooper())
	{
		int desTAnim = pm->ps->legsAnim;

		if (!(pm->cmd.buttons & (BUTTON_ATTACK|BUTTON_ALT_ATTACK)))
		{ //don't do this while holding attack
			if (pm->ps->torsoAnim != desTAnim)
			{
				PM_StartTorsoAnim( desTAnim );
			}
		}
	}

	if (((pm->ps->torsoAnim) == TORSO_WEAPONREADY4 ||
		(pm->ps->torsoAnim) == BOTH_ATTACK4) &&
		(pm->ps->weapon != WP_DISRUPTOR || pm->ps->zoomMode != 1))
	{
		if (pm->ps->weapon == WP_EMPLACED_GUN)
		{
			PM_StartTorsoAnim( BOTH_GUNSIT1 );
		}
		else if (PM_CanSetWeaponAnims())
		{
			PM_StartTorsoAnim( WeaponReadyAnim[pm->ps->weapon] );
		}
	}
	else if (((pm->ps->torsoAnim) != TORSO_WEAPONREADY4 &&
		(pm->ps->torsoAnim) != BOTH_ATTACK4) &&
		PM_CanSetWeaponAnims() &&
		(pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1))
	{
		PM_StartTorsoAnim( TORSO_WEAPONREADY4 );
	}

	if (pm->ps->clientNum >= MAX_CLIENTS &&
		pm_entSelf &&
		pm_entSelf->s.NPC_class == CLASS_VEHICLE)
	{//we are a vehicle
		veh = pm_entSelf;
	}
	if ( veh
		&& veh->m_pVehicle )
	{
		if ( g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[0].ID].fHoming
			|| g_vehWeaponInfo[veh->m_pVehicle->m_pVehicleInfo->weapon[1].ID].fHoming )
		{//don't clear the rocket locking ever?
			vehicleRocketLock = qtrue;
		}
	}

	if ( !vehicleRocketLock )
	{
		if (pm->ps->weapon != WP_ROCKET_LAUNCHER)
		{
			if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
				&&pm->ps->m_iVehicleNum)
			{//riding a vehicle, the vehicle will tell me my rocketlock stuff...
			}
			else
			{
				pm->ps->rocketLockIndex = ENTITYNUM_NONE;
				pm->ps->rocketLockTime = 0;
				pm->ps->rocketTargetTime = 0;
			}
		}
	}

	if ( PM_DoChargedWeapons(vehicleRocketLock, veh))
	{
		// In some cases the charged weapon code may want us to short circuit the rest of the firing code
		return;
	}

	// check for fire
	if ( ! (pm->cmd.buttons & (BUTTON_ATTACK|BUTTON_ALT_ATTACK)))
	{
		pm->ps->weaponTime = 0;
		pm->ps->weaponstate = WEAPON_READY;
		return;
	}

	if (pm->ps->weapon == WP_EMPLACED_GUN)
	{
		addTime = weaponData[pm->ps->weapon].fireTime;
		pm->ps->weaponTime += addTime;
		if ( (pm->cmd.buttons & BUTTON_ALT_ATTACK) )
		{
			PM_AddEvent( EV_ALT_FIRE );
		}
		else
		{
			PM_AddEvent( EV_FIRE_WEAPON );
		}
		return;
	}
	else if (pm->ps->m_iVehicleNum
		&& pm_entSelf->s.NPC_class==CLASS_VEHICLE)
	{ //a vehicle NPC that has a pilot
		pm->ps->weaponstate = WEAPON_FIRING;
		pm->ps->weaponTime += 100;
#ifdef _GAME //hack, only do it game-side. vehicle weapons don't really need predicting I suppose.
		if ( (pm->cmd.buttons & BUTTON_ALT_ATTACK) )
		{
			G_CheapWeaponFire(pm->ps->clientNum, EV_ALT_FIRE);
		}
		else
		{
			G_CheapWeaponFire(pm->ps->clientNum, EV_FIRE_WEAPON);
		}
#endif
		return;
	}

	if (pm->ps->weapon == WP_DISRUPTOR &&
		(pm->cmd.buttons & BUTTON_ALT_ATTACK) &&
		!pm->ps->zoomLocked)
	{
		return;
	}

	if (pm->ps->weapon == WP_DISRUPTOR &&
		(pm->cmd.buttons & BUTTON_ALT_ATTACK) &&
		pm->ps->zoomMode == 2)
	{ //can't use disruptor secondary while zoomed binoculars
		return;
	}

	if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
	{
		PM_StartTorsoAnim( BOTH_ATTACK4 );
	}
	else if (pm->ps->weapon == WP_MELEE)
	{ //special anims for standard melee attacks
		//Alternate between punches and use the anim length as weapon time.
		if (!pm->ps->m_iVehicleNum)
		{ //if riding a vehicle don't do this stuff at all
			if (pm->debugMelee &&
				(pm->cmd.buttons & BUTTON_ATTACK) &&
				(pm->cmd.buttons & BUTTON_ALT_ATTACK))
			{ //ok, grapple time
#if 0 //eh, I want to try turning the saber off, but can't do that reliably for prediction..
				qboolean icandoit = qtrue;
				if (pm->ps->weaponTime > 0)
				{ //weapon busy
					icandoit = qfalse;
				}
				if (pm->ps->forceHandExtend != HANDEXTEND_NONE)
				{ //force power or knockdown or something
					icandoit = qfalse;
				}
				if (pm->ps->weapon != WP_SABER && pm->ps->weapon != WP_MELEE)
				{
					icandoit = qfalse;
				}

				if (icandoit)
				{
					//G_SetAnim(ent, &ent->client->pers.cmd, SETANIM_BOTH, BOTH_KYLE_GRAB, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
					PM_SetAnim(SETANIM_BOTH, BOTH_KYLE_GRAB, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
					if (pm->ps->torsoAnim == BOTH_KYLE_GRAB)
					{ //providing the anim set succeeded..
						pm->ps->torsoTimer += 500; //make the hand stick out a little longer than it normally would
						if (pm->ps->legsAnim == pm->ps->torsoAnim)
						{
							pm->ps->legsTimer = pm->ps->torsoTimer;
						}
						pm->ps->weaponTime = pm->ps->torsoTimer;
						return;
					}
				}
#else
	#ifdef _GAME
				if (pm_entSelf)
				{
					if (TryGrapple((gentity_t *)pm_entSelf))
					{
						return;
					}
				}
	#else
				return;
	#endif
#endif
			}
			else if (pm->debugMelee &&
				(pm->cmd.buttons & BUTTON_ALT_ATTACK))
			{ //kicks
				if (!BG_KickingAnim(pm->ps->torsoAnim) &&
					!BG_KickingAnim(pm->ps->legsAnim))
				{
					int kickMove = PM_KickMoveForConditions();
					if (kickMove == LS_HILT_BASH)
					{ //yeah.. no hilt to bash with!
						kickMove = LS_KICK_F;
					}

					if (kickMove != -1)
					{
						if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
						{//if in air, convert kick to an in-air kick
							float gDist = PM_GroundDistance();
							//let's only allow air kicks if a certain distance from the ground
							//it's silly to be able to do them right as you land.
							//also looks wrong to transition from a non-complete flip anim...
							if ((!BG_FlippingAnim( pm->ps->legsAnim ) || pm->ps->legsTimer <= 0) &&
								gDist > 64.0f && //strict minimum
								gDist > (-pm->ps->velocity[2])-64.0f //make sure we are high to ground relative to downward velocity as well
								)
							{
								switch ( kickMove )
								{
								case LS_KICK_F:
									kickMove = LS_KICK_F_AIR;
									break;
								case LS_KICK_B:
									kickMove = LS_KICK_B_AIR;
									break;
								case LS_KICK_R:
									kickMove = LS_KICK_R_AIR;
									break;
								case LS_KICK_L:
									kickMove = LS_KICK_L_AIR;
									break;
								default: //oh well, can't do any other kick move while in-air
									kickMove = -1;
									break;
								}
							}
							else
							{ //off ground, but too close to ground
								kickMove = -1;
							}
						}
					}

					if (kickMove != -1)
					{
						int kickAnim = saberMoveData[kickMove].animToUse;

						if (kickAnim != -1)
						{
							PM_SetAnim(SETANIM_BOTH, kickAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
							if (pm->ps->legsAnim == kickAnim)
							{
								pm->ps->weaponTime = pm->ps->legsTimer;
								return;
							}
						}
					}
				}

				//if got here then no move to do so put torso into leg idle or whatever
				if (pm->ps->torsoAnim != pm->ps->legsAnim)
				{
					PM_SetAnim(SETANIM_BOTH, pm->ps->legsAnim, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD);
				}
				pm->ps->weaponTime = 0;
				return;
			}
			else
			{ //just punch
				int desTAnim = BOTH_MELEE1;
				if (pm->ps->torsoAnim == BOTH_MELEE1)
				{
					desTAnim = BOTH_MELEE2;
				}
				PM_StartTorsoAnim( desTAnim );

				if (pm->ps->torsoAnim == desTAnim)
				{
					pm->ps->weaponTime = pm->ps->torsoTimer;
				}
			}
		}
	}
	else
	{
		PM_StartTorsoAnim( WeaponAttackAnim[pm->ps->weapon] );
	}

	if (pm->cmd.buttons & BUTTON_ALT_ATTACK)
	{
		amount = weaponData[pm->ps->weapon].altEnergyPerShot;
#ifdef _GAME
		if (pm->ps->stats[STAT_RACEMODE]) {
			if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_COOP_JKA)
				amount = 0;
			else if (pm->ps->weapon == WP_ROCKET_LAUNCHER)
				amount = 1;
		}
		else {
			if (g_tweakWeapons.integer & WT_INFINITE_AMMO)
				amount = 0;
			else if (pm->ps->weapon == WP_ROCKET_LAUNCHER && (g_tweakWeapons.integer & WT_TRIBES))
				amount = 1;
			else if (pm->ps->weapon == WP_FLECHETTE && g_tweakWeapons.integer & WT_STAKE_GUN)
				amount = 0;//Detonating stakes shouldnt take ammo
		}
#endif
	}
	else
	{
		amount = weaponData[pm->ps->weapon].energyPerShot;
#ifdef _GAME
		if (pm->ps->stats[STAT_RACEMODE]) {
			if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_COOP_JKA)
				amount = 0;
			else if (pm->ps->weapon == WP_ROCKET_LAUNCHER)
				amount = 1;
			else if (pm->ps->weapon == WP_DET_PACK)
				amount = 1;
		}
		else {
			if (g_tweakWeapons.integer & WT_INFINITE_AMMO)
				amount = 0;
			else if (pm->ps->weapon == WP_FLECHETTE && g_tweakWeapons.integer & WT_STAKE_GUN)
				amount = 10;//5 ammo per stake? eh
		}
#endif
	}

	pm->ps->weaponstate = WEAPON_FIRING;

	// take an ammo away if not infinite
	if ( pm->ps->clientNum < MAX_CLIENTS && pm->ps->ammo[ weaponData[pm->ps->weapon].ammoIndex ] != -1 )
	{
		// enough energy to fire this weapon?
		if ((pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] - amount) >= 0) {
				pm->ps->ammo[weaponData[pm->ps->weapon].ammoIndex] -= amount;
		}
		else	// Not enough energy
		{
			// Switch weapons
#ifdef _GAME
			if ((pm->ps->weapon != WP_DET_PACK || !pm->ps->hasDetPackPlanted) && (pm->ps->weapon != WP_FLECHETTE || !(g_tweakWeapons.integer & WT_STAKE_GUN)))
#else
			if (pm->ps->weapon != WP_DET_PACK || !pm->ps->hasDetPackPlanted)
#endif
			{
				PM_AddEventWithParm( EV_NOAMMO, WP_NUM_WEAPONS+pm->ps->weapon );
				if (pm->ps->weaponTime < 500)
				{
					pm->ps->weaponTime += 500;
				}
			}
			return;
		}
	}

	if (pm->cmd.buttons & BUTTON_ALT_ATTACK) {
		if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode != 1) {
			PM_AddEvent(EV_FIRE_WEAPON);
			addTime = weaponData[pm->ps->weapon].fireTime;
		}
		else {
			if (pm->ps->weapon != WP_MELEE || !pm->ps->m_iVehicleNum) { //do not fire melee events at all when on vehicle
				PM_AddEvent(EV_ALT_FIRE);
			}
			addTime = weaponData[pm->ps->weapon].altFireTime;
		}
	}
	else {
		if (pm->ps->weapon != WP_MELEE || !pm->ps->m_iVehicleNum) { //do not fire melee events at all when on vehicle
			PM_AddEvent(EV_FIRE_WEAPON);
		}
		addTime = weaponData[pm->ps->weapon].fireTime;
	}

	//Override firetimes
#if _GAME
	switch (pm->ps->weapon) {
		case WP_STUN_BATON:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && pm->ps->stats[STAT_RACEMODE] && !pm->ps->duelInProgress)
				addTime = 600;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && (g_tweakWeapons.integer & WT_STUN_SHOCKLANCE))
				addTime = 1500;
			else if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && (g_tweakWeapons.integer & WT_STUN_LG))
				addTime = 50;
			break;
		case WP_BRYAR_OLD:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 800;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 100;
			break;
		case WP_BRYAR_PISTOL:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1000;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1000;
			break;
		case WP_BLASTER:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && pm->ps->stats[STAT_RACEMODE])
				addTime = 100;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 125;
			else if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 75;
			break;
		case WP_DISRUPTOR:
			if (pm->ps->stats[STAT_RACEMODE] && !pm->ps->duelInProgress)
				addTime = 600;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && g_tweakWeapons.integer & WT_SLOW_SNIPER)//Sad hack to make instagib more playable
				addTime = 1500;
			break;
		case WP_BOWCASTER:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1050;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1050;
			break;
		case WP_REPEATER:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 2500;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 200;
			break;
		case WP_DEMP2:
			if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 750;
			break;
		case WP_FLECHETTE:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
			addTime = 800;
			break;
		case WP_ROCKET_LAUNCHER:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 3500;
			if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1050;
			break;
		case WP_THERMAL:
			if (!(pm->ps->stats[STAT_RACEMODE]) && ((g_tweakWeapons.integer & WT_IMPACT_NITRON) || (g_tweakWeapons.integer & WT_TRIBES)))
				addTime = 1500;
			break;
		case WP_DET_PACK:
			if (pm->gametype == GT_SIEGE)
				addTime *= 2;
			break;
		case WP_CONCUSSION:
			if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1400;
			else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (g_tweakWeapons.integer & WT_TRIBES))
				addTime = 1200;
			break;
		default:
			break;
	}
#else
	switch (pm->ps->weapon) {
	case WP_STUN_BATON:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && pm->ps->stats[STAT_RACEMODE] && !pm->ps->duelInProgress)
			addTime = 600;
		else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && (cgs.jcinfo & JAPRO_CINFO_SHOCKLANCE))
			addTime = 1500;
		else if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && (cgs.jcinfo & JAPRO_CINFO_LG))
			addTime = 50;
		break;
	case WP_BRYAR_OLD:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 800;
		else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 100;
		break;
	case WP_BRYAR_PISTOL:
		break;
	case WP_BLASTER:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && pm->ps->stats[STAT_RACEMODE])
			addTime = 100;
		else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 125;
		else if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 75;
		break;
	case WP_DISRUPTOR:
		if (pm->ps->stats[STAT_RACEMODE] && !pm->ps->duelInProgress)
			addTime = 600;
		//else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && g_tweakWeapons.integer & WT_SLOW_SNIPER)//Sad hack to make instagib more playable
		//	addTime = 1500;
		break;
	case WP_BOWCASTER:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 1050;
		if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 1050;
		break;
	case WP_REPEATER:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 3000;
		else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 200;
		break;
	case WP_DEMP2:
		if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 750;
		break;
	case WP_FLECHETTE:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 800;
		break;
	case WP_ROCKET_LAUNCHER:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 3500;
		if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 1050;
		break;
	case WP_THERMAL:
		if (!pm->ps->stats[STAT_RACEMODE] && /*(g_tweakWeapons.integer & WT_IMPACT_NITRON) ||*/ (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 1500;
		break;
	case WP_DET_PACK:
		if (pm->gametype == GT_SIEGE)
			addTime *= 2;
		break;
	case WP_CONCUSSION:
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 800;
		else if (!(pm->cmd.buttons & BUTTON_ALT_ATTACK) && !pm->ps->stats[STAT_RACEMODE] && (cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES))
			addTime = 1200;
		break;
	default:
		break;
	}
#endif


#if _GAME
	if (!(g_tweakForce.integer & FT_NORAGEFIRERATE) || pm->ps->weapon == WP_MELEE || pm->ps->weapon == WP_SABER) {
		if (pm->ps->fd.forcePowersActive & (1 << FP_RAGE))
			addTime *= 0.75;
		else if (pm->ps->fd.forceRageRecoveryTime > pm->cmd.serverTime)
			addTime *= 1.5;
	}

	if (pm->ps->stats[STAT_RACEMODE]) {
		if (((gentity_t *)pm_entSelf)->client->pers.haste)
			addTime /= 1.3;
	}
#endif

	pm->ps->weaponTime += addTime;

#if _GAME
#if _SPECIFICWEAPONTIME

	if ((g_tweakWeapons.integer & WT_TRIBES) && !pm->ps->stats[STAT_RACEMODE]) {
		int i;
		for (i = 0; i < MAX_WEAPONS; i++) {
			((gentity_t *)pm_entSelf)->client->specificWeaponTime[i] = 800;
		}
		((gentity_t *)pm_entSelf)->client->specificWeaponTime[pm->ps->weapon] += addTime - 800;
	}
#endif
#endif

}

/*
================
PM_Animate
================
*/

static void PM_Animate( void ) {
	if ( pm->cmd.buttons & BUTTON_GESTURE ) {
		if (pm->ps->m_iVehicleNum)
		{ //eh, fine, clear it
			if (pm->ps->forceHandExtendTime < pm->cmd.serverTime)
			{
				pm->ps->forceHandExtend = HANDEXTEND_NONE;
			}
		}

		if ( pm->ps->torsoTimer < 1 && pm->ps->forceHandExtend == HANDEXTEND_NONE &&
			pm->ps->legsTimer < 1 && pm->ps->weaponTime < 1 && pm->ps->saberLockTime < pm->cmd.serverTime) {

			pm->ps->forceHandExtend = HANDEXTEND_TAUNT;

			//FIXME: random taunt anims?
			pm->ps->forceDodgeAnim = BOTH_ENGAGETAUNT;

			pm->ps->forceHandExtendTime = pm->cmd.serverTime + 1000;

			//pm->ps->weaponTime = 100;

			PM_AddEvent( EV_TAUNT );
		}
#if 0
// Here's an interesting bit.  The bots in TA used buttons to do additional gestures.
// I ripped them out because I didn't want too many buttons given the fact that I was already adding some for JK2.
// We can always add some back in if we want though.
	} else if ( pm->cmd.buttons & BUTTON_GETFLAG ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_GETFLAG );
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
	} else if ( pm->cmd.buttons & BUTTON_GUARDBASE ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_GUARDBASE );
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
	} else if ( pm->cmd.buttons & BUTTON_PATROL ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_PATROL );
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
	} else if ( pm->cmd.buttons & BUTTON_FOLLOWME ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_FOLLOWME );
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
	} else if ( pm->cmd.buttons & BUTTON_AFFIRMATIVE ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_AFFIRMATIVE);
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
	} else if ( pm->cmd.buttons & BUTTON_NEGATIVE ) {
		if ( pm->ps->torsoTimer == 0 ) {
			PM_StartTorsoAnim( TORSO_NEGATIVE );
			pm->ps->torsoTimer = 600;	//TIMER_GESTURE;
		}
#endif //
	}
}


/*
================
PM_DropTimers
================
*/
static void PM_DropTimers( void ) {
	// drop misc timing counter
	if ( pm->ps->pm_time ) {
		if ( pml.msec >= pm->ps->pm_time ) {
			pm->ps->pm_flags &= ~PMF_ALL_TIMES;
			pm->ps->pm_time = 0;
		} else {
			pm->ps->pm_time -= pml.msec;
		}
	}

	// drop animation counter
	if ( pm->ps->legsTimer > 0 ) {
		pm->ps->legsTimer -= pml.msec;
		if ( pm->ps->legsTimer < 0 ) {
			pm->ps->legsTimer = 0;
		}
	}

	if ( pm->ps->torsoTimer > 0 ) {
		pm->ps->torsoTimer -= pml.msec;
		if ( pm->ps->torsoTimer < 0 ) {
			pm->ps->torsoTimer = 0;
		}
	}

	if (pm->ps->stats[STAT_DASHTIME] > pml.msec)//JAPRO dodge/dash/wj
		pm->ps->stats[STAT_DASHTIME] -= pml.msec;
	else if (pm->ps->stats[STAT_DASHTIME] > 0)
		pm->ps->stats[STAT_DASHTIME] = 0;

	if (pm->ps->stats[STAT_WJTIME] > pml.msec)//JAPRO dodge/dash/wj
		pm->ps->stats[STAT_WJTIME] -= pml.msec;
	else if (pm->ps->stats[STAT_WJTIME] > 0)
		pm->ps->stats[STAT_WJTIME] = 0;

	if (pm->ps->stats[STAT_JUMPTIME] > pml.msec)
		pm->ps->stats[STAT_JUMPTIME] -= pml.msec;
	else if (pm->ps->stats[STAT_JUMPTIME] > 0)
		pm->ps->stats[STAT_JUMPTIME] = 0;

#ifdef _GAME
	if (g_tweakSaber.integer & ST_FIXED_SABERSWITCH) {
		if (((gentity_t *)pm_entSelf)->client->saberDelayCount > 0) {
			((gentity_t *)pm_entSelf)->client->saberDelayCount -= pml.msec;
			((gentity_t *)pm_entSelf)->client->saberDelay = 1000;
		}
		if (((gentity_t *)pm_entSelf)->client->saberDelayCount <= 0) {
			((gentity_t *)pm_entSelf)->client->saberDelayCount = 0;
			((gentity_t *)pm_entSelf)->client->saberDelay = 0;
		}
	}
	else {
		((gentity_t *)pm_entSelf)->client->saberDelayCount = 0;
		((gentity_t *)pm_entSelf)->client->saberDelay = 0;
	}
#endif
}

// Following function is stateless (at the moment). And hoisting it out
// of the namespace here is easier than fixing all the places it's used,
// which includes files that are also compiled in SP. We do need to make
// sure we only get one copy in the linker, though.

extern	vmCvar_t	bg_fighterAltControl;
qboolean BG_UnrestrainedPitchRoll( playerState_t *ps, Vehicle_t *pVeh )
{
	if ( bg_fighterAltControl.integer
		&& ps->clientNum < MAX_CLIENTS //real client
		&& ps->m_iVehicleNum//in a vehicle
		&& pVeh //valid vehicle data pointer
		&& pVeh->m_pVehicleInfo//valid vehicle info
		&& pVeh->m_pVehicleInfo->type == VH_FIGHTER )//fighter
		//FIXME: specify per vehicle instead of assuming true for all fighters
		//FIXME: map/server setting?
	{//can roll and pitch without limitation!
		return qtrue;
	}
	return qfalse;
}


/*
================
PM_UpdateViewAngles

This can be used as another entry point when only the viewangles
are being updated isntead of a full move
================
*/
void PM_UpdateViewAngles( playerState_t *ps, const usercmd_t *cmd ) {
	short		temp;
	int		i;

	if ( ps->pm_type == PM_INTERMISSION || ps->pm_type == PM_SPINTERMISSION) {
		return;		// no view changes at all
	}

	if ( ps->pm_type != PM_SPECTATOR && ps->stats[STAT_HEALTH] <= 0 ) {
		return;		// no view changes at all
	}

	// circularly clamp the angles with deltas
	for (i=0 ; i<3 ; i++) {
		temp = cmd->angles[i] + ps->delta_angles[i];
#ifdef VEH_CONTROL_SCHEME_4
		if ( pm_entVeh
			&& pm_entVeh->m_pVehicle
			&& pm_entVeh->m_pVehicle->m_pVehicleInfo
			&& pm_entVeh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER
			&& (cmd->serverTime-pm_entVeh->playerState->hyperSpaceTime) >= HYPERSPACE_TIME )
		{//in a vehicle and not hyperspacing
			if ( i == PITCH )
			{
				int pitchClamp = ANGLE2SHORT(AngleNormalize180(pm_entVeh->m_pVehicle->m_vPrevRiderViewAngles[PITCH]+10.0f));
				// don't let the player look up or down more than 22.5 degrees
				if ( temp > pitchClamp )
				{
					ps->delta_angles[i] = pitchClamp - cmd->angles[i];
					temp = pitchClamp;
				}
				else if ( temp < -pitchClamp )
				{
					ps->delta_angles[i] = -pitchClamp - cmd->angles[i];
					temp = -pitchClamp;
				}
			}
			if ( i == YAW )
			{
				int yawClamp = ANGLE2SHORT(AngleNormalize180(pm_entVeh->m_pVehicle->m_vPrevRiderViewAngles[YAW]+10.0f));
				// don't let the player look left or right more than 22.5 degrees
				if ( temp > yawClamp )
				{
					ps->delta_angles[i] = yawClamp - cmd->angles[i];
					temp = yawClamp;
				}
				else if ( temp < -yawClamp )
				{
					ps->delta_angles[i] = -yawClamp - cmd->angles[i];
					temp = -yawClamp;
				}
			}
		}
#else //VEH_CONTROL_SCHEME_4
		if ( pm_entVeh && BG_UnrestrainedPitchRoll( ps, pm_entVeh->m_pVehicle ) )
		{//in a fighter
			/*
			if ( i == ROLL )
			{//get roll from vehicle
				ps->viewangles[ROLL] = pm_entVeh->playerState->viewangles[ROLL];//->m_pVehicle->m_vOrientation[ROLL];
				continue;

			}
			*/
		}
#endif // VEH_CONTROL_SCHEME_4
		else
		{
			if ( i == PITCH ) {
				// don't let the player look up or down more than 90 degrees
				if ( temp > 16000 ) {
					ps->delta_angles[i] = 16000 - cmd->angles[i];
					temp = 16000;
				} else if ( temp < -16000 ) {
					ps->delta_angles[i] = -16000 - cmd->angles[i];
					temp = -16000;
				}
			}
		}
		ps->viewangles[i] = SHORT2ANGLE(temp);
	}
}

/*
void PM_UpdateViewAngles( playerState_t *ps, const usercmd_t *cmd ) {
	short		temp;
	int		i;
	float	rootPitch = 0, pitchMin=-90, pitchMax=90, yawMin=0, yawMax=0, lockedYawValue = 0;	//just to shut up warnings
	qboolean	lockedYaw = qfalse, clamped = qfalse;
	bgEntity_t *vehEnt = NULL;

	if ( ps->pm_type == PM_INTERMISSION || ps->pm_type == PM_SPINTERMISSION) {
		return;		// no view changes at all
	}

	if ( ps->pm_type != PM_SPECTATOR && ps->stats[STAT_HEALTH] <= 0 ) {
		return;		// no view changes at all
	}

	// If we're a vehicle, or we're riding a vehicle...?
	if ( ps->m_iVehicleNum )
	{
		if ( ps->clientNum < MAX_CLIENTS )
		{ //player riding vehicle
			vehEnt = PM_BGEntForNum(ps->m_iVehicleNum);
		}
		else
		{ //vehicle with player pilot
			vehEnt = PM_BGEntForNum(ps->clientNum);
		}
		if ( vehEnt )
		{//there is a vehicle
			Vehicle_t *pVeh = vehEnt->m_pVehicle;
			if ( pVeh && pVeh->m_pVehicleInfo )
			{
				// There is a vehicle...
				if ( pVeh->m_pVehicleInfo->type != VH_ANIMAL )
				{//animals just turn normally, no clamping
					if ( pVeh->m_pVehicleInfo->type == VH_FIGHTER )
					{
						rootPitch = pVeh->m_vOrientation[PITCH];//gent->owner->client->ps.vehicleAngles[PITCH];//???  what if goes over 90 when add the min/max?
						if ( pVeh->m_pVehicleInfo->pitchLimit == -1 )
						{
							pitchMax = 180;
						}
						else
						{
							pitchMax = pVeh->m_pVehicleInfo->pitchLimit;
						}
						pitchMin = -pitchMax;
					}
					else
					{
						lockedYawValue = 0;//gent->owner->client->ps.vehicleAngles[YAW];
						lockedYaw = qtrue;
						yawMax = pVeh->m_pVehicleInfo->lookYaw;
						yawMin = -yawMax;
						rootPitch = 0;//gent->owner->client->ps.vehicleAngles[PITCH];//???  what if goes over 90 when add the min/max?
						pitchMax = pVeh->m_pVehicleInfo->lookPitch;
						pitchMin = -pitchMax;
					}
				}
			}
		}
	}
	if ( 1 )
	{
		const short pitchClampMin = ANGLE2SHORT(rootPitch+pitchMin);
		const short pitchClampMax = ANGLE2SHORT(rootPitch+pitchMax);
		const short yawClampMin = ANGLE2SHORT(lockedYawValue+yawMin);
		const short yawClampMax = ANGLE2SHORT(lockedYawValue+yawMax);
		for (i=0 ; i<3 ; i++)
		{
			temp = cmd->angles[i] + ps->delta_angles[i];
			if ( i == PITCH )
			{
				//FIXME get this limit from the NPCs stats?
				// don't let the player look up or down more than 90 degrees
				if ( temp > pitchClampMax )
				{
					ps->delta_angles[i] = (pitchClampMax - cmd->angles[i]) & 0xffff;	//& clamp to short
					temp = pitchClampMax;
					clamped = qtrue;
				}
				else if ( temp < pitchClampMin )
				{
					ps->delta_angles[i] = (pitchClampMin - cmd->angles[i]) & 0xffff;	//& clamp to short
					temp = pitchClampMin;
					clamped = qtrue;
				}
			}
			if ( i == YAW && lockedYaw )
			{
				//FIXME get this limit from the NPCs stats?
				// don't let the player look up or down more than 90 degrees
				if ( temp > yawClampMax )
				{
					ps->delta_angles[i] = (yawClampMax - cmd->angles[i]) & 0xffff;	//& clamp to short
					temp = yawClampMax;
					clamped = qtrue;
				}
				else if ( temp < yawClampMin )
				{
					ps->delta_angles[i] = (yawClampMin - cmd->angles[i]) & 0xffff;	//& clamp to short
					temp = yawClampMin;
					clamped = qtrue;
				}
				ps->viewangles[i] = SHORT2ANGLE(temp);
			}
			else
			{
				ps->viewangles[i] = SHORT2ANGLE(temp);
			}
		}
	}
	else
	{
		// circularly clamp the angles with deltas
		for (i=0 ; i<3 ; i++) {
			temp = cmd->angles[i] + ps->delta_angles[i];
			if ( i == PITCH ) {
				// don't let the player look up or down more than 90 degrees
				if ( temp > 16000 ) {
					ps->delta_angles[i] = 16000 - cmd->angles[i];
					temp = 16000;
				} else if ( temp < -16000 ) {
					ps->delta_angles[i] = -16000 - cmd->angles[i];
					temp = -16000;
				}
			}
			ps->viewangles[i] = SHORT2ANGLE(temp);
		}
	}

}
*/

//-------------------------------------------
void PM_AdjustAttackStates( pmove_t *pmove )
//-------------------------------------------
{
	int amount;

	if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&&pmove->ps->m_iVehicleNum)
	{ //riding a vehicle
		bgEntity_t *veh = pm_entVeh;
		if ( veh &&
			(veh->m_pVehicle && (veh->m_pVehicle->m_pVehicleInfo->type == VH_WALKER || veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER)) )
		{//riding a walker/fighter
			//not firing, ever
			pmove->ps->eFlags &= ~(EF_FIRING|EF_ALT_FIRING);
			return;
		}
	}
	// get ammo usage
	if ( pmove->cmd.buttons & BUTTON_ALT_ATTACK )
	{
		amount = pmove->ps->ammo[weaponData[ pmove->ps->weapon ].ammoIndex] - weaponData[pmove->ps->weapon].altEnergyPerShot;
	}
	else
	{
		amount = pmove->ps->ammo[weaponData[ pmove->ps->weapon ].ammoIndex] - weaponData[pmove->ps->weapon].energyPerShot;
	}

	// disruptor alt-fire should toggle the zoom mode, but only bother doing this for the player?
	if ( pmove->ps->weapon == WP_DISRUPTOR && pmove->ps->weaponstate == WEAPON_READY )
	{
		if ( !(pmove->ps->eFlags & EF_ALT_FIRING) && (pmove->cmd.buttons & BUTTON_ALT_ATTACK) /*&&
			pmove->cmd.upmove <= 0 && !pmove->cmd.forwardmove && !pmove->cmd.rightmove*/)
		{
			// We just pressed the alt-fire key
			if ( !pmove->ps->zoomMode && pmove->ps->pm_type != PM_DEAD && pmove->ps->pm_type != PM_NOCLIP && !pm->ps->stats[STAT_RACEMODE])
			{
				// not already zooming, so do it now
				pmove->ps->zoomMode = 1;
				pmove->ps->zoomLocked = qfalse;
				pmove->ps->zoomFov = 80.0f;//cg_fov.value;
				pmove->ps->zoomLockTime = pmove->cmd.serverTime + 50;
				PM_AddEvent(EV_DISRUPTOR_ZOOMSOUND);
			}
			else if (pmove->ps->zoomMode == 1 && pmove->ps->zoomLockTime < pmove->cmd.serverTime)
			{ //check for == 1 so we can't turn binoculars off with disruptor alt fire
				// already zooming, so must be wanting to turn it off
				pmove->ps->zoomMode = 0;
				pmove->ps->zoomTime = pmove->ps->commandTime;
				pmove->ps->zoomLocked = qfalse;
				PM_AddEvent(EV_DISRUPTOR_ZOOMSOUND);
				pmove->ps->weaponTime = 1000;
			}
		}
		else if ( !(pmove->cmd.buttons & BUTTON_ALT_ATTACK ) && pmove->ps->zoomLockTime < pmove->cmd.serverTime)
		{
			// Not pressing zoom any more
			if ( pmove->ps->zoomMode )
			{
				if (pmove->ps->zoomMode == 1 && !pmove->ps->zoomLocked)
				{ //approximate what level the client should be zoomed at based on how long zoom was held
					pmove->ps->zoomFov = ((pmove->cmd.serverTime+50) - pmove->ps->zoomLockTime) * 0.035f;
					if (pmove->ps->zoomFov > 50)
					{
						pmove->ps->zoomFov = 50;
					}
					if (pmove->ps->zoomFov < 1)
					{
						pmove->ps->zoomFov = 1;
					}
				}
				// were zooming in, so now lock the zoom
				pmove->ps->zoomLocked = qtrue;
			}
		}
		//This seemed like a good idea, but apparently it confuses people. So disabled for now.
		/*
		else if (!(pmove->ps->eFlags & EF_ALT_FIRING) && (pmove->cmd.buttons & BUTTON_ALT_ATTACK) &&
			(pmove->cmd.upmove > 0 || pmove->cmd.forwardmove || pmove->cmd.rightmove))
		{ //if you try to zoom while moving, just convert it into a primary attack
			pmove->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			pmove->cmd.buttons |= BUTTON_ATTACK;
		}
		*/

		/*
		if (pmove->cmd.upmove > 0 || pmove->cmd.forwardmove || pmove->cmd.rightmove)
		{
			if (pmove->ps->zoomMode == 1 && pmove->ps->zoomLockTime < pmove->cmd.serverTime)
			{ //check for == 1 so we can't turn binoculars off with disruptor alt fire
				pmove->ps->zoomMode = 0;
				pmove->ps->zoomTime = pmove->ps->commandTime;
				pmove->ps->zoomLocked = qfalse;
				PM_AddEvent(EV_DISRUPTOR_ZOOMSOUND);
			}
		}
		*/

		if ( pmove->cmd.buttons & BUTTON_ATTACK )
		{
			// If we are zoomed, we should switch the ammo usage to the alt-fire, otherwise, we'll
			//	just use whatever ammo was selected from above
			if ( pmove->ps->zoomMode )
			{
				amount = pmove->ps->ammo[weaponData[ pmove->ps->weapon ].ammoIndex] -
							weaponData[pmove->ps->weapon].altEnergyPerShot;
			}
		}
		else
		{
			// alt-fire button pressing doesn't use any ammo
			amount = 0;
		}
	}
	/*
	else if (pmove->ps->weapon == WP_DISRUPTOR) //still perform certain checks, even if the weapon is not ready
	{
		if (pmove->cmd.upmove > 0 || pmove->cmd.forwardmove || pmove->cmd.rightmove)
		{
			if (pmove->ps->zoomMode == 1 && pmove->ps->zoomLockTime < pmove->cmd.serverTime)
			{ //check for == 1 so we can't turn binoculars off with disruptor alt fire
				pmove->ps->zoomMode = 0;
				pmove->ps->zoomTime = pmove->ps->commandTime;
				pmove->ps->zoomLocked = qfalse;
				PM_AddEvent(EV_DISRUPTOR_ZOOMSOUND);
			}
		}
	}
	*/

	// set the firing flag for continuous beam weapons, saber will fire even if out of ammo
	if ( !(pmove->ps->pm_flags & PMF_RESPAWNED) &&
			pmove->ps->pm_type != PM_INTERMISSION &&
			pmove->ps->pm_type != PM_NOCLIP &&
			( pmove->cmd.buttons & (BUTTON_ATTACK|BUTTON_ALT_ATTACK)) &&
			( amount >= 0 || pmove->ps->weapon == WP_SABER ))
	{
		if ( pmove->cmd.buttons & BUTTON_ALT_ATTACK )
		{
			pmove->ps->eFlags |= EF_ALT_FIRING;
		}
		else
		{
			pmove->ps->eFlags &= ~EF_ALT_FIRING;
		}

		// This flag should always get set, even when alt-firing
		pmove->ps->eFlags |= EF_FIRING;
	}
	else
	{
		// Clear 'em out
		pmove->ps->eFlags &= ~(EF_FIRING|EF_ALT_FIRING);
	}

	// disruptor should convert a main fire to an alt-fire if the gun is currently zoomed
	if ( pmove->ps->weapon == WP_DISRUPTOR)
	{
		if ( pmove->cmd.buttons & BUTTON_ATTACK && pmove->ps->zoomMode == 1 && pmove->ps->zoomLocked)
		{
			// converting the main fire to an alt-fire
			pmove->cmd.buttons |= BUTTON_ALT_ATTACK;
			pmove->ps->eFlags |= EF_ALT_FIRING;
		}
		else if ( pmove->cmd.buttons & BUTTON_ALT_ATTACK && pmove->ps->zoomMode == 1 && pmove->ps->zoomLocked)
		{
			pmove->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			pmove->ps->eFlags &= ~EF_ALT_FIRING;
		}
	}
}

void BG_CmdForRoll( playerState_t *ps, int anim, usercmd_t *pCmd )
{
	switch ( (anim) )
	{
	case BOTH_ROLL_F:
//[JAPRO - Serverside - Physics - Roll start/stop move - Start]

		if (GetFixRoll(ps) > 2 && pCmd->forwardmove < 0)
			break;
		pCmd->forwardmove = 127;
		pCmd->rightmove = 0;
		break;

		/*
#ifdef _GAME
		if (g_fixRoll.integer > 2 && pCmd->forwardmove < 0)
			break;
		pCmd->forwardmove = 127;
		pCmd->rightmove = 0;
		break;
#else
		if (((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL3) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL3)) && (pCmd->forwardmove < 0))
			break;
		pCmd->forwardmove = 127;
		pCmd->rightmove = 0;
		break;
#endif
		*/

//[JAPRO - Serverside - Physics - Roll start/stop move - End]
	case BOTH_ROLL_B:
		pCmd->forwardmove = -127;
		pCmd->rightmove = 0;
		break;
	case BOTH_ROLL_R:
		pCmd->forwardmove = 0;
		pCmd->rightmove = 127;
		break;
	case BOTH_ROLL_L:
		pCmd->forwardmove = 0;
		pCmd->rightmove = -127;
		break;
	case BOTH_GETUP_BROLL_R:
		pCmd->forwardmove = 0;
		pCmd->rightmove = 48;
		//NOTE: speed is 400
		break;

	case BOTH_GETUP_FROLL_R:
		if ( ps->legsTimer <= 250 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			pCmd->forwardmove = 0;
			pCmd->rightmove = 48;
			//NOTE: speed is 400
		}
		break;

	case BOTH_GETUP_BROLL_L:
		pCmd->forwardmove = 0;
		pCmd->rightmove = -48;
		//NOTE: speed is 400
		break;

	case BOTH_GETUP_FROLL_L:
		if ( ps->legsTimer <= 250 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			pCmd->forwardmove = 0;
			pCmd->rightmove = -48;
			//NOTE: speed is 400
		}
		break;

	case BOTH_GETUP_BROLL_B:
		if ( ps->torsoTimer <= 250 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else if ( PM_AnimLength( 0, (animNumber_t)ps->legsAnim ) - ps->torsoTimer < 350 )
		{//beginning of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			//FIXME: ramp down over length of anim
			pCmd->forwardmove = -64;
			pCmd->rightmove = 0;
			//NOTE: speed is 400
		}
		break;

	case BOTH_GETUP_FROLL_B:
		if ( ps->torsoTimer <= 100 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else if ( PM_AnimLength( 0, (animNumber_t)ps->legsAnim ) - ps->torsoTimer < 200 )
		{//beginning of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			//FIXME: ramp down over length of anim
			pCmd->forwardmove = -64;
			pCmd->rightmove = 0;
			//NOTE: speed is 400
		}
		break;

	case BOTH_GETUP_BROLL_F:
		if ( ps->torsoTimer <= 550 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else if ( PM_AnimLength( 0, (animNumber_t)ps->legsAnim ) - ps->torsoTimer < 150 )
		{//beginning of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			pCmd->forwardmove = 64;
			pCmd->rightmove = 0;
			//NOTE: speed is 400
		}
		break;

	case BOTH_GETUP_FROLL_F:
		if ( ps->torsoTimer <= 100 )
		{//end of anim
			pCmd->forwardmove = pCmd->rightmove = 0;
		}
		else
		{
			//FIXME: ramp down over length of anim
			pCmd->forwardmove = 64;
			pCmd->rightmove = 0;
			//NOTE: speed is 400
		}
		break;
	}
	pCmd->upmove = 0;
}

qboolean PM_SaberInTransition( int move );

void BG_AdjustClientSpeed(playerState_t *ps, usercmd_t *cmd, int svTime)
{
	saberInfo_t	*saber;
	int fixroll = GetFixRoll(ps);

	if (ps->clientNum >= MAX_CLIENTS)
	{
		bgEntity_t *bgEnt = pm_entSelf;

		if (bgEnt && bgEnt->s.NPC_class == CLASS_VEHICLE)
		{ //vehicles manage their own speed
			return;
		}
	}

	//For prediction, always reset speed back to the last known server base speed
	//If we didn't do this, under lag we'd eventually dwindle speed down to 0 even though
	//that would not be the correct predicted value.
	ps->speed = ps->basespeed;

	if (ps->forceHandExtend == HANDEXTEND_DODGE)
	{
		ps->speed = 0;
	}

	if (ps->forceHandExtend == HANDEXTEND_KNOCKDOWN ||
		ps->forceHandExtend == HANDEXTEND_PRETHROWN ||
		ps->forceHandExtend == HANDEXTEND_POSTTHROWN)
	{
		ps->speed = 0;
	}


	if ( cmd->forwardmove < 0 && !(cmd->buttons&BUTTON_WALKING) && pm->ps->groundEntityNum != ENTITYNUM_NONE && !JK2SWINGS(ps) )
	{//running backwards is slower than running forwards (like SP)
#ifdef _GAME
		if (!(g_tweakSaber.integer & ST_ALLOW_ROLLCANCEL) || pm->ps->stats[STAT_RACEMODE])
#else
		if (!(cgs.jcinfo & JAPRO_CINFO_ROLLCANCEL) || pm->ps->stats[STAT_RACEMODE])
#endif
			if (ps->stats[STAT_MOVEMENTSTYLE] != MV_OCPM && ps->stats[STAT_MOVEMENTSTYLE] != MV_TRIBES)
				ps->speed *= 0.75f; //JK2 1.02 doesn't have this? does q3 / wsw?
	}

//[JAPRO - Serverside + Clientside - Force - Add fast grip option - Start]
	if (ps->fd.forcePowersActive & (1 << FP_GRIP)) {
		if (ps->stats[STAT_RACEMODE])
		{
			//keep grip at normal runspeed if in racemode like jk2
		}
#ifdef _GAME
		else if (g_tweakForce.integer & FT_FASTGRIP)
#else
		if (cgs.serverMod == SVMOD_JAPLUS || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FASTGRIP))
#endif
			ps->speed *= 0.8f;
		else
			ps->speed *= 0.4f;
	}
//[JAPRO - Serverside + Clientside - Force - Add fast grip option - End]

//JAPRO - Serverside - Force Combo - Start
#ifdef _GAME
 	if ((g_tweakForce.integer & FT_FORCECOMBO) && ps->fd.forcePowersActive & (1 << FP_SPEED) && ps->fd.forcePowersActive & (1 << FP_RAGE))
#else
	if (cgs.serverMod == SVMOD_JAPRO && (cgs.jcinfo & JAPRO_CINFO_FORCECOMBO) && ps->fd.forcePowersActive & (1 << FP_SPEED) && ps->fd.forcePowersActive & (1 << FP_RAGE))
#endif
	{
		ps->speed *= 2.2f;
	}
//JAPRO - Serverside - Force Combo - End

	else if (ps->fd.forcePowersActive & (1 << FP_SPEED))
	{
		ps->speed *= 1.7f;
	}
	else if (ps->fd.forcePowersActive & (1 << FP_RAGE))
	{
		ps->speed *= 1.3f;
	}
	else if (ps->fd.forceRageRecoveryTime > svTime)
	{
		ps->speed *= 0.75f;
	}

	if (pm->ps->weapon == WP_DISRUPTOR &&
		pm->ps->zoomMode == 1 && pm->ps->zoomLockTime < pm->cmd.serverTime)
	{
		ps->speed *= 0.5f;
	}

	if ( ps->fd.forceGripCripple && pm->ps->persistant[PERS_TEAM] != TEAM_SPECTATOR ) {
		if ( ps->fd.forcePowersActive & (1 << FP_RAGE) )
			ps->speed *= 0.9f;
		else if ( ps->fd.forcePowersActive & (1 << FP_SPEED) )
			ps->speed *= 0.8f;
		else
			ps->speed *= 0.2f;
	}

	if ( BG_SaberInAttack( ps->saberMove ) && cmd->forwardmove < 0 )
	{//if running backwards while attacking, don't run as fast.
		switch( ps->fd.saberAnimLevel )
		{
		case FORCE_LEVEL_1:
			ps->speed *= 0.75f;
			break;
		case FORCE_LEVEL_2:
		case SS_DUAL:
		case SS_STAFF:
			ps->speed *= 0.60f;
			break;
		case FORCE_LEVEL_3:
			ps->speed *= 0.45f;
			break;
		default:
			break;
		}
	}
	else if ( BG_SpinningSaberAnim( ps->legsAnim ) )
	{
		if (ps->fd.saberAnimLevel == FORCE_LEVEL_3 && !JK2SWINGS(ps))
		{
			ps->speed *= 0.3f;
		}
		else
		{
			ps->speed *= 0.5f;
		}
	}
	else if ( ps->weapon == WP_SABER && BG_SaberInAttack( ps->saberMove ) )
	{//if attacking with saber while running, drop your speed
		switch( ps->fd.saberAnimLevel )
		{
		case FORCE_LEVEL_2:
		case SS_DUAL:
		case SS_STAFF:
			ps->speed *= 0.85f;
			break;
		case FORCE_LEVEL_3:
			ps->speed *= JK2SWINGS(ps) ? 0.70f : 0.55f;
			break;
		default:
			break;
		}
	}
	else if (ps->weapon == WP_SABER && ps->fd.saberAnimLevel == FORCE_LEVEL_3 && !JK2SWINGS(ps) &&
		PM_SaberInTransition(ps->saberMove))
	{ //Now, we want to even slow down in transitions for level 3 (since it has chains and stuff now)
		if (cmd->forwardmove < 0)
		{
			ps->speed *= 0.4f;
		}
		else
		{
			ps->speed *= 0.6f;
		}
	}

	/*
#ifdef _GAME
	if (g_fixRoll.integer > 2)//fixroll 3
#else
	if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL3) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL3))//fixroll3
#endif
	*/


	if (fixroll > 2)
	{
		if ( BG_InRoll( ps, ps->legsAnim ) && ps->speed > 50.0f )
		{ //can't roll unless you're able to move normally
			if ((ps->legsAnim) == BOTH_ROLL_B)
			{ //backwards roll is pretty fast, should also be slower
				ps->speed = ps->legsTimer/2.5f;
			}
			else
			{
				if ( ps->legsTimer <= 800 )
				{
					if ( ps->legsTimer <= 100 )
					{
						if ( (pm->cmd.forwardmove < 0) )
						{
							ps->speed = ps->legsTimer/20.0f;
						}
						else
						{
							ps->speed = ps->legsTimer/5.0f;
						}
					}
					else
					{
						if ( pm->cmd.forwardmove < 0 )
							ps->speed = ps->legsTimer/20.0f;
						else
							ps->speed = ps->legsTimer/1.5;
					}
				}
				else
				{
					ps->speed = ps->legsTimer/1.5;
				}
			}
		}
	}
/*
#ifdef _GAME
	else if (g_fixRoll.integer == 2)//fixroll 2
#else
	else if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL2) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL2))//fixroll2
#endif
	*/

	else if (fixroll == 2)
	{
		if ( BG_InRoll( ps, ps->legsAnim ) && ps->speed > 50 )
		{ //can't roll unless you're able to move normally
			if ((ps->legsAnim) == BOTH_ROLL_B)
			{ //backwards roll is pretty fast, should also be slower
				if (ps->legsTimer > 800)
				{
					ps->speed = ps->legsTimer/2.5;
				}
				else
				{
					ps->speed = ps->legsTimer/6.0;//450;
				}
			}
			else
			{
				if (ps->legsTimer > 800)
				{
					ps->speed = ps->legsTimer/1.5;//450;
				}
				else
				{
					ps->speed = ps->legsTimer/5.0;//450;
				}
			}
			if (ps->speed > 600)
			{
				ps->speed = 600;
			}
			//Automatically slow down as the roll ends.
		}
	}

/*
#ifdef _GAME
	else if (g_fixRoll.integer == 1)//fixroll 1
#else
	else if ((cgs.serverMod == SVMOD_JAPLUS && cgs.cinfo & JAPLUS_CINFO_FIXROLL1) || (cgs.serverMod == SVMOD_JAPRO && cgs.jcinfo & JAPRO_CINFO_FIXROLL1))//fixroll1
#endif
*/

	else if (fixroll == 1)
	{
		if ( BG_InRoll( ps, ps->legsAnim ) && ps->speed > 50 )
		{ //can't roll unless you're able to move normally
			if ((ps->legsAnim) == BOTH_ROLL_B)
			{ //backwards roll is pretty fast, should also be slower
				if (ps->legsTimer > 800)
				{
					ps->speed = ps->legsTimer/2.5;
				}
				else
				{
					ps->speed = ps->legsTimer/6.0;//450;
				}
			}
			else
			{
				if (ps->legsTimer > 800)
				{
					ps->speed = ps->legsTimer/1.5;//450;
				}
				else
				{
					ps->speed = ps->legsTimer/5.0;//450;
				}
			}
			if (ps->speed > 600)
			{
				ps->speed = 600;
			}
			//Automatically slow down as the roll ends.
		}
	}
	else if ( BG_InRoll( ps, ps->legsAnim ) && ps->speed > 50 ) //base / fixroll 0
	{ //can't roll unless you're able to move normally
		if ((ps->legsAnim) == BOTH_ROLL_B)
		{ //backwards roll is pretty fast, should also be slower
			if (ps->legsTimer > 800)
			{
				ps->speed = ps->legsTimer/2.5;
			}
			else
			{
				ps->speed = ps->legsTimer/6.0;//450;
			}
		}
		else
		{
			if (ps->legsTimer > 800)
			{
				ps->speed = ps->legsTimer/1.5;//450;
			}
			else
			{
				ps->speed = ps->legsTimer/5.0;//450;
			}
		}
		if (ps->speed > 600)
		{
			ps->speed = 600;
		}
		//Automatically slow down as the roll ends.
	}

	if (!ps->stats[STAT_RACEMODE]) {
		saber = BG_MySaber( ps->clientNum, 0 );
		if ( saber
			&& saber->moveSpeedScale != 1.0f )
		{
			ps->speed *= saber->moveSpeedScale;
		}
		saber = BG_MySaber( ps->clientNum, 1 );
		if ( saber
			&& saber->moveSpeedScale != 1.0f )
		{
			ps->speed *= saber->moveSpeedScale;
		}
	}
}

qboolean BG_InRollAnim( entityState_t *cent )
{
	switch ( (cent->legsAnim) )
	{
	case BOTH_ROLL_F:
	case BOTH_ROLL_B:
	case BOTH_ROLL_R:
	case BOTH_ROLL_L:
		return qtrue;
	}
	return qfalse;
}

qboolean BG_InKnockDown( int anim )
{
	switch ( (anim) )
	{
	case BOTH_KNOCKDOWN1:
	case BOTH_KNOCKDOWN2:
	case BOTH_KNOCKDOWN3:
	case BOTH_KNOCKDOWN4:
	case BOTH_KNOCKDOWN5:
		return qtrue;
		break;
	case BOTH_GETUP1:
	case BOTH_GETUP2:
	case BOTH_GETUP3:
	case BOTH_GETUP4:
	case BOTH_GETUP5:
	case BOTH_FORCE_GETUP_F1:
	case BOTH_FORCE_GETUP_F2:
	case BOTH_FORCE_GETUP_B1:
	case BOTH_FORCE_GETUP_B2:
	case BOTH_FORCE_GETUP_B3:
	case BOTH_FORCE_GETUP_B4:
	case BOTH_FORCE_GETUP_B5:
	case BOTH_GETUP_BROLL_B:
	case BOTH_GETUP_BROLL_F:
	case BOTH_GETUP_BROLL_L:
	case BOTH_GETUP_BROLL_R:
	case BOTH_GETUP_FROLL_B:
	case BOTH_GETUP_FROLL_F:
	case BOTH_GETUP_FROLL_L:
	case BOTH_GETUP_FROLL_R:
		return qtrue;
		break;
	}
	return qfalse;
}

qboolean BG_InRollES( entityState_t *ps, int anim )
{
	switch ( (anim) )
	{
	case BOTH_ROLL_F:
	case BOTH_ROLL_B:
	case BOTH_ROLL_R:
	case BOTH_ROLL_L:
		return qtrue;
		break;
	}
	return qfalse;
}

void BG_IK_MoveArm(void *ghoul2, int lHandBolt, int time, entityState_t *ent, int basePose, vec3_t desiredPos, qboolean *ikInProgress,
					 vec3_t origin, vec3_t angles, vec3_t scale, int blendTime, qboolean forceHalt)
{
	mdxaBone_t lHandMatrix;
	vec3_t lHand;
	vec3_t torg;
	float distToDest;

	if (!ghoul2)
	{
		return;
	}

	assert(bgHumanoidAnimations[basePose].firstFrame > 0);

	if (!*ikInProgress && !forceHalt)
	{
		int baseposeAnim = basePose;
		sharedSetBoneIKStateParams_t ikP;

		//restrict the shoulder joint
		//VectorSet(ikP.pcjMins,-50.0f,-80.0f,-15.0f);
		//VectorSet(ikP.pcjMaxs,15.0f,40.0f,15.0f);

		//for now, leaving it unrestricted, but restricting elbow joint.
		//This lets us break the arm however we want in order to fling people
		//in throws, and doesn't look bad.
		VectorSet(ikP.pcjMins,0,0,0);
		VectorSet(ikP.pcjMaxs,0,0,0);

		//give the info on our entity.
		ikP.blendTime = blendTime;
		VectorCopy(origin, ikP.origin);
		VectorCopy(angles, ikP.angles);
		ikP.angles[PITCH] = 0;
		ikP.pcjOverrides = 0;
		ikP.radius = 10.0f;
		VectorCopy(scale, ikP.scale);

		//base pose frames for the limb
		ikP.startFrame = bgHumanoidAnimations[baseposeAnim].firstFrame + bgHumanoidAnimations[baseposeAnim].numFrames;
		ikP.endFrame = bgHumanoidAnimations[baseposeAnim].firstFrame + bgHumanoidAnimations[baseposeAnim].numFrames;

		ikP.forceAnimOnBone = qfalse; //let it use existing anim if it's the same as this one.

		//we want to call with a null bone name first. This will init all of the
		//ik system stuff on the g2 instance, because we need ragdoll effectors
		//in order for our pcj's to know how to angle properly.
		if (!trap->G2API_SetBoneIKState(ghoul2, time, NULL, IKS_DYNAMIC, &ikP))
		{
			assert(!"Failed to init IK system for g2 instance!");
		}

		//Now, create our IK bone state.
		if (trap->G2API_SetBoneIKState(ghoul2, time, "lhumerus", IKS_DYNAMIC, &ikP))
		{
			//restrict the elbow joint
			VectorSet(ikP.pcjMins,-90.0f,-20.0f,-20.0f);
			VectorSet(ikP.pcjMaxs,30.0f,20.0f,-20.0f);

			if (trap->G2API_SetBoneIKState(ghoul2, time, "lradius", IKS_DYNAMIC, &ikP))
			{ //everything went alright.
				*ikInProgress = qtrue;
			}
		}
	}

	if (*ikInProgress && !forceHalt)
	{ //actively update our ik state.
		sharedIKMoveParams_t ikM;
		sharedRagDollUpdateParams_t tuParms;
		vec3_t tAngles;

		//set the argument struct up
		VectorCopy(desiredPos, ikM.desiredOrigin); //we want the bone to move here.. if possible

		VectorCopy(angles, tAngles);
		tAngles[PITCH] = tAngles[ROLL] = 0;

		trap->G2API_GetBoltMatrix(ghoul2, 0, lHandBolt, &lHandMatrix, tAngles, origin, time, 0, scale);

		//Get the point position from the matrix.
		lHand[0] = lHandMatrix.matrix[0][3];
		lHand[1] = lHandMatrix.matrix[1][3];
		lHand[2] = lHandMatrix.matrix[2][3];

		VectorSubtract(lHand, desiredPos, torg);
		distToDest = VectorLength(torg);

		//closer we are, more we want to keep updated.
		//if we're far away we don't want to be too fast or we'll start twitching all over.
		if (distToDest < 2)
		{ //however if we're this close we want very precise movement
			ikM.movementSpeed = 0.4f;
		}
		else if (distToDest < 16)
		{
			ikM.movementSpeed = 0.9f;//8.0f;
		}
		else if (distToDest < 32)
		{
			ikM.movementSpeed = 0.8f;//4.0f;
		}
		else if (distToDest < 64)
		{
			ikM.movementSpeed = 0.7f;//2.0f;
		}
		else
		{
			ikM.movementSpeed = 0.6f;
		}
		VectorCopy(origin, ikM.origin); //our position in the world.

		ikM.boneName[0] = 0;
		if (trap->G2API_IKMove(ghoul2, time, &ikM))
		{
			//now do the standard model animate stuff with ragdoll update params.
			VectorCopy(angles, tuParms.angles);
			tuParms.angles[PITCH] = 0;

			VectorCopy(origin, tuParms.position);
			VectorCopy(scale, tuParms.scale);

			tuParms.me = ent->number;
			VectorClear(tuParms.velocity);

			trap->G2API_AnimateG2Models(ghoul2, time, &tuParms);
		}
		else
		{
			*ikInProgress = qfalse;
		}
	}
	else if (*ikInProgress)
	{ //kill it
		float cFrame, animSpeed;
		int sFrame, eFrame, flags;

		trap->G2API_SetBoneIKState(ghoul2, time, "lhumerus", IKS_NONE, NULL);
		trap->G2API_SetBoneIKState(ghoul2, time, "lradius", IKS_NONE, NULL);

		//then reset the angles/anims on these PCJs
		trap->G2API_SetBoneAngles(ghoul2, 0, "lhumerus", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, NULL, 0, time);
		trap->G2API_SetBoneAngles(ghoul2, 0, "lradius", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, NULL, 0, time);

		//Get the anim/frames that the pelvis is on exactly, and match the left arm back up with them again.
		trap->G2API_GetBoneAnim(ghoul2, "pelvis", (const int)time, &cFrame, &sFrame, &eFrame, &flags, &animSpeed, 0, 0);
		trap->G2API_SetBoneAnim(ghoul2, 0, "lhumerus", sFrame, eFrame, flags, animSpeed, time, sFrame, 300);
		trap->G2API_SetBoneAnim(ghoul2, 0, "lradius", sFrame, eFrame, flags, animSpeed, time, sFrame, 300);

		//And finally, get rid of all the ik state effector data by calling with null bone name (similar to how we init it).
		trap->G2API_SetBoneIKState(ghoul2, time, NULL, IKS_NONE, NULL);

		*ikInProgress = qfalse;
	}
}

//Adjust the head/neck desired angles
void BG_UpdateLookAngles( int lookingDebounceTime, vec3_t lastHeadAngles, int time, vec3_t lookAngles, float lookSpeed, float minPitch, float maxPitch, float minYaw, float maxYaw, float minRoll, float maxRoll )
{
	static const float fFrameInter = 0.1f;
	static vec3_t oldLookAngles;
	static vec3_t lookAnglesDiff;
	static int ang;

	if ( lookingDebounceTime > time )
	{
		//clamp so don't get "Exorcist" effect
		if ( lookAngles[PITCH] > maxPitch )
		{
			lookAngles[PITCH] = maxPitch;
		}
		else if ( lookAngles[PITCH] < minPitch )
		{
			lookAngles[PITCH] = minPitch;
		}
		if ( lookAngles[YAW] > maxYaw )
		{
			lookAngles[YAW] = maxYaw;
		}
		else if ( lookAngles[YAW] < minYaw )
		{
			lookAngles[YAW] = minYaw;
		}
		if ( lookAngles[ROLL] > maxRoll )
		{
			lookAngles[ROLL] = maxRoll;
		}
		else if ( lookAngles[ROLL] < minRoll )
		{
			lookAngles[ROLL] = minRoll;
		}

		//slowly lerp to this new value
		//Remember last headAngles
		VectorCopy( lastHeadAngles, oldLookAngles );
		VectorSubtract( lookAngles, oldLookAngles, lookAnglesDiff );

		for ( ang = 0; ang < 3; ang++ )
		{
			lookAnglesDiff[ang] = AngleNormalize180( lookAnglesDiff[ang] );
		}

		if( VectorLengthSquared( lookAnglesDiff ) )
		{
			lookAngles[PITCH] = AngleNormalize180( oldLookAngles[PITCH]+(lookAnglesDiff[PITCH]*fFrameInter*lookSpeed) );
			lookAngles[YAW] = AngleNormalize180( oldLookAngles[YAW]+(lookAnglesDiff[YAW]*fFrameInter*lookSpeed) );
			lookAngles[ROLL] = AngleNormalize180( oldLookAngles[ROLL]+(lookAnglesDiff[ROLL]*fFrameInter*lookSpeed) );
		}
	}
	//Remember current lookAngles next time
	VectorCopy( lookAngles, lastHeadAngles );
}

//for setting visual look (headturn) angles
static void BG_G2ClientNeckAngles( void *ghoul2, int time, const vec3_t lookAngles, vec3_t headAngles, vec3_t neckAngles, vec3_t thoracicAngles, vec3_t headClampMinAngles, vec3_t headClampMaxAngles )
{
	vec3_t	lA;
	VectorCopy( lookAngles, lA );
	//clamp the headangles (which should now be relative to the cervical (neck) angles
	if ( lA[PITCH] < headClampMinAngles[PITCH] )
	{
		lA[PITCH] = headClampMinAngles[PITCH];
	}
	else if ( lA[PITCH] > headClampMaxAngles[PITCH] )
	{
		lA[PITCH] = headClampMaxAngles[PITCH];
	}

	if ( lA[YAW] < headClampMinAngles[YAW] )
	{
		lA[YAW] = headClampMinAngles[YAW];
	}
	else if ( lA[YAW] > headClampMaxAngles[YAW] )
	{
		lA[YAW] = headClampMaxAngles[YAW];
	}

	if ( lA[ROLL] < headClampMinAngles[ROLL] )
	{
		lA[ROLL] = headClampMinAngles[ROLL];
	}
	else if ( lA[ROLL] > headClampMaxAngles[ROLL] )
	{
		lA[ROLL] = headClampMaxAngles[ROLL];
	}

	//split it up between the neck and cranium
	if ( thoracicAngles[PITCH] )
	{//already been set above, blend them
		thoracicAngles[PITCH] = (thoracicAngles[PITCH] + (lA[PITCH] * 0.4)) * 0.5f;
	}
	else
	{
		thoracicAngles[PITCH] = lA[PITCH] * 0.4;
	}
	if ( thoracicAngles[YAW] )
	{//already been set above, blend them
		thoracicAngles[YAW] = (thoracicAngles[YAW] + (lA[YAW] * 0.1)) * 0.5f;
	}
	else
	{
		thoracicAngles[YAW] = lA[YAW] * 0.1;
	}
	if ( thoracicAngles[ROLL] )
	{//already been set above, blend them
		thoracicAngles[ROLL] = (thoracicAngles[ROLL] + (lA[ROLL] * 0.1)) * 0.5f;
	}
	else
	{
		thoracicAngles[ROLL] = lA[ROLL] * 0.1;
	}

	neckAngles[PITCH] = lA[PITCH] * 0.2f;
	neckAngles[YAW] = lA[YAW] * 0.3f;
	neckAngles[ROLL] = lA[ROLL] * 0.3f;

	headAngles[PITCH] = lA[PITCH] * 0.4;
	headAngles[YAW] = lA[YAW] * 0.6;
	headAngles[ROLL] = lA[ROLL] * 0.6;

	/* //non-applicable SP code
	if ( G_RidingVehicle( cent->gent ) )// && type == VH_SPEEDER ?
	{//aim torso forward too
		headAngles[YAW] = neckAngles[YAW] = thoracicAngles[YAW] = 0;
	}
	*/

	trap->G2API_SetBoneAngles(ghoul2, 0, "cranium", headAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
	trap->G2API_SetBoneAngles(ghoul2, 0, "cervical", neckAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
	trap->G2API_SetBoneAngles(ghoul2, 0, "thoracic", thoracicAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
}

//rww - Finally decided to convert all this stuff to BG form.
static void BG_G2ClientSpineAngles( void *ghoul2, int motionBolt, vec3_t cent_lerpOrigin, vec3_t cent_lerpAngles, entityState_t *cent,
							int time, vec3_t viewAngles, int ciLegs, int ciTorso, const vec3_t angles, vec3_t thoracicAngles,
							vec3_t ulAngles, vec3_t llAngles, vec3_t modelScale, float *tPitchAngle, float *tYawAngle, int *corrTime )
{
	qboolean doCorr = qfalse;

	//*tPitchAngle = viewAngles[PITCH];
	viewAngles[YAW] = AngleDelta( cent_lerpAngles[YAW], angles[YAW] );
	//*tYawAngle = viewAngles[YAW];

#if 1
	if ( !BG_FlippingAnim( cent->legsAnim ) &&
		!BG_SpinningSaberAnim( cent->legsAnim ) &&
		!BG_SpinningSaberAnim( cent->torsoAnim ) &&
		!BG_InSpecialJump( cent->legsAnim ) &&
		!BG_InSpecialJump( cent->torsoAnim ) &&
		!BG_InDeathAnim(cent->legsAnim) &&
		!BG_InDeathAnim(cent->torsoAnim) &&
		!BG_InRollES(cent, cent->legsAnim) &&
		!BG_InRollAnim(cent) &&
		!BG_SaberInSpecial(cent->saberMove) &&
		!BG_SaberInSpecialAttack(cent->torsoAnim) &&
		!BG_SaberInSpecialAttack(cent->legsAnim) &&

		!BG_InKnockDown(cent->torsoAnim) &&
		!BG_InKnockDown(cent->legsAnim) &&
		!BG_InKnockDown(ciTorso) &&
		!BG_InKnockDown(ciLegs) &&

		!BG_FlippingAnim( ciLegs ) &&
		!BG_SpinningSaberAnim( ciLegs ) &&
		!BG_SpinningSaberAnim( ciTorso ) &&
		!BG_InSpecialJump( ciLegs ) &&
		!BG_InSpecialJump( ciTorso ) &&
		!BG_InDeathAnim(ciLegs) &&
		!BG_InDeathAnim(ciTorso) &&
		!BG_SaberInSpecialAttack(ciTorso) &&
		!BG_SaberInSpecialAttack(ciLegs) &&

		!(cent->eFlags & EF_DEAD) &&
		(cent->legsAnim) != (cent->torsoAnim) &&
		(ciLegs) != (ciTorso) &&
		!cent->m_iVehicleNum)
	{
		doCorr = qtrue;
	}
#else
	if ( ((!BG_FlippingAnim( cent->legsAnim )
		&& !BG_SpinningSaberAnim( cent->legsAnim )
		&& !BG_SpinningSaberAnim( cent->torsoAnim )
		&& (cent->legsAnim) != (cent->torsoAnim)) //NOTE: presumes your legs & torso are on the same frame, though they *should* be because PM_SetAnimFinal tries to keep them in synch
		||
		(!BG_FlippingAnim( ciLegs )
		&& !BG_SpinningSaberAnim( ciLegs )
		&& !BG_SpinningSaberAnim( ciTorso )
		&& (ciLegs) != (ciTorso)))
		||
		ciLegs != cent->legsAnim
		||
		ciTorso != cent->torsoAnim)
	{
		doCorr = qtrue;
		*corrTime = time + 1000; //continue correcting for a second after to smooth things out. SP doesn't need this for whatever reason but I can't find a way around it.
	}
	else if (*corrTime >= time)
	{
		if (!BG_FlippingAnim( cent->legsAnim )
			&& !BG_SpinningSaberAnim( cent->legsAnim )
			&& !BG_SpinningSaberAnim( cent->torsoAnim )
			&& !BG_FlippingAnim( ciLegs )
			&& !BG_SpinningSaberAnim( ciLegs )
			&& !BG_SpinningSaberAnim( ciTorso ))
		{
			doCorr = qtrue;
		}
	}
#endif

	if (doCorr)
	{//FIXME: no need to do this if legs and torso on are same frame
		//adjust for motion offset
		mdxaBone_t	boltMatrix;
		vec3_t		motionFwd, motionAngles;
		vec3_t		motionRt, tempAng;
		int			ang;

		trap->G2API_GetBoltMatrix_NoRecNoRot( ghoul2, 0, motionBolt, &boltMatrix, vec3_origin, cent_lerpOrigin, time, 0, modelScale);
		//BG_GiveMeVectorFromMatrix( &boltMatrix, NEGATIVE_Y, motionFwd );
		motionFwd[0] = -boltMatrix.matrix[0][1];
		motionFwd[1] = -boltMatrix.matrix[1][1];
		motionFwd[2] = -boltMatrix.matrix[2][1];

		vectoangles( motionFwd, motionAngles );

		//BG_GiveMeVectorFromMatrix( &boltMatrix, NEGATIVE_X, motionRt );
		motionRt[0] = -boltMatrix.matrix[0][0];
		motionRt[1] = -boltMatrix.matrix[1][0];
		motionRt[2] = -boltMatrix.matrix[2][0];

		vectoangles( motionRt, tempAng );
		motionAngles[ROLL] = -tempAng[PITCH];

		for ( ang = 0; ang < 3; ang++ )
		{
			viewAngles[ang] = AngleNormalize180( viewAngles[ang] - AngleNormalize180( motionAngles[ang] ) );
		}
	}

	//distribute the angles differently up the spine
	//NOTE: each of these distributions must add up to 1.0f
	thoracicAngles[PITCH] = viewAngles[PITCH]*0.20f;
	llAngles[PITCH] = viewAngles[PITCH]*0.40f;
	ulAngles[PITCH] = viewAngles[PITCH]*0.40f;

	thoracicAngles[YAW] = viewAngles[YAW]*0.20f;
	ulAngles[YAW] = viewAngles[YAW]*0.35f;
	llAngles[YAW] = viewAngles[YAW]*0.45f;

	thoracicAngles[ROLL] = viewAngles[ROLL]*0.20f;
	ulAngles[ROLL] = viewAngles[ROLL]*0.35f;
	llAngles[ROLL] = viewAngles[ROLL]*0.45f;
}

/*
==================
CG_SwingAngles
==================
*/
static float BG_SwingAngles( float destination, float swingTolerance, float clampTolerance,
					float speed, float *angle, qboolean *swinging, int frametime ) {
	float	swing;
	float	move;
	float	scale;

	if ( !*swinging ) {
		// see if a swing should be started
		swing = AngleSubtract( *angle, destination );
		if ( swing > swingTolerance || swing < -swingTolerance ) {
			*swinging = qtrue;
		}
	}

	if ( !*swinging ) {
		return 0;
	}

	// modify the speed depending on the delta
	// so it doesn't seem so linear
	swing = AngleSubtract( destination, *angle );
	scale = fabs( swing );
	if ( scale < swingTolerance * 0.5 ) {
		scale = 0.5;
	} else if ( scale < swingTolerance ) {
		scale = 1.0;
	} else {
		scale = 2.0;
	}

	// swing towards the destination angle
	if ( swing >= 0 ) {
		move = frametime * scale * speed;
		if ( move >= swing ) {
			move = swing;
			*swinging = qfalse;
		}
		*angle = AngleMod( *angle + move );
	} else if ( swing < 0 ) {
		move = frametime * scale * -speed;
		if ( move <= swing ) {
			move = swing;
			*swinging = qfalse;
		}
		*angle = AngleMod( *angle + move );
	}

	// clamp to no more than tolerance
	swing = AngleSubtract( destination, *angle );
	if ( swing > clampTolerance ) {
		*angle = AngleMod( destination - (clampTolerance - 1) );
	} else if ( swing < -clampTolerance ) {
		*angle = AngleMod( destination + (clampTolerance - 1) );
	}

	return swing;
}

//#define BONE_BASED_LEG_ANGLES

//I apologize for this function
qboolean BG_InRoll2( entityState_t *es )
{
	switch ( (es->legsAnim) )
	{
	case BOTH_GETUP_BROLL_B:
	case BOTH_GETUP_BROLL_F:
	case BOTH_GETUP_BROLL_L:
	case BOTH_GETUP_BROLL_R:
	case BOTH_GETUP_FROLL_B:
	case BOTH_GETUP_FROLL_F:
	case BOTH_GETUP_FROLL_L:
	case BOTH_GETUP_FROLL_R:
	case BOTH_ROLL_F:
	case BOTH_ROLL_B:
	case BOTH_ROLL_R:
	case BOTH_ROLL_L:
		return qtrue;
		break;
	}
	return qfalse;
}


extern qboolean BG_SaberLockBreakAnim( int anim ); //bg_panimate.c
void BG_G2PlayerAngles(void *ghoul2, int motionBolt, entityState_t *cent, int time, vec3_t cent_lerpOrigin,
					   vec3_t cent_lerpAngles, matrix3_t legs, vec3_t legsAngles, qboolean *tYawing,
					   qboolean *tPitching, qboolean *lYawing, float *tYawAngle, float *tPitchAngle,
					   float *lYawAngle, int frametime, vec3_t turAngles, vec3_t modelScale, int ciLegs,
					   int ciTorso, int *corrTime, vec3_t lookAngles, vec3_t lastHeadAngles, int lookTime,
					   entityState_t *emplaced, int *crazySmoothFactor)
{
	int					adddir = 0;
	static int			dir;
	static int			i;
//	static int			movementOffsets[8] = { 0, 22, 45, -22, 0, 22, -45, -22 };
	float				degrees_negative = 0;
	float				degrees_positive = 0;
	static float		dif;
	static float		dest;
	static float		speed; //, speed_dif, speed_desired;
	static const float	lookSpeed = 1.5f;
#ifdef BONE_BASED_LEG_ANGLES
	static float		legBoneYaw;
#endif
	static vec3_t		eyeAngles;
	static vec3_t		neckAngles;
	static vec3_t		velocity;
	static vec3_t		torsoAngles, headAngles;
	static vec3_t		velPos, velAng;
	static vec3_t		ulAngles, llAngles, viewAngles, angles, thoracicAngles = {0,0,0};
	static vec3_t		headClampMinAngles = {-25,-55,-10}, headClampMaxAngles = {50,50,10};

	if ( cent->m_iVehicleNum || cent->forceFrame || BG_SaberLockBreakAnim(cent->legsAnim) || BG_SaberLockBreakAnim(cent->torsoAnim) )
	{ //a vehicle or riding a vehicle - in either case we don't need to be in here
		vec3_t forcedAngles;

		VectorClear(forcedAngles);
		forcedAngles[YAW] = cent_lerpAngles[YAW];
		forcedAngles[ROLL] = cent_lerpAngles[ROLL];
		AnglesToAxis( forcedAngles, legs );
		VectorCopy(forcedAngles, legsAngles);
		VectorCopy(legsAngles, turAngles);

		if (cent->number < MAX_CLIENTS)
		{
			trap->G2API_SetBoneAngles(ghoul2, 0, "lower_lumbar", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			trap->G2API_SetBoneAngles(ghoul2, 0, "upper_lumbar", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			trap->G2API_SetBoneAngles(ghoul2, 0, "cranium", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			trap->G2API_SetBoneAngles(ghoul2, 0, "thoracic", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			trap->G2API_SetBoneAngles(ghoul2, 0, "cervical", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
		}
		return;
	}

	if ((time+2000) < *corrTime)
	{
		*corrTime = 0;
	}

	VectorCopy( cent_lerpAngles, headAngles );
	headAngles[YAW] = AngleMod( headAngles[YAW] );
	VectorClear( legsAngles );
	VectorClear( torsoAngles );
	// --------- yaw -------------

	// allow yaw to drift a bit
	if ((( cent->legsAnim ) != BOTH_STAND1) ||
			( cent->torsoAnim ) != WeaponReadyAnim[cent->weapon]  )
	{
		// if not standing still, always point all in the same direction
		//cent->pe.torso.yawing = qtrue;	// always center
		*tYawing = qtrue;
		//cent->pe.torso.pitching = qtrue;	// always center
		*tPitching = qtrue;
		//cent->pe.legs.yawing = qtrue;	// always center
		*lYawing = qtrue;
	}

	// adjust legs for movement dir
	if ( cent->eFlags & EF_DEAD ) {
		// don't let dead bodies twitch
		dir = 0;
	} else {
		dir = cent->angles2[YAW];
		if ( dir < 0 || dir > 7 ) {
			Com_Error( ERR_DROP, "Bad player movement angle (%i)", dir );
		}
	}

	torsoAngles[YAW] = headAngles[YAW];

	//for now, turn torso instantly and let the legs swing to follow
	*tYawAngle = torsoAngles[YAW];

	// --------- pitch -------------

	VectorCopy( cent->pos.trDelta, velocity );

	if (BG_InRoll2(cent))
	{ //don't affect angles based on vel then
		VectorClear(velocity);
	}
	else if (cent->weapon == WP_SABER &&
		BG_SaberInSpecial(cent->saberMove))
	{
		VectorClear(velocity);
	}

	speed = VectorNormalize( velocity );

	if (!speed)
	{
		torsoAngles[YAW] = headAngles[YAW];
	}

	// only show a fraction of the pitch angle in the torso
	if ( headAngles[PITCH] > 180 ) {
		dest = (-360 + headAngles[PITCH]) * 0.75;
	} else {
		dest = headAngles[PITCH] * 0.75;
	}

	if (cent->m_iVehicleNum)
	{ //swing instantly on vehicles
		*tPitchAngle = dest;
	}
	else
	{
		BG_SwingAngles( dest, 15, 30, 0.1f, tPitchAngle, tPitching, frametime );
	}
	torsoAngles[PITCH] = *tPitchAngle;

	// --------- roll -------------

	if ( speed ) {
		matrix3_t	axis;
		float	side;

		speed *= 0.05f;

		AnglesToAxis( legsAngles, axis );
		side = speed * DotProduct( velocity, axis[1] );
		legsAngles[ROLL] -= side;

		side = speed * DotProduct( velocity, axis[0] );
		legsAngles[PITCH] += side;
	}

	//legsAngles[YAW] = headAngles[YAW] + (movementOffsets[ dir ]*speed_dif);

	//rww - crazy velocity-based leg angle calculation
	legsAngles[YAW] = headAngles[YAW];
	velPos[0] = cent_lerpOrigin[0] + velocity[0];
	velPos[1] = cent_lerpOrigin[1] + velocity[1];
	velPos[2] = cent_lerpOrigin[2];// + velocity[2];

	if ( cent->groundEntityNum == ENTITYNUM_NONE ||
		cent->forceFrame ||
		(cent->weapon == WP_EMPLACED_GUN && emplaced) )
	{ //off the ground, no direction-based leg angles (same if in saberlock)
		VectorCopy(cent_lerpOrigin, velPos);
	}

	VectorSubtract(cent_lerpOrigin, velPos, velAng);

	if (!VectorCompare(velAng, vec3_origin))
	{
		vectoangles(velAng, velAng);

		if (velAng[YAW] <= legsAngles[YAW])
		{
			degrees_negative = (legsAngles[YAW] - velAng[YAW]);
			degrees_positive = (360 - legsAngles[YAW]) + velAng[YAW];
		}
		else
		{
			degrees_negative = legsAngles[YAW] + (360 - velAng[YAW]);
			degrees_positive = (velAng[YAW] - legsAngles[YAW]);
		}

		if ( degrees_negative < degrees_positive )
		{
			dif = degrees_negative;
			adddir = 0;
		}
		else
		{
			dif = degrees_positive;
			adddir = 1;
		}

		if (dif > 90)
		{
			dif = (180 - dif);
		}

		if (dif > 60)
		{
			dif = 60;
		}

		//Slight hack for when playing is running backward
		if (dir == 3 || dir == 5)
		{
			dif = -dif;
		}

		if (adddir)
		{
			legsAngles[YAW] -= dif;
		}
		else
		{
			legsAngles[YAW] += dif;
		}
	}

	if (cent->m_iVehicleNum)
	{ //swing instantly on vehicles
		*lYawAngle = legsAngles[YAW];
	}
	else
	{
		BG_SwingAngles( legsAngles[YAW], /*40*/0, 90, 0.65f, lYawAngle, lYawing, frametime );
	}
	legsAngles[YAW] = *lYawAngle;

	/*
	// pain twitch
	CG_AddPainTwitch( cent, torsoAngles );
	*/

	legsAngles[ROLL] = 0;
	torsoAngles[ROLL] = 0;

//	VectorCopy(legsAngles, turAngles);

	// pull the angles back out of the hierarchial chain
	AnglesSubtract( headAngles, torsoAngles, headAngles );
	AnglesSubtract( torsoAngles, legsAngles, torsoAngles );

	legsAngles[PITCH] = 0;

	if (cent->heldByClient)
	{ //keep the base angles clear when doing the IK stuff, it doesn't compensate for it.
	  //rwwFIXMEFIXME: Store leg angles off and add them to all the fed in angles for G2 functions?
		VectorClear(legsAngles);
		legsAngles[YAW] = cent_lerpAngles[YAW];
	}

#ifdef BONE_BASED_LEG_ANGLES
	legBoneYaw = legsAngles[YAW];
	VectorClear(legsAngles);
	legsAngles[YAW] = cent_lerpAngles[YAW];
#endif

	VectorCopy(legsAngles, turAngles);

	AnglesToAxis( legsAngles, legs );

	VectorCopy( cent_lerpAngles, viewAngles );
	viewAngles[YAW] = viewAngles[ROLL] = 0;
	viewAngles[PITCH] *= 0.5;

	VectorSet( angles, 0, legsAngles[1], 0 );

	angles[0] = legsAngles[0];
	if ( angles[0] > 30 )
	{
		angles[0] = 30;
	}
	else if ( angles[0] < -30 )
	{
		angles[0] = -30;
	}

	if (cent->weapon == WP_EMPLACED_GUN &&
		emplaced)
	{ //if using an emplaced gun, then we want to make sure we're angled to "hold" it right
		vec3_t facingAngles;

		VectorSubtract(emplaced->pos.trBase, cent_lerpOrigin, facingAngles);
		vectoangles(facingAngles, facingAngles);

		if (emplaced->weapon == WP_NONE)
		{ //e-web
			VectorCopy(facingAngles, legsAngles);
			AnglesToAxis( legsAngles, legs );
		}
		else
		{ //misc emplaced
			float emplacedDif = AngleSubtract(cent_lerpAngles[YAW], facingAngles[YAW]);

			/*
			if (emplaced->weapon == WP_NONE)
			{ //offset is a little bit different for the e-web
				emplacedDif -= 16.0f;
			}
			*/

			VectorSet(facingAngles, -16.0f, -emplacedDif, 0.0f);

			if (cent->legsAnim == BOTH_STRAFE_LEFT1 || cent->legsAnim == BOTH_STRAFE_RIGHT1)
			{ //try to adjust so it doesn't look wrong
				if (crazySmoothFactor)
				{ //want to smooth a lot during this because it chops around and looks like ass
					*crazySmoothFactor = time + 1000;
				}

				BG_G2ClientSpineAngles(ghoul2, motionBolt, cent_lerpOrigin, cent_lerpAngles, cent, time, viewAngles, ciLegs, ciTorso, angles, thoracicAngles, ulAngles, llAngles, modelScale, tPitchAngle, tYawAngle, corrTime);
				trap->G2API_SetBoneAngles(ghoul2, 0, "lower_lumbar", llAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
				trap->G2API_SetBoneAngles(ghoul2, 0, "upper_lumbar", ulAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
				trap->G2API_SetBoneAngles(ghoul2, 0, "cranium", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);

				VectorAdd(facingAngles, thoracicAngles, facingAngles);

				if (cent->legsAnim == BOTH_STRAFE_LEFT1)
				{ //this one needs some further correction
					facingAngles[YAW] -= 32.0f;
				}
			}
			else
			{
			//	trap->G2API_SetBoneAngles(ghoul2, 0, "lower_lumbar", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			//	trap->G2API_SetBoneAngles(ghoul2, 0, "upper_lumbar", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
				trap->G2API_SetBoneAngles(ghoul2, 0, "cranium", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			}

			VectorScale(facingAngles, 0.6f, facingAngles);	trap->G2API_SetBoneAngles(ghoul2, 0, "lower_lumbar", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			VectorScale(facingAngles, 0.8f, facingAngles);	trap->G2API_SetBoneAngles(ghoul2, 0, "upper_lumbar", facingAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
			VectorScale(facingAngles, 0.8f, facingAngles);	trap->G2API_SetBoneAngles(ghoul2, 0, "thoracic", facingAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);

			//Now we want the head angled toward where we are facing
			VectorSet(facingAngles, 0.0f, dif, 0.0f);
			VectorScale(facingAngles, 0.6f, facingAngles);
			trap->G2API_SetBoneAngles(ghoul2, 0, "cervical", facingAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);

			return; //don't have to bother with the rest then
		}
	}

	BG_G2ClientSpineAngles(ghoul2, motionBolt, cent_lerpOrigin, cent_lerpAngles, cent, time,
		viewAngles, ciLegs, ciTorso, angles, thoracicAngles, ulAngles, llAngles, modelScale,
		tPitchAngle, tYawAngle, corrTime);

	VectorCopy(cent_lerpAngles, eyeAngles);

	for ( i = 0; i < 3; i++ )
	{
		lookAngles[i] = AngleNormalize180( lookAngles[i] );
		eyeAngles[i] = AngleNormalize180( eyeAngles[i] );
	}
	AnglesSubtract( lookAngles, eyeAngles, lookAngles );

	BG_UpdateLookAngles(lookTime, lastHeadAngles, time, lookAngles, lookSpeed, -50.0f, 50.0f, -70.0f, 70.0f, -30.0f, 30.0f);

	BG_G2ClientNeckAngles(ghoul2, time, lookAngles, headAngles, neckAngles, thoracicAngles, headClampMinAngles, headClampMaxAngles);

#ifdef BONE_BASED_LEG_ANGLES
	{
		vec3_t bLAngles;
		VectorClear(bLAngles);
		bLAngles[ROLL] = AngleNormalize180((legBoneYaw - cent_lerpAngles[YAW]));
		strap_G2API_SetBoneAngles(ghoul2, 0, "model_root", bLAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);

		if (!llAngles[YAW])
		{
			llAngles[YAW] -= bLAngles[ROLL];
		}
	}
#endif

	trap->G2API_SetBoneAngles(ghoul2, 0, "lower_lumbar", llAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
	trap->G2API_SetBoneAngles(ghoul2, 0, "upper_lumbar", ulAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
	trap->G2API_SetBoneAngles(ghoul2, 0, "thoracic", thoracicAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
//	trap->G2API_SetBoneAngles(ghoul2, 0, "cervical", vec3_origin, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time);
}

void BG_G2ATSTAngles(void *ghoul2, int time, vec3_t cent_lerpAngles )
{//																							up			right		fwd
	trap->G2API_SetBoneAngles( ghoul2, 0, "thoracic", cent_lerpAngles, BONE_ANGLES_POSTMULT, POSITIVE_X, NEGATIVE_Y, NEGATIVE_Z, 0, 0, time );
}

static qboolean PM_AdjustAnglesForDualJumpAttack( playerState_t *ps, usercmd_t *ucmd )
{
	//ucmd->angles[PITCH] = ANGLE2SHORT( ps->viewangles[PITCH] ) - ps->delta_angles[PITCH];
	//ucmd->angles[YAW] = ANGLE2SHORT( ps->viewangles[YAW] ) - ps->delta_angles[YAW];
	return qtrue;
}

static QINLINE void PM_CmdForSaberMoves(usercmd_t *ucmd)
{
	//DUAL FORWARD+JUMP+ATTACK
	if ( (pm->ps->legsAnim == BOTH_JUMPATTACK6		&& pm->ps->saberMove == LS_JUMPATTACK_DUAL) ||
		 (pm->ps->legsAnim == BOTH_BUTTERFLY_FL1	&& pm->ps->saberMove == LS_JUMPATTACK_STAFF_LEFT) ||
		 (pm->ps->legsAnim == BOTH_BUTTERFLY_FR1	&& pm->ps->saberMove == LS_JUMPATTACK_STAFF_RIGHT) ||
		 (pm->ps->legsAnim == BOTH_BUTTERFLY_RIGHT	&& pm->ps->saberMove == LS_BUTTERFLY_RIGHT) ||
		 (pm->ps->legsAnim == BOTH_BUTTERFLY_LEFT	&& pm->ps->saberMove == LS_BUTTERFLY_LEFT) )
	{
		int aLen = PM_AnimLength(0, BOTH_JUMPATTACK6);

		ucmd->forwardmove = ucmd->rightmove = ucmd->upmove = 0;

		if ( pm->ps->legsAnim == BOTH_JUMPATTACK6 )
		{ //dual stance attack
			if ( pm->ps->legsTimer >= 100 //not at end
				&& (aLen - pm->ps->legsTimer) >= 250 ) //not in beginning
			{ //middle of anim
				//push forward
				ucmd->forwardmove = 127;
			}

			if ( (pm->ps->legsTimer >= 900 //not at end
					&& aLen - pm->ps->legsTimer >= 950 ) //not in beginning
				|| ( pm->ps->legsTimer >= 1600
					&& aLen - pm->ps->legsTimer >= 400 ) ) //not in beginning
			{ //one of the two jumps
				if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
				{ //still on ground?
					if ( pm->ps->groundEntityNum >= MAX_CLIENTS )
					{
						//jump!
						pm->ps->velocity[2] = 250;//400;
						pm->ps->fd.forceJumpZStart = pm->ps->origin[2];//so we don't take damage if we land at same height
						//pm->ps->pm_flags |= PMF_JUMPING;
						//FIXME: NPCs yell?
						PM_AddEvent(EV_JUMP);
						//G_SoundOnEnt( ent, CHAN_BODY, "sound/weapons/force/jump.wav" );
					}
				}
				else
				{ //FIXME: if this is the second jump, maybe we should just stop the anim?
				}
			}
		}
		else
		{ //saberstaff attacks
			float lenMin = 1700.0f;
			float lenMax = 1800.0f;

			aLen = PM_AnimLength(0, (animNumber_t)pm->ps->legsAnim);

			if (pm->ps->legsAnim == BOTH_BUTTERFLY_LEFT)
			{
				lenMin = 1200.0f;
				lenMax = 1400.0f;
			}

			//FIXME: don't slide off people/obstacles?
			if ( pm->ps->legsAnim == BOTH_BUTTERFLY_RIGHT
				|| pm->ps->legsAnim == BOTH_BUTTERFLY_LEFT )
			{
				if ( pm->ps->legsTimer > 450 )
				{
					switch ( pm->ps->legsAnim )
					{
						case BOTH_BUTTERFLY_LEFT:
							ucmd->rightmove = -127;
							break;
						case BOTH_BUTTERFLY_RIGHT:
							ucmd->rightmove = 127;
							break;
						default:
							break;
					}
				}
			}
			else
			{
				if ( pm->ps->legsTimer >= 100 //not at end
					&& aLen - pm->ps->legsTimer >= 250 )//not in beginning
				{//middle of anim
					//push forward
					ucmd->forwardmove = 127;
				}
			}

			if ( pm->ps->legsTimer >= lenMin && pm->ps->legsTimer < lenMax )
			{//one of the two jumps
				if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
				{//still on ground?
					//jump!
					if (pm->ps->legsAnim == BOTH_BUTTERFLY_LEFT)
					{
						pm->ps->velocity[2] = 350;
					}
					else
					{
						pm->ps->velocity[2] = 250;
					}
					pm->ps->fd.forceJumpZStart = pm->ps->origin[2];//so we don't take damage if we land at same height
					//pm->ps->pm_flags |= PMF_JUMPING;//|PMF_SLOW_MO_FALL;
					//FIXME: NPCs yell?
					PM_AddEvent(EV_JUMP);
					//G_SoundOnEnt( ent, CHAN_BODY, "sound/weapons/force/jump.wav" );
				}
				else
				{//FIXME: if this is the second jump, maybe we should just stop the anim?
				}
			}
		}

		if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
		{//can only turn when your feet hit the ground
			if (PM_AdjustAnglesForDualJumpAttack(pm->ps, ucmd))
			{
				PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, ucmd);
			}
		}
		//rwwFIXMEFIXME: Bother with bbox resizing like sp?
	}
	//STAFF BACK+JUMP+ATTACK
	else if (pm->ps->saberMove == LS_A_BACKFLIP_ATK &&
		pm->ps->legsAnim == BOTH_JUMPATTACK7)
	{
		int aLen = PM_AnimLength(0, BOTH_JUMPATTACK7);

		if ( pm->ps->legsTimer > 800 //not at end
			&& aLen - pm->ps->legsTimer >= 400 )//not in beginning
		{//middle of anim
			if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
			{//still on ground?
				vec3_t yawAngles, backDir;


#ifdef _GAME
				gclient_t *client = NULL;
				{
					int clientNum = pm->ps->clientNum;
					if (0 <= clientNum && clientNum < MAX_CLIENTS) {
							client = g_entities[clientNum].client;
					}
				}

				if (client && client->lastKickTime + 50 < level.time) //japro serverside flood protect on staff dfa, use the same debouncer as flipkick i guess
#endif
				{

					//push backwards some?
					VectorSet( yawAngles, 0, pm->ps->viewangles[YAW]+180, 0 );
					AngleVectors( yawAngles, backDir, 0, 0 );
					VectorScale( backDir, 100, pm->ps->velocity );

					//jump!
					pm->ps->velocity[2] = 300;
					pm->ps->fd.forceJumpZStart = pm->ps->origin[2]; //so we don't take damage if we land at same height
					//pm->ps->pm_flags |= PMF_JUMPING;//|PMF_SLOW_MO_FALL;

					//FIXME: NPCs yell?
					PM_AddEvent(EV_JUMP);
					//G_SoundOnEnt( ent, CHAN_BODY, "sound/weapons/force/jump.wav" );
					ucmd->upmove = 0; //clear any actual jump command

#ifdef _GAME
					if (client) {
						client->lastKickTime = level.time;
					}
#endif

				}


			}
		}
		ucmd->forwardmove = ucmd->rightmove = ucmd->upmove = 0;
	}
	//STAFF/DUAL SPIN ATTACK
	else if (pm->ps->saberMove == LS_SPINATTACK ||
		pm->ps->saberMove == LS_SPINATTACK_DUAL)
	{
		ucmd->forwardmove = ucmd->rightmove = ucmd->upmove = 0;
		//lock their viewangles during these attacks.
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, ucmd);
	}
}

//constrain him based on the angles of his vehicle and the caps
void PM_VehicleViewAngles(playerState_t *ps, bgEntity_t *veh, usercmd_t *ucmd)
{
	Vehicle_t *pVeh = veh->m_pVehicle;
	qboolean setAngles = qfalse;
	vec3_t clampMin;
	vec3_t clampMax;
	int i;

	if ( veh->m_pVehicle->m_pPilot
		&& veh->m_pVehicle->m_pPilot->s.number == ps->clientNum )
	{//set the pilot's viewangles to the vehicle's viewangles
#ifdef VEH_CONTROL_SCHEME_4
		if ( 1 )
#else //VEH_CONTROL_SCHEME_4
		if ( !BG_UnrestrainedPitchRoll( ps, veh->m_pVehicle ) )
#endif //VEH_CONTROL_SCHEME_4
		{//only if not if doing special free-roll/pitch control
			setAngles = qtrue;
			clampMin[PITCH] = -pVeh->m_pVehicleInfo->lookPitch;
			clampMax[PITCH] = pVeh->m_pVehicleInfo->lookPitch;
			clampMin[YAW] = clampMax[YAW] = 0;
			clampMin[ROLL] = clampMax[ROLL] = -1;
		}
	}
	else
	{
		//NOTE: passengers can look around freely, UNLESS they're controlling a turret!
		for ( i = 0; i < MAX_VEHICLE_TURRETS; i++ )
		{
			if ( veh->m_pVehicle->m_pVehicleInfo->turret[i].passengerNum == ps->generic1 )
			{//this turret is my station
				setAngles = qtrue;
				clampMin[PITCH] = veh->m_pVehicle->m_pVehicleInfo->turret[i].pitchClampUp;
				clampMax[PITCH] = veh->m_pVehicle->m_pVehicleInfo->turret[i].pitchClampDown;
				clampMin[YAW] = veh->m_pVehicle->m_pVehicleInfo->turret[i].yawClampRight;
				clampMax[YAW] = veh->m_pVehicle->m_pVehicleInfo->turret[i].yawClampLeft;
				clampMin[ROLL] = clampMax[ROLL] = 0;
				break;
			}
		}
	}
	if ( setAngles )
	{
		for ( i = 0; i < 3; i++ )
		{//clamp viewangles
			if ( clampMin[i] == -1 || clampMax[i] == -1 )
			{//no clamp
			}
			else if ( !clampMin[i] && !clampMax[i] )
			{//no allowance
				//ps->viewangles[i] = veh->playerState->viewangles[i];
			}
			else
			{//allowance
				if (ps->viewangles[i] > clampMax[i])
				{
					ps->viewangles[i] = clampMax[i];
				}
				else if (ps->viewangles[i] < clampMin[i])
				{
					ps->viewangles[i] = clampMin[i];
				}
			}
		}

		PM_SetPMViewAngle(ps, ps->viewangles, ucmd);
	}
}

/*
//constrain him based on the angles of his vehicle and the caps
void PM_VehicleViewAngles(playerState_t *ps, bgEntity_t *veh, usercmd_t *ucmd)
{
	Vehicle_t *pVeh = veh->m_pVehicle;

	//now set the viewangles to the vehicle's directly
	ps->viewangles[YAW] = veh->playerState->viewangles[YAW];

	//constrain the viewangles pitch based on the vehicle properties
	if ( !pVeh->m_pVehicleInfo->lookPitch )
	{//not allowed to look up & down!  ....???
		ps->viewangles[PITCH] = veh->playerState->viewangles[PITCH];
	}
	else
	{//clamp
		if (ps->viewangles[PITCH] > pVeh->m_pVehicleInfo->lookPitch)
		{
			ps->viewangles[PITCH] = pVeh->m_pVehicleInfo->lookPitch;
		}
		else if (ps->viewangles[PITCH] < -pVeh->m_pVehicleInfo->lookPitch)
		{
			ps->viewangles[PITCH] = -pVeh->m_pVehicleInfo->lookPitch;
		}
	}

	PM_SetPMViewAngle(ps, ps->viewangles, ucmd);
}
*/
//see if a weapon is ok to use on a vehicle
qboolean PM_WeaponOkOnVehicle( int weapon )
{
	//FIXME: check g_vehicleInfo for our vehicle?
	switch ( weapon )
	{
	//case WP_NONE:
	case WP_MELEE:
	case WP_SABER:
	case WP_BLASTER:
	//case WP_THERMAL:
		return qtrue;
		break;
	}
	return qfalse;
}

//do we have a weapon that's ok for using on the vehicle?
int PM_GetOkWeaponForVehicle(void)
{
	int i = 0;

	while (i < WP_NUM_WEAPONS)
	{
		if ((pm->ps->stats[STAT_WEAPONS] & (1 << i)) &&
			PM_WeaponOkOnVehicle(i))
		{ //this one's good
			return i;
		}

		i++;
	}

	//oh dear!
	//assert(!"No valid veh weaps");
	return -1;
}

//force the vehicle to turn and travel to its forced destination point
void PM_VehForcedTurning(bgEntity_t *veh)
{
	bgEntity_t *dst = PM_BGEntForNum(veh->playerState->vehTurnaroundIndex);
	float pitchD, yawD;
	vec3_t dir;

	if (!veh || !veh->m_pVehicle)
	{
		return;
	}

	if (!dst)
	{ //can't find dest ent?
		return;
	}

	pm->cmd.upmove = veh->m_pVehicle->m_ucmd.upmove = 127;
	pm->cmd.forwardmove = veh->m_pVehicle->m_ucmd.forwardmove = 0;
	pm->cmd.rightmove = veh->m_pVehicle->m_ucmd.rightmove = 0;

	VectorSubtract(dst->s.origin, veh->playerState->origin, dir);
	vectoangles(dir, dir);

	yawD = AngleSubtract(pm->ps->viewangles[YAW], dir[YAW]);
	pitchD = AngleSubtract(pm->ps->viewangles[PITCH], dir[PITCH]);

	yawD *= 0.6f*pml.frametime;
	pitchD *= 0.6f*pml.frametime;

#ifdef VEH_CONTROL_SCHEME_4
	veh->playerState->viewangles[YAW] = AngleSubtract(veh->playerState->viewangles[YAW], yawD);
	veh->playerState->viewangles[PITCH] = AngleSubtract(veh->playerState->viewangles[PITCH], pitchD);
	pm->ps->viewangles[YAW] = veh->playerState->viewangles[YAW];
	pm->ps->viewangles[PITCH] = 0;

	PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	PM_SetPMViewAngle(veh->playerState, veh->playerState->viewangles, &pm->cmd);
	VectorClear( veh->m_pVehicle->m_vPrevRiderViewAngles );
	veh->m_pVehicle->m_vPrevRiderViewAngles[YAW] = AngleNormalize180(pm->ps->viewangles[YAW]);

#else //VEH_CONTROL_SCHEME_4

	pm->ps->viewangles[YAW] = AngleSubtract(pm->ps->viewangles[YAW], yawD);
	pm->ps->viewangles[PITCH] = AngleSubtract(pm->ps->viewangles[PITCH], pitchD);

	PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
#endif //VEH_CONTROL_SCHEME_4
}

#ifdef VEH_CONTROL_SCHEME_4
void PM_VehFaceHyperspacePoint(bgEntity_t *veh)
{

	if (!veh || !veh->m_pVehicle)
	{
		return;
	}
	else
	{
		float timeFrac = ((float)(pm->cmd.serverTime-veh->playerState->hyperSpaceTime))/HYPERSPACE_TIME;
		float	turnRate, aDelta;
		int		i, matchedAxes = 0;

		pm->cmd.upmove = veh->m_pVehicle->m_ucmd.upmove = 127;
		pm->cmd.forwardmove = veh->m_pVehicle->m_ucmd.forwardmove = 0;
		pm->cmd.rightmove = veh->m_pVehicle->m_ucmd.rightmove = 0;

		turnRate = (90.0f*pml.frametime);
		for ( i = 0; i < 3; i++ )
		{
			aDelta = AngleSubtract(veh->playerState->hyperSpaceAngles[i], veh->m_pVehicle->m_vOrientation[i]);
			if ( fabs( aDelta ) < turnRate )
			{//all is good
				veh->playerState->viewangles[i] = veh->playerState->hyperSpaceAngles[i];
				matchedAxes++;
			}
			else
			{
				aDelta = AngleSubtract(veh->playerState->hyperSpaceAngles[i], veh->playerState->viewangles[i]);
				if ( fabs( aDelta ) < turnRate )
				{
					veh->playerState->viewangles[i] = veh->playerState->hyperSpaceAngles[i];
				}
				else if ( aDelta > 0 )
				{
					if ( i == YAW )
					{
						veh->playerState->viewangles[i] = AngleNormalize360( veh->playerState->viewangles[i]+turnRate );
					}
					else
					{
						veh->playerState->viewangles[i] = AngleNormalize180( veh->playerState->viewangles[i]+turnRate );
					}
				}
				else
				{
					if ( i == YAW )
					{
						veh->playerState->viewangles[i] = AngleNormalize360( veh->playerState->viewangles[i]-turnRate );
					}
					else
					{
						veh->playerState->viewangles[i] = AngleNormalize180( veh->playerState->viewangles[i]-turnRate );
					}
				}
			}
		}

		pm->ps->viewangles[YAW] = veh->playerState->viewangles[YAW];
		pm->ps->viewangles[PITCH] = 0.0f;

		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
		PM_SetPMViewAngle(veh->playerState, veh->playerState->viewangles, &pm->cmd);
		VectorClear( veh->m_pVehicle->m_vPrevRiderViewAngles );
		veh->m_pVehicle->m_vPrevRiderViewAngles[YAW] = AngleNormalize180(pm->ps->viewangles[YAW]);

		if ( timeFrac < HYPERSPACE_TELEPORT_FRAC )
		{//haven't gone through yet
			if ( matchedAxes < 3 )
			{//not facing the right dir yet
				//keep hyperspace time up to date
				veh->playerState->hyperSpaceTime += pml.msec;
			}
			else if ( !(veh->playerState->eFlags2&EF2_HYPERSPACE))
			{//flag us as ready to hyperspace!
				veh->playerState->eFlags2 |= EF2_HYPERSPACE;
			}
		}
	}
}

#else //VEH_CONTROL_SCHEME_4

void PM_VehFaceHyperspacePoint(bgEntity_t *veh)
{

	if (!veh || !veh->m_pVehicle)
	{
		return;
	}
	else
	{
		float timeFrac = ((float)(pm->cmd.serverTime-veh->playerState->hyperSpaceTime))/HYPERSPACE_TIME;
		float	turnRate, aDelta;
		int		i, matchedAxes = 0;

		pm->cmd.upmove = veh->m_pVehicle->m_ucmd.upmove = 127;
		pm->cmd.forwardmove = veh->m_pVehicle->m_ucmd.forwardmove = 0;
		pm->cmd.rightmove = veh->m_pVehicle->m_ucmd.rightmove = 0;

		turnRate = (90.0f*pml.frametime);
		for ( i = 0; i < 3; i++ )
		{
			aDelta = AngleSubtract(veh->playerState->hyperSpaceAngles[i], veh->m_pVehicle->m_vOrientation[i]);
			if ( fabs( aDelta ) < turnRate )
			{//all is good
				pm->ps->viewangles[i] = veh->playerState->hyperSpaceAngles[i];
				matchedAxes++;
			}
			else
			{
				aDelta = AngleSubtract(veh->playerState->hyperSpaceAngles[i], pm->ps->viewangles[i]);
				if ( fabs( aDelta ) < turnRate )
				{
					pm->ps->viewangles[i] = veh->playerState->hyperSpaceAngles[i];
				}
				else if ( aDelta > 0 )
				{
					if ( i == YAW )
					{
						pm->ps->viewangles[i] = AngleNormalize360( pm->ps->viewangles[i]+turnRate );
					}
					else
					{
						pm->ps->viewangles[i] = AngleNormalize180( pm->ps->viewangles[i]+turnRate );
					}
				}
				else
				{
					if ( i == YAW )
					{
						pm->ps->viewangles[i] = AngleNormalize360( pm->ps->viewangles[i]-turnRate );
					}
					else
					{
						pm->ps->viewangles[i] = AngleNormalize180( pm->ps->viewangles[i]-turnRate );
					}
				}
			}
		}

		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);

		if ( timeFrac < HYPERSPACE_TELEPORT_FRAC )
		{//haven't gone through yet
			if ( matchedAxes < 3 )
			{//not facing the right dir yet
				//keep hyperspace time up to date
				veh->playerState->hyperSpaceTime += pml.msec;
			}
			else if ( !(veh->playerState->eFlags2&EF2_HYPERSPACE))
			{//flag us as ready to hyperspace!
				veh->playerState->eFlags2 |= EF2_HYPERSPACE;
			}
		}
	}
}

#endif //VEH_CONTROL_SCHEME_4

void BG_VehicleAdjustBBoxForOrientation( Vehicle_t *veh, vec3_t origin, vec3_t mins, vec3_t maxs,
										int clientNum, int tracemask,
										void (*localTrace)(trace_t *results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentMask))
{
	if ( !veh
		|| !veh->m_pVehicleInfo->length
		|| !veh->m_pVehicleInfo->width
		|| !veh->m_pVehicleInfo->height )
		//|| veh->m_LandTrace.fraction < 1.0f )
	{
		return;
	}
	else if ( veh->m_pVehicleInfo->type != VH_FIGHTER
		//&& veh->m_pVehicleInfo->type != VH_SPEEDER
		&& veh->m_pVehicleInfo->type != VH_FLIER )
	{//only those types of vehicles have dynamic bboxes, the rest just use a static bbox
		VectorSet( maxs, veh->m_pVehicleInfo->width/2.0f, veh->m_pVehicleInfo->width/2.0f, veh->m_pVehicleInfo->height+DEFAULT_MINS_2 );
		VectorSet( mins, veh->m_pVehicleInfo->width/-2.0f, veh->m_pVehicleInfo->width/-2.0f, DEFAULT_MINS_2 );
		return;
	}
	else
	{
		matrix3_t	axis;
		vec3_t		point[8], newMins, newMaxs;
		int			curAxis = 0, i;
		trace_t		trace;

		AnglesToAxis( veh->m_vOrientation, axis );
		VectorMA( origin, veh->m_pVehicleInfo->length/2.0f, axis[0], point[0] );
		VectorMA( origin, -veh->m_pVehicleInfo->length/2.0f, axis[0], point[1] );
		//extrapolate each side up and down
		VectorMA( point[0], veh->m_pVehicleInfo->height/2.0f, axis[2], point[0] );
		VectorMA( point[0], -veh->m_pVehicleInfo->height, axis[2], point[2] );
		VectorMA( point[1], veh->m_pVehicleInfo->height/2.0f, axis[2], point[1] );
		VectorMA( point[1], -veh->m_pVehicleInfo->height, axis[2], point[3] );

		VectorMA( origin, veh->m_pVehicleInfo->width/2.0f, axis[1], point[4] );
		VectorMA( origin, -veh->m_pVehicleInfo->width/2.0f, axis[1], point[5] );
		//extrapolate each side up and down
		VectorMA( point[4], veh->m_pVehicleInfo->height/2.0f, axis[2], point[4] );
		VectorMA( point[4], -veh->m_pVehicleInfo->height, axis[2], point[6] );
		VectorMA( point[5], veh->m_pVehicleInfo->height/2.0f, axis[2], point[5] );
		VectorMA( point[5], -veh->m_pVehicleInfo->height, axis[2], point[7] );
		/*
		VectorMA( origin, veh->m_pVehicleInfo->height/2.0f, axis[2], point[4] );
		VectorMA( origin, -veh->m_pVehicleInfo->height/2.0f, axis[2], point[5] );
		*/
		//Now inflate a bbox around these points
		VectorCopy( origin, newMins );
		VectorCopy( origin, newMaxs );
		for ( curAxis = 0; curAxis < 3; curAxis++ )
		{
			for ( i = 0; i < 8; i++ )
			{
				if ( point[i][curAxis] > newMaxs[curAxis] )
				{
					newMaxs[curAxis] = point[i][curAxis];
				}
				else if ( point[i][curAxis] < newMins[curAxis] )
				{
					newMins[curAxis] = point[i][curAxis];
				}
			}
		}
		VectorSubtract( newMins, origin, newMins );
		VectorSubtract( newMaxs, origin, newMaxs );
		//now see if that's a valid way to be
		if (localTrace)
		{
			localTrace( &trace, origin, newMins, newMaxs, origin, clientNum, tracemask );
		}
		else
		{ //don't care about solid stuff then
			trace.startsolid = trace.allsolid = 0;
		}
		if ( !trace.startsolid && !trace.allsolid )
		{//let's use it!
			VectorCopy( newMins, mins );
			VectorCopy( newMaxs, maxs );
		}
		//else: just use the last one, I guess...?
		//FIXME: make it as close as possible?  Or actually prevent the change in m_vOrientation?  Or push away from anything we hit?
	}
}
/*
================
PmoveSingle

================
*/
extern int BG_EmplacedView(vec3_t baseAngles, vec3_t angles, float *newYaw, float constraint);
extern qboolean BG_FighterUpdate(Vehicle_t *pVeh, const usercmd_t *pUcmd, vec3_t trMins, vec3_t trMaxs, float gravity,
					  void (*traceFunc)( trace_t *results, const vec3_t start, const vec3_t lmins, const vec3_t lmaxs, const vec3_t end, int passEntityNum, int contentMask )); //FighterNPC.c

#define JETPACK_HOVER_HEIGHT	64

//#define _TESTING_VEH_PREDICTION

void PM_MoveForKata(usercmd_t *ucmd)
{
	if ( pm->ps->legsAnim == BOTH_A7_SOULCAL
		&& pm->ps->saberMove == LS_STAFF_SOULCAL )
	{//forward spinning staff attack
		ucmd->upmove = 0;

		if ( PM_CanRollFromSoulCal( pm->ps ) )
		{
			ucmd->upmove = -127;
			ucmd->rightmove = 0;
			if (ucmd->forwardmove < 0)
			{
				ucmd->forwardmove = 0;
			}
		}
		else
		{
			ucmd->rightmove = 0;
			//FIXME: don't slide off people/obstacles?
			if ( pm->ps->legsTimer >= 2750 )
			{//not at end
				//push forward
				ucmd->forwardmove = 64;
			}
			else
			{
				ucmd->forwardmove = 0;
			}
		}
		if ( pm->ps->legsTimer >= 2650
			&& pm->ps->legsTimer < 2850 )
		{//the jump
			if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
			{//still on ground?
				//jump!
				pm->ps->velocity[2] = 250;
				pm->ps->fd.forceJumpZStart = pm->ps->origin[2];//so we don't take damage if we land at same height
			//	pm->ps->pm_flags |= PMF_JUMPING;//|PMF_SLOW_MO_FALL;
				//FIXME: NPCs yell?
				PM_AddEvent(EV_JUMP);
			}
		}
	}
	else if (pm->ps->legsAnim == BOTH_A2_SPECIAL)
	{ //medium kata
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
		if (pm->ps->legsTimer < 2700 && pm->ps->legsTimer > 2300)
		{
			pm->cmd.forwardmove = 127;
		}
		else if (pm->ps->legsTimer < 900 && pm->ps->legsTimer > 500)
		{
			pm->cmd.forwardmove = 127;
		}
		else
		{
			pm->cmd.forwardmove = 0;
		}
	}
	else if (pm->ps->legsAnim == BOTH_A3_SPECIAL)
	{ //strong kata
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
		if (pm->ps->legsTimer < 1700 && pm->ps->legsTimer > 1000)
		{
			pm->cmd.forwardmove = 127;
		}
		else
		{
			pm->cmd.forwardmove = 0;
		}
	}
	else
	{
		pm->cmd.forwardmove = 0;
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
	}
}

/*
static QINLINE float bg_roundfloat(float n)
{
	return (n < 0.0f) ? ceilf(n - 0.5f) : floorf(n + 0.5f);
}*/

void PmoveSingle (pmove_t *pmove) {
	qboolean stiffenedUp = qfalse;
	float gDist = 0;
	qboolean noAnimate = qfalse;
	int savedGravity = 0;

	pm = pmove;

#ifdef _CGAME
	if (cgs.serverMod != SVMOD_JAPLUS || pm->ps->weapon != WP_MELEE) {
#endif
		if (pm->cmd.buttons & BUTTON_ATTACK && pm->cmd.buttons & BUTTON_USE_HOLDABLE)
		{
			pm->cmd.buttons &= ~BUTTON_ATTACK;
			pm->cmd.buttons &= ~BUTTON_USE_HOLDABLE;
		}
		if (pm->cmd.buttons & BUTTON_ALT_ATTACK && pm->cmd.buttons & BUTTON_USE_HOLDABLE)
		{
			pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			pm->cmd.buttons &= ~BUTTON_USE_HOLDABLE;
		}
#ifdef _CGAME
	}
#endif

	if (pm->ps->emplacedIndex)
	{
		if (pm->cmd.buttons & BUTTON_ALT_ATTACK)
		{ //hackerrific.
			pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
			pm->cmd.buttons |= BUTTON_ATTACK;
		}
	}

	//set up these "global" bg ents
	pm_entSelf = PM_BGEntForNum(pm->ps->clientNum);
	if (pm->ps->m_iVehicleNum)
	{
		if (pm->ps->clientNum < MAX_CLIENTS)
		{ //player riding vehicle
			pm_entVeh = PM_BGEntForNum(pm->ps->m_iVehicleNum);
		}
		else
		{ //vehicle with player pilot
			pm_entVeh = PM_BGEntForNum(pm->ps->m_iVehicleNum-1);
		}
	}
	else
	{ //no vehicle ent
		pm_entVeh = NULL;
	}

	gPMDoSlowFall = PM_DoSlowFall();

	// this counter lets us debug movement problems with a journal
	// by setting a conditional breakpoint fot the previous frame
	c_pmove++;

	// clear results
	pm->numtouch = 0;
	pm->watertype = 0;
	pm->waterlevel = 0;

	if (PM_IsRocketTrooper())
	{ //kind of nasty, don't let them crouch or anything if nonhumanoid (probably a rockettrooper)
		if (pm->cmd.upmove < 0)
		{
			pm->cmd.upmove = 0;
		}
	}

	if (pm->ps->pm_type == PM_FLOAT)
	{ //You get no control over where you go in grip movement
		stiffenedUp = qtrue;
	}
	else if (pm->ps->eFlags & EF_DISINTEGRATION)
	{
		stiffenedUp = qtrue;
	}
	else if ( BG_SaberLockBreakAnim( pm->ps->legsAnim )
		|| BG_SaberLockBreakAnim( pm->ps->torsoAnim )
		|| pm->ps->saberLockTime >= pm->cmd.serverTime )
	{//can't move or turn
		stiffenedUp = qtrue;
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	}
	else if ( pm->ps->saberMove == LS_A_BACK || pm->ps->saberMove == LS_A_BACK_CR ||
		pm->ps->saberMove == LS_A_BACKSTAB || pm->ps->saberMove == LS_A_FLIP_STAB ||
		pm->ps->saberMove == LS_A_FLIP_SLASH || pm->ps->saberMove == LS_A_JUMP_T__B_ ||
		pm->ps->saberMove == LS_DUAL_LR || pm->ps->saberMove == LS_DUAL_FB)
	{
		if (pm->ps->legsAnim == BOTH_JUMPFLIPSTABDOWN ||
			pm->ps->legsAnim == BOTH_JUMPFLIPSLASHDOWN1)
		{ //flipover medium stance attack
			if (pm->ps->legsTimer < 1600 && pm->ps->legsTimer > 900)
			{
//[JAPRO - Serverside - Saber - Tweak yellow dfa - Start]
#ifdef _GAME
				if (!(g_tweakSaber.integer & ST_FIXYELLOWDFA))
#else
				if (!((cgs.cinfo & JAPLUS_CINFO_YELLOWDFA) || (cgs.jcinfo & JAPRO_CINFO_YELLOWDFA)))
#endif

				{
					pm->ps->viewangles[YAW] += pml.frametime*240.0f;
					PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
				}
//[JAPRO - Serverside - Saber - Tweak yellow dfa - Start]
			}
		}
		stiffenedUp = qtrue;
	}
	else if ((pm->ps->legsAnim) == (BOTH_A2_STABBACK1) ||
		(pm->ps->legsAnim) == (BOTH_ATTACK_BACK) ||
		(pm->ps->legsAnim) == (BOTH_CROUCHATTACKBACK1) ||
		(pm->ps->legsAnim) == (BOTH_FORCELEAP2_T__B_) ||
		(pm->ps->legsAnim) == (BOTH_JUMPFLIPSTABDOWN) ||
		(pm->ps->legsAnim) == (BOTH_JUMPFLIPSLASHDOWN1))
	{
		stiffenedUp = qtrue;
	}
	else if (pm->ps->legsAnim == BOTH_ROLL_STAB)
	{
		stiffenedUp = qtrue;
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	}
	else if (pm->ps->heldByClient)
	{
		stiffenedUp = qtrue;
	}
	else if (BG_KickMove(pm->ps->saberMove) || BG_KickingAnim(pm->ps->legsAnim))
	{
		stiffenedUp = qtrue;
	}
	else if (BG_InGrappleMove(pm->ps->torsoAnim))
	{
		stiffenedUp = qtrue;
#ifdef _GAME
		if (!(g_tweakForce.integer & FT_BUFFMELEE) || (BG_InGrappleMove(pm->ps->torsoAnim) == 3))
#endif
			PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	}
	else if ( pm->ps->saberMove == LS_STABDOWN_DUAL ||
			pm->ps->saberMove == LS_STABDOWN_STAFF ||
			pm->ps->saberMove == LS_STABDOWN)
	{//FIXME: need to only move forward until we bump into our target...?
		if (pm->ps->legsTimer < 800)
		{ //freeze movement near end of anim
			stiffenedUp = qtrue;
			PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
		}
		else
		{ //force forward til then
            pm->cmd.rightmove = 0;
			pm->cmd.upmove = 0;
			pm->cmd.forwardmove = 64;
		}
	}
	else if (pm->ps->saberMove == LS_PULL_ATTACK_STAB ||
		pm->ps->saberMove == LS_PULL_ATTACK_SWING)
	{
		stiffenedUp = qtrue;
	}
	else if (BG_SaberInKata(pm->ps->saberMove) ||
			 BG_InKataAnim(pm->ps->torsoAnim) ||
			 BG_InKataAnim(pm->ps->legsAnim))
	{
		PM_MoveForKata(&pm->cmd);
	}
	else if ( BG_FullBodyTauntAnim( pm->ps->legsAnim )
		&& BG_FullBodyTauntAnim( pm->ps->torsoAnim ) )
	{
		if ( (pm->cmd.buttons&BUTTON_ATTACK)
			|| (pm->cmd.buttons&BUTTON_ALT_ATTACK)
			|| (pm->cmd.buttons&BUTTON_FORCEPOWER)
			|| (pm->cmd.buttons&BUTTON_FORCEGRIP)
			|| (pm->cmd.buttons&BUTTON_FORCE_LIGHTNING)
			|| (pm->cmd.buttons&BUTTON_FORCE_DRAIN)
			|| pm->cmd.upmove )
		{//stop the anim
			if ( pm->ps->legsAnim == BOTH_MEDITATE
				&& pm->ps->torsoAnim == BOTH_MEDITATE )
			{
				PM_SetAnim( SETANIM_BOTH, BOTH_MEDITATE_END, SETANIM_FLAG_OVERRIDE|SETANIM_FLAG_HOLD );
			}
			else
			{
				pm->ps->legsTimer = pm->ps->torsoTimer = 0;
			}
			if ( pm->ps->forceHandExtend == HANDEXTEND_TAUNT )
			{
				pm->ps->forceHandExtend = 0;
			}
		}
		else
		{
			if ( pm->ps->legsAnim == BOTH_MEDITATE )
			{
				if ( pm->ps->legsTimer < 100 )
				{
					pm->ps->legsTimer = 100;
				}
			}
			if ( pm->ps->torsoAnim == BOTH_MEDITATE )
			{
				if ( pm->ps->torsoTimer < 100 )
				{
					pm->ps->legsTimer = 100;
				}
				pm->ps->forceHandExtend = HANDEXTEND_TAUNT;
				pm->ps->forceHandExtendTime = pm->cmd.serverTime + 100;
				stiffenedUp = qtrue;
//[JAPRO - Serverside +clientside - Physics - Unlock bow movement/turning- Start]
#ifdef _CGAME
				if (cgs.serverMod >= SVMOD_JAPLUS)
				{
				}
				else
				{
					PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
				}
#endif
				//if emotedisable baseduel, lock player view here like in basejk
				pm->cmd.rightmove = 0;
				pm->cmd.upmove = 0;
				pm->cmd.forwardmove = 0;
				//pm->cmd.buttons = 0; //let chatbox show in meditate
			}
			else if ( pm->ps->legsTimer > 0 || pm->ps->torsoTimer > 0 )
			{
#ifdef _CGAME
				if (cgs.serverMod >= SVMOD_JAPLUS)
				{
				}
				else
				{
					stiffenedUp = qtrue;
					PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
					pm->cmd.rightmove = 0;
					pm->cmd.upmove = 0;
					pm->cmd.forwardmove = 0;
					pm->cmd.buttons = 0;
				}
#endif
//[JAPRO - Serverside +clientside - Physics - Unlock bow movement/turning- End]
			}
		}
	}
	else if ( pm->ps->legsAnim == BOTH_MEDITATE_END
		&& pm->ps->legsTimer > 0 )
	{
		stiffenedUp = qtrue;
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
        pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
		pm->cmd.forwardmove = 0;
		//pm->cmd.buttons = 0;
	}
	else if (pm->ps->legsAnim == BOTH_FORCELAND1 ||
		pm->ps->legsAnim == BOTH_FORCELANDBACK1 ||
		pm->ps->legsAnim == BOTH_FORCELANDRIGHT1 ||
		pm->ps->legsAnim == BOTH_FORCELANDLEFT1)
	{ //can't move while in a force land
		stiffenedUp = qtrue;
	}

	if ( pm->ps->saberMove == LS_A_LUNGE )
	{//can't move during lunge
		pm->cmd.rightmove = pm->cmd.upmove = 0;
		if ( pm->ps->legsTimer > 500 )
		{
			pm->cmd.forwardmove = 127;
		}
		else
		{
			pm->cmd.forwardmove = 0;
		}
	}

	if ( pm->ps->saberMove == LS_A_JUMP_T__B_ )
	{//can't move during leap
		if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
		{//hit the ground
			pm->cmd.forwardmove = 0;
		}
		pm->cmd.rightmove = pm->cmd.upmove = 0;
	}

#ifdef _CGAME
	if (cgs.serverMod == SVMOD_JAPLUS) { //some JA+ animation support...
		if (pm->ps->legsAnim == BOTH_JUMP_BACKFLIP_ATCKEE || pm->ps->torsoAnim == BOTH_JUMP_BACKFLIP_ATCKEE
			|| pm->ps->torsoAnim == BOTH_GETUP1 || pm->ps->torsoAnim == BOTH_NEW_STABEE
			|| (pm->ps->legsAnim >= BOTH_KISSEE && pm->ps->legsAnim <= BOTH_LEDGE_MERCPULL))
		{
			PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
			stiffenedUp = qtrue;
		}
		else if ((pm->ps->legsAnim >= BOTH_MELEE_BACKKICK && pm->ps->legsAnim <= BOTH_MELEE_SPINKICK)
			|| pm->ps->legsAnim == BOTH_JUMP_BACKFLIP_ATCK || pm->ps->torsoAnim == BOTH_JUMP_BACKFLIP_ATCK)
			stiffenedUp = qtrue;
	}
#endif

	if (pm->ps->emplacedIndex)
	{
		if (pm->cmd.forwardmove < 0 || PM_GroundDistance() > 32.0f)
		{
			pm->ps->emplacedIndex = 0;
			pm->ps->saberHolstered = 0;
		}
		else
		{
			stiffenedUp = qtrue;
		}
	}

	/*
	if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->weaponstate == WEAPON_CHARGING_ALT)
	{ //not allowed to move while charging the disruptor
		pm->cmd.forwardmove = 0;
		pm->cmd.rightmove = 0;
		if (pm->cmd.upmove > 0)
		{
			pm->cmd.upmove = 0;
		}
	}
	*/

	if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->weaponstate == WEAPON_CHARGING_ALT)
	{ //not allowed to move while charging the disruptor
		if (pm->cmd.forwardmove ||
			pm->cmd.rightmove ||
			pm->cmd.upmove > 0)
		{ //get out
			pm->ps->weaponstate = WEAPON_READY;
			pm->ps->weaponTime = 1000;
			PM_AddEventWithParm(EV_WEAPON_CHARGE, WP_DISRUPTOR); //cut the weapon charge sound
			pm->cmd.upmove = 0;
		}
	}
	else if (pm->ps->weapon == WP_DISRUPTOR && pm->ps->zoomMode == 1)
	{ //can't jump
		if (pm->cmd.upmove > 0)
		{
			pm->cmd.upmove = 0;
		}
	}

	if (stiffenedUp)
	{
		pm->cmd.forwardmove = 0;
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
	}

	if (pm->ps->fd.forceGripCripple && pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_COOP_JKA)
	{ //don't let attack or alt attack if being gripped I guess
		pm->cmd.buttons &= ~BUTTON_ATTACK;
		pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
	}
	else if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_COOP_JKA && pm->ps->electrifyTime > pm->cmd.serverTime)
	{
		//pm->cmd.buttons &= ~BUTTON_ATTACK;
		if (pm->ps->weapon == WP_BLASTER)
			pm->cmd.buttons &= ~BUTTON_ALT_ATTACK;
	}

	if ( BG_InRoll( pm->ps, pm->ps->legsAnim ) )
	{ //can't roll unless you're able to move normally
		BG_CmdForRoll( pm->ps, pm->ps->legsAnim, &pm->cmd );
	}

	PM_CmdForSaberMoves(&pm->cmd);

	if ( pm->ps->stats[STAT_HEALTH] <= 0 ) {
		pm->tracemask &= ~CONTENTS_BODY;	// corpses can fly through bodies
	}

	// make sure walking button is clear if they are running, to avoid
	// proxy no-footsteps cheats
	if ( abs( pm->cmd.forwardmove ) > 64 || abs( pm->cmd.rightmove ) > 64 ) {
		pm->cmd.buttons &= ~BUTTON_WALKING;
	}

	BG_AdjustClientSpeed(pm->ps, &pm->cmd, pm->cmd.serverTime); //move this down 2 blocks

	// set the talk balloon flag
	if ( pm->cmd.buttons & BUTTON_TALK ) {
		pm->ps->eFlags |= EF_TALK;
	} else {
		pm->ps->eFlags &= ~EF_TALK;
	}

	pm_cancelOutZoom = qfalse;
	if (pm->ps->weapon == WP_DISRUPTOR &&
		pm->ps->zoomMode == 1)
	{
		if ((pm->cmd.buttons & BUTTON_ALT_ATTACK) &&
			!(pm->cmd.buttons & BUTTON_ATTACK) &&
			pm->ps->zoomLocked)
		{
			pm_cancelOutZoom = qtrue;
		}
	}
	// In certain situations, we may want to control which attack buttons are pressed and what kind of functionality
	//	is attached to them
	PM_AdjustAttackStates( pm );

	// clear the respawned flag if attack and use are cleared
	if ( pm->ps->stats[STAT_HEALTH] > 0 &&
		!( pm->cmd.buttons & (BUTTON_ATTACK | BUTTON_USE_HOLDABLE) ) ) {
		pm->ps->pm_flags &= ~PMF_RESPAWNED;
	}

	// if talk button is down, dissallow all other input
	// this is to prevent any possible intercept proxy from
	// adding fake talk balloons
	if ( pmove->cmd.buttons & BUTTON_TALK ) {
		// keep the talk button set tho for when the cmd.serverTime > 66 msec
		// and the same cmd is used multiple times in Pmove
		pmove->cmd.buttons = BUTTON_TALK;
		pmove->cmd.forwardmove = 0;
		pmove->cmd.rightmove = 0;
		pmove->cmd.upmove = 0;
	}

	// clear all pmove local vars
	memset (&pml, 0, sizeof(pml));

	// determine the time
	pml.msec = pmove->cmd.serverTime - pm->ps->commandTime;
	if ( pml.msec < 1 ) {
		pml.msec = 1;
	} else if ( pml.msec > 200 ) {
		pml.msec = 200;
	}

#ifdef _GAME
	((gentity_t *)pm_entSelf)->client->pmoveMsec = pml.msec;
#endif

	/*
	if (pm->ps->clientNum >= MAX_CLIENTS)
	{
#ifdef _GAME
		Com_Printf( S_C0LOR_RED" SERVER N%i msec %d\n", pm->ps->clientNum, pml.msec );
#else
		Com_Printf( S_COLOR_GREEN" CLIENT N%i msec %d\n", pm->ps->clientNum, pml.msec );
#endif
	}
	*/

	pm->ps->commandTime = pmove->cmd.serverTime;

	// save old org in case we get stuck
	VectorCopy (pm->ps->origin, pml.previous_origin);

	// save old velocity for crashlanding
	VectorCopy (pm->ps->velocity, pml.previous_velocity);

	pml.frametime = pml.msec * 0.001;

	if (pm->ps->clientNum >= MAX_CLIENTS &&
		pm_entSelf &&
		pm_entSelf->s.NPC_class == CLASS_VEHICLE)
	{ //we are a vehicle
		bgEntity_t *veh = pm_entSelf;
		assert( veh && veh->m_pVehicle);
		if ( veh && veh->m_pVehicle )
		{
			veh->m_pVehicle->m_fTimeModifier = pml.frametime*60.0f;
		}
	}
	else if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&&pm->ps->m_iVehicleNum)
	{
		bgEntity_t *veh = pm_entVeh;

		if (veh && veh->playerState &&
			(pm->cmd.serverTime-veh->playerState->hyperSpaceTime) < HYPERSPACE_TIME)
		{ //going into hyperspace, turn to face the right angles
            PM_VehFaceHyperspacePoint(veh);
		}
		else if (veh && veh->playerState &&
			veh->playerState->vehTurnaroundIndex &&
			veh->playerState->vehTurnaroundTime > pm->cmd.serverTime)
		{ //riding this vehicle, turn my view too
            PM_VehForcedTurning(veh);
		}
	}

	if ( pm->ps->legsAnim == BOTH_FORCEWALLRUNFLIP_ALT &&
		pm->ps->legsTimer > 0 )
	{
		vec3_t vFwd, fwdAng;
		VectorSet(fwdAng, 0.0f, pm->ps->viewangles[YAW], 0.0f);

		AngleVectors( fwdAng, vFwd, NULL, NULL );
		if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
		{
			float savZ = pm->ps->velocity[2];
			VectorScale( vFwd, 100, pm->ps->velocity );
			pm->ps->velocity[2] = savZ;
		}
		pm->cmd.forwardmove = pm->cmd.rightmove = pm->cmd.upmove = 0;
		PM_AdjustAnglesForWallRunUpFlipAlt( &pm->cmd );
	}

//	PM_AdjustAngleForWallRun(pm->ps, &pm->cmd, qtrue);
//	PM_AdjustAnglesForStabDown( pm->ps, &pm->cmd );
	PM_AdjustAngleForWallJump( pm->ps, &pm->cmd, qtrue );
	PM_AdjustAngleForWallRunUp( pm->ps, &pm->cmd, qtrue );
	PM_AdjustAngleForWallRun( pm->ps, &pm->cmd, qtrue );

//[JAPRO - Serverside + Clientside - Saber - Spin Red DFA , Spin Backslash - Start]
#ifdef _GAME
	if (pm->ps->saberMove == LS_A_BACKSTAB && !(g_tweakSaber.integer & ST_SPINBACKSLASH))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if (pm->ps->saberMove == LS_A_JUMP_T__B_ && !(g_tweakSaber.integer & ST_SPINREDDFA))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if ((pm->ps->saberMove == LS_A_BACK_CR || pm->ps->saberMove == LS_A_BACK) && !(g_tweakSaber.integer & ST_SPINBACKSLASH))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if (pm->ps->saberMove == LS_A_LUNGE && (!(g_tweakSaber.integer & ST_JK2LUNGE) || pm->ps->stats[STAT_RACEMODE]))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
#else
	if (pm->ps->saberMove == LS_A_BACKSTAB && !(cgs.jcinfo & JAPRO_CINFO_BACKSLASH)) //should be its own thing but ran out of cinfo bits
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if (pm->ps->saberMove == LS_A_JUMP_T__B_ && !(cgs.jcinfo & JAPRO_CINFO_REDDFA))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if ((pm->ps->saberMove == LS_A_BACK_CR || pm->ps->saberMove == LS_A_BACK) && !(cgs.jcinfo & JAPRO_CINFO_BACKSLASH))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	else if (pm->ps->saberMove == LS_A_LUNGE && (!(cgs.jcinfo & JAPRO_CINFO_JK2LUNGE) || pm->ps->stats[STAT_RACEMODE]))
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
#endif
//[JAPRO - Serverside + Clientside - Saber - Spin Red DFA , Spin Backslash - End]

#if 0
	if ((pm->ps->legsAnim) == BOTH_KISSER1LOOP ||
		(pm->ps->legsAnim) == BOTH_KISSEE1LOOP)
	{
		pm->ps->viewangles[PITCH] = 0;
		PM_SetPMViewAngle(pm->ps, pm->ps->viewangles, &pm->cmd);
	}
#endif

	PM_SetSpecialMoveValues();

	// update the viewangles
	PM_UpdateViewAngles( pm->ps, &pm->cmd );

	AngleVectors (pm->ps->viewangles, pml.forward, pml.right, pml.up);

	if ( pm->cmd.upmove < 10 && !(pm->ps->pm_flags & PMF_STUCK_TO_WALL)) {
		// not holding jump
		pm->ps->pm_flags &= ~PMF_JUMP_HELD;
	}

	// decide if backpedaling animations should be used
	if ( pm->cmd.forwardmove < 0 ) {
		pm->ps->pm_flags |= PMF_BACKWARDS_RUN;
	} else if ( pm->cmd.forwardmove > 0 || ( pm->cmd.forwardmove == 0 && pm->cmd.rightmove ) ) {
		pm->ps->pm_flags &= ~PMF_BACKWARDS_RUN;
	}

	if ( pm->ps->pm_type >= PM_DEAD ) {
		pm->cmd.forwardmove = 0;
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
	}

	/*
	if (pm->ps->fd.saberAnimLevel == SS_STAFF &&
		(pm->cmd.buttons & BUTTON_ALT_ATTACK) &&
		pm->cmd.upmove > 0)
	{ //this is how you do kick-for-condition
		pm->cmd.upmove = 0;
		pm->ps->pm_flags |= PMF_JUMP_HELD;
	}
	*/

	if (pm->ps->saberLockTime >= pm->cmd.serverTime)
	{
		pm->cmd.upmove = 0;
		pm->cmd.forwardmove = 0;//50;
		pm->cmd.rightmove = 0;//*= 0.1;
	}

	if ( pm->ps->pm_type == PM_SPECTATOR ) {
		PM_CheckDuck ();
		if (!pm->noSpecMove)
		{
			PM_FlyMove ();
		}
		PM_DropTimers ();
		return;
	}

	if ( pm->ps->pm_type == PM_NOCLIP ) {
		if (pm->ps->clientNum < MAX_CLIENTS)
		{
			PM_NoclipMove ();
			PM_DropTimers ();
			return;
		}
	}

#ifdef _GAME
	if (pm->ps->pm_type == PM_FREEZE && (g_emotesDisable.integer == ((1 << E_ALL) - 1))) {//Sad hack loda fixme
		return;		// no movement at all
	}
#else
	if (pm->ps->pm_type == PM_FREEZE)
		return;		// no movement at all
#endif

	if ( pm->ps->pm_type == PM_INTERMISSION || pm->ps->pm_type == PM_SPINTERMISSION) {
		return;		// no movement at all
	}

	// set watertype, and waterlevel
	PM_SetWaterLevel();
	pml.previous_waterlevel = pmove->waterlevel;

	// set mins, maxs, and viewheight
	PM_CheckDuck ();

#ifdef _GAME
	if (!pm_entSelf->m_pVehicle && (g_tweakJetpack.integer || pm->ps->stats[STAT_RACEMODE])) {
#else
	if (!pm_entSelf->m_pVehicle && (cgs.jcinfo & JAPRO_CINFO_JETPACK || pm->ps->stats[STAT_RACEMODE])) {
#endif
		if (!pm->cmd.upmove || (pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_TRIBES && pm->ps->jetpackFuel == 0) || ((pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) && (pm->ps->fd.forcePower == 0))) { //Hold to use (spacebar) newjetpack new jetpack
			pm->ps->eFlags &= ~EF_JETPACK_ACTIVE;
		}
		else if (pm->ps->pm_type == PM_NORMAL && pm->cmd.upmove && pm->ps->groundEntityNum == ENTITYNUM_NONE && pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_TRIBES && !(pmove->ps->pm_flags & PMF_JUMP_HELD) && BG_CanJetpack(pm->ps)) { //Pressing jump, while in air
			//Also dont let them jetpack if going down from a bhop?
			gDist = PM_GroundDistance();

			if (pm->ps->velocity[2] > 0 || gDist > JETPACK_HOVER_HEIGHT) {//Going up or super high off ground - this needs to be improved - base on last jump time or?
				if (!(pm->ps->eFlags & EF_JETPACK_ACTIVE)) {
					pm->ps->stats[STAT_JUMPTIME] = 500;
					pm->ps->eFlags |= EF_JETPACK_ACTIVE;
				}
				//If we were not just active, and now we are, set jumptime.

			}
			//Com_Printf("Setting jetpack\n");
		}
		else if (pm->ps->pm_type == PM_NORMAL && pm->cmd.upmove && pm->ps->groundEntityNum == ENTITYNUM_NONE && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && BG_CanJetpack(pm->ps)) { //Pressing jump, while in air																																											   //Also dont let them jetpack if going down from a bhop?
			gDist = PM_GroundDistance();

			if (/*pm->ps->velocity[2] > 0 ||*/pm->ps->stats[STAT_JUMPTIME] < 300 || gDist > JETPACK_HOVER_HEIGHT) {
				if (!(pm->ps->eFlags & EF_JETPACK_ACTIVE)) {
					pm->ps->stats[STAT_JUMPTIME] = 500;
					pm->ps->eFlags |= EF_JETPACK_ACTIVE;
				}
				//If we were not just active, and now we are, set jumptime.

			}
			//Com_Printf("Setting jetpack\n");
		}
		else if (pm->cmd.upmove > 0 && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && (pm->cmd.buttons & BUTTON_DASH) && BG_CanJetpack(pm->ps)) { //Special skiing option for going up terrain
			if (!(pm->ps->eFlags & EF_JETPACK_ACTIVE)) {
				pm->ps->stats[STAT_JUMPTIME] = 500;
				pm->ps->eFlags |= EF_JETPACK_ACTIVE;
			}
		}
		//Downjet?
	}


	if (pm->ps->pm_type == PM_JETPACK)
	{
		gDist = PM_GroundDistance();
		savedGravity = pm->ps->gravity;

		if (gDist < JETPACK_HOVER_HEIGHT+64)
		{
			pm->ps->gravity *= 0.1f;
		}
		else
		{
			pm->ps->gravity *= 0.25f;
		}
	}
	else if (BG_IsNewJetpacking(pm->ps)) //New Jetpack
	{
		savedGravity = pm->ps->gravity;
		//pm->ps->gravity *= 0.01f; //0.05 in FM3
		//dont fuck with gravity in jetpack just use stronger thrust?
	}

	else if (gPMDoSlowFall)
	{
		savedGravity = pm->ps->gravity;
		pm->ps->gravity *= 0.5;
	}

	if (pm->cmd.buttons & BUTTON_DASH) { //JAPRO DASH
		PM_CheckDash();
		PM_CheckWallJump();
	}

	if (pm->ps->stats[STAT_RACEMODE] && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES)
		PM_ThrustMove();
	else
#if _GAME
	if (!pm->ps->stats[STAT_RACEMODE] && g_tweakWeapons.integer & WT_TRIBES) { //Tribes special
	#else
	if (!pm->ps->stats[STAT_RACEMODE] && cgs.jcinfo2 & JAPRO_CINFO2_WTTRIBES) {
#endif
	if (pm->ps->fd.forcePowerSelected == 3) //FIXME
		PM_ThrustMove();
	else if (pm->ps->fd.forcePowerSelected == 4) //FIXME
		PM_BlinkMove();
		PM_OverDriveMove(); //This should just be an actual forcepower (absorb?), have it do the loop and set a ps flag on anyone in range.  then have code here to check for that flag and predict the movement on affected players?
	}


	//if we're in jetpack mode then see if we should be jetting around
	if (pm->ps->pm_type == PM_JETPACK)
	{
		if (pm->cmd.rightmove > 0)
		{
			PM_ContinueLegsAnim(BOTH_INAIRRIGHT1);
		}
		else if (pm->cmd.rightmove < 0)
		{
            PM_ContinueLegsAnim(BOTH_INAIRLEFT1);
		}
		else if (pm->cmd.forwardmove > 0)
		{
			PM_ContinueLegsAnim(BOTH_INAIR1);
		}
		else if (pm->cmd.forwardmove < 0)
		{
			PM_ContinueLegsAnim(BOTH_INAIRBACK1);
		}
		else
		{
			PM_ContinueLegsAnim(BOTH_INAIR1);
		}

		if (pm->ps->weapon == WP_SABER &&
			BG_SpinningSaberAnim( pm->ps->legsAnim ))
		{ //make him stir around since he shouldn't have any real control when spinning
			pm->ps->velocity[0] += Q_irand(-100, 100);
			pm->ps->velocity[1] += Q_irand(-100, 100);
		}

		if (pm->cmd.upmove > 0 && pm->ps->velocity[2] < 256)
		{ //cap upward velocity off at 256. Seems reasonable.
			float addIn = 12.0f;

/*
			//Add based on our distance to the ground if we're already travelling upward
			if (pm->ps->velocity[2] > 0)
			{
				while (gDist > 64)
				{ //subtract 1 for every 64 units off the ground we get
					addIn--;

					gDist -= 64;

					if (addIn <= 0)
					{ //break out if we're not even going to add anything
						break;
					}
				}
			}
*/
			if (pm->ps->velocity[2] > 0)
			{
				addIn = 12.0f - (gDist / 64.0f);
			}

			if (addIn > 0.0f)
			{
				pm->ps->velocity[2] += addIn;
			}

			pm->ps->eFlags |= EF_JETPACK_FLAMING; //going up
		}
		else
		{
			pm->ps->eFlags &= ~EF_JETPACK_FLAMING; //idling

			if (pm->ps->velocity[2] < 256)
			{
				if (pm->ps->velocity[2] < -100)
				{
					pm->ps->velocity[2] = -100;
				}
				if (gDist < JETPACK_HOVER_HEIGHT)
				{ //make sure we're always hovering off the ground somewhat while jetpack is active
					pm->ps->velocity[2] += 2;
				}
			}
		}
	}
	else if (BG_IsNewJetpacking(pm->ps)) //New Jetpack  //Loda todo - rewrite this to let us do mv_jetpack and mv_tribes keeping them seperate?
	{
		//Redo this NEWJETPACK2
		//FM3 is +18 if going up slower than 324 and holding jump
		//FM3 is -6 if falling slower than 1200 and holding crouch (downjet)
		//Jetpack gets shut off when close to ground in FM3 (<16)
		//Jetpack upspeed is capped at 324, fallspeed is capped at -1200
		//Grav should still affect jetters??
		const int MAX_FALL_SPEED = -4000;
		const int MAX_JETPACK_VEL_UP = 2000;
		float gDist2 = gDist;
		float scale = PM_CmdScale(&pm->cmd) / pm->ps->speed * 320.0f;

		//todo - jetpack/tribes dif?

		if (pm->cmd.upmove > 0 && pm->ps->velocity[2] < MAX_JETPACK_VEL_UP)	{//**??^^ unlock upward vel
			float upScale = scale;
			if (!pm->ps->stats[STAT_RACEMODE])
				upScale *= pm->ps->gravity / 800.0f;
			//Jet gets stronger the more your velocity is lower, and weaker the more your z vel is higher.  Same with WASD?
			//Probably need to do something here to give it 2 stages.  1: Low velocity accel boost which fades away as you start getting fast.
			if (pm->ps->velocity[2] > 0 && pm->ps->velocity[2] < 250) {
				float hackscale = 250.0f / pm->ps->velocity[2];

				if (hackscale > 1.4f)
					hackscale = 1.4f;
				else if (hackscale < 1)
					hackscale = 1;

				pm->ps->velocity[2] += 425.0f * pml.frametime * upScale * hackscale;//was 18 with no grav

#if 0
				float hackscale = 250.0f / pm->ps->velocity[2];
				float hackscale2 = (pm->ps->velocity[0]*pm->ps->velocity[0] + pm->ps->velocity[1]*pm->ps->velocity[1]) / (700 * 700);

				if (hackscale2 < 1)
					hackscale2 = 1;

				hackscale /= hackscale2;

				if (hackscale > 1.4f)
					hackscale = 1.4f;
				else if (hackscale < 1)
					hackscale = 1;

				pm->ps->velocity[2] += 425.0f * pml.frametime * upScale * hackscale;//was 18 with no grav
#endif
			}
			else if (pm->ps->velocity[2] < 0) {
				//This is fucked.  Start at 1.25 and get higher based on Z speed.  Don't take XY into account..?
				float hackscale = pm->ps->velocity[2] / -600;


				if (hackscale < 1.4f)
					hackscale = 1.4f;

				if (hackscale > 4.0f)
					hackscale = 4.0f;

				//Com_Printf("Hackscale z is %.2f\n", hackscale);

				pm->ps->velocity[2] += 425.0f * pml.frametime * upScale * hackscale;//was 18 with no grav
#if 0
				{

					float hackscale = 1.25f;
					float hackscale2 = (pm->ps->velocity[0] * pm->ps->velocity[0] + pm->ps->velocity[1] * pm->ps->velocity[1]) / (700 * 700);

					if (hackscale2 < 1)
						hackscale2 = 1;

					hackscale /= hackscale2;

					if (hackscale < 1)
						hackscale = 1;

					//Com_Printf("Hackscale z is %.2f\n", hackscale);

					pm->ps->velocity[2] += 425.0f * pml.frametime * upScale * hackscale;//was 18 with no grav
				}
#endif
			}
			else if (pm->ps->velocity[2] > 800) {
				float hackscale = 800.0f / pm->ps->velocity[2];
				if (hackscale < 0.5f)
					hackscale = 0.5f;
				pm->ps->velocity[2] += 425.0f * pml.frametime * upScale * hackscale;//Weaken upjet if we are going up extremely fast already
			}
			else {
				pm->ps->velocity[2] += 425.0f * pml.frametime * upScale;
			}
			pm->ps->eFlags |= EF_JETPACK_FLAMING; //going up
		}
		else if (pm->cmd.upmove < 0 && pm->ps->velocity[2] > MAX_FALL_SPEED) { //**?? max fall speed
			gDist2 = PM_GroundDistance(); //Have to get this since we dont do it when holding crouch normally
			if (gDist2 >= 16) {
				pm->ps->velocity[2] -= 150.0f * pml.frametime * scale;//was 12 with no grav
				pm->ps->eFlags |= EF_JETPACK_FLAMING;
			}
		}

		if (pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES && (pm->cmd.rightmove || pm->cmd.forwardmove)) {
			//vec3_t forward;
			//AngleVectors(pm->ps->viewangles, forward, NULL, NULL);

			if (1) { //new shit
				//Principles
				//More jet xy strength the slower you are going and also more if you are going opposite
				//air control should not let you strafe to gain speed
				//We don't even need scale here since there is no way to XY jet without up or downjet already
				//Get our wishdir, normalized e.g. (0.5 0.5) for going 45 degrees xy
				//No need for [2] on wishdir, exlude that before or after math?
				vec3_t wishvel;
				vec3_t currentVelNormal;
				float dot;
				float xy_hackscale;
				float speed;

				//How fast are we going in the direction that we are trying to Jet?
				//This simple single digit # is what we scale our hackscale on.  Negative and we upscale bigly.  Positive and we upscale the lower it is.  Past 500 or so we don't upscale (?).

				wishvel[0] = pml.forward[0] * pm->cmd.forwardmove + pml.right[0] * pm->cmd.rightmove;
				wishvel[1] = pml.forward[1] * pm->cmd.forwardmove + pml.right[1] * pm->cmd.rightmove;
				wishvel[2] = 0;
				VectorNormalize(wishvel);

				//Com_Printf("Wishvel is [%.2f %.2f]\n", wishvel[0], wishvel[1]);

				VectorCopy(pm->ps->velocity, currentVelNormal);
				//VectorNormalize(currentVelNormal);
				dot = DotProduct(currentVelNormal, wishvel);

				//Com_Printf("Dotted vel is %.2f\n", dot);

				speed = VectorLength(currentVelNormal);

				if (dot < 0) {
					xy_hackscale = 4; //-dot ? but dot is not normalized
				}
				else {
					xy_hackscale = 800 / speed;
				}

				if (xy_hackscale < 1.2)
					xy_hackscale = 1.2;
				else if (xy_hackscale > 4)
					xy_hackscale = 4;

				//Com_Printf("Hackscalexy is %.2f\n", xy_hackscale);

				//Why does this behave so weird between 0-500 speed? so slow

				VectorMA(pm->ps->velocity, xy_hackscale*pml.frametime*100, wishvel, pm->ps->velocity);


				//Calculate our strength.  More strength based on dotproduct.
				//And more strenght at lower speeds.
				//First

			}
			else
			{ //use the proper way for siege

				vec3_t		wishVelocity;
				vec3_t		pushDir;
				float		pushLen;
				float		canPush;
				vec3_t wishvel, wishdir;
				float wishspeed;
				int i;
				float accel = 0.009f; //server should use pmove_float
				vec3_t currentVelNormal;
				float dot;
				vec3_t xyvel;
				float curSpeed;


				scale /= pm->ps->speed;
				scale *= pm->ps->speed / 320.0f;
				scale *= 20000; //MAX

				//problem, outside of jet they can still slow down their speed with air control ?
				//problem, still going too high up with wasd.  need custom cmd scale?

				//Todo, need a new hackscale based on current vel to give stronger if we are going slow.  Can this be done by changin pm_accelerate or its inputs?

				if (!scale) {
					wishvel[0] = 0;
					wishvel[1] = 0;
					wishvel[2] = 2048 * (pm->cmd.upmove / 127.0f); //pm->ps->speed
				}
				else {
					for (i = 0; i<3; i++) {
						wishvel[i] = scale * pml.forward[i] * pm->cmd.forwardmove + scale * pml.right[i] * pm->cmd.rightmove;
					}

					wishvel[2] += scale * pm->cmd.upmove;
				}

				VectorCopy(wishvel, wishdir);
				wishspeed = VectorNormalize(wishdir);

				//Ok, do a dotproduct of our current vel and our wishvel ?
				//if its negative, give us more accel
				//Make this a smooth cutoff though so maybe just
				//if dot < 0,  accel *=  (-dot)+1
				VectorCopy(pm->ps->velocity, currentVelNormal);
				VectorNormalize(currentVelNormal);
				dot = DotProduct(currentVelNormal, wishdir);

				xyvel[0] = pm->ps->velocity[0];
				xyvel[1] = pm->ps->velocity[1];
				xyvel[2] = 0;
				curSpeed = VectorLength(xyvel);


				//Cases
				// Going fast and wnt to go opposite - hackscale
				//Going slow - hackscale
				//How to smooth the hackscale


				if (dot < 0) {
					//Com_Printf("Dot is %.2f, old accel was %.2f, new accel is %.2f\n", dot, accel * 100, 100 * (accel * (((-dot) + 1) * 1.5)));
					accel *= ((-dot) + 1) * 1.5;//1.5 further modifies the strength of "reverse lateral jetting" compared to regular lateral jetting
				}


				if (curSpeed < 320) { //Need to rework this and above to be more like t1
					float xy_hackscale;
					if (curSpeed)
						xy_hackscale = 320 / curSpeed;
					else
						xy_hackscale = 320;

					xy_hackscale *= xy_hackscale;

					if (xy_hackscale > 3)
						xy_hackscale = 3;
					accel *= xy_hackscale;
				}




				VectorScale(wishdir, wishspeed, wishVelocity);
				VectorSubtract(wishVelocity, pm->ps->velocity, pushDir);
				pushLen = VectorNormalize(pushDir);

				canPush = accel*pml.frametime*wishspeed;
				if (canPush > pushLen) {
					canPush = pushLen;
				}

				VectorMA(pm->ps->velocity, canPush, pushDir, pm->ps->velocity);
			}
			//Get forward dir
			//Apply thrust vectoring based on scale
		}


		/*
		if (pm->ps->velocity[2] < MAX_FALL_SPEED) {
			pm->ps->velocity[2] = MAX_FALL_SPEED;
		}
		else if (pm->ps->velocity[2] > MAX_JETPACK_VEL_UP) {
			pm->ps->velocity[2] = MAX_JETPACK_VEL_UP;
		}
		*/

		if (gDist2 < 16 && pm->cmd.upmove < 0) {//** changed this so jetpack shuts off on ground
			//Sad hack, this stops sliding on ground with downjet
			pm->ps->eFlags &= ~EF_JETPACK_ACTIVE;
		}

	}

	if (pm->ps->clientNum >= MAX_CLIENTS &&
		pm_entSelf && pm_entSelf->m_pVehicle)
	{ //Now update our mins/maxs to match our m_vOrientation based on our length, width & height
		BG_VehicleAdjustBBoxForOrientation( pm_entSelf->m_pVehicle, pm->ps->origin, pm->mins, pm->maxs, pm->ps->clientNum, pm->tracemask, pm->trace );
	}

	// set groundentity
	PM_GroundTrace();
	if ( pm_flying == FLY_HOVER )
	{//never stick to the ground
		PM_HoverTrace();
	}

	if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
	{//on ground
		pm->ps->fd.forceJumpZStart = 0;
	}

	if ( pm->ps->pm_type == PM_DEAD ) {
		if (pm->ps->clientNum >= MAX_CLIENTS &&
			pm_entSelf &&
			pm_entSelf->s.NPC_class == CLASS_VEHICLE &&
			pm_entSelf->m_pVehicle->m_pVehicleInfo->type != VH_ANIMAL)
		{//vehicles don't use deadmove
		}
		else
		{
			PM_DeadMove ();
		}
	}

	PM_DropTimers();

#ifdef _TESTING_VEH_PREDICTION
#ifndef _GAME
	{
		vec3_t blah;
		VectorMA(pm->ps->origin, 128.0f, pm->ps->moveDir, blah);
		CG_TestLine(pm->ps->origin, blah, 1, 0x0000ff, 1);

		VectorMA(pm->ps->origin, 1.0f, pm->ps->velocity, blah);
		CG_TestLine(pm->ps->origin, blah, 1, 0xff0000, 1);
	}
#endif
#endif

	if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&&pm->ps->m_iVehicleNum)
	{ //a player riding a vehicle
		bgEntity_t *veh = pm_entVeh;

		if ( veh && veh->m_pVehicle &&
			(veh->m_pVehicle->m_pVehicleInfo->type == VH_WALKER || veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER) )
		{//*sigh*, until we get forced weapon-switching working?
			pm->cmd.buttons &= ~(BUTTON_ATTACK|BUTTON_ALT_ATTACK);
			pm->ps->eFlags &= ~(EF_FIRING|EF_ALT_FIRING);
			//pm->cmd.weapon = pm->ps->weapon;
		}
	}

	if (!pm->ps->m_iVehicleNum &&
		pm_entSelf->s.NPC_class!=CLASS_VEHICLE&&
		pm_entSelf->s.NPC_class!=CLASS_RANCOR&&
		pm->ps->groundEntityNum < ENTITYNUM_WORLD &&
		pm->ps->groundEntityNum >= MAX_CLIENTS)
	{ //I am a player client, not riding on a vehicle, and potentially standing on an NPC
		bgEntity_t *pEnt = PM_BGEntForNum(pm->ps->groundEntityNum);

		if (pEnt && pEnt->s.eType == ET_NPC &&
			pEnt->s.NPC_class != CLASS_VEHICLE) //don't bounce on vehicles
		{ //this is actually an NPC, let's try to bounce of its head to make sure we can't just stand around on top of it.
			if (pm->ps->velocity[2] < 270)


				if (!GetFlipkick(pm->ps))
				{ //try forcing velocity up and also force him to jump
					pm->ps->velocity[2] = 270; //seems reasonable
					if (pm->ps->clientNum < MAX_CLIENTS) //Fixes a crash that happens when npcs bounce on other npcs heads with g_flipkick 0 ...?
						pm->cmd.upmove = 127; //Probably this is why it was crashing, trying to send this on an npc...?
				}
		}
#ifdef _GAME
		else if ( !pm->ps->zoomMode &&
			pm_entSelf //I exist
			&& pEnt->m_pVehicle )//ent has a vehicle
		{
			gentity_t *gEnt = (gentity_t*)pEnt;
			if ( gEnt->client
				&& !gEnt->client->ps.m_iVehicleNum //vehicle is empty
				&& (gEnt->spawnflags&2) )//SUSPENDED
			{//it's a vehicle, see if we should get in it
				//if land on an empty, suspended vehicle, get in it
				pEnt->m_pVehicle->m_pVehicleInfo->Board( pEnt->m_pVehicle, (bgEntity_t *)pm_entSelf );
			}
		}
#endif
	}

	if (pm->ps->clientNum >= MAX_CLIENTS &&
		pm_entSelf &&
		pm_entSelf->s.NPC_class == CLASS_VEHICLE)
	{ //we are a vehicle
		bgEntity_t *veh = pm_entSelf;

		assert(veh && veh->playerState && veh->m_pVehicle && veh->s.number >= MAX_CLIENTS);

		if (veh->m_pVehicle->m_pVehicleInfo->type != VH_FIGHTER)
		{ //kind of hacky, don't want to do this for flying vehicles
			veh->m_pVehicle->m_vOrientation[PITCH] = pm->ps->viewangles[PITCH];
		}

		if (!pm->ps->m_iVehicleNum)
		{ //no one is driving, just update and get out
#ifdef _GAME
			veh->m_pVehicle->m_pVehicleInfo->Update(veh->m_pVehicle, &pm->cmd);
		    veh->m_pVehicle->m_pVehicleInfo->Animate(veh->m_pVehicle);
#endif
		}
		else
		{
			bgEntity_t *self = pm_entVeh;
#ifdef _GAME
			int i = 0;
#endif

			assert(self && self->playerState && self->s.number < MAX_CLIENTS);

			if (pm->ps->pm_type == PM_DEAD &&
				(veh->m_pVehicle->m_ulFlags & VEH_CRASHING))
			{
				veh->m_pVehicle->m_ulFlags &= ~VEH_CRASHING;
			}

			if (self->playerState->m_iVehicleNum)
			{ //only do it if they still have a vehicle (didn't get ejected this update or something)
				PM_VehicleViewAngles(self->playerState, veh, &veh->m_pVehicle->m_ucmd);
			}

#ifdef _GAME
			veh->m_pVehicle->m_pVehicleInfo->Update(veh->m_pVehicle, &veh->m_pVehicle->m_ucmd);
			veh->m_pVehicle->m_pVehicleInfo->Animate(veh->m_pVehicle);

			veh->m_pVehicle->m_pVehicleInfo->UpdateRider(veh->m_pVehicle, self, &veh->m_pVehicle->m_ucmd);
			//update the passengers
			while (i < veh->m_pVehicle->m_iNumPassengers)
			{
				if (veh->m_pVehicle->m_ppPassengers[i])
				{
					gentity_t *thePassenger = (gentity_t *)veh->m_pVehicle->m_ppPassengers[i]; //yes, this is, in fact, ass.
					if (thePassenger->inuse && thePassenger->client)
					{
						veh->m_pVehicle->m_pVehicleInfo->UpdateRider(veh->m_pVehicle, veh->m_pVehicle->m_ppPassengers[i], &thePassenger->client->pers.cmd);
					}
				}
				i++;
			}
#else
			if (!veh->playerState->vehBoarding )//|| veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER)
			{
				if (veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER)
				{ //client must explicitly call this for prediction
					BG_FighterUpdate(veh->m_pVehicle, &veh->m_pVehicle->m_ucmd, pm->mins, pm->maxs, self->playerState->gravity, pm->trace);
				}

				if (veh->m_pVehicle->m_iBoarding == 0)
				{
					vec3_t vRollAng;

					//make sure we are set as its pilot cgame side
					veh->m_pVehicle->m_pPilot = self;

					// Keep track of the old orientation.
					VectorCopy( veh->m_pVehicle->m_vOrientation, veh->m_pVehicle->m_vPrevOrientation );

					veh->m_pVehicle->m_pVehicleInfo->ProcessOrientCommands(veh->m_pVehicle);
					PM_SetPMViewAngle(veh->playerState, veh->m_pVehicle->m_vOrientation, &veh->m_pVehicle->m_ucmd);
					veh->m_pVehicle->m_pVehicleInfo->ProcessMoveCommands(veh->m_pVehicle);

					vRollAng[YAW] = self->playerState->viewangles[YAW];
					vRollAng[PITCH] = self->playerState->viewangles[PITCH];
					vRollAng[ROLL] = veh->m_pVehicle->m_vOrientation[ROLL];
					PM_SetPMViewAngle(self->playerState, vRollAng, &pm->cmd);

					// Setup the move direction.
					if ( veh->m_pVehicle->m_pVehicleInfo->type == VH_FIGHTER )
					{
						AngleVectors( veh->m_pVehicle->m_vOrientation, veh->playerState->moveDir, NULL, NULL );
					}
					else
					{
						vec3_t vVehAngles;

						VectorSet(vVehAngles, 0, veh->m_pVehicle->m_vOrientation[YAW], 0);
						AngleVectors( vVehAngles, veh->playerState->moveDir, NULL, NULL );
					}
				}
			}
			/*
			else
			{
				veh->playerState->speed = 0.0f;
				PM_SetPMViewAngle(self->playerState, veh->playerState->viewangles, &veh->m_pVehicle->m_ucmd);
			}
			*/
			else if (veh->playerState)
			{
				veh->playerState->speed = 0.0f;
				if (veh->m_pVehicle)
				{
					PM_SetPMViewAngle(self->playerState, veh->m_pVehicle->m_vOrientation, &pm->cmd);
					PM_SetPMViewAngle(veh->playerState, veh->m_pVehicle->m_vOrientation, &pm->cmd);
				}
			}
#endif
		}
		noAnimate = qtrue;
	}


#if _CGAME
    if (pm->ps->stats[STAT_RACEMODE] && pm->ps->pm_type == PM_NORMAL && pm->cmd.buttons & BUTTON_STRAFEBOT && !(cgs.restricts & RESTRICT_SB)) {
#else
        if (pm->ps->stats[STAT_RACEMODE] && pm->ps->pm_type == PM_NORMAL && pm->cmd.buttons & BUTTON_STRAFEBOT) {
#endif
        const int moveStyle = PM_GetMovePhysics();
#if _CGAME
        if (pm->ps->clientNum >= 0 && pm->ps->clientNum < MAX_CLIENTS && (moveStyle == MV_BOTCPM /*|| (g_entities[pm->ps->clientNum].client && g_entities[pm->ps->clientNum].client->pers.practice)*/))
#else
            if (pm->ps->clientNum >= 0 && pm->ps->clientNum < MAX_CLIENTS && (moveStyle == MV_BOTCPM || (g_entities[pm->ps->clientNum].client && g_entities[pm->ps->clientNum].client->pers.practice)))
#endif
        {
            const float realCurrentSpeed = sqrt((pm->ps->velocity[0] * pm->ps->velocity[0]) + (pm->ps->velocity[1] * pm->ps->velocity[1]));
            if (realCurrentSpeed > 0) {
                vec3_t vel = { 0 }, velangle;
                float optimalDeltaAngle = 0;
                qboolean CJ = qtrue;
                if (pm->ps->groundEntityNum != ENTITYNUM_WORLD || pm->cmd.upmove > 0)
                    CJ = qfalse;
                else if (moveStyle == MV_SLICK)
                    CJ = qfalse;
                else if (pml.walking && pml.groundTrace.surfaceFlags & SURF_SLICK) { //Lmao fuck this bullshit. no way to tell if we are on slick i guess.
                    CJ = qfalse;
                }
                else if (realCurrentSpeed > pm->ps->basespeed * 1.5f) //idk this is retarded, but lets us groundframe
                    CJ = qfalse;

                if (realCurrentSpeed > pm->ps->basespeed || (CJ && (realCurrentSpeed > (pm->ps->basespeed * 0.5f)))) {
                    float middleOffset = 0; //Idk
#if _GAME
                    middleOffset = bot_strafeOffset.integer;
#endif
                    if (CJ)
                        if (moveStyle == MV_CPM || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM)
                            optimalDeltaAngle = -1; //CJ //Take into account ground accel/friction.. only cpm styles turn faster?
                        else
                            optimalDeltaAngle = -6;
                    else {
                        float realAccel = pm_airaccelerate;
                        if (moveStyle == MV_SP)
                            realAccel = pm_sp_airaccelerate;
                        else if (moveStyle == MV_SLICK)
                            realAccel = pm_slick_accelerate;
                        //jetpack. 1.4f ?
                        optimalDeltaAngle = (acos((double)((pm->ps->basespeed - (realAccel * pm->ps->basespeed * pml.frametime)) / realCurrentSpeed)) * (180.0f / M_PI) - 45.0f);
                        if (optimalDeltaAngle < 0 || optimalDeltaAngle > 360)
                            optimalDeltaAngle = 0;
                    }

                    vel[0] = pm->ps->velocity[0];
                    vel[1] = pm->ps->velocity[1];
                    vectoangles(vel, velangle);

                    if (pm->cmd.forwardmove > 0 && pm->cmd.rightmove > 0) {//WD
                        optimalDeltaAngle = 0 - optimalDeltaAngle;
                    }
                    else if (pm->cmd.forwardmove > 0 && pm->cmd.rightmove < 0) {//WA
                        optimalDeltaAngle = 0 + optimalDeltaAngle;
                    }
                    else if (!pm->cmd.forwardmove && pm->cmd.rightmove > 0) {//D
                        if (moveStyle == MV_QW || moveStyle == MV_CPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM)
                            optimalDeltaAngle = 0 - middleOffset; //Take into account speed.
                        else
                            optimalDeltaAngle = 45 - optimalDeltaAngle;
                    }
                    else if (!pm->cmd.forwardmove && pm->cmd.rightmove < 0) {//A
                        if (moveStyle == MV_QW || moveStyle == MV_CPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM)
                            optimalDeltaAngle = 0 + middleOffset;
                        else
                            optimalDeltaAngle = -45 + optimalDeltaAngle;
                    }
                    else if (pm->cmd.forwardmove > 0 && !pm->cmd.rightmove) {//W
                        if (AngleSubtract(velangle[YAW], pm->ps->viewangles[YAW]) > 0) { //Decide which W we want.  (Whatever is closest)
                            if (moveStyle == MV_QW || moveStyle == MV_CPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM) //Why the f does it switch
                                optimalDeltaAngle = -45; //Needs good offset
                            else
                                optimalDeltaAngle = -45 - optimalDeltaAngle;
                        }
                        else { //Right side
                            if (moveStyle == MV_QW || moveStyle == MV_CPM || moveStyle == MV_PJK || moveStyle == MV_WSW || moveStyle == MV_RJCPM || moveStyle == MV_BOTCPM)
                                optimalDeltaAngle = 45; //Needs good offset
                            else
                                optimalDeltaAngle = 45 + optimalDeltaAngle;
                        }
                    }

                    velangle[YAW] += optimalDeltaAngle;
                    velangle[PITCH] = pm->ps->viewangles[PITCH];

                    PM_SetPMViewAngle(pm->ps, velangle, &pm->cmd);
                    AngleVectors(pm->ps->viewangles, pml.forward, pml.right, pml.up); //Have to re set this here
                }
            }
        }
    }

	if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&&pm->ps->m_iVehicleNum)
	{//don't even run physics on a player if he's on a vehicle - he goes where the vehicle goes
	}
	else
	{ //don't even run physics on a player if he's on a vehicle - he goes where the vehicle goes
		if (pm->ps->pm_type == PM_FLOAT || pm_flying == FLY_NORMAL)
		{
			PM_FlyMove ();
		}
		else if ( pm_flying == FLY_VEHICLE )
		{
			PM_FlyVehicleMove();
		}
		else
		{

#if _GRAPPLE
			if ((pm->ps->pm_flags & PMF_GRAPPLE) && pm->ps->stats[STAT_MOVEMENTSTYLE] == MV_TRIBES) {
				PM_GrappleMoveTribes();
			}
#if _GAME
			else if ((pm->ps->pm_flags & PMF_GRAPPLE) && !(pm->ps->pm_flags & PMF_DUCKED) && ((g_allowGrapple.integer == 1) || pm->ps->stats[STAT_RACEMODE])) {
				PM_GrappleMoveTarzan();
			}
			else if ((pm->ps->pm_flags & PMF_GRAPPLE) && !(pm->ps->pm_flags & PMF_DUCKED) && (g_allowGrapple.integer > 1)) {
				PM_GrappleMove();
			}
#else
			else if ((pm->ps->pm_flags & PMF_GRAPPLE) && !(pm->ps->pm_flags & PMF_DUCKED) && cgs.serverMod != SVMOD_JAPLUS && (!(cgs.jcinfo & JAPRO_CINFO_JAPLUSGRAPPLE) || pm->ps->stats[STAT_RACEMODE]))
				PM_GrappleMoveTarzan();
			else if ((pm->ps->pm_flags & PMF_GRAPPLE) && !(pm->ps->pm_flags & PMF_DUCKED) && (cgs.serverMod == SVMOD_JAPLUS || (cgs.jcinfo & JAPRO_CINFO_JAPLUSGRAPPLE)))
				PM_GrappleMove();
#endif

#endif
			if (pm->ps->pm_flags & PMF_TIME_WATERJUMP) {
				PM_WaterJumpMove();
			} else if ( pm->waterlevel > 1 ) {
				// swimming
				PM_WaterMove();
			} else if ( pml.walking ) {
				// walking on ground
				PM_WalkMove();
			} else {
				// airborne
				PM_AirMove();
			}
		}
	}

	if (!noAnimate)
	{
		PM_Animate();
	}

	// set groundentity, watertype, and waterlevel
	PM_GroundTrace();
	if ( pm_flying == FLY_HOVER )
	{//never stick to the ground
		PM_HoverTrace();
	}
	PM_SetWaterLevel();
	if (pm->cmd.forcesel != (byte)-1 && (pm->ps->fd.forcePowersKnown & (1 << pm->cmd.forcesel)))
	{
#if _GAME
		if (!(g_tweakWeapons.integer & WT_TRIBES) || pm->ps->stats[STAT_RACEMODE])
#endif
			pm->ps->fd.forcePowerSelected = pm->cmd.forcesel;
	}
	if (pm->cmd.invensel != (byte)-1 && (pm->ps->stats[STAT_HOLDABLE_ITEMS] & (1 << pm->cmd.invensel)))
	{
		pm->ps->stats[STAT_HOLDABLE_ITEM] = BG_GetItemIndexByTag(pm->cmd.invensel, IT_HOLDABLE);
	}

	if (pm->ps->m_iVehicleNum
		/*&&pm_entSelf->s.NPC_class!=CLASS_VEHICLE*/
		&& pm->ps->clientNum < MAX_CLIENTS)
	{//a client riding a vehicle
		if ( (pm->ps->eFlags&EF_NODRAW) )
		{//inside the vehicle, do nothing
		}
		else if (!PM_WeaponOkOnVehicle(pm->cmd.weapon) || !PM_WeaponOkOnVehicle(pm->ps->weapon))
		{ //this weapon is not legal for the vehicle, force to our current one
	        if (!PM_WeaponOkOnVehicle(pm->ps->weapon))
			{ //uh-oh!
				int weap = PM_GetOkWeaponForVehicle();

				if (weap != -1)
				{
					pm->cmd.weapon = weap;
					pm->ps->weapon = weap;
				}
			}
			else
			{
				pm->cmd.weapon = pm->ps->weapon;
			}
		}
	}

	if (!pm->ps->m_iVehicleNum //not a vehicle and not riding one
		|| pm_entSelf->s.NPC_class==CLASS_VEHICLE //you are a vehicle NPC
		|| (!(pm->ps->eFlags&EF_NODRAW)&&PM_WeaponOkOnVehicle(pm->cmd.weapon)) )//you're not inside the vehicle and the weapon you're holding can be used when riding this vehicle
	{ //only run weapons if a valid weapon is selected
		// weapons
		PM_Weapon();
	}

	PM_Use();

	if (!pm->ps->m_iVehicleNum &&
		(pm->ps->clientNum < MAX_CLIENTS ||
		!pm_entSelf ||
		pm_entSelf->s.NPC_class != CLASS_VEHICLE))
	{ //don't do this if we're on a vehicle, or we are one
		// footstep events / legs animations
		PM_Footsteps();
	}

	// entering / leaving water splashes
	PM_WaterEvents();

	//Walbug fix start, if getting stuck w/o noclip is even possible.  This should maybe be after round float? im not sure..
	if ((pm->ps->persistant[PERS_TEAM] != TEAM_SPECTATOR) && pm->ps->stats[STAT_RACEMODE] && VectorCompare(pm->ps->origin, pml.previous_origin) /*&& (VectorLengthSquared(pm->ps->velocity) > VectorLengthSquared(pml.previous_velocity))*/)
			VectorClear(pm->ps->velocity); //Their velocity is increasing while their origin is not moving (wallbug), so prevent this..
			//VectorCopy(pml.previous_velocity, pm->ps->velocity);
	//To fix rocket wallbug, since that gets applied elsewhere, just always reset vel if origins dont match?
	//Wallbug fix end

	if (pm->ps->persistant[PERS_TEAM] == TEAM_SPECTATOR) {
		trap->SnapVector( pm->ps->velocity );
	}
	else {
		if ((pm->ps->stats[STAT_RACEMODE] && (pm->ps->stats[STAT_MOVEMENTSTYLE] != MV_OCPM)) || (!pm->ps->stats[STAT_RACEMODE] && (pm->pmove_float > 1))) {//japro fix racemode fps
		}
	#ifdef _GAME
		else if (g_fixHighFPSAbuse.integer && ((pml.msec < 4) || (pml.msec > 25))) { //More than 333fps, or less than 40fps.
			//trap->SendServerCommand( -1, va("print \"333? msec: %i\n\"", pml.msec ));
		}
	#elif _CGAME
		else if ((cgs.jcinfo & JAPRO_CINFO_HIGHFPSFIX) && (pml.msec < 4 || pml.msec > 25)) {
		}
	#endif
		else if (!pm->pmove_float) {
			/*
			bgEntity_t *veh;
			veh = pm_entSelf;

			if (veh->m_pVehicle && veh->m_pVehicle->m_pPilot && veh->m_pVehicle->m_pPilot->playerState && veh->m_pVehicle->m_pPilot->playerState->stats[STAT_RACEMODE]) {
			}
			else
			*/
			trap->SnapVector( pm->ps->velocity ); // snap velocity to integer coordinates to save network bandwidth
		}
	}

 	if (pm->ps->pm_type == PM_JETPACK || gPMDoSlowFall || BG_IsNewJetpacking(pm->ps))
	{
		pm->ps->gravity = savedGravity;
	}

	if (//pm->ps->m_iVehicleNum &&
		pm->ps->clientNum >= MAX_CLIENTS &&
		pm_entSelf &&
		pm_entSelf->s.NPC_class == CLASS_VEHICLE)
	{ //a vehicle with passengers
		bgEntity_t *veh;

		veh = pm_entSelf;

		assert(veh->m_pVehicle);

		//this could be kind of "inefficient" because it's called after every passenger pmove too.
		//Maybe instead of AttachRiders we should have each rider call attach for himself?
		if (veh->m_pVehicle && veh->ghoul2)
		{
			veh->m_pVehicle->m_pVehicleInfo->AttachRiders( veh->m_pVehicle );
		}
	}

	if (pm_entSelf->s.NPC_class!=CLASS_VEHICLE
		&& pm->ps->m_iVehicleNum)
	{ //riding a vehicle, see if we should do some anim overrides
		PM_VehicleWeaponAnimate();
	}
}

qboolean BG_InRollFixed( playerState_t *ps, int anim )
{
	switch ( (anim) )
	{
	case BOTH_ROLL_F:
	case BOTH_ROLL_B:
	case BOTH_ROLL_R:
	case BOTH_ROLL_L:
		if ( ps->legsTimer > 0 )
		{
			return qtrue;
		}
		break;
	}

	return qfalse;
}

/*
================
Pmove

Can be called by either the server or the client
================
*/
void Pmove (pmove_t *pmove) {
	int			finalTime;

	finalTime = pmove->cmd.serverTime;

	if ( finalTime < pmove->ps->commandTime ) {
		return;	// should not happen
	}

	if ( finalTime > pmove->ps->commandTime + 1000 ) {
		pmove->ps->commandTime = finalTime - 1000;
	}

	if (pmove->ps->iModelScale) { //Lugormod
		scaleh = pmove->ps->iModelScale/100.0f;
	} else {
		scaleh = 1.0f;
	}

	#if _CGAME
		if (cgs.serverMod == SVMOD_LMD) { // Lugormod
			for (int i = 0; i < 8; i++) {
				// 11 = STAT_EXTRA_FORCE_BITS in Lugormod (not STAT_RACEMODE)
				if (pmove->ps->stats[11] & (1 << i)) {
					pmove->ps->fd.forcePowerLevel[i] |= 4;
				}
			}
	 
			for (int i = 8; i < 16; i++) {
				// 11 = STAT_EXTRA_FORCE_BITS2 in Lugormod (not STAT_RESTRICTIONS)
				if (pmove->ps->stats[12] & (1 << (i - 8))) {
					pmove->ps->fd.forcePowerLevel[i] |= 4;
				}
			}
		}
	#endif

	if (pmove->ps->fallingToDeath)
	{
		pmove->cmd.forwardmove = 0;
		pmove->cmd.rightmove = 0;
		pmove->cmd.upmove = 0;
		pmove->cmd.buttons = 0;
	}

	pmove->ps->pmove_framecount = (pmove->ps->pmove_framecount+1) & ((1<<PS_PMOVEFRAMECOUNTBITS)-1);

	//if (pmove->ps->stats[STAT_RACEMODE] /*pm->ps->clientNum < MAX_CLIENTS*/) {//racemode only?
		pmove->cmd.angles[ROLL] = 0;
		pmove->ps->viewangles[ROLL] = 0;
		pmove->ps->delta_angles[ROLL] = 0;
	//}

	// chop the move up if it is too long, to prevent framerate
	// dependent behavior
	while ( pmove->ps->commandTime != finalTime ) {
		int		msec;

		msec = finalTime - pmove->ps->commandTime;
		if (pmove->ps->stats[STAT_RACEMODE]) { //Using float now
			if ( msec > 8 ) {
				if (BG_InRollFixed(pmove->ps, pmove->ps->legsAnim) || (pmove->ps->stats[STAT_MOVEMENTSTYLE] == MV_OCPM)) {
					msec = 8;
				}
				/*else if (msec > 16) {
					msec = 16;
				}*/
			}
		}
		else if ( pmove->pmove_fixed ) {
			if ( msec > pmove->pmove_msec ) {
				msec = pmove->pmove_msec;
			}
		}
		else {
			if ( msec > 66 ) {
				msec = 66;
			}
		}
		pmove->cmd.serverTime = pmove->ps->commandTime + msec;

		PmoveSingle( pmove );

		if ( pmove->ps->pm_flags & PMF_JUMP_HELD ) {
			pmove->cmd.upmove = 20;
		}
	}
}

