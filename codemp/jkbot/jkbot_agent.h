/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#pragma once

#ifdef JKBOT_AGENT

void JKBot_Init( void );
void JKBot_Shutdown( void );
void JKBot_GameFrame( int gameTime );  // after each GVM_RunFrame in SV_Frame

// lockstep.cpp
#define JKB_USERCMD_MSEC 8  // one usercmd period: the 125 fps client (environment.md §2)
int JKBot_StepMsec( void );  // the STEP period: jkbot_step_msec (default JKB_USERCMD_MSEC)
void JKBot_LockstepInit( void );
qboolean JKBot_Lockstep( void );  // jkbot_lockstep is on
qboolean JKBot_Stepping( void );  // inside a STEP's SV_Frame
void JKBot_Step( int n );
int JKBot_Steps( void );
int JKBot_VirtualMsec( void );

// export.cpp
struct jkb_agent_obs_s;
void JKBot_ExportInit( void );
uint64_t JKBot_XXH64( const void *data, size_t len, uint64_t seed );
void JKBot_HashFrame( int gameTime );  // after each game frame
uint64_t JKBot_FrameHash( void );  // of the latest game frame
qboolean JKBot_ExportSnapshot( int clientNum, struct jkb_agent_obs_s *out, int *messageNum );
void JKBot_ExportPS( const playerState_t *ps, uint32_t *out );  // RawFrame order, wire encoding
void JKBot_ExportStep( void );  // after each STEP
int JKBot_RandomSeed( int fallback );  // jkbot_seed if set

// agent.cpp
void JKBot_AgentInit( void );
qboolean JKBot_IsAgent( int clientNum );
void JKBot_AgentsThink( void );  // after each STEP's SV_Frame
int JKBot_AddAgent( const char *name, const char *model, const char *saber1, const char *saber2 );
void JKBot_AgentForget( int clientNum );
usercmd_t *JKBot_AgentCmd( int clientNum );  // the agent's held usercmd
void JKBot_AgentCmdConsumed( int clientNum );  // a client frame took it

// bridge.cpp
void JKBot_BridgeService( void );  // from SV_Frame while lockstep is idle

// reset.cpp
struct jkb_reset_s;
void JKBot_ResetInit( void );
qboolean JKBot_Reset( const struct jkb_reset_s *r, int *agentClients, int *botClient );
void JKBot_BotUsercmd( int clientNum, usercmd_t *cmd );  // stock bots' usercmds (scripted chat)
int JKBot_EpisodeIndex( void );
int JKBot_RoundStart( void );

// calllog.cpp
void JKBot_CallLogInit( void );
void JKBot_CallLogEnter( char kind, int a, int b );  // 'F' level time / 'T' client, cmd time
void JKBot_CallLogLeave( char kind );  // 'f' / 't'
void JKBot_CallLogSyscall( const intptr_t *args );  // from SV_GameSystemCalls
void JKBot_CallLogBolt( int modelIndex, int boltIndex, const float *matrix, const float *angles, const float *pos );  // after G_G2_GETBOLT

// netsched.cpp
void JKBot_NetInit( void );
void JKBot_NetReset( int clientNum, int pingUp, int pingDown, int maxPackets, int packetDup );
void JKBot_NetDrop( int clientNum );
void JKBot_NetStep( void );
int JKBot_NetClientTime( int clientNum );  // cl.serverTime; 0 before the first snapshot
int JKBot_NetHeld( int clientNum, int *serverTime );  // the snapshot the agent holds, -1 none
void JKBot_NetLogClientPacket( int clientNum, int cmdCount, int newCount, int firstNew, int last );  // real clients
void JKBot_NetLogClientSnapshot( int clientNum, int messageNum );  // real clients
int JKBot_NetRecentCmds( int clientNum, usercmd_t *out, int max );  // oldest first

// predict.cpp
void JKBot_PredictInit( void );
void JKBot_PredictAgent( int clientNum, int cmdNum );  // after the client frame that made cmdNum
void JKBot_PredictAuthoritative( int clientNum, int cmdNum );  // after the server ran cmdNum
qboolean JKBot_Predicted( int clientNum, playerState_t *out );
void JKBot_PredictForget( int clientNum );

// visibility.cpp
void JKBot_VisInit( void );
void JKBot_VisAgent( int clientNum );  // after the agent's client frame and prediction
int JKBot_Sees( int clientNum, int target );  // 1, 0, or -1 without a view yet
qboolean JKBot_View( int clientNum, vec3_t origin, vec3_t angles );  // the agent's camera
void JKBot_VisForget( int clientNum );

// geometry.cpp
// Throughput timers (bench.cpp, P1-BEN-01/02)
void JKBot_BenchInit( void );
int64_t JKBot_BenchNow( void );  // CLOCK_MONOTONIC, ns
void JKBot_BenchStep( int64_t start );  // after each STEP
void JKBot_BenchGameFrame( void );  // after each game frame
void JKBot_BenchReport( void );
struct refexport_s *JKBot_BenchWrapRef( struct refexport_s *ref );  // the table re points at

void JKBot_GeometryInit( void );
void JKBot_RaysAgent( int clientNum );  // after the agent's client frame and prediction
int JKBot_Rays( int clientNum, float *out );  // the latest rays (JKB_MAX_RAYS), count or 0
void JKBot_RaysForget( int clientNum );

#endif // JKBOT_AGENT
