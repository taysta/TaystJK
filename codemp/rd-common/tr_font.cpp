/*
===========================================================================
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
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

#include "qcommon/sstring.h"	// stl string class won't compile in here (MS shite), so use Gil's.
#include "tr_local.h"
#include "tr_font.h"

#include "qcommon/stringed_ingame.h"

cvar_t *r_fontSharpness;

#ifdef USE_FREETYPE
cvar_t* r_useFreeType;

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_COLOR_H
#include FT_TRUETYPE_TABLES_H	// FT_Load_Sfnt_Table (GSUB, for emoji ZWJ ligatures)

#include <vector>
#include <unordered_map>
#include <algorithm>	// std::stable_sort (GSUB ligature ordering)

static FT_Library g_FTLibrary = NULL;

// ---- r_fontProfile: counters and timings, printed (and reset) by "fontlist" ----
//
#include <chrono>

static cvar_t* r_fontProfile;

static struct fontStats_t
{
	unsigned int	draws, quads, pageSwitches;
	unsigned int	rasterized, colorLayers, uploads;
	unsigned int	uploadKB;
	double			drawMs, rasterMs, uploadMs;
} g_fontStats;

static inline double Font_ProfileClock(void)
{
	if (!r_fontProfile || !r_fontProfile->integer)
	{
		return 0.0;
	}
	return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

struct FontProfileScope_t
{
	double* pTotal;
	double	start;

	explicit FontProfileScope_t(double* pTotalMs) : pTotal(pTotalMs), start(Font_ProfileClock()) {}
	~FontProfileScope_t() { if (start) { *pTotal += Font_ProfileClock() - start; } }
};

// ---- per-glyph fallback fonts (r_fontFallbacks) ----
//
// When the main font has no glyph for a codepoint, these faces are searched
// in order and the winning glyph is rasterized into the SAME atlas, at the
// host font's size. Semicolon/space separated file names, eg "notoemoji".
//
#define FONT_MAX_FALLBACKS	8

static FT_Face	g_FallbackFaces[FONT_MAX_FALLBACKS];
static byte* g_FallbackData[FONT_MAX_FALLBACKS];
static int		g_iNumFallbacks = 0;
static bool		g_bFallbacksLoaded = false;
cvar_t* r_fontFallbacks;

static void Font_LoadFallbacks(void)
{
	char	sList[MAX_STRING_CHARS];
	char* psName;

	g_bFallbacksLoaded = true;

	if (!g_FTLibrary || !r_fontFallbacks || !r_fontFallbacks->string[0])
	{
		return;
	}

	Q_strncpyz(sList, r_fontFallbacks->string, sizeof(sList));

	for (psName = strtok(sList, "; ,"); psName && g_iNumFallbacks < FONT_MAX_FALLBACKS; psName = strtok(NULL, "; ,"))
	{
		char		sPath[MAX_QPATH];
		int			iLen = -1;
		const char* psExtensions[] = { "ttf", "otf" };
		void* pvBuff;

		for (size_t i = 0; i < ARRAY_LEN(psExtensions); i++)
		{
			Com_sprintf(sPath, sizeof(sPath), "fonts/%s.%s", psName, psExtensions[i]);
			iLen = ri.FS_ReadFile(sPath, NULL);
			if (iLen > 0)
			{
				break;
			}
		}

		if (iLen <= 0)
		{
			ri.Printf(PRINT_DEVELOPER, "r_fontFallbacks: fonts/%s.ttf|otf not found\n", psName);
			continue;
		}

		ri.FS_ReadFile(sPath, &pvBuff);
		g_FallbackData[g_iNumFallbacks] = new byte[iLen];
		memcpy(g_FallbackData[g_iNumFallbacks], pvBuff, iLen);
		ri.FS_FreeFile(pvBuff);

		if (FT_New_Memory_Face(g_FTLibrary, g_FallbackData[g_iNumFallbacks], iLen, 0, &g_FallbackFaces[g_iNumFallbacks]) != 0)
		{
			ri.Printf(PRINT_WARNING, "r_fontFallbacks: FT_New_Memory_Face failed on %s\n", sPath);
			delete[] g_FallbackData[g_iNumFallbacks];
			g_FallbackData[g_iNumFallbacks] = NULL;
			continue;
		}

		ri.Printf(PRINT_ALL, "Fallback font %d: %s\n", g_iNumFallbacks, sPath);
		g_iNumFallbacks++;
	}
}

#define TTF_ATLAS_SIZE			512		// smallest atlas page, see CFontInfo::TTF_Init
#define TTF_ATLAS_MAX_SIZE		2048
#define TTF_ATLAS_MAX_PAGES		16
#define TTF_DIRECT_GLYPHS		256		// codepoints below this are looked up through a flat table
#define TTF_PRECACHE_LIMIT		0x2000	// alphabetic scripts live below this: rasterized a 128 codepoint block at a time
#define TTF_GLYPH_PADDING		2

struct TTFGlyph_t
{
	glyphInfo_t	glyph;
	qhandle_t	hShader;		// atlas page this glyph lives on
	qhandle_t	hShadowShader;	// vertex-tinted twin, used by the dropshadow pass
	bool		bMissing;		// rasterization failed: remembered so it isn't retried on every draw
};

typedef std::unordered_map<unsigned int, TTFGlyph_t> TTFGlyphMap_t;

struct TTFAtlasPage_t
{
	qhandle_t	hShader;
	qhandle_t	hShadowShader;	// vertex-tinted twin of hShader (== hShader for text pages)
	void* pImage;		// opaque renderer image, see R_Font_CreateAtlasImage
	int			iCursorX;
	int			iCursorY;
	int			iRowHeight;
};

// Freshly rasterized glyphs are not sent to the GPU one by one: they queue up
// here and TTF_FlushUploads() sends each run of neighbours on an atlas shelf as
// a single texture update...
//
struct TTFPendingUpload_t
{
	void*				pImage;
	int					iX, iY, iW, iH;
	std::vector<byte>	rgba;
};

static std::vector<TTFPendingUpload_t> g_TTFPendingUploads;

// takes over the contents of rgba...
//
static void TTF_QueueUpload(void* pImage, int iX, int iY, int iW, int iH, std::vector<byte>& rgba)
{
	g_TTFPendingUploads.push_back(TTFPendingUpload_t());

	TTFPendingUpload_t& upload = g_TTFPendingUploads.back();
	upload.pImage = pImage;
	upload.iX = iX;
	upload.iY = iY;
	upload.iW = iW;
	upload.iH = iH;
	upload.rgba.swap(rgba);
}

// one upload: a run of neighbours on a shelf, or several whole shelves...
//
struct TTFUploadRun_t
{
	size_t	iFirst, iEnd;	// [iFirst, iEnd) in g_TTFPendingUploads
	int		iX, iY, iW, iH;
};

static void TTF_FlushUploads(void)
{
	const size_t iNumUploads = g_TTFPendingUploads.size();
	if (!iNumUploads)
	{
		return;
	}

	FontProfileScope_t profile(&g_fontStats.uploadMs);
	std::vector<TTFUploadRun_t> runs;

	// the shelf packer hands out space left to right, so glyphs queued one
	// after another on the same shelf are neighbours with nothing but padding
	// (and the unused space below shorter glyphs) between them...
	for (size_t i = 0; i < iNumUploads; )
	{
		const TTFPendingUpload_t& first = g_TTFPendingUploads[i];
		TTFUploadRun_t run;

		run.iFirst = i;
		run.iX = first.iX;
		run.iY = first.iY;
		run.iH = first.iH;
		for (i++; i < iNumUploads
			&& g_TTFPendingUploads[i].pImage == first.pImage
			&& g_TTFPendingUploads[i].iY == first.iY
			&& g_TTFPendingUploads[i].iX > g_TTFPendingUploads[i - 1].iX; i++)
		{
			if (g_TTFPendingUploads[i].iH > run.iH)
			{
				run.iH = g_TTFPendingUploads[i].iH;
			}
		}
		run.iEnd = i;
		run.iW = (g_TTFPendingUploads[i - 1].iX + g_TTFPendingUploads[i - 1].iW) - run.iX;

		// ...and a shelf that was filled from its left edge holds nothing but
		// this run, so it can join the run of the shelf right above it when
		// that one started at the left edge too: whole blocks of new glyphs
		// then go up as one rectangle instead of one per shelf
		if (!runs.empty())
		{
			TTFUploadRun_t& prev = runs.back();
			if (run.iX == 0 && prev.iX == 0 && run.iY > prev.iY
				&& g_TTFPendingUploads[prev.iFirst].pImage == first.pImage)
			{
				prev.iEnd = run.iEnd;
				prev.iH = (run.iY + run.iH) - prev.iY;
				if (run.iW > prev.iW)
				{
					prev.iW = run.iW;
				}
				continue;
			}
		}
		runs.push_back(run);
	}

	std::vector<byte> merged;
	for (size_t r = 0; r < runs.size(); r++)
	{
		const TTFUploadRun_t& run = runs[r];
		const TTFPendingUpload_t& first = g_TTFPendingUploads[run.iFirst];

		if (run.iEnd == run.iFirst + 1)
		{
			R_Font_UpdateAtlasImage(first.pImage, first.iX, first.iY, first.iW, first.iH, &first.rgba[0]);
		}
		else
		{
			merged.assign((size_t)run.iW * run.iH * 4, 0);
			for (size_t k = run.iFirst; k < run.iEnd; k++)
			{
				const TTFPendingUpload_t& upload = g_TTFPendingUploads[k];
				for (int iRow = 0; iRow < upload.iH; iRow++)
				{
					memcpy(&merged[((size_t)(upload.iY - run.iY + iRow) * run.iW + (upload.iX - run.iX)) * 4],
						&upload.rgba[(size_t)iRow * upload.iW * 4],
						(size_t)upload.iW * 4);
				}
			}
			R_Font_UpdateAtlasImage(first.pImage, run.iX, run.iY, run.iW, run.iH, &merged[0]);
		}
		g_fontStats.uploads++;
		g_fontStats.uploadKB += (unsigned int)(((size_t)run.iW * run.iH * 4) >> 10);
	}

	g_TTFPendingUploads.clear();
}

#endif // USE_FREETYPE

#define TTF_DEFAULT_POINTSIZE	16

// font name may carry an "@NN" point size suffix, eg "myfont@24"...
// (needed without FreeType as well: cgame and ui always register sized names)
//
static void Font_SplitSizedName(const char* psName, char* psBaseName, int iBaseNameSize, int* piPointSize)
{
	char* psAt;

	Q_strncpyz(psBaseName, psName, iBaseNameSize);
	*piPointSize = TTF_DEFAULT_POINTSIZE;

	psAt = strrchr(psBaseName, '@');
	if (psAt && atoi(psAt + 1) > 0)
	{
		*piPointSize = atoi(psAt + 1);
		*psAt = '\0';
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// This file is shared in the single and multiplayer codebases, so be CAREFUL WHAT YOU ADD/CHANGE!!!!!
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	eWestern,	// ( I only care about asian languages in here at the moment )
	eRussian,	//  .. but now I need to care about this, since it uses a different TP
	ePolish,	// ditto
	eHungarian,	// Windows-1250 like Polish, but never had a font of its own
	eCzech,		// ditto
	eSlovak,	// ditto
	eUkrainian,	// Windows-1251 like Russian, ditto
	eKorean,
	eTaiwanese,	// 15x15 glyphs tucked against BR of 16x16 space
	eJapanese,	// 15x15 glyphs tucked against TL of 16x16 space
	eChinese,	// 15x15 glyphs tucked against TL of 16x16 space
	eThai,		// 16x16 cells with glyphs against left edge, special file (tha_widths.dat) for variable widths
} Language_e;

// this is to cut down on all the stupid string compares I've been doing, and convert asian stuff to switch-case
//
Language_e GetLanguageEnum()
{
	static int			iSE_Language_ModificationCount = -1234;	// any old silly value that won't match the cvar mod count
	static Language_e	eLanguage = eWestern;

	// only re-strcmp() when language string has changed from what we knew it as...
	//
	if (iSE_Language_ModificationCount != se_language->modificationCount )
	{
		iSE_Language_ModificationCount  = se_language->modificationCount;

				if ( Language_IsRussian()	)	eLanguage = eRussian;
		else	if ( Language_IsPolish()	)	eLanguage = ePolish;
		else	if ( Language_IsHungarian() )	eLanguage = eHungarian;
		else	if ( Language_IsCzech()		)	eLanguage = eCzech;
		else	if ( Language_IsSlovak()	)	eLanguage = eSlovak;
		else	if ( Language_IsUkrainian() )	eLanguage = eUkrainian;
		else	if ( Language_IsKorean()	)	eLanguage = eKorean;
		else	if ( Language_IsTaiwanese()	)	eLanguage = eTaiwanese;
		else	if ( Language_IsJapanese()	)	eLanguage = eJapanese;
		else	if ( Language_IsChinese()	)	eLanguage = eChinese;
		else	if ( Language_IsThai()		)	eLanguage = eThai;
		else	eLanguage = eWestern;
	}

	return eLanguage;
}

struct SBCSOverrideLanguages_t
{
	const char *m_psName;
	Language_e	m_eLanguage;
};

// so I can do some stuff with for-next loops when I add polish etc...
//
SBCSOverrideLanguages_t g_SBCSOverrideLanguages[]=
{
	{"russian",	eRussian},
	{"polish",	ePolish},
	{NULL,		eWestern}
};



//================================================
//

#define sFILENAME_THAI_WIDTHS	"fonts/tha_widths.dat"
#define sFILENAME_THAI_CODES	"fonts/tha_codes.dat"

struct ThaiCodes_t
{
	std::map <int, int>	m_mapValidCodes;
	std::vector<int>		m_viGlyphWidths;
	sstring_t		m_strInitFailureReason;	// so we don't have to keep retrying to work this out

	void Clear( void )
	{
		m_mapValidCodes.clear();
		m_viGlyphWidths.clear();
		m_strInitFailureReason = "";	// if blank, never failed, else says don't bother re-trying
	}

	ThaiCodes_t()
	{
		Clear();
	}

	// convert a supplied 1,2 or 3-byte multiplied-up integer into a valid 0..n index, else -1...
	//
	int GetValidIndex( int iCode )
	{
		std::map <int,int>::iterator it = m_mapValidCodes.find( iCode );
		if (it != m_mapValidCodes.end())
		{
            return (*it).second;
		}

		return -1;
	}

	int GetWidth( int iGlyphIndex )
	{
		if (iGlyphIndex < (int)m_viGlyphWidths.size())
		{
			return m_viGlyphWidths[ iGlyphIndex ];
		}

		assert(0);
		return 0;
	}

	// return is error message to display, or NULL for success
	const char *Init(void)
	{
		if (m_mapValidCodes.empty() && m_viGlyphWidths.empty())
		{
			if (m_strInitFailureReason.empty())	// never tried and failed already?
			{
				int *piData = NULL;	// note <int>, not <byte>, for []-access
				//
				// read the valid-codes table in...
				//
				int iBytesRead = ri.FS_ReadFile( sFILENAME_THAI_CODES, (void **) &piData );
				if (iBytesRead > 0 && !(iBytesRead&3))	// valid length and multiple of 4 bytes long
				{
					int iTableEntries = iBytesRead / sizeof(int);

					for (int i=0; i < iTableEntries; i++)
					{
						m_mapValidCodes[ piData[i] ] = i;	// convert MBCS code to sequential index...
					}
					ri.FS_FreeFile( piData );	// dispose of original

					// now read in the widths... (I'll keep these in a simple STL vector, so they'all disappear when the <map> entries do...
					//
					iBytesRead = ri.FS_ReadFile( sFILENAME_THAI_WIDTHS, (void **) &piData );
					if (iBytesRead > 0 && !(iBytesRead&3) && iBytesRead>>2/*sizeof(int)*/ == iTableEntries)
					{
						for (int i=0; i<iTableEntries; i++)
						{
							m_viGlyphWidths.push_back( piData[i] );
						}
						ri.FS_FreeFile( piData );	// dispose of original
					}
					else
					{
						m_strInitFailureReason = va("Error with file \"%s\", size = %d!\n", sFILENAME_THAI_WIDTHS, iBytesRead);
					}
				}
				else
				{
					m_strInitFailureReason = va("Error with file \"%s\", size = %d!\n", sFILENAME_THAI_CODES, iBytesRead);
				}
			}
		}

		return m_strInitFailureReason.c_str();
	}
};


#define GLYPH_MAX_KOREAN_SHADERS	3
#define GLYPH_MAX_TAIWANESE_SHADERS 4
#define GLYPH_MAX_JAPANESE_SHADERS	3
#define GLYPH_MAX_CHINESE_SHADERS	3
#define GLYPH_MAX_THAI_SHADERS		3
#define GLYPH_MAX_ASIAN_SHADERS		4	// this MUST equal the larger of the above defines

#define MAX_FONT_VARIANTS 8

class CFontInfo
{
private:
	// From the fontdat file
	glyphInfo_t		mGlyphs[GLYPH_COUNT];

//	int				mAsianHack;				// unused junk from John's fontdat file format.
	// end of fontdat data

	int				mShader;   				// handle to the shader with the glyph

	int				m_hAsianShaders[GLYPH_MAX_ASIAN_SHADERS];	// shaders for Korean glyphs where applicable
	glyphInfo_t		m_AsianGlyph;			// special glyph containing asian->western scaling info for all glyphs
	int				m_iAsianGlyphsAcross;	// needed to dynamically calculate S,T coords
	int				m_iAsianPagesLoaded;
	bool			m_bAsianLastPageHalfHeight;
	int				m_iLanguageModificationCount;	// doesn't matter what this is, so long as it's comparable as being changed

	ThaiCodes_t		*m_pThaiData;

#ifdef USE_FREETYPE
	FT_Face			m_ftFace;
	byte* m_pFaceData;		// FreeType requires the font file data to stay alive
	TTFAtlasPage_t	m_TTFPages[TTF_ATLAS_MAX_PAGES];
	int				m_iTTFNumPages;
	TTFAtlasPage_t	m_TTFColorPages[TTF_ATLAS_MAX_PAGES];	// identity-colour pages for emoji/colour glyphs
	int				m_iTTFNumColorPages;
	int				m_iTTFAtlasSize;		// width and height of this font's atlas pages
	bool			m_bTTFAtlasFull;
	TTFGlyphMap_t	m_TTFGlyphs;
	TTFGlyph_t*		m_TTFDirect[TTF_DIRECT_GLYPHS];	// m_TTFGlyphs entries of the low codepoints, NULL until cached
	uint64_t		m_uiTTFPrecachedBlocks;	// one bit per 128 codepoint block below TTF_PRECACHE_LIMIT
	std::map<std::vector<unsigned int>, unsigned int> m_TTFSeqCache;	// emoji sequence -> synthetic m_TTFGlyphs key (0 = known failure)

	TTFGlyph_t* TTF_CacheGlyph(unsigned int uiLetter);
	TTFGlyph_t* TTF_RenderGlyphIndex(FT_Face pFace, FT_UInt uiGlyphIndex, unsigned int uiCacheKey);
	TTFAtlasPage_t* TTF_AllocAtlasSpace(int iWidth, int iHeight, int* piX, int* piY, bool bColor);
#endif

public:
	char			m_sFontName[MAX_QPATH];	// eg "fonts/lcd"	// needed for korean font-hint if we need >1 hangul set
	int				mPointSize;
	int				mHeight;
	int				mAscender;
	int				mDescender;

	bool			mbRoundCalcs;	// trying to make this !@#$%^ thing work with scaling
	int				m_iThisFont;	// handle to itself
	int				m_iAltSBCSFont;	// -1 == NULL // alternative single-byte font for languages like russian/polish etc that need to override high characters ?
	int				m_iOriginalFontWhenSBCSOverriden;
	float			m_fAltSBCSFontScaleFactor;	// -1, else amount to adjust returned values by to make them fit the master western font they're substituting for
	bool			m_bIsFakeAlienLanguage;	// ... if true, don't process as MBCS or override as SBCS etc

	CFontInfo		*m_variants[MAX_FONT_VARIANTS];
	int				m_numVariants;
	int				m_handle;
	qboolean		m_isVariant;

#ifdef USE_FREETYPE
	bool			m_bTTF;

	bool TTF_Init(const char* psName);
	const glyphInfo_t* TTF_GetLetter(const unsigned int uiLetter, int* piShader);
	const glyphInfo_t* GetSequenceGlyph(unsigned int uiFirst, const char** ppsText, int* piShader = NULL);
	bool IsTTF(void) const { return m_bTTF; }
	void TTF_Warm(void) { TTF_CacheGlyph('a'); }	// rasterizes the whole ASCII block
#else
	const glyphInfo_t* GetSequenceGlyph(unsigned int, const char**, int* = NULL) { return NULL; }
	bool IsTTF(void) const { return false; }
#endif

	CFontInfo(const char *fontName);
//	CFontInfo(int fill) { memset(this, fill, sizeof(*this)); }	// wtf?
	~CFontInfo(void)
	{
#ifdef USE_FREETYPE
		if (m_ftFace)
		{
			FT_Done_Face(m_ftFace);
			m_ftFace = NULL;
		}
		if (m_pFaceData)
		{
			delete[] m_pFaceData;
			m_pFaceData = NULL;
		}
#endif
	}

	const int GetPointSize(void) const { return(mPointSize); }
	const int GetHeight(void) const { return(mHeight); }
	const int GetAscender(void) const { return(mAscender); }
	const int GetDescender(void) const { return(mDescender); }

	const glyphInfo_t *GetLetter(const unsigned int uiLetter, int *piShader = NULL);
	const int GetCollapsedAsianCode(ulong uiLetter) const;

	const int GetLetterWidth(const unsigned int uiLetter);
	const int GetLetterHorizAdvance(const unsigned int uiLetter);
	const int GetShader(void) const { return(mShader); }

	void FlagNoAsianGlyphs(void) { m_hAsianShaders[0] = 0; m_iLanguageModificationCount = -1; }	// used during constructor
	bool AsianGlyphsAvailable(void) const { return !!(m_hAsianShaders[0]); }

	void UpdateAsianIfNeeded( bool bForceReEval = false);

	int GetHandle();

	void AddVariant(CFontInfo *variant);
	int GetNumVariants();
	CFontInfo *GetVariant(int index);
};

//================================================




// round float to one decimal place...
//
float RoundTenth( float fValue )
{
	return ( floorf( (fValue*10.0f) + 0.5f) ) / 10.0f;
}


int							g_iCurrentFontIndex;	// entry 0 is reserved index for missing/invalid, else ++ with each new font registered
std::vector<CFontInfo *>			g_vFontArray;
typedef std::map<sstring_t, int>	FontIndexMap_t;
							FontIndexMap_t g_mapFontIndexes;
int g_iNonScaledCharRange;	// this is used with auto-scaling of asian fonts, anything below this number is preserved in scale, anything above is scaled down by 0.75f

//paletteRGBA_c				lastcolour;

// =============================== some korean stuff =======================================

#define KSC5601_HANGUL_HIBYTE_START		0xB0	// range is...
#define KSC5601_HANGUL_HIBYTE_STOP		0xC8	// ... inclusive
#define KSC5601_HANGUL_LOBYTE_LOBOUND	0xA0	// range is...
#define KSC5601_HANGUL_LOBYTE_HIBOUND	0xFF	// ...bounding (ie only valid in between these points, but NULLs in charsets for these codes)
#define KSC5601_HANGUL_CODES_PER_ROW	96		// 2 more than the number of glyphs

extern qboolean Language_IsKorean( void );

static inline bool Korean_ValidKSC5601Hangul( byte _iHi, byte _iLo )
{
	return (_iHi >=KSC5601_HANGUL_HIBYTE_START		&&
			_iHi <=KSC5601_HANGUL_HIBYTE_STOP		&&
			_iLo > KSC5601_HANGUL_LOBYTE_LOBOUND	&&
			_iLo < KSC5601_HANGUL_LOBYTE_HIBOUND
			);
}

static inline bool Korean_ValidKSC5601Hangul( unsigned int uiCode )
{
	return Korean_ValidKSC5601Hangul( uiCode >> 8, uiCode & 0xFF );
}


// takes a KSC5601 double-byte hangul code and collapses down to a 0..n glyph index...
// Assumes rows are 96 wide (glyph slots), not 94 wide (actual glyphs), so I can ignore boundary markers
//
// (invalid hangul codes will return 0)
//
static int Korean_CollapseKSC5601HangulCode(unsigned int uiCode)
{
	if (Korean_ValidKSC5601Hangul( uiCode ))
	{
		uiCode -= (KSC5601_HANGUL_HIBYTE_START * 256) + KSC5601_HANGUL_LOBYTE_LOBOUND;	// sneaky maths on both bytes, reduce to 0x0000 onwards
		uiCode  = ((uiCode >> 8) * KSC5601_HANGUL_CODES_PER_ROW) + (uiCode & 0xFF);
		return uiCode;
	}
	return 0;
}

#include "tr_font_ksc.h"

// Korean text is handed around as Unicode like everything else, so that an
// outline font can draw it; these convert at the edges. (0 = no such character)
//
static unsigned int Korean_KSCToUnicode( unsigned int uiCode )
{
	const int iIndex = Korean_CollapseKSC5601HangulCode( uiCode );
	return (iIndex > 0 && iIndex < KSC_TABLE_SIZE) ? g_kscToUnicode[iIndex] : 0;
}

// ...and back to a glyph index in the game's own Korean glyph pages
//
static int Korean_CollapseUnicode( unsigned int uiLetter )
{
	static unsigned short pReverse[0x10000];
	static bool bBuilt = false;
	if (!bBuilt)
	{
		bBuilt = true;
		for (int i = KSC_TABLE_SIZE - 1; i > 0; i--)	// backwards: of duplicates, keep the first
		{
			pReverse[g_kscToUnicode[i]] = (unsigned short)i;
		}
		pReverse[0] = 0;
	}
	return (uiLetter >= 0x80 && uiLetter <= 0xFFFF) ? pReverse[uiLetter] : 0;
}

static int Korean_InitFields(int &iGlyphTPs, const char *&psLang)
{
	psLang		= "kor";
	iGlyphTPs	= GLYPH_MAX_KOREAN_SHADERS;
	g_iNonScaledCharRange = 255;
	return 32;	// m_iAsianGlyphsAcross
}

// ======================== some taiwanese stuff ==============================

// (all ranges inclusive for Big5)...
//
#define BIG5_HIBYTE_START0		0xA1	// (misc chars + level 1 hanzi)
#define BIG5_HIBYTE_STOP0		0xC6	//
#define BIG5_HIBYTE_START1		0xC9	// (level 2 hanzi)
#define BIG5_HIBYTE_STOP1		0xF9	//
#define BIG5_LOBYTE_LOBOUND0	0x40	//
#define BIG5_LOBYTE_HIBOUND0	0x7E	//
#define BIG5_LOBYTE_LOBOUND1	0xA1	//
#define BIG5_LOBYTE_HIBOUND1	0xFE	//
#define BIG5_CODES_PER_ROW		160		// 3 more than the number of glyphs

extern qboolean Language_IsTaiwanese( void );

static bool Taiwanese_ValidBig5Code( unsigned int uiCode )
{
	const byte _iHi = (uiCode >> 8)&0xFF;
	if (	(_iHi >= BIG5_HIBYTE_START0 && _iHi <= BIG5_HIBYTE_STOP0)
		||	(_iHi >= BIG5_HIBYTE_START1 && _iHi <= BIG5_HIBYTE_STOP1)
		)
	{
		const byte _iLo = uiCode & 0xFF;

		if ( (_iLo >= BIG5_LOBYTE_LOBOUND0 && _iLo <= BIG5_LOBYTE_HIBOUND0) ||
			 (_iLo >= BIG5_LOBYTE_LOBOUND1 && _iLo <= BIG5_LOBYTE_HIBOUND1)
			)
		{
			return true;
		}
	}

	return false;
}


// only call this when Taiwanese_ValidBig5Code() has already returned true...
//
static bool Taiwanese_IsTrailingPunctuation( unsigned int uiCode )
{
	// so far I'm just counting the first 21 chars, those seem to be all the basic punctuation...
	//
	if (	uiCode >= ((BIG5_HIBYTE_START0<<8)|BIG5_LOBYTE_LOBOUND0) &&
			uiCode <  (((BIG5_HIBYTE_START0<<8)|BIG5_LOBYTE_LOBOUND0)+20)
		)
	{
		return true;
	}

	return false;
}


// takes a BIG5 double-byte code (including level 2 hanzi) and collapses down to a 0..n glyph index...
// Assumes rows are 160 wide (glyph slots), not 157 wide (actual glyphs), so I can ignore boundary markers
//
// (invalid big5 codes will return 0)
//
static int Taiwanese_CollapseBig5Code( unsigned int uiCode )
{
	if (Taiwanese_ValidBig5Code( uiCode ))
	{
		uiCode -= (BIG5_HIBYTE_START0 * 256) + BIG5_LOBYTE_LOBOUND0;	// sneaky maths on both bytes, reduce to 0x0000 onwards
		if ( (uiCode & 0xFF) >= (BIG5_LOBYTE_LOBOUND1-1)-BIG5_LOBYTE_LOBOUND0)
		{
			uiCode -= ((BIG5_LOBYTE_LOBOUND1-1) - (BIG5_LOBYTE_HIBOUND0+1)) -1;
		}
		uiCode = ((uiCode >> 8) * BIG5_CODES_PER_ROW) + (uiCode & 0xFF);
		return uiCode;
	}
	return 0;
}

static int Taiwanese_InitFields(int &iGlyphTPs, const char *&psLang)
{
	psLang		= "tai";
	iGlyphTPs	= GLYPH_MAX_TAIWANESE_SHADERS;
	g_iNonScaledCharRange = 255;
	return 64;	// m_iAsianGlyphsAcross
}

// ======================== some Japanese stuff ==============================


// ( all ranges inclusive for Shift-JIS )
//
#define SHIFTJIS_HIBYTE_START0	0x81
#define SHIFTJIS_HIBYTE_STOP0	0x9F
#define SHIFTJIS_HIBYTE_START1	0xE0
#define SHIFTJIS_HIBYTE_STOP1	0xEF
//
#define SHIFTJIS_LOBYTE_START0	0x40
#define SHIFTJIS_LOBYTE_STOP0	0x7E
#define SHIFTJIS_LOBYTE_START1	0x80
#define SHIFTJIS_LOBYTE_STOP1	0xFC
#define SHIFTJIS_CODES_PER_ROW	(((SHIFTJIS_LOBYTE_STOP0-SHIFTJIS_LOBYTE_START0)+1)+((SHIFTJIS_LOBYTE_STOP1-SHIFTJIS_LOBYTE_START1)+1))


extern qboolean Language_IsJapanese( void );

static bool Japanese_ValidShiftJISCode( byte _iHi, byte _iLo )
{
	if (	(_iHi >= SHIFTJIS_HIBYTE_START0 && _iHi <= SHIFTJIS_HIBYTE_STOP0)
		||	(_iHi >= SHIFTJIS_HIBYTE_START1 && _iHi <= SHIFTJIS_HIBYTE_STOP1)
		)
	{
		if ( (_iLo >= SHIFTJIS_LOBYTE_START0 && _iLo <= SHIFTJIS_LOBYTE_STOP0) ||
			 (_iLo >= SHIFTJIS_LOBYTE_START1 && _iLo <= SHIFTJIS_LOBYTE_STOP1)
			)
		{
			return true;
		}
	}

	return false;
}

static inline bool Japanese_ValidShiftJISCode( unsigned int uiCode )
{
	return Japanese_ValidShiftJISCode( uiCode >> 8, uiCode & 0xFF );
}


// only call this when Japanese_ValidShiftJISCode() has already returned true...
//
static bool Japanese_IsTrailingPunctuation( unsigned int uiCode )
{
	// so far I'm just counting the first 18 chars, those seem to be all the basic punctuation...
	//
	if (	uiCode >= ((SHIFTJIS_HIBYTE_START0<<8)|SHIFTJIS_LOBYTE_START0) &&
			uiCode <  (((SHIFTJIS_HIBYTE_START0<<8)|SHIFTJIS_LOBYTE_START0)+18)
		)
	{
		return true;
	}

	return false;
}


// takes a ShiftJIS double-byte code and collapse down to a 0..n glyph index...
//
// (invalid codes will return 0)
//
static int Japanese_CollapseShiftJISCode( unsigned int uiCode )
{
	if (Japanese_ValidShiftJISCode( uiCode ))
	{
		uiCode -= ((SHIFTJIS_HIBYTE_START0<<8)|SHIFTJIS_LOBYTE_START0);	// sneaky maths on both bytes, reduce to 0x0000 onwards

		if ( (uiCode & 0xFF) >= (SHIFTJIS_LOBYTE_START1)-SHIFTJIS_LOBYTE_START0)
		{
			uiCode -= ((SHIFTJIS_LOBYTE_START1)-SHIFTJIS_LOBYTE_STOP0)-1;
		}

		if ( ((uiCode>>8)&0xFF) >= (SHIFTJIS_HIBYTE_START1)-SHIFTJIS_HIBYTE_START0)
		{
			uiCode -= (((SHIFTJIS_HIBYTE_START1)-SHIFTJIS_HIBYTE_STOP0)-1) << 8;
		}

		uiCode = ((uiCode >> 8) * SHIFTJIS_CODES_PER_ROW) + (uiCode & 0xFF);

		return uiCode;
	}
	return 0;
}


#include "tr_font_sjis.h"

// Shift-JIS single bytes 0xA1-0xDF, half-width katakana, as their full-width
// forms: those are the ones the fonts and the glyph pages have
//
static const unsigned short g_sjisHalfWidth[63] = {
	0x3002,0x300C,0x300D,0x3001,0x30FB,0x30F2,0x30A1,0x30A3,0x30A5,0x30A7,0x30A9,0x30E3,0x30E5,0x30E7,0x30C3,0x30FC,
	0x30A2,0x30A4,0x30A6,0x30A8,0x30AA,0x30AB,0x30AD,0x30AF,0x30B1,0x30B3,0x30B5,0x30B7,0x30B9,0x30BB,0x30BD,0x30BF,
	0x30C1,0x30C4,0x30C6,0x30C8,0x30CA,0x30CB,0x30CC,0x30CD,0x30CE,0x30CF,0x30D2,0x30D5,0x30D8,0x30DB,0x30DE,0x30DF,
	0x30E0,0x30E1,0x30E2,0x30E4,0x30E6,0x30E8,0x30E9,0x30EA,0x30EB,0x30EC,0x30ED,0x30EF,0x30F3,0x309B,0x309C,
};

// Japanese text is handed around as Unicode like everything else, so that an
// outline font can draw it; these convert at the edges. (0 = no such character)
//
static unsigned int Japanese_ShiftJISToUnicode( unsigned int uiCode )
{
	const int iIndex = Japanese_CollapseShiftJISCode( uiCode );
	return (iIndex > 0 && iIndex < SJIS_TABLE_SIZE) ? g_sjisToUnicode[iIndex] : 0;
}

// ...and back to a glyph index in the game's own Japanese glyph pages
//
static int Japanese_CollapseUnicode( unsigned int uiLetter )
{
	static unsigned short pReverse[0x10000];
	static bool bBuilt = false;
	if (!bBuilt)
	{
		bBuilt = true;
		for (int i = SJIS_TABLE_SIZE - 1; i > 0; i--)	// backwards: of duplicates, keep the first
		{
			pReverse[g_sjisToUnicode[i]] = (unsigned short)i;
		}
		pReverse[0] = 0;
	}
	return (uiLetter >= 0x80 && uiLetter <= 0xFFFF) ? pReverse[uiLetter] : 0;
}

// A Shift-JIS character and the start of the next one can also be read as one
// UTF-8 character, so look a few characters ahead: true if the high bytes
// from here are well-formed UTF-8 for the kind of text that would be sent
// that way (kana, kanji, full-width forms, hangul, emoji).
//
static bool Font_UTF8RunAhead( const byte *psString )
{
	int iSequences = 0;
	while ((*psString & 0x80) && iSequences < 4)
	{
		int iAdvance = 1;
		const unsigned int uiCode = Q_UTF8_ReadCharFromString( (const char *)psString, &iAdvance );
		if (iAdvance < 3)
		{
			return false;
		}
		if (!(	(uiCode >= 0x3000 && uiCode <= 0x30FF) || (uiCode >= 0x4E00 && uiCode <= 0x9FFF) ||
				(uiCode >= 0xAC00 && uiCode <= 0xD7A3) || (uiCode >= 0xFE00 && uiCode <= 0xFFEF) ||
				(uiCode >= 0x2000 && uiCode <= 0x2BFF) || uiCode >= 0x10000 ))
		{
			return false;
		}
		psString += iAdvance;
		iSequences++;
	}
	return iSequences > 0;
}

static int Japanese_InitFields(int &iGlyphTPs, const char *&psLang)
{
	psLang		= "jap";
	iGlyphTPs	= GLYPH_MAX_JAPANESE_SHADERS;
	g_iNonScaledCharRange = 255;
	return 64;	// m_iAsianGlyphsAcross
}

// ======================== some Chinese stuff ==============================

#define GB_HIBYTE_START		0xA1	// range is...
#define GB_HIBYTE_STOP		0xF7	// ... inclusive
#define GB_LOBYTE_LOBOUND	0xA0	// range is...
#define GB_LOBYTE_HIBOUND	0xFF	// ...bounding (ie only valid in between these points, but NULLs in charsets for these codes)
#define GB_CODES_PER_ROW	95		// 1 more than the number of glyphs

extern qboolean Language_IsChinese( void );

static inline bool Chinese_ValidGBCode( byte _iHi, byte _iLo )
{
	return (_iHi >=GB_HIBYTE_START		&&
			_iHi <=GB_HIBYTE_STOP		&&
			_iLo > GB_LOBYTE_LOBOUND	&&
			_iLo < GB_LOBYTE_HIBOUND
			);
}

static inline bool Chinese_ValidGBCode( unsigned int uiCode)
{
	return Chinese_ValidGBCode( uiCode >> 8, uiCode & 0xFF );
}


// only call this when Chinese_ValidGBCode() has already returned true...
//
static bool Chinese_IsTrailingPunctuation( unsigned int uiCode )
{
	// so far I'm just counting the first 13 chars, those seem to be all the basic punctuation...
	//
	if (	uiCode >  ((GB_HIBYTE_START<<8)|GB_LOBYTE_LOBOUND) &&
			uiCode <  (((GB_HIBYTE_START<<8)|GB_LOBYTE_LOBOUND)+14)
		)
	{
		return true;
	}

	return false;
}


// takes a GB double-byte code and collapses down to a 0..n glyph index...
// Assumes rows are 96 wide (glyph slots), not 94 wide (actual glyphs), so I can ignore boundary markers
//
// (invalid GB codes will return 0)
//
static int Chinese_CollapseGBCode( unsigned int uiCode )
{
	if (Chinese_ValidGBCode( uiCode ))
	{
		uiCode -= (GB_HIBYTE_START * 256) + GB_LOBYTE_LOBOUND;	// sneaky maths on both bytes, reduce to 0x0000 onwards
		uiCode  = ((uiCode >> 8) * GB_CODES_PER_ROW) + (uiCode & 0xFF);
		return uiCode;
	}

	return 0;
}

static int Chinese_InitFields(int &iGlyphTPs, const char *&psLang)
{
	psLang		= "chi";
	iGlyphTPs	= GLYPH_MAX_CHINESE_SHADERS;
	g_iNonScaledCharRange = 255;
	return 64;	// m_iAsianGlyphsAcross
}

// ======================== some Thai stuff ==============================

//TIS 620-2533

#define TIS_GLYPHS_START	160
#define TIS_SARA_AM			0xD3		// special case letter, both a new letter and a trailing accent for the prev one
ThaiCodes_t g_ThaiCodes;	// the one and only instance of this object

extern qboolean Language_IsThai( void );

/*
static int Thai_IsAccentChar( unsigned int uiCode )
{
	switch (uiCode)
	{
		case 209:
		case 212:	case 213:	case 214:	case 215:	case 216:	case 217:	case 218:
		case 231:	case 232:	case 233:	case 234:	case 235:	case 236:	case 237:	case 238:
		return true;
	}

	return false;
}
*/

// returns a valid Thai code (or 0), based on taking 1,2 or 3 bytes from the supplied byte stream
//	Fills in <iThaiBytes> with 1,2 or 3
static int Thai_ValidTISCode( const byte *psString, int &iThaiBytes )
{
	// try a 1-byte code first...
	//
	if (psString[0] >= 160)	// so western letters drop through and use normal font
	{
		// this code is heavily little-endian, so someone else will need to port for Mac etc... (not my problem ;-)
		//
		union CodeToTry_t
		{
            char sChars[4];
			unsigned int uiCode;
		};

		CodeToTry_t CodeToTry;
		CodeToTry.uiCode = 0;	// important that we clear all 4 bytes in sChars here

		// thai codes can be up to 3 bytes long, so see how high we can get...
		//
		int i;
		for (i=0; i<3; i++)
		{
			CodeToTry.sChars[i] = psString[i];

            int iIndex = g_ThaiCodes.GetValidIndex( CodeToTry.uiCode );
			if (iIndex == -1)
			{
				// failed, so return previous-longest code...
				//
				CodeToTry.sChars[i] = 0;
				break;
			}
		}
		iThaiBytes = i;
		assert(i);	// if 'i' was 0, then this may be an error, trying to get a thai accent as standalone char?
		return CodeToTry.uiCode;
	}

	return 0;
}

// special case, thai can only break on certain letters, and since the rules are complicated then
//	we tell the translators to put an underscore ('_') between each word even though in Thai they're
//	all jammed together at final output onscreen...
//
static inline bool Thai_IsTrailingPunctuation( unsigned int uiCode )
{
	return uiCode == '_';
}

// takes a TIS 1,2 or 3 byte code and collapse down to a 0..n glyph index...
//
// (invalid codes will return 0)
//
static int Thai_CollapseTISCode( unsigned int uiCode )
{
	if (uiCode >= TIS_GLYPHS_START)	// so western letters drop through as invalid
	{
		int iCollapsedIndex = g_ThaiCodes.GetValidIndex( uiCode );
		if (iCollapsedIndex != -1)
		{
			return iCollapsedIndex;
		}
	}

	return 0;
}

static int Thai_InitFields(int &iGlyphTPs, const char *&psLang)
{
	psLang		= "tha";
	iGlyphTPs	= GLYPH_MAX_THAI_SHADERS;
	g_iNonScaledCharRange = INT_MAX;	// in other words, don't scale any thai chars down
	return 32;	// m_iAsianGlyphsAcross
}


// ============================================================================

// Windows-1250 (central european: polish, hungarian, czech...) 0x80-0xFF as Unicode
static const unsigned short g_cp1250[128] =
{
	0x20AC,0x0081,0x201A,0x0083,0x201E,0x2026,0x2020,0x2021,0x0088,0x2030,0x0160,0x2039,0x015A,0x0164,0x017D,0x0179,
	0x0090,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,0x0098,0x2122,0x0161,0x203A,0x015B,0x0165,0x017E,0x017A,
	0x00A0,0x02C7,0x02D8,0x0141,0x00A4,0x0104,0x00A6,0x00A7,0x00A8,0x00A9,0x015E,0x00AB,0x00AC,0x00AD,0x00AE,0x017B,
	0x00B0,0x00B1,0x02DB,0x0142,0x00B4,0x00B5,0x00B6,0x00B7,0x00B8,0x0105,0x015F,0x00BB,0x013D,0x02DD,0x013E,0x017C,
	0x0154,0x00C1,0x00C2,0x0102,0x00C4,0x0139,0x0106,0x00C7,0x010C,0x00C9,0x0118,0x00CB,0x011A,0x00CD,0x00CE,0x010E,
	0x0110,0x0143,0x0147,0x00D3,0x00D4,0x0150,0x00D6,0x00D7,0x0158,0x016E,0x00DA,0x0170,0x00DC,0x00DD,0x0162,0x00DF,
	0x0155,0x00E1,0x00E2,0x0103,0x00E4,0x013A,0x0107,0x00E7,0x010D,0x00E9,0x0119,0x00EB,0x011B,0x00ED,0x00EE,0x010F,
	0x0111,0x0144,0x0148,0x00F3,0x00F4,0x0151,0x00F6,0x00F7,0x0159,0x016F,0x00FA,0x0171,0x00FC,0x00FD,0x0163,0x02D9
};

// Windows-1252 (western european) 0x80-0x9F as Unicode; 0xA0-0xFF are the same in both
static const unsigned short g_cp1252[32] =
{
	0x20AC,0x0081,0x201A,0x0192,0x201E,0x2026,0x2020,0x2021,0x02C6,0x2030,0x0160,0x2039,0x0152,0x008D,0x017D,0x008F,
	0x0090,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,0x02DC,0x2122,0x0161,0x203A,0x0153,0x009D,0x017E,0x0178
};

// Windows-1251 (cyrillic) 0x80-0xBF as Unicode; 0xC0-0xFF are U+0410..U+044F
static const unsigned short g_cp1251[64] =
{
	0x0402,0x0403,0x201A,0x0453,0x201E,0x2026,0x2020,0x2021,0x20AC,0x2030,0x0409,0x2039,0x040A,0x040C,0x040B,0x040F,
	0x0452,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,0x0098,0x2122,0x0459,0x203A,0x045A,0x045C,0x045B,0x045F,
	0x00A0,0x040E,0x045E,0x0408,0x00A4,0x0490,0x00A6,0x00A7,0x0401,0x00A9,0x0404,0x00AB,0x00AC,0x00AD,0x00AE,0x0407,
	0x00B0,0x00B1,0x0406,0x0456,0x0491,0x00B5,0x00B6,0x00B7,0x0451,0x2116,0x0454,0x00BB,0x0458,0x0405,0x0455,0x0457
};

// Text that is not valid UTF-8 is in the single-byte codepage of the game's
// language: stock string files, old translations, chat from other clients.
// Characters are passed around as Unicode, so a raw high byte is translated
// here, on the way in...
//
static cvar_t *r_fontCodepage;

// which codepage that is: r_fontCodepage, or the game's language when it is 0
static Language_e Font_LegacyLanguage( void )
{
	switch ( r_fontCodepage ? r_fontCodepage->integer : 0 )
	{
		case 1250:	return ePolish;
		case 1251:	return eRussian;
		case 1252:	return eWestern;
		default:	break;
	}
	// (Russian localisations that replace the base fonts rather than use the
	// engine's "russian" override name their language "Rus")
	//
	if (se_language && !Q_stricmpn( se_language->string, "rus", 3 ))
	{
		return eRussian;
	}
	return GetLanguageEnum();
}

static unsigned int Font_LegacyByteToUnicode( unsigned int uiByte )
{
	if (uiByte < 0x80 || uiByte > 0xFF)
	{
		return uiByte;
	}
	switch ( Font_LegacyLanguage() )
	{
		case eRussian:
		case eUkrainian:	return (uiByte >= 0xC0) ? uiByte - 0xC0 + 0x0410 : g_cp1251[uiByte - 0x80];
		case ePolish:
		case eHungarian:
		case eCzech:
		case eSlovak:	return g_cp1250[uiByte - 0x80];
		case eWestern:	return (uiByte <= 0x9F) ? g_cp1252[uiByte - 0x80] : uiByte;
		case eJapanese:	return (uiByte >= 0xA1 && uiByte <= 0xDF) ? g_sjisHalfWidth[uiByte - 0xA1] : uiByte;
		default:		return uiByte;
	}
}

// ...and back again for the bitmap fonts, whose glyphs sit in codepage slots.
// Returns the character unchanged when the codepage has no slot for it.
//
static unsigned int Font_UnicodeToLegacyByte( unsigned int uiLetter )
{
	if (uiLetter <= 0xFF)
	{
		return uiLetter;
	}
	switch ( Font_LegacyLanguage() )
	{
		case eRussian:
		case eUkrainian:
			if (uiLetter >= 0x0410 && uiLetter <= 0x044F)
			{
				return uiLetter - 0x0410 + 0xC0;
			}
			for (int i = 0; i < 64; i++)
			{
				if (g_cp1251[i] == uiLetter) return 0x80 + i;
			}
			break;
		case ePolish:
		case eHungarian:
		case eCzech:
		case eSlovak:
			for (int i = 0; i < 128; i++)
			{
				if (g_cp1250[i] == uiLetter) return 0x80 + i;
			}
			break;
		case eWestern:
			for (int i = 0; i < 32; i++)
			{
				if (g_cp1252[i] == uiLetter) return 0x80 + i;
			}
			break;
		default:
			break;
	}
	return uiLetter;
}

// takes char *, returns integer char at that point, and advances char * on by enough bytes to move
//	past the letter (either western 1 byte or Asian multi-byte)...
//
// looks messy, but the actual execution route is quite short, so it's fast...
//
// Note that I have to have this 3-param form instead of advancing a passed-in "const char **psText" because of VM-crap where you can only change ptr-contents, not ptrs themselves. Bleurgh. Ditto the qtrue:qfalse crap instead of just returning stuff straight through.
//
unsigned int AnyLanguage_ReadCharFromString( const char *psText, int *piAdvanceCount, qboolean *pbIsTrailingPunctuation /* = NULL */)
{
	const byte *psString = (const byte *) psText;	// avoid sign-promote bug
	unsigned int uiLetter;

	switch ( GetLanguageEnum() )
	{
		case eKorean:
		{
			// (chat and names from updated clients are UTF-8 whatever the language)
			//
			if ( !Font_UTF8RunAhead( psString ) && Korean_ValidKSC5601Hangul( psString[0], psString[1] ))
			{
				uiLetter = (psString[0] * 256) + psString[1];
				*piAdvanceCount = 2;

				// not going to bother testing for korean punctuation here, since korean already
				//	uses spaces, and I don't have the punctuation glyphs defined, only the basic 2350 hanguls
				//
				if ( pbIsTrailingPunctuation)
				{
					*pbIsTrailingPunctuation = qfalse;
				}

				uiLetter = Korean_KSCToUnicode( uiLetter );
				return uiLetter ? uiLetter : 0x3000;	// unassigned code: a blank, as the glyph pages have
			}
		}
		break;

		case eTaiwanese:
		{
			if ( Taiwanese_ValidBig5Code( (psString[0] * 256) + psString[1] ))
			{
				uiLetter = (psString[0] * 256) + psString[1];
				*piAdvanceCount = 2;

				// need to ask if this is a trailing (ie like a comma or full-stop) punctuation?...
				//
				if ( pbIsTrailingPunctuation)
				{
					*pbIsTrailingPunctuation = Taiwanese_IsTrailingPunctuation( uiLetter ) ? qtrue : qfalse;
				}

				return uiLetter;
			}
		}
		break;

		case eJapanese:
		{
			// (chat and names from updated clients are UTF-8 whatever the language)
			//
			if ( !Font_UTF8RunAhead( psString ) && Japanese_ValidShiftJISCode( psString[0], psString[1] ))
			{
				uiLetter = (psString[0] * 256) + psString[1];
				*piAdvanceCount = 2;

				// need to ask if this is a trailing (ie like a comma or full-stop) punctuation?...
				//
				if ( pbIsTrailingPunctuation)
				{
					*pbIsTrailingPunctuation = Japanese_IsTrailingPunctuation( uiLetter ) ? qtrue : qfalse;
				}

				uiLetter = Japanese_ShiftJISToUnicode( uiLetter );
				return uiLetter ? uiLetter : 0x3000;	// unassigned code: a blank, as the glyph pages have
			}
		}
		break;

		case eChinese:
		{
			if ( Chinese_ValidGBCode( (psString[0] * 256) + psString[1] ))
			{
				uiLetter = (psString[0] * 256) + psString[1];
				*piAdvanceCount = 2;

				// need to ask if this is a trailing (ie like a comma or full-stop) punctuation?...
				//
				if ( pbIsTrailingPunctuation)
				{
					*pbIsTrailingPunctuation = Chinese_IsTrailingPunctuation( uiLetter ) ? qtrue : qfalse;
				}

				return uiLetter;
			}
		}
		break;

		case eThai:
		{
			// Thai in UTF-8 (U+0E00-U+0E7F, E0 B8/B9 xx) is read as UTF-8 below, and the
			// TIS-620 codes only mean something when the game's Thai glyph data is installed
			//
			int iUTF8Advance = 1;
			const unsigned int uiUTF8 = Q_UTF8_ReadCharFromString( (const char *)psString, &iUTF8Advance );
			if ( (iUTF8Advance == 3 && uiUTF8 >= 0x0E00 && uiUTF8 <= 0x0E7F) || g_ThaiCodes.m_mapValidCodes.empty() )
			{
				break;
			}

			int iThaiBytes;
			uiLetter = Thai_ValidTISCode( psString, iThaiBytes );
			if ( uiLetter )
			{
				*piAdvanceCount = iThaiBytes;

				if ( pbIsTrailingPunctuation )
				{
					*pbIsTrailingPunctuation = Thai_IsTrailingPunctuation( uiLetter ) ? qtrue : qfalse;
				}

				return uiLetter;
			}
		}
		break;

		default:
		break;
	}

	// ... must not have been an MBCS code...
	//
	// try UTF-8 before falling back to a raw single byte. Invalid/truncated
	// sequences decode as raw bytes, so legacy cp1251/SBCS text keeps working...
	//
	// (...except straight after a legacy byte: a capital and a symbol in the
	// middle of a codepage word can pass for one UTF-8 character)
	//
	static const byte *psLegacyRunNext = NULL;

	if ((psString[0] & 0x80) && psString != psLegacyRunNext)
	{
		int iUTF8Advance = 1;
		unsigned int uiCode = Q_UTF8_ReadCharFromString((const char*)psString, &iUTF8Advance);
		if (iUTF8Advance > 1)
		{
			*piAdvanceCount = iUTF8Advance;
			if (pbIsTrailingPunctuation)
			{
				*pbIsTrailingPunctuation = qfalse;
			}
			return uiCode;
		}
	}

	uiLetter = Font_LegacyByteToUnicode( psString[0] );
	*piAdvanceCount = 1;
	psLegacyRunNext = (psString[0] & 0x80) ? psString + 1 : NULL;

	if (pbIsTrailingPunctuation)
	{
		*pbIsTrailingPunctuation = (uiLetter == '!' ||
									uiLetter == '?' ||
									uiLetter == ',' ||
									uiLetter == '.' ||
									uiLetter == ';' ||
									uiLetter == ':'
									) ? qtrue : qfalse;
	}

	return uiLetter;
}


// needed for subtitle printing since original code no longer worked once camera bar height was changed to 480/10
//	rather than refdef height / 10. I now need to bodge the coords to come out right.
//
qboolean Language_IsAsian(void)
{
	switch ( GetLanguageEnum() )
	{
		case eKorean:
		case eTaiwanese:
		case eJapanese:
		case eChinese:
		case eThai:	// this is asian, but the query is normally used for scaling
			return qtrue;
		default:
			break;
	}

	return qfalse;
}

qboolean Language_UsesSpaces(void)
{
	// ( korean uses spaces )
	switch ( GetLanguageEnum() )
	{
		case eTaiwanese:
		case eJapanese:
		case eChinese:
		case eThai:
			return qfalse;
		default:
			break;
	}

	return qtrue;
}

// ======================================================================
// name is (eg) "ergo" or "lcd", no extension.
//
//  If path present, it's a special language hack for SBCS override languages, eg: "lcd/russian", which means
//	  just treat the file as "russian", but with the "lcd" part ensuring we don't find a different registered russian font
//
static const char *FontDatPath( const char *_fontName ) {
	static char fontName[MAX_QPATH];
	Com_sprintf( fontName,sizeof(fontName), "fonts/%s.fontdat",COM_SkipPath(const_cast<char*>(_fontName)) );	// COM_SkipPath should take a const char *, but it's just possible people use it as a char * I guess, so I have to hack around like this <groan>
	return fontName;
}
CFontInfo::CFontInfo(const char *_fontName)
{
	int			len, i;
	void		*buff;
	dfontdat_t	*fontdat;

	// remove any special hack name insertions...
	//
	const char *fontName = FontDatPath( _fontName );

	// clear some general things...
	//
	m_pThaiData = NULL;
	m_iAltSBCSFont = -1;
	m_iThisFont = -1;
	m_iOriginalFontWhenSBCSOverriden = -1;
	m_fAltSBCSFontScaleFactor = -1;
	{
		char sBaseName[MAX_QPATH];
		int iDummy;
		Font_SplitSizedName(_fontName, sBaseName, sizeof(sBaseName), &iDummy);	// (may be "aurabesh@18")
		m_bIsFakeAlienLanguage = !strcmp(sBaseName,"aurabesh");	// dont try and make SBCS or asian overrides for this
	}
	m_isVariant = qfalse;

#ifdef USE_FREETYPE
	m_bTTF = false;
	m_ftFace = NULL;
	m_pFaceData = NULL;
	m_iTTFNumPages = 0;
	memset(m_TTFPages, 0, sizeof(m_TTFPages));
	m_iTTFNumColorPages = 0;
	memset(m_TTFColorPages, 0, sizeof(m_TTFColorPages));
	m_iTTFAtlasSize = TTF_ATLAS_SIZE;
	m_bTTFAtlasFull = false;
	memset(m_TTFDirect, 0, sizeof(m_TTFDirect));
	m_uiTTFPrecachedBlocks = 0;
#endif
	memset(mGlyphs, 0, sizeof(mGlyphs));
	mPointSize = 0;
	mHeight = 0;
	mAscender = 0;
	mDescender = 0;

	len = ri.FS_ReadFile(fontName, NULL);

#ifdef USE_FREETYPE
	// r_useFreeType 2 = prefer TTF/OTF over .fontdat even when both exist...
	if (r_useFreeType && r_useFreeType->integer >= 2)
	{
		TTF_Init(_fontName);
	}
	if (!m_bTTF && len == sizeof(dfontdat_t))
#else
	if (len == sizeof(dfontdat_t))
#endif
	{
		ri.FS_ReadFile(fontName, &buff);
		fontdat = (dfontdat_t *)buff;

		for(i = 0; i < GLYPH_COUNT; i++)
		{
#ifdef Q3_BIG_ENDIAN
			mGlyphs[i].width = LittleShort(fontdat->mGlyphs[i].width);
			mGlyphs[i].height = LittleShort(fontdat->mGlyphs[i].height);
			mGlyphs[i].horizAdvance = LittleShort(fontdat->mGlyphs[i].horizAdvance);
			mGlyphs[i].horizOffset = LittleShort(fontdat->mGlyphs[i].horizOffset);
			mGlyphs[i].baseline = LittleLong(fontdat->mGlyphs[i].baseline);
			mGlyphs[i].s = LittleFloat(fontdat->mGlyphs[i].s);
			mGlyphs[i].t = LittleFloat(fontdat->mGlyphs[i].t);
			mGlyphs[i].s2 = LittleFloat(fontdat->mGlyphs[i].s2);
			mGlyphs[i].t2 = LittleFloat(fontdat->mGlyphs[i].t2);
#else
			mGlyphs[i] = fontdat->mGlyphs[i];
#endif
		}
		mPointSize = LittleShort(fontdat->mPointSize);
		mHeight = LittleShort(fontdat->mHeight);
		mAscender = LittleShort(fontdat->mAscender);
		mDescender = LittleShort(fontdat->mDescender);
//		mAsianHack = LittleShort(fontdat->mKoreanHack);	// ignore this crap, it's some junk in the fontdat file that no-one uses
		mbRoundCalcs = false /*!!strstr(fontName,"ergo")*/;

		// cope with bad fontdat headers...
		//
		if (mHeight == 0)
		{
			mHeight = mPointSize;
            mAscender = mPointSize - Round( ((float)mPointSize/10.0f)+2 );	// have to completely guess at the baseline... sigh.
            mDescender = mHeight - mAscender;
		}

		ri.FS_FreeFile(buff);
	}
	else
	{
#ifdef USE_FREETYPE
		if (!m_bTTF)	// (may already be loaded via the r_useFreeType 2 path above)
		{
		mHeight = 0;
		mShader = 0;
			TTF_Init(_fontName);	// sets m_bTTF and font metrics on success
		}
#else
		mHeight = 0;
		mShader = 0;
#endif
	}

	Q_strncpyz(m_sFontName, fontName, sizeof(m_sFontName));
	COM_StripExtension( m_sFontName, m_sFontName, sizeof( m_sFontName ) );	// so we get better error printing if failed to load shader (ie lose ".fontdat")
#ifdef USE_FREETYPE
	if (m_bTTF)
	{
		mShader = 0;	// glyphs live on dynamically created atlas shaders instead
	}
	else
#endif
	{
	mShader = RE_RegisterShaderNoMip(m_sFontName);
	}

	FlagNoAsianGlyphs();
	UpdateAsianIfNeeded(true);

	// finished...
	g_vFontArray.resize(g_iCurrentFontIndex + 1);
	m_handle = g_iCurrentFontIndex;
	g_vFontArray[g_iCurrentFontIndex++] = this;


	if ( ri.Cvar_VariableIntegerValue( "com_buildScript" ) == 2)
	{
		Com_Printf( "com_buildScript(2): Registering foreign fonts...\n" );
		static qboolean bDone = qfalse;	// Do this once only (for speed)...
		if (!bDone)
		{
			bDone = qtrue;

			char sTemp[MAX_QPATH];
			int iGlyphTPs = 0;
			const char *psLang = NULL;

			// SBCS override languages...
			//
			fileHandle_t f;
			for (int i=0; g_SBCSOverrideLanguages[i].m_psName ;i++)
			{
				char sTemp[MAX_QPATH];

				Com_sprintf(sTemp, sizeof(sTemp), "fonts/%s.tga", g_SBCSOverrideLanguages[i].m_psName );
				ri.FS_FOpenFileRead( sTemp, &f, qfalse );
				if (f) ri.FS_FCloseFile( f );

				Com_sprintf(sTemp, sizeof(sTemp), "fonts/%s.fontdat", g_SBCSOverrideLanguages[i].m_psName );
				ri.FS_FOpenFileRead( sTemp, &f, qfalse );
				if (f) ri.FS_FCloseFile( f );
			}

			// asian MBCS override languages...
			//
			for (int iLang=0; iLang<5; iLang++)
			{
				switch (iLang)
				{
					case 0:	m_iAsianGlyphsAcross = Korean_InitFields	(iGlyphTPs, psLang);	break;
					case 1: m_iAsianGlyphsAcross = Taiwanese_InitFields	(iGlyphTPs, psLang);	break;
					case 2: m_iAsianGlyphsAcross = Japanese_InitFields	(iGlyphTPs, psLang);	break;
					case 3: m_iAsianGlyphsAcross = Chinese_InitFields	(iGlyphTPs, psLang);	break;
					case 4: m_iAsianGlyphsAcross = Thai_InitFields		(iGlyphTPs, psLang);
					{
						// additional files needed for Thai language...
						//
						ri.FS_FOpenFileRead( sFILENAME_THAI_WIDTHS , &f, qfalse );
						if (f) {
							ri.FS_FCloseFile( f );
						}

						ri.FS_FOpenFileRead( sFILENAME_THAI_CODES, &f, qfalse );
						if (f) {
							ri.FS_FCloseFile( f );
						}
					}
                    break;
				}

				for (int i=0; i<iGlyphTPs; i++)
				{
					Com_sprintf(sTemp,sizeof(sTemp), "fonts/%s_%d_1024_%d.tga", psLang, 1024/m_iAsianGlyphsAcross, i);

					// RE_RegisterShaderNoMip( sTemp );	// don't actually need to load it, so...
					ri.FS_FOpenFileRead( sTemp, &f, qfalse );
					if (f) {
						ri.FS_FCloseFile( f );
					}
				}
			}
		}
	}

	m_numVariants = 0;
}

#ifdef USE_FREETYPE
// ==================== TTF/OTF (FreeType) support ====================
//
// Fonts are rasterized at exactly mPointSize pixels; high-res crispness is
// achieved through the existing font-variant system (see RE_RegisterFont).
//
static bool g_bTTFRegisteringVariant = false;	// see CFontInfo::TTF_Init

bool CFontInfo::TTF_Init(const char* psName)
{
	char			sBaseName[MAX_QPATH];
	char			sPath[MAX_QPATH];
	int				iPointSize;
	int				iLen = -1;
	const char* psExtensions[] = { "ttf", "otf" };
	fileBuffer_t	buff;

	if (!g_FTLibrary || !r_useFreeType || !r_useFreeType->integer)
	{
		return false;
	}

	Font_SplitSizedName(psName, sBaseName, sizeof(sBaseName), &iPointSize);

	// a TTF standing in for a bitmap font keeps that font's point size, whatever
	// size was asked for: menus and HUD were laid out against the bitmap font's
	// glyph metrics, and text scales are relative to its size. (the hi-res
	// variants ask for a multiple of that size, and have to get it)
	if (!g_bTTFRegisteringVariant)
	{
		Com_sprintf(sPath, sizeof(sPath), "fonts/%s.fontdat", COM_SkipPath(sBaseName));
		if (ri.FS_ReadFile(sPath, NULL) == sizeof(dfontdat_t))
		{
			ri.FS_ReadFile(sPath, &buff.v);
			const int iBitmapPointSize = LittleShort(((dfontdat_t*)buff.v)->mPointSize);
			ri.FS_FreeFile(buff.v);
			if (iBitmapPointSize > 0)
			{
				iPointSize = iBitmapPointSize;
			}
		}
	}

	for (size_t i = 0; i < ARRAY_LEN(psExtensions); i++)
	{
		Com_sprintf(sPath, sizeof(sPath), "fonts/%s.%s", COM_SkipPath(sBaseName), psExtensions[i]);
		iLen = ri.FS_ReadFile(sPath, NULL);
		if (iLen > 0)
		{
			break;
		}
	}

	if (iLen <= 0)
	{
		return false;
	}

	ri.FS_ReadFile(sPath, &buff.v);
	m_pFaceData = new byte[iLen];
	memcpy(m_pFaceData, buff.b, iLen);
	ri.FS_FreeFile(buff.v);

	if (FT_New_Memory_Face(g_FTLibrary, m_pFaceData, iLen, 0, &m_ftFace) != 0)
	{
		ri.Printf(PRINT_WARNING, "TTF_Init: FT_New_Memory_Face failed on %s\n", sPath);
		m_ftFace = NULL;
		delete[] m_pFaceData;
		m_pFaceData = NULL;
		return false;
	}

	if (FT_Set_Pixel_Sizes(m_ftFace, 0, iPointSize) != 0)
	{
		ri.Printf(PRINT_WARNING, "TTF_Init: FT_Set_Pixel_Sizes(%d) failed on %s\n", iPointSize, sPath);
		FT_Done_Face(m_ftFace);
		m_ftFace = NULL;
		delete[] m_pFaceData;
		m_pFaceData = NULL;
		return false;
	}

	mPointSize = iPointSize;
	mHeight = (int)(m_ftFace->size->metrics.height >> 6);
	mAscender = (int)(m_ftFace->size->metrics.ascender >> 6);
	mDescender = (int)((-m_ftFace->size->metrics.descender) >> 6);	// FT descender is negative, JA wants positive

	if (mHeight <= 0)
	{
		mHeight = mPointSize;
		mAscender = mPointSize - Round(((float)mPointSize / 10.0f) + 2);
		mDescender = mHeight - mAscender;
	}

	// size the atlas pages so that the glyphs of ordinary text end up on one
	// page: quads are only batched into a single draw while their shader (ie
	// their page) stays the same. Matters for the hi-res variants, whose
	// glyphs are several times larger than the base font's...
	m_iTTFAtlasSize = TTF_ATLAS_SIZE;
	while (m_iTTFAtlasSize < TTF_ATLAS_MAX_SIZE && iPointSize * 18 > m_iTTFAtlasSize)
	{
		m_iTTFAtlasSize <<= 1;
	}
	while (m_iTTFAtlasSize > TTF_ATLAS_SIZE && glConfig.maxTextureSize > 0 && m_iTTFAtlasSize > glConfig.maxTextureSize)
	{
		m_iTTFAtlasSize >>= 1;
	}

	mbRoundCalcs = false;
	m_bTTF = true;

	return true;
}

// simple shelf packer over up to TTF_ATLAS_MAX_PAGES atlas textures...
//
TTFAtlasPage_t* CFontInfo::TTF_AllocAtlasSpace(int iWidth, int iHeight, int* piX, int* piY, bool bColor)
{
	const int iPaddedW = iWidth + TTF_GLYPH_PADDING;
	const int iPaddedH = iHeight + TTF_GLYPH_PADDING;

	if (iPaddedW > m_iTTFAtlasSize || iPaddedH > m_iTTFAtlasSize)
	{
		return NULL;	// glyph bigger than a whole page?!
	}

	// text glyphs live on vertex-tinted pages, colour glyphs (emoji) on
	// identity-colour pages -- see R_Font_CreateAtlasImage...
	TTFAtlasPage_t* pPageArray = bColor ? m_TTFColorPages : m_TTFPages;
	int& iNumPages = bColor ? m_iTTFNumColorPages : m_iTTFNumPages;

	TTFAtlasPage_t* pPage = (iNumPages > 0) ? &pPageArray[iNumPages - 1] : NULL;

	if (pPage)
	{
		if (pPage->iCursorX + iPaddedW > m_iTTFAtlasSize)
		{
			// start a new shelf...
			pPage->iCursorX = 0;
			pPage->iCursorY += pPage->iRowHeight;
			pPage->iRowHeight = 0;
		}
		if (pPage->iCursorY + iPaddedH > m_iTTFAtlasSize)
		{
			pPage = NULL;	// page is full
		}
	}

	if (!pPage)
	{
		if (iNumPages == TTF_ATLAS_MAX_PAGES)
		{
			if (!m_bTTFAtlasFull)
			{
				m_bTTFAtlasFull = true;
				ri.Printf(PRINT_WARNING, "TTF font %s: out of atlas pages\n", m_sFontName);
			}
			return NULL;
		}
		// creating an image can make the renderer issue the draw commands
		// queued so far, so the glyphs they use must be on the GPU first...
		TTF_FlushUploads();
		pPage = &pPageArray[iNumPages++];
		pPage->iCursorX = pPage->iCursorY = pPage->iRowHeight = 0;
		pPage->pImage = R_Font_CreateAtlasImage(m_iTTFAtlasSize, m_iTTFAtlasSize, &pPage->hShader, bColor ? qtrue : qfalse, &pPage->hShadowShader);
		if (!pPage->pImage)
		{
			iNumPages--;
			return NULL;
		}
	}

	*piX = pPage->iCursorX;
	*piY = pPage->iCursorY;

	pPage->iCursorX += iPaddedW;
	if (iPaddedH > pPage->iRowHeight)
	{
		pPage->iRowHeight = iPaddedH;
	}

	return pPage;
}

// ==================== GSUB ligatures: emoji ZWJ / flag / keycap sequences ====================
//
// FreeType rasterizes single glyphs but does no OpenType shaping, so multi-
// codepoint emoji (family 👨‍👩‍👧, flags 🇱🇻, keycaps 1️⃣, skin tones 👍🏽) fall apart
// into their components. Colour emoji fonts (Twemoji Mozilla, Segoe UI Emoji)
// express those sequences as plain GSUB LigatureSubst lookups, so we parse just
// that one lookup type out of the raw GSUB table and apply it ourselves.
//
struct GSUBLigature_t
{
	std::vector<FT_UInt>	comps;	// component glyphs AFTER the first one
	FT_UInt					lig;	// resulting ligature glyph
};

struct GSUBData_t
{
	std::map<FT_UInt, std::vector<GSUBLigature_t> > ligMap;	// first component glyph -> candidates (longest first)
};

static std::map<FT_Face, GSUBData_t> g_GSUBCache;

// set while RE_Font_DrawString renders its dropshadow pass: colour glyphs then
// hand out their vertex-tinted shadow shader instead of the identity one...
static bool g_bFontShadowPass = false;

static inline FT_UInt  GSUB_U16(const byte* p) { return ((FT_UInt)p[0] << 8) | p[1]; }
static inline FT_ULong GSUB_U32(const byte* p) { return ((FT_ULong)p[0] << 24) | ((FT_ULong)p[1] << 16) | ((FT_ULong)p[2] << 8) | p[3]; }

static bool GSUB_LigatureLonger(const GSUBLigature_t& a, const GSUBLigature_t& b)
{
	return a.comps.size() > b.comps.size();
}

// LigatureSubstFormat1 (GSUB LookupType 4)...
static void GSUB_ParseLigSubtable(const byte* pTable, FT_ULong iLen, FT_ULong iOffset, GSUBData_t& data)
{
	if (iOffset > iLen || iLen - iOffset < 6)
	{
		return;
	}
	const byte* pSub = pTable + iOffset;
	if (GSUB_U16(pSub) != 1)
	{
		return;
	}
	const FT_ULong	covOff = iOffset + GSUB_U16(pSub + 2);
	const FT_UInt	ligSetCount = GSUB_U16(pSub + 4);

	// coverage table: which glyph starts which LigatureSet...
	std::vector<FT_UInt> coverage;
	if (covOff + 4 > iLen)
	{
		return;
	}
	const byte* pCov = pTable + covOff;
	const FT_UInt covFmt = GSUB_U16(pCov);
	if (covFmt == 1)
	{
		const FT_UInt n = GSUB_U16(pCov + 2);
		if (covOff + 4 + (FT_ULong)n * 2 > iLen)
		{
			return;
		}
		for (FT_UInt i = 0; i < n; i++)
		{
			coverage.push_back(GSUB_U16(pCov + 4 + i * 2));
		}
	}
	else if (covFmt == 2)
	{
		const FT_UInt n = GSUB_U16(pCov + 2);
		if (covOff + 4 + (FT_ULong)n * 6 > iLen)
		{
			return;
		}
		for (FT_UInt i = 0; i < n && coverage.size() < 0x10000; i++)
		{
			const FT_UInt iStart = GSUB_U16(pCov + 4 + i * 6);
			const FT_UInt iEnd = GSUB_U16(pCov + 4 + i * 6 + 2);
			for (FT_UInt g = iStart; g <= iEnd && coverage.size() < 0x10000; g++)
			{
				coverage.push_back(g);
			}
		}
	}
	else
	{
		return;
	}

	if (iOffset + 6 + (FT_ULong)ligSetCount * 2 > iLen)
	{
		return;
	}

	for (FT_UInt s = 0; s < ligSetCount && s < coverage.size(); s++)
	{
		const FT_ULong setOff = iOffset + GSUB_U16(pSub + 6 + s * 2);
		if (setOff + 2 > iLen)
		{
			continue;
		}
		const FT_UInt ligCount = GSUB_U16(pTable + setOff);
		if (setOff + 2 + (FT_ULong)ligCount * 2 > iLen)
		{
			continue;
		}
		for (FT_UInt l = 0; l < ligCount; l++)
		{
			const FT_ULong ligOff = setOff + GSUB_U16(pTable + setOff + 2 + l * 2);
			if (ligOff + 4 > iLen)
			{
				continue;
			}
			const FT_UInt ligGlyph = GSUB_U16(pTable + ligOff);
			const FT_UInt compCount = GSUB_U16(pTable + ligOff + 2);
			if (compCount < 2 || compCount > 32 || ligOff + 4 + (FT_ULong)(compCount - 1) * 2 > iLen)
			{
				continue;
			}
			GSUBLigature_t entry;
			entry.lig = ligGlyph;
			for (FT_UInt c = 1; c < compCount; c++)
			{
				entry.comps.push_back(GSUB_U16(pTable + ligOff + 4 + (c - 1) * 2));
			}
			data.ligMap[coverage[s]].push_back(entry);
		}
	}
}

static GSUBData_t* Font_GetGSUB(FT_Face pFace)
{
	std::map<FT_Face, GSUBData_t>::iterator it = g_GSUBCache.find(pFace);
	if (it != g_GSUBCache.end())
	{
		return &(*it).second;
	}

	GSUBData_t& data = g_GSUBCache[pFace];	// inserted empty: negative result caches too

	FT_ULong iLen = 0;
	if (FT_Load_Sfnt_Table(pFace, FT_MAKE_TAG('G', 'S', 'U', 'B'), 0, NULL, &iLen) != 0 || iLen < 10)
	{
		return &data;
	}
	byte* pTable = new byte[iLen];
	if (FT_Load_Sfnt_Table(pFace, FT_MAKE_TAG('G', 'S', 'U', 'B'), 0, pTable, &iLen) != 0)
	{
		delete[] pTable;
		return &data;
	}

	// header: version(4) scriptList(2) featureList(2) lookupList(2). We take
	// every ligature lookup in the font regardless of script/feature: only
	// emoji sequences ever reach the matcher, so 'liga'-style text ligatures
	// (fi/fl) can never fire by accident...
	const FT_ULong lookupListOff = GSUB_U16(pTable + 8);
	if (lookupListOff + 2 <= iLen)
	{
		const FT_UInt lookupCount = GSUB_U16(pTable + lookupListOff);
		if (lookupListOff + 2 + (FT_ULong)lookupCount * 2 <= iLen)
		{
			for (FT_UInt i = 0; i < lookupCount; i++)
			{
				const FT_ULong lookOff = lookupListOff + GSUB_U16(pTable + lookupListOff + 2 + i * 2);
				if (lookOff + 6 > iLen)
				{
					continue;
				}
				const FT_UInt uiType = GSUB_U16(pTable + lookOff);
				const FT_UInt subCount = GSUB_U16(pTable + lookOff + 4);
				if (lookOff + 6 + (FT_ULong)subCount * 2 > iLen)
				{
					continue;
				}
				for (FT_UInt s = 0; s < subCount; s++)
				{
					const FT_ULong subOff = lookOff + GSUB_U16(pTable + lookOff + 6 + s * 2);
					if (uiType == 4)
					{
						GSUB_ParseLigSubtable(pTable, iLen, subOff, data);
					}
					else if (uiType == 7)	// extension: 32-bit offset wrapper
					{
						if (subOff + 8 > iLen || GSUB_U16(pTable + subOff) != 1)
						{
							continue;
						}
						if (GSUB_U16(pTable + subOff + 2) == 4)
						{
							const FT_ULong extOff = GSUB_U32(pTable + subOff + 4);
							if (extOff <= iLen - subOff)
							{
								GSUB_ParseLigSubtable(pTable, iLen, subOff + extOff, data);
							}
						}
					}
				}
			}
		}
	}
	delete[] pTable;

	// longest-match-first within each starting glyph...
	for (std::map<FT_UInt, std::vector<GSUBLigature_t> >::iterator itLig = data.ligMap.begin(); itLig != data.ligMap.end(); ++itLig)
	{
		std::stable_sort((*itLig).second.begin(), (*itLig).second.end(), GSUB_LigatureLonger);
	}

	return &data;
}

// repeatedly substitute leftmost-longest ligatures until stable. Multi-stage
// sequences (skin-toned pairs etc) need more than one pass...
static bool GSUB_ApplyLigatures(GSUBData_t* pData, std::vector<FT_UInt>& glyphs)
{
	bool bAny = false;
	for (int iPass = 0; iPass < 8; iPass++)
	{
		bool bSubstituted = false;
		for (size_t i = 0; i < glyphs.size(); i++)
		{
			std::map<FT_UInt, std::vector<GSUBLigature_t> >::const_iterator it = pData->ligMap.find(glyphs[i]);
			if (it == pData->ligMap.end())
			{
				continue;
			}
			const std::vector<GSUBLigature_t>& vLigs = (*it).second;
			for (size_t l = 0; l < vLigs.size(); l++)
			{
				const GSUBLigature_t& lig = vLigs[l];
				if (i + 1 + lig.comps.size() > glyphs.size())
				{
					continue;
				}
				bool bMatch = true;
				for (size_t c = 0; c < lig.comps.size(); c++)
				{
					if (glyphs[i + 1 + c] != lig.comps[c])
					{
						bMatch = false;
						break;
					}
				}
				if (bMatch)
				{
					glyphs[i] = lig.lig;
					glyphs.erase(glyphs.begin() + i + 1, glyphs.begin() + i + 1 + lig.comps.size());
					bSubstituted = bAny = true;
					break;
				}
			}
		}
		if (!bSubstituted)
		{
			break;
		}
	}
	return bAny;
}

// codepoints that glue an emoji sequence together...
static inline bool Font_IsSeqLinker(unsigned int cp)
{
	return cp == 0x200D							// zero-width joiner
		|| cp == 0xFE0E || cp == 0xFE0F			// variation selectors 15/16
		|| (cp >= 0x1F3FB && cp <= 0x1F3FF)		// skin tone modifiers
		|| cp == 0x20E3							// combining keycap
		|| (cp >= 0xE0020 && cp <= 0xE007F);	// tag characters (subdivision flags)
}

static inline bool Font_IsRegionalIndicator(unsigned int cp)
{
	return cp >= 0x1F1E6 && cp <= 0x1F1FF;
}

// If the text at *ppsText continues uiFirst into an emoji sequence the font can
// ligate, rasterize the ligature, advance *ppsText past the consumed codepoints
// and return the glyph. Returns NULL (and leaves *ppsText alone) otherwise.
//
const glyphInfo_t* CFontInfo::GetSequenceGlyph(unsigned int uiFirst, const char** ppsText, int* piShader /* = NULL */)
{
	if (!m_bTTF || !m_ftFace || !ppsText || !*ppsText)
	{
		return NULL;
	}

	// cheap gate: every linker/regional-indicator starts with a UTF-8 lead
	// byte >= 0xE2, so plain text bails after one byte compare...
	if ((unsigned char)(*ppsText)[0] < 0xE2)
	{
		return NULL;
	}

	const char* ps = *ppsText;
	int iAdvance;
	unsigned int cp = AnyLanguage_ReadCharFromString(ps, &iAdvance, NULL);

	const bool bRegionalPair = Font_IsRegionalIndicator(uiFirst) && Font_IsRegionalIndicator(cp);
	if (!bRegionalPair && !Font_IsSeqLinker(cp))
	{
		return NULL;
	}

	// ---- collect the codepoint sequence ----
	std::vector<unsigned int> seq;
	seq.push_back(uiFirst);

	if (bRegionalPair)
	{
		seq.push_back(cp);
		ps += iAdvance;
	}
	else
	{
		while (seq.size() < 24)
		{
			cp = AnyLanguage_ReadCharFromString(ps, &iAdvance, NULL);
			if (cp == 0x200D)
			{
				// joiner must be followed by another emoji...
				int iAdvance2;
				const unsigned int cpNext = AnyLanguage_ReadCharFromString(ps + iAdvance, &iAdvance2, NULL);
				if (!cpNext || Font_IsSeqLinker(cpNext))
				{
					break;
				}
				seq.push_back(cp);
				seq.push_back(cpNext);
				ps += iAdvance + iAdvance2;
			}
			else if (Font_IsSeqLinker(cp))
			{
				seq.push_back(cp);
				ps += iAdvance;
			}
			else
			{
				break;
			}
		}
	}

	if (seq.size() < 2)
	{
		return NULL;
	}

	// ---- cached? ----
	std::map<std::vector<unsigned int>, unsigned int>::iterator itSeq = m_TTFSeqCache.find(seq);
	if (itSeq != m_TTFSeqCache.end())
	{
		if ((*itSeq).second == 0)
		{
			return NULL;	// known-unligatable
		}
		TTFGlyph_t& cached = m_TTFGlyphs[(*itSeq).second];
		if (piShader)
		{
			*piShader = (g_bFontShadowPass && cached.hShadowShader) ? cached.hShadowShader : cached.hShader;
		}
		*ppsText = ps;
		return &cached.glyph;
	}

	// ---- pick the face that owns the base codepoint (same walk as TTF_CacheGlyph) ----
	FT_Face pFace = m_ftFace;
	int iFaceId = 0;
	if (FT_Get_Char_Index(pFace, seq[0]) == 0)
	{
		if (!g_bFallbacksLoaded)
		{
			Font_LoadFallbacks();
		}
		pFace = NULL;
		for (int i = 0; i < g_iNumFallbacks; i++)
		{
			if (FT_Get_Char_Index(g_FallbackFaces[i], seq[0]))
			{
				pFace = g_FallbackFaces[i];
				iFaceId = 1 + i;
				FT_Set_Pixel_Sizes(pFace, 0, mPointSize);
				break;
			}
		}
	}

	FT_UInt uiLigGlyph = 0;
	if (pFace)
	{
		// ---- codepoints -> glyph ids ----
		std::vector<FT_UInt> glyphs;
		bool bResolved = true;
		for (size_t i = 0; i < seq.size(); i++)
		{
			const FT_UInt g = FT_Get_Char_Index(pFace, seq[i]);
			if (g)
			{
				glyphs.push_back(g);
			}
			else if (seq[i] == 0xFE0E || seq[i] == 0xFE0F)
			{
				continue;	// fonts routinely omit variation selector glyphs: drop
			}
			else
			{
				bResolved = false;
				break;
			}
		}

		// ---- ligate ----
		if (bResolved && !glyphs.empty())
		{
			GSUBData_t* pGSUB = Font_GetGSUB(pFace);
			if (glyphs.size() > 1)
			{
				GSUB_ApplyLigatures(pGSUB, glyphs);
			}
			if (glyphs.size() > 1)
			{
				// leftover variation selectors that no ligature consumed are
				// ignorable per Unicode: strip their glyphs and retry...
				const FT_UInt uiVS15 = FT_Get_Char_Index(pFace, 0xFE0E);
				const FT_UInt uiVS16 = FT_Get_Char_Index(pFace, 0xFE0F);
				for (size_t i = glyphs.size(); i-- > 0; )
				{
					if ((uiVS15 && glyphs[i] == uiVS15) || (uiVS16 && glyphs[i] == uiVS16))
					{
						glyphs.erase(glyphs.begin() + i);
					}
				}
				if (glyphs.size() > 1)
				{
					GSUB_ApplyLigatures(pGSUB, glyphs);
				}
			}
			if (glyphs.size() == 1)
			{
				uiLigGlyph = glyphs[0];
			}
		}
	}

	if (!uiLigGlyph)
	{
		m_TTFSeqCache[seq] = 0;
		return NULL;
	}

	// glyph indices are 16-bit in OpenType: pack face+glyph into a synthetic
	// cache key far above the Unicode range...
	const unsigned int uiCacheKey = 0x40000000u | ((unsigned int)iFaceId << 16) | (uiLigGlyph & 0xFFFF);

	TTFGlyph_t* pEntry;
	TTFGlyphMap_t::iterator itGlyph = m_TTFGlyphs.find(uiCacheKey);
	if (itGlyph != m_TTFGlyphs.end())
	{
		pEntry = &(*itGlyph).second;
	}
	else
	{
		pEntry = TTF_RenderGlyphIndex(pFace, uiLigGlyph, uiCacheKey);
	}

	if (!pEntry)
	{
		m_TTFSeqCache[seq] = 0;
		return NULL;
	}

	m_TTFSeqCache[seq] = uiCacheKey;
	if (piShader)
	{
		*piShader = (g_bFontShadowPass && pEntry->hShadowShader) ? pEntry->hShadowShader : pEntry->hShader;
	}
	*ppsText = ps;
	return &pEntry->glyph;
}

TTFGlyph_t* CFontInfo::TTF_CacheGlyph(unsigned int uiLetter)
{
	if (uiLetter < TTF_DIRECT_GLYPHS)
	{
		TTFGlyph_t* pDirect = m_TTFDirect[uiLetter];
		if (pDirect)
		{
			return pDirect->bMissing ? NULL : pDirect;
		}
	}
	else
	{
		TTFGlyphMap_t::iterator it = m_TTFGlyphs.find(uiLetter);
		if (it != m_TTFGlyphs.end())
		{
			return (*it).second.bMissing ? NULL : &(*it).second;
		}
	}

	if (!m_ftFace)
	{
		return NULL;
	}

	// first use of an alphabetic block: rasterize every glyph the font has in
	// it right away, so they reach the GPU as a few large uploads here rather
	// than trickling in one at a time as text using them shows up...
	if (uiLetter < TTF_PRECACHE_LIMIT)
	{
		const uint64_t uiBlockBit = (uint64_t)1 << (uiLetter >> 7);
		if (!(m_uiTTFPrecachedBlocks & uiBlockBit))
		{
			m_uiTTFPrecachedBlocks |= uiBlockBit;

			const unsigned int uiBlockStart = uiLetter & ~0x7Fu;
			for (unsigned int uiOther = uiBlockStart; uiOther < uiBlockStart + 0x80; uiOther++)
			{
				if (uiOther != uiLetter && FT_Get_Char_Index(m_ftFace, uiOther))
				{
					TTF_CacheGlyph(uiOther);
				}
			}
		}
	}

	FT_Face pFace = m_ftFace;
	FT_UInt uiGlyphIndex = FT_Get_Char_Index(pFace, uiLetter);

	if (uiGlyphIndex == 0)
	{
		// main font lacks this codepoint: walk the fallback chain. If nothing
		// has it either, we render the main font's ".notdef" box (tofu)...
		//
		if (!g_bFallbacksLoaded)
		{
			Font_LoadFallbacks();
		}

		for (int i = 0; i < g_iNumFallbacks; i++)
		{
			const FT_UInt uiIdx = FT_Get_Char_Index(g_FallbackFaces[i], uiLetter);
			if (uiIdx)
			{
				pFace = g_FallbackFaces[i];
				uiGlyphIndex = uiIdx;
				FT_Set_Pixel_Sizes(pFace, 0, mPointSize);	// match the host font's size (incl. hi-res variants)
				break;
			}
		}
	}

	TTFGlyph_t* pEntry = TTF_RenderGlyphIndex(pFace, uiGlyphIndex, uiLetter);
	if (!pEntry)
	{
		// (broken glyph, atlas full...) cache the failure as well, or every
		// draw of this character would try to rasterize it all over again
		pEntry = &m_TTFGlyphs[uiLetter];
		memset(pEntry, 0, sizeof(*pEntry));
		pEntry->bMissing = true;
	}
	if (uiLetter < TTF_DIRECT_GLYPHS)
	{
		m_TTFDirect[uiLetter] = pEntry;
	}
	return pEntry->bMissing ? NULL : pEntry;
}

// rasterize a glyph by its index in pFace and cache it in m_TTFGlyphs under
// uiCacheKey. Split out of TTF_CacheGlyph so that emoji ZWJ ligature glyphs
// (which have a glyph index but no codepoint of their own) can be rendered too...
//
TTFGlyph_t* CFontInfo::TTF_RenderGlyphIndex(FT_Face pFace, FT_UInt uiGlyphIndex, unsigned int uiCacheKey)
{
	TTFGlyph_t entry;
	memset(&entry, 0, sizeof(entry));

	FontProfileScope_t profile(&g_fontStats.rasterMs);
	g_fontStats.rasterized++;

	// ---- colour path: COLRv0 layered glyphs (Segoe UI Emoji, Twemoji...) ----
	//
	// each layer is a monochrome glyph tinted by a palette colour; composite
	// them src-over into an RGBA canvas and park it on an identity-colour page...
	//
	{
		FT_LayerIterator	iterScan;
		FT_UInt				uiLayerGlyph, uiLayerColor;

		iterScan.p = NULL;
		if (FT_Get_Color_Glyph_Layer(pFace, uiGlyphIndex, &uiLayerGlyph, &uiLayerColor, &iterScan))
		{
			FT_Color* pPalette = NULL;
			int			iXMin = 99999, iYMin = 99999, iXMax = -99999, iYMax = -99999;
			int			iAdvance = 0;

			FT_Palette_Select(pFace, 0, &pPalette);

			// rasterize every layer once, keeping its coverage bitmap for the
			// compositing below, and gather the union bounding box...
			struct ColorLayer_t
			{
				int					iLeft, iTop, iW, iH;
				FT_UInt				uiColor;
				std::vector<byte>	coverage;
			};
			std::vector<ColorLayer_t> layers;

			FT_LayerIterator iterBox; iterBox.p = NULL;
			while (FT_Get_Color_Glyph_Layer(pFace, uiGlyphIndex, &uiLayerGlyph, &uiLayerColor, &iterBox))
			{
				if (FT_Load_Glyph(pFace, uiLayerGlyph, FT_LOAD_RENDER) != 0)
				{
					continue;
				}
				const FT_GlyphSlot s = pFace->glyph;
				if (!s->bitmap.width || !s->bitmap.rows || s->bitmap.pixel_mode != FT_PIXEL_MODE_GRAY)
				{
					continue;
				}
				g_fontStats.colorLayers++;
				if (s->bitmap_left < iXMin) { iXMin = s->bitmap_left; }
				if (s->bitmap_left + (int)s->bitmap.width > iXMax) { iXMax = s->bitmap_left + (int)s->bitmap.width; }
				if (s->bitmap_top > iYMax) { iYMax = s->bitmap_top; }
				if (s->bitmap_top - (int)s->bitmap.rows < iYMin) { iYMin = s->bitmap_top - (int)s->bitmap.rows; }

				layers.push_back(ColorLayer_t());
				ColorLayer_t& layer = layers.back();
				layer.iLeft = s->bitmap_left;
				layer.iTop = s->bitmap_top;
				layer.iW = (int)s->bitmap.width;
				layer.iH = (int)s->bitmap.rows;
				layer.uiColor = uiLayerColor;
				layer.coverage.resize((size_t)layer.iW * layer.iH);
				for (int iRow = 0; iRow < layer.iH; iRow++)
				{
					memcpy(&layer.coverage[(size_t)iRow * layer.iW], s->bitmap.buffer + iRow * s->bitmap.pitch, layer.iW);
				}
			}

			if (FT_Load_Glyph(pFace, uiGlyphIndex, FT_LOAD_DEFAULT) == 0)
			{
				iAdvance = (int)(pFace->glyph->advance.x >> 6);
			}

			if (pPalette && iXMax > iXMin && iYMax > iYMin)
			{
				const int iW = iXMax - iXMin;
				const int iH = iYMax - iYMin;
				std::vector<byte> rgba((size_t)iW * iH * 4, 0);
				byte* pRGBA = &rgba[0];

				// composite the layers src-over, in layer order...
				for (size_t iLayer = 0; iLayer < layers.size(); iLayer++)
				{
					const ColorLayer_t& layer = layers[iLayer];

					byte r = 255, g = 255, b = 255, a = 255;	// 0xFFFF = "text foreground": use white
					if (layer.uiColor != 0xFFFF)
					{
						r = pPalette[layer.uiColor].red;
						g = pPalette[layer.uiColor].green;
						b = pPalette[layer.uiColor].blue;
						a = pPalette[layer.uiColor].alpha;
					}

					for (int iRow = 0; iRow < layer.iH; iRow++)
					{
						const byte* pSrc = &layer.coverage[(size_t)iRow * layer.iW];
						const int	iDstY = (iYMax - layer.iTop) + iRow;
						byte* pDstRow = pRGBA + (iDstY * iW + (layer.iLeft - iXMin)) * 4;

						for (int iCol = 0; iCol < layer.iW; iCol++)
						{
							const int iSrcA = (pSrc[iCol] * a) / 255;
							if (!iSrcA)
							{
								continue;
							}
							byte* pDst = pDstRow + iCol * 4;
							const int iInvA = 255 - iSrcA;
							pDst[0] = (byte)((r * iSrcA + pDst[0] * iInvA) / 255);
							pDst[1] = (byte)((g * iSrcA + pDst[1] * iInvA) / 255);
							pDst[2] = (byte)((b * iSrcA + pDst[2] * iInvA) / 255);
							pDst[3] = (byte)(iSrcA + (pDst[3] * iInvA) / 255);
						}
					}
				}

				int iX, iY;
				TTFAtlasPage_t* pPage = TTF_AllocAtlasSpace(iW, iH, &iX, &iY, true);
				if (pPage)
				{
					TTF_QueueUpload(pPage->pImage, iX, iY, iW, iH, rgba);

					entry.glyph.s = (float)iX / (float)m_iTTFAtlasSize;
					entry.glyph.t = (float)iY / (float)m_iTTFAtlasSize;
					entry.glyph.s2 = (float)(iX + iW) / (float)m_iTTFAtlasSize;
					entry.glyph.t2 = (float)(iY + iH) / (float)m_iTTFAtlasSize;
					entry.hShader = pPage->hShader;
					entry.hShadowShader = pPage->hShadowShader;

					entry.glyph.width = iW;
					entry.glyph.height = iH;
					entry.glyph.horizAdvance = iAdvance ? iAdvance : iW + 1;
					entry.glyph.horizOffset = iXMin;
					entry.glyph.baseline = iYMax;

					m_TTFGlyphs[uiCacheKey] = entry;
					return &m_TTFGlyphs[uiCacheKey];
				}
			}
		}
	}

	// ---- monochrome path ----
	//
	// glyph index 0 is the ".notdef" box (tofu), exactly what we want for missing chars...
	//
	if (FT_Load_Glyph(pFace, uiGlyphIndex, FT_LOAD_RENDER) != 0)
	{
		return NULL;
	}

	FT_GlyphSlot	pSlot = pFace->glyph;
	FT_Bitmap* pBitmap = &pSlot->bitmap;

	const int iW = (int)pBitmap->width;
	const int iH = (int)pBitmap->rows;
	const bool bMono = (pBitmap->pixel_mode == FT_PIXEL_MODE_MONO);	// 1 bit per pixel (embedded bitmap strikes)

	if (iW > 0 && iH > 0 && !bMono && pBitmap->pixel_mode != FT_PIXEL_MODE_GRAY)
	{
		return NULL;	// (BGRA / LCD bitmaps: not something we can expand below)
	}

	if (iW > 0 && iH > 0)
	{
		int iX, iY;
		TTFAtlasPage_t* pPage = TTF_AllocAtlasSpace(iW, iH, &iX, &iY, false);
		if (!pPage)
		{
			return NULL;
		}

		// expand FreeType's 8-bit coverage bitmap into white RGBA...
		//
		std::vector<byte> rgba((size_t)iW * iH * 4);
		byte* pRGBA = &rgba[0];
		for (int iRow = 0; iRow < iH; iRow++)
		{
			const byte* pSrc = pBitmap->buffer + iRow * pBitmap->pitch;
			byte* pDst = pRGBA + iRow * iW * 4;
			for (int iCol = 0; iCol < iW; iCol++)
			{
				pDst[iCol * 4 + 0] = 255;
				pDst[iCol * 4 + 1] = 255;
				pDst[iCol * 4 + 2] = 255;
				pDst[iCol * 4 + 3] = bMono ? ((pSrc[iCol >> 3] & (0x80 >> (iCol & 7))) ? 255 : 0) : pSrc[iCol];
			}
		}
		TTF_QueueUpload(pPage->pImage, iX, iY, iW, iH, rgba);

		entry.glyph.s = (float)iX / (float)m_iTTFAtlasSize;
		entry.glyph.t = (float)iY / (float)m_iTTFAtlasSize;
		entry.glyph.s2 = (float)(iX + iW) / (float)m_iTTFAtlasSize;
		entry.glyph.t2 = (float)(iY + iH) / (float)m_iTTFAtlasSize;
		entry.hShader = pPage->hShader;
		entry.hShadowShader = pPage->hShadowShader;
	}
	else if (m_iTTFNumPages > 0)
	{
		entry.hShader = m_TTFPages[0].hShader;	// eg space: no bitmap, any page will do
		entry.hShadowShader = m_TTFPages[0].hShadowShader;
	}

	entry.glyph.width = iW;
	entry.glyph.height = iH;
	entry.glyph.horizAdvance = (int)(pSlot->advance.x >> 6);
	entry.glyph.horizOffset = pSlot->bitmap_left;
	entry.glyph.baseline = pSlot->bitmap_top;

	m_TTFGlyphs[uiCacheKey] = entry;
	return &m_TTFGlyphs[uiCacheKey];
}

const glyphInfo_t* CFontInfo::TTF_GetLetter(const unsigned int uiLetterIn, int* piShader)
{
	unsigned int uiLetter = uiLetterIn;

	TTFGlyph_t* pEntry = TTF_CacheGlyph(uiLetter);

	if (!pEntry)
	{
		pEntry = TTF_CacheGlyph('.');	// last-ditch fallback
		if (!pEntry)
		{
			static glyphInfo_t emptyGlyph;	// static storage == zero-initialized
			if (piShader)
			{
				*piShader = 0;
			}
			return &emptyGlyph;
		}
	}

	if (piShader)
	{
		*piShader = (g_bFontShadowPass && pEntry->hShadowShader) ? pEntry->hShadowShader : pEntry->hShader;
	}

	return &pEntry->glyph;
}
#endif // USE_FREETYPE

int CFontInfo::GetHandle() {
	return m_handle;
}

void CFontInfo::AddVariant(CFontInfo * replacer) {
	m_variants[m_numVariants++] = replacer;
}

int CFontInfo::GetNumVariants() {
	return m_numVariants;
}

CFontInfo *CFontInfo::GetVariant(int index) {
	return m_variants[index];
}

void CFontInfo::UpdateAsianIfNeeded( bool bForceReEval /* = false */ )
{
	// if asian language, then provide an alternative glyph set and fill in relevant fields...
	// (TTF fonts too: text in those languages arrives in their legacy multi-byte
	// encodings, which only the game's own glyph pages can draw)
	//
	if (mHeight && !m_bIsFakeAlienLanguage)	// western charset exists in first place, and isn't alien rubbish?
	{
		Language_e eLanguage = GetLanguageEnum();

		if (eLanguage == eKorean || eLanguage == eTaiwanese || eLanguage == eJapanese || eLanguage == eChinese || eLanguage == eThai)
		{
			int iCappedHeight = mHeight < 16 ? 16: mHeight;	// arbitrary limit on small char sizes because Asian chars don't squash well

			if (m_iLanguageModificationCount != se_language->modificationCount || !AsianGlyphsAvailable() || bForceReEval)
			{
				m_iLanguageModificationCount  = se_language->modificationCount;

				int iGlyphTPs = 0;
				const char *psLang = NULL;

				switch ( eLanguage )
				{
					case eKorean:		m_iAsianGlyphsAcross = Korean_InitFields(iGlyphTPs, psLang);	break;
					case eTaiwanese:	m_iAsianGlyphsAcross = Taiwanese_InitFields(iGlyphTPs, psLang);	break;
					case eJapanese:		m_iAsianGlyphsAcross = Japanese_InitFields(iGlyphTPs, psLang);	break;
					case eChinese:		m_iAsianGlyphsAcross = Chinese_InitFields(iGlyphTPs, psLang);	break;
					case eThai:
					{
						m_iAsianGlyphsAcross = Thai_InitFields(iGlyphTPs, psLang);

						if (!m_pThaiData)
						{
							const char *psFailureReason = g_ThaiCodes.Init();
							if (!psFailureReason[0])
							{
								m_pThaiData = &g_ThaiCodes;
							}
							else
							{
								// no Thai glyph data: Thai text is UTF-8 then, drawn by
								// the TTF fonts and r_fontFallbacks instead of glyph pages
								// (this runs on every font lookup while there are no pages)
								//
								static bool bReported = false;
								if (!bReported)
								{
									ri.Printf( PRINT_DEVELOPER, "%s", psFailureReason );
									bReported = true;
								}
								iGlyphTPs = 0;
							}
						}
					}
					break;
					default: break;
				}

				// textures need loading...
				//
				if (m_sFontName[0])
				{
					// Use this sometime if we need to do logic to load alternate-height glyphs to better fit other fonts.
					// (but for now, we just use the one glyph set)
					//
				}

				for (int i = 0; i < iGlyphTPs; i++)
				{
					// (Note!!  assumption for S,T calculations: all Asian glyph textures pages are square except for last one)
					//
					char sTemp[MAX_QPATH];
					Com_sprintf(sTemp,sizeof(sTemp), "fonts/%s_%d_1024_%d", psLang, 1024/m_iAsianGlyphsAcross, i);
					//
					// returning 0 here will automatically inhibit Asian glyph calculations at runtime...
					//
					m_hAsianShaders[i] = RE_RegisterShaderNoMip( sTemp );
				}

				// for now I'm hardwiring these, but if we ever have more than one glyph set per language then they'll be changed...
				//
				m_iAsianPagesLoaded = iGlyphTPs;	// not necessarily true, but will be safe, and show up obvious if something missing
				m_bAsianLastPageHalfHeight = true;

				bForceReEval = true;
			}

			if (bForceReEval)
			{
				// now init the Asian member glyph fields to make them come out the same size as the western ones
				//	that they serve as an alternative for...
				//
				m_AsianGlyph.width			= iCappedHeight;	// square Asian chars same size as height of western set
				m_AsianGlyph.height			= iCappedHeight;	// ""
				switch (eLanguage)
				{
					default:		m_AsianGlyph.horizAdvance	= iCappedHeight;	break;
					case eKorean:	m_AsianGlyph.horizAdvance	= iCappedHeight - 1;break;	// korean has a small amount of space at the edge of the glyph

					case eTaiwanese:
					case eJapanese:
					case eChinese:	m_AsianGlyph.horizAdvance	= iCappedHeight + 3;	// need to force some spacing for these
//					case eThai:	// this is done dynamically elsewhere, since Thai glyphs are variable width
				}
				m_AsianGlyph.horizOffset	= 0;				// ""
				m_AsianGlyph.baseline		= mAscender + ((iCappedHeight - mHeight) >> 1);
			}
		}
		else
		{
			// not using Asian...
			//
			FlagNoAsianGlyphs();
		}
	}
	else
	{
		// no western glyphs available, so don't attempt to match asian...
		//
		FlagNoAsianGlyphs();
	}
}

static CFontInfo *GetFont_Actual(int index)
{
	index &= SET_MASK;
	if((index >= 1) && (index < g_iCurrentFontIndex))
	{
		CFontInfo *pFont = g_vFontArray[index];

		if (pFont)
		{
			pFont->UpdateAsianIfNeeded();
		}

		return pFont;
	}
	return(NULL);
}

static CFontInfo *RE_Font_GetVariant(CFontInfo *font, float *scale) {
	int variants = font->GetNumVariants();

	if (variants > 0) {
		CFontInfo *variant;
		int requestedSize = font->GetPointSize() * *scale *
			r_fontSharpness->value * (glConfig.vidHeight / SCREEN_HEIGHT);

		if (requestedSize <= font->GetPointSize())
			return font;

		for (int i = 0; i < variants; i++) {
			variant = font->GetVariant(i);

			if (requestedSize <= variant->GetPointSize())
				break;
		}

		*scale *= (float)font->GetPointSize() / variant->GetPointSize();
		return variant;
	}

	return font;
}

// needed to add *piShader param because of multiple TPs,
//	if not passed in, then I also skip S,T calculations for re-usable static asian glyphinfo struct...
//
const glyphInfo_t *CFontInfo::GetLetter(const unsigned int uiLetter, int *piShader /* = NULL */)
{
	// invisible unicode formatting codepoints (emoji variation selectors,
	// zero-width joiners, BOM): draw as a degenerate zero-area quad.
	// width=1 on purpose — zero width would trigger DrawString's '.' substitution...
	if ((uiLetter >= 0xFE00 && uiLetter <= 0xFE0F) ||
		uiLetter == 0x200C || uiLetter == 0x200D ||
		uiLetter == 0x2060 || uiLetter == 0xFEFF)
	{
		static glyphInfo_t invisibleGlyph;

		invisibleGlyph.width = 1;
		invisibleGlyph.height = 0;
		invisibleGlyph.horizAdvance = 0;

		if (piShader)
		{
			*piShader = GetShader();
		}
		return &invisibleGlyph;
	}

#ifdef USE_FREETYPE
	// (Japanese and Korean arrive as Unicode, so the font or a fallback can draw
	// them; the other Asian languages are still in their own encodings, and
	// anything the fonts lack is left to the game's glyph pages)
	//
	if (m_bTTF && (!(AsianGlyphsAvailable() && GetCollapsedAsianCode(uiLetter))
				|| ((GetLanguageEnum() == eJapanese || GetLanguageEnum() == eKorean) && TTF_CacheGlyph(uiLetter))))
	{
		return TTF_GetLetter(uiLetter, piShader);
	}
#endif
	if ( AsianGlyphsAvailable() )
	{
		int iCollapsedAsianCode = GetCollapsedAsianCode( uiLetter );
		if (iCollapsedAsianCode)
		{
			if (piShader)
			{
				// (Note!!  assumption for S,T calculations: all asian glyph textures pages are square except for last one
				//			which may or may not be half height) - but not for Thai
				//
				int iTexturePageIndex = iCollapsedAsianCode / (m_iAsianGlyphsAcross * m_iAsianGlyphsAcross);

				if (iTexturePageIndex > m_iAsianPagesLoaded)
				{
					assert(0);				// should never happen
					iTexturePageIndex = 0;
				}

				int iOriginalCollapsedAsianCode = iCollapsedAsianCode;	// need to back this up (if Thai) for later
				iCollapsedAsianCode -= iTexturePageIndex *  (m_iAsianGlyphsAcross * m_iAsianGlyphsAcross);

				const int iColumn	= iCollapsedAsianCode % m_iAsianGlyphsAcross;
				const int iRow		= iCollapsedAsianCode / m_iAsianGlyphsAcross;
				const bool bHalfT	= (iTexturePageIndex == (m_iAsianPagesLoaded - 1) && m_bAsianLastPageHalfHeight);
				const int iAsianGlyphsDown = (bHalfT) ? m_iAsianGlyphsAcross / 2 : m_iAsianGlyphsAcross;

				switch ( GetLanguageEnum() )
				{
					case eKorean:
					default:
					{
						m_AsianGlyph.s  = (float)( iColumn    ) / (float)m_iAsianGlyphsAcross;
						m_AsianGlyph.t  = (float)( iRow       ) / (float)  iAsianGlyphsDown;
						m_AsianGlyph.s2 = (float)( iColumn + 1) / (float)m_iAsianGlyphsAcross;
						m_AsianGlyph.t2 = (float)( iRow + 1   ) / (float)  iAsianGlyphsDown;
					}
					break;

					case eTaiwanese:
					{
						m_AsianGlyph.s  = (float)(((1024 / m_iAsianGlyphsAcross) * ( iColumn    ))+1) / 1024.0f;
						m_AsianGlyph.t  = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow       ))+1) / 1024.0f;
						m_AsianGlyph.s2 = (float)(((1024 / m_iAsianGlyphsAcross) * ( iColumn+1  ))  ) / 1024.0f;
						m_AsianGlyph.t2 = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow+1     ))  ) / 1024.0f;
					}
					break;

					case eJapanese:
					case eChinese:
					{
						m_AsianGlyph.s  = (float)(((1024 / m_iAsianGlyphsAcross) * ( iColumn    ))  ) / 1024.0f;
						m_AsianGlyph.t  = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow       ))  ) / 1024.0f;
						m_AsianGlyph.s2 = (float)(((1024 / m_iAsianGlyphsAcross) * ( iColumn+1  ))-1) / 1024.0f;
						m_AsianGlyph.t2 = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow+1     ))-1) / 1024.0f;
					}
					break;

					case eThai:
					{
						int iGlyphXpos = (1024 / m_iAsianGlyphsAcross) * ( iColumn );
						int iGlyphWidth = g_ThaiCodes.GetWidth( iOriginalCollapsedAsianCode );

						// very thai-specific language-code...
						//
						if (uiLetter == TIS_SARA_AM)
						{
							iGlyphXpos += 9;	// these are pixel coords on the source TP, so don't affect scaled output
							iGlyphWidth= 20;	//
						}
						m_AsianGlyph.s  = (float)(iGlyphXpos) / 1024.0f;
						m_AsianGlyph.t  = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow       ))  ) / 1024.0f;
						// technically this .s2 line should be modified to blit only the correct width, but since
						//	all Thai glyphs are up against the left edge of their cells and have blank to the cell
						//	boundary then it's better to keep these calculations simpler...

						m_AsianGlyph.s2 = (float)(iGlyphXpos+iGlyphWidth) / 1024.0f;
						m_AsianGlyph.t2 = (float)(((1024 / iAsianGlyphsDown    ) * ( iRow+1     ))-1) / 1024.0f;

						// special addition for Thai, need to bodge up the width and advance fields...
						//
                        m_AsianGlyph.width = iGlyphWidth;
						m_AsianGlyph.horizAdvance = iGlyphWidth + 1;
					}
					break;
				}
				*piShader = m_hAsianShaders[ iTexturePageIndex ];
			}
			return &m_AsianGlyph;
		}
	}

	if (piShader)
	{
		*piShader = GetShader();
	}

	// characters arrive as Unicode: map them back onto the codepage slots the
	// bitmap fonts of this language use, instead of blindly masking the
	// codepoint down to garbage...
	const unsigned int uiSlot = Font_UnicodeToLegacyByte( uiLetter );

	const glyphInfo_t* pGlyph = &mGlyphs[uiSlot & 0xff];
	//
	// SBCS language substitution?...
	//
	if ( m_fAltSBCSFontScaleFactor != -1 )
	{
		// sod it, use the asian glyph, that's fine...
		//
		memcpy(&m_AsianGlyph,pGlyph,sizeof(m_AsianGlyph));	// *before* changin pGlyph!

//		CFontInfo *pOriginalFont = GetFont_Actual( this->m_iOriginalFontWhenSBCSOverriden );
//		pGlyph = &pOriginalFont->mGlyphs[ uiLetter & 0xff ];

		#define ASSIGN_WITH_ROUNDING(_dst,_src) _dst = mbRoundCalcs ? Round( m_fAltSBCSFontScaleFactor * _src ) : m_fAltSBCSFontScaleFactor * (float)_src;

		ASSIGN_WITH_ROUNDING( m_AsianGlyph.baseline,	pGlyph->baseline );
		ASSIGN_WITH_ROUNDING( m_AsianGlyph.height,		pGlyph->height );
		ASSIGN_WITH_ROUNDING( m_AsianGlyph.horizAdvance,pGlyph->horizAdvance );
//		m_AsianGlyph.horizOffset	= /*Round*/( m_fAltSBCSFontScaleFactor * pGlyph->horizOffset );
		ASSIGN_WITH_ROUNDING( m_AsianGlyph.width,		pGlyph->width*tr.widthRatioCoef );

		pGlyph = &m_AsianGlyph;
	}

	return pGlyph;
}

const int CFontInfo::GetCollapsedAsianCode(ulong uiLetter) const
{
	int iCollapsedAsianCode = 0;

	if (AsianGlyphsAvailable())
	{
		switch ( GetLanguageEnum() )
		{
			case eKorean:		iCollapsedAsianCode = Korean_CollapseUnicode( uiLetter );			break;
			case eTaiwanese:	iCollapsedAsianCode = Taiwanese_CollapseBig5Code( uiLetter );		break;
			case eJapanese:		iCollapsedAsianCode = Japanese_CollapseUnicode( uiLetter );			break;
			case eChinese:		iCollapsedAsianCode = Chinese_CollapseGBCode( uiLetter );			break;
			case eThai:			iCollapsedAsianCode = Thai_CollapseTISCode( uiLetter );				break;
			default:			assert(0);	/* unhandled asian language */							break;
		}
	}

	return iCollapsedAsianCode;
}

const int CFontInfo::GetLetterWidth(unsigned int uiLetter)
{
	const glyphInfo_t *pGlyph = GetLetter( uiLetter );
	return pGlyph->width ? pGlyph->width : mGlyphs[(unsigned)'.'].width;
}

const int CFontInfo::GetLetterHorizAdvance(unsigned int uiLetter)
{
	const glyphInfo_t *pGlyph = GetLetter( uiLetter );
	return pGlyph->horizAdvance ? pGlyph->horizAdvance : mGlyphs[(unsigned)'.'].horizAdvance;
}

// ensure any GetFont calls that need SBCS overriding (such as when playing in Russian) have the appropriate stuff done...
//
static CFontInfo *GetFont_SBCSOverride(CFontInfo *pFont, Language_e eLanguageSBCS, const char *psLanguageNameSBCS )
{
	// the override exists because the bitmap fonts have no Cyrillic or Polish
	// letters; TTF fonts carry them (or find them in r_fontFallbacks), so they
	// keep their own typeface
	//
	if ( pFont->IsTTF() )
	{
		return NULL;
	}

	if ( !pFont->m_bIsFakeAlienLanguage )
	{
		if ( GetLanguageEnum() == eLanguageSBCS )
		{
			if ( pFont->m_iAltSBCSFont == -1 ) 	// no reg attempted yet?
			{
				// need to register this alternative SBCS font...
				//
#ifdef USE_FREETYPE
				// an outline version of it (fonts/russian.ttf) is simply loaded at the
				// size of the font it stands in for; without one this ends up at the
				// bitmap font, like the plain name below
				g_bTTFRegisteringVariant = true;
				int iAltFontIndex = RE_RegisterFont( va("%s/%s@%d",COM_SkipPath(pFont->m_sFontName),psLanguageNameSBCS,pFont->GetPointSize()) );
				g_bTTFRegisteringVariant = false;
#else
				int iAltFontIndex = RE_RegisterFont( va("%s/%s",COM_SkipPath(pFont->m_sFontName),psLanguageNameSBCS) );	// ensure unique name (eg: "lcd/russian")
#endif
				CFontInfo *pAltFont = GetFont_Actual( iAltFontIndex );
				if ( pAltFont && pAltFont->IsTTF() )
				{
					pAltFont->mHeight	 = pFont->GetHeight();
					pAltFont->mAscender	 = pFont->GetAscender();
					pAltFont->mDescender = pFont->GetDescender();
					pAltFont->m_iOriginalFontWhenSBCSOverriden = pFont->m_iThisFont;
				}
				else
				if ( pAltFont )
				{
					// work out the scaling factor for this font's glyphs...( round it to 1 decimal place to cut down on silly scale factors like 0.53125 )
					//
					pAltFont->m_fAltSBCSFontScaleFactor = RoundTenth((float)pFont->GetPointSize() / (float)pAltFont->GetPointSize());
					//
					// then override with the main properties of the original font...
					//
					pAltFont->mPointSize = pFont->GetPointSize();//(float) pAltFont->GetPointSize() * pAltFont->m_fAltSBCSFontScaleFactor;
					pAltFont->mHeight	 = pFont->GetHeight();//(float) pAltFont->GetHeight()	* pAltFont->m_fAltSBCSFontScaleFactor;
					pAltFont->mAscender	 = pFont->GetAscender();//(float) pAltFont->GetAscender()	* pAltFont->m_fAltSBCSFontScaleFactor;
					pAltFont->mDescender = pFont->GetDescender();//(float) pAltFont->GetDescender()	* pAltFont->m_fAltSBCSFontScaleFactor;

//					pAltFont->mPointSize = (float) pAltFont->GetPointSize() * pAltFont->m_fAltSBCSFontScaleFactor;
//					pAltFont->mHeight	 = (float) pAltFont->GetHeight()	* pAltFont->m_fAltSBCSFontScaleFactor;
//					pAltFont->mAscender	 = (float) pAltFont->GetAscender()	* pAltFont->m_fAltSBCSFontScaleFactor;
//					pAltFont->mDescender = (float) pAltFont->GetDescender()	* pAltFont->m_fAltSBCSFontScaleFactor;

					pAltFont->mbRoundCalcs = true;
					pAltFont->m_iOriginalFontWhenSBCSOverriden = pFont->m_iThisFont;
				}
				pFont->m_iAltSBCSFont = iAltFontIndex;
			}

			if ( pFont->m_iAltSBCSFont > 0)
			{
				return GetFont_Actual( pFont->m_iAltSBCSFont );
			}
		}
	}

	return NULL;
}



CFontInfo *GetFont(int index)
{
	CFontInfo *pFont = GetFont_Actual( index );

	if (pFont)
	{
		// any SBCS overrides? (this has to be pretty quick, and is (sort of))...
		//
		for (int i=0; g_SBCSOverrideLanguages[i].m_psName; i++)
		{
			CFontInfo *pAltFont = GetFont_SBCSOverride( pFont, g_SBCSOverrideLanguages[i].m_eLanguage, g_SBCSOverrideLanguages[i].m_psName );
			if (pAltFont)
			{
				return pAltFont;
			}
		}
	}

	return pFont;
}

float RE_Font_StrLenPixelsNew( const char *psText, const int iFontHandle, const float fScaleIn ) {
	float fScale = fScaleIn;
	CFontInfo *curfont = GetFont(iFontHandle);
	if ( !curfont ) {
		return 0.0f;
	}
	curfont = RE_Font_GetVariant(curfont, &fScale);

	float fScaleAsian = fScale;
	if (Language_IsAsian() && fScale > 0.7f )
	{
		fScaleAsian = fScale * 0.75f;
	}

	float maxLineWidth = 0.0f;
	float thisLineWidth = 0.0f;
	while ( *psText ) {
		int iAdvanceCount;
		unsigned int uiLetter = AnyLanguage_ReadCharFromString( psText, &iAdvanceCount, NULL );
		psText += iAdvanceCount;

		if ( uiLetter == '^' ) {
			if ( *psText >= '0' && *psText <= '9' ) {
				uiLetter = AnyLanguage_ReadCharFromString( psText, &iAdvanceCount, NULL );
				psText += iAdvanceCount;
				continue;
			}
		}

		if ( uiLetter == '\n' ) {
			thisLineWidth = 0.0f;
		}
		else {
			// keep sequence consumption in sync with RE_Font_DrawString...
			const glyphInfo_t* pSeqGlyph = curfont->GetSequenceGlyph(uiLetter, &psText);
			float iPixelAdvance = pSeqGlyph
				? (float)pSeqGlyph->horizAdvance
				: (float)curfont->GetLetterHorizAdvance(uiLetter);

			float fValue = iPixelAdvance * ((uiLetter > (unsigned)g_iNonScaledCharRange) ? fScaleAsian : fScale);

			if ( r_aspectCorrectFonts->integer == 1 || cl_ratioFix->integer == 1 ) {
				fValue *= tr.widthRatioCoef;
			}
			else if ( r_aspectCorrectFonts->integer == 2 || cl_ratioFix->integer == 2 ) { // ?? duno
				fValue = ceilf(
					fValue * tr.widthRatioCoef
				);
			}
			thisLineWidth += curfont->mbRoundCalcs
				? roundf( fValue )
				: (r_aspectCorrectFonts->integer == 2)
					? ceilf( fValue )
					: fValue;
			if ( thisLineWidth > maxLineWidth ) {
				maxLineWidth = thisLineWidth;
			}
		}
	}
	return maxLineWidth;
}

int RE_Font_StrLenPixels( const char *psText, const int iFontHandle, const float fScale ) {
	return (int)ceilf( RE_Font_StrLenPixelsNew( psText, iFontHandle, fScale ) );
}

// not really a font function, but keeps naming consistant...
//
int RE_Font_StrLenChars(const char *psText)
{
	// logic for this function's letter counting must be kept same in this function and RE_Font_DrawString()
	//
	int iCharCount = 0;

	while ( *psText )
	{
		// in other words, colour codes and CR/LF don't count as chars, all else does...
		//
		int iAdvanceCount;
		unsigned int uiLetter = AnyLanguage_ReadCharFromString( psText, &iAdvanceCount, NULL );
		psText += iAdvanceCount;

		switch (uiLetter)
		{
			case '^':
				if (*psText >= '0' &&
					*psText <= '9')
				{
					psText++;
				}
				else
				{
					iCharCount++;
				}
				break;	// colour code (note next-char skip)
			case 10:								break;	// linefeed
			case 13:								break;	// return
			case '_':	iCharCount += (GetLanguageEnum() == eThai && (((unsigned char *)psText)[0] >= TIS_GLYPHS_START))?0:1; break;	// special word-break hack
			default:	iCharCount++;				break;
		}
	}

	return iCharCount;
}

int RE_Font_HeightPixels(const int iFontHandle, const float fScaleIn)
{
	float fScale = fScaleIn;
	CFontInfo	*curfont;

	curfont = GetFont(iFontHandle);
	if(curfont)
	{
		float fValue;
		curfont = RE_Font_GetVariant(curfont, &fScale);
		fValue = curfont->GetPointSize() * fScale;
		return curfont->mbRoundCalcs ? Round(fValue) : fValue;
	}
	return(0);
}

// iMaxPixelWidth is -1 for "all of string", else pixel display count...
//
cvar_t *cl_coloredTextShadows;
void RE_Font_DrawString(int ox, int oy, const char *psText, const float *rgba, const int iFontHandleIn, int iMaxPixelWidth, const float fScaleIn)
{
	RE_Font_DrawStringF( (float)ox, (float)oy, psText, rgba, iFontHandleIn, iMaxPixelWidth, fScaleIn );
}

// The position is in 640x480 virtual units, which are several real pixels
// apiece at high resolutions: text laid out one cell at a time (the console)
// needs the fractions, or its spacing comes out uneven.
//
void RE_Font_DrawStringF(float ox, float oy, const char *psText, const float *rgba, const int iFontHandleIn, int iMaxPixelWidth, const float fScaleIn)
{
	static qboolean gbInShadow = qfalse;	// MUST default to this
	float				fox, foy, fx, fy;
	int					colour, offset;
	const glyphInfo_t	*pLetter;
	qhandle_t			hShader;
	float				fScale = fScaleIn;
	int					iFontHandle = iFontHandleIn;

	assert (psText);

#ifdef USE_FREETYPE
	static int iDrawDepth = 0;	// the dropshadow pass recurses: time the outermost call only
	struct DrawProfile_t
	{
		int& iDepth;
		double start;
		explicit DrawProfile_t(int& iDepthRef) : iDepth(iDepthRef), start(iDepthRef++ == 0 ? Font_ProfileClock() : 0.0) {}
		~DrawProfile_t() { iDepth--; if (start) { g_fontStats.drawMs += Font_ProfileClock() - start; } }
	} drawProfile(iDrawDepth);
	g_fontStats.draws++;
#endif

	if(iFontHandle & STYLE_BLINK)
	{
		if((ri.Milliseconds() >> 7) & 1)
		{
			return;
		}
	}

//	// test code only
//	if (GetLanguageEnum() == eTaiwanese)
//	{
//		psText = "Wp:�}�F�a �p�G���A�Ʊ�A���L�̻����@�˦�C";
//	}
//	else
//	if (GetLanguageEnum() == eChinese)
//	{
//		//psText = "Ӷ��ս��II  Լ��?Ī��˹  ����ʧ��  ��Ҫ���û����趨�ı����  Ԥ��,S3 ѹ��,DXT1 ѹ��,DXT5 ѹ��,16 Bit,32 Bit";
//		psText = "Ӷ��ս��II";
//	}
//	else
//	if (GetLanguageEnum() == eThai)
//	{
//		//psText = "�ҵðҹ��Ե�ѳ���ص��ˡ�����������Ѻ�ѡ����·����Ѻ����������";
//		psText = "�ҵðҹ��Ե";
//		psText = "��������Ѻ";
//		psText = "��������Ѻ   ��_�Թ_����_1415";
//	}
//	else
//	if (GetLanguageEnum() == eKorean)
//	{
//		psText = "Wp:��Ÿ���̴� �ָ�. �׵��� ���Ѵ�� �װ� ������ ����ϰڴ�.";
//	}
//	else
//	if (GetLanguageEnum() == eJapanese)
//	{
//		static char sBlah[200];
//		sprintf(sBlah,va("%c%c%c%c%c%c%c%c",0x82,0xA9,0x82,0xC8,0x8A,0xBF,0x8E,0x9A));
//		psText = &sBlah[0];
//	}
//	else
//	if (GetLanguageEnum() == eRussian)
//	{
////		//psText = "�� ������� ����� ����� ������ ��� � ������������ � ����� � ���������� ������."
//		psText = "�� ������� ����� �����";
//	}
//	else
//	if (GetLanguageEnum() == ePolish)
//	{
//		psText = "za�o�ony w 1364 roku, jest najstarsz� polsk� uczelni� i nale�y...";
//		psText = "za�o�ony nale�y";
//	}


	CFontInfo *curfont = GetFont(iFontHandle);
	if(!curfont || !psText)
	{
		return;
	}
	curfont = RE_Font_GetVariant(curfont, &fScale);
	iFontHandle = curfont->GetHandle() | (iFontHandle & ~SET_MASK);

	float fScaleAsian = fScale;
	float fAsianYAdjust = 0.0f;
	if (Language_IsAsian() && fScale > 0.7f)
	{
		fScaleAsian = fScale * 0.75f;
		fAsianYAdjust = ((curfont->GetPointSize() * fScale) - (curfont->GetPointSize() * fScaleAsian)) / 2.0f;
	}

	// Draw a dropshadow if required
	if (iFontHandle & STYLE_DROPSHADOW)
	{
		if (cl_coloredTextShadows && cl_coloredTextShadows->integer) {
			int i = 0, r = 0;
			char dropShadowText[1024];
			const vec4_t v4DKGREY2 = { 0.15f, 0.15f, 0.15f, rgba ? rgba[3] : 1.0f };

			offset = Round(curfont->GetPointSize() * fScale * 0.075f);

			//^blah stuff confuses shadows, so parse it out first
			while (psText[i] && r < 1024) {
				if (psText[i] == '^') {
					if ((i < 1 || psText[i - 1] != '^') &&
						(!psText[i + 1] || psText[i + 1] != '^')) { //If char before or after ^ is ^ then it prints ^ instead of accepting a colorcode
						i += 2;
					}
				}

				dropShadowText[r] = psText[i];
				r++;
				i++;
			}
			dropShadowText[r] = 0;

#ifdef USE_FREETYPE
			g_bFontShadowPass = true;
#endif
			RE_Font_DrawStringF(ox + offset, oy + offset, dropShadowText, v4DKGREY2, iFontHandle & SET_MASK, iMaxPixelWidth, fScale);
#ifdef USE_FREETYPE
			g_bFontShadowPass = false;
#endif
		}
		else
		{
			const vec4_t v4DKGREY2 = { 0.15f, 0.15f, 0.15f, rgba ? rgba[3] : 1.0f };

			offset = Round(curfont->GetPointSize() * fScale * 0.075f);

			gbInShadow = qtrue;
#ifdef USE_FREETYPE
			g_bFontShadowPass = true;
#endif
			RE_Font_DrawStringF(ox + offset, oy + offset, psText, v4DKGREY2, iFontHandle & SET_MASK, iMaxPixelWidth, fScale);
#ifdef USE_FREETYPE
			g_bFontShadowPass = false;
#endif
			gbInShadow = qfalse;
		}
	}

	RE_SetColor( rgba );

	// Now we take off the training wheels and become a big font renderer
	// It's all floats from here on out
	fox = ox;
	foy = oy;

	fx = fox;
	foy += curfont->mbRoundCalcs ? Round((curfont->GetHeight() - (curfont->GetDescender() >> 1)) * fScale) : (curfont->GetHeight() - (curfont->GetDescender() >> 1)) * fScale;

	qboolean bNextTextWouldOverflow = qfalse;
	unsigned int uiPrevLetter = 0;
	float fPrevHeight = 0.0f;
	while (*psText && !bNextTextWouldOverflow)
	{
		int iAdvanceCount;
		unsigned int uiLetter = AnyLanguage_ReadCharFromString( psText, &iAdvanceCount, NULL );
		psText += iAdvanceCount;

		switch( uiLetter )
		{
		case 10:						//linefeed
			fx = fox;
			foy += curfont->mbRoundCalcs ? Round(curfont->GetPointSize() * fScale) : curfont->GetPointSize() * fScale;
			if (Language_IsAsian())
			{
				foy += 4.0f;	// this only comes into effect when playing in asian for "A long time ago in a galaxy" etc, all other text is line-broken in feeder functions
			}
			break;
		case 13:						// Return
			break;
		case 32:						// Space
			pLetter = curfont->GetLetter(' ');
			fx += curfont->mbRoundCalcs ? Round(pLetter->horizAdvance * fScale) : pLetter->horizAdvance * fScale * tr.widthRatioCoef;

			bNextTextWouldOverflow = ( iMaxPixelWidth != -1 && ((fx-fox) > (float)iMaxPixelWidth) ) ? qtrue : qfalse; // yeuch
			break;
		case '_':	// has a special word-break usage if in Thai (and followed by a thai char), and should not be displayed, else treat as normal
			if (GetLanguageEnum()== eThai && ((unsigned char *)psText)[0] >= TIS_GLYPHS_START)
			{
				break;
			}
			// else drop through and display as normal...
		case '^':
			if (uiLetter != '_')	// necessary because of fallthrough above
			{
				if (*psText >= '0' &&
					*psText <= '9')
				{
					colour = ColorIndex(*psText++);
					if (!gbInShadow)
					{
						vec4_t color;
						Com_Memcpy( color, g_color_table[colour], sizeof( color ) );
						color[3] = rgba ? rgba[3] : 1.0f;
						RE_SetColor( color );
					}
					break;
				}
			}
			//purposely falls thrugh
		default:
			// emoji ZWJ / flag / keycap sequences: try to collapse the whole
			// sequence into one ligature glyph (advances psText on success)...
			pLetter = curfont->GetSequenceGlyph(uiLetter, &psText, &hShader);
			if (!pLetter)
			{
			pLetter = curfont->GetLetter( uiLetter, &hShader );			// Description of pLetter
			}
			if(!pLetter->width)
			{
				pLetter = curfont->GetLetter('.');
			}

			float fThisScale = uiLetter > (unsigned)g_iNonScaledCharRange ? fScaleAsian : fScale;

			// sigh, super-language-specific hack...
			//
			if (uiLetter == TIS_SARA_AM && GetLanguageEnum() == eThai)
			{
				fx -= curfont->mbRoundCalcs ? Round(7.0f * fThisScale) : 7.0f * fThisScale;
			}

			float fAdvancePixels = curfont->mbRoundCalcs ? Round(pLetter->horizAdvance * fThisScale) : pLetter->horizAdvance * fThisScale;
			bNextTextWouldOverflow = ( iMaxPixelWidth != -1 && (((fx+fAdvancePixels)-fox) > (float)iMaxPixelWidth) ) ? qtrue : qfalse; // yeuch
			if (!bNextTextWouldOverflow)
			{
				// this 'mbRoundCalcs' stuff is crap, but the only way to make the font code work. Sigh...
				//
				fy = foy - (curfont->mbRoundCalcs ? Round(pLetter->baseline * fThisScale) : pLetter->baseline * fThisScale);
				if (curfont->m_fAltSBCSFontScaleFactor != -1)
				{
					fy += 3.0f; // I'm sick and tired of going round in circles trying to do this legally, so bollocks to it
				}

				// Thai: a tone mark sits on top of a vowel written above the consonant
				//
				if (uiLetter >= 0x0E48 && uiLetter <= 0x0E4C
					&& (uiPrevLetter == 0x0E31 || (uiPrevLetter >= 0x0E34 && uiPrevLetter <= 0x0E37)))
				{
					fy -= fPrevHeight;
				}
				uiPrevLetter = uiLetter;
				fPrevHeight = pLetter->height * fThisScale;

#ifdef USE_FREETYPE
				{
					static qhandle_t hLastShader = 0;
					g_fontStats.quads++;
					if (hShader != hLastShader)
					{
						hLastShader = hShader;
						g_fontStats.pageSwitches++;
					}
				}
#endif
				RE_StretchPic(curfont->mbRoundCalcs ? fx + Round(pLetter->horizOffset * fThisScale) : fx + pLetter->horizOffset * fThisScale, // float x
								(uiLetter > (unsigned)g_iNonScaledCharRange) ? fy - fAsianYAdjust : fy,	// float y
								curfont->mbRoundCalcs ? Round(pLetter->width * fThisScale) : pLetter->width * fThisScale * tr.widthRatioCoef,	// float w
								curfont->mbRoundCalcs ? Round(pLetter->height * fThisScale) : pLetter->height * fThisScale, // float h
								pLetter->s,						// float s1
								pLetter->t,						// float t1
								pLetter->s2,					// float s2
								pLetter->t2,					// float t2
								//lastcolour.c,
								hShader							// qhandle_t hShader
								);

				if ( r_aspectCorrectFonts->integer == 1  || cl_ratioFix->integer == 1 ) {
					fx += fAdvancePixels
						* tr.widthRatioCoef;
				}
				else if ( r_aspectCorrectFonts->integer == 2 || cl_ratioFix->integer == 2 ) { // xD
					fx += ceilf( fAdvancePixels
						* tr.widthRatioCoef );
				}
				else {
					fx += fAdvancePixels;
				}
			}
			break;
		}
	}
	//let it remember the old color //RE_SetColor(NULL);
#ifdef USE_FREETYPE
	TTF_FlushUploads();	// glyphs this string rasterized must be uploaded before its quads get drawn
#endif
}

static int RE_RegisterFont_Real(const char *psName)
{
	FontIndexMap_t::iterator it = g_mapFontIndexes.find(psName);
	if (it != g_mapFontIndexes.end() )
	{
		int iFontIndex = (*it).second;
		return iFontIndex;
	}

	// not registered, so...
	//
	{
		CFontInfo *pFont = new CFontInfo(psName);
		if (pFont->GetPointSize() > 0)
		{
			int iFontIndex = g_iCurrentFontIndex - 1;
			g_mapFontIndexes[psName] = iFontIndex;
			pFont->m_iThisFont = iFontIndex;
			return iFontIndex;
		}
		else
		{
			g_mapFontIndexes[psName] = 0;	// missing/invalid
		}
	}

	return 0;
}

int RE_RegisterFont(const char *psName) {
	int oriFontHandle = RE_RegisterFont_Real(psName);
	if (oriFontHandle) {
		CFontInfo *oriFont = GetFont_Actual(oriFontHandle);

#ifdef USE_FREETYPE
		if (oriFont->IsTTF()) {
			if (oriFont->GetNumVariants() == 0) {
				// auto-register a single hi-res variant matching the current display,
				// so the existing variant system keeps TTF glyphs crisp at any resolution.
				// (renderer DLL is reloaded on vid_restart, so this is always up to date)
				int iIdealSize = (int)(oriFont->GetPointSize() * ceilf((float)glConfig.vidHeight / SCREEN_HEIGHT));
				if (iIdealSize > oriFont->GetPointSize()) {
					char sBaseName[MAX_QPATH];
					int iDummy;
					Font_SplitSizedName(psName, sBaseName, sizeof(sBaseName), &iDummy);
					g_bTTFRegisteringVariant = true;
					int replacerFontHandle = RE_RegisterFont_Real(va("%s@%i", sBaseName, iIdealSize));
					g_bTTFRegisteringVariant = false;
					if (replacerFontHandle) {
						CFontInfo* replacerFont = GetFont_Actual(replacerFontHandle);
						if (replacerFont->IsTTF()) {
							replacerFont->m_isVariant = qtrue;
							oriFont->AddVariant(replacerFont);
						}
					}
				}
				// rasterize ASCII now, while things are loading anyway, rather
				// than on the first frame that draws text with this font. Only
				// the size that ordinary text is drawn with gets this...
				(oriFont->GetNumVariants() ? oriFont->GetVariant(0) : oriFont)->TTF_Warm();
				TTF_FlushUploads();
			}
			return oriFontHandle;	// skip the "_sharp" fontdat probing below for TTF fonts
		}
#endif
		if (oriFont->GetNumVariants() == 0) {
			for (int i = 0; i < MAX_FONT_VARIANTS; i++) {
				const char *variantName = va( "%s_sharp%i", psName, i + 1 );
				const char *fontDatPath = FontDatPath( variantName );
				if ( ri.FS_ReadFile(fontDatPath, NULL) > 0 ) {
					int replacerFontHandle = RE_RegisterFont_Real(variantName);
					if (replacerFontHandle) {
						CFontInfo *replacerFont = GetFont_Actual(replacerFontHandle);
						replacerFont->m_isVariant = qtrue;
						oriFont->AddVariant(replacerFont);
					} else {
						break;
					}
				} else {
					break;
				}
			}
		}
	} else {
		// "name@size" but no TTF/OTF on disk (or no FreeType / r_useFreeType 0):
		// quietly fall back to the plain bitmap font so menus keep working...
		char sBaseName[MAX_QPATH];
		int iDummy;
		Font_SplitSizedName(psName, sBaseName, sizeof(sBaseName), &iDummy);
		if (strcmp(sBaseName, psName) != 0)
		{
			return RE_RegisterFont(sBaseName);
		}
		ri.Printf( PRINT_WARNING, "RE_RegisterFont: Couldn't find font %s\n", psName );
	}

	return oriFontHandle;
}

void R_InitFonts(void)
{
	g_iCurrentFontIndex = 1;			// entry 0 is reserved for "missing/invalid"
	g_iNonScaledCharRange = INT_MAX;	// default all chars to have no special scaling (other than user supplied)

	r_fontSharpness = ri.Cvar_Get( "r_fontSharpness", "1", CVAR_ARCHIVE_ND, "" );

	cl_coloredTextShadows = ri.Cvar_Get("cl_coloredTextShadows", "0", CVAR_ARCHIVE, "Toggle JK2 1.02-style colored text shadows");
	r_fontCodepage = ri.Cvar_Get("r_fontCodepage", "0", CVAR_ARCHIVE_ND, "Windows codepage of text that is not UTF-8 (chat and names from other clients, old string files): 1250, 1251 or 1252; 0 = by se_language");
#ifdef USE_FREETYPE
	r_fontFallbacks = ri.Cvar_Get("r_fontFallbacks", "arialnb;twemoji;dejavusans-bold;wqy-zenhei;notosansthai-bold", CVAR_ARCHIVE_ND | CVAR_LATCH, "Fonts searched, in order, for glyphs a TTF font lacks; ones that are not installed are skipped");
#endif

#ifdef USE_FREETYPE
	r_useFreeType = ri.Cvar_Get("r_useFreeType", "2", CVAR_ARCHIVE_ND | CVAR_LATCH, "TTF/OTF fonts: 0 = off, 1 = only for fonts that have no .fontdat, 2 = preferred over a .fontdat of the same name");
	r_fontProfile = ri.Cvar_Get("r_fontProfile", "0", CVAR_NONE, "Time font drawing, rasterizing and uploads; \"fontlist\" prints and resets the numbers");

	if (!g_FTLibrary)
	{
		if (FT_Init_FreeType(&g_FTLibrary) == 0)
		{
			FT_Int iMajor, iMinor, iPatch;
			FT_Library_Version(g_FTLibrary, &iMajor, &iMinor, &iPatch);
			ri.Printf(PRINT_ALL, "FreeType %d.%d.%d initialized\n", iMajor, iMinor, iPatch);
		}
		else
		{
			g_FTLibrary = NULL;
			ri.Printf(PRINT_WARNING, "FT_Init_FreeType failed, TTF/OTF fonts unavailable\n");
		}
	}
#endif
}

/*
===============
R_FontList_f
===============
*/
void R_FontList_f( void ) {
	Com_Printf ("------------------------------------\n");

	FontIndexMap_t::iterator it;
	for (it = g_mapFontIndexes.begin(); it != g_mapFontIndexes.end(); ++it)
	{
		CFontInfo *font = GetFont((*it).second);
		if( font )
		{
			Com_Printf("%3i:%s  ps:%hi h:%hi a:%hi d:%hi\n", (*it).second, font->m_sFontName,
				font->mPointSize, font->mHeight, font->mAscender, font->mDescender);
		}
	}
	Com_Printf ("------------------------------------\n");
#ifdef USE_FREETYPE
	Com_Printf("Since the last fontlist: %u strings, %u glyph quads, %u shader switches\n",
		g_fontStats.draws, g_fontStats.quads, g_fontStats.pageSwitches);
	Com_Printf("  %u glyphs rasterized (%u colour layers), %u atlas uploads (%u KB)\n",
		g_fontStats.rasterized, g_fontStats.colorLayers, g_fontStats.uploads, g_fontStats.uploadKB);
	if (r_fontProfile && r_fontProfile->integer)
	{
		Com_Printf("  time: drawing %.3f ms (of which rasterizing %.3f ms, uploading %.3f ms)\n",
			g_fontStats.drawMs, g_fontStats.rasterMs, g_fontStats.uploadMs);
	}
	else
	{
		Com_Printf("  (set r_fontProfile 1 for timings)\n");
	}
	memset(&g_fontStats, 0, sizeof(g_fontStats));
#endif
}

void R_ShutdownFonts(void)
{
	for(int i = 1; i < g_iCurrentFontIndex; i++)	// entry 0 is reserved for "missing/invalid"
	{
		delete g_vFontArray[i];
	}
	g_mapFontIndexes.clear();
	g_vFontArray.clear();
	g_iCurrentFontIndex = 1;	// entry 0 is reserved for "missing/invalid"

	g_ThaiCodes.Clear();

#ifdef USE_FREETYPE
	for (int i = 0; i < g_iNumFallbacks; i++)
	{
		if (g_FallbackFaces[i])
		{
			FT_Done_Face(g_FallbackFaces[i]);
			g_FallbackFaces[i] = NULL;
		}
		if (g_FallbackData[i])
		{
			delete[] g_FallbackData[i];
			g_FallbackData[i] = NULL;
		}
	}
	g_iNumFallbacks = 0;
	g_bFallbacksLoaded = false;
	g_GSUBCache.clear();	// keyed by FT_Face pointers which are now gone
	g_TTFPendingUploads.clear();

	if (g_FTLibrary)
	{
		FT_Done_FreeType(g_FTLibrary);
		g_FTLibrary = NULL;
	}
#endif
}

// this is only really for debugging while tinkering with fonts, but harmless to leave in...
//
void R_ReloadFonts_f(void)
{
	// first, grab all the currently-registered fonts IN THE ORDER THEY WERE REGISTERED...
	//
	std::vector <sstring_t> vstrFonts;

	int iFontToFind;
	for (iFontToFind = 1; iFontToFind < g_iCurrentFontIndex; iFontToFind++)
	{
		FontIndexMap_t::iterator it;
		CFontInfo *font = GetFont( iFontToFind );
		if ( font && font->m_isVariant ) continue;
		for (it = g_mapFontIndexes.begin(); it != g_mapFontIndexes.end(); ++it)
		{
			if (iFontToFind == (*it).second)
			{
				vstrFonts.push_back( (*it).first );
				break;
			}
		}
		if (it == g_mapFontIndexes.end() )
		{
			break;	// couldn't find this font
		}
	}
	if ( iFontToFind == g_iCurrentFontIndex ) // found all of them?
	{
		// now restart the font system...
		//
		R_ShutdownFonts();
		R_InitFonts();
		//
		// and re-register our fonts in the same order as before (note that some menu items etc cache the string lengths so really a vid_restart is better, but this is just for my testing)
		//
		for (size_t iFont = 0; iFont < vstrFonts.size(); iFont++)
		{
#ifdef _DEBUG
			int iNewFontHandle = RE_RegisterFont( vstrFonts[iFont].c_str() );
			assert( iNewFontHandle == (int)(iFont+1) );
#else
			RE_RegisterFont( vstrFonts[iFont].c_str() );
#endif
		}
		Com_Printf( "Done.\n" );
	}
	else
	{
		Com_Printf( "Problem encountered finding current fonts, ignoring.\n" );	// poo. Oh well, forget it.
	}
}


// end
