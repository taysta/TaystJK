/*
 * Client self-test (JKBot P2-CL-01). Reports only: no input endpoint, so it may ship in release
 * builds (see README.md).
 *
 * With `+set jkbot_selftest 1`, at the end of Com_Init (renderer, sound and UI are up) the client
 * checks that the stock assets load from fs_basepath, prints one line per check, then quits:
 * "selftest ok" and exit status 0, or "selftest failed: <checks>" and exit status 1.
 */

#include "client/client.h"
#include "client/snd_public.h"

static const char *stockPaks[] = { "assets0", "assets1", "assets2", "assets3" };

// One stock file from each of the two big pk3s: the v1 map (assets0) and the bot's model (assets1).
static const char *stockFiles[] = { "maps/mp/duel1.bsp", "models/players/kyle/model.glm" };

static int checks, failures;

static void Check( qboolean ok, const char *what ) {
	Com_Printf( "selftest: %s %s\n", ok ? "ok  " : "FAIL", what );
	checks++;
	if ( !ok ) {
		failures++;
	}
}

static qboolean PakLoaded( const char *basename ) {
	const char *names = FS_LoadedPakNames();
	const size_t n = strlen( basename );
	for ( const char *p = names; ( p = strstr( p, basename ) ) != NULL; p += n ) {
		if ( ( p == names || p[-1] == ' ' ) && ( p[n] == ' ' || p[n] == '\0' ) ) {
			return qtrue;
		}
	}
	return qfalse;
}

void CL_SelfTest( void ) {
	if ( !Cvar_VariableIntegerValue( "jkbot_selftest" ) ) {
		return;
	}
	checks = failures = 0;
	Com_Printf( "selftest: fs_basepath %s\n", Cvar_VariableString( "fs_basepath" ) );

	for ( size_t i = 0; i < ARRAY_LEN( stockPaks ); i++ ) {
		Check( PakLoaded( stockPaks[i] ), va( "pak %s.pk3 loaded", stockPaks[i] ) );
	}
	for ( size_t i = 0; i < ARRAY_LEN( stockFiles ); i++ ) {
		const long len = FS_ReadFile( stockFiles[i], NULL );
		Check( (qboolean)( len > 0 ), va( "file %s (%ld bytes)", stockFiles[i], len ) );
	}

	Check( cls.rendererStarted, "renderer started" );
	Check( (qboolean)( cls.rendererStarted && re->RegisterModel( "models/players/kyle/model.glm" ) ),
		"renderer registers models/players/kyle/model.glm" );
	Check( (qboolean)( cls.rendererStarted && re->RegisterShaderNoMip( "gfx/hud/ammo_tic_1" ) ),
		"renderer registers gfx/hud/ammo_tic_1" );
	Check( cls.soundStarted, "sound started" );
	Check( (qboolean)( cls.soundStarted && S_RegisterSound( "sound/weapons/saber/saberon.wav" ) ),
		"sound registers sound/weapons/saber/saberon (mp3)" );
	Check( cls.uiStarted, "ui module started" );

	if ( failures ) {
		Com_Printf( "selftest failed: %d of %d checks\n", failures, checks );
		CL_Shutdown();
		Com_Shutdown();
		FS_Shutdown( qtrue );
		exit( 1 );
	}
	Com_Printf( "selftest ok\n" );
	Com_Quit_f();
}
