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

// console.c

#include "client.h"
#include "cl_cgameapi.h"
#include "qcommon/stringed_ingame.h"
#include "qcommon/game_version.h"



console_t	con;

cvar_t		*con_conspeed;
cvar_t		*con_notifytime;
cvar_t		*con_notifylines;
cvar_t		*con_opacity; // background alpha multiplier
cvar_t		*con_ratioFix; //for custom console backgrounds
cvar_t		*con_autoclear;
cvar_t		*con_notifywords;
cvar_t		*con_notifyconnect;
cvar_t		*con_notifyvote;
cvar_t		*con_height;
cvar_t		*con_scale;
cvar_t		*con_timestamps;

#define	DEFAULT_CONSOLE_WIDTH	78

#define CON_BLANK_CHAR			' '
#define CON_SCROLL_L_CHAR		'$'
#define CON_SCROLL_R_CHAR		'$'
#define CON_TIMESTAMP_LEN		11 // "[13:37:00] "
#define CON_MIN_WIDTH			20


static const conChar_t CON_WRAP = { { ColorIndex(COLOR_GREY), '\\' } };
static const conChar_t CON_BLANK = { { ColorIndex(COLOR_WHITE), CON_BLANK_CHAR } };

vec4_t	console_color = {0.509f, 0.609f, 0.847f, 1.0f};

/*
================
Con_ToggleConsole_f
================
*/
void Con_ToggleConsole_f (void) {
	// closing a full screen console restarts the demo loop
	if ( cls.state == CA_DISCONNECTED && Key_GetCatcher( ) == KEYCATCH_CONSOLE ) {
		CL_StartDemoLoop();
		return;
	}

	if( con_autoclear->integer )
		Field_Clear( &g_consoleField );

	Con_ClearNotify ();
	Key_SetCatcher( Key_GetCatcher( ) ^ KEYCATCH_CONSOLE );
}

/*
===================
Con_ToggleMenu_f
===================
*/
void Con_ToggleMenu_f( void ) {
	CL_KeyEvent( A_ESCAPE, qtrue, Sys_Milliseconds() );
	CL_KeyEvent( A_ESCAPE, qfalse, Sys_Milliseconds() );
}

/*
================
Con_MessageMode_f
================
*/
void Con_MessageMode_f (void) {	//yell
	chat_playerNum = -1;
	chat_team = qfalse;
	Field_Clear( &chatField );
	chatField.widthInChars = SCREEN_WIDTH / (BIGCHAR_WIDTH * cls.widthRatioCoef) - (16 * cls.widthRatioCoef);
	Key_SetCatcher( Key_GetCatcher( ) ^ KEYCATCH_MESSAGE );
}

/*
================
Con_MessageMode2_f
================
*/
void Con_MessageMode2_f (void) {	//team chat
	chat_playerNum = -1;
	chat_team = qtrue;
	Field_Clear( &chatField );
	chatField.widthInChars = SCREEN_WIDTH / (BIGCHAR_WIDTH * cls.widthRatioCoef) - (25 * cls.widthRatioCoef);
	Key_SetCatcher( Key_GetCatcher( ) ^ KEYCATCH_MESSAGE );
}

/*
================
Con_MessageMode3_f
================
*/
void Con_MessageMode3_f (void) {	//target chat
	if (!cls.cgameStarted)
	{
		assert(!"null cgvm");
		return;
	}

	if (cl.snap.ps.pm_flags & PMF_FOLLOW) { //Send to the person we are spectating instead
		chat_playerNum = cl.snap.ps.clientNum;
	}
	else {
		chat_playerNum = CGVM_CrosshairPlayer();
	}

	if ( chat_playerNum < 0 || chat_playerNum >= MAX_CLIENTS ) {
		chat_playerNum = -1;
		return;
	}
	chat_team = qfalse;
	Field_Clear( &chatField );
	chatField.widthInChars = SCREEN_WIDTH / (BIGCHAR_WIDTH * cls.widthRatioCoef) - (24 * cls.widthRatioCoef);
	Key_SetCatcher( Key_GetCatcher( ) ^ KEYCATCH_MESSAGE );
}

/*
================
Con_MessageMode4_f
================
*/
void Con_MessageMode4_f (void)
{	//attacker
	if (!cls.cgameStarted)
	{
		assert(!"null cgvm");
		return;
	}

	chat_playerNum = CGVM_LastAttacker();
	if ( chat_playerNum < 0 || chat_playerNum >= MAX_CLIENTS ) {
		chat_playerNum = -1;
		return;
	}
	chat_team = qfalse;
	Field_Clear( &chatField );
	chatField.widthInChars = SCREEN_WIDTH / (BIGCHAR_WIDTH * cls.widthRatioCoef) - (24 * cls.widthRatioCoef);
	Key_SetCatcher( Key_GetCatcher( ) ^ KEYCATCH_MESSAGE );
}

/*
================
Con_Clear_f
================
*/
void Con_Clear_f (void) {
	int		i;

	for ( i = 0 ; i < CON_TEXTSIZE ; i++ ) {
		con.text[i] = CON_BLANK;
	}

	Con_Bottom();		// go to end
}

void Con_Copy(void) {
	int l, x, i;
	conChar_t *line;
	int bufferlen, savebufferlen;
	char *buffer, *savebuffer;

	// skip empty lines
	for (l = con.current - con.totallines + 1; l <= con.current; l++)
	{
		line = con.text + (l%con.totallines)*con.linewidth;
		for (x = 0; x<con.linewidth; x++)
			if (line[x].f.character != CON_BLANK_CHAR)
				break;
		if (x != con.linewidth)
			break;
	}

	if (l > con.current) {
		Com_Printf("^3Console is empty! Nothing copied.\n");
		return;
	}

#ifdef _WIN32
	bufferlen = con.linewidth + 3;
#else
	bufferlen = con.linewidth + 2;
#endif

	savebufferlen = bufferlen*(con.current - l);
	buffer = (char *)Hunk_AllocateTempMemory(bufferlen);
	savebuffer = (char *)Hunk_AllocateTempMemory(savebufferlen);
	memset(savebuffer, 0, savebufferlen);

	// write the remaining lines
	buffer[bufferlen - 1] = 0;
	for (; l < con.current; l++)
	{
		line = con.text + (l%con.totallines)*con.linewidth;

		buffer[0] = '[';//this was a space
		for (i = 0; i<CON_TIMESTAMP_LEN; i++) //Add [ and ] brackets around timestamp.  0 and timestamp_length ?
			buffer[i+1] = line[i].f.character;
		buffer[CON_TIMESTAMP_LEN] = ']';//this was a space
		buffer[CON_TIMESTAMP_LEN+1] = CON_BLANK_CHAR;//add a new space
		for (i = CON_TIMESTAMP_LEN+1; i<con.linewidth; i++) //Add [ and ] brackets around timestamp.  0 and timestamp_length ?
			buffer[i+1] = line[i-1].f.character; //i-1 instead of i, does this fuck up the end?

		for (x = con.linewidth - 1; x >= 0; x--)
		{
			if (buffer[x] == CON_BLANK_CHAR)
				buffer[x] = 0;
			else
				break;
		}
#ifdef _WIN32
		Q_strcat(buffer, bufferlen, "\r\n");
#else
		Q_strcat(buffer, bufferlen, "\n");
#endif
		Q_strcat(savebuffer, savebufferlen, buffer);
	}
	Sys_SetClipboardData(savebuffer);
	Com_Printf("^2Console successfully copied to clipboard!\n");
	Hunk_FreeTempMemory(buffer);
	Hunk_FreeTempMemory(savebuffer);
}

void Con_CopyLink(void) {
	int l, x, i, pointDiff;
	conChar_t *line;
	char *buffer, n[] = "\0";
	const char *link, *point1, *point2, *point3;
	qboolean containsNum = qfalse, containsPoint = qfalse;

	buffer = (char *)Hunk_AllocateTempMemory(con.linewidth);

	for (l = con.current; l >= con.current - 32; l--)
	{
		line = con.text + (l%con.totallines)*con.linewidth;
		for (i = 0; i < con.linewidth; i++) {
			buffer[i] = line[i].f.character;
			if (!containsNum && Q_isanumber(&buffer[i])) containsNum = qtrue;
			if (!containsPoint && buffer[i] == '.') containsPoint = qtrue;
		}
		// Clear spaces at end of buffer
		for (x = con.linewidth - 1; x >= 0; x--) {
			if (buffer[x] == CON_BLANK_CHAR)
				buffer[x] = 0;
			else
				break;
		}
		Q_StripColor(buffer);
		if ((link = Q_stristr(buffer, "://")) || (link = Q_stristr(buffer, "www."))) {
			// Move link ptr back until it hits a space or first char of string
			while (link != &buffer[0] && *(link - 1) != CON_BLANK_CHAR) link--;
			for (i = 0; buffer[i] != 0; i++) {
				buffer[i] = *link++;
				if (*link == CON_BLANK_CHAR || *link == '"') buffer[i + 1] = 0;
			}
			Sys_SetClipboardData(buffer);
			Com_Printf("^2Link ^7\"%s\" ^2Copied!\n", buffer);
			break;
		}
		if (containsNum && containsPoint) {
			containsNum = qfalse, containsPoint = qfalse;
			if (!(point1 = Q_stristr(buffer, ".")) || // Set address of first point
				// Check if points exist after point1 and set their addresses
				!(point2 = Q_stristr(point1 + 1, ".")) ||
				!(point3 = Q_stristr(point2 + 1, "."))) continue;
			for(i = 0; buffer[i] != 0; i++) {
				if (point1 == &buffer[i]) { // If addresses match, set point1 to next point
					// Check if points exist and set point addresses
					if (
						!(point1 = Q_stristr(&buffer[i + 1], ".")) ||
						!(point2 = Q_stristr(point1 + 1, ".")) ||
						!(point3 = Q_stristr(point2 + 1, "."))
						) break;
				}
				*n = buffer[i]; // Force Q_isanumber to look at a single char
				if (Q_isanumber(n)) {
					// Check if chars exist between points and the amount of chars is > 0 & <=3
					// <xxx>.<xxx>.<xxx>. Can't reliably check for chars after last point
					if ((pointDiff = point1 - &buffer[i]) <= 3 &&
						pointDiff > 0 &&
						(pointDiff = point2 - (point1 + 1)) <= 3 &&
						pointDiff > 0 &&
						(pointDiff = point3 - (point2 + 1)) <= 3 &&
						pointDiff > 0
						) {
						link = &buffer[i];
						break;
					}
				}
			}
			if (link) {
				for (i = 0; buffer[i] != 0; i++) {
					buffer[i] = *link++;
					if (*link == CON_BLANK_CHAR || *link == '"') buffer[i + 1] = 0;
				}
				Sys_SetClipboardData(buffer);
				Com_Printf("^2IP ^7\"%s\" ^2Copied!\n", buffer);
				break;
			}
		}
	}
	if (!link) {
		Com_Printf("^1No Links or IPs found!\n", buffer);
	}
	Hunk_FreeTempMemory(buffer);
}

/*
================
Con_Dump_f

Save the console contents out to a file
================
*/
void Con_Dump_f (void)
{
	char			filename[MAX_QPATH];
	qboolean		empty;
	int				l, i, j;
	int				line;
	int				lineLen;
	fileHandle_t	f;
#ifdef WIN32
	char			buffer[CON_TIMESTAMP_LEN + MAXPRINTMSG + 2];
#else
	char			buffer[CON_TIMESTAMP_LEN + MAXPRINTMSG + 1];
#endif

	if (Cmd_Argc() != 2)
	{
		Com_Printf ("%s\n", SE_GetString("CON_TEXT_DUMP_USAGE"));
		return;
	}

	Q_strncpyz( filename, Cmd_Argv( 1 ), sizeof( filename ) );
	COM_DefaultExtension( filename, sizeof( filename ), ".txt" );

	if(!COM_CompareExtension(filename, ".txt"))
	{
		Com_Printf( "Con_Dump_f: Only the \".txt\" extension is supported by this command!\n" );
		return;
	}

	f = FS_FOpenFileWrite( filename );
	if (!f)
	{
		Com_Printf ("ERROR: couldn't open %s.\n", filename);
		return;
	}

	Com_Printf ("Dumped console text to %s.\n", filename );

	// skip empty lines
	for (l = 1, empty = qtrue ; l < con.totallines && empty ; l++)
	{
		line = ((con.current + l) % con.totallines) * con.rowwidth;

		for (j = CON_TIMESTAMP_LEN ; j < con.rowwidth - 1 ; j++)
			if (con.text[line + j].f.character != CON_BLANK_CHAR)
				empty = qfalse;
	}

	for ( ; l < con.totallines ; l++)
	{
		lineLen = 0;
		i = 0;

		// Print timestamp
		if (con_timestamps->integer) {
			line = ((con.current + l) % con.totallines) * con.rowwidth;

			for (i = 0; i < CON_TIMESTAMP_LEN; i++)
				buffer[i] = con.text[line + i].f.character;

			lineLen = CON_TIMESTAMP_LEN;
		}

		// Concatenate wrapped lines
		for ( ; l < con.totallines ; l++)
		{
			line = ((con.current + l) % con.totallines) * con.rowwidth;

			for (j = CON_TIMESTAMP_LEN; j < con.rowwidth - 1 && i < (int)sizeof(buffer) - 1; j++, i++) {
				buffer[i] = con.text[line + j].f.character;

				if (con.text[line + j].f.character != CON_BLANK_CHAR)
					lineLen = i + 1;
			}

			if (i == sizeof(buffer) - 1)
				break;

			if (con.text[line + j].compare != CON_WRAP.compare)
				break;
		}

#ifdef WIN32 // I really don't like this inconsistency, but OpenJK has been doing this since April 2013
		buffer[lineLen] = '\r';
		buffer[lineLen+1] = '\n';
		FS_Write(buffer, lineLen + 2, f);
#else
		buffer[lineLen] = '\n';
		FS_Write(buffer, lineLen + 1, f);
#endif
	}

	FS_FCloseFile( f );
}


/*
================
Con_ClearNotify
================
*/
void Con_ClearNotify( void ) {
	int		i;

	for ( i = 0 ; i < NUM_CON_TIMES ; i++ ) {
		con.times[i] = 0;
	}
}

/*
================
Con_Initialize

Initialize console for the first time.
================
*/
void Con_Initialize(void)
{
	int	i;

	VectorCopy4(colorWhite, con.color);
	con.charWidth = SMALLCHAR_WIDTH;
	con.charHeight = SMALLCHAR_HEIGHT;
	con.linewidth = DEFAULT_CONSOLE_WIDTH;
	con.rowwidth = CON_TIMESTAMP_LEN + con.linewidth + 1;
	con.totallines = CON_TEXTSIZE / con.rowwidth;
	con.current = con.totallines - 1;
	con.display = con.current;
	con.xadjust = 1.0f;
	con.yadjust = 1.0f;
	for(i=0; i<CON_TEXTSIZE; i++)
	{
		con.text[i] = CON_BLANK;
	}

	con.initialized = qtrue;
}



/*
================
Con_Resize

Reformat the buffer for new row width
================
*/
static void Con_Resize(int rowwidth)
{
	static conChar_t tbuf[CON_TEXTSIZE];
	int		i, j;
	int		oldrowwidth;
	int		oldtotallines;

	oldrowwidth = con.rowwidth;
	oldtotallines = con.totallines;

	con.rowwidth = rowwidth;
	con.totallines = CON_TEXTSIZE / rowwidth;

	Com_Memcpy (tbuf, con.text, sizeof(tbuf));
	for(i=0; i<CON_TEXTSIZE; i++)
		con.text[i] = CON_BLANK;

	int oi = 0;
	int ni = 0;

	while (oi < oldtotallines)
		{
			conChar_t	line[MAXPRINTMSG];
			conChar_t	timestamp[CON_TIMESTAMP_LEN];
			int		lineLen = 0;
			int		oldline = ((con.current + oi) % oldtotallines) * oldrowwidth;
			int		newline = (ni % con.totallines) * con.rowwidth;

			// Store timestamp
			for (i = 0; i < CON_TIMESTAMP_LEN; i++)
				timestamp[i] = tbuf[oldline + i];

			// Store whole line concatenating on CON_WRAP
			for (i = 0; oi < oldtotallines; oi++)
				{
					oldline = ((con.current + oi) % oldtotallines) * oldrowwidth;

					for (j = CON_TIMESTAMP_LEN; j < oldrowwidth - 1 && i < (int)ARRAY_LEN(line); j++, i++) {
						line[i] = tbuf[oldline + j];

						if (line[i].f.character != CON_BLANK_CHAR)
							lineLen = i + 1;
					}

					if (i == ARRAY_LEN(line))
						break;

					if (tbuf[oldline + j].compare != CON_WRAP.compare)
						break;
				}

			oi++;

			// Print stored line to a new text buffer
			for (i = 0; ; ni++) {
				newline = (ni % con.totallines) * con.rowwidth;

				// Print timestamp at the begining of each line
				for (j = 0; j < CON_TIMESTAMP_LEN; j++)
					con.text[newline + j] = timestamp[j];

				for (j = CON_TIMESTAMP_LEN; j < con.rowwidth - 1 && i < lineLen; j++, i++)
					con.text[newline + j] = line[i];

				if (i == lineLen) {
					// Erase remaining chars in case newline wrapped
					for (; j < con.rowwidth - 1; j++)
						con.text[newline + j] = CON_BLANK;

					ni++;
					break;
				}

				con.text[newline + j] = CON_WRAP;
			}
		}

	con.current = ni;

	// Erase con.current line for next CL_ConsolePrint
	int newline = (con.current % con.totallines) * con.rowwidth;
	for (j = 0; j < con.rowwidth; j++)
		con.text[newline + j] = CON_BLANK;

	Con_ClearNotify ();

	con.display = con.current;
}

/*
================
Con_CheckResize

If the line width has changed, reformat the buffer.
================
*/
void Con_CheckResize (void)
{
	int		charWidth, rowwidth, width;
	float	scale;

	assert(SMALLCHAR_HEIGHT >= SMALLCHAR_WIDTH);

	scale = ((con_scale->value > 0.0f) ? con_scale->value : 1.0f);
	charWidth = scale * SMALLCHAR_WIDTH;

	if (charWidth < 1) {
		charWidth = 1;
		scale = (float)charWidth / SMALLCHAR_WIDTH;
	}

	width = (cls.glconfig.vidWidth / charWidth) - 2;

	if (width < 20) {
		width = 20;
		charWidth = cls.glconfig.vidWidth / 22;
		scale = (float)charWidth / SMALLCHAR_WIDTH;
	}

	if (charWidth < 1) {
		Com_Error(ERR_FATAL, "Con_CheckResize: Window too small to draw a console");
	}

	rowwidth = width + 1 + (con_timestamps->integer ? 0 : CON_TIMESTAMP_LEN);

	con.charWidth = charWidth;
	con.charHeight = scale * SMALLCHAR_HEIGHT;
	con.linewidth = width;
	con.xadjust = ((float)SCREEN_WIDTH) / cls.glconfig.vidWidth;
	con.yadjust = ((float)SCREEN_HEIGHT) / cls.glconfig.vidHeight;
	g_consoleField.widthInChars = width - 1; // Command prompt

	if (con.rowwidth != rowwidth)
	{
		Con_Resize(rowwidth);
	}
}


/*
==================
Cmd_CompleteTxtName
==================
*/
void Cmd_CompleteTxtName( char *args, int argNum ) {
	if ( argNum == 2 )
		Field_CompleteFilename( "", "txt", qfalse, qtrue );
}

/*
================
Con_Init
================
*/

void Con_Init (void) {
	int		i;

	con_notifytime = Cvar_Get ("con_notifytime", "3", 0, "How many seconds notify messages should be shown before they fade away");
	con_notifylines = Cvar_Get("con_notifylines", "3", CVAR_ARCHIVE_ND, "Max number of console lines to print in top left");
	con_conspeed = Cvar_Get ("scr_conspeed", "3", 0, "Console open/close speed");
	Cvar_CheckRange (con_conspeed, 1.0f, 100.0f, qfalse);

	con_scale = Cvar_Get("con_scale", "1.0", CVAR_ARCHIVE_ND, "Console character scale");
	Cvar_CheckRange(con_scale, 0.2, 10.0f, qfalse);

	con_opacity = Cvar_Get ("con_opacity", "1.0", CVAR_ARCHIVE_ND, "Opacity of console background");
	con_ratioFix = Cvar_Get("con_ratioFix", "1", CVAR_ARCHIVE_ND, "Correct console background height, should probably disable for custom console backgrounds.");
	con_autoclear = Cvar_Get ("con_autoclear", "1", CVAR_ARCHIVE_ND, "Automatically clear console input on close");
	con_notifywords = Cvar_Get("con_notifywords", "0", CVAR_ARCHIVE, "Notifies you when defined words are mentioned");
	con_notifyconnect = Cvar_Get("con_notifyconnect", "0", CVAR_ARCHIVE, "Notifies you when someone connects to the server");
	con_notifyvote = Cvar_Get("con_notifyvote", "1", CVAR_ARCHIVE, "Notifies you when someone calls a vote");
	con_height = Cvar_Get ("con_height", "0.5", CVAR_ARCHIVE_ND, "Adjust the height of the console");

	con_scale = Cvar_Get ("con_scale", "1", CVAR_ARCHIVE_ND, "Scale console font");
	con_timestamps = Cvar_Get ("con_timestamps", "0", CVAR_ARCHIVE_ND, "Display timestamps infront of console lines");

	Field_Clear( &g_consoleField );
	g_consoleField.widthInChars = DEFAULT_CONSOLE_WIDTH;
	for ( i = 0 ; i < COMMAND_HISTORY ; i++ ) {
		Field_Clear( &historyEditLines[i] );
		historyEditLines[i].widthInChars = DEFAULT_CONSOLE_WIDTH;
	}

	Cmd_AddCommand( "toggleconsole", Con_ToggleConsole_f, "Show/hide console" );
	Cmd_AddCommand( "togglemenu", Con_ToggleMenu_f, "Show/hide the menu" );
	Cmd_AddCommand( "messagemode", Con_MessageMode_f, "Global Chat" );
	Cmd_AddCommand( "messagemode2", Con_MessageMode2_f, "Team Chat" );
	Cmd_AddCommand( "messagemode3", Con_MessageMode3_f, "Private Chat with Target Player" );
	Cmd_AddCommand( "messagemode4", Con_MessageMode4_f, "Private Chat with Last Attacker" );
	Cmd_AddCommand( "clear", Con_Clear_f, "Clear console text" );
	Cmd_AddCommand( "condump", Con_Dump_f, "Dump console text to file" );
	Cmd_SetCommandCompletionFunc( "condump", Cmd_CompleteTxtName );

	//Initialize values on first print
	con.initialized = qfalse;
}

/*
================
Con_Shutdown
================
*/
void Con_Shutdown(void)
{
	Cmd_RemoveCommand("toggleconsole");
	Cmd_RemoveCommand("togglemenu");
	Cmd_RemoveCommand("messagemode");
	Cmd_RemoveCommand("messagemode2");
	Cmd_RemoveCommand("messagemode3");
	Cmd_RemoveCommand("messagemode4");
	Cmd_RemoveCommand("clear");
	Cmd_RemoveCommand("condump");
}

/*
===============
Con_Linefeed
===============
*/
int stampColor = COLOR_GREY;
static void Con_Linefeed (qboolean skipnotify)
{
	int		i;
	int		line = (con.current % con.totallines) * con.rowwidth;

	// print timestamp on the PREVIOUS line
	{
		time_t t = time( NULL );
		struct tm *tms = localtime( &t );
		char	timestamp[CON_TIMESTAMP_LEN + 1];
		const unsigned char color = ColorIndex(COLOR_GREY);

		Com_sprintf(timestamp, sizeof(timestamp), "[%02d:%02d:%02d] ",
			tms->tm_hour, tms->tm_min, tms->tm_sec);

		for ( i = 0; i < CON_TIMESTAMP_LEN; i++ ) {
			con.text[line + i].f = { color, timestamp[i] };
		}
	}

	// mark time for transparent overlay
	if (con.current >= 0)
		con.times[con.current % NUM_CON_TIMES] = skipnotify ? 0 : cls.realtime;

	con.x = 0;

	if (con.display == con.current)
		con.display++;
	con.current++;

	line = (con.current % con.totallines) * con.rowwidth;

	for ( i = 0; i < con.rowwidth; i++ )
		con.text[line + i] = CON_BLANK;
}

/*
================
CL_ConsolePrint

Handles cursor positioning, line wrapping, etc
All console printing must go through this in order to be logged to disk
If no console is visible, the text will appear at the top of the game window
================
*/
void CL_ConsolePrint( const char *txt) {
	int		y;
	char			c;
	unsigned char	color;
	qboolean skipnotify = qfalse;		// NERVE - SMF
	int prev;							// NERVE - SMF

	// for some demos we don't want to ever show anything on the console
	if (cl_noprint && cl_noprint->integer) {
		return;
	}

	// TTimo - prefix for text that shows up in console but not in notify
	// backported from RTCW
	if ( !Q_strncmp( txt, "[skipnotify]", 12 ) ) {
		skipnotify = qtrue;
		txt += 12;
	}
	if (txt[0] == '*') {
		skipnotify = qtrue;
		txt += 1;
	}

	if (!con.initialized) {
		Con_Initialize();
	}

	color = ColorIndex(COLOR_WHITE);
	while ( (c = (unsigned char) *txt) != 0 ) {
		if ( Q_IsColorString( (unsigned char*) txt ) ) {
			color = ColorIndex( *(txt+1) );
			txt += 2;
			continue;
		}

		txt++;
		switch (c)
		{
		case '\n':
			Con_Linefeed (skipnotify);
			break;
		case '\r':
			con.x = CON_TIMESTAMP_LEN;
			break;
		default:	// display character and advance
			y = con.current % con.totallines;

			if (con.x == con.rowwidth - CON_TIMESTAMP_LEN - 1) {
				con.text[y * con.rowwidth + CON_TIMESTAMP_LEN + con.x] = CON_WRAP;
				Con_Linefeed( skipnotify );
				y = con.current % con.totallines;
			}

			con.text[y * con.rowwidth + CON_TIMESTAMP_LEN + con.x].f = { color, c };
			con.x++;
			break;
		}
	}

	// mark time for transparent overlay
	if (con.current >= 0 )
	{
		// NERVE - SMF
		if ( skipnotify ) {
			prev = con.current % NUM_CON_TIMES - 1;
			if ( prev < 0 )
				prev = NUM_CON_TIMES - 1;
			con.times[prev] = 0;
		}
		else
		// -NERVE - SMF
			con.times[con.current % NUM_CON_TIMES] = cls.realtime;
	}

	stampColor = COLOR_GREY;
}


/*
==============================================================================

DRAWING

==============================================================================
*/


/*
================
Con_DrawInput

Draw the editline after a ] prompt
================
*/
void Con_DrawInput (void) {
	int		y, x;
	char ts[CON_TIMESTAMP_LEN];
	qtime_t	now;

	if ( cls.state != CA_DISCONNECTED && !(Key_GetCatcher( ) & KEYCATCH_CONSOLE ) ) {
		return;
	}

	y = con.vislines - ( con.charHeight * (re->Language_IsAsian() ? 1.5 : 2) );

	Com_RealTime(&now);
	Com_sprintf(ts, sizeof(ts), "[%02d:%02d:%02d]", now.tm_hour, now.tm_min, now.tm_sec);

	re->SetColor(g_color_table[ColorIndex(COLOR_GREY)]);
	for (x = 0; x<CON_TIMESTAMP_LEN-1; x++) {
		SCR_DrawSmallChar(con.xadjust + (x + 1) * con.charWidth, y, ts[x]);
	}
	x = CON_TIMESTAMP_LEN;

	re->SetColor( con.color );

	Field_Draw( &g_consoleField, con.xadjust + (x+1) * con.charWidth, y, qtrue, qtrue );

	re->SetColor( g_color_table[ColorIndex(COLOR_GREY)] );

	if ( g_consoleField.scroll > 0 )
		SCR_DrawSmallChar( 0, y, CON_SCROLL_L_CHAR );

	int len = Q_PrintStrlen( g_consoleField.buffer );
	int pos = Q_PrintStrLenTo( g_consoleField.buffer, g_consoleField.scroll, NULL );
	if ( pos + g_consoleField.widthInChars < len )
		SCR_DrawSmallChar( cls.glconfig.vidWidth - con.charWidth, y, CON_SCROLL_R_CHAR );
}



float chatColour[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // For DrawStringExt2
/*
================
Con_DrawNotify

Draws the last few lines of output transparently over the game top
================
*/
void Con_DrawNotify (void)
{
	int		x, v;
	conChar_t		*text;
	int		i;
	int		time;
	int		skip;
	int		currentColor;
	const char* chattext;

	currentColor = 7;
	re->SetColor( g_color_table[currentColor] );

	static int iFontIndex = re->RegisterFont("ocr_a");
	float fFontScale = 1.0f;
	int iPixelHeightToAdvance = 0;
	if (re->Language_IsAsian())
	{
		fFontScale = con.charWidth * 10.0f /
			re->Font_StrLenPixels("aaaaaaaaaa", iFontIndex, 1.0f);
		fFontScale *= con.yadjust;
		iPixelHeightToAdvance = 2+(1.3/con.yadjust) * re->Font_HeightPixels(iFontIndex, fFontScale);
	}

	v = 0;
	for (i= con.current-con_notifylines->integer ; i<=con.current ; i++)
	{
		if (i < 0)
			continue;
		time = con.times[i % NUM_CON_TIMES];
		if (time == 0)
			continue;
		time = cls.realtime - time;
		if (time > con_notifytime->value*1000)
			continue;
		text = con.text + (i % con.totallines)*con.rowwidth;
		if (!con_timestamps->integer)
			text += CON_TIMESTAMP_LEN;

		if (cl.snap.ps.pm_type != PM_INTERMISSION && Key_GetCatcher( ) & (KEYCATCH_UI | KEYCATCH_CGAME) ) {
			continue;
		}


		if (!cl_conXOffset)
		{
			cl_conXOffset = Cvar_Get ("cl_conXOffset", "0", 0);
		}

		// asian language needs to use the new font system to print glyphs...
		//
		// (ignore colours since we're going to print the whole thing as one string)
		//
		if (re->Language_IsAsian())
		{
			// concat the text to be printed...
			//
			char sTemp[4096];	// ott
			sTemp[0] = '\0';
			for (x = 0 ; x < con.linewidth ; x++)
			{
				if ( text[x].f.color != currentColor ) {
					currentColor = text[x].f.color;
					strcat(sTemp,va("^%i", currentColor ));
				}
				strcat(sTemp,va("%c",text[x].f.character));
			}
			//
			// and print...
			//
			re->Font_DrawString(cl_conXOffset->integer + con.xadjust * (con.xadjust + con.charWidth), con.yadjust * v, sTemp,
				g_color_table[currentColor], iFontIndex, -1, fFontScale);

			v +=  iPixelHeightToAdvance;
		}
		else
		{
			for (x = 0 ; x < con.linewidth ; x++) {
				if ( text[x].f.character == CON_BLANK_CHAR ) {
					continue;
				}
				if ( text[x].f.color != currentColor ) {
					currentColor = text[x].f.color;
					re->SetColor( g_color_table[currentColor] );
				}
				if (!cl_conXOffset)
				{
					cl_conXOffset = Cvar_Get ("cl_conXOffset", "0", 0);
				}
				SCR_DrawSmallChar( (int)(cl_conXOffset->integer + (x+1)*con.charWidth), v, text[x].f.character );
			}

			v += con.charHeight;
		}
	}

	re->SetColor( NULL );

	if (Key_GetCatcher( ) & (KEYCATCH_UI | KEYCATCH_CGAME) ) {
		return;
	}

	// draw the chat line
	if ( Key_GetCatcher( ) & KEYCATCH_MESSAGE )
	{
		if (chat_playerNum != -1) {
			chattext = "Whisper:";
		}
		else if (chat_team)	{
			chattext = SE_GetString("MP_SVGAME", "SAY_TEAM");
		}
		else {
			chattext = SE_GetString("MP_SVGAME", "SAY");
		}

		SCR_DrawStringExt2(8 * cls.widthRatioCoef, v, BIGCHAR_WIDTH*cls.widthRatioCoef, BIGCHAR_HEIGHT, chattext, chatColour, qfalse, qfalse);
		skip = strlen(chattext) + 1;
		Field_BigDraw( &chatField, skip * BIGCHAR_WIDTH, v,
			SCREEN_WIDTH - ( skip + 1 ) * BIGCHAR_WIDTH, qtrue, qtrue );

		v += BIGCHAR_HEIGHT;
	}

}

/*
================
Con_DrawSolidConsole

Draws the console with the solid background
================
*/
void Con_DrawSolidConsole( float frac ) {
	int				i, x, y;
	int				rows;
	conChar_t		*text;
	int				row;
	int				lines;
	int				currentColor;

	lines = (int) (cls.glconfig.vidHeight * frac);
	if (lines <= 0)
		return;

	if (lines > cls.glconfig.vidHeight )
		lines = cls.glconfig.vidHeight;

	// draw the background
	y = (int) (frac * SCREEN_HEIGHT - 2);
	if ( y < 1 ) {
		y = 0;
	}
	else {
		// draw the background at full opacity only if fullscreen
		if (frac < 1.0f)
		{
			vec4_t con_color;
			MAKERGBA(con_color, 1.0f, 1.0f, 1.0f, Com_Clamp(0.0f, 1.0f, con_opacity->value));
			re->SetColor(con_color);
		}
		else
		{
			re->SetColor(NULL);
		}

		//re->DrawStretchPic(0, 0, SCREEN_WIDTH, (float)y, 0, 0 + (cls.widthRatioCoef / 4), 1, 1 - (cls.widthRatioCoef / 4), cls.consoleShader);
		if (con_ratioFix->integer && frac <= 0.5f && cls.widthRatioCoef < 1.0f) // && cls.widthRatioCoef < 1.0f)
			re->DrawStretchPic(0, 0, SCREEN_WIDTH, (float)y, 0, 1 - cls.widthRatioCoef, 1, 0 + cls.widthRatioCoef, cls.consoleShader);
		else
			re->DrawStretchPic(0, 0, SCREEN_WIDTH, (float)y, 0, 0, 1, 1, cls.consoleShader);
	}

	// draw the bottom bar and version number

	re->SetColor( console_color );
	re->DrawStretchPic( 0, y, SCREEN_WIDTH, 2, 0, 0, 0, 0, cls.whiteShader );

	i = strlen( JK_VERSION );

	for (x=0 ; x<i ; x++) {
		SCR_DrawSmallChar( cls.glconfig.vidWidth - ( i - x + 1 ) * con.charWidth,
			(lines-(con.charHeight+con.charHeight/2)), JK_VERSION[x] );
	}

	// draw the input prompt, user text, and cursor if desired
	Con_DrawInput ();

	/*
	// Draw time and date
	time(&rawtime);
	newtime = localtime(&rawtime);
	if (newtime->tm_hour >= 12) AM = qfalse;
	if (newtime->tm_hour > 12) newtime->tm_hour -= 12;
	if (newtime->tm_hour == 0) newtime->tm_hour = 12;
	Com_sprintf(ts, sizeof(ts), "%.19s %s ", asctime(newtime), AM ? "AM" : "PM" );
	i = strlen(ts);

	for (x = 0; x<i; x++) {
		SCR_DrawSmallChar(cls.glconfig.vidWidth - (i - x) * con.charWidth, lines - (con.charHeight + con.charHeight / 2), ts[x]);
	}*/

	// draw the text
	con.vislines = lines;
	rows = (lines-con.charHeight)/con.charHeight;		// rows of text to draw

	y = lines - (con.charHeight*3);

	// draw from the bottom up
	if (con.display != con.current)
	{
	// draw arrows to show the buffer is backscrolled
		re->SetColor( console_color );
		for (x=0 ; x<con.linewidth ; x+=4)
			SCR_DrawSmallChar( (x+1)*con.charWidth, y, '^' );
		y -= con.charHeight;
		rows--;
	}

	row = con.display;

	if ( con.x == 0 ) {
		row--;
	}

	currentColor = 7;
	re->SetColor( g_color_table[currentColor] );

	static int iFontIndex = re->RegisterFont("ocr_a");
	float fFontScale = 1.0f;
	int iPixelHeightToAdvance = con.charHeight;
	if (re->Language_IsAsian())
	{
		fFontScale = con.charWidth * 10.0f /
			re->Font_StrLenPixels("aaaaaaaaaa", iFontIndex, 1.0f);
		fFontScale *= con.yadjust;
		iPixelHeightToAdvance = 2+(1.3/con.yadjust) * re->Font_HeightPixels(iFontIndex, fFontScale);
	}

	for (i=0 ; i<rows ; i++, y -= iPixelHeightToAdvance, row--)
	{
		if (row < 0)
			break;
		if (con.current - row >= con.totallines) {
			// past scrollback wrap point
			continue;
		}

		text = con.text + (row % con.totallines)*con.rowwidth;
		if (!con_timestamps->integer)
			text += CON_TIMESTAMP_LEN;

		// asian language needs to use the new font system to print glyphs...
		//
		// (ignore colours since we're going to print the whole thing as one string)
		//
		if (re->Language_IsAsian())
		{
			// concat the text to be printed...
			//
			char sTemp[4096];	// ott
			sTemp[0] = '\0';
			for (x = 0 ; x < con.linewidth + 1 ; x++)
			{
				if ( text[x].f.color != currentColor ) {
					currentColor = text[x].f.color;
					strcat(sTemp,va("^%i", currentColor ));
				}
				strcat(sTemp,va("%c",text[x].f.character));
			}
			//
			// and print...
			//
			re->Font_DrawString(con.xadjust*(con.xadjust + con.charWidth), con.yadjust * y, sTemp, g_color_table[currentColor],
				iFontIndex, -1, fFontScale);
		}
		else
		{
			for (x = 0; x < con.linewidth + 1 ; x++) {
				if ( text[x].f.character == CON_BLANK_CHAR ) {
					continue;
				}

				if ( text[x].f.color != currentColor ) {
					currentColor = text[x].f.color;
					re->SetColor( g_color_table[currentColor] );
				}
				SCR_DrawSmallChar( (x+1)*con.charWidth, y, text[x].f.character );
			}
		}
	}

	re->SetColor( NULL );
}



/*
==================
Con_DrawConsole
==================
*/
void Con_DrawConsole( void ) {
	// check for console width changes from a vid mode change
	Con_CheckResize ();

	// if disconnected, render console full screen
	if ( cls.state == CA_DISCONNECTED ) {
		if ( !( Key_GetCatcher( ) & (KEYCATCH_UI | KEYCATCH_CGAME)) ) {
			Con_DrawSolidConsole( 1.0 );
			return;
		}
	}

	if ( con.displayFrac ) {
		Con_DrawSolidConsole( con.displayFrac );
	} else {
		// draw notify lines
		if ( cls.state == CA_ACTIVE ) {
			Con_DrawNotify ();
		}
	}
}

//================================================================

/*
==================
Con_RunConsole

Scroll it up or down
==================
*/
void Con_RunConsole (void) {
	// decide on the destination height of the console
	if ( Key_GetCatcher( ) & KEYCATCH_CONSOLE )
		con.finalFrac = (con_height->value != 0) ? con_height->value : con.tempFrac;
	else
		con.finalFrac = 0;				// none visible

	// scroll towards the destination height
	if (con.finalFrac < con.displayFrac)
	{
		con.displayFrac -= con_conspeed->value*(float)(cls.realFrametime*0.001);
		if (con.finalFrac > con.displayFrac)
			con.displayFrac = con.finalFrac;

	}
	else if (con.finalFrac > con.displayFrac)
	{
		con.displayFrac += con_conspeed->value*(float)(cls.realFrametime*0.001);
		if (con.finalFrac < con.displayFrac)
			con.displayFrac = con.finalFrac;
	}

}

void Con_SetFrac(const float conFrac) {
	con.tempFrac = conFrac;
}

void Con_PageUp( void ) {
	con.display -= 2;
	if ( con.current - con.display >= con.totallines ) {
		con.display = con.current - con.totallines + 1;
	}
}

void Con_PageDown( void ) {
	con.display += 2;
	if (con.display > con.current) {
		con.display = con.current;
	}
}

void Con_Top( void ) {
	con.display = con.totallines;
	if ( con.current - con.display >= con.totallines ) {
		con.display = con.current - con.totallines + 1;
	}
}

void Con_Bottom( void ) {
	con.display = con.current;
}


void Con_Close( void ) {
	if ( !com_cl_running->integer ) {
		return;
	}
	Field_Clear( &g_consoleField );
	Con_ClearNotify ();
	Key_SetCatcher( Key_GetCatcher( ) & ~KEYCATCH_CONSOLE );
	con.finalFrac = 0;				// none visible
	con.displayFrac = 0;
}
