#ifndef DEFAULT_FORMAT_CALLBACK
#error Please define a default format callback before including this file
#endif

#ifndef SIMPLE_FORMAT_CALLBACK
#error Please define a default format callback before including this file
#endif

#ifndef BITFLAG_FORMAT_CALLBACK
#error Please define a bitflag format callback before including this file
#endif

#ifndef KEYVALUE_FORMAT_CALLBACK
#error Please define a key/value format callback before including this file
#endif

#define NL "\n"
#define LINE( tabbing, color, prefix, separator, desc ) tabbing color prefix S_COLOR_WHITE separator desc
#define PADGROUP( specialChar, text ) specialChar text specialChar

// describes one possible setting. use their aliases when possible
#define DESCLINE( color, prefix, desc )		LINE( "    ", color, prefix, " "S_COLOR_GREY"-"S_COLOR_WHITE" ", desc )
#define EMPTYLINE( prefix, moreDesc )		LINE( "    ", "", prefix, "   ", moreDesc )
#define EXAMPLE( example, desc )			S_COLOR_WHITE "Example: "S_COLOR_GREY"\"" S_COLOR_WHITE example S_COLOR_GREY "\" -> " S_COLOR_WHITE desc ""

// aliases for DESCLINE
#define SETTING( setting, desc )			DESCLINE( S_COLOR_WHITE, PADGROUP( "\x1f", setting ), desc )
#define BITFLAG( desc )						DESCLINE( S_COLOR_MAGENTA, PADGROUP( "\x1f", "\x19" ), desc )
#define SPECIAL( special, desc )			DESCLINE( S_COLOR_YELLOW, PADGROUP( "\x1f", special ), desc )
#define KEY( key, desc )					DESCLINE( S_COLOR_CYAN, PADGROUP( "\x1f", key ), desc )
#define KEYVALUE( key, valueFormat, desc )	DESCLINE( S_COLOR_CYAN, PADGROUP( "\x1f", PADGROUP( "\x1d", key ) S_COLOR_WHITE "=" S_COLOR_CYAN PADGROUP( "\x1e", "["valueFormat"]" ) ), desc )

// aliases for EMPTYLINE to continue the previous DESCLINE alias
#define SETTING_NEXTLINE( moreDesc )		EMPTYLINE( PADGROUP( "\x1f", "" ), moreDesc )
#define BITFLAG_NEXTLINE( moreDesc )		EMPTYLINE( PADGROUP( "\x1f", "" ), moreDesc )
#define SPECIAL_NEXTLINE( moreDesc )		EMPTYLINE( PADGROUP( "\x1f", "" ), moreDesc )
#define KEYVALUE_NEXTLINE( moreDesc )		EMPTYLINE( PADGROUP( "\x1f", PADGROUP( "\x1d", "" ) " " PADGROUP( "\x1e", "" ) ), moreDesc )

// general headers for cvar types, bound to their own macro
#define HEADER_BITFLAG_CVAR \
	S_COLOR_MAGENTA"Bitflag Cvar"S_COLOR_WHITE": add bitflags together to combine settings." NL \
	SETTING( "-1", "Enable all settings" ) NL \
	SETTING( "0", "Disable all settings" ) NL

#define HEADER_KEYVALUE_CVAR \
	S_COLOR_CYAN"Key/Value Cvar"S_COLOR_WHITE": optionally use any number of key/value parameters." NL \
	S_COLOR_WHITE"The format is "S_COLOR_GREY"\""S_COLOR_WHITE"key1=value1 key2=value2 [...]"S_COLOR_GREY"\""S_COLOR_WHITE". All keys have default values if unspecified." NL

#ifdef XDOCS_CVAR_SHORT_LIST
	#define XDOCS_CVAR_DEF( name, shortDesc, longDesc ) { name, shortDesc, DEFAULT_FORMAT_CALLBACK },
	#define XDOCS_CVAR_BITFLAG_DEF( name, shortDesc, longDesc ) { name, shortDesc, DEFAULT_FORMAT_CALLBACK },
	#define XDOCS_CVAR_KEYVALUE_DEF( name, shortDesc, longDesc ) { name, shortDesc, DEFAULT_FORMAT_CALLBACK },
	#define XDOCS_CMD_DEF( name, desc )
#endif

#ifdef XDOCS_CVAR_LONG_LIST
	#define XDOCS_CVAR_DEF( name, shortDesc, longDesc ) { name, longDesc, SIMPLE_FORMAT_CALLBACK },
	#define XDOCS_CVAR_BITFLAG_DEF( name, shortDesc, longDesc ) { name, HEADER_BITFLAG_CVAR longDesc, BITFLAG_FORMAT_CALLBACK },
	#define XDOCS_CVAR_KEYVALUE_DEF( name, shortDesc, longDesc ) { name, HEADER_KEYVALUE_CVAR longDesc, KEYVALUE_FORMAT_CALLBACK },
	#define XDOCS_CMD_DEF( name, desc )
#endif

#ifdef XDOCS_CMD_LIST
	#define XDOCS_CVAR_DEF( name, shortDesc, longDesc )
	#define XDOCS_CVAR_BITFLAG_DEF( name, shortDesc, longDesc )
	#define XDOCS_CVAR_KEYVALUE_DEF( name, shortDesc, longDesc )
	#define XDOCS_CMD_DEF( name, desc ) { name, desc, DEFAULT_FORMAT_CALLBACK },
#endif

/* --------------------------------------------------- */
/* CVARS */

// Newmod HUD cvars:

XDOCS_CVAR_DEF("cg_12HourTime", "Display scoreboard clock in 12-hour format",
	SETTING("0", "Display scoreboard clock in 24-hour format (e.g. 23:00)") NL
	SETTING("1", "Display scoreboard clock in 12-hour format (e.g. 11:00 pm)")
)

// ...

/* --------------------------------------------------- */
/* COMMANDS */

// Newmod commands:

XDOCS_CMD_DEF("clientlist", "Displays a list of all connected clients and their real client numbers")

// ...

#undef NL
#undef LINE
#undef PADGROUP

#undef DESCLINE
#undef EMPTYLINE
#undef EXAMPLE

#undef SETTING
#undef BITFLAG
#undef SPECIAL
#undef KEYVALUE

#undef SETTING_NEXTLINE
#undef BITFLAG_NEXTLINE
#undef SPECIAL_NEXTLINE
#undef KEYVALUE_NEXTLINE

#undef HEADER_BITFLAG_CVAR
#undef HEADER_KEYVALUE_CVAR

#undef XDOCS_CVAR_DEF
#undef XDOCS_CVAR_BITFLAG_DEF
#undef XDOCS_CVAR_KEYVALUE_DEF
#undef XDOCS_CMD_DEF