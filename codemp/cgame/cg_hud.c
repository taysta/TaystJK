/*
===========================================================================
Copyright (C) 2022 Sergei Shubin

This file is part of Quake III Champions source code.

Quake III Champions source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Champions source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Champions source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

//
// cg_hud.c - New HUD
//

#include "cg_local.h"
#include "hud_local.h"

void CG_InitNewHUD( void ) {
	hud_initmedia();
	hud_initobituary();
}

/*
=================
CG_Draw2DNew
=================
*/

void CG_Draw2DNew( void ) {
	trap->R_SetColor( NULL );
	hud_drawobituary(); //todo: create/check killfeed cvar

}
