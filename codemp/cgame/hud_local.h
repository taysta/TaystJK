/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2005 - 2015, ioquake3 contributors
Copyright (C) 2013 - 2015, OpenJK contributors
Copyright (C) 2015 - 2021, EternalJK contributors
Copyright (C) 2015 - 2023, TaystJK contributors


This file is part of the TaystJK source code.

TaystJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <https://www.gnu.org/licenses/>.
===========================================================================
*/

#if !defined( HUD_LOCAL_H )
#define HUD_LOCAL_H


#define MAX_OBITUARY 8
#define OBITUARY_TIMEOUT 2500
#define OBITUARY_FADEOUTTIME 2000
#define OBITUARY_ICON_SIZE 18.0f
#define OBITUARY_TEXT_SIZE 2.0f

#define OBITUARY_PADDING_SCALAR 0.2f

enum KillfeedAlignment
{
    KF_RIGHT,
    KF_LEFT,
    KF_CENTER,
};

typedef struct {
    int	killer;
    int victim;
    meansOfDeath_t mod;
    int time;
} obituary_t;

typedef struct {
    qhandle_t	deathIcon; // for generic kill message
	qhandle_t	modIcon[MOD_MAX];				// means of death icons
} hudMedia_t;

extern hudMedia_t hm;
extern vec4_t       hudModColors[MOD_MAX];
extern const char	*hudModIcons[MOD_MAX];

// get all the required assets
void HUD_InitMedia( void );
void HUD_InitObituary( void );
void HUD_DrawObituary( void );
void HUD_InitKFAlignment( void );
#endif
