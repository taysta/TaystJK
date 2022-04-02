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

// q_shared.c -- stateless support routines that are included in each code dll
#include "q_shared.h"

/*
-------------------------
GetIDForString
-------------------------
*/


int GetIDForString ( stringID_table_t *table, const char *string )
{
	int	index = 0;

	while ( ( table[index].name != NULL ) &&
			( table[index].name[0] != 0 ) )
	{
		if ( !Q_stricmp( table[index].name, string ) )
			return table[index].id;

		index++;
	}

	return -1;
}

/*
-------------------------
GetStringForID
-------------------------
*/

const char *GetStringForID( stringID_table_t *table, int id )
{
	int	index = 0;

	while ( ( table[index].name != NULL ) &&
			( table[index].name[0] != 0 ) )
	{
		if ( table[index].id == id )
			return table[index].name;

		index++;
	}

	return NULL;
}

/*
============
COM_SkipPath
============
*/
char *COM_SkipPath (char *pathname)
{
	char	*last;

	last = pathname;
	while (*pathname)
	{
		if (*pathname=='/')
			last = pathname+1;
		pathname++;
	}
	return last;
}

/*
============
COM_GetExtension
============
*/
const char *COM_GetExtension( const char *name )
{
	const char *dot = strrchr(name, '.'), *slash;
	if (dot && (!(slash = strrchr(name, '/')) || slash < dot))
		return dot + 1;
	else
		return "";
}

/*
============
COM_StripExtension
============
*/
void COM_StripExtension( const char *in, char *out, int destsize )
{
	const char *dot = strrchr(in, '.'), *slash;
	if (dot && (!(slash = strrchr(in, '/')) || slash < dot))
		destsize = (destsize < dot-in+1 ? destsize : dot-in+1);

	if ( in == out && destsize > 1 )
		out[destsize-1] = '\0';
	else
		Q_strncpyz(out, in, destsize);
}

/*
============
COM_CompareExtension

string compare the end of the strings and return qtrue if strings match
============
*/
qboolean COM_CompareExtension(const char *in, const char *ext)
{
	int inlen, extlen;

	inlen = strlen(in);
	extlen = strlen(ext);

	if(extlen <= inlen)
	{
		in += inlen - extlen;

		if(!Q_stricmp(in, ext))
			return qtrue;
	}

	return qfalse;
}

/*
==================
COM_DefaultExtension
==================
*/
void COM_DefaultExtension( char *path, int maxSize, const char *extension )
{
	const char *dot = strrchr(path, '.'), *slash;
	if (dot && (!(slash = strrchr(path, '/')) || slash < dot))
		return;
	else
		Q_strcat(path, maxSize, extension);
}

/*
============================================================================

PARSING

============================================================================
*/

static	char	com_token[MAX_TOKEN_CHARS];
static	char	com_parsename[MAX_TOKEN_CHARS];
static	int		com_lines;
static	int		com_tokenline;

void COM_BeginParseSession( const char *name )
{
	com_lines = 1;
	com_tokenline = 0;
	Com_sprintf(com_parsename, sizeof(com_parsename), "%s", name);
}

int COM_GetCurrentParseLine( void )
{
	if ( com_tokenline )
	{
		return com_tokenline;
	}

	return com_lines;
}

char *COM_Parse( const char **data_p )
{
	return COM_ParseExt( data_p, qtrue );
}

void COM_ParseError( char *format, ... )
{
	va_list argptr;
	static char string[4096];

	va_start (argptr, format);
	Q_vsnprintf (string, sizeof( string ), format, argptr);
	va_end (argptr);

	Com_Printf("ERROR: %s, line %d: %s\n", com_parsename, COM_GetCurrentParseLine(), string);
}

void COM_ParseWarning( char *format, ... )
{
	va_list argptr;
	static char string[4096];

	va_start (argptr, format);
	Q_vsnprintf (string, sizeof(string), format, argptr);
	va_end (argptr);

	Com_Printf("WARNING: %s, line %d: %s\n", com_parsename, COM_GetCurrentParseLine(), string);
}

/*
==============
COM_Parse

Parse a token out of a string
Will never return NULL, just empty strings

If "allowLineBreaks" is qtrue then an empty
string will be returned if the next token is
a newline.
==============
*/
const char *SkipWhitespace( const char *data, qboolean *hasNewLines ) {
	int c;

	while( (c = *(const unsigned char* /*eurofix*/)data) <= ' ') {
		if( !c ) {
			return NULL;
		}
		if( c == '\n' ) {
			com_lines++;
			*hasNewLines = qtrue;
		}
		data++;
	}

	return data;
}

int COM_Compress( char *data_p ) {
	char *in, *out;
	int c;
	qboolean newline = qfalse, whitespace = qfalse;

	in = out = data_p;
	if (in) {
		while ((c = *in) != 0) {
			// skip double slash comments
			if ( c == '/' && in[1] == '/' ) {
				while (*in && *in != '\n') {
					in++;
				}
			// skip /* */ comments
			} else if ( c == '/' && in[1] == '*' ) {
				while ( *in && ( *in != '*' || in[1] != '/' ) )
					in++;
				if ( *in )
					in += 2;
				// record when we hit a newline
			} else if ( c == '\n' || c == '\r' ) {
				newline = qtrue;
				in++;
				// record when we hit whitespace
			} else if ( c == ' ' || c == '\t') {
				whitespace = qtrue;
				in++;
				// an actual token
			} else {
				// if we have a pending newline, emit it (and it counts as whitespace)
				if (newline) {
					*out++ = '\n';
					newline = qfalse;
					whitespace = qfalse;
				} if (whitespace) {
					*out++ = ' ';
					whitespace = qfalse;
				}

				// copy quoted strings unmolested
				if (c == '"') {
					*out++ = c;
					in++;
					while (1) {
						c = *in;
						if (c && c != '"') {
							*out++ = c;
							in++;
						} else {
							break;
						}
					}
					if (c == '"') {
						*out++ = c;
						in++;
					}
				} else {
					*out = c;
					out++;
					in++;
				}
			}
		}

		*out = 0;
	}
	return out - data_p;
}

char *COM_ParseExt( const char **data_p, qboolean allowLineBreaks )
{
	int c = 0, len;
	qboolean hasNewLines = qfalse;
	const char *data;

	data = *data_p;
	len = 0;
	com_token[0] = 0;
	com_tokenline = 0;

	// make sure incoming data is valid
	if ( !data )
	{
		*data_p = NULL;
		return com_token;
	}

	while ( 1 )
	{
		// skip whitespace
		data = SkipWhitespace( data, &hasNewLines );
		if ( !data )
		{
			*data_p = NULL;
			return com_token;
		}
		if ( hasNewLines && !allowLineBreaks )
		{
			*data_p = data;
			return com_token;
		}

		c = *data;

		// skip double slash comments
		if ( c == '/' && data[1] == '/' )
		{
			data += 2;
			while (*data && *data != '\n') {
				data++;
			}
		}
		// skip /* */ comments
		else if ( c=='/' && data[1] == '*' )
		{
			data += 2;
			while ( *data && ( *data != '*' || data[1] != '/' ) )
			{
				if ( *data == '\n' )
				{
					com_lines++;
				}
				data++;
			}
			if ( *data )
			{
				data += 2;
			}
		}
		else
		{
			break;
		}
	}

	// token starts on this line
	com_tokenline = com_lines;

	// handle quoted strings
	if (c == '\"')
	{
		data++;
		while (1)
		{
			c = *data++;
			if (c=='\"' || !c)
			{
				com_token[len] = 0;
				*data_p = ( char * ) data;
				return com_token;
			}
			if ( c == '\n' )
			{
				com_lines++;
			}
			if (len < MAX_TOKEN_CHARS - 1)
			{
				com_token[len] = c;
				len++;
			}
		}
	}

	// parse a regular word
	do
	{
		if (len < MAX_TOKEN_CHARS - 1)
		{
			com_token[len] = c;
			len++;
		}
		data++;
		c = *data;
	} while (c>32);

	com_token[len] = 0;

	*data_p = ( char * ) data;
	return com_token;
}

/*
===============
COM_ParseString
===============
*/
qboolean COM_ParseString( const char **data, const char **s )
{
//	*s = COM_ParseExt( data, qtrue );
	*s = COM_ParseExt( data, qfalse );
	if ( s[0] == 0 )
	{
		COM_ParseWarning( "COM_ParseString: unexpected EOF" );
		return qtrue;
	}
	return qfalse;
}

/*
===============
COM_ParseInt
===============
*/
qboolean COM_ParseInt( const char **data, int *i )
{
	const char	*token;

	token = COM_ParseExt( data, qfalse );
	if ( token[0] == 0 )
	{
		COM_ParseWarning( "COM_ParseInt: unexpected EOF" );
		return qtrue;
	}

	*i = atoi( token );
	return qfalse;
}

/*
===============
COM_ParseFloat
===============
*/
qboolean COM_ParseFloat( const char **data, float *f )
{
	const char	*token;

	token = COM_ParseExt( data, qfalse );
	if ( token[0] == 0 )
	{
		COM_ParseWarning( "COM_ParseFloat: unexpected EOF" );
		return qtrue;
	}

	*f = atof( token );
	return qfalse;
}

/*
===============
COM_ParseVec4
===============
*/
qboolean COM_ParseVec4( const char **buffer, vec4_t *c)
{
	int i;
	float f;

	for (i = 0; i < 4; i++)
	{
		if (COM_ParseFloat(buffer, &f))
		{
			return qtrue;
		}
		(*c)[i] = f;
	}
	return qfalse;
}

/*
==================
COM_MatchToken
==================
*/
void COM_MatchToken( const char **buf_p, char *match ) {
	char	*token;

	token = COM_Parse( buf_p );
	if ( strcmp( token, match ) ) {
		Com_Error( ERR_DROP, "MatchToken: %s != %s", token, match );
	}
}


/*
=================
SkipBracedSection

The next token should be an open brace or set depth to 1 if already parsed it.
Skips until a matching close brace is found.
Internal brace depths are properly skipped.
=================
*/
qboolean SkipBracedSection (const char **program, int depth) {
	char			*token;

	do {
		token = COM_ParseExt( program, qtrue );
		if( token[1] == 0 ) {
			if( token[0] == '{' ) {
				depth++;
			}
			else if( token[0] == '}' ) {
				depth--;
			}
		}
	} while( depth && *program );

	return (qboolean)( depth == 0 );
}

/*
=================
SkipRestOfLine
=================
*/
void SkipRestOfLine ( const char **data ) {
	const char	*p;
	int		c;

	p = *data;

	if ( !*p )
		return;

	while ( (c = *p++) != 0 ) {
		if ( c == '\n' ) {
			com_lines++;
			break;
		}
	}

	*data = p;
}


void Parse1DMatrix (const char **buf_p, int x, float *m) {
	char	*token;
	int		i;

	COM_MatchToken( buf_p, "(" );

	for (i = 0 ; i < x ; i++) {
		token = COM_Parse(buf_p);
		m[i] = atof(token);
	}

	COM_MatchToken( buf_p, ")" );
}

void Parse2DMatrix (const char **buf_p, int y, int x, float *m) {
	int		i;

	COM_MatchToken( buf_p, "(" );

	for (i = 0 ; i < y ; i++) {
		Parse1DMatrix (buf_p, x, m + i * x);
	}

	COM_MatchToken( buf_p, ")" );
}

void Parse3DMatrix (const char **buf_p, int z, int y, int x, float *m) {
	int		i;

	COM_MatchToken( buf_p, "(" );

	for (i = 0 ; i < z ; i++) {
		Parse2DMatrix (buf_p, y, x, m + i * x*y);
	}

	COM_MatchToken( buf_p, ")" );
}

/*
===================
Com_HexStrToInt
===================
*/
int Com_HexStrToInt( const char *str )
{
	if ( !str || !str[ 0 ] )
		return -1;

	// check for hex code
	if( str[ 0 ] == '0' && str[ 1 ] == 'x' )
	{
		int  n = 0;
		size_t i;

		for( i = 2; i < strlen( str ); i++ )
		{
			char digit;

			n *= 16;

			digit = tolower( str[ i ] );

			if( digit >= '0' && digit <= '9' )
				digit -= '0';
			else if( digit >= 'a' && digit <= 'f' )
				digit = digit - 'a' + 10;
			else
				return -1;

			n += digit;
		}

		return n;
	}

	return -1;
}

/*
============================================================================

					LIBRARY REPLACEMENT FUNCTIONS

============================================================================
*/

int QDECL Com_sprintf( char *dest, int size, const char *fmt, ...) {
	int		len;
	va_list		argptr;

	va_start (argptr,fmt);
	len = Q_vsnprintf(dest, size, fmt, argptr);
	va_end (argptr);

	if(len >= size)
		Com_Printf("Com_sprintf: Output length %d too short, require %d bytes.\n", size, len + 1);

	return len;
}

int FloatAsInt( float f ) {
	byteAlias_t fi;
	fi.f = f;
	return fi.i;
}

/*
============
va

does a varargs printf into a temp buffer, so I don't need to have
varargs versions of all text functions.
FIXME: make this buffer size safe someday
============
*/
#define	MAX_VA_STRING	32000
#define MAX_VA_BUFFERS 4

char * QDECL va( const char *format, ... )
{
	va_list		argptr;
	static char	string[MAX_VA_BUFFERS][MAX_VA_STRING];	// in case va is called by nested functions
	static int	index = 0;
	char		*buf;

	va_start( argptr, format );
	buf = (char *)&string[index++ & 3];
	Q_vsnprintf( buf, sizeof(*string), format, argptr );
	va_end( argptr );

	return buf;
}

/*
============
Com_TruncateLongString

Assumes buffer is atleast TRUNCATE_LENGTH big
============
*/
void Com_TruncateLongString( char *buffer, const char *s ) {
	int length = strlen( s );

	if ( length <= TRUNCATE_LENGTH )
		Q_strncpyz( buffer, s, TRUNCATE_LENGTH );
	else {
		Q_strncpyz( buffer, s, (TRUNCATE_LENGTH/2) - 3 );
		Q_strcat( buffer, TRUNCATE_LENGTH, " ... " );
		Q_strcat( buffer, TRUNCATE_LENGTH, s + length - (TRUNCATE_LENGTH/2) + 3 );
	}
}

/*
=====================================================================

  INFO STRINGS

=====================================================================
*/

/*
===============
Info_ValueForKey

Searches the string for the given
key and returns the associated value, or an empty string.
FIXME: overflow check?
===============
*/
char *Info_ValueForKey( const char *s, const char *key ) {
	char	pkey[BIG_INFO_KEY];
	static	char value[2][BIG_INFO_VALUE];	// use two buffers so compares
											// work without stomping on each other
	static	int	valueindex = 0;
	char	*o;

	if ( !s || !key ) {
		return "";
	}

	if ( strlen( s ) >= BIG_INFO_STRING ) {
		Com_Error( ERR_DROP, "Info_ValueForKey: oversize infostring" );
	}

	valueindex ^= 1;
	if (*s == '\\')
		s++;
	while (1)
	{
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
				return "";
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value[valueindex];

		while (*s != '\\' && *s)
		{
			*o++ = *s++;
		}
		*o = 0;

		if (!Q_stricmp (key, pkey) )
			return value[valueindex];

		if (!*s)
			break;
		s++;
	}

	return "";
}

/*
===================
Info_NextPair

Used to itterate through all the key/value pairs in an info string
Return qfalse if we discover the infostring is invalid
===================
*/
qboolean Info_NextPair( const char **head, char *key, char *value ) {
	char *o;
	const char *s = *head;

	if ( *s == '\\' )
		s++;
	key[0] = 0;
	value[0] = 0;

	o = key;
	while ( *s != '\\' ) {
		if ( !*s ) {
			key[0] = 0;
			*head  = s;
			return qtrue;
		}
		*o++ = *s++;
	}
	*o = 0;
	s++;

	// If they key is empty at this point with a slash after it
	// then this is considered invalid, possibly an attempt at hacked userinfo strings
	if ( !key[0] )
		return qfalse;

	o = value;
	while ( *s != '\\' && *s ) {
		*o++ = *s++;
	}
	*o = 0;

	*head = s;

	return qtrue;
}

/*
===================
Info_RemoveKey
===================
*/
void Info_RemoveKey( char *s, const char *key ) {
	char	*start = NULL, *o = NULL;
	char	pkey[MAX_INFO_KEY] = {0};
	char	value[MAX_INFO_VALUE] = {0};

	if ( strlen( s ) >= MAX_INFO_STRING ) {
		Com_Error( ERR_DROP, "Info_RemoveKey: oversize infostring" );
		return;
	}

	if (strchr (key, '\\')) {
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\')
			s++;
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;

		//OJKNOTE: static analysis pointed out pkey may not be null-terminated
		if (!strcmp (key, pkey) )
		{
			memmove(start, s, strlen(s) + 1);	// remove this part
			return;
		}

		if (!*s)
			return;
	}
}

/*
===================
Info_RemoveKey_Big
===================
*/
void Info_RemoveKey_Big( char *s, const char *key ) {
	char	*start;
	static char	pkey[BIG_INFO_KEY], value[BIG_INFO_VALUE];
	char	*o;

	pkey[0] = value[0] = '\0';

	if ( strlen( s ) >= BIG_INFO_STRING ) {
		Com_Error( ERR_DROP, "Info_RemoveKey_Big: oversize infostring" );
		return;
	}

	if (strchr (key, '\\')) {
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\')
			s++;
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;

		//OJKNOTE: static analysis pointed out pkey may not be null-terminated
		if (!strcmp (key, pkey) )
		{
			memmove(start, s, strlen(s) + 1);	// remove this part
			return;
		}

		if (!*s)
			return;
	}

}

/*
==================
Info_Validate

Some characters are illegal in info strings because they
can mess up the server's parsing
==================
*/
qboolean Info_Validate( const char *s ) {
	const char *c = s;

	while ( *c != '\0' )
	{
		if( !Q_isprint( *c ) )
			return qfalse;

		if( *c == '\"' )
			return qfalse;

		if( *c == ';' )
			return qfalse;

		++c;
	}

	return qtrue;
}

/*
==================
Info_SetValueForKey

Changes or adds a key/value pair
==================
*/
void Info_SetValueForKey( char *s, const char *key, const char *value ) {
	char	newi[MAX_INFO_STRING];
	const char* blacklist = "\\;\"";

	if ( strlen( s ) >= MAX_INFO_STRING ) {
		Com_Error( ERR_DROP, "Info_SetValueForKey: oversize infostring" );
	}

	for(; *blacklist; ++blacklist)
	{
		if (strchr (key, *blacklist) || strchr (value, *blacklist))
		{
			Com_Printf (S_COLOR_YELLOW "Can't use keys or values with a '%c': %s = %s\n", *blacklist, key, value);
			return;
		}
	}

	Info_RemoveKey (s, key);
	if (!value || !strlen(value))
		return;

	Com_sprintf (newi, sizeof(newi), "\\%s\\%s", key, value);

	if (strlen(newi) + strlen(s) >= MAX_INFO_STRING)
	{
		Com_Printf ("Info string length exceeded: %s\n", s);
		return;
	}

	strcat (newi, s);
	strcpy (s, newi);
}

/*
==================
Info_SetValueForKey_Big

Changes or adds a key/value pair
Includes and retains zero-length values
==================
*/
void Info_SetValueForKey_Big( char *s, const char *key, const char *value ) {
	char	newi[BIG_INFO_STRING];
	const char* blacklist = "\\;\"";

	if ( strlen( s ) >= BIG_INFO_STRING ) {
		Com_Error( ERR_DROP, "Info_SetValueForKey_Big: oversize infostring" );
	}

	for(; *blacklist; ++blacklist)
	{
		if (strchr (key, *blacklist) || strchr (value, *blacklist))
		{
			Com_Printf (S_COLOR_YELLOW "Can't use keys or values with a '%c': %s = %s\n", *blacklist, key, value);
			return;
		}
	}

	Info_RemoveKey_Big (s, key);
	if (!value)
		return;

	Com_sprintf (newi, sizeof(newi), "\\%s\\%s", key, value);

	if (strlen(newi) + strlen(s) >= BIG_INFO_STRING)
	{
		Com_Printf ("BIG Info string length exceeded\n");
		return;
	}

	strcat (s, newi);
}

/*
==================
Com_CharIsOneOfCharset
==================
*/
static qboolean Com_CharIsOneOfCharset( char c, char *set ) {
	size_t i;

	for ( i=0; i<strlen( set ); i++ ) {
		if ( set[i] == c )
			return qtrue;
	}

	return qfalse;
}

/*
==================
Com_SkipCharset
==================
*/
char *Com_SkipCharset( char *s, char *sep ) {
	char *p = s;

	while ( p ) {
		if ( Com_CharIsOneOfCharset( *p, sep ) )
			p++;
		else
			break;
	}

	return p;
}

/*
==================
Com_SkipTokens
==================
*/
char *Com_SkipTokens( char *s, int numTokens, char *sep ) {
	int sepCount = 0;
	char *p = s;

	while ( sepCount < numTokens ) {
		if ( Com_CharIsOneOfCharset( *p++, sep ) ) {
			sepCount++;
			while ( Com_CharIsOneOfCharset( *p, sep ) )
				p++;
		}
		else if ( *p == '\0' )
			break;
	}

	if ( sepCount == numTokens )
		return p;
	else
		return s;
}

qboolean Q_InBitflags( const uint32_t *bits, int index, uint32_t bitsPerByte ) {
	return ( bits[index / bitsPerByte] & (1 << (index % bitsPerByte)) ) ? qtrue : qfalse;
}

void Q_AddToBitflags( uint32_t *bits, int index, uint32_t bitsPerByte ) {
	bits[index / bitsPerByte] |= (1 << (index % bitsPerByte));
}

void Q_RemoveFromBitflags( uint32_t *bits, int index, uint32_t bitsPerByte ) {
	bits[index / bitsPerByte] &= ~(1 << (index % bitsPerByte));
}

void *Q_LinearSearch( const void *key, const void *ptr, size_t count,
	size_t size, cmpFunc_t cmp )
{
	size_t i;
	for ( i = 0; i < count; i++ )
	{
		if ( cmp( key, ptr ) == 0 ) return (void *)ptr;
		ptr = (const char *)ptr + size;
	}
	return NULL;
}
vec3_t defaultColors[10] =
        {
                {0.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f},
                {1.0f, 1.0f, 0.0f},
                {0.0f, 0.0f, 1.0f},
                {0.0f, 1.0f, 1.0f},
                {1.0f, 0.0f, 1.0f},
                {1.0f, 1.0f, 1.0f},
                {0.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
        };
vec3_t uagColors[43] =
        {
                { 0.000f, 0.000f, 0.000f }, // '0' 0x30 48:   0   0   0
                { 1.000f, 0.000f, 0.000f }, // '1' 0x31 49: 255   0   0
                { 0.000f, 1.000f, 0.000f }, // '2' 0x32 50:   0 255   0
                { 1.000f, 1.000f, 0.000f }, // '3' 0x33 51: 255 255   0
                { 0.000f, 0.000f, 1.000f }, // '4' 0x34 52:   0   0 255
                { 0.000f, 1.000f, 1.000f }, // '5' 0x35 53:   0 255 255
                { 1.000f, 0.000f, 1.000f }, // '6' 0x36 54: 255   0 255
                { 1.000f, 1.000f, 1.000f }, // '7' 0x37 55: 255 255 255
// '8'-'@' will be skipped, but '8' and '9' will appear in the console as black and red (as in original jamp)
                { 0.000f, 0.000f, 0.000f }, // '8' 0x38 56:   0   0   0
                { 1.000f, 0.000f, 0.000f }, // '9' 0x39 57: 255   0   0
                { 1.000f, 1.000f, 1.000f }, // ':' 0x3A 58: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // ';' 0x3B 59: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // '<' 0x3C 60: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // '=' 0x3D 61: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // '>' 0x3E 62: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // '?' 0x3F 63: 255 255 255
                { 1.000f, 1.000f, 1.000f }, // '@' 0x40 64: 255 255 255
// end of skip
                { 1.000f, 0.561f, 0.561f }, // 'A' 0x41 65: 255 143 143
                { 0.500f, 0.039f, 0.039f }, // 'B' 0x42 66: 127  10  10
                { 0.500f, 0.302f, 0.027f }, // 'C' 0x43 67: 127  77   7
                { 1.000f, 0.584f, 0.000f }, // 'D' 0x44 68: 255 149   0
                { 0.843f, 0.757f, 0.545f }, // 'E' 0x45 69: 215 193 139
                { 1.000f, 1.000f, 0.612f }, // 'F' 0x46 70: 255 255 156
                { 0.647f, 1.000f, 0.655f }, // 'G' 0x47 71: 165 255 167
                { 0.541f, 0.863f, 0.035f }, // 'H' 0x48 72: 138 220   9
                { 0.004f, 0.475f, 0.004f }, // 'I' 0x49 73:   1 121   1
                { 0.439f, 0.447f, 0.176f }, // 'J' 0x4A 74: 112 114  45
                { 0.388f, 0.490f, 0.321f }, // 'K' 0x4B 75:  99 125  82
                { 0.000f, 0.902f, 0.659f }, // 'L' 0x4C 76:   0 230 168
                { 0.612f, 0.996f, 1.000f }, // 'M' 0x4D 77: 156 254 255
                { 0.000f, 0.580f, 0.580f }, // 'N' 0x4E 78:   0 148 148
                { 0.321f, 0.482f, 0.510f }, // 'O' 0x4F 79:  82 123 130
                { 0.000f, 0.667f, 1.000f }, // 'P' 0x50 80:   0 170 255
                { 0.494f, 0.500f, 1.000f }, // 'Q' 0x51 81: 126 127 255
                { 0.306f, 0.306f, 0.573f }, // 'R' 0x52 82:  78  78 146
                { 0.518f, 0.000f, 1.000f }, // 'S' 0x53 83: 132   0 255
                { 0.769f, 0.518f, 1.000f }, // 'T' 0x54 84: 196 132 255
                { 0.510f, 0.329f, 0.506f }, // 'U' 0x55 85: 130  84 129
                { 0.988f, 0.608f, 0.937f }, // 'V' 0x56 86: 252 155 239
                { 1.000f, 0.000f, 0.500f }, // 'W' 0x57 87: 255   0 127
                { 0.596f, 0.000f, 0.588f }, // 'X' 0x58 88: 152   0 150
                { 0.725f, 0.725f, 0.725f }, // 'Y' 0x59 89: 185 185 185
                { 0.329f, 0.329f, 0.329f }, // 'Z' 0x5A 90:  84  84  84
        };
vec3_t rpmodColors[75] = // RPMod: add more text colors
        {
                { 0.0f, 0.0f, 0.0f }, // 0: black
                { 1.0f, 0.0f, 0.0f }, // 1: red
                { 0.0f, 1.0f, 0.0f }, // 2: green
                { 1.0f, 1.0f, 0.0f }, // 3: yellow
                { 0.0f, 0.0f, 1.0f }, // 4: blue
                { 0.0f, 1.0f, 1.0f }, // 5: cyan
                { 1.0f, 0.0f, 1.0f }, // 6: magenta
                { 1.0f, 1.0f, 1.0f }, // 7: white
                { 1.0f, 0.5f, 0.0f }, // 8: orange
                { 0.5f, 0.0f, 0.8f }, // 9: purple
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 0.59f, 0.29f, 0.00f }, // A
                { 1.00f, 0.80f, 0.64f }, // B
                { 0.00f, 0.80f, 0.80f }, // C
                { 0.00f, 0.00f, 0.50f }, // D
                { 0.31f, 0.15f, 0.51f }, // E
                { 1.00f, 0.75f, 0.80f }, // F
                { 0.00f, 0.48f, 0.65f }, // G
                { 0.00f, 0.29f, 0.33f }, // H
                { 0.97f, 0.51f, 0.47f }, // I
                { 0.00f, 0.50f, 0.50f }, // J
                { 0.50f, 0.00f, 0.00f }, // K
                { 0.64f, 0.35f, 0.32f }, // L
                { 0.25f, 0.51f, 0.43f }, // M
                { 0.50f, 0.00f, 1.00f }, // N
                { 0.75f, 0.75f, 0.75f }, // O
                { 0.21f, 0.27f, 0.31f }, // P
                { 0.40f, 0.60f, 0.80f }, // Q
                { 0.89f, 0.26f, 0.20f }, // R
                { 0.77f, 0.38f, 0.06f }, // S
                { 0.85f, 0.56f, 0.35f }, // T
                { 0.91f, 0.38f, 0.00f }, // U
                { 0.80f, 0.80f, 1.00f }, // V
                { 0.69f, 0.88f, 0.90f }, // W
                { 0.68f, 0.85f, 0.90f }, // X
                { 0.54f, 0.81f, 0.94f }, // Y
                { 0.00f, 0.00f, 1.00f }, // Z
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 1.0f, 1.0f, 1.0f }, // (padding)
                { 0.25f, 0.00f, 1.00f }, // a
                { 0.00f, 0.00f, 0.55f }, // b
                { 0.11f, 0.16f, 0.32f }, // c
                { 1.00f, 1.00f, 0.80f }, // d
                { 0.94f, 0.80f, 0.00f }, // e
                { 1.00f, 0.83f, 0.00f }, // f
                { 1.00f, 0.94f, 0.00f }, // g
                { 1.00f, 1.00f, 0.47f }, // h
                { 0.98f, 0.85f, 0.37f }, // i
                { 1.00f, 0.84f, 0.00f }, // j
                { 0.76f, 0.69f, 0.57f }, // k
                { 0.50f, 0.50f, 0.00f }, // l
                { 0.88f, 0.07f, 0.37f }, // m
                { 1.00f, 0.08f, 0.58f }, // n
                { 1.00f, 0.44f, 1.00f }, // o
                { 0.40f, 0.01f, 0.24f }, // p
                { 0.47f, 0.32f, 0.66f }, // q
                { 0.44f, 0.16f, 0.39f }, // r
                { 0.47f, 0.09f, 0.29f }, // s
                { 0.56f, 0.59f, 0.47f }, // t
                { 0.53f, 0.66f, 0.42f }, // u
                { 0.34f, 0.51f, 0.01f }, // v
                { 0.68f, 1.00f, 0.18f }, // w
                { 0.27f, 0.30f, 0.22f }, // x
                { 0.00f, 0.34f, 0.25f }, // y
                { 0.54f, 0.60f, 0.36f }, // z
        };
int Q_parseColor( const char *p, const vec3_t *numberColors, float *color ) {
    char c = *p++;
    if (((c >= '0' && c <='9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && numberColors == &(rpmodColors[0])) {
        if (!color)
            return 1;
        memcpy( color, numberColors + c - '0', sizeof( vec3_t ));
        return 1;
    } else if (((c >= '0' && c <='9') || (c >= 'A' && c <= 'Z')) && numberColors == &(uagColors[0])) {
        if (!color)
            return 1;
        memcpy( color, numberColors + c - '0', sizeof( vec3_t ));
        return 1;
    } else if (c >= '0' && c <='9') {
        if (!color)
            return 1;
        memcpy( color, numberColors + c - '0', sizeof( vec3_t ));
        return 1;
/*	} else if ( ( c >= 'a' && c < 'u') || (c >= 'A' && c < 'U') ) {
		int deg;
		float angle, v;
		if (!color)
			return 1;
		deg = (((c|32) - 'a') * 360) / 24;
		angle = (DEG2RAD(deg % 120));
		v = ((cos(angle) / cos((M_PI / 3) - angle)) + 1) / 3;
		if ( deg <= 120) {
			color[0] = v;
			color[1] = 1-v;
			color[2] = 0;
		} else if ( deg <= 240) {
			color[0] = 0;
			color[1] = v;
			color[2] = 1-v;
		} else {
			color[0] = 1-v;
			color[1] = 0;
			color[2] = v;
		}
		return 1;*/
    } else if ( c == 'u' || c == 'U' || c == 'v' || c == 'V'
                || c == 'w' || c == 'W' || c == 'x' || c == 'X'
                || c == 'y' || c == 'Y' || c == 'z' || c == 'Z'
                || c == '#') {
        int i;
        int val;
        for (i = 0;i<6;i++) {
            int readHex;
            c = p[i];
            if ( c >= '0' && c<= '9') {
                readHex = c - '0';
            } else if ( c >= 'a' && c<= 'f') {
                readHex = 0xa + c - 'a';
            } else if ( c >= 'A' && c<= 'F') {
                readHex = 0xa + c - 'A';
            } else {
/*				if (color) {
					color[0] = color[1] = color[2] = 1.0f;
				}*/
                return -1;
            }
            if (!color)
                continue;
            if ( i & 1) {
                val|= readHex;
                color[i >> 1] = val * (1 / 255.0f);
            } else {
                val = readHex << 4;
            }
        }
        return 7;
    }
/*	if (color) {
		color[0] = color[1] = color[2] = 1.0f;
	}*/
    return -1;
}