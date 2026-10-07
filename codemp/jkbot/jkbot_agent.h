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

#endif // JKBOT_AGENT
