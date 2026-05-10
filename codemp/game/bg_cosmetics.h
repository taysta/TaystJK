#pragma once

#include "qcommon/q_shared.h"

//Let's use 14 bytes because OpenJK and JA++ game modules both use 16 bytes buffer for color1, so if we support up to 16 only, we can pretty much use this on any server.
//The remaining 2 bytes are to support the actual saber colors, since TaystJK supports up to 12 colors, we need to reserve 2 bytes for the color.
#define MAX_COSMETIC_LENGTH 14

#define COSMETIC_HATS_PATH "models/cosmetics/hats/"
#define COSMETIC_HATS_PATH_LENGTH (sizeof(COSMETIC_HATS_PATH) - 1)
#define COSMETIC_HATS_SETTINGS_PATH "settings/cosmetics/hats/"
#define COSMETIC_HATS_SETTINGS_PATH_LENGTH (sizeof(COSMETIC_HATS_SETTINGS_PATH) - 1)

#define COSMETIC_CAPES_PATH "models/cosmetics/capes/"
#define COSMETIC_CAPES_PATH_LENGTH (sizeof(COSMETIC_CAPES_PATH) - 1)
#define COSMETIC_CAPES_SETTINGS_PATH "settings/cosmetics/capes/"
#define COSMETIC_CAPES_SETTINGS_PATH_LENGTH (sizeof(COSMETIC_CAPES_SETTINGS_PATH) - 1)

typedef struct cosmeticItem_s {
	char		name[MAX_COSMETIC_LENGTH];
	qhandle_t	handle;
	int			xOffset;
	int			yOffset;
	int			zOffset;
} cosmeticItem_t;

typedef struct cosmetics_s {
	cosmeticItem_t	*hats;
	cosmeticItem_t	*capes;
	int				totalHats;
	int				totalCapes;
} cosmetics_t;

void			BG_LoadCosmetics(cosmetics_t *cosmetics);
void			BG_FreeCosmetics(cosmetics_t *cosmetics);
void			BG_LoadCustomCosmeticOffsets(const char *settingsPath, int pathLen, cosmeticItem_t *cosmetic,const char *model, const char *skin );
cosmeticItem_t *BG_FindCosmeticByName(const char *name, cosmeticItem_t *items, int count );
