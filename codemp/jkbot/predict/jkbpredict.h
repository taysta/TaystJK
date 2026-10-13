/*
 * JKBot own-state prediction library (simulator only, P1-ENG-11). See README.md in codemp/jkbot.
 *
 * libjkbpredict is the client's movement prediction, built from the cgame's bg_* sources exactly
 * as the TaystJK cgame compiles them (_CGAME), plus a little glue (jkbpredict.c) that stands in
 * for the rest of the cgame: cg/cgs/cg_entities, the trap imports, CG_Trace and the per-command
 * part of CG_PredictPlayerState. The agent server (predict.cpp) loads it with RTLD_LOCAL and
 * talks to it only through this header, so none of its symbols (Pmove, pm, bgAllAnims...) can
 * bind to or from the game module's, and the game's mechanics are untouched.
 *
 * Both sides include q_shared.h from the same tree; Init checks the shared struct sizes.
 */
#pragma once

#ifdef JKBOT_AGENT

#define JKBP_API_VERSION 1
#define JKBP_GETAPI "JKBP_GetAPI"

typedef struct jkbpHost_s {
	int version;
	int sizeofPlayerState, sizeofEntityState, sizeofUsercmd, sizeofTrace;
	void ( *Print )( const char *msg );
	void ( *Error )( const char *msg );  // doesn't return
	int ( *Milliseconds )( void );
	void ( *SnapVector )( float *v );  // the engine's, as the client's trap->SnapVector
	int ( *FS_Open )( const char *qpath, fileHandle_t *f, fsMode_t mode );
	int ( *FS_Read )( void *buffer, int len, fileHandle_t f );
	void ( *FS_Close )( fileHandle_t f );
	int ( *FS_GetFileList )( const char *path, const char *extension, char *listbuf, int bufsize );
	clipHandle_t ( *CM_InlineModel )( int index );
	clipHandle_t ( *CM_TempModel )( const vec3_t mins, const vec3_t maxs, int capsule );
	int ( *CM_PointContents )( const vec3_t p, clipHandle_t model );
	int ( *CM_TransformedPointContents )( const vec3_t p, clipHandle_t model, const vec3_t origin, const vec3_t angles );
	void ( *CM_Trace )( trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, int capsule );
	void ( *CM_TransformedTrace )( trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, const vec3_t origin, const vec3_t angles, int capsule );
	const char *( *ConfigString )( int index );  // the server's, as the client received it
} jkbpHost_t;

typedef struct jkbpAPI_s {
	// Loads the humanoid animations and the saber definitions (the cgame's CG_Init part).
	qboolean ( *Init )( const jkbpHost_t *host );
	// CG_ParseServerinfo's movement-relevant part, from CS_SERVERINFO and CS_SYSTEMINFO.
	void ( *SetServerInfo )( void );
	// A predicting client: its sabers (cgs.clientinfo[].saber, as CG_NewClientInfo parses them).
	void ( *SetClient )( int clientNum, const char *saber1, const char *saber2 );
	// The snapshot the client holds (cg.snap): its playerState and entities.
	void ( *SetSnapshot )( int serverTime, const playerState_t *ps, const entityState_t *ents, int numEnts );
	// CG_PredictPlayerState from that snapshot over the client's usercmds, oldest first: commands
	// at or before ps.commandTime are skipped. *out is the predicted playerState; returns the
	// number of commands run.
	int ( *Predict )( const usercmd_t *cmds, int numCmds, playerState_t *out );
} jkbpAPI_t;

typedef const jkbpAPI_t *( *jkbpGetAPI_t )( int version );

#endif // JKBOT_AGENT
