/*
 * JKBot packet and latency scheduler (simulator only). See README.md in this directory.
 *
 * Each agent client is emulated as a real client on a link with ping_up / ping_down, on the
 * lockstep clock (now = sv.time + sv.timeResidual, advancing JKB_USERCMD_MSEC per STEP). The
 * semantics are the reference model's (training/src/jkbot/net/model.py, P1-NET-01), so the
 * delivery log equals it:
 *
 * - Client frame (once per STEP): the agent's held usercmd becomes usercmd n. A packet goes out
 *   only if at least 1000 / cl_maxpackets ms (integer, maxpackets clamped to 20..1000) have passed
 *   since the last one, carrying the usercmds created since the previous packet (plus the
 *   cl_packetdup packets' before it, which the server skips), and arrives at send + ping_up.
 * - Server: each snapshot SV_BuildClientSnapshot builds for the agent (every server frame here)
 *   arrives at its svs.time + ping_down; the agent holds the newest arrived snapshot.
 * - A packet is delivered at the first STEP at or after its arrival time: its new usercmds go to
 *   SV_ClientThink in order, then the replies a real client's packet carries: the snapshot it
 *   held when sending is acknowledged (so the server's ping is the real round trip), reliable
 *   commands up to those that snapshot carried are acknowledged, and lastPacketTime is now.
 *
 * A usercmd is stamped with the client's estimate of server time when created: now - ping_down
 * (cl_timeNudge 0: the latest snapshot's time plus the time since it arrived; the client's drift
 * correction isn't modelled).
 *
 * Console commands until RESET carries the link (P1-ENG-09):
 *   jkbot_agent_net <client> <ping_up> <ping_down> [maxpackets] [packetdup]   (resets the link)
 *   jkbot_netlog <path> | stop     log packets (P) and snapshots (S sent, H held), one per line
 */
#ifdef JKBOT_AGENT

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "server/server.h"
#include "jkbot_agent.h"

#define JKB_MAX_INFLIGHT	256
#define JKB_CMD_RING		1024
#define JKB_MAX_DUP			5

typedef struct {
	int sendMs, arriveMs;
	int firstNew, newCount, firstCmd;
	int ackMessage;  // the snapshot the client held when sending (-1: none yet)
	int ackServerTime;
	int ackReliable;
} jkbPacket_t;

typedef struct {
	int messageNum, serverTime, arriveMs;
	int reliableSequence;  // reliable commands the snapshot carried
} jkbSnap_t;

typedef struct {
	qboolean active;
	int pingUp, pingDown, maxPackets, packetDup;
	int numCmds;  // usercmds created so far
	usercmd_t cmds[JKB_CMD_RING];
	int sentUpto[JKB_MAX_DUP + 2];  // usercmd count at each recent packet, oldest first
	int numSent;
	int lastSend;  // -1: none yet
	jkbPacket_t inflight[JKB_MAX_INFLIGHT];
	int inHead, inCount;
	jkbSnap_t snaps[JKB_MAX_INFLIGHT];
	int snapHead, snapCount;
	int lastBuilt;  // outgoingSequence up to which snapshots are recorded
	int held;  // messageNum of the newest arrived snapshot, -1 none
	int heldServerTime;
	int heldReliable;
} jkbLink_t;

static jkbLink_t links[MAX_CLIENTS];
static FILE *netlog;

static void Log( const char *fmt, ... ) {
	if ( !netlog ) {
		return;
	}
	va_list ap;
	va_start( ap, fmt );
	vfprintf( netlog, fmt, ap );
	va_end( ap );
}

void JKBot_NetReset( int clientNum, int pingUp, int pingDown, int maxPackets, int packetDup ) {
	jkbLink_t *l = &links[clientNum];
	Com_Memset( l, 0, sizeof( *l ) );
	l->active = qtrue;
	l->pingUp = pingUp < 0 ? 0 : pingUp;
	l->pingDown = pingDown < 0 ? 0 : pingDown;
	l->maxPackets = maxPackets < 20 ? 20 : maxPackets > 1000 ? 1000 : maxPackets;
	l->packetDup = packetDup < 0 ? 0 : packetDup > JKB_MAX_DUP ? JKB_MAX_DUP : packetDup;
	l->lastSend = -1;
	l->held = -1;
	l->lastBuilt = svs.clients[clientNum].netchan.outgoingSequence;
	Log( "R %d %d %d %d %d %d\n", clientNum, sv.time + sv.timeResidual, l->pingUp, l->pingDown,
		l->maxPackets, l->packetDup );
}

void JKBot_NetDrop( int clientNum ) {
	links[clientNum].active = qfalse;
}

int JKBot_NetHeld( int clientNum, int *serverTime ) {
	const jkbLink_t *l = &links[clientNum];
	if ( !l->active ) {
		return -1;
	}
	if ( serverTime ) {
		*serverTime = l->heldServerTime;
	}
	return l->held;
}

static void RecordSnapshots( int clientNum, jkbLink_t *l, const client_t *cl ) {
	while ( l->lastBuilt < cl->netchan.outgoingSequence ) {
		if ( l->snapCount == JKB_MAX_INFLIGHT ) {
			Com_Error( ERR_DROP, "jkbot netsched: snapshot queue full" );
		}
		jkbSnap_t *s = &l->snaps[( l->snapHead + l->snapCount++ ) % JKB_MAX_INFLIGHT];
		s->messageNum = l->lastBuilt++;
		s->serverTime = svs.time;  // built in this STEP's SV_Frame, at its frame time
		s->arriveMs = svs.time + l->pingDown;
		s->reliableSequence = cl->reliableSequence;
		Log( "S %d %d %d %d\n", clientNum, s->messageNum, s->serverTime, s->arriveMs );
	}
}

static void ReceiveSnapshots( int clientNum, jkbLink_t *l, int now ) {
	while ( l->snapCount && l->snaps[l->snapHead].arriveMs <= now ) {
		const jkbSnap_t *s = &l->snaps[l->snapHead];
		l->held = s->messageNum;
		l->heldServerTime = s->serverTime;
		l->heldReliable = s->reliableSequence;
		Log( "H %d %d %d\n", clientNum, s->messageNum, now );
		l->snapHead = ( l->snapHead + 1 ) % JKB_MAX_INFLIGHT;
		l->snapCount--;
	}
}

static void ClientFrame( int clientNum, jkbLink_t *l, int now ) {
	usercmd_t cmd = *JKBot_AgentCmd( clientNum );
	cmd.serverTime = now - l->pingDown;
	l->cmds[l->numCmds % JKB_CMD_RING] = cmd;
	l->numCmds++;
	JKBot_AgentCmdConsumed( clientNum );
	if ( l->lastSend >= 0 && now - l->lastSend < 1000 / l->maxPackets ) {
		return;  // CL_ReadyToSendPacket: not yet
	}
	const int prev = l->numSent ? l->sentUpto[l->numSent - 1] : 0;
	const int dupFrom = l->numSent - 1 - l->packetDup;
	if ( l->inCount == JKB_MAX_INFLIGHT ) {
		Com_Error( ERR_DROP, "jkbot netsched: packet queue full" );
	}
	if ( l->numCmds - prev > JKB_CMD_RING ) {
		Com_Error( ERR_DROP, "jkbot netsched: usercmd ring overflow" );
	}
	jkbPacket_t *p = &l->inflight[( l->inHead + l->inCount++ ) % JKB_MAX_INFLIGHT];
	p->sendMs = now;
	p->arriveMs = now + l->pingUp;
	p->firstNew = prev;
	p->newCount = l->numCmds - prev;
	p->firstCmd = dupFrom >= 0 ? l->sentUpto[dupFrom] : 0;
	p->ackMessage = l->held;
	p->ackServerTime = l->heldServerTime;
	p->ackReliable = l->heldReliable;
	if ( l->numSent == JKB_MAX_DUP + 2 ) {
		for ( int i = 1; i < l->numSent; i++ ) {
			l->sentUpto[i - 1] = l->sentUpto[i];
		}
		l->numSent--;
	}
	l->sentUpto[l->numSent++] = l->numCmds;
	l->lastSend = now;
}

static void DeliverPackets( int clientNum, jkbLink_t *l, client_t *cl, int now ) {
	while ( l->inCount && l->inflight[l->inHead].arriveMs <= now ) {
		const jkbPacket_t p = l->inflight[l->inHead];
		l->inHead = ( l->inHead + 1 ) % JKB_MAX_INFLIGHT;
		l->inCount--;
		Log( "P %d %d %d %d %d %d %d\n", clientNum, p.sendMs, p.arriveMs, now, p.firstNew,
			p.newCount, p.firstCmd );
		for ( int n = p.firstNew; n < p.firstNew + p.newCount; n++ ) {
			usercmd_t cmd = l->cmds[n % JKB_CMD_RING];
			SV_ClientThink( cl, &cmd );
			if ( cl->state < CS_CONNECTED ) {
				return;  // dropped during the usercmd
			}
		}
		cl->lastPacketTime = svs.time;
		if ( p.ackMessage >= 0 ) {
			clientSnapshot_t *f = &cl->frames[p.ackMessage & PACKET_MASK];
			if ( f->messageAcked == -1 ) {
				// the round trip: from the snapshot's send to this packet's arrival, on the
				// clock messageSent uses (wall or svs.time per sv_pingFix)
				f->messageAcked = f->messageSent + ( p.arriveMs - p.ackServerTime );
			}
			if ( p.ackReliable > cl->reliableAcknowledge ) {
				cl->reliableAcknowledge = p.ackReliable;
			}
		}
	}
}

// After each STEP's SV_Frame (lockstep.cpp): every agent's client frame and arrivals.
void JKBot_NetStep( void ) {
	const int now = sv.time + sv.timeResidual;
	for ( int i = 0; i < sv_maxclients->integer && i < MAX_CLIENTS; i++ ) {
		jkbLink_t *l = &links[i];
		if ( !l->active || !JKBot_IsAgent( i ) ) {
			continue;
		}
		client_t *cl = &svs.clients[i];
		RecordSnapshots( i, l, cl );
		ReceiveSnapshots( i, l, now );
		ClientFrame( i, l, now );
		DeliverPackets( i, l, cl, now );
	}
}

static void JKBot_AgentNet_f( void ) {
	if ( Cmd_Argc() < 4 ) {
		Com_Printf( "usage: jkbot_agent_net <client> <ping_up> <ping_down> [maxpackets] [packetdup]\n" );
		return;
	}
	int n = atoi( Cmd_Argv( 1 ) );
	if ( !JKBot_IsAgent( n ) ) {
		Com_Printf( "jkbot_agent_net: %d isn't an agent client\n", n );
		return;
	}
	JKBot_NetReset( n, atoi( Cmd_Argv( 2 ) ), atoi( Cmd_Argv( 3 ) ),
		Cmd_Argc() > 4 ? atoi( Cmd_Argv( 4 ) ) : 100, Cmd_Argc() > 5 ? atoi( Cmd_Argv( 5 ) ) : 1 );
	Com_Printf( "jkbot_agent_net %d\n", n );
}

static void JKBot_NetLog_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "usage: jkbot_netlog <path> | stop\n" );
		return;
	}
	if ( netlog ) {
		fclose( netlog );
		netlog = NULL;
	}
	if ( !Q_stricmp( Cmd_Argv( 1 ), "stop" ) ) {
		Com_Printf( "jkbot_netlog stopped\n" );
		return;
	}
	netlog = fopen( Cmd_Argv( 1 ), "w" );
	Com_Printf( netlog ? "jkbot_netlog started\n" : "jkbot_netlog: can't open the file\n" );
}

void JKBot_NetInit( void ) {
	Cmd_AddCommand( "jkbot_agent_net", JKBot_AgentNet_f, "JKBot: set an agent's link (agent builds only)" );
	Cmd_AddCommand( "jkbot_netlog", JKBot_NetLog_f, "JKBot: log agents' packets and snapshots (agent builds only)" );
}

#endif // JKBOT_AGENT
