// bg_cosmetics.c
// cgame and ui, NOT game.
//

#include "qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_cosmetics.h"
#include "cJSON.h"

#include <ctype.h>

#ifdef _CGAME
	#include "cgame/cg_local.h"
#elif UI_BUILD
	#include "ui/ui_local.h"
#endif

#define VALID_COSMETIC_OFFSETS(x, y, z) (cJSON_IsNumber(x) && cJSON_IsNumber(y) && cJSON_IsNumber(z))

static void BG_LoadCosmeticCategory(const char *path, int pathLen, int *totalCosmetics, cosmeticItem_t **storePtr)
{
	int fileCnt, i, j, fileLen;
	char cosmeticFiles[MAX_QPATH * 256]; //lets support 256 cosmetics for every category for now.
	char cosmetic[MAX_QPATH];
	cosmeticItem_t *cosmeticsPtr;
	char *ptr;

	fileCnt = trap->FS_GetFileList(path, ".md3", cosmeticFiles, sizeof(cosmeticFiles));

	if (!fileCnt) return;

	cosmeticsPtr = malloc(fileCnt * sizeof(*cosmeticsPtr));
	if (!cosmeticsPtr) trap->Error(ERR_DROP, S_COLOR_RED"ERROR: Failed to allocate memory for cosmetics.\n");

	ptr = cosmeticFiles;
	j = 0;

	for (i = 0; i < fileCnt; i++, ptr += fileLen + 1)
	{
		qhandle_t handle;

		memset(cosmetic, 0, MAX_QPATH);
		fileLen = strlen(ptr);

		if ((pathLen + fileLen) > (MAX_QPATH - 1))
		{
			Com_Printf(S_COLOR_YELLOW"WARNING: Cosmetic [%s] path exceeded max length of %d, skipping...\n", ptr, MAX_QPATH - 1);
			continue;
		}

		Q_strncpyz(cosmetic, ptr, sizeof(cosmetic));
		COM_StripExtension(cosmetic, cosmetic, sizeof(cosmetic));

		if (strlen(cosmetic) > (MAX_COSMETIC_LENGTH - 1))
		{
			Com_Printf(S_COLOR_YELLOW"WARNING: Cosmetic [%s] filename exceeded max length of %d, skipping...\n", cosmetic, MAX_COSMETIC_LENGTH - 1);
			continue;
		}

		if (isdigit(cosmetic[0]))
		{
			Com_Printf(S_COLOR_YELLOW"WARNING: Cosmetic [%s] filename starts with a digit, skipping...\n", cosmetic);
			continue;
		}

		handle = trap->R_RegisterModel(va("%s%s.md3", path, cosmetic));

		if (!handle)
		{
			Com_Printf(S_COLOR_YELLOW"WARNING: Failed to register cosmetic [%s], skipping...\n", cosmetic);
			continue;
		}

		Q_strncpyz(cosmeticsPtr[j].name, cosmetic, sizeof(cosmeticsPtr[j].name));
		cosmeticsPtr[j].xOffset = cosmeticsPtr[j].yOffset = cosmeticsPtr[j].zOffset = 0;
		cosmeticsPtr[j].handle = handle;
		j++;
	}

	if (j == 0)
	{
		free(cosmeticsPtr);
		cosmeticsPtr = NULL;
	}
	else if (j < fileCnt)
	{
		cosmeticItem_t *temp = realloc(cosmeticsPtr, j * sizeof(*cosmeticsPtr));
		if (!temp) trap->Error(ERR_DROP, S_COLOR_RED"ERROR: Failed to reallocate memory for cosmetics.\n");
		cosmeticsPtr = temp;
	}

	*storePtr = cosmeticsPtr;
	*totalCosmetics = j;
}

void BG_LoadCosmetics(cosmetics_t *cosmetics)
{
	if (!cosmetics) return;

	BG_LoadCosmeticCategory(COSMETIC_HATS_PATH, COSMETIC_HATS_PATH_LENGTH, &cosmetics->totalHats, &cosmetics->hats);
	BG_LoadCosmeticCategory(COSMETIC_CAPES_PATH, COSMETIC_CAPES_PATH_LENGTH, &cosmetics->totalCapes, &cosmetics->capes);
}

void BG_FreeCosmetics(cosmetics_t *cosmetics)
{
	if (!cosmetics) return;

	if (cosmetics->hats) {
		free(cosmetics->hats);
		cosmetics->hats = NULL;
	}

	if (cosmetics->capes) {
		free(cosmetics->capes);
		cosmetics->capes = NULL;
	}

	cosmetics->totalHats = 0;
	cosmetics->totalCapes = 0;
}

void BG_LoadCustomCosmeticOffsets(const char *settingsPath, int pathLen, cosmeticItem_t *cosmetic, const char *model, const char *skin)
{
	char fullPath[MAX_QPATH];
	char *cosmeticName;
	fileHandle_t file;
	int fileSize, i;
	qboolean modelFallback = qfalse; //Let's set the default value to false.

	if (!cosmetic || !cosmetic->handle) return;

	cosmeticName = cosmetic->name;

	if (pathLen + strlen(cosmeticName) + strlen("cosmetic") + 1 >= MAX_QPATH)
	{
		Com_Printf(S_COLOR_YELLOW"WARNING: Skipping custom offsets for cosmetic (%s), path too long.\n", cosmeticName);
		return;
	}

	Com_sprintf(fullPath, sizeof(fullPath),"%s%s.cosmetic", settingsPath, cosmeticName);
	fileSize = trap->FS_Open(fullPath, &file, FS_READ);

	if (fileSize <= 0) //File doesn't exist.
	{
		cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
		trap->FS_Close(file);
		return;
	}
	else
	{
		char *buff = malloc((fileSize + 1) * sizeof(char));
		cJSON *json;
		cJSON *jsonModel;
		cJSON *jsonSkin;
		cJSON *jsonModelFallback;
		cJSON *xOffset, *yOffset, *zOffset;

		if (!buff)
		{
			trap->FS_Close(file);
			trap->Error(ERR_DROP,S_COLOR_RED"ERROR: Failed to allocate memory of cosmetic offsets.\n");
		}

		trap->FS_Read(buff, fileSize, file);
		buff[fileSize] = '\0';
		trap->FS_Close(file);

		json = cJSON_Parse(buff);

		if (!json)
		{
			Com_Printf(S_COLOR_YELLOW"WARNING: Skipping custom offsets for cosmetic (%s), failed to parse JSON.\n", cosmeticName);
			cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
			free(buff);
			return;
		}

		jsonModel = cJSON_GetObjectItemCaseSensitive(json, va("%s",model));

		if (!jsonModel) // No custom offsets for the exact model have been been found, lets look for wildcard names.
		{
			char* ptr;
			int longestLen = 0;
			int skinLen = strlen(model);
			int len;
			int index = -1;

			for (i = 0; i < cJSON_GetArraySize(json); i++)
			{
				cJSON* temp = cJSON_GetArrayItem(json, i);

				if (!cJSON_IsObject(temp)) continue;
				ptr = strchr(temp->string, '*');
				if (!ptr) continue;
				len = ptr - temp->string;

				if (len <= skinLen && !strncmp(temp->string, model, len))
				{
					if (len > longestLen)
					{
						longestLen = len;
						index = i;
					}
				}
			}

			if (index > -1) //We found a wildcard model.
			{
				jsonModel = cJSON_GetArrayItem(json, index);
				goto foundValidModel;
			}
			else
			{
				cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
				cJSON_Delete(json);
				free(buff);
				return;
			}
		}
		else
		{
			foundValidModel:
			jsonModelFallback = cJSON_GetObjectItem(jsonModel, "modelFallback");
			if (cJSON_IsBool(jsonModelFallback))
			{
				if (cJSON_IsTrue(jsonModelFallback)) {
					modelFallback = qtrue;
				}
				else
				{
					modelFallback = qfalse;
				}
			}

			jsonSkin = cJSON_GetObjectItemCaseSensitive(jsonModel, va("%s", skin));

			if (!jsonSkin) // No custom offsets for the exact skin have been been found, lets look for wildcard names.
			{
				char *ptr;
				int longestLen = 0;
				int skinLen = strlen(skin);
				int len;
				int index = -1;

				for (i = 0; i < cJSON_GetArraySize(jsonModel); i++)
				{
					cJSON *temp = cJSON_GetArrayItem(jsonModel, i);

					if (!cJSON_IsObject(temp)) continue;
					ptr = strchr(temp->string, '*');
					if (!ptr) continue;
					len = ptr - temp->string;

					if (len <= skinLen && !strncmp(temp->string, skin, len))
					{
						if (len > longestLen)
						{
							longestLen = len;
							index = i;
						}
					}
				}

				if (index > -1) //We found a wildcard skin.
				{
					jsonSkin = cJSON_GetArrayItem(jsonModel, index);

					xOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "xOffset");
					yOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "yOffset");
					zOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "zOffset");

					if (VALID_COSMETIC_OFFSETS(xOffset, yOffset, zOffset)) {
						cosmetic->xOffset = xOffset->valueint;
						cosmetic->yOffset = yOffset->valueint;
						cosmetic->zOffset = zOffset->valueint;
					}
					else
					{
						Com_Printf(S_COLOR_YELLOW"WARNING: Skipping custom offsets for cosmetic (%s), the skin (%s) JSON object does not contain valid offset values.\n", cosmeticName, jsonSkin->string);
						cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
					}
				}
				else //No wildcard found, check if we should fallback to the model's offsets or not.
				{
					if (modelFallback)
					{
						xOffset = cJSON_GetObjectItemCaseSensitive(jsonModel, "xOffset");
						yOffset = cJSON_GetObjectItemCaseSensitive(jsonModel, "yOffset");
						zOffset = cJSON_GetObjectItemCaseSensitive(jsonModel, "zOffset");

						if (VALID_COSMETIC_OFFSETS(xOffset, yOffset, zOffset)) {
							cosmetic->xOffset = xOffset->valueint;
							cosmetic->yOffset = yOffset->valueint;
							cosmetic->zOffset = zOffset->valueint;
						}
						else
						{
							Com_Printf(S_COLOR_YELLOW"WARNING: Skipping custom offsets for cosmetic (%s), the model (%s) JSON object does not contain valid offset values.\n", cosmeticName, jsonModel->string);
							cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
						}
					}
					else
					{
						cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
					}
				}
			}
			else
			{
				xOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "xOffset");
				yOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "yOffset");
				zOffset = cJSON_GetObjectItemCaseSensitive(jsonSkin, "zOffset");

				if (VALID_COSMETIC_OFFSETS(xOffset, yOffset, zOffset)) {
					cosmetic->xOffset = xOffset->valueint;
					cosmetic->yOffset = yOffset->valueint;
					cosmetic->zOffset = zOffset->valueint;
				}
				else
				{
					Com_Printf(S_COLOR_YELLOW"WARNING: Skipping custom offsets for cosmetic (%s),the skin (%s) JSON object does not contain valid offset values.\n", cosmeticName, jsonSkin->string);
					cosmetic->xOffset = cosmetic->yOffset = cosmetic->zOffset = 0;
				}
			}
		}
		cJSON_Delete(json);
		free(buff);
	}
}

cosmeticItem_t *BG_FindCosmeticByName(const char *name, cosmeticItem_t *items, int count)
{
	int i;

	if (!name || !*name || !items) return NULL;

	for (i = 0; i < count; i++)
	{
		if (!Q_stricmp(items[i].name, name))
			return &items[i];
	}
	return NULL;
}
