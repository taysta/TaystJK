/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2005 - 2015, ioquake3 contributors
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
#include "qcommon/stringed_ingame.h"
#include "qcommon/game_version.h"
#include "server/sv_gameapi.h"
#include "server/sv_dynbsp.h"
#include "server/sv_dimension.h"
#include "qcommon/cm_public.h"

#include <sstream>
#include <ctime>

#ifdef DEDICATED
extern std::vector<std::unique_ptr<bufferedMessageContainer_t>> demoPreRecordBuffer[MAX_CLIENTS];
extern std::map<std::string, std::string> demoMetaData[MAX_CLIENTS];
#endif

/*
===============================================================================

OPERATOR CONSOLE ONLY COMMANDS

These commands can only be entered from stdin or by a remote operator datagram
===============================================================================
*/

const char *SV_GetStringEdString(char *refSection, char *refName)
{
	//Well, it would've been lovely doing it the above way, but it would mean mixing
	//languages for the client depending on what the server is. So we'll mark this as
	//a stringed reference with @@@ and send the refname to the client, and when it goes
	//to print it will get scanned for the stringed reference indication and dealt with
	//properly.
	static char text[1024]={0};
	Com_sprintf(text, sizeof(text), "@@@%s", refName);
	return text;
}

/*
==================
SV_GetPlayerByHandle

Returns the player with player id or name from Cmd_Argv(1)
==================
*/
static client_t *SV_GetPlayerByHandle( void ) {
	client_t	*cl;
	int			i;
	char		*s;
	char		cleanName[64];

	// make sure server is running
	if ( !com_sv_running->integer ) {
		return NULL;
	}

	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "No player specified.\n" );
		return NULL;
	}

	s = Cmd_Argv(1);

	// Check whether this is a numeric player handle
	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++);

	if(!s[i])
	{
		int plid = atoi(s);

		// Check for numeric playerid match
		if(plid >= 0 && plid < sv_maxclients->integer)
		{
			cl = &svs.clients[plid];

			if(cl->state)
				return cl;
		}
	}

	// check for a name match
	for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++ ) {
		if ( !cl->state ) {
			continue;
		}
		if ( !Q_stricmp( cl->name, s ) ) {
			return cl;
		}

		Q_strncpyz( cleanName, cl->name, sizeof(cleanName) );
		Q_StripColor( cleanName );
		//Q_CleanStr( cleanName );
		if ( !Q_stricmp( cleanName, s ) ) {
			return cl;
		}
	}

	Com_Printf( "Player %s is not on the server\n", s );

	return NULL;
}

/*
==================
SV_GetPlayerByNum

Returns the player with idnum from Cmd_Argv(1)
==================
*/
static client_t *SV_GetPlayerByNum( void ) {
	client_t	*cl;
	int			i;
	int			idnum;
	char		*s;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		return NULL;
	}

	if ( Cmd_Argc() < 2 ) {
		Com_Printf( "No player specified.\n" );
		return NULL;
	}

	s = Cmd_Argv(1);

	for (i = 0; s[i]; i++) {
		if (s[i] < '0' || s[i] > '9') {
			Com_Printf( "Bad slot number: %s\n", s);
			return NULL;
		}
	}
	idnum = atoi( s );
	if ( idnum < 0 || idnum >= sv_maxclients->integer ) {
		Com_Printf( "Bad client slot: %i\n", idnum );
		return NULL;
	}

	cl = &svs.clients[idnum];
	if ( !cl->state ) {
		Com_Printf( "Client %i is not active\n", idnum );
		return NULL;
	}
	return cl;
}

//=========================================================

/*
==================
SV_Map_f

Restart the server on a different map
==================
*/
static void SV_Map_f( void ) {
	char		*cmd = NULL, *map = NULL;
	qboolean	killBots=qfalse, cheat=qfalse;
	char		expanded[MAX_QPATH] = {0}, mapname[MAX_QPATH] = {0};

	map = Cmd_Argv(1);
	if ( !map )
		return;

	// make sure the level exists before trying to change, so that
	// a typo at the server console won't end the game
	if (strchr (map, '\\') ) {
		Com_Printf ("Can't have mapnames with a \\\n");
		return;
	}

	Com_sprintf (expanded, sizeof(expanded), "maps/%s.bsp", map);
	if ( FS_ReadFile (expanded, NULL) == -1 ) {
		Com_Printf ("Can't find map %s\n", expanded);
		return;
	}

#ifndef DEDICATED
	Cvar_Set("sv_pure", "0");
#endif

	// force latched values to get set
	Cvar_Get ("g_gametype", "0", CVAR_SERVERINFO | CVAR_LATCH );

	cmd = Cmd_Argv(0);
	if ( !Q_stricmpn( cmd, "devmap", 6 ) ) {
		cheat = qtrue;
		killBots = qtrue;
	} else {
		cheat = qfalse;
		killBots = qfalse;
	}

	// save the map name here cause on a map restart we reload the jampconfig.cfg
	// and thus nuke the arguments of the map command
	Q_strncpyz(mapname, map, sizeof(mapname));

	ForceReload_e eForceReload = eForceReload_NOTHING;	// default for normal load

//	if ( !Q_stricmp( cmd, "devmapbsp") ) {	// not relevant in MP codebase
//		eForceReload = eForceReload_BSP;
//	}
//	else
	if ( !Q_stricmp( cmd, "devmapmdl") ) {
		eForceReload = eForceReload_MODELS;
	}
	else
	if ( !Q_stricmp( cmd, "devmapall") ) {
		eForceReload = eForceReload_ALL;
	}

	// start up the map
	SV_SpawnServer( mapname, killBots, eForceReload );

	// set the cheat value
	// if the level was started with "map <levelname>", then
	// cheats will not be allowed.  If started with "devmap <levelname>"
	// then cheats will be allowed
	Cvar_Set( "sv_cheats", cheat ? "1" : "0" );
}


/*
================
SV_MapRestart_f

Completely restarts a level, but doesn't send a new gamestate to the clients.
This allows fair starts with variable load times.
================
*/
static void SV_MapRestart_f( void ) {
	int			i;
	client_t	*client;
	char		*denied;
	qboolean	isBot;
	int			delay;

	// make sure we aren't restarting twice in the same frame
	if ( com_frameTime == sv.serverId ) {
		return;
	}

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( sv.restartTime ) {
		return;
	}

	if (Cmd_Argc() > 1 ) {
		delay = atoi( Cmd_Argv(1) );
	}
	else {
		delay = 5;
	}
	if( delay ) {
		sv.restartTime = sv.time + delay * 1000;
		SV_SetConfigstring( CS_WARMUP, va("%i", sv.restartTime) );
		return;
	}

	// check for changes in variables that can't just be restarted
	// check for maxclients change
	if ( sv_maxclients->modified || sv_gametype->modified ) { // why does it do this? especially for maxclients.. seems useless?
		char	mapname[MAX_QPATH];

		Com_Printf( "variable change -- restarting.\n" );
		// restart the map the slow way
		Q_strncpyz( mapname, Cvar_VariableString( "mapname" ), sizeof( mapname ) );

		SV_SpawnServer( mapname, qfalse, eForceReload_NOTHING );
		return;
	}

#ifdef DEDICATED
	SV_StopAutoRecordDemos();
	SV_ClearAllDemoPreRecord();
#endif

	// toggle the server bit so clients can detect that a
	// map_restart has happened
	svs.snapFlagServerBit ^= SNAPFLAG_SERVERCOUNT;

	// generate a new serverid
	// TTimo - don't update restartedserverId there, otherwise we won't deal correctly with multiple map_restart
	sv.serverId = com_frameTime;
	Cvar_Set( "sv_serverid", va("%i", sv.serverId ) );

	time( &sv.realMapTimeStarted );
	sv.demosPruned = qfalse;

	// if a map_restart occurs while a client is changing maps, we need
	// to give them the correct time so that when they finish loading
	// they don't violate the backwards time check in cl_cgame.c
	for (i=0 ; i<sv_maxclients->integer ; i++) {
		if (svs.clients[i].state == CS_PRIMED) {
			svs.clients[i].oldServerTime = sv.restartTime;
		}
	}

	// reset all the vm data in place without changing memory allocation
	// note that we do NOT set sv.state = SS_LOADING, so configstrings that
	// had been changed from their default values will generate broadcast updates
	sv.state = SS_LOADING;
	sv.restarting = qtrue;

	SV_RestartGame();

	// run a few frames to allow everything to settle
	for ( i = 0 ;i < 3 ; i++ ) {
		GVM_RunFrame( sv.time );
		sv.time += 100;
		svs.time += 100;
	}

	sv.state = SS_GAME;
	sv.restarting = qfalse;

	// connect and begin all the clients
	for (i=0 ; i<sv_maxclients->integer ; i++) {
		client = &svs.clients[i];

		// send the new gamestate to all connected clients
		if ( client->state < CS_CONNECTED) {
			continue;
		}

		if ( client->netchan.remoteAddress.type == NA_BOT ) {
			isBot = qtrue;
		} else {
			isBot = qfalse;
		}

		// add the map_restart command
		SV_AddServerCommand( client, "map_restart\n" );

		// connect the client again, without the firstTime flag
		denied = GVM_ClientConnect( i, qfalse, isBot );
		if ( denied ) {
			// this generally shouldn't happen, because the client
			// was connected before the level change
			SV_DropClient( client, denied );
			Com_Printf( "SV_MapRestart_f(%d): dropped client %i - denied!\n", delay, i );
			continue;
		}

		if(client->state == CS_ACTIVE)
			SV_ClientEnterWorld(client, &client->lastUsercmd);
		else
		{
			// If we don't reset client->lastUsercmd and are restarting during map load,
			// the client will hang because we'll use the last Usercmd from the previous map,
			// which is wrong obviously.
			SV_ClientEnterWorld(client, NULL);
		}
	}

	// run another frame to allow things to look at all the players
	GVM_RunFrame( sv.time );
	sv.time += 100;
	svs.time += 100;

#ifdef DEDICATED
	SV_BeginAutoRecordDemos();
#endif
}

//===============================================================

/*
==================
SV_KickBlankPlayers
==================
*/
static void SV_KickBlankPlayers( void ) {
	client_t	*cl;
	int			i;
	char		cleanName[64];

	// make sure server is running
	if ( !com_sv_running->integer ) {
		return;
	}

	// check for a name match
	for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++ ) {
		if ( !cl->state ) {
			continue;
		}
		if( cl->netchan.remoteAddress.type == NA_LOOPBACK ) {
			continue;
		}
		if ( !Q_stricmp( cl->name, "" ) ) {
			SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
			cl->lastPacketTime = svs.time;	// in case there is a funny zombie
			continue;
		}

		Q_strncpyz( cleanName, cl->name, sizeof(cleanName) );
		Q_StripColor( cleanName );
		//Q_CleanStr( cleanName );
		if ( !Q_stricmp( cleanName, "" ) ) {
			SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
			cl->lastPacketTime = svs.time;	// in case there is a funny zombie
		}
	}
}

/*
==================
SV_Kick_f

Kick a user off of the server
==================
*/
static void SV_Kick_f( void ) {
	client_t	*cl;
	int			i;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 ) {
		Com_Printf ("Usage: kick <player name>\nkick all = kick everyone\nkick allbots = kick all bots\n");
		return;
	}

	if (!Q_stricmp(Cmd_Argv(1), "Padawan"))
	{ //if you try to kick the default name, also try to kick ""
		SV_KickBlankPlayers();
	}

	cl = SV_GetPlayerByHandle();
	if ( !cl ) {
		if ( !Q_stricmp(Cmd_Argv(1), "all") ) {
			for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++ ) {
				if ( !cl->state ) {
					continue;
				}
				if( cl->netchan.remoteAddress.type == NA_LOOPBACK ) {
					continue;
				}
				SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
				cl->lastPacketTime = svs.time;	// in case there is a funny zombie
			}
		}
		else if ( !Q_stricmp(Cmd_Argv(1), "allbots") ) {
			for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++ ) {
				if ( !cl->state ) {
					continue;
				}
				if( cl->netchan.remoteAddress.type != NA_BOT ) {
					continue;
				}
				SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
				cl->lastPacketTime = svs.time;	// in case there is a funny zombie
			}
		}
		else if ( !Q_stricmp(Cmd_Argv(1), "allplayingbots") ) {
			for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++ ) {
				if ( !cl->state ) {
					continue;
				}
				if( cl->netchan.remoteAddress.type != NA_BOT ) {
					continue;
				}
				if (!Q_stricmp(cl->name, "RECORDER")) {
					continue;
				}
				SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
				cl->lastPacketTime = svs.time;	// in case there is a funny zombie
			}
		}
		return;
	}
	if( cl->netchan.remoteAddress.type == NA_LOOPBACK ) {
		Com_Printf("Cannot kick host player\n");
		return;
	}

	SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
	cl->lastPacketTime = svs.time;	// in case there is a funny zombie
}

/*
==================
SV_KickBots_f

Kick all bots off of the server
==================
*/
static void SV_KickBots_f( void ) {
	client_t	*cl;
	int			i;

	// make sure server is running
	if( !com_sv_running->integer ) {
		Com_Printf("Server is not running.\n");
		return;
	}

	for( i = 0, cl = svs.clients; i < sv_maxclients->integer; i++, cl++ ) {
		if( !cl->state ) {
			continue;
		}

		if( cl->netchan.remoteAddress.type != NA_BOT ) {
			continue;
		}

		SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
		cl->lastPacketTime = svs.time; // in case there is a funny zombie
	}
}
/*
==================
SV_KickAll_f

Kick all users off of the server
==================
*/
static void SV_KickAll_f( void ) {
	client_t *cl;
	int i;

	// make sure server is running
	if( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	for( i = 0, cl = svs.clients; i < sv_maxclients->integer; i++, cl++ ) {
		if( !cl->state ) {
			continue;
		}

		if( cl->netchan.remoteAddress.type == NA_LOOPBACK ) {
			continue;
		}

		SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
		cl->lastPacketTime = svs.time; // in case there is a funny zombie
	}
}

/*
==================
SV_KickNum_f

Kick a user off of the server
==================
*/
static void SV_KickNum_f( void ) {
	client_t	*cl;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 ) {
		Com_Printf ("Usage: %s <client number>\n", Cmd_Argv(0));
		return;
	}

	cl = SV_GetPlayerByNum();
	if ( !cl ) {
		return;
	}
	if( cl->netchan.remoteAddress.type == NA_LOOPBACK ) {
		Com_Printf("Cannot kick host player\n");
		return;
	}

	SV_DropClient( cl, SV_GetStringEdString("MP_SVGAME","WAS_KICKED"));	// "was kicked" );
	cl->lastPacketTime = svs.time;	// in case there is a funny zombie
}

/*
==================
SV_RehashBans_f

Load saved bans from file.
==================
*/
static void SV_RehashBans_f( void )
{
	int index, filelen;
	fileHandle_t readfrom;
	char *textbuf, *curpos, *maskpos, *newlinepos, *endpos;
	char filepath[MAX_QPATH];

	// make sure server is running
	if ( !com_sv_running->integer ) {
		return;
	}

	serverBansCount = 0;

	if ( !sv_banFile->string || !*sv_banFile->string )
		return;

	Com_sprintf( filepath, sizeof( filepath ), "%s/%s", FS_GetCurrentGameDir(), sv_banFile->string );

	if ( (filelen = FS_SV_FOpenFileRead( filepath, &readfrom )) >= 0 )
	{
		if ( filelen < 2 )
		{
			// Don't bother if file is too short.
			FS_FCloseFile( readfrom );
			return;
		}

		curpos = textbuf = (char *)Z_Malloc( filelen, TAG_TEMP_WORKSPACE );

		filelen = FS_Read( textbuf, filelen, readfrom );
		FS_FCloseFile( readfrom );

		endpos = textbuf + filelen;

		for ( index = 0; index < SERVER_MAXBANS && curpos + 2 < endpos; index++ )
		{
			// find the end of the address string
			for ( maskpos = curpos + 2; maskpos < endpos && *maskpos != ' '; maskpos++ );

			if ( maskpos + 1 >= endpos )
				break;

			*maskpos = '\0';
			maskpos++;

			// find the end of the subnet specifier
			for ( newlinepos = maskpos; newlinepos < endpos && *newlinepos != '\n'; newlinepos++ );

			if ( newlinepos >= endpos )
				break;

			*newlinepos = '\0';

			if ( NET_StringToAdr( curpos + 2, &serverBans[index].ip ) )
			{
				serverBans[index].isexception = (qboolean)(curpos[0] != '0');
				serverBans[index].subnet = atoi( maskpos );

				if ( serverBans[index].ip.type == NA_IP &&
					(serverBans[index].subnet < 1 || serverBans[index].subnet > 32) )
				{
					serverBans[index].subnet = 32;
				}
			}

			curpos = newlinepos + 1;
		}

		serverBansCount = index;

		Z_Free( textbuf );
	}
}

/*
==================
SV_WriteBans

Save bans to file.
==================
*/
static void SV_WriteBans( void )
{
	int index;
	fileHandle_t writeto;
	char filepath[MAX_QPATH];

	if ( !sv_banFile->string || !*sv_banFile->string )
		return;

	Com_sprintf( filepath, sizeof( filepath ), "%s/%s", FS_GetCurrentGameDir(), sv_banFile->string );

	if ( (writeto = FS_SV_FOpenFileWrite( filepath )) )
	{
		char writebuf[128];
		serverBan_t *curban;

		for ( index = 0; index < serverBansCount; index++ )
		{
			curban = &serverBans[index];

			Com_sprintf( writebuf, sizeof( writebuf ), "%d %s %d\n",
				curban->isexception, NET_AdrToString( &curban->ip ), curban->subnet );
			FS_Write( writebuf, strlen( writebuf ), writeto );
		}

		FS_FCloseFile( writeto );
	}
}

/*
==================
SV_DelBanEntryFromList

Remove a ban or an exception from the list.
==================
*/

static qboolean SV_DelBanEntryFromList( int index ) {
	if ( index == serverBansCount - 1 )
		serverBansCount--;
	else if ( index < (int)ARRAY_LEN( serverBans ) - 1 )
	{
		memmove( serverBans + index, serverBans + index + 1, (serverBansCount - index - 1) * sizeof( *serverBans ) );
		serverBansCount--;
	}
	else
		return qtrue;

	return qfalse;
}

/*
==================
SV_ParseCIDRNotation

Parse a CIDR notation type string and return a netadr_t and suffix by reference
==================
*/

static qboolean SV_ParseCIDRNotation( netadr_t *dest, int *mask, char *adrstr )
{
	char *suffix;

	suffix = strchr( adrstr, '/' );
	if ( suffix )
	{
		*suffix = '\0';
		suffix++;
	}

	if ( !NET_StringToAdr( adrstr, dest ) )
		return qtrue;

	if ( suffix )
	{
		*mask = atoi( suffix );

		if ( dest->type == NA_IP )
		{
			if ( *mask < 1 || *mask > 32 )
				*mask = 32;
		}
		else
			*mask = 32;
	}
	//else if ( dest->type == NA_IP )
	//	*mask = 32;
	else
		*mask = 32;

	return qfalse;
}

/*
==================
SV_AddBanToList

Ban a user from being able to play on this server based on his ip address.
==================
*/

static void SV_AddBanToList( qboolean isexception )
{
	char *banstring;
	char addy2[NET_ADDRSTRMAXLEN];
	netadr_t ip;
	int index, argc, mask;
	serverBan_t *curban;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	argc = Cmd_Argc();

	if ( argc < 2 || argc > 3 )
	{
		Com_Printf( "Usage: %s (ip[/subnet] | clientnum [subnet])\n", Cmd_Argv( 0 ) );
		return;
	}

	if ( serverBansCount >= (int)ARRAY_LEN( serverBans ) )
	{
		Com_Printf( "Error: Maximum number of bans/exceptions exceeded.\n" );
		return;
	}

	banstring = Cmd_Argv( 1 );

	if ( strchr( banstring, '.' ) /*|| strchr( banstring, ':' )*/ )
	{
		// This is an ip address, not a client num.

		if ( SV_ParseCIDRNotation( &ip, &mask, banstring ) )
		{
			Com_Printf( "Error: Invalid address %s\n", banstring );
			return;
		}
	}
	else
	{
		client_t *cl;

		// client num.

		cl = SV_GetPlayerByNum();

		if ( !cl )
		{
			Com_Printf( "Error: Playernum %s does not exist.\n", Cmd_Argv( 1 ) );
			return;
		}

		ip = cl->netchan.remoteAddress;

		if ( argc == 3 )
		{
			mask = atoi( Cmd_Argv( 2 ) );

			if ( ip.type == NA_IP )
			{
				if ( mask < 1 || mask > 32 )
					mask = 32;
			}
			else
				mask = 32;
		}
		else
			mask = 32;
	}

	if ( ip.type != NA_IP )
	{
		Com_Printf( "Error: Can ban players connected via the internet only.\n" );
		return;
	}

	// first check whether a conflicting ban exists that would supersede the new one.
	for ( index = 0; index < serverBansCount; index++ )
	{
		curban = &serverBans[index];

		if ( curban->subnet <= mask )
		{
			if ( (curban->isexception || !isexception) && NET_CompareBaseAdrMask( &curban->ip, &ip, curban->subnet ) )
			{
				Q_strncpyz( addy2, NET_AdrToString( &ip ), sizeof( addy2 ) );

				Com_Printf( "Error: %s %s/%d supersedes %s %s/%d\n", curban->isexception ? "Exception" : "Ban",
					NET_AdrToString( &curban->ip ), curban->subnet,
					isexception ? "exception" : "ban", addy2, mask );
				return;
			}
		}
		if ( curban->subnet >= mask )
		{
			if ( !curban->isexception && isexception && NET_CompareBaseAdrMask( &curban->ip, &ip, mask ) )
			{
				Q_strncpyz( addy2, NET_AdrToString( &curban->ip ), sizeof( addy2 ) );

				Com_Printf( "Error: %s %s/%d supersedes already existing %s %s/%d\n", isexception ? "Exception" : "Ban",
					NET_AdrToString( &ip ), mask,
					curban->isexception ? "exception" : "ban", addy2, curban->subnet );
				return;
			}
		}
	}

	// now delete bans that are superseded by the new one
	index = 0;
	while ( index < serverBansCount )
	{
		curban = &serverBans[index];

		if ( curban->subnet > mask && (!curban->isexception || isexception) && NET_CompareBaseAdrMask( &curban->ip, &ip, mask ) )
			SV_DelBanEntryFromList( index );
		else
			index++;
	}

	serverBans[serverBansCount].ip = ip;
	serverBans[serverBansCount].subnet = mask;
	serverBans[serverBansCount].isexception = isexception;

	serverBansCount++;

	SV_WriteBans();

	Com_Printf( "Added %s: %s/%d\n", isexception ? "ban exception" : "ban",
		NET_AdrToString( &ip ), mask );
}

/*
==================
SV_DelBanFromList

Remove a ban or an exception from the list.
==================
*/

static void SV_DelBanFromList( qboolean isexception )
{
	int index, count = 0, todel, mask;
	netadr_t ip;
	char *banstring;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 )
	{
		Com_Printf( "Usage: %s (ip[/subnet] | num)\n", Cmd_Argv( 0 ) );
		return;
	}

	banstring = Cmd_Argv( 1 );

	if ( strchr( banstring, '.' ) || strchr( banstring, ':' ) )
	{
		serverBan_t *curban;

		if ( SV_ParseCIDRNotation( &ip, &mask, banstring ) )
		{
			Com_Printf( "Error: Invalid address %s\n", banstring );
			return;
		}

		index = 0;

		while ( index < serverBansCount )
		{
			curban = &serverBans[index];

			if ( curban->isexception == isexception		&&
				curban->subnet >= mask 			&&
				NET_CompareBaseAdrMask( &curban->ip, &ip, mask ) )
			{
				Com_Printf( "Deleting %s %s/%d\n",
					isexception ? "exception" : "ban",
					NET_AdrToString( &curban->ip ), curban->subnet );

				SV_DelBanEntryFromList( index );
			}
			else
				index++;
		}
	}
	else
	{
		todel = atoi( Cmd_Argv( 1 ) );

		if ( todel < 1 || todel > serverBansCount )
		{
			Com_Printf( "Error: Invalid ban number given\n" );
			return;
		}

		for ( index = 0; index < serverBansCount; index++ )
		{
			if ( serverBans[index].isexception == isexception )
			{
				count++;

				if ( count == todel )
				{
					Com_Printf( "Deleting %s %s/%d\n",
						isexception ? "exception" : "ban",
						NET_AdrToString( &serverBans[index].ip ), serverBans[index].subnet );

					SV_DelBanEntryFromList( index );

					break;
				}
			}
		}
	}

	SV_WriteBans();
}


/*
==================
SV_ListBans_f

List all bans and exceptions on console
==================
*/

static void SV_ListBans_f( void )
{
	int index, count;
	serverBan_t *ban;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	// List all bans
	for ( index = count = 0; index < serverBansCount; index++ )
	{
		ban = &serverBans[index];
		if ( !ban->isexception )
		{
			count++;

			Com_Printf( "Ban #%d: %s/%d\n", count,
				NET_AdrToString( &ban->ip ), ban->subnet );
		}
	}
	// List all exceptions
	for ( index = count = 0; index < serverBansCount; index++ )
	{
		ban = &serverBans[index];
		if ( ban->isexception )
		{
			count++;

			Com_Printf( "Except #%d: %s/%d\n", count,
				NET_AdrToString( &ban->ip ), ban->subnet );
		}
	}
}

/*
==================
SV_FlushBans_f

Delete all bans and exceptions.
==================
*/

static void SV_FlushBans_f( void )
{
	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	serverBansCount = 0;

	// empty the ban file.
	SV_WriteBans();

	Com_Printf( "All bans and exceptions have been deleted.\n" );
}

static void SV_BanAddr_f( void )
{
	SV_AddBanToList( qfalse );
}

static void SV_ExceptAddr_f( void )
{
	SV_AddBanToList( qtrue );
}

static void SV_BanDel_f( void )
{
	SV_DelBanFromList( qfalse );
}

static void SV_ExceptDel_f( void )
{
	SV_DelBanFromList( qtrue );
}

static const char *SV_CalcUptime( void ) {
	static char buf[MAX_STRING_CHARS / 4] = { '\0' };
	char tmp[64] = { '\0' };
	time_t currTime;

	time( &currTime );

	int secs = difftime( currTime, svs.startTime );
	int mins = secs / 60;
	int hours = mins / 60;
	int days = hours / 24;

	secs %= 60;
	mins %= 60;
	hours %= 24;
	//days %= 365;

	buf[0] = '\0';
	if ( days > 0 ) {
		Com_sprintf( tmp, sizeof(tmp), "%i days ", days );
		Q_strcat( buf, sizeof(buf), tmp );
	}

	Com_sprintf( tmp, sizeof(tmp), "%ih%im%is", hours, mins, secs );
	Q_strcat( buf, sizeof(buf), tmp );

	return buf;
}

/*
================
SV_Status_f
================
*/
static void SV_Status_f( void )
{
	int				i, humans, bots;
	client_t		*cl;
	playerState_t	*ps;
	const char		*s;
	int				ping;
	char			state[32];

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	humans = bots = 0;
	for ( i = 0 ; i < sv_maxclients->integer ; i++ ) {
		if ( svs.clients[i].state >= CS_CONNECTED ) {
			if ( svs.clients[i].netchan.remoteAddress.type != NA_BOT ) {
				humans++;
			}
			else {
				bots++;
			}
		}
	}

#if defined(_WIN32)
#define STATUS_OS "Windows"
#elif defined(__linux__)
#define STATUS_OS "Linux"
#elif defined(MACOS_X)
#define STATUS_OS "OSX"
#else
#define STATUS_OS "Unknown"
#endif

	const char *ded_table[] = { "listen", "LAN dedicated", "public dedicated" };
	const char *gametypeNames[] = { "FFA", "Holocron", "Jedimaster", "Duel", "Powerduel", "Single", "Team", "Siege", "CTF", "CTY" };
	char hostname[MAX_HOSTNAMELENGTH] = { 0 };

	Q_strncpyz( hostname, sv_hostname->string, sizeof(hostname) );
	Q_StripColor( hostname );

	Com_Printf( "hostname: %s^7\n", hostname );
	Com_Printf( "server  : %s:%i, %s, %s\n", Cvar_VariableString("net_ip"), Cvar_VariableIntegerValue("net_port"), STATUS_OS, ded_table[com_dedicated->integer] );
	Com_Printf( "game    : %s %i, %s\n", VERSION_STRING_DOTTED, PROTOCOL_VERSION, FS_GetCurrentGameDir());
	Com_Printf( "map     : ^7%s^7, %s(%i)\n", sv_mapname->string, gametypeNames[sv_gametype->integer], sv_gametype->integer );//Do we need to validate sv_gametype is 0-9? don't think so
	Com_Printf( "players : %i %s, %i %s(%i max)\n", humans, (humans == 1 ? "human" : "humans"), bots, (bots == 1 ? "bot" : "bots"), sv_maxclients->integer - sv_privateClients->integer );
	Com_Printf( "uptime  : %s\n", SV_CalcUptime() );

	Com_Printf("cl score ping rate  address                name \n");
	Com_Printf("-- ----- ---- ----- ---------------------- ---------------\n");

	for (i=0,cl=svs.clients ; i < sv_maxclients->integer ; i++,cl++) {
		if ( !cl->state )
			continue;

		if ( cl->state == CS_CONNECTED )
			Q_strncpyz( state, "CON ", sizeof( state ) );
		else if ( cl->state == CS_ZOMBIE )
			Q_strncpyz( state, "ZMB ", sizeof( state ) );
		else {
			ping = cl->ping < 9999 ? cl->ping : 9999;
			Com_sprintf( state, sizeof(state), "%4i", ping );
		}

		ps = SV_GameClientNum( i );
		s = NET_AdrToString( &cl->netchan.remoteAddress );

		Com_Printf("%2i %5i %s %5i %22s %s^7\n", i, ps->persistant[PERS_SCORE], state, cl->rate, s, cl->name);//No need for truncation "feature" if we move name to end
	}
	Com_Printf ("\n");
}

char	*SV_ExpandNewlines( char *in );
#define SVSAY_PREFIX "Server^7\x19: "

/*
==================
SV_ConSay_f
==================
*/
static void SV_ConSay_f(void) {
	char	text[MAX_SAY_TEXT] = {0};

	if( !com_dedicated->integer ) {
		Com_Printf( "Server is not dedicated.\n" );
		return;
	}

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc () < 2 ) {
		return;
	}

	Cmd_ArgsBuffer( text, sizeof(text) );

	Com_Printf ("broadcast: chat \"" SVSAY_PREFIX "%s\\n\"\n", SV_ExpandNewlines((char *)text) );
	SV_SendServerCommand(NULL, "chat \"" SVSAY_PREFIX "%s\"\n", text);
}

static void SV_ResendGameState_f( void ) {
	int i;
	int count = 0;
	static cvar_t *sv_debugBSPInstances = NULL;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( !sv_debugBSPInstances ) {
		sv_debugBSPInstances = Cvar_Get( "sv_debugBSPInstances", "1", 0 );
	}

	for ( i = 0; i < sv_maxclients->integer; i++ ) {
		client_t *client = &svs.clients[i];
		clientState_t oldState;

		if ( client->state < CS_CONNECTED ) {
			continue;
		}
		if ( client->netchan.remoteAddress.type == NA_BOT ) {
			continue;
		}

		if ( sv_debugBSPInstances->integer ) {
			Com_Printf( "BSPDEBUG server force gamestate reload begin client=%i name='%s' state=%i serverId=%i gamestateMessageNum=%i lastClientCommand=%i\n",
				i, client->name, client->state, sv.serverId, client->gamestateMessageNum, client->lastClientCommand );
		}

		oldState = client->state;
		client->state = CS_CONNECTED;
		client->deltaMessage = -1;
		SV_SendClientGameState( client );
		if ( sv_debugBSPInstances->integer ) {
			Com_Printf( "BSPDEBUG server force gamestate reload sent client=%i name='%s' oldState=%i newState=%i gamestateMessageNum=%i netchanOutgoingSequence=%i\n",
				i, client->name, oldState, client->state, client->gamestateMessageNum, client->netchan.outgoingSequence );
		}
		count++;
	}

	Com_Printf( "Resent gamestate to %i client%s.\n", count, count == 1 ? "" : "s" );
}

static qboolean SV_ClientMapClassIsSpawn( const char *classname ) {
	return !Q_stricmp( classname, "info_player_deathmatch" )
		|| !Q_stricmp( classname, "info_player_start" )
		|| !Q_stricmp( classname, "info_player_duel" )
		|| !Q_stricmp( classname, "info_player_duel1" )
		|| !Q_stricmp( classname, "info_player_duel2" )
		|| !Q_stricmp( classname, "team_CTF_redplayer" )
		|| !Q_stricmp( classname, "team_CTF_blueplayer" ) ? qtrue : qfalse;
}

static int SV_ClientMapSpawnRank( const char *classname, int spawnflags ) {
	if ( !Q_stricmp( classname, "info_player_deathmatch" ) ) {
		return ( spawnflags & 1 ) ? 0 : 2;
	}
	if ( !Q_stricmp( classname, "info_player_start" ) ) {
		return ( spawnflags & 1 ) ? 1 : 3;
	}
	if ( !Q_stricmp( classname, "info_player_duel" ) ) {
		return 4;
	}
	if ( !Q_stricmp( classname, "info_player_duel1" ) || !Q_stricmp( classname, "info_player_duel2" ) ) {
		return 5;
	}
	if ( !Q_stricmp( classname, "team_CTF_redplayer" ) || !Q_stricmp( classname, "team_CTF_blueplayer" ) ) {
		return 6;
	}

	return 999;
}

static qboolean SV_ClientMapFindSpawn( int bspIndex, vec3_t origin, vec3_t angles ) {
	const char *data = bspIndex >= 0 ? CM_SubBSPEntityString( bspIndex ) : CM_EntityString();
	char classname[MAX_TOKEN_CHARS];
	vec3_t entOrigin;
	vec3_t entAngles;
	qboolean haveOrigin;
	int spawnflags;
	int bestRank = 999;
	int entityIndex = -1;
	int bestEntityIndex = -1;
	qboolean debug = SV_DynBSPDebugEnabled();

	VectorClear( origin );
	VectorClear( angles );

	if ( !data ) {
		if ( debug ) {
			Com_Printf( "BSPDEBUG clientMap spawn bsp=%i no entity string\n", bspIndex );
		}
		return qfalse;
	}

	while ( 1 ) {
		char *token = COM_Parse( &data );
		if ( !token[0] ) {
			break;
		}
		if ( token[0] != '{' ) {
			break;
		}
		entityIndex++;

		classname[0] = 0;
		VectorClear( entOrigin );
		VectorClear( entAngles );
		haveOrigin = qfalse;
		spawnflags = 0;

		while ( 1 ) {
			char key[MAX_TOKEN_CHARS];
			char value[MAX_TOKEN_CHARS];

			token = COM_Parse( &data );
			if ( !token[0] || token[0] == '}' ) {
				break;
			}
			Q_strncpyz( key, token, sizeof( key ) );

			token = COM_Parse( &data );
			if ( !token[0] ) {
				break;
			}
			Q_strncpyz( value, token, sizeof( value ) );

			if ( !Q_stricmp( key, "classname" ) ) {
				Q_strncpyz( classname, value, sizeof( classname ) );
			}
			else if ( !Q_stricmp( key, "origin" ) ) {
				if ( sscanf( value, "%f %f %f", &entOrigin[0], &entOrigin[1], &entOrigin[2] ) == 3 ) {
					haveOrigin = qtrue;
				}
			}
			else if ( !Q_stricmp( key, "angle" ) ) {
				entAngles[YAW] = atof( value );
			}
			else if ( !Q_stricmp( key, "angles" ) ) {
				sscanf( value, "%f %f %f", &entAngles[0], &entAngles[1], &entAngles[2] );
			}
			else if ( !Q_stricmp( key, "spawnflags" ) ) {
				spawnflags = atoi( value );
			}
		}

		if ( haveOrigin && SV_ClientMapClassIsSpawn( classname ) ) {
			int rank = SV_ClientMapSpawnRank( classname, spawnflags );
			if ( debug ) {
				Com_Printf( "BSPDEBUG clientMap spawn candidate bsp=%i ent=%i class='%s' rank=%i spawnflags=0x%x origin=(%.1f %.1f %.1f) angles=(%.1f %.1f %.1f)\n",
					bspIndex, entityIndex, classname, rank, spawnflags,
					entOrigin[0], entOrigin[1], entOrigin[2],
					entAngles[0], entAngles[1], entAngles[2] );
			}
			if ( rank < bestRank ) {
				bestRank = rank;
				bestEntityIndex = entityIndex;
				VectorCopy( entOrigin, origin );
				VectorCopy( entAngles, angles );
				if ( bestRank == 0 ) {
					break;
				}
			}
		}
	}

	if ( bestRank == 999 ) {
		if ( debug ) {
			Com_Printf( "BSPDEBUG clientMap spawn bsp=%i no usable spawn found\n", bspIndex );
		}
		return qfalse;
	}

	origin[2] += 9;
	if ( debug ) {
		Com_Printf( "BSPDEBUG clientMap spawn selected bsp=%i ent=%i rank=%i finalOrigin=(%.1f %.1f %.1f) angles=(%.1f %.1f %.1f)\n",
			bspIndex, bestEntityIndex, bestRank,
			origin[0], origin[1], origin[2],
			angles[0], angles[1], angles[2] );
	}
	return qtrue;
}

void SV_ClientMapMoveClientToSpawn( client_t *client, int bspIndex ) {
	vec3_t spawnOrigin;
	vec3_t spawnAngles;
	playerState_t *ps;
	qboolean debug = SV_DynBSPDebugEnabled();

	if ( !client || !client->gentity || !SV_ClientMapFindSpawn( bspIndex, spawnOrigin, spawnAngles ) ) {
		if ( debug ) {
			Com_Printf( "BSPDEBUG clientMap move failed client=%li bsp=%i hasClient=%i hasGentity=%i\n",
				client ? (long)( client - svs.clients ) : -1L, bspIndex,
				client ? 1 : 0, client && client->gentity ? 1 : 0 );
		}
		return;
	}

	ps = client->gentity->playerState;
	if ( debug ) {
		Com_Printf( "BSPDEBUG clientMap move begin client=%li name='%s' bsp=%i oldPs=(%.1f %.1f %.1f) oldEnt=(%.1f %.1f %.1f) spawn=(%.1f %.1f %.1f) angles=(%.1f %.1f %.1f)\n",
			(long)( client - svs.clients ), client->name, bspIndex,
			ps ? ps->origin[0] : 0.0f, ps ? ps->origin[1] : 0.0f, ps ? ps->origin[2] : 0.0f,
			client->gentity->r.currentOrigin[0], client->gentity->r.currentOrigin[1], client->gentity->r.currentOrigin[2],
			spawnOrigin[0], spawnOrigin[1], spawnOrigin[2],
			spawnAngles[0], spawnAngles[1], spawnAngles[2] );
	}
	if ( ps ) {
		VectorCopy( spawnOrigin, ps->origin );
		VectorCopy( spawnAngles, ps->viewangles );
		ps->delta_angles[0] = 0;
		ps->delta_angles[1] = 0;
		ps->delta_angles[2] = 0;
	}

	VectorCopy( spawnOrigin, client->gentity->s.origin );
	VectorCopy( spawnOrigin, client->gentity->r.currentOrigin );
	VectorCopy( spawnAngles, client->gentity->s.angles );
	VectorCopy( spawnAngles, client->gentity->r.currentAngles );
	SV_LinkEntity( client->gentity );
	if ( debug ) {
		Com_Printf( "BSPDEBUG clientMap move linked client=%li ps=(%.1f %.1f %.1f) ent=(%.1f %.1f %.1f) absmin=(%.1f %.1f %.1f) absmax=(%.1f %.1f %.1f) runtime=%i\n",
			(long)( client - svs.clients ),
			ps ? ps->origin[0] : 0.0f, ps ? ps->origin[1] : 0.0f, ps ? ps->origin[2] : 0.0f,
			client->gentity->r.currentOrigin[0], client->gentity->r.currentOrigin[1], client->gentity->r.currentOrigin[2],
			client->gentity->r.absmin[0], client->gentity->r.absmin[1], client->gentity->r.absmin[2],
			client->gentity->r.absmax[0], client->gentity->r.absmax[1], client->gentity->r.absmax[2],
			SV_RuntimeBSPInstanceForGentity( client->gentity ) );
	}
}

qboolean SV_SetClientMap( client_t *client, const char *mapName ) {
	char expanded[MAX_QPATH];
	int modelIndex;
	int bspIndex;
	qboolean sendGameState = qfalse;
	sharedEntity_t *holder = NULL;
	int totalStartTime = Sys_Milliseconds();
	int phaseStartTime;

	if ( !client || !mapName || !mapName[0] ) {
		return qfalse;
	}

	if ( !Q_stricmp( mapName, "clear" ) ) {
		if ( !client->runtimeMapName[0] ) {
			client->spectatorRuntimeMapName[0] = 0;
			return qtrue;
		}
		if ( client->gentity ) {
			SV_SetRuntimeBSPInstanceForGentity( client->gentity, -1 );
		}
		SV_ClientMapMoveClientToSpawn( client, -1 );
		SV_DynBSPClearClientMap( client );
		client->loadedBSPModelsGeneration = -1;
		client->sendBSPModelsGeneration = -1;
		sendGameState = qtrue;
	}
	else {
		if ( client->runtimeMapName[0] && !Q_stricmp( client->runtimeMapName, mapName ) ) {
			holder = SV_DynBSPInstanceForMap( mapName );
			if ( SV_DynBSPDebugEnabled() ) {
				Com_Printf( "BSPDEBUG clientMap set ignored same map client=%li name='%s' map='%s'\n",
					(long)( client - svs.clients ), client->name, mapName );
			}
			if ( client->gentity ) {
				SV_SetRuntimeBSPInstanceForGentity( client->gentity, holder ? SV_RuntimeBSPInstanceForGentity( holder ) : -1 );
			}
			SV_ClientMapMoveClientToSpawn( client, client->runtimeMapBSPIndex );
			return qtrue;
		}

		if ( strchr( mapName, '\\' ) || strchr( mapName, ';' ) || strstr( mapName, ".." ) ) {
			Com_Printf( "Invalid map name '%s'.\n", mapName );
			return qfalse;
		}

		Com_sprintf( expanded, sizeof( expanded ), "maps/%s.bsp", mapName );
		phaseStartTime = Sys_Milliseconds();
		if ( FS_ReadFile( expanded, NULL ) == -1 ) {
			Com_Printf( "Can't find map %s\n", expanded );
			return qfalse;
		}
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap FS_ReadFileCheck client=%li map='%s' path='%s' ms=%i total=%i\n",
				(long)( client - svs.clients ), mapName, expanded,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}

		phaseStartTime = Sys_Milliseconds();
		modelIndex = CM_LoadSubBSP( expanded, qfalse );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap CM_LoadSubBSP client=%li map='%s' model=%i ms=%i total=%i\n",
				(long)( client - svs.clients ), mapName, modelIndex,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}
		phaseStartTime = Sys_Milliseconds();
		bspIndex = CM_FindSubBSP( modelIndex );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap CM_FindSubBSP client=%li map='%s' bsp=%i ms=%i total=%i\n",
				(long)( client - svs.clients ), mapName, bspIndex,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}
		if ( bspIndex < 0 ) {
			Com_Printf( "Failed to load runtime client map collision for %s\n", expanded );
			return qfalse;
		}
		phaseStartTime = Sys_Milliseconds();
		holder = SV_DynBSPInstanceForMap( mapName );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap InstanceForMap client=%li map='%s' holder=%i ms=%i total=%i\n",
				(long)( client - svs.clients ), mapName, holder ? SV_NumForGentity( holder ) : -1,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPDEBUG clientMap set client=%li name='%s' map='%s' model=%i bsp=%i holder=%i holderOrigin=(%.1f %.1f %.1f)\n",
				(long)( client - svs.clients ), client->name, mapName, modelIndex, bspIndex,
				holder ? SV_NumForGentity( holder ) : -1,
				holder ? holder->r.currentOrigin[0] : 0.0f,
				holder ? holder->r.currentOrigin[1] : 0.0f,
				holder ? holder->r.currentOrigin[2] : 0.0f );
		}

		SV_DynBSPSetClientMap( client, mapName, bspIndex );
		if ( client->gentity ) {
			SV_SetRuntimeBSPInstanceForGentity( client->gentity, holder ? SV_RuntimeBSPInstanceForGentity( holder ) : -1 );
		}
		phaseStartTime = Sys_Milliseconds();
		SV_ClientMapMoveClientToSpawn( client, bspIndex );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap MoveClientToSpawn client=%li map='%s' bsp=%i ms=%i total=%i\n",
				(long)( client - svs.clients ), mapName, bspIndex,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}
		client->loadedBSPModelsGeneration = -1;
		client->sendBSPModelsGeneration = -1;
		sendGameState = qtrue;
	}

	if ( client->netchan.remoteAddress.type != NA_BOT && sendGameState ) {
		clientState_t oldState = client->state;
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPDEBUG clientMap transition begin client=%li name='%s' map='%s' state=%i serverId=%i runtimeServerId=%i outgoing=%i lastClientCommand=%i\n",
				(long)( client - svs.clients ), client->name,
				client->runtimeMapName[0] ? client->runtimeMapName : sv_mapname->string,
				client->state, sv.serverId, SV_DynBSPClientServerId( client ),
				client->netchan.outgoingSequence, client->lastClientCommand );
		}

		client->state = CS_CONNECTED;
		client->deltaMessage = -1;
		client->skipClientBeginForRuntimeMap = qtrue;
		client->reliableSequence = client->reliableAcknowledge;
		client->reliableSent = client->reliableSequence;
		phaseStartTime = Sys_Milliseconds();
		SV_SendClientGameState( client );
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPTIME server clientMap SendClientGameState client=%li map='%s' ms=%i total=%i\n",
				(long)( client - svs.clients ),
				client->runtimeMapName[0] ? client->runtimeMapName : sv_mapname->string,
				Sys_Milliseconds() - phaseStartTime, Sys_Milliseconds() - totalStartTime );
		}
		if ( SV_DynBSPDebugEnabled() ) {
			Com_Printf( "BSPDEBUG clientMap transition gamestate sent client=%li oldState=%i newState=%i outgoing=%i gamestateMessageNum=%i sendGen=%i currentGen=%i\n",
				(long)( client - svs.clients ), oldState, client->state,
				client->netchan.outgoingSequence, client->gamestateMessageNum,
				client->sendBSPModelsGeneration, sv.bspModelsGeneration );
		}
	}
	else if ( SV_DynBSPDebugEnabled() ) {
		Com_Printf( "BSPDEBUG clientMap transition no gamestate client=%li name='%s' map='%s' state=%i loadedGen=%i currentGen=%i bot=%i\n",
			(long)( client - svs.clients ), client->name,
			client->runtimeMapName[0] ? client->runtimeMapName : sv_mapname->string,
			client->state, client->loadedBSPModelsGeneration, sv.bspModelsGeneration,
			client->netchan.remoteAddress.type == NA_BOT );
	}

	if ( SV_DynBSPDebugEnabled() ) {
		Com_Printf( "BSPTIME server clientMap total client=%li map='%s' sendGameState=%i total=%i\n",
			(long)( client - svs.clients ),
			client->runtimeMapName[0] ? client->runtimeMapName : sv_mapname->string,
			sendGameState, Sys_Milliseconds() - totalStartTime );
	}

	return qtrue;
}

static void SV_ClientMap_f( void ) {
	client_t *client;
	clientState_t oldState;
	char mapName[MAX_QPATH];
	int clientNum;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( Cmd_Argc() != 3 ) {
		Com_Printf( "Usage: clientMap <clientNum> <map|clear>\n" );
		return;
	}

	client = SV_GetPlayerByNum();
	if ( !client ) {
		return;
	}

	clientNum = client - svs.clients;
	oldState = client->state;
	Q_strncpyz( mapName, Cmd_Argv( 2 ), sizeof( mapName ) );
	if ( Q_stricmp( mapName, "clear" ) ) {
		GVM_ClientRuntimeMapChanged( clientNum, mapName );
	}
	if ( !SV_SetClientMap( client, mapName ) ) {
		return;
	}
	if ( !Q_stricmp( mapName, "clear" ) ) {
		GVM_ClientRuntimeMapChanged( clientNum, mapName );
	}

	Com_Printf( "clientMap set client=%i name='%s' map='%s' bot=%i oldState=%i newState=%i serverId=%i\n",
		clientNum, client->name, client->runtimeMapName[0] ? client->runtimeMapName : sv_mapname->string,
		client->netchan.remoteAddress.type == NA_BOT, oldState, client->state, SV_DynBSPClientServerId( client ) );
}

static void SV_ClientBSPState_f( void ) {
	client_t *client;
	playerState_t *ps;
	client_t *targetClient = NULL;
	sharedEntity_t *holder = NULL;
	const char *targetMap = "";
	int clientNum;
	int targetNum = -1;
	qboolean forceSend = qfalse;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( Cmd_Argc() < 2 || Cmd_Argc() > 3 ) {
		Com_Printf( "Usage: clientBSPState <clientNum> [send]\n" );
		return;
	}

	client = SV_GetPlayerByNum();
	if ( !client ) {
		return;
	}

	clientNum = client - svs.clients;
	ps = SV_GameClientNum( clientNum );
	if ( ps && ( ps->pm_flags & PMF_FOLLOW ) && ps->clientNum >= 0 && ps->clientNum < sv_maxclients->integer ) {
		targetNum = ps->clientNum;
		targetClient = &svs.clients[targetNum];
		targetMap = targetClient->runtimeMapName;
		holder = SV_DynBSPInstanceForMap( targetMap );
	}

	Com_Printf( "clientBSPState client=%i name='%s' bot=%i state=%i pmType=%i runtimeMap='%s' spectatorMap='%s' loadedGen=%i sendGen=%i currentGen=%i follow=%i target=%i targetMap='%s' holder=%i holderModel=%i holderOrigin=(%.1f %.1f %.1f)\n",
		clientNum, client->name, client->netchan.remoteAddress.type == NA_BOT, client->state,
		ps ? ps->pm_type : -1,
		client->runtimeMapName, client->spectatorRuntimeMapName, client->loadedBSPModelsGeneration, client->sendBSPModelsGeneration, sv.bspModelsGeneration,
		ps && ( ps->pm_flags & PMF_FOLLOW ), targetNum, targetMap && targetMap[0] ? targetMap : "",
		holder ? holder->s.number : -1, holder ? holder->s.modelindex : -1,
		holder ? holder->r.currentOrigin[0] : 0.0f, holder ? holder->r.currentOrigin[1] : 0.0f, holder ? holder->r.currentOrigin[2] : 0.0f );

	forceSend = ( Cmd_Argc() == 3 && !Q_stricmp( Cmd_Argv( 2 ), "send" ) ) ? qtrue : qfalse;
	if ( forceSend ) {
		clientState_t oldState;

		if ( client->netchan.remoteAddress.type == NA_BOT ) {
			Com_Printf( "clientBSPState send does not support bots.\n" );
			return;
		}

		oldState = client->state;
		SV_DynBSPPrepareClientGameState( client );
		client->state = CS_CONNECTED;
		client->deltaMessage = -1;
		SV_SendClientGameState( client );
		Com_Printf( "clientBSPState sent BSP-model gamestate client=%i oldState=%i newState=%i sendGen=%i currentGen=%i\n",
			clientNum, oldState, client->state, client->sendBSPModelsGeneration, sv.bspModelsGeneration );
	}
}

static void SV_ClearBSPs_f( void ) {
	int i;
	int firstRuntimeBSPModelConfigstring;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( !GVM_ConsoleCommand() ) {
		Com_Printf( "Game did not handle clearBSPs.\n" );
	}

	firstRuntimeBSPModelConfigstring = sv.firstRuntimeBSPModelConfigstring;
	if ( firstRuntimeBSPModelConfigstring > 0 ) {
		for ( i = firstRuntimeBSPModelConfigstring; i < CS_BSP_MODELS + MAX_SUB_BSP; i++ ) {
			SV_SetConfigstring( i, "" );
		}
	}
	for ( i = 0; i < MAX_RUNTIME_BSP_INSTANCES; i++ ) {
		SV_SetConfigstring( CS_RUNTIME_BSP_META + i, "" );
	}

	sv.firstRuntimeBSPModelConfigstring = 0;
	sv.bspModelsGeneration++;

	for ( i = 0; i < sv_maxclients->integer; i++ ) {
		client_t *client = &svs.clients[i];

		if ( client->state < CS_CONNECTED ) {
			continue;
		}

		SV_DynBSPClearClientMap( client );
		client->spectatorRuntimeMapName[0] = 0;
		client->loadedBSPModelsGeneration = -1;
		client->sendBSPModelsGeneration = -1;
	}

	Com_Printf( "Cleared runtime BSP configstrings from %i and reset runtime BSP state for connected clients. generation=%i\n",
		firstRuntimeBSPModelConfigstring, sv.bspModelsGeneration );
}

static sharedEntity_t *SV_DimensionEntityForArg( int argIndex, const char *label ) {
	int entNum;

	if ( Cmd_Argc() <= argIndex ) {
		return NULL;
	}

	entNum = atoi( Cmd_Argv( argIndex ) );
	if ( entNum < 0 || entNum >= sv.num_entities ) {
		Com_Printf( "Invalid %s entity %i; valid range is 0-%i.\n", label, entNum, sv.num_entities - 1 );
		return NULL;
	}

	return SV_GentityNum( entNum );
}

static void SV_PrintWorldContext( const char *label, const svWorldContext_t *world ) {
	Com_Printf( "%s world=%i bsp=%i model=%i runtime=%i projected=%i origin=(%.1f %.1f %.1f)\n",
		label, world->worldId, world->bspIndex, world->bspModelIndex,
		world->runtimeBSPInstance, world->projected,
		world->origin[0], world->origin[1], world->origin[2] );
}

static void SV_PrintInteractionContext( const char *label, const svInteractionContext_t *interaction ) {
	Com_Printf( "%s group=%i owner=%i partner=%i team=%i flags=0x%x\n",
		label, interaction->groupId, interaction->ownerClientNum,
		interaction->partnerClientNum, interaction->team, interaction->flags );
}

static void SV_PrintDimensionEntity( const char *label, sharedEntity_t *ent ) {
	svWorldContext_t world;
	svInteractionContext_t interaction;
	int entNum = SV_NumForGentity( ent );

	Com_Printf( "%s entity=%i type=%i class='%s' linked=%i runtime=%i owner=%i solid=0x%x contents=0x%x\n",
		label, entNum, ent->s.eType, ent->classname ? ent->classname : "",
		ent->r.linked, SV_RuntimeBSPInstanceForGentity( ent ), ent->r.ownerNum, ent->s.solid, ent->r.contents );

	if ( SV_GetEntityWorldContext( ent, &world ) ) {
		SV_PrintWorldContext( "  entityWorld", &world );
	}
	if ( SV_GetEntityInteractionContext( ent, &interaction ) ) {
		SV_PrintInteractionContext( "  interaction", &interaction );
	}

	if ( entNum >= 0 && entNum < sv_maxclients->integer ) {
		client_t *client = &svs.clients[entNum];
		svWorldContext_t viewWorld;

		if ( SV_GetClientViewWorldContext( client, &viewWorld ) ) {
			SV_PrintWorldContext( "  clientView", &viewWorld );
		}
		Com_Printf( "  client state=%i name='%s' runtimeMap='%s' spectatorMap='%s' runtimeBSP=%i\n",
			client->state, client->name, client->runtimeMapName,
			client->spectatorRuntimeMapName, client->runtimeMapName[0] ? client->runtimeMapBSPIndex : -1 );
	}
}

static void SV_DimensionInfo_f( void ) {
	sharedEntity_t *ent;
	sharedEntity_t *target;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( Cmd_Argc() < 2 || Cmd_Argc() > 3 ) {
		Com_Printf( "Usage: dimensionInfo <entityNum> [targetEntityNum]\n" );
		return;
	}

	ent = SV_DimensionEntityForArg( 1, "source" );
	if ( !ent ) {
		return;
	}

	if ( !SV_DimensionIsolationEnabled() ) {
		Com_Printf( "note: sv_engineDimensions is 0; policy shown below is not being enforced.\n" );
	}

	SV_PrintDimensionEntity( "source", ent );

	if ( Cmd_Argc() != 3 ) {
		return;
	}

	target = SV_DimensionEntityForArg( 2, "target" );
	if ( !target ) {
		return;
	}

	SV_PrintDimensionEntity( "target", target );
	Com_Printf( "  canInteract trace=%i pointContents=%i snapshot=%i damage=%i event=%i sound=%i use=%i\n",
		SV_CanEntitiesInteract( ent, target, SVISO_TRACE ),
		SV_CanEntitiesInteract( ent, target, SVISO_POINT_CONTENTS ),
		SV_CanEntitiesInteract( ent, target, SVISO_SNAPSHOT ),
		SV_CanEntitiesInteract( ent, target, SVISO_DAMAGE ),
		SV_CanEntitiesInteract( ent, target, SVISO_EVENT ),
		SV_CanEntitiesInteract( ent, target, SVISO_SOUND ),
		SV_CanEntitiesInteract( ent, target, SVISO_USE ) );
}

static void SV_RuntimeBModelInfo_f( void ) {
	client_t *client;
	sharedEntity_t *holder;
	playerState_t *ps;
	int clientNum;
	int bspIndex;
	int modelBase;
	int runtimeBSPInstance;
	int printed = 0;
	int limit = 64;
	int e;

	if ( sv.state != SS_GAME ) {
		Com_Printf( "Server is not running a game.\n" );
		return;
	}

	if ( Cmd_Argc() < 2 || Cmd_Argc() > 3 ) {
		Com_Printf( "Usage: runtimeBModelInfo <clientNum> [limit]\n" );
		return;
	}

	client = SV_GetPlayerByNum();
	if ( !client ) {
		return;
	}

	clientNum = client - svs.clients;
	ps = SV_GameClientNum( clientNum );
	if ( Cmd_Argc() == 3 ) {
		limit = atoi( Cmd_Argv( 2 ) );
		if ( limit < 1 ) {
			limit = 1;
		}
	}

	bspIndex = SV_DynBSPClientBSPIndex( client );
	holder = client->runtimeMapName[0] ? SV_DynBSPInstanceForMap( client->runtimeMapName ) : NULL;
	runtimeBSPInstance = holder ? SV_RuntimeBSPInstanceForGentity( holder ) : -1;
	modelBase = bspIndex >= 0 ? CM_SubBSPModelIndex( bspIndex ) : -1;

	Com_Printf( "runtimeBModelInfo client=%i name='%s' runtimeMap='%s' bsp=%i modelBase=%i holder=%i holderModel=%i runtime=%i loadedGen=%i sendGen=%i currentGen=%i psOrigin=(%.1f %.1f %.1f)\n",
		clientNum, client->name, client->runtimeMapName,
		bspIndex, modelBase, holder ? holder->s.number : -1, holder ? holder->s.modelindex : -1,
		runtimeBSPInstance, client->loadedBSPModelsGeneration, client->sendBSPModelsGeneration, sv.bspModelsGeneration,
		ps ? ps->origin[0] : 0.0f, ps ? ps->origin[1] : 0.0f, ps ? ps->origin[2] : 0.0f );

	if ( runtimeBSPInstance < 0 ) {
		Com_Printf( "  client is not actively in a runtime map.\n" );
		return;
	}

	for ( e = 0; e < sv.num_entities && printed < limit; e++ ) {
		sharedEntity_t *ent = SV_GentityNum( e );
		svEntity_t *svEnt;
		int translatedModel = ent->s.modelindex;

		if ( !ent->r.linked || SV_RuntimeBSPInstanceForGentity( ent ) != runtimeBSPInstance || !ent->r.bmodel ) {
			continue;
		}

		svEnt = SV_SvEntityForGentity( ent );
		if ( modelBase >= 0 && translatedModel >= modelBase ) {
			translatedModel -= modelBase;
		}

		Com_Printf( "  ent=%i class='%s' type=%i linked=%i r.bmodel=%i solid=0x%x contents=0x%x model=%i translated=%i area=%i/%i clusters=%i lastCluster=%i origin=(%.1f %.1f %.1f) current=(%.1f %.1f %.1f) mins=(%.1f %.1f %.1f) maxs=(%.1f %.1f %.1f)\n",
			e, ent->classname ? ent->classname : "", ent->s.eType, ent->r.linked, ent->r.bmodel,
			ent->s.solid, ent->r.contents, ent->s.modelindex, translatedModel,
			svEnt->areanum, svEnt->areanum2, svEnt->numClusters, svEnt->lastCluster,
			ent->s.origin[0], ent->s.origin[1], ent->s.origin[2],
			ent->r.currentOrigin[0], ent->r.currentOrigin[1], ent->r.currentOrigin[2],
			ent->r.mins[0], ent->r.mins[1], ent->r.mins[2],
			ent->r.maxs[0], ent->r.maxs[1], ent->r.maxs[2] );
		printed++;
	}

	Com_Printf( "runtimeBModelInfo printed=%i limit=%i\n", printed, limit );
}
#define SVTELL_PREFIX "\x19[Server^7\x19]\x19: "

/*
==================
SV_ConTell_f
==================
*/
static void SV_ConTell_f(void) {
	char	text[MAX_SAY_TEXT] = {0};
	client_t	*cl;

	if( !com_dedicated->integer ) {
		Com_Printf( "Server is not dedicated.\n" );
		return;
	}

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc () < 3 ) {
		Com_Printf ("Usage: svtell <client number> <text>\n");
		return;
	}

	cl = SV_GetPlayerByNum();
	if ( !cl ) {
		return;
	}

	Cmd_ArgsFromBuffer( 2, text, sizeof(text) );

	Com_Printf ("tell: svtell to %s" S_COLOR_WHITE ": %s\n", cl->name, SV_ExpandNewlines((char *)text) );
	SV_SendServerCommand(cl, "chat \"" SVTELL_PREFIX S_COLOR_MAGENTA "%s" S_COLOR_WHITE "\"\n", text);
}

const char *forceToggleNamePrints[NUM_FORCE_POWERS] = {
	"HEAL",
	"JUMP",
	"SPEED",
	"PUSH",
	"PULL",
	"MINDTRICK",
	"GRIP",
	"LIGHTNING",
	"DARK RAGE",
	"PROTECT",
	"ABSORB",
	"TEAM HEAL",
	"TEAM REPLENISH",
	"DRAIN",
	"SEEING",
	"SABER OFFENSE",
	"SABER DEFENSE",
	"SABER THROW",
};

static void SV_ForceToggle_f( void ) {
	int bits = Cvar_VariableIntegerValue("g_forcePowerDisable");
	int i, val;
	char *s;
	const char *disablestrings[] =
	{
		"Enabled",
		"Disabled"
	};

	// make sure server is running
	if( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 ) {
		for(i = 0; i < NUM_FORCE_POWERS; i++ ) {
			Com_Printf ("%i - %s - Status: %s\n", i, forceToggleNamePrints[i], disablestrings[!(bits & (1<<i))]);
		}
		Com_Printf( "Example usage: forcetoggle 3(toggles PUSH)\n" );
		return;
	}

	s = Cmd_Argv(1);

	if( Q_isanumber( s ) ) {
		val = atoi(s);
		if( val >= 0 && val < NUM_FORCE_POWERS) {
			bits ^= (1 << val);
			Cvar_SetValue("g_forcePowerDisable", bits);
			Com_Printf( "%s %s^7\n", forceToggleNamePrints[val], (bits & (1<<val)) ? "^2Enabled" : "^1Disabled" );
		}
		else {
			for ( i = 0; i<NUM_FORCE_POWERS; i++ ) {
				if ( (bits & (1 << i)) )		Com_Printf( "%2d [X] %s\n", i, forceToggleNamePrints[i] );
				else							Com_Printf( "%2d [ ] %s\n", i, forceToggleNamePrints[i] );
			}
			Com_Printf ("Specified a power that does not exist.\nExample usage: forcetoggle 3\n(toggles PUSH)\n");
		}
	}
	else {
		for(i = 0; i < NUM_FORCE_POWERS; i++ ) {
			Com_Printf ("%i - %s - Status: %s\n", i, forceToggleNamePrints[i], disablestrings[!(bits & (1<<i))]);
		}
		Com_Printf ("Specified a power that does not exist.\nExample usage: forcetoggle 3\n(toggles PUSH)\n");
	}
}

const char *weaponToggleNamePrints[WP_NUM_WEAPONS] = {
	"NO WEAPON",
	"STUN BATON",
	"MELEE",
	"SABER",
	"BRYAR PISTOL",
	"BLASTER",
	"DISRUPTOR",
	"BOWCASTER",
	"REPEATER",
	"DEMP2",
	"FLECHETTE",
	"ROCKET LAUNCHER",
	"THERMAL",
	"TRIP MINE",
	"DET PACK",
	"CONCUSSION",
	"BRYAR OLD",
	"EMPLACED GUN",
	"TURRET"
};

static void SV_WeaponToggle_f( void ) {
	int bits = 0;
	int i, val;
	char *s;
	const char *cvarStr = NULL;

	if ( sv_gametype->integer == GT_DUEL || sv_gametype->integer == GT_POWERDUEL ) {
		cvarStr = "g_duelWeaponDisable";
		bits = Cvar_VariableIntegerValue( "g_duelWeaponDisable" );
	}
	else {
		cvarStr = "g_weaponDisable";
		bits = Cvar_VariableIntegerValue( "g_weaponDisable" );
	}

	// make sure server is running
	if( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 ) {
		for ( i = 0; i<WP_NUM_WEAPONS; i++ ) {
			if ( (bits & (1 << i)) )		Com_Printf( "%2d [X] %s\n", i, weaponToggleNamePrints[i] );
			else							Com_Printf( "%2d [ ] %s\n", i, weaponToggleNamePrints[i] );
		}
		Com_Printf ("Example usage: weapontoggle 3(toggles SABER)\n");
		return;
	}

	s = Cmd_Argv(1);

	if( Q_isanumber( s ) ) {
		val = atoi(s);
		if( val >= 0 && val < WP_NUM_WEAPONS) {
			bits ^= (1 << val);
			Cvar_SetValue(cvarStr, bits);
			Com_Printf( "%s %s^7\n", weaponToggleNamePrints[val], (bits & (1 << val)) ? "^2Enabled" : "^1Disabled" );
		}
		else {
			for ( i = 0; i<WP_NUM_WEAPONS; i++ ) {
				if ( (bits & (1 << i)) )		Com_Printf( "%2d [X] %s\n", i, weaponToggleNamePrints[i] );
				else							Com_Printf( "%2d [ ] %s\n", i, weaponToggleNamePrints[i] );
			}
			Com_Printf ("Specified a weapon that does not exist.\nExample usage: weapontoggle 3\n(toggles SABER)\n");
		}
	}
	else {
		for ( i = 0; i<WP_NUM_WEAPONS; i++ ) {
			if ( (bits & (1 << i)) )		Com_Printf( "%2d [X] %s\n", i, weaponToggleNamePrints[i] );
			else							Com_Printf( "%2d [ ] %s\n", i, weaponToggleNamePrints[i] );
		}
		Com_Printf ("Specified a weapon that does not exist.\nExample usage: weapontoggle 3\n(toggles SABER)\n");
	}
}

/*
==================
SV_Heartbeat_f

Also called by SV_DropClient, SV_DirectConnect, and SV_SpawnServer
==================
*/
void SV_Heartbeat_f( void ) {
	svs.nextHeartbeatTime = -9999999;
}

/*
===========
SV_Serverinfo_f

Examine the serverinfo string
===========
*/
static void SV_Serverinfo_f( void ) {
	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	Com_Printf ("Server info settings:\n");
	Info_Print ( Cvar_InfoString( CVAR_SERVERINFO ) );
}

/*
===========
SV_Systeminfo_f

Examine or change the serverinfo string
===========
*/
static void SV_Systeminfo_f( void ) {
	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	Com_Printf ("System info settings:\n");
	Info_Print ( Cvar_InfoString_Big( CVAR_SYSTEMINFO ) );
}

/*
===========
SV_DumpUser_f

Examine all a users info strings FIXME: move to game
===========
*/
static void SV_DumpUser_f( void ) {
	client_t	*cl;

	// make sure server is running
	if ( !com_sv_running->integer ) {
		Com_Printf( "Server is not running.\n" );
		return;
	}

	if ( Cmd_Argc() != 2 ) {
		Com_Printf ("Usage: dumpuser <userid>\n");
		return;
	}

	cl = SV_GetPlayerByHandle();
	if ( !cl ) {
		return;
	}

	Com_Printf( "userinfo\n" );
	Com_Printf( "--------\n" );
	Info_Print( cl->userinfo );
}

/*
=================
SV_KillServer
=================
*/
static void SV_KillServer_f( void ) {
	SV_Shutdown( "killserver" );
}

#ifdef DEDICATED
void SV_WriteDemoMessage ( client_t *cl, msg_t *msg, int headerBytes ) {
	int		len, swlen;

	// write the packet sequence
	len = cl->netchan.outgoingSequence;
	swlen = LittleLong( len );
	FS_Write( &swlen, 4, cl->demo.demofile );

	// skip the packet sequencing information
	len = msg->cursize - headerBytes;
	swlen = LittleLong( len );
	FS_Write( &swlen, 4, cl->demo.demofile );
	FS_Write( msg->data + headerBytes, len, cl->demo.demofile );
}

void SV_WriteDemoMessage ( client_t *cl, msg_t *msg, int headerBytes, int messageNum ) { // Version that specifies messagenumber manually, for buffered (pre-record) messages.
	int		len, swlen;

	// write the packet sequence
	len = messageNum;
	swlen = LittleLong( len );
	FS_Write( &swlen, 4, cl->demo.demofile );

	// skip the packet sequencing information
	len = msg->cursize - headerBytes;
	swlen = LittleLong( len );
	FS_Write( &swlen, 4, cl->demo.demofile );
	FS_Write( msg->data + headerBytes, len, cl->demo.demofile );
}



constexpr char postEOFMetadataMarker[] = "HIDDENMETA";

// Write an empty message at start of demo with metadata.
// Metadata must be in JSON format to maintain compatibility for this format,
// that way every demo writing tool/client/server can read/write different parameters
// without conflicting.
// But the JSON is not verified in this function, so just be good.
// "lastClientCommand" is client->lastClientCommand, but if you are pre-recording,
// you should get the older value
// "messageNum" is the messageNum of the metadata messsage.
// Normally the first message in a demo is the "header" or gamestate message with first message num -1
// With metadata, this becomes sthe first message instead. So it's first demo message num - 2
void SV_WriteEmptyMessageWithMetadata(int lastClientCommand, fileHandle_t f, const char* metaData, int messageNum) {
	byte			bufData[MAX_MSGLEN];
	msg_t			buf;
	int				len;

	MSG_Init(&buf, bufData, sizeof(bufData));
	MSG_Bitstream(&buf);
	// NOTE, MRE: all server->client messages now acknowledge
	MSG_WriteLong(&buf, lastClientCommand);
	MSG_WriteByte(&buf, svc_EOF);

	// Normal demo readers will quit here. For all intents and purposes this demo message is over. But we're gonna put the metadata here now. Since it comes after svc_EOF, nobody will ever be bothered by it
	// but we can read it if we want to.
	constexpr int metaMarkerLength = sizeof(postEOFMetadataMarker)-1;
	// This is how the demo huffman operates. Worst case a byte can take almost 2 bytes to save, from what I understand. When reading past the end, we need to detect if we SHOULD read past the end.
	// For each byte we need to read, thus, the message length must be at least 2 bytes longer still. Hence at the end we will artificially set the message length to be minimum that long.
	// We will only read x amount of bytes (where x is the length of the meta marker) and see if the meta marker is present. If it is, we then proceeed to read a bigstring.
	// This same thing is technically not true for the custom compressed types (as their size is always the real size of the data) but we'll just leave it like this to be universal and simple.
	constexpr int maxBytePerByteSaved = 2;
	constexpr int metaMarkerPresenceMinimumByteLengthExtra = metaMarkerLength * maxBytePerByteSaved;

	const int requiredCursize = buf.cursize + metaMarkerPresenceMinimumByteLengthExtra; // We'll just set it to this value at the end if it ends up smaller.

	for (int i = 0; i < metaMarkerLength; i++) {
		MSG_WriteByte(&buf, postEOFMetadataMarker[i]);
	}
	MSG_WriteBigString(&buf, metaData);


	MSG_WriteByte(&buf, svc_EOF); // Done. Not really needed but whatever.

	if (buf.cursize < requiredCursize) {
		buf.cursize = requiredCursize;
	}

	// write it to the demo file
	len = LittleLong(messageNum);
	FS_Write(&len, 4, f);
	len = LittleLong(buf.cursize);
	FS_Write(&len, 4, f);

	FS_Write(buf.data, buf.cursize, f);
}

void SV_StopRecordDemo( client_t *cl ) {
	int		len;

	if ( !cl->demo.demorecording ) {
		Com_Printf( "Client %d is not recording a demo.\n", cl - svs.clients );
		return;
	}

	// finish up
	len = -1;
	FS_Write (&len, 4, cl->demo.demofile);
	FS_Write (&len, 4, cl->demo.demofile);
	FS_FCloseFile (cl->demo.demofile);
	cl->demo.demofile = 0;
	cl->demo.demorecording = qfalse;
	if (com_developer->integer)
		Com_Printf ("Stopped demo for client %d.\n", cl - svs.clients);
}

void SV_ClearClientDemoMeta( client_t *cl ) {

	demoMetaData[cl - svs.clients].clear();
}

void SV_ClearClientDemoPreRecord( client_t *cl ) {

	demoPreRecordBuffer[cl - svs.clients].clear();
	Com_Memset(&cl->demo.preRecord,0,sizeof(cl->demo.preRecord));
	cl->demo.preRecord.lastKeyframeTime = -(1000*sv_demoPreRecordKeyframeDistance->integer) * 2; // Make sure that restarting recording will immediately create a keyframe.
}

void SV_ClearAllDemoPreRecord( ) {

	if (svs.clients) {
		for (client_t* client = svs.clients; client - svs.clients < sv_maxclients->integer; client++) {
			SV_ClearClientDemoPreRecord( client );
		}
	}
}

// stops all recording demos
void SV_StopAutoRecordDemos() {
	if ( svs.clients && sv_autoDemo->integer ) {
		for ( client_t *client = svs.clients; client - svs.clients < sv_maxclients->integer; client++ ) {
			if ( client->demo.demorecording) {
				SV_StopRecordDemo( client );
			}
		}
	}
}

/*
====================
SV_StopRecording_f

stop recording a demo
====================
*/
void SV_StopRecord_f( void ) {
	int		i;

	client_t *cl = NULL;
	if ( Cmd_Argc() == 2 ) {
		int clIndex = atoi( Cmd_Argv( 1 ) );
		if ( clIndex < 0 || clIndex >= sv_maxclients->integer ) {
			Com_Printf( "Unknown client number %d.\n", clIndex );
			return;
		}
		cl = &svs.clients[clIndex];
	} else {
		for (i = 0; i < sv_maxclients->integer; i++) {
			if ( svs.clients[i].demo.demorecording ) {
				cl = &svs.clients[i];
				break;
			}
		}
		if ( cl == NULL ) {
			Com_Printf( "No demo being recorded.\n" );
			return;
		}
	}
	SV_StopRecordDemo( cl );
}

/*
====================
SV_RenameDemo_f

rename a demo, deleting the destination file if it already exists
====================
*/
void SV_RenameDemo_f(void) {
	char		from[MAX_OSPATH];
	char		to[MAX_OSPATH];

	if (Cmd_Argc() != 3) {
		return;
	}

	Com_sprintf(from, sizeof(from), "demos/%s.dm_%d", Cmd_Argv(1), PROTOCOL_VERSION);
	Com_sprintf(to, sizeof(to), "demos/%s.dm_%d", Cmd_Argv(2), PROTOCOL_VERSION); //DEMO_EXTENSION

	if (FS_CheckDirTraversal(from) || FS_CheckDirTraversal(to)) {
		return;
	}

	FS_Rename(from, to);
}

/*
====================
SV_ListRecording_f

list demos being recorded
====================
*/
void SV_ListRecording_f(void) {
	int i;
	Com_Printf("Demos currently being recorded:\n");
	for (i = 0; i < sv_maxclients->integer; i++) {
		if (svs.clients[i].demo.demorecording) {
			Com_Printf("Client %i (%s)\n", i, svs.clients[i].demo.demoName);
		}
	}
}

/*
==================
SV_DemoFilename
==================
*/
void SV_DemoFilename( char *buf, int bufSize ) {
	time_t rawtime;
	char timeStr[32] = {0}; // should really only reach ~19 chars

	time( &rawtime );
	strftime( timeStr, sizeof( timeStr ), "%Y-%m-%d_%H-%M-%S", localtime( &rawtime ) ); // or gmtime

	Com_sprintf( buf, bufSize, "demo%s", timeStr );
}

// defined in sv_client.cpp
extern void SV_CreateClientGameStateMessage( client_t *client, msg_t* msg );
void SV_RecordDemo( client_t *cl, char *demoName ) {
	char		name[MAX_OSPATH];
	byte		bufData[MAX_MSGLEN];
	msg_t		msg;
	int			len;
	std::stringstream ssMeta; // JSON metadata

	if ( cl->demo.demorecording ) {
		Com_Printf( "Already recording.\n" );
		return;
	}

	if ( cl->state != CS_ACTIVE ) {
		Com_Printf( "Client is not active.\n" );
		return;
	}

	// open the demo file
	Q_strncpyz( cl->demo.demoName, demoName, sizeof( cl->demo.demoName ) );
	Com_sprintf( name, sizeof( name ), "demos/%s.dm_%d", cl->demo.demoName, PROTOCOL_VERSION ); //Should use DEMO_EXTENSION


	if (com_developer->integer) {
		Com_Printf("recording to %s.\n", name);
	}
	cl->demo.demofile = FS_FOpenFileWriteAsync( name, qtrue );
	if ( !cl->demo.demofile ) {
		Com_Printf ("ERROR: couldn't open.\n");
		return;
	}
	cl->demo.demorecording = qtrue;

	cl->demo.isBot = (cl->netchan.remoteAddress.type == NA_BOT) ? qtrue : qfalse;
	cl->demo.botReliableAcknowledge = cl->reliableSent;

	// Save metadata message if desired
	if (sv_demoWriteMeta->integer) {
		ssMeta << "{";
		ssMeta << "\"wr\":\"TaystJK_Server\""; // Writer (keyword used by other tools too to identify origin of demo)

		// Go through manually set metadata and add it.
		for (auto it = demoMetaData[cl - svs.clients].begin(); it != demoMetaData[cl - svs.clients].end(); it++) {
			if (it->first != "wr" && it->first != "ost" && it->first != "prso") { // Can't overwrite default parameters (writer, original start time, pre-record start offset)

				ssMeta << ",\"" << it->first << "\":"; // JSON Key

				// Check if value is number
				bool isNumber = true;
				for (int i = 0; i < it->second.size(); i++) {
					if (!((it->second[i] >= '0' && it->second[i] <= '9') || (it->second[i] == '.'))) { // Allow floating point numbers too
						isNumber = false;
						break;
					}
				}

				if (isNumber) {
					ssMeta << it->second; // JSON Number value (no quotes)
				}
				else {
					ssMeta << "\"" << it->second << "\""; // JSON String value (with quotes)
				}
			}
		}
		//ssMeta << "}"; // Don't end the json array here, we want to add extra info in the case of pre-recording
	}

	// Ok we have two options now. Either the classical way of starting with gamestate.
	// OR, if enabled, we use our pre-recorded buffer to start recording a bit in the past,
	// in which case we also don't have to worry about demowaiting since the pre-record
	// already takes care of that
	if (sv_demoPreRecord->integer) {
		// Pre-recording is enabled. Let's check for the oldest available keyframe.
		demoPreRecordBufferIt firstOldKeyframe;
		qboolean firstOldKeyframeFound = qfalse;
		for (demoPreRecordBufferIt it = demoPreRecordBuffer[cl - svs.clients].begin(); it != demoPreRecordBuffer[cl - svs.clients].end(); it++) {
			if (it->get()->isKeyframe && it->get()->time < sv.time) {
				firstOldKeyframe = it;
				firstOldKeyframeFound = qtrue;
				break;
			}
		}
		if (firstOldKeyframeFound) {
			int index = 0;
			// Dump this keyframe (gamestate message) and all following non-keyframes into the demo.
			for (demoPreRecordBufferIt it = firstOldKeyframe; it != demoPreRecordBuffer[cl - svs.clients].end(); it++,index++) {
				static byte preRecordBufData[MAX_MSGLEN]; // I make these static so they don't sit on the stack.
				static msg_t		preRecordMsg;

				if ((!it->get()->isKeyframe || index == 0) && it->get()->msgNum <= cl->netchan.outgoingSequence && it->get()->time <= sv.time) { // Check against outgoing sequence and server time too, *just in case* we ended up with some old messages
					// We only want a keyframe at the beginning of the demo, none after.
					Com_Memset(&preRecordMsg, 0, sizeof(msg_t));
					Com_Memset(&preRecordBufData, 0, sizeof(preRecordBufData));
					preRecordMsg.data = preRecordBufData;
					MSG_FromBuffered(&preRecordMsg, &it->get()->msg);
					MSG_WriteByte(&preRecordMsg, svc_EOF); // We didn't do that for the ones we put into the buffer, so we do it now.
					if (index == 0 && sv_demoWriteMeta->integer) {
						// This goes before the first messsage

						ssMeta << ",\"ost\":" << ((int64_t)std::time(nullptr) - ((sv.time - it->get()->time)/1000)); // Original start time. When was demo recording started?
						ssMeta << ",\"prso\":" << (sv.time-it->get()->time); // Pre-recording start offset. Offset from start of demo to when the command to start recording was called

						ssMeta << "}"; // End JSON object
						SV_WriteEmptyMessageWithMetadata(it->get()->lastClientCommand, cl->demo.demofile,ssMeta.str().c_str(),it->get()->msgNum-1);
					}
					SV_WriteDemoMessage(cl,&preRecordMsg,0,it->get()->msgNum);
				}
			}
			return; // No need to go through the whole normal demo procedure with demowaiting etc.
		}
	}

	// don't start saving messages until a non-delta compressed message is received
	cl->demo.demowaiting = qtrue;

	// write out the gamestate message
	MSG_Init( &msg, bufData, sizeof( bufData ) );

	// NOTE, MRE: all server->client messages now acknowledge
	int tmp = cl->reliableSent;
	SV_CreateClientGameStateMessage( cl, &msg );
	cl->reliableSent = tmp;

	// finished writing the client packet
	MSG_WriteByte( &msg, svc_EOF );

	if (sv_demoWriteMeta->integer) {
		// Write metadata first
		ssMeta << ",\"ost\":" << (int64_t)std::time(nullptr); // Original start time. When was demo recording started?
		ssMeta << "}"; // End JSON object
		SV_WriteEmptyMessageWithMetadata(cl->lastClientCommand, cl->demo.demofile, ssMeta.str().c_str(), cl->netchan.outgoingSequence - 2);
	}

	// write it to the demo file
	len = LittleLong( cl->netchan.outgoingSequence - 1 );
	FS_Write( &len, 4, cl->demo.demofile );

	len = LittleLong( msg.cursize );
	FS_Write( &len, 4, cl->demo.demofile );
	FS_Write( msg.data, msg.cursize, cl->demo.demofile );

	// the rest of the demo file will be copied from net messages
}

void SV_AutoRecordDemo( client_t *cl ) {
	char demoName[MAX_OSPATH];
	char demoFolderName[MAX_OSPATH];
	char demoFileName[MAX_OSPATH];
	char *demoNames[] = { demoFolderName, demoFileName };
	char date[MAX_OSPATH];
	char folderDate[MAX_OSPATH];
	char folderTreeDate[MAX_OSPATH];
	char demoPlayerName[MAX_NAME_LENGTH];
	time_t rawtime;
	struct tm * timeinfo;
	time( &rawtime );
	timeinfo = localtime( &rawtime );
	strftime( date, sizeof( date ), "%Y-%m-%d_%H-%M-%S", timeinfo );
	timeinfo = localtime( &sv.realMapTimeStarted );
	strftime( folderDate, sizeof( folderDate ), "%Y-%m-%d_%H-%M-%S", timeinfo );
	strftime( folderTreeDate, sizeof( folderTreeDate ), "%Y/%m/%d", timeinfo );
	Q_strncpyz( demoPlayerName, cl->name, sizeof( demoPlayerName ) );
	Q_CleanStr( demoPlayerName );
	if (sv_autoDemo->integer == 2)
		Com_sprintf( demoFileName, sizeof( demoFileName ), "%s %s", Cvar_VariableString( "mapname" ), date );
	else
	  Com_sprintf( demoFileName, sizeof( demoFileName ), "%d %s %s %s",
			  cl - svs.clients, demoPlayerName, Cvar_VariableString( "mapname" ), date );
	Com_sprintf( demoFolderName, sizeof( demoFolderName ), "%s %s", Cvar_VariableString( "mapname" ), folderDate );
	// sanitize filename
	for ( char **start = demoNames; start - demoNames < (ptrdiff_t)ARRAY_LEN( demoNames ); start++ ) {
		Q_strstrip( *start, "\n\r;:.?*<>|\\/\"", NULL );
	}
	Com_sprintf( demoName, sizeof( demoName ), "autorecord/%s/%s/%s", folderTreeDate, demoFolderName, demoFileName );
	SV_RecordDemo( cl, demoName );
}

static time_t SV_ExtractTimeFromDemoFolder( char *folder ) {
	char *slash = strrchr( folder, '/' );
	if ( slash ) {
		folder = slash + 1;
	}
	size_t timeLen = strlen( "0000-00-00_00-00-00" );
	if ( strlen( folder ) < timeLen ) {
		return 0;
	}
	struct tm timeinfo;
	timeinfo.tm_isdst = 0;
	int numMatched = sscanf( folder + ( strlen(folder) - timeLen ), "%4d-%2d-%2d_%2d-%2d-%2d",
		&timeinfo.tm_year, &timeinfo.tm_mon, &timeinfo.tm_mday, &timeinfo.tm_hour, &timeinfo.tm_min, &timeinfo.tm_sec);
	if ( numMatched < 6 ) {
		// parsing failed
		return 0;
	}
	timeinfo.tm_year -= 1900;
	timeinfo.tm_mon--;
	return mktime( &timeinfo );
}

static int QDECL SV_DemoFolderTimeComparator( const void *arg1, const void *arg2 ) {
	char *left = (char *)arg1, *right = (char *)arg2;
	time_t leftTime = SV_ExtractTimeFromDemoFolder( left );
	time_t rightTime = SV_ExtractTimeFromDemoFolder( right );
	if ( leftTime == 0 && rightTime == 0 ) {
		return -strcmp( left, right );
	} else if ( leftTime == 0 ) {
		return 1;
	} else if ( rightTime == 0 ) {
		return -1;
	}
	return rightTime - leftTime;
}


// returns number of folders found.  pass NULL result pointer for just a count.
static int SV_FindLeafFolders( const char *baseFolder, char *result, int maxResults, int maxFolderLength ) {
	char *fileList = (char *)Z_Malloc( MAX_OSPATH * maxResults, TAG_FILESYS ); // too big for stack since this is recursive
	char fullFolder[MAX_OSPATH];
	int resultCount = 0;
	char *fileName;
	int i;
	int numFiles = FS_GetFileList( baseFolder, "/", fileList, MAX_OSPATH * maxResults );

	fileName = fileList;
	for ( i = 0; i < numFiles; i++ ) {
		if ( Q_stricmp( fileName, "." ) && Q_stricmp( fileName, ".." ) ) {
			char *nextResult = NULL;
			Com_sprintf( fullFolder, sizeof( fullFolder ), "%s/%s", baseFolder, fileName );
			if ( result != NULL ) {
				nextResult = &result[maxFolderLength * resultCount];
			}
			int newResults = SV_FindLeafFolders( fullFolder, nextResult, maxResults - resultCount, maxFolderLength );
			resultCount += newResults;
			if ( result != NULL && resultCount >= maxResults ) {
				break;
			}
			if ( newResults == 0 ) {
				if ( result != NULL ) {
					Q_strncpyz( &result[maxFolderLength * resultCount], fullFolder, maxFolderLength );
				}
				resultCount++;
				if ( result != NULL && resultCount >= maxResults ) {
					break;
				}
			}
		}
		fileName += strlen( fileName ) + 1;
	}

	Z_Free( fileList );

	return resultCount;
}

// starts demo recording on all active clients
void SV_BeginAutoRecordDemos() {
	if ( sv_autoDemo->integer ) {
		if (sv_autoDemo->integer == 2) { //Record a bot in spec named "RECORDER" only (to be used with cvar that networks spectators all player info)
			qboolean humans = qfalse;

			for ( client_t *client = svs.clients; client - svs.clients < sv_maxclients->integer; client++ ) {
				if ( client->state == CS_ACTIVE && client->netchan.remoteAddress.type != NA_BOT ) {
					humans = qtrue;
					break;
				}
			}

			if (humans) { //mm.. stop demos of only bots being started when map_restart calls this
				for ( client_t *client = svs.clients; client - svs.clients < sv_maxclients->integer; client++ ) {
					if ( client->state == CS_ACTIVE && !client->demo.demorecording ) {
						if ( client->netchan.remoteAddress.type == NA_BOT && !Q_stricmp(client->name, "RECORDER") ) { //Only record a bot named RECORDER who is in spectate

							//client->gentity->playerState->fd.forcePowersActive
							//client->gentity->r.broadcastClients

							//client->gentity->playerState->

							SV_AutoRecordDemo( client );
							break;
						}
					}
				}
			}
		}
		else if (sv_autoDemo->integer == 1) { //Normal autodemo behaviour, record 1 demo for everyone
			for ( client_t *client = svs.clients; client - svs.clients < sv_maxclients->integer; client++ ) {
				if ( client->state == CS_ACTIVE && !client->demo.demorecording ) {
					if ( client->netchan.remoteAddress.type != NA_BOT || sv_autoDemoBots->integer ) {
						SV_AutoRecordDemo( client );
					}
				}
			}
		}
		if ( sv_autoDemoMaxMaps->integer > 0 && sv.demosPruned == qfalse ) {
			char autorecordDirList[500 * MAX_OSPATH], tmpFileList[5 * MAX_OSPATH];
			int autorecordDirListCount = SV_FindLeafFolders( "demos/autorecord", autorecordDirList, 500, MAX_OSPATH );
			int i;

			qsort( autorecordDirList, autorecordDirListCount, MAX_OSPATH, SV_DemoFolderTimeComparator );
			for ( i = sv_autoDemoMaxMaps->integer; i < autorecordDirListCount; i++ ) {
				char *folder = &autorecordDirList[i * MAX_OSPATH], *slash = NULL;
				FS_HomeRmdir( folder, qtrue );
				// if this folder was the last thing in its parent folder (and its parent isn't the root folder),
				// also delete the parent.
				for (;;) {
					slash = strrchr( folder, '/' );
					if ( slash == NULL ) {
						break;
					}
					slash[0] = '\0';
					if ( !strcmp( folder, "demos/autorecord" ) ) {
						break;
					}
					int numFiles = FS_GetFileList( folder, "", tmpFileList, sizeof( tmpFileList ) );
					int numFolders = FS_GetFileList( folder, "/", tmpFileList, sizeof( tmpFileList ) );
					// numFolders will include . and ..
					if ( numFiles == 0 && numFolders == 2 ) {
						// dangling empty folder, delete
						FS_HomeRmdir( folder, qfalse );
					} else {
						break;
					}
				}
			}
			sv.demosPruned = qtrue;
		}
	}
}

// code is a merge of the cl_main.cpp function of the same name and SV_SendClientGameState in sv_client.cpp
static void SV_Record_f( void ) {
	char		demoName[MAX_OSPATH];
	char		name[MAX_OSPATH];
	int			i;
	char		*s;
	client_t	*cl;
	//int			len;

	if ( svs.clients == NULL ) {
		Com_Printf( "cannot record server demo - null svs.clients\n" );
		return;
	}

	if ( Cmd_Argc() > 3 ) {
		Com_Printf( "record <demoname> <clientnum>\n" );
		return;
	}

	if ( Cmd_Argc() == 3 ) {
		int clIndex = atoi( Cmd_Argv( 2 ) );
		if ( clIndex < 0 || clIndex >= sv_maxclients->integer ) {
			Com_Printf( "Unknown client number %d.\n", clIndex );
			return;
		}
		cl = &svs.clients[clIndex];
	} else {
		for ( i=0, cl=svs.clients ; i < sv_maxclients->integer ; i++, cl++ )
		{
			if ( !cl->state )
			{
				continue;
			}

			if ( cl->demo.demorecording )
			{
				continue;
			}

			if ( cl->state == CS_ACTIVE )
			{
				break;
			}
		}
	}

	if (cl - svs.clients >= sv_maxclients->integer) {
		Com_Printf( "No active client could be found.\n" );
		return;
	}

	if ( cl->demo.demorecording ) {
		Com_Printf( "Already recording.\n" );
		return;
	}

	if ( cl->state != CS_ACTIVE ) {
		Com_Printf( "Client is not active.\n" );
		return;
	}

	if ( Cmd_Argc() >= 2 ) {
		s = Cmd_Argv( 1 );
		Q_strncpyz( demoName, s, sizeof( demoName ) );
		Com_sprintf( name, sizeof( name ), "demos/%s.dm_%d", demoName, PROTOCOL_VERSION ); //Should use DEMO_EXTENSION
	} else {
		// timestamp the file
		SV_DemoFilename( demoName, sizeof( demoName ) );

		Com_sprintf (name, sizeof(name), "demos/%s.dm_%d", demoName, PROTOCOL_VERSION );

		if ( FS_FileExists( name ) ) {
			Com_Printf( "Record: Couldn't create a file\n");
			return;
 		}
	}

	SV_RecordDemo( cl, demoName );
}

// Set metadata for demos of a particular client
static void SV_DemoMeta_f(void) {
	int i,len;
	client_t* cl;
	const char* key = NULL;
	const char* data = NULL;

	if (!svs.clients) {
		Com_Printf("Can't set demo metadata, svs.clients is null\n");
		return;
	}

	if (Cmd_Argc() != 4 && Cmd_Argc() != 3) {
		Com_Printf("svdemometa <clientnum> <metakey> <metadata>, for example svdemometa 2 runstarttime 235254. Leave out <metadata> to remove key.\n");
		return;
	}

	int clIndex = atoi(Cmd_Argv(1));
	if (clIndex < 0 || clIndex >= sv_maxclients->integer) {
		Com_Printf("Unknown client number %d.\n", clIndex);
		return;
	}
	cl = &svs.clients[clIndex];

	key = Cmd_Argv(2);
	data = Cmd_Argc() == 4 ? Cmd_Argv(3) : "";

	// Quick sanity check for key (must be valid json key)
	// Let's be strict and only allow letters
	len = strlen(key);
	if (len == 0) {
		Com_Printf("Metadata key must not be empty\n");
		return;
	}
	for (i = 0; i < len; i++) {
		if (!((key[i] > 'a' && key[i] < 'z') || (key[i] > 'A' && key[i] < 'Z'))) {
			Com_Printf("Metadata key must only contain a-z (lower or upper case)\n");
			return;
		}
	}
	len = strlen(data);
	if (len == 0) {
		// Empty data provided. Remove key if it exists.
		if (demoMetaData[cl - svs.clients].find(key) != demoMetaData[cl - svs.clients].end()) {
			demoMetaData[cl - svs.clients].erase(key);
		}
	}
	else {
		demoMetaData[cl - svs.clients][key] = data;
	}

}
// Clear metadata for demos of a particular client
static void SV_DemoClearMeta_f(void) {
	client_t* cl;

	if (!svs.clients) {
		Com_Printf("Can't clear demo metadata, svs.clients is null\n");
		return;
	}

	if (Cmd_Argc() != 2) {
		Com_Printf("svdemoclearmeta <clientnum>\n");
		return;
	}

	int clIndex = atoi(Cmd_Argv(1));
	if (clIndex < 0 || clIndex >= sv_maxclients->integer) {
		Com_Printf("Unknown client number %d.\n", clIndex);
		return;
	}
	cl = &svs.clients[clIndex];

	SV_ClearClientDemoMeta(cl);
}
// Clear pre-record data for demos of a particular client
// Careful with overusage: This will force generation of new keyframes & non-delta snaps
static void SV_DemoClearPreRecord_f(void) {
	client_t* cl;

	if (!svs.clients) {
		Com_Printf("Can't clear demo pre-record, svs.clients is null\n");
		return;
	}

	if (Cmd_Argc() != 2) {
		Com_Printf("svdemoclearprerecord <clientnum>\n");
		return;
	}

	int clIndex = atoi(Cmd_Argv(1));
	if (clIndex < 0 || clIndex >= sv_maxclients->integer) {
		Com_Printf("Unknown client number %d.\n", clIndex);
		return;
	}
	cl = &svs.clients[clIndex];

	SV_ClearClientDemoPreRecord(cl);
}


#endif

/*
=================
SV_WhitelistIP_f
=================
*/
static void SV_WhitelistIP_f( void ) {
	if ( Cmd_Argc() < 2 ) {
		Com_Printf ("Usage: whitelistip <ip>...\n");
		return;
	}

	for ( int i = 1; i < Cmd_Argc(); i++ ) {
		netadr_t	adr;

		if ( NET_StringToAdr( Cmd_Argv(i), &adr ) ) {
			SVC_WhitelistAdr( &adr );
			Com_Printf("Added %s to the IP whitelist\n", NET_AdrToString(&adr));
		} else {
			Com_Printf("Incorrect IP address: %s\n", Cmd_Argv(i));
		}
	}
}

//===========================================================

/*
==================
SV_CompleteMapName
==================
*/
static void SV_CompleteMapName( char *args, int argNum ) {
	if ( argNum == 2 )
		Field_CompleteFilename( "maps", "bsp", qtrue, qfalse );
}

/*
==================
SV_AddOperatorCommands
==================
*/
void SV_AddOperatorCommands( void ) {
	static qboolean	initialized;

	if ( initialized ) {
		return;
	}
	initialized = qtrue;

	Cmd_AddCommand ("heartbeat", SV_Heartbeat_f, "Sends a heartbeat to the masterserver" );
	Cmd_AddCommand ("kick", SV_Kick_f, "Kick a user from the server" );
	Cmd_AddCommand ("kickbots", SV_KickBots_f, "Kick all bots from the server" );
	Cmd_AddCommand ("kickall", SV_KickAll_f, "Kick all users from the server" );
	Cmd_AddCommand ("kicknum", SV_KickNum_f, "Kick a user from the server by userid" );
	Cmd_AddCommand ("clientkick", SV_KickNum_f, "Kick a user from the server by userid" );
	Cmd_AddCommand ("status", SV_Status_f, "Prints status of server and connected clients" );
	Cmd_AddCommand ("serverinfo", SV_Serverinfo_f, "Prints the serverinfo that is visible in the server browsers" );
	Cmd_AddCommand ("systeminfo", SV_Systeminfo_f, "Prints the systeminfo variables that are replicated to clients" );
	Cmd_AddCommand ("dumpuser", SV_DumpUser_f, "Prints the userinfo for a given userid" );
	Cmd_AddCommand ("map_restart", SV_MapRestart_f, "Restart the current map" );
	Cmd_AddCommand ("sectorlist", SV_SectorList_f);
	Cmd_AddCommand ("map", SV_Map_f, "Load a new map with cheats disabled" );
	Cmd_SetCommandCompletionFunc( "map", SV_CompleteMapName );
	Cmd_AddCommand ("devmap", SV_Map_f, "Load a new map with cheats enabled" );
	Cmd_SetCommandCompletionFunc( "devmap", SV_CompleteMapName );
//	Cmd_AddCommand ("devmapbsp", SV_Map_f);	// not used in MP codebase, no server BSP_cacheing
	Cmd_AddCommand ("devmapmdl", SV_Map_f, "Load a new map with cheats enabled" );
	Cmd_SetCommandCompletionFunc( "devmapmdl", SV_CompleteMapName );
	Cmd_AddCommand ("devmapall", SV_Map_f, "Load a new map with cheats enabled" );
	Cmd_SetCommandCompletionFunc( "devmapall", SV_CompleteMapName );
	Cmd_AddCommand ("killserver", SV_KillServer_f, "Shuts the server down and disconnects all clients" );
	Cmd_AddCommand ("svsay", SV_ConSay_f, "Broadcast server messages to clients" );
	Cmd_AddCommand ("clearBSPs", SV_ClearBSPs_f, "Clear all dynamically loaded runtime BSP instances" );
	Cmd_AddCommand ("resendgamestate", SV_ResendGameState_f, "Force connected clients through a fresh gamestate reload" );
	Cmd_AddCommand ("clientMap", SV_ClientMap_f, "Diagnostic: send one client a gamestate with a different mapname" );
	Cmd_AddCommand ("clientBSPState", SV_ClientBSPState_f, "Diagnostic: inspect/send runtime BSP model state for one client" );
	Cmd_AddCommand ("dimensionInfo", SV_DimensionInfo_f, "Diagnostic: inspect dimension world/group context for one or two entities" );
	Cmd_AddCommand ("runtimeBModelInfo", SV_RuntimeBModelInfo_f, "Diagnostic: list runtime brush models for one client" );
	Cmd_AddCommand ("svtell", SV_ConTell_f, "Private message from the server to a user" );
	Cmd_AddCommand ("forcetoggle", SV_ForceToggle_f, "Toggle g_forcePowerDisable bits" );
	Cmd_AddCommand ("weapontoggle", SV_WeaponToggle_f, "Toggle g_weaponDisable bits" );
#ifdef DEDICATED
	Cmd_AddCommand ("svrecord", SV_Record_f, "Record a server-side demo" );
	Cmd_AddCommand ("svstoprecord", SV_StopRecord_f, "Stop recording a server-side demo" );
	Cmd_AddCommand ("svdemometa", SV_DemoMeta_f, "Sets a new metadata entry for server-side demos for one player. Call with clientnum, metakey, [data]");
	Cmd_AddCommand ("svdemoclearmeta", SV_DemoClearMeta_f, "Clears metadata for server-side demos for one player. Call with clientnum.");
	Cmd_AddCommand ("svdemoclearprerecord", SV_DemoClearPreRecord_f, "Clears pre-record data for a particular client. Call with clientnum.");
	Cmd_AddCommand ("svrenamedemo", SV_RenameDemo_f, "Rename a server-side demo");
	Cmd_AddCommand("sv_listrecording", SV_ListRecording_f, "Lists demos being recorded");
#endif
	Cmd_AddCommand ("sv_rehashbans", SV_RehashBans_f, "Reloads banlist from file" );
	Cmd_AddCommand ("sv_listbans", SV_ListBans_f, "Lists bans" );
	Cmd_AddCommand ("sv_banaddr", SV_BanAddr_f, "Bans a user" );
	Cmd_AddCommand ("sv_exceptaddr", SV_ExceptAddr_f, "Adds a ban exception for a user" );
	Cmd_AddCommand ("sv_bandel", SV_BanDel_f, "Removes a ban" );
	Cmd_AddCommand ("sv_exceptdel", SV_ExceptDel_f, "Removes a ban exception" );
	Cmd_AddCommand ("sv_flushbans", SV_FlushBans_f, "Removes all bans and exceptions" );
	Cmd_AddCommand ("whitelistip", SV_WhitelistIP_f, "Add IP to the whitelist" );
}

/*
==================
SV_RemoveOperatorCommands
==================
*/
void SV_RemoveOperatorCommands( void ) {
#if 0
	// removing these won't let the server start again
	Cmd_RemoveCommand ("heartbeat");
	Cmd_RemoveCommand ("kick");
	Cmd_RemoveCommand ("banUser");
	Cmd_RemoveCommand ("banClient");
	Cmd_RemoveCommand ("status");
	Cmd_RemoveCommand ("serverinfo");
	Cmd_RemoveCommand ("systeminfo");
	Cmd_RemoveCommand ("dumpuser");
	Cmd_RemoveCommand ("map_restart");
	Cmd_RemoveCommand ("sectorlist");
	Cmd_RemoveCommand ("svsay");
#endif
}

