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

#include "server.h"
#include "server/sv_dynbsp.h"
#include "server/sv_dimension.h"
#include "qcommon/cm_public.h"

#ifdef DEDICATED
std::vector<std::unique_ptr<bufferedMessageContainer_t>> demoPreRecordBuffer[MAX_CLIENTS];
std::map<std::string,std::string> demoMetaData[MAX_CLIENTS];
#endif

static qboolean SV_SnapshotEventIsolationPurpose( sharedEntity_t *ent, svIsolationPurpose_t *purpose ) {
	int eventNum;

	if ( !ent || ent->s.eType < ET_EVENTS || !purpose ) {
		return qfalse;
	}

	eventNum = ( ent->s.eType - ET_EVENTS ) & ~EV_EVENT_BITS;
	switch ( eventNum ) {
	case EV_GENERAL_SOUND:
	case EV_ENTITY_SOUND:
	case EV_BMODEL_SOUND:
	case EV_PREDEFSOUND:
		*purpose = SVISO_SOUND;
		return qtrue;
	case EV_GLOBAL_SOUND:
	case EV_GLOBAL_TEAM_SOUND:
	case EV_VOICECMD_SOUND:
	case EV_MUTE_SOUND:
		return qfalse;
	default:
		*purpose = SVISO_EVENT;
		return qtrue;
	}
}

static qboolean SV_SnapshotEventAlwaysGlobal( sharedEntity_t *ent ) {
	int eventNum;

	if ( !ent || ent->s.eType < ET_EVENTS ) {
		return qfalse;
	}

	eventNum = ( ent->s.eType - ET_EVENTS ) & ~EV_EVENT_BITS;
	switch ( eventNum ) {
	case EV_VOICECMD_SOUND:
	case EV_OBITUARY:
		return qtrue;
	default:
		return qfalse;
	}
}

static void SV_TranslateClientMapEntityState( client_t *client, sharedEntity_t *ent, entityState_t *state ) {
	int bspIndex;
	int modelBase;

	if ( !client || !ent || !state || !client->runtimeMapName[0] || !ent->r.bmodel ) {
		return;
	}

	bspIndex = SV_DynBSPClientBSPIndex( client );
	if ( bspIndex < 0 ) {
		return;
	}

	modelBase = CM_SubBSPModelIndex( bspIndex );
	if ( modelBase >= 0 && state->modelindex >= modelBase ) {
		state->modelindex -= modelBase;
	}
	state->solid = SOLID_BMODEL;
}

/*
=============================================================================

Delta encode a client frame onto the network channel

A normal server packet will look like:

4	sequence number (high bit set if an oversize fragment)
<optional reliable commands>
1	svc_snapshot
4	last client reliable command
4	serverTime
1	lastframe for delta compression
1	snapFlags
1	areaBytes
<areabytes>
<playerstate>
<packetentities>

=============================================================================
*/

/*
=============
SV_EmitPacketEntities

Writes a delta update of an entityState_t list to the message.
=============
*/
static void SV_EmitPacketEntities( clientSnapshot_t *from, clientSnapshot_t *to, msg_t *msg ) {
	entityState_t	*oldent, *newent;
	int		oldindex, newindex;
	int		oldnum, newnum;
	int		from_num_entities;

	// generate the delta update
	if ( !from ) {
		from_num_entities = 0;
	} else {
		from_num_entities = from->num_entities;
	}

	newent = NULL;
	oldent = NULL;
	newindex = 0;
	oldindex = 0;
	while ( newindex < to->num_entities || oldindex < from_num_entities ) {
		if ( newindex >= to->num_entities ) {
			newnum = 9999;
		} else {
			newent = &svs.snapshotEntities[(to->first_entity+newindex) % svs.numSnapshotEntities];
			newnum = newent->number;
		}

		if ( oldindex >= from_num_entities ) {
			oldnum = 9999;
		} else {
			oldent = &svs.snapshotEntities[(from->first_entity+oldindex) % svs.numSnapshotEntities];
			oldnum = oldent->number;
		}

		if ( newnum == oldnum ) {
			// delta update from old position
			// because the force parm is qfalse, this will not result
			// in any bytes being emited if the entity has not changed at all
			MSG_WriteDeltaEntity (msg, oldent, newent, qfalse );
			oldindex++;
			newindex++;
			continue;
		}

		if ( newnum < oldnum ) {
			// this is a new entity, send it from the baseline
			MSG_WriteDeltaEntity (msg, &sv.svEntities[newnum].baseline, newent, qtrue );
			newindex++;
			continue;
		}

		if ( newnum > oldnum ) {
			// the old entity isn't present in the new message
			MSG_WriteDeltaEntity (msg, oldent, NULL, qtrue );
			oldindex++;
			continue;
		}
	}

	MSG_WriteBits( msg, (MAX_GENTITIES-1), GENTITYNUM_BITS );	// end of packetentities
}



/*
==================
SV_WriteSnapshotToClient
==================
*/
static void SV_WriteSnapshotToClient( client_t *client, msg_t *msg ) {
	clientSnapshot_t	*frame, *oldframe;
	int					lastframe;
	int					i;
	int					snapFlags;
	int					deltaMessage;

	// this is the snapshot we are creating
	frame = &client->frames[ client->netchan.outgoingSequence & PACKET_MASK ];

	// bots never acknowledge, but it doesn't matter since the only use case is for serverside demos
	// in which case we can delta against the very last message every time
	deltaMessage = client->deltaMessage;
#ifdef DEDICATED
	if ( client->demo.isBot ) {
		client->deltaMessage = client->netchan.outgoingSequence;
	}
#endif

	// try to use a previous frame as the source for delta compressing the snapshot
	if ( deltaMessage <= 0 || client->state != CS_ACTIVE ) {
		// client is asking for a retransmit
		oldframe = NULL;
		lastframe = 0;
	} else if ( client->netchan.outgoingSequence - deltaMessage
		>= (PACKET_BACKUP - 3) ) {
		// client hasn't gotten a good message through in a long time
		Com_DPrintf ("%s: Delta request from out of date packet.\n", client->name);
		oldframe = NULL;
		lastframe = 0;
	} 
#ifdef DEDICATED
	else if ( client->demo.demorecording && client->demo.demowaiting ) {
		// demo is waiting for a non-delta-compressed frame for this client, so don't delta compress
		oldframe = NULL;
		lastframe = 0;
	} else if ( client->demo.minDeltaFrame > deltaMessage ) {
		// we saved a non-delta frame to the demo and sent it to the client, but the client didn't ack it
		// we can't delta against an old frame that's not in the demo without breaking the demo.  so send
		// non-delta frames until the client acks.
		oldframe = NULL;
		lastframe = 0;
	} else if ( sv_demoPreRecord->integer && client->demo.preRecord.keyframeWaiting ) {
		// demo is waiting for a non-delta-compressed frame for this client, so don't delta compress
		oldframe = NULL;
		lastframe = 0;
	} else if (sv_demoPreRecord->integer && client->demo.preRecord.minDeltaFrame > deltaMessage ) {
		// we saved a non-delta frame to the pre-record buffer and sent it to the client, but the client didn't ack it
		// we can't delta against an old frame that's not in the demo without breaking the demo.  so send
		// non-delta frames until the client acks.
		oldframe = NULL;
		lastframe = 0;
	} 
#endif
	else {
		// we have a valid snapshot to delta from
		oldframe = &client->frames[ deltaMessage & PACKET_MASK ];
		lastframe = client->netchan.outgoingSequence - deltaMessage;

		// the snapshot's entities may still have rolled off the buffer, though
		if ( oldframe->first_entity <= svs.nextSnapshotEntities - svs.numSnapshotEntities ) {
			Com_DPrintf ("%s: Delta request from out of date entities.\n", client->name);
			oldframe = NULL;
			lastframe = 0;
		}
	}

#ifdef DEDICATED
	if ( oldframe == NULL ) {
		if ( client->demo.demowaiting ) {
			// this is a non-delta frame, so we can delta against it in the demo
			client->demo.minDeltaFrame = client->netchan.outgoingSequence;
		}
		client->demo.demowaiting = qfalse;
		if ( client->demo.preRecord.keyframeWaiting ) {
			// this is a non-delta frame, so we can delta against it in the demo
			client->demo.preRecord.minDeltaFrame = client->netchan.outgoingSequence;
		}
		client->demo.preRecord.keyframeWaiting = qfalse;
	}
	else {
		if (!client->demo.preRecord.keyframeWaiting) {
			// We got the frame we needed acked, so reset this to 0
			// to avoid any potential shenanigans after map changes or so
			client->demo.preRecord.minDeltaFrame = 0;
		}
		if (!client->demo.demowaiting) {
			// We got the frame we needed acked, so reset this to 0
			// to avoid any potential shenanigans after map changes or so
			client->demo.minDeltaFrame = 0;
		}
	}
#endif

	MSG_WriteByte (msg, svc_snapshot);

	// NOTE, MRE: now sent at the start of every message from server to client
	// let the client know which reliable clientCommands we have received
	//MSG_WriteLong( msg, client->lastClientCommand );

	// send over the current server time so the client can drift
	// its view of time to try to match
	if( client->oldServerTime 
#ifdef DEDICATED
		&& !( client->demo.demorecording && client->demo.isBot )
#endif
		) {
		// The server has not yet got an acknowledgement of the
		// new gamestate from this client, so continue to send it
		// a time as if the server has not restarted. Note from
		// the client's perspective this time is strictly speaking
		// incorrect, but since it'll be busy loading a map at
		// the time it doesn't really matter.
		MSG_WriteLong (msg, sv.time + client->oldServerTime);
	} else {
		MSG_WriteLong (msg, sv.time);
	}

	// what we are delta'ing from
	MSG_WriteByte (msg, lastframe);

	snapFlags = svs.snapFlagServerBit;
	if ( client->rateDelayed ) {
		snapFlags |= SNAPFLAG_RATE_DELAYED;
	}
	if ( client->state != CS_ACTIVE ) {
		snapFlags |= SNAPFLAG_NOT_ACTIVE;
	}

	MSG_WriteByte (msg, snapFlags);

	// send over the areabits
	MSG_WriteByte (msg, frame->areabytes);
	MSG_WriteData (msg, frame->areabits, frame->areabytes);

	// delta encode the playerstate
	if ( oldframe ) {
#ifdef _ONEBIT_COMBO
		MSG_WriteDeltaPlayerstate( msg, &oldframe->ps, &frame->ps, frame->pDeltaOneBit, frame->pDeltaNumBit );
#else
		MSG_WriteDeltaPlayerstate( msg, &oldframe->ps, &frame->ps );
#endif
		if (frame->ps.m_iVehicleNum)
		{ //then write the vehicle's playerstate too
			if (!oldframe->ps.m_iVehicleNum)
			{ //if last frame didn't have vehicle, then the old vps isn't gonna delta
				//properly (because our vps on the client could be anything)
#ifdef _ONEBIT_COMBO
				MSG_WriteDeltaPlayerstate( msg, NULL, &frame->vps, NULL, NULL, qtrue );
#else
				MSG_WriteDeltaPlayerstate( msg, NULL, &frame->vps, qtrue );
#endif
			}
			else
			{
#ifdef _ONEBIT_COMBO
				MSG_WriteDeltaPlayerstate( msg, &oldframe->vps, &frame->vps, frame->pDeltaOneBitVeh, frame->pDeltaNumBitVeh, qtrue );
#else
				MSG_WriteDeltaPlayerstate( msg, &oldframe->vps, &frame->vps, qtrue );
#endif
			}
		}
	} else {
#ifdef _ONEBIT_COMBO
		MSG_WriteDeltaPlayerstate( msg, NULL, &frame->ps, NULL, NULL );
#else
		MSG_WriteDeltaPlayerstate( msg, NULL, &frame->ps );
#endif
		if (frame->ps.m_iVehicleNum)
		{ //then write the vehicle's playerstate too
#ifdef _ONEBIT_COMBO
			MSG_WriteDeltaPlayerstate( msg, NULL, &frame->vps, NULL, NULL, qtrue );
#else
			MSG_WriteDeltaPlayerstate( msg, NULL, &frame->vps, qtrue );
#endif
		}
	}

	// delta encode the entities
	SV_EmitPacketEntities (oldframe, frame, msg);

	// padding for rate debugging
	if ( sv_padPackets->integer ) {
		for ( i = 0 ; i < sv_padPackets->integer ; i++ ) {
			MSG_WriteByte (msg, svc_nop);
		}
	}
}


/*
==================
SV_UpdateServerCommandsToClient

(re)send all server commands the client hasn't acknowledged yet
==================
*/
void SV_UpdateServerCommandsToClient( client_t *client, msg_t *msg ) {
	int		i;
	int		reliableAcknowledge;

#ifdef DEDICATED
	if ( client->demo.isBot && client->demo.demorecording ) {
		reliableAcknowledge = client->demo.botReliableAcknowledge;
	} else
#endif
	{
		reliableAcknowledge = client->reliableAcknowledge;
	}

	// write any unacknowledged serverCommands
	for ( i = reliableAcknowledge + 1 ; i <= client->reliableSequence ; i++ ) {
		MSG_WriteByte( msg, svc_serverCommand );
		MSG_WriteLong( msg, i );
		MSG_WriteString( msg, client->reliableCommands[ i & (MAX_RELIABLE_COMMANDS-1) ] );
	}
	client->reliableSent = client->reliableSequence;
}

/*
=============================================================================

Build a client snapshot structure

=============================================================================
*/

typedef struct snapshotEntityNumbers_s {
	int		numSnapshotEntities;
	int		snapshotEntities[MAX_SNAPSHOT_ENTITIES];
} snapshotEntityNumbers_t;

/*
=======================
SV_QsortEntityNumbers
=======================
*/
static int QDECL SV_QsortEntityNumbers( const void *a, const void *b ) {
	int	*ea, *eb;

	ea = (int *)a;
	eb = (int *)b;

	if ( *ea == *eb ) {
		Com_Error( ERR_DROP, "SV_QsortEntityStates: duplicated entity" );
	}

	if ( *ea < *eb ) {
		return -1;
	}

	return 1;
}


/*
===============
SV_AddEntToSnapshot
===============
*/
static void SV_AddEntToSnapshot( svEntity_t *svEnt, sharedEntity_t *gEnt, snapshotEntityNumbers_t *eNums ) {
	// if we have already added this entity to this snapshot, don't add again
	if ( svEnt->snapshotCounter == sv.snapshotCounter ) {
		return;
	}
	svEnt->snapshotCounter = sv.snapshotCounter;

	// if we are full, silently discard entities
	if ( eNums->numSnapshotEntities == MAX_SNAPSHOT_ENTITIES ) {
		return;
	}

	eNums->snapshotEntities[ eNums->numSnapshotEntities ] = gEnt->s.number;
	eNums->numSnapshotEntities++;
}

/*
===============
SV_AddEntitiesVisibleFromPoint
===============
*/
float g_svCullDist = -1.0f;
#define MAX_LANDING_EFFECTS_PER_SNAPSHOT 16
static void SV_AddEntitiesVisibleFromPoint( vec3_t origin, clientSnapshot_t *frame,
#ifndef DEDICATED
									snapshotEntityNumbers_t *eNums, qboolean portal, int viewerClientNum )
#else
									snapshotEntityNumbers_t *eNums, qboolean portal, qboolean skipDuelCull, int viewerClientNum )
#endif
{
	int		e, i;
	sharedEntity_t *ent;
	svEntity_t	*svEnt;
	int		l;
	int		clientarea, clientcluster;
	int		leafnum;
	byte	*clientpvs;
	byte	*bitvector;
	vec3_t	difference;
	float	length, radius;
	int		effectCount = 0;
	sharedEntity_t *clientBSPInstance = NULL;
	int		clientRuntimeBSPInstance = -1;
	int		clientSubBSPIndex = -1;
	int		clientSubArea = -1;
	int		clientSubCluster = -1;
	byte	*clientSubPVS = NULL;
	vec3_t	clientSubOrigin;
	int		clientMapBSPIndex;
	playerState_t *viewerPs;
	svDimensionView_t viewerView;

	// during an error shutdown message we may need to transmit
	// the shutdown message after the server has shutdown, so
	// specfically check for it
	if ( !sv.state ) {
		return;
	}

	VectorClear( clientSubOrigin );
	viewerPs = SV_GameClientNum( viewerClientNum );
	SV_BeginClientViewDimension( &svs.clients[viewerClientNum], &viewerView );
	clientMapBSPIndex = SV_DynBSPClientBSPIndex( &svs.clients[viewerClientNum] );
	if ( clientMapBSPIndex >= 0 ) {
		clientBSPInstance = SV_DynBSPInstanceForMap( svs.clients[viewerClientNum].runtimeMapName );
		if ( clientBSPInstance ) {
			clientRuntimeBSPInstance = SV_RuntimeBSPInstanceForGentity( clientBSPInstance );
		}

		leafnum = CM_PointLeafnumForBSP( clientMapBSPIndex, origin );
		clientarea = CM_LeafAreaForBSP( clientMapBSPIndex, leafnum );
		clientcluster = CM_LeafClusterForBSP( clientMapBSPIndex, leafnum );
		frame->areabytes = CM_WriteAreaBitsForBSP( clientMapBSPIndex, frame->areabits, clientarea );
		clientpvs = CM_ClusterPVSForBSP( clientMapBSPIndex, clientcluster );
	}
	else {
		const char *spectatorMapName = svs.clients[viewerClientNum].spectatorRuntimeMapName;

		if ( viewerPs && spectatorMapName[0]
			&& ( ( viewerPs->pm_flags & PMF_FOLLOW )
				|| viewerPs->pm_type == PM_SPECTATOR
				|| viewerPs->persistant[PERS_TEAM] == TEAM_SPECTATOR ) ) {
			clientBSPInstance = SV_DynBSPInstanceForMap( spectatorMapName );
			if ( clientBSPInstance ) {
				clientSubBSPIndex = CM_FindSubBSP( clientBSPInstance->s.modelindex );
				if ( clientSubBSPIndex >= 0 ) {
					clientRuntimeBSPInstance = SV_RuntimeBSPInstanceForGentity( clientBSPInstance );
					VectorSubtract( origin, clientBSPInstance->r.currentOrigin, clientSubOrigin );
					leafnum = CM_PointLeafnumForBSP( clientSubBSPIndex, clientSubOrigin );
					clientSubArea = CM_LeafAreaForBSP( clientSubBSPIndex, leafnum );
					clientSubCluster = CM_LeafClusterForBSP( clientSubBSPIndex, leafnum );
					clientSubPVS = CM_ClusterPVSForBSP( clientSubBSPIndex, clientSubCluster );
				}
			}
		}

		leafnum = CM_PointLeafnum (origin);
		clientarea = CM_LeafArea (leafnum);
		clientcluster = CM_LeafCluster (leafnum);

		// calculate the visible areas
		frame->areabytes = CM_WriteAreaBits( frame->areabits, clientarea );

		clientpvs = CM_ClusterPVS (clientcluster);
	}
	for ( e = 0 ; e < sv.num_entities ; e++ ) {
		ent = SV_GentityNum(e);

		// never send entities that aren't linked in
		if ( !ent->r.linked ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-unlinked" );
			continue;
		}

		if (ent->s.eFlags & EF_PERMANENT)
		{	// he's permanent, so don't send him down!
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-EF_PERMANENT" );
			continue;
		}

		if (ent->s.number != e) {
			Com_DPrintf ("FIXING ENT->S.NUMBER!!!\n");
			ent->s.number = e;
		}

		// entities can be flagged to explicitly not be sent to the client
		if ( ent->r.svFlags & SVF_NOCLIENT ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-SVF_NOCLIENT" );
			continue;
		}

		// entities can be flagged to be sent to only one client
		if ( ent->r.svFlags & SVF_SINGLECLIENT ) {
			if ( ent->r.singleClient != frame->ps.clientNum ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-SVF_SINGLECLIENT" );
				continue;
			}
		}
		// entities can be flagged to be sent to everyone but one client
		if ( ent->r.svFlags & SVF_NOTSINGLECLIENT ) {
			if ( ent->r.singleClient == frame->ps.clientNum ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-SVF_NOTSINGLECLIENT" );
				continue;
			}
		}

		svEnt = SV_SvEntityForGentity( ent );

		// don't double add an entity through portals
		if ( svEnt->snapshotCounter == sv.snapshotCounter ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-already-added" );
			continue;
		}

		// entities can request not to be sent to certain clients (NOTE: always send to ourselves)
		if ( e != frame->ps.clientNum && (ent->r.svFlags & SVF_BROADCASTCLIENTS)
			&& !(ent->r.broadcastClients[frame->ps.clientNum/32] & (1 << (frame->ps.clientNum % 32))) )
		{
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-broadcastclients" );
			continue;
		}

		if ( svEnt->runtimeBSPInstance >= 0
			&& !( clientMapBSPIndex >= 0 && clientRuntimeBSPInstance >= 0
				&& svEnt->runtimeBSPInstance == clientRuntimeBSPInstance )
			&& svs.clients[viewerClientNum].loadedBSPModelsGeneration != sv.bspModelsGeneration ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-runtime-bsp-client-unloaded" );
			continue;
		}

		if ( SV_DimensionIsolationEnabled() ) {
			if ( !SV_SnapshotEventAlwaysGlobal( ent ) ) {
				svIsolationPurpose_t eventPurpose;
#ifdef DEDICATED
				qboolean applyCull = !skipDuelCull ? qtrue : qfalse;
#else
				qboolean applyCull = qtrue;
#endif

				if ( applyCull && !SV_ViewCanInteract( &viewerView, ent, SVISO_SNAPSHOT ) ) {
					SV_DynBSPSnapshotDebug( ent, e, frame, "skip-dimension-snapshot" );
					continue;
				}
				if ( applyCull && SV_SnapshotEventIsolationPurpose( ent, &eventPurpose )
					&& !SV_ViewCanInteract( &viewerView, ent, eventPurpose ) ) {
					SV_DynBSPSnapshotDebug( ent, e, frame, eventPurpose == SVISO_SOUND ? "skip-dimension-sound" : "skip-dimension-event" );
					continue;
				}
			}
		}
#ifdef DEDICATED
		else if ( !skipDuelCull && DuelCull( SV_GentityNum( frame->ps.clientNum ), ent ) == 1 ) {
			continue;
		}
#endif

		if (ent->s.eType >= ET_EVENTS && sv_legacyFixes->integer && !(sv_legacyFixes->integer & SVFIXES_DISABLE_MOVEMENT_EVENT_CHECKS) &&
			svs.servermod < SVMOD_JAPRO && svs.servermod != SVMOD_UNKNOWN && svs.servermod != SVMOD_MBII)//only check event types on known mods, to avoid modified eTypes/event enum conflicts
		{
			int eventNum = (ent->s.eType - ET_EVENTS) & ~EV_EVENT_BITS;

			if (eventNum == EV_JUMP || eventNum == EV_FALL || eventNum == EV_FOOTSTEP)
			{ //block these movement-triggered event entities, these should always be on a player
				continue;
			}
			
			if ((eventNum == EV_PLAY_EFFECT || eventNum == EV_PLAY_EFFECT_ID) &&
				(ent->s.eventParm >= EFFECT_WATER_SPLASH && ent->s.eventParm <= EFFECT_LANDING_GRAVEL)) //all landing effects
			{
				effectCount++;
				if (effectCount > MAX_LANDING_EFFECTS_PER_SNAPSHOT)
					continue; //block these so they cant be abused on ffa3
			}
		}

		if ( clientMapBSPIndex >= 0 && svEnt->runtimeBSPInstance >= 0 && SV_DynBSPIsInstanceEntity( ent ) ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-clientMap-holder" );
			continue;
		}

		// broadcast entities are always sent, and so is the main player so we don't see noclip weirdness
		if ( (ent->r.svFlags & SVF_BROADCAST) || e == frame->ps.clientNum
			|| (ent->r.broadcastClients[frame->ps.clientNum/32] & (1 << (frame->ps.clientNum % 32))) )
		{
			SV_DynBSPSnapshotDebug( ent, e, frame, "add-broadcast-or-player" );
			SV_AddEntToSnapshot( svEnt, ent, eNums );
			continue;
		}

		if (ent->s.isPortalEnt)
		{ //rww - portal entities are always sent as well
			SV_DynBSPSnapshotDebug( ent, e, frame, "add-portal-ent" );
			SV_AddEntToSnapshot( svEnt, ent, eNums );
			continue;
		}

#ifdef DEDICATED
		if (sv_autoDemo->integer == 2) //How find out how to only add all entities for the bot named RECORDER, not all bots? what entities can we still exclude?
		{
			sharedEntity_t *ent2;
			ent2 = SV_GentityNum(frame->ps.clientNum);
			if (ent2->r.svFlags & SVF_BOT && ent2->playerState->pm_type == PM_SPECTATOR) {
				SV_AddEntToSnapshot( svEnt, ent, eNums );
				continue;
			}
		}
#endif

		if ( clientMapBSPIndex >= 0 ) {
			if ( clientRuntimeBSPInstance >= 0
				&& svEnt->runtimeBSPInstance >= 0
				&& svEnt->runtimeBSPInstance != clientRuntimeBSPInstance ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-clientMap-instance" );
				continue;
			}

			if ( !CM_AreasConnectedForBSP( clientMapBSPIndex, clientarea, svEnt->areanum ) ) {
				if ( !CM_AreasConnectedForBSP( clientMapBSPIndex, clientarea, svEnt->areanum2 ) ) {
					SV_DynBSPSnapshotDebug( ent, e, frame, "skip-clientMap-area" );
					continue;
				}
			}

			if ( !svEnt->numClusters ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-clientMap-no-clusters" );
				continue;
			}

			if ( !SV_DynBSPEntityVisibleInPVS( svEnt, clientpvs ) ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-clientMap-pvs" );
				continue;
			}
		}
		else if ( svEnt->runtimeBSPInstance >= 0 ) {
			if ( svEnt->runtimeBSPInstance != clientRuntimeBSPInstance || clientSubBSPIndex < 0 || !clientSubPVS ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-runtime-bsp-instance" );
				continue;
			}

			if ( !CM_AreasConnectedForBSP( clientSubBSPIndex, clientSubArea, svEnt->areanum ) ) {
				if ( !CM_AreasConnectedForBSP( clientSubBSPIndex, clientSubArea, svEnt->areanum2 ) ) {
					SV_DynBSPSnapshotDebug( ent, e, frame, "skip-runtime-bsp-area" );
					continue;
				}
			}

			if ( !svEnt->numClusters ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-runtime-bsp-no-clusters" );
				continue;
			}

			if ( !SV_DynBSPEntityVisibleInPVS( svEnt, clientSubPVS ) ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, svEnt->lastCluster ? "skip-runtime-bsp-pvs-overflow" : "skip-runtime-bsp-pvs" );
				continue;
			}
		}
		else if ( clientRuntimeBSPInstance >= 0 ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-parent-map-from-runtime-bsp" );
			continue;
		}
		else {
		// ignore if not touching a PV leaf
		// check area
		if ( !CM_AreasConnected( clientarea, svEnt->areanum ) ) {
			// doors can legally straddle two areas, so
			// we may need to check another one
			if ( !CM_AreasConnected( clientarea, svEnt->areanum2 ) ) {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-area" );
				continue;		// blocked by a door
			}
		}

		bitvector = clientpvs;

		// check individual leafs
		if ( !svEnt->numClusters ) {
			SV_DynBSPSnapshotDebug( ent, e, frame, "skip-no-clusters" );
			continue;
		}
		l = 0;
		for ( i=0 ; i < svEnt->numClusters ; i++ ) {
			l = svEnt->clusternums[i];
			if ( bitvector[l >> 3] & (1 << (l&7) ) ) {
				break;
			}
		}

		// if we haven't found it to be visible,
		// check overflow clusters that coudln't be stored
		if ( i == svEnt->numClusters ) {
			if ( svEnt->lastCluster ) {
				for ( ; l <= svEnt->lastCluster ; l++ ) {
					if ( bitvector[l >> 3] & (1 << (l&7) ) ) {
						break;
					}
				}
				if ( l == svEnt->lastCluster ) {
					SV_DynBSPSnapshotDebug( ent, e, frame, "skip-pvs-overflow" );
					continue;	// not visible
				}
			} else {
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-pvs" );
				continue;
			}
		}
		}

		if (g_svCullDist != -1.0f)
		{ //do a distance cull check
			VectorAdd(ent->r.absmax, ent->r.absmin, difference);
			VectorScale(difference, 0.5f, difference);
			VectorSubtract(origin, difference, difference);
			length = VectorLength(difference);

			// calculate the diameter
			VectorSubtract(ent->r.absmax, ent->r.absmin, difference);
			radius = VectorLength(difference);
			if (length-radius >= g_svCullDist)
			{ //then don't add it
				SV_DynBSPSnapshotDebug( ent, e, frame, "skip-distance" );
				continue;
			}
		}

		// add it
		SV_DynBSPSnapshotDebug( ent, e, frame, "add-visible" );
		SV_AddEntToSnapshot( svEnt, ent, eNums );

		// if its a portal entity, add everything visible from its camera position
		if ( ent->r.svFlags & SVF_PORTAL ) {
			if ( ent->s.generic1 ) {
				vec3_t dir;
				VectorSubtract(ent->s.origin, origin, dir);
				if ( VectorLengthSquared(dir) > (float) ent->s.generic1 * ent->s.generic1 ) {
					continue;
				}
			}
#ifndef DEDICATED
			SV_AddEntitiesVisibleFromPoint( ent->s.origin2, frame, eNums, qtrue, viewerClientNum );
#else
			SV_AddEntitiesVisibleFromPoint( ent->s.origin2, frame, eNums, qtrue, skipDuelCull, viewerClientNum );
#endif
		}
	}
}

/*
=============
SV_BuildClientSnapshot

Decides which entities are going to be visible to the client, and
copies off the playerstate and areabits.

This properly handles multiple recursive portals, but the render
currently doesn't.

For viewing through other player's eyes, client can be something other than client->gentity
=============
*/
static void SV_BuildClientSnapshot( client_t *client ) {
	vec3_t						org;
	clientSnapshot_t			*frame;
	snapshotEntityNumbers_t		entityNumbers;
	int							i;
	sharedEntity_t				*ent;
	entityState_t				*state;
	svEntity_t					*svEnt;
	sharedEntity_t				*clent;
	playerState_t				*ps;

	// bump the counter used to prevent double adding
	sv.snapshotCounter++;

	// this is the frame we are creating
	frame = &client->frames[ client->netchan.outgoingSequence & PACKET_MASK ];

	// clear everything in this snapshot
	entityNumbers.numSnapshotEntities = 0;
	Com_Memset( frame->areabits, 0, sizeof( frame->areabits ) );

	frame->num_entities = 0;

	clent = client->gentity;
	if ( !clent || client->state == CS_ZOMBIE ) {
		return;
	}

	// grab the current playerState_t
	ps = SV_GameClientNum( client - svs.clients );
	frame->ps = *ps;
	SV_DynBSPSpectatorProjectPlayerState( client, &frame->ps );
#ifdef _ONEBIT_COMBO
	frame->pDeltaOneBit = &ps->deltaOneBits;
	frame->pDeltaNumBit = &ps->deltaNumBits;
#endif

	if (ps->m_iVehicleNum)
	{ //get the vehicle's playerstate too then
		sharedEntity_t *veh = SV_GentityNum(ps->m_iVehicleNum);

		if (veh && veh->playerState)
		{ //Now VMA it and we've got ourselves a playerState
			playerState_t *vps = ((playerState_t *)VM_ArgPtr((intptr_t)veh->playerState));

            frame->vps = *vps;
#ifdef _ONEBIT_COMBO
			frame->pDeltaOneBitVeh = &vps->deltaOneBits;
			frame->pDeltaNumBitVeh = &vps->deltaNumBits;
#endif
		}
	}

	int							clientNum;
	// never send client's own entity, because it can
	// be regenerated from the playerstate
	clientNum = frame->ps.clientNum;
	if ( clientNum < 0 || clientNum >= MAX_GENTITIES ) {
		Com_Error( ERR_DROP, "SV_SvEntityForGentity: bad gEnt" );
	}
	svEnt = &sv.svEntities[ clientNum ];
	svEnt->snapshotCounter = sv.snapshotCounter;


	// find the client's viewpoint
	VectorCopy( frame->ps.origin, org );
	org[2] += frame->ps.viewheight;

	// add all the entities directly visible to the eye, which
	// may include portal entities that merge other viewpoints
#ifndef DEDICATED
	SV_AddEntitiesVisibleFromPoint( org, frame, &entityNumbers, qfalse, client - svs.clients );
#else
	SV_AddEntitiesVisibleFromPoint( org, frame, &entityNumbers, qfalse, client->disableDuelCull, client - svs.clients );
#endif

	// if there were portals visible, there may be out of order entities
	// in the list which will need to be resorted for the delta compression
	// to work correctly.  This also catches the error condition
	// of an entity being included twice.
	qsort( entityNumbers.snapshotEntities, entityNumbers.numSnapshotEntities,
		sizeof( entityNumbers.snapshotEntities[0] ), SV_QsortEntityNumbers );

	// now that all viewpoint's areabits have been OR'd together, invert
	// all of them to make it a mask vector, which is what the renderer wants
	for ( i = 0 ; i < MAX_MAP_AREA_BYTES/4 ; i++ ) {
		((int *)frame->areabits)[i] = ((int *)frame->areabits)[i] ^ -1;
	}

	// copy the entity states out
	svDimensionView_t clientView;
	SV_BeginClientViewDimension( client, &clientView );
	frame->num_entities = 0;
	frame->first_entity = svs.nextSnapshotEntities;
	for ( i = 0 ; i < entityNumbers.numSnapshotEntities ; i++ ) {
		ent = SV_GentityNum(entityNumbers.snapshotEntities[i]);
		state = &svs.snapshotEntities[svs.nextSnapshotEntities % svs.numSnapshotEntities];
		*state = ent->s;
		SV_TranslateClientMapEntityState( client, ent, state );
		if ( SV_DimensionIsolationEnabled() ) {
#ifdef DEDICATED
			if ( !client->jpPlugin && !ent->r.bmodel && !SV_ViewCanInteract( &clientView, ent, SVISO_TRACE ) ) {
				state->solid = 0;
			}
#else
			if ( !ent->r.bmodel && !SV_ViewCanInteract( &clientView, ent, SVISO_TRACE ) ) {
				state->solid = 0;
			}
#endif
		}
#ifdef DEDICATED
		else if ( !client->jpPlugin && DuelCull( client->gentity, ent ) ) {
			state->solid = 0;
		}
#endif
		svs.nextSnapshotEntities++;
		// this should never hit, map should always be restarted first in SV_Frame
		if ( svs.nextSnapshotEntities >= 0x7FFFFFFE ) {
			Com_Error(ERR_FATAL, "svs.nextSnapshotEntities wrapped");
		}
		frame->num_entities++;
	}
}


/*
====================
SV_RateMsec

Return the number of msec a given size message is supposed
to take to clear, based on the current rate
====================
*/
#define	HEADER_RATE_BYTES	48		// include our header, IP header, and some overhead
static int SV_RateMsec( client_t *client, int messageSize ) {
	int		rate;
	int		rateMsec;

	// individual messages will never be larger than fragment size
	if ( messageSize > 1500 ) {
		messageSize = 1500;
	}
	rate = client->rate;
	if ( sv_maxRate->integer ) {
		if ( sv_maxRate->integer < 1000 ) {
			Cvar_Set( "sv_MaxRate", "1000" );
		}
		if ( sv_maxRate->integer < rate ) {
			rate = sv_maxRate->integer;
		}
	}
	if ( sv_minRate->integer ) {
		if ( sv_minRate->integer < 1000 ) {
			Cvar_Set( "sv_minRate", "1000" );
		}
		if ( sv_minRate->integer > rate ) {
			rate = sv_minRate->integer;
		}
	}

	rateMsec = ( messageSize + HEADER_RATE_BYTES ) * 1000 / ((int) (rate * com_timescale->value));

	return rateMsec;
}

extern void SV_WriteDemoMessage ( client_t *cl, msg_t *msg, int headerBytes );
// defined in sv_client.cpp
extern void SV_CreateClientGameStateMessage(client_t* client, msg_t* msg);
/*
=======================
SV_SendMessageToClient

Called by SV_SendClientSnapshot and SV_SendClientGameState
=======================
*/
void SV_SendMessageToClient( msg_t *msg, client_t *client ) {
	int			rateMsec;

	// MW - my attempt to fix illegible server message errors caused by
	// packet fragmentation of initial snapshot.
	while(client->state&&client->netchan.unsentFragments)
	{
		// send additional message fragments if the last message
		// was too large to send at once
		Com_Printf ("[ISM]SV_SendClientGameState() [1] for %s, writing out old fragments\n", client->name);
		SV_Netchan_TransmitNextFragment(&client->netchan);
	}

	// record information about the message
	client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageSize = msg->cursize;
	// With sv_pingFix enabled we use a time value that is not limited by sv_fps.
	client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageSent = (sv_pingFix->integer ? Sys_Milliseconds() : svs.time);
	client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageAcked = -1;

#ifdef DEDICATED
	if (sv_demoPreRecord->integer) { // If pre record demo message buffering is enabled, we write this message to the buffer.

		// But first, Do a quick cleanup of possible old packages in the buffer that have msgNum > client->netchan.outgoingSequence
		// This shouldn't really happen as we clear the buffer on disconnects/connects and map_restarts but let's be safe.
		demoPreRecordBufferIt lastEvilPackage;
		qboolean evilPackagesFound = qfalse;
		for (demoPreRecordBufferIt it = demoPreRecordBuffer[client - svs.clients].begin(); it != demoPreRecordBuffer[client - svs.clients].end(); it++) {
			if (it->get()->msgNum > client->netchan.outgoingSequence || it->get()->time > sv.time) {
				lastEvilPackage = it;
				evilPackagesFound = qtrue;
			}
			else {
				break;
			}
		}
		if (evilPackagesFound) {
			// The lastTooOldKeyframe itself won't be erased because .erase()'s second parameter is not inclusive, 
			// aka it deletes up to that element, but not that element itself.
			Com_Printf("Found evil old messages in demoPreRecordBuffer. This shouldn't happen.\n");
			lastEvilPackage++; // .erase() function excludes the last element, but we want to delete the last evil package too.
			demoPreRecordBuffer[client - svs.clients].erase(demoPreRecordBuffer[client - svs.clients].begin(), lastEvilPackage);
		}

		// Now put the current messsage in the buffer.
		if(client->netchan.remoteAddress.type != NA_BOT || sv_demoPreRecordBots->integer){
			std::unique_ptr<bufferedMessageContainer_t> bmtPtr(new bufferedMessageContainer_t(msg));
			bufferedMessageContainer_t* bmt = bmtPtr.get();
			//static bufferedMessageContainer_t bmt; // I make these static so they don't sit on the stack.
			//Com_Memset(bmt, 0, sizeof(bufferedMessageContainer_t));
			//MSG_ToBuffered(msg,&bmt->msg);
			bmt->msgNum = client->netchan.outgoingSequence;
			bmt->lastClientCommand = client->lastClientCommand;
			bmt->time = sv.time;
			bmt->isKeyframe = qfalse; // In theory it might be a gamestate message, but we only call it a keyframe if we ourselves explicitly save a keyframe.
			demoPreRecordBuffer[client - svs.clients].push_back(std::move(bmtPtr));
		}
	}

	// save the message to demo.  this must happen before sending over network as that encodes the backing databuf
	if ( client->demo.demorecording && !client->demo.demowaiting ) {
		msg_t msgcopy = *msg;
		MSG_WriteByte( &msgcopy, svc_EOF );
		SV_WriteDemoMessage( client, &msgcopy, 0 );
	}

	// Check for whether a new keyframe must be written in pre recording, and if so, do it.
	if (sv_demoPreRecord->integer && (client->netchan.remoteAddress.type != NA_BOT || sv_demoPreRecordBots->integer)) {

		if (client->demo.preRecord.lastKeyframeTime + (1000 * sv_demoPreRecordKeyframeDistance->integer) < sv.time || client->demo.preRecord.lastKeyframeTime > sv.time) { // See if it's time for a new keyframe, or if the last keyframe was made before a serverTime restart.
			// Save a keyframe.
			static byte keyframeBufData[MAX_MSGLEN]; // I make these static so they don't sit on the stack.
			static msg_t		keyframeMsg;
			Com_Memset(&keyframeMsg, 0, sizeof(msg_t));
			//Com_Memset(bmt, 0, sizeof(bufferedMessageContainer_t));

			MSG_Init(&keyframeMsg, keyframeBufData, sizeof(keyframeBufData));

			int tmp = client->reliableSent; //Idk if this is still needed? Might have been from an older version of SV_CreateClientGameStateMessage that changed that?
			SV_CreateClientGameStateMessage(client, &keyframeMsg);
			client->reliableSent = tmp;

			//MSG_ToBuffered(&keyframeMsg, &bmt->msg);
			std::unique_ptr<bufferedMessageContainer_t> bmtPtr(new bufferedMessageContainer_t(&keyframeMsg));
			bufferedMessageContainer_t* bmt = bmtPtr.get();
			bmt->msgNum = client->netchan.outgoingSequence; // Yes the keyframe duplicates the messagenum of a message. This is (part of) why we dump only one keyframe at the start of the demo and discard future keyframes
			bmt->lastClientCommand = client->lastClientCommand;
			bmt->time = sv.time;
			bmt->isKeyframe = qtrue; // This is a keyframe (gamestate that will be followed by non-delta frames)
			demoPreRecordBuffer[client - svs.clients].push_back(std::move(bmtPtr));
			client->demo.preRecord.minDeltaFrame = 0;
			client->demo.preRecord.keyframeWaiting = qtrue;
			client->demo.preRecord.lastKeyframeTime = sv.time;
		}

		// Clean up pre-record buffer
		// 
		// The goal is to always maintain *at least* sv_demoPreRecordTime seconds of buffer. Rather more than less. 
		// So we find the last keyframe that is older than sv_demoPreRecordTime seconds (or just that old) and then delete everything *before* it.
		demoPreRecordBufferIt lastTooOldKeyframe;
		qboolean lastTooOldKeyframeFound = qfalse;
		for (demoPreRecordBufferIt it = demoPreRecordBuffer[client - svs.clients].begin(); it != demoPreRecordBuffer[client - svs.clients].end(); it++) {
			if (it->get()->isKeyframe && (it->get()->time + (1000*sv_demoPreRecordTime->integer)) < sv.time) {
				lastTooOldKeyframe = it;
				lastTooOldKeyframeFound = qtrue;
			}
		}
		if (lastTooOldKeyframeFound) {
			// The lastTooOldKeyframe itself won't be erased because .erase()'s second parameter is not inclusive, 
			// aka it deletes up to that element, but not that element itself.
			demoPreRecordBuffer[client - svs.clients].erase(demoPreRecordBuffer[client - svs.clients].begin(), lastTooOldKeyframe);
		}
	}
	else { // Pre-recording disabled. Clear buffer to prevent unexpected behavior if it is turned back on.
		SV_ClearClientDemoPreRecord(client);
	}

	// bots need to have their snapshots built, but
	// they query them directly without needing to be sent
	if ( client->demo.isBot ) {
		client->netchan.outgoingSequence++;
		client->demo.botReliableAcknowledge = client->reliableSent;
		return;
	}
#endif

	// send the datagram
	SV_Netchan_Transmit( client, msg );	//msg->cursize, msg->data );

	// set nextSnapshotTime based on rate and requested number of updates

	// local clients get snapshots every server frame
	// TTimo - https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=491
	// added sv_lanForceRate check
	if ( client->netchan.remoteAddress.type == NA_LOOPBACK || (sv_lanForceRate->integer && Sys_IsLANAddress (&client->netchan.remoteAddress)) ) {
		client->nextSnapshotTime = svs.time + ((int) (1000.0 / sv_fps->integer * com_timescale->value));
		return;
	}

	// normal rate / snapshotMsec calculation
	rateMsec = SV_RateMsec( client, msg->cursize );

	if ( rateMsec < client->snapshotMsec ) {
		// never send more packets than this, no matter what the rate is at
		rateMsec = client->snapshotMsec;
		client->rateDelayed = qfalse;
	} else {
		client->rateDelayed = qtrue;
	}

	client->nextSnapshotTime = svs.time + ((int) (rateMsec * com_timescale->value));

	// don't pile up empty snapshots while connecting
	if ( client->state != CS_ACTIVE ) {
		// a gigantic connection message may have already put the nextSnapshotTime
		// more than a second away, so don't shorten it
		// do shorten if client is downloading
		if ( !*client->downloadName && client->nextSnapshotTime < svs.time + ((int) (1000.0 * com_timescale->value)) ) {
			client->nextSnapshotTime = svs.time + ((int) (1000 * com_timescale->value));
		}
	}
}


/*
=======================
SV_SendClientSnapshot

Also called by SV_FinalMessage

=======================
*/
extern cvar_t	*fs_gamedirvar;
void SV_SendClientSnapshot( client_t *client ) {
	byte		msg_buf[MAX_MSGLEN];
	msg_t		msg;

	if ( SV_DynBSPClientNeedsGameState( client ) ) {
		clientState_t oldState = client->state;

		SV_DynBSPPrepareClientGameState( client );
		client->state = CS_CONNECTED;
		SV_SendClientGameState( client );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPDEBUG server lazy gamestate sent client=%i name='%s' oldState=%i newState=%i gamestateMessageNum=%i\n",
				(int)( client - svs.clients ), client->name, oldState, client->state, client->gamestateMessageNum );
		}
		return;
	}

	if (!client->sentGamedir)
	{ //rww - if this is the case then make sure there is an svc_setgame sent before this snap
		int i = 0;

		MSG_Init (&msg, msg_buf, sizeof(msg_buf));

		//have to include this for each message.
		MSG_WriteLong( &msg, client->lastClientCommand );

		MSG_WriteByte (&msg, svc_setgame);

		const char *gamedir = FS_GetCurrentGameDir(true);

		while (gamedir[i])
		{
			MSG_WriteByte(&msg, gamedir[i]);
			i++;
		}
		MSG_WriteByte(&msg, 0);

		// MW - my attempt to fix illegible server message errors caused by
		// packet fragmentation of initial snapshot.
		//rww - reusing this code here
		while(client->state&&client->netchan.unsentFragments)
		{
			// send additional message fragments if the last message
			// was too large to send at once
			Com_Printf ("[ISM]SV_SendClientGameState() [1] for %s, writing out old fragments\n", client->name);
			SV_Netchan_TransmitNextFragment(&client->netchan);
		}

		// record information about the message
		client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageSize = msg.cursize;
		client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageSent = svs.time;
		client->frames[client->netchan.outgoingSequence & PACKET_MASK].messageAcked = -1;

		// send the datagram
		SV_Netchan_Transmit( client, &msg );	//msg->cursize, msg->data );

		client->sentGamedir = qtrue;
	}

	// build the snapshot
	SV_BuildClientSnapshot( client );

#ifdef DEDICATED
	if ( !client->demo.demorecording ) { //dont think this needs to be done with singledemo option
		if (sv_autoDemo->integer == 2) {
			if (client->netchan.remoteAddress.type == NA_BOT && !Q_stricmp(client->name, "RECORDER")) {
				SV_BeginAutoRecordDemos();
			}
		}
		else if (sv_autoDemo->integer == 1) {
			if ( client->netchan.remoteAddress.type != NA_BOT || sv_autoDemoBots->integer ) {
				SV_BeginAutoRecordDemos();
			}
		}
	}
#endif

	// bots need to have their snapshots built, but
	// they query them directly without needing to be sent
	if ( client->netchan.remoteAddress.type == NA_BOT
#ifdef DEDICATED
		&& !client->demo.demorecording 
#endif
		) {
		return;
	}

	MSG_Init (&msg, msg_buf, sizeof(msg_buf));
	msg.allowoverflow = qtrue;

	// NOTE, MRE: all server->client messages now acknowledge
	// let the client know which reliable clientCommands we have received
	MSG_WriteLong( &msg, client->lastClientCommand );

	// (re)send any reliable server commands
	SV_UpdateServerCommandsToClient( client, &msg );

	// send over all the relevant entityState_t
	// and the playerState_t
	SV_WriteSnapshotToClient( client, &msg );

	// Add any download data if the client is downloading
	SV_WriteDownloadToClient( client, &msg );

	// check for overflow
	if ( msg.overflowed ) {
		Com_Printf ("WARNING: msg overflowed for %s\n", client->name);
		MSG_Clear (&msg);
	}

	SV_SendMessageToClient( &msg, client );
}


/*
=======================
SV_SendClientMessages
=======================
*/
void SV_SendClientMessages( void ) {
	int			i;
	client_t	*c;

	// send a message to each connected client
	for (i=0, c = svs.clients ; i < sv_maxclients->integer ; i++, c++) {
		if (!c->state) {
			continue;		// not connected
		}

		if ( svs.time < c->nextSnapshotTime ) {
			continue;		// not time yet
		}

		// send additional message fragments if the last message
		// was too large to send at once
		if ( c->netchan.unsentFragments ) {
			c->nextSnapshotTime = svs.time +
				SV_RateMsec( c, c->netchan.unsentLength - c->netchan.unsentFragmentStart );
			SV_Netchan_TransmitNextFragment( &c->netchan );
			continue;
		}

		// generate and send a new message
		SV_SendClientSnapshot( c );
	}
}

