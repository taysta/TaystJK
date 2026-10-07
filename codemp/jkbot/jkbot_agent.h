/*
 * JKBot agent and bridge endpoint (simulator only). See README.md in this directory.
 */
#pragma once

#ifdef JKBOT_AGENT

void JKBot_Init( void );
void JKBot_Shutdown( void );
void JKBot_GameFrame( void );  // after each GVM_RunFrame in SV_Frame

#endif // JKBOT_AGENT
