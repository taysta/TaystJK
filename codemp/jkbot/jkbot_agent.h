/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#pragma once

#ifdef JKBOT_AGENT

void JKBot_Init( void );
void JKBot_Shutdown( void );
void JKBot_GameFrame( int gameTime );  // after each GVM_RunFrame in SV_Frame

// lockstep.cpp
#define JKB_USERCMD_MSEC 7  // one usercmd period: the 142 fps client (environment.md §2)
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
void JKBot_ExportStep( void );  // after each STEP
int JKBot_RandomSeed( int fallback );  // jkbot_seed if set

// agent.cpp
void JKBot_AgentInit( void );
qboolean JKBot_IsAgent( int clientNum );
void JKBot_AgentsThink( void );  // after each STEP's SV_Frame

#endif // JKBOT_AGENT
