/*
 * JKBot own-state prediction library: the glue (simulator only, P1-ENG-11). See jkbpredict.h.
 *
 * Compiled with the cgame's bg_* sources and _CGAME, so Pmove behaves exactly as in the TaystJK
 * client. This file stands in for the parts of the cgame the bg code reaches: the cg, cgs and
 * cg_entities globals, the trap import table (file and collision imports go to the host, the
 * renderer, sound, effects and Ghoul2 ones are inert: prediction runs without a Ghoul2 instance,
 * as the cgame does when it has none), CG_Trace/CG_PointContents over the held snapshot's solid
 * entities (cg_predict.c), and the per-command part of CG_PredictPlayerState.
 *
 * Not ported, as they don't arise for a duelist on a basejka server: vehicles, the JA+ hook and
 * knockback prediction (TaystJK client features), demo playback and PMF_FOLLOW, prediction-error
 * smoothing (visual only), and trigger touching (CG_TouchTriggerPrediction: jump pads and
 * teleporters, none in mp/duel1).
 */
#ifdef JKBOT_AGENT

#include "cgame/cg_local.h"
#include "jkbpredict.h"

// ---- what the cgame would define ----

cgameImport_t *trap = NULL;
cg_t cg;
cgs_t cgs;
centity_t cg_entities[MAX_GENTITIES];
int cg_dueltypes[MAX_CLIENTS];
vmCvar_t bg_fighterAltControl, cg_jumpHeight, cg_legstuck, cp_pluginDisable, pmove_fixed;

static playerState_t sendPSPool[MAX_GENTITIES];
playerState_t *cgSendPS[MAX_GENTITIES];

void WP_SaberLoadParms( void );  // bg_saberLoad.c (the cgame declares them locally too)
void WP_SetSaber( int entNum, saberInfo_t *sabers, int saberNum, const char *saberName );

static const jkbpHost_t *host;
static cgameImport_t imports;
static pmove_t pmv;  // cg_pmove

static centity_t *solids[MAX_ENTITIES_IN_SNAPSHOT + 1];
static int numSolids;
static playerState_t snapPS;
static int snapTime;

static void QDECL PredPrintf( const char *fmt, ... ) {
	va_list ap;
	char msg[4096];
	va_start( ap, fmt );
	Q_vsnprintf( msg, sizeof( msg ), fmt, ap );
	va_end( ap );
	host->Print( msg );
}

static NORETURN void QDECL PredError( int level, const char *fmt, ... ) {
	va_list ap;
	char msg[4096];
	va_start( ap, fmt );
	Q_vsnprintf( msg, sizeof( msg ), fmt, ap );
	va_end( ap );
	host->Error( msg );
	for ( ;; ) {
	}
}

// q_shared.h: under _CGAME these are pointers the module sets (cg_main.c)
NORETURN_PTR void ( *Com_Error )( int level, const char *error, ... ) = PredError;
void ( *Com_Printf )( const char *msg, ... ) = PredPrintf;

int BG_GetTime( void ) {
	return cg.time;
}

const char *CG_ConfigString( int index ) {
	return host->ConfigString( index );
}

void CG_GetVehicleCamPos( vec3_t camPos ) {
	VectorClear( camPos );
}

// ---- trap imports ----

static void CvarRegister( vmCvar_t *v, const char *name, const char *value, uint32_t flags ) {
	if ( v ) {
		Q_strncpyz( v->string, value, sizeof( v->string ) );
		v->value = atof( value );
		v->integer = atoi( value );
	}
}
static void CvarSet( const char *name, const char *value ) {}
static void CvarString( const char *name, char *buf, int size ) { if ( size > 0 ) buf[0] = 0; }
static void ConsoleCommand( const char *text ) {}
static qhandle_t RegisterName( const char *name ) { return 0; }
static sfxHandle_t RegisterSound( const char *name ) { return 0; }
static void StartSound( const vec3_t o, int e, int ch, sfxHandle_t s ) {}
static int RegisterEffect( const char *file ) { return 0; }
static void PlayEffect( int id, vec3_t org, vec3_t fwd, int vol, int rad, qboolean portal ) {}
// Ghoul2: never called with an instance (pm->ghoul2 and the entities' ghoul2 are NULL)
static int G2AddBolt( void *g2, int model, const char *name ) { return -1; }
static qboolean G2GetBolt( void *g2, const int m, const int b, mdxaBone_t *mat, const vec3_t a, const vec3_t p, const int f, qhandle_t *l, vec3_t s ) {
	Com_Memset( mat, 0, sizeof( *mat ) );
	return qfalse;
}

static void FillImports( void ) {
	Com_Memset( &imports, 0, sizeof( imports ) );
	imports.Print = PredPrintf;
	imports.Error = PredError;
	imports.SnapVector = host->SnapVector;
	imports.Milliseconds = host->Milliseconds;
	imports.Cvar_Register = CvarRegister;
	imports.Cvar_Set = CvarSet;
	imports.Cvar_VariableStringBuffer = CvarString;
	imports.SendConsoleCommand = ConsoleCommand;
	imports.FS_Open = host->FS_Open;
	imports.FS_Read = host->FS_Read;
	imports.FS_Close = host->FS_Close;
	imports.FS_GetFileList = host->FS_GetFileList;
	imports.CM_InlineModel = host->CM_InlineModel;
	imports.CM_TempModel = host->CM_TempModel;
	imports.CM_PointContents = host->CM_PointContents;
	imports.CM_TransformedPointContents = host->CM_TransformedPointContents;
	imports.CM_Trace = host->CM_Trace;
	imports.CM_TransformedTrace = host->CM_TransformedTrace;
	imports.R_RegisterModel = RegisterName;
	imports.R_RegisterShader = RegisterName;
	imports.R_RegisterShaderNoMip = RegisterName;
	imports.R_RegisterSkin = RegisterName;
	imports.S_RegisterSound = RegisterSound;
	imports.S_StartSound = StartSound;
	imports.FX_RegisterEffect = RegisterEffect;
	imports.FX_PlayEffectID = PlayEffect;
	imports.G2API_AddBolt = G2AddBolt;
	imports.G2API_GetBoltMatrix = G2GetBolt;
	imports.G2API_GetBoltMatrix_NoRecNoRot = G2GetBolt;
	trap = &imports;
}

// ---- CG_Trace and CG_PointContents (cg_predict.c), over the held snapshot's solid entities ----

static void ClipMoveToEntities( const vec3_t start, const vec3_t mins, const vec3_t maxs,
	const vec3_t end, int skipNumber, int mask, trace_t *tr ) {
	for ( int i = 0; i < numSolids; i++ ) {
		centity_t *cent = solids[i];
		entityState_t *ent = &cent->currentState;
		clipHandle_t cmodel;
		vec3_t bmins, bmaxs, origin, angles;
		trace_t trace;

		if ( ent->number == skipNumber ) {
			continue;
		}
		if ( ent->number > MAX_CLIENTS &&
			ent->genericenemyindex - MAX_GENTITIES == cg.predictedPlayerState.clientNum ) {
			continue;  // owned objects don't block their owner's prediction
		}
		if ( ent->eType == ET_SPECIAL && ent->modelindex == HI_SHIELD ) {
			continue;
		}
		if ( ent->solid == SOLID_BMODEL ) {
			cmodel = trap->CM_InlineModel( ent->modelindex );
			VectorCopy( cent->lerpAngles, angles );
			BG_EvaluateTrajectory( &cent->currentState.pos, cg.physicsTime, origin );
		} else {
			const int x = ent->solid & 255;
			const int zd = ( ent->solid >> 8 ) & 255;
			const int zu = ( ( ent->solid >> 16 ) & 255 ) - 32;
			bmins[0] = bmins[1] = -x;
			bmaxs[0] = bmaxs[1] = x;
			bmins[2] = -zd;
			bmaxs[2] = zu;
			cmodel = trap->CM_TempModel( bmins, bmaxs, 0 );
			VectorCopy( vec3_origin, angles );
			VectorCopy( cent->lerpOrigin, origin );
		}
		trap->CM_TransformedTrace( &trace, start, end, mins, maxs, cmodel, mask, origin, angles, 0 );
		trace.entityNum = trace.fraction != 1.0 ? ent->number : ENTITYNUM_NONE;
		if ( trace.allsolid || trace.fraction < tr->fraction ) {
			trace.entityNum = ent->number;
			*tr = trace;
		} else if ( trace.startsolid ) {
			tr->startsolid = qtrue;
			tr->entityNum = trace.entityNum = ent->number;
		}
		if ( tr->allsolid ) {
			return;
		}
	}
}

static void Trace( trace_t *result, const vec3_t start, const vec3_t mins, const vec3_t maxs,
	const vec3_t end, int skipNumber, int mask ) {
	trace_t t;
	trap->CM_Trace( &t, start, end, mins, maxs, 0, mask, 0 );
	t.entityNum = t.fraction != 1.0 ? ENTITYNUM_WORLD : ENTITYNUM_NONE;
	ClipMoveToEntities( start, mins, maxs, end, skipNumber, mask, &t );
	*result = t;
}

static int PointContents( const vec3_t point, int passEntityNum ) {
	int contents = trap->CM_PointContents( point, 0 );
	for ( int i = 0; i < numSolids; i++ ) {
		centity_t *cent = solids[i];
		entityState_t *ent = &cent->currentState;
		if ( ent->number == passEntityNum || ent->solid != SOLID_BMODEL ) {
			continue;
		}
		clipHandle_t cmodel = trap->CM_InlineModel( ent->modelindex );
		if ( cmodel ) {
			contents |= trap->CM_TransformedPointContents( point, cmodel, cent->lerpOrigin, cent->lerpAngles );
		}
	}
	return contents;
}

// ---- the API ----

static qboolean Init( const jkbpHost_t *h ) {
	host = h;
	if ( h->version != JKBP_API_VERSION || h->sizeofPlayerState != (int)sizeof( playerState_t ) ||
		h->sizeofEntityState != (int)sizeof( entityState_t ) ||
		h->sizeofUsercmd != (int)sizeof( usercmd_t ) || h->sizeofTrace != (int)sizeof( trace_t ) ) {
		h->Print( "jkbpredict: the host's structs don't match the library's\n" );
		return qfalse;
	}
	FillImports();
	Com_Memset( &cg, 0, sizeof( cg ) );
	Com_Memset( &cgs, 0, sizeof( cgs ) );
	Com_Memset( cg_entities, 0, sizeof( cg_entities ) );
	CvarRegister( &pmove_fixed, "pmove_fixed", "0", 0 );
	CvarRegister( &bg_fighterAltControl, "bg_fighterAltControl", "0", 0 );
	CvarRegister( &cg_jumpHeight, "cg_jumpHeight", "0", 0 );
	CvarRegister( &cg_legstuck, "cg_legstuck", "0", 0 );
	CvarRegister( &cp_pluginDisable, "cp_pluginDisable", "0", 0 );

	// CG_PmoveClientPointerUpdate
	Com_Memset( sendPSPool, 0, sizeof( sendPSPool ) );
	for ( int i = 0; i < MAX_GENTITIES; i++ ) {
		cgSendPS[i] = &sendPSPool[i];
		cg_entities[i].playerState = cgSendPS[i];
	}
	Com_Memset( &pmv, 0, sizeof( pmv ) );
	pmv.baseEnt = (bgEntity_t *)cg_entities;
	pmv.entSize = sizeof( centity_t );
	pmv.ghoul2 = NULL;
	pmv.g2Bolts_LFoot = pmv.g2Bolts_RFoot = -1;

	// CG_Init: animsets, weapon anims, sabers; every player uses the humanoid set (cg_players.c)
	BG_InitAnimsets();
	BG_FixWeaponAttackAnim();
	WP_SaberLoadParms();
	if ( BG_ParseAnimationFile( "models/players/_humanoid/animation.cfg", bgHumanoidAnimations, qtrue ) == -1 ) {
		h->Print( "jkbpredict: can't load models/players/_humanoid/animation.cfg\n" );
		return qfalse;
	}
	return qtrue;
}

static void SetServerInfo( void ) {
	const char *info = CG_ConfigString( CS_SERVERINFO );
	const char *sys = CG_ConfigString( CS_SYSTEMINFO );
	const char *gamename = Info_ValueForKey( info, "gamename" );

	cgs.debugMelee = atoi( Info_ValueForKey( info, "g_debugMelee" ) );
	cgs.stepSlideFix = atoi( Info_ValueForKey( info, "g_stepSlideFix" ) );
	cgs.noSpecMove = atoi( Info_ValueForKey( info, "g_noSpecMove" ) );
	cgs.gametype = atoi( Info_ValueForKey( info, "g_gametype" ) );
	cgs.dmflags = atoi( Info_ValueForKey( info, "dmflags" ) );
	cgs.taystJKinfo = atoi( Info_ValueForKey( info, "taystJKinfo" ) );
	cgs.legacyProtocol = atoi( Info_ValueForKey( info, "protocol" ) ) < 26;
	// the mod checks in CG_ParseServerinfo only change the mods' own servers; this is basejka
	cgs.serverMod = SVMOD_BASEJKA;
	cgs.baseGame = !Q_stricmpn( gamename, "basejk", 6 );
	// pmove_fixed/msec are CVAR_SYSTEMINFO: the client takes the server's values
	CvarRegister( &pmove_fixed, "pmove_fixed", Info_ValueForKey( sys, "pmove_fixed" ), 0 );
}

static void SetClient( int clientNum, const char *saber1, const char *saber2 ) {
	clientInfo_t *ci = &cgs.clientinfo[clientNum];
	Com_Memset( ci->saber, 0, sizeof( ci->saber ) );
	Q_strncpyz( ci->saberName, saber1, sizeof( ci->saberName ) );
	Q_strncpyz( ci->saber2Name, saber2, sizeof( ci->saber2Name ) );
	WP_SetSaber( clientNum, ci->saber, 0, ci->saberName );
	WP_SetSaber( clientNum, ci->saber, 1, ci->saber2Name );
	ci->infoValid = qtrue;
	cg_entities[clientNum].localAnimIndex = 0;  // humanoid
}

static void SetSnapshot( int serverTime, const playerState_t *ps, const entityState_t *ents, int numEnts ) {
	for ( int i = 0; i < numSolids; i++ ) {
		solids[i]->currentValid = qfalse;
	}
	numSolids = 0;
	snapPS = *ps;
	snapTime = serverTime;
	// CG_TransitionSnapshot: the entities' states, and our own from the playerState
	for ( int i = 0; i < numEnts && i < MAX_ENTITIES_IN_SNAPSHOT; i++ ) {
		centity_t *cent = &cg_entities[ents[i].number];
		cent->currentState = cent->nextState = ents[i];
		cent->currentValid = qtrue;
		BG_EvaluateTrajectory( &ents[i].pos, serverTime, cent->lerpOrigin );
		BG_EvaluateTrajectory( &ents[i].apos, serverTime, cent->lerpAngles );
		// CG_BuildSolidList
		if ( ents[i].eType == ET_ITEM || ents[i].eType == ET_PUSH_TRIGGER || ents[i].eType == ET_TELEPORT_TRIGGER ) {
			continue;
		}
		if ( cent->nextState.solid ) {
			solids[numSolids++] = cent;
		}
	}
	centity_t *self = &cg_entities[ps->clientNum];
	BG_PlayerStateToEntityState( &snapPS, &self->currentState, qfalse );
	self->nextState = self->currentState;
	self->currentValid = qtrue;
	VectorCopy( snapPS.origin, self->lerpOrigin );
	VectorCopy( snapPS.viewangles, self->lerpAngles );
	{  // the hardcoded own bbox CG_BuildSolidList adds (the server doesn't send our entity)
		const int i = 15, j = -DEFAULT_MINS_2, k = DEFAULT_MAXS_2 + 32;
		self->currentState.solid = ( k << 16 ) | ( j << 8 ) | i;
		solids[numSolids++] = self;
	}
}

static int Predict( const usercmd_t *cmds, int numCmds, playerState_t *out ) {
	int ran = 0;
	if ( numCmds < 1 ) {
		*out = snapPS;
		return 0;
	}
	const usercmd_t *latest = &cmds[numCmds - 1];
	clientInfo_t *ci = &cgs.clientinfo[snapPS.clientNum];
	centity_t *pEnt = &cg_entities[snapPS.clientNum];

	cg.time = latest->serverTime;
	cg.snap = NULL;
	cg.predictedPlayerState = snapPS;
	cg.physicsTime = snapTime;
	pmv.ps = &cg.predictedPlayerState;
	pmv.trace = Trace;
	pmv.pointcontents = PointContents;
	pmv.tracemask = snapPS.pm_type == PM_DEAD ? MASK_PLAYERSOLID & ~CONTENTS_BODY : MASK_PLAYERSOLID;
	if ( snapPS.persistant[PERS_TEAM] == TEAM_SPECTATOR || snapPS.pm_type == PM_SPECTATOR ) {
		pmv.tracemask &= ~CONTENTS_BODY;
	}
	pmv.noFootsteps = ( cgs.dmflags & DF_NO_FOOTSTEPS ) > 0;
	pmv.pmove_fixed = pmove_fixed.integer;
	pmv.pmove_float = 0;
	pmv.pmove_msec = 8;

	for ( int i = 0; i < MAX_GENTITIES; i++ ) {
		const entityState_t *s = &cg_entities[i].currentState;
		if ( s->eType == ET_PLAYER || s->eType == ET_NPC ) {
			VectorCopy( s->pos.trBase, cgSendPS[i]->origin );
			VectorCopy( s->pos.trDelta, cgSendPS[i]->velocity );
			cgSendPS[i]->saberLockFrame = s->forceFrame;
			cgSendPS[i]->legsAnim = s->legsAnim;
			cgSendPS[i]->torsoAnim = s->torsoAnim;
			cgSendPS[i]->legsFlip = s->legsFlip;
			cgSendPS[i]->torsoFlip = s->torsoFlip;
			cgSendPS[i]->clientNum = s->clientNum;
			cgSendPS[i]->saberMove = s->saberMove;
		}
	}

	for ( int n = 0; n < numCmds; n++ ) {
		pmv.cmd = cmds[n];
		if ( pmv.pmove_fixed ) {
			PM_UpdateViewAngles( pmv.ps, &pmv.cmd );
		}
		if ( pmv.cmd.serverTime <= cg.predictedPlayerState.commandTime ) {
			continue;
		}
		if ( pmv.cmd.serverTime > latest->serverTime ) {
			continue;
		}
		if ( pmv.pmove_fixed ) {
			pmv.cmd.serverTime = ( ( pmv.cmd.serverTime + pmv.pmove_msec - 1 ) / pmv.pmove_msec ) * pmv.pmove_msec;
		}
		pmv.animations = bgAllAnims[pEnt->localAnimIndex].anims;
		pmv.gametype = cgs.gametype;
		pmv.debugMelee = cgs.debugMelee;
		pmv.stepSlideFix = cgs.stepSlideFix;
		pmv.noSpecMove = cgs.noSpecMove;
		pmv.nonHumanoid = ( pEnt->localAnimIndex > 0 );

		if ( snapPS.saberLockTime > cg.time ) {
			centity_t *blockOpp = &cg_entities[snapPS.saberLockEnemy];
			vec3_t lockDir, lockAng;
			VectorSubtract( blockOpp->lerpOrigin, snapPS.origin, lockDir );
			vectoangles( lockDir, lockAng );
			VectorCopy( lockAng, pmv.ps->viewangles );
		}

		pmv.ps->fd.saberAnimLevelBase = pmv.ps->fd.saberAnimLevel;
		if ( pmv.ps->saberHolstered == 1 ) {
			if ( ci->saber[0].numBlades > 0 ) {
				pmv.ps->fd.saberAnimLevelBase = SS_STAFF;
			} else if ( ci->saber[1].model[0] ) {
				pmv.ps->fd.saberAnimLevelBase = SS_DUAL;
			}
		}

		Pmove( &pmv );
		ran++;
	}
	*out = cg.predictedPlayerState;
	return ran;
}

static const jkbpAPI_t api = { Init, SetServerInfo, SetClient, SetSnapshot, Predict };

Q_EXPORT const jkbpAPI_t *JKBP_GetAPI( int version ) {
	return version == JKBP_API_VERSION ? &api : NULL;
}

#endif // JKBOT_AGENT
