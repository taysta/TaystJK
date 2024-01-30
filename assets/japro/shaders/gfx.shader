console
{
	nopicmip
	nomipmaps
    {
        map gfx/interface/stars
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        alphaGen vertex
        tcMod scroll 0.01 0.02
        tcMod scale 2 1
    }
    {
        map gfx/interface/console_jediacademy
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave sin 0.2 0.1 0 0.2
    }
}

markShadow
{
	polygonOffset
    {
        clampmap gfx/damage/shadow
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen identity
        alphaGen vertex
    }
}

// wake is the mark on water surfaces for paddling players

wake
{
	cull	disable
    {
        clampmap gfx/misc/splash
        blendFunc GL_ONE GL_ONE
        rgbGen wave sawtooth 1 -1 0 0.8
        tcMod stretch sawtooth 0.5 0.55 0 0.8
        tcMod rotate -15
    }
    {
        clampmap gfx/misc/splash
        blendFunc GL_ONE GL_ONE
        rgbGen wave sawtooth 1 -1 0.33 0.8
        alphaGen const 0.6
        tcMod rotate 30
        tcMod stretch sawtooth 0.5 0.5 0.33 0.8
    }
    {
        clampmap gfx/misc/splash
        blendFunc GL_ONE GL_ONE
        rgbGen wave sawtooth 1 -1 0.66 1
        alphaGen const 0.6
        tcMod rotate -40
        tcMod stretch sawtooth 0.3 0.7 0.66 1
        tcMod turb 0.02 0.01 0 1
    }
}

// projectionShadow is used for cheap squashed model shadows

projectionShadow
{
	polygonOffset
	deformvertexes	projectionShadow
    {
// just solid black

        map $whiteimage
        blendFunc GL_ONE GL_ZERO
        rgbGen wave square 0 0 0 0
    }
}

white
{
    {
        map $whiteimage
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

sun
{
	cull	twosided
    {
        map gfx/misc/sun
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

sun2
{
	qer_editorimage	gfx/misc/sun
	cull	twosided
    {
        map gfx/misc/sun
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/misc/flare
{
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flare
        blendFunc GL_ONE GL_ONE
        depthFunc disable
        glow
        rgbGen vertex
    }
}

gfx/misc/probechunk01
{
	cull	twosided
    {
        map gfx/misc/probechunk01
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

gfx/misc/probechunk02
{
	cull	twosided
    {
        map gfx/misc/probechunk02
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

gfx/misc/probechunk03
{
	cull	twosided
    {
        map gfx/misc/probechunk03
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

// ===============================================================

// navigation aids

gfx/misc/nav_arrow
{
	cull	twosided
    {
        map gfx/misc/navarrow
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen identity
        alphaGen wave sin 0.5 0.25 0 1
        tcMod scroll 0 -2
    }
}

gfx/misc/nav_node
{
	cull	twosided
    {
        map gfx/misc/navnode
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen exactVertex
        alphaGen wave sin 0.5 0.25 0 1
    }
}

gfx/misc/nav_line
{
	cull	twosided
    {
        map gfx/misc/navline
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen exactVertex
        alphaGen wave sin 0.5 0.25 0 1
    }
}

gfx/misc/nav_cpoint
{
	cull	twosided
    {
        map gfx/misc/cpoint
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen exactVertex
        alphaGen wave sin 0.5 0.25 0 1
    }
}

gfx/misc/nav_radius
{
	qer_editorimage	gfx/misc/navnode
	cull	twosided
    {
        map gfx/misc/navradius
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen exactVertex
        alphaGen wave sin 0.5 0.25 0 1
    }
}

gfx/misc/flare_long
{
    {
        map gfx/misc/flare_long
        blendFunc GL_ONE GL_ONE
        depthFunc disable
        glow
        rgbGen vertex
    }
}

gfx/misc/Flareparticle
{
	qer_editorimage	gfx/misc/flare
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flare
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/misc/flaretail
{
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
    {
        map gfx/misc/flaretail
        blendFunc GL_ONE GL_ONE
    }
}

gfx/misc/flaretail3
{
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
    {
        map gfx/misc/flaretail3
        blendFunc GL_ONE GL_ONE
    }
}

gfx/misc/halo
{
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	q3map_nolightmap
	cull	twosided
    {
        map gfx/misc/halo
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
    }
}

gfx/misc/flaretailup
{
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flaretailup
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
    }
}

gfx/misc/fxflare
{
	qer_editorimage	gfx/misc/flare
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flare
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
    }
}

gfx/misc/flaretailside
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flaretailside
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        tcMod scroll 5 0
    }
}

gfx/misc/Chunk
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/chunk
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
    }
}

gfx/misc/Twirl1
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/twirl1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/misc/Bars
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/bars
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        tcMod scroll 10 0
    }
}

gfx/misc/ftailside_c
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flaretailside_c
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        tcMod scroll 5 0
    }
}

gfx/misc/ftailside_r
{
	qer_editorimage	gfx/misc/flaretailup
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	cull	twosided
    {
        map gfx/misc/flaretailside_c1
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
        tcMod scroll -5 0
    }
}

gfx/misc/nav_arrow_new
{
	qer_editorimage	gfx/misc/navline
	cull	twosided
    {
        map gfx/misc/navarrow_old
        blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE
        rgbGen entity
        tcMod scroll 0 -1
    }
}

gfx/misc/flaretail2
{
	qer_editorimage	gfx/misc/flaretail
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
    {
        map gfx/misc/flaretail
        blendFunc GL_ONE GL_ONE
        rgbGen vertex
    }
}

gfx/hud/background
{
	q3map_nolightmap
	cull	twosided
    {
        clampmap gfx/hud/background
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
    {
        map gfx/hud/static_gold
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0.5 3
        tcMod scroll 0.3 0
    }
    {
        map gfx/hud/static_gold
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0 3
        tcMod scroll -0.3 0
    }
    {
        map gfx/hud/static_gold
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll 1 0
    }
    {
        map gfx/hud/static_gold
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll -1 0
    }
}

gfx/hud/hudleft
{
	nopicmip
    {
        map gfx/hud/hudleft
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

gfx/hud/hudleft_innerframe
{
	nopicmip
    {
        map gfx/hud/hudleft_innerframe
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/hud/background_f
{
	q3map_nolightmap
	cull	twosided
    {
        clampmap gfx/hud/background_f
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map gfx/hud/static4
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0.5 3
        tcMod scroll 0.3 0
    }
    {
        map gfx/hud/static4
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0 3
        tcMod scroll -0.3 0
    }
    {
        map gfx/hud/static4
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll 1 0
    }
    {
        map gfx/hud/static4
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll -1 0
    }
}

gfx/hud/background_i
{
	q3map_nolightmap
	cull	twosided
    {
        clampmap gfx/hud/background_i
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map gfx/hud/static_green
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0.5 3
        tcMod scroll 0.3 0
    }
    {
        map gfx/hud/static_green
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        rgbGen wave square 0 1 0 3
        tcMod scroll -0.3 0
    }
    {
        map gfx/hud/static_green
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll 1 0
    }
    {
        map gfx/hud/static_green
        blendFunc GL_ONE GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll -1 0
    }
}

gfx/hud/prong_on_weap
{
	nopicmip
	nomipmaps
	notc
	cull disable
	{
		map gfx/hud/prong_on_w
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}
}

gfx/hud/prong_on_item
{
	nopicmip
	nomipmaps
	notc
	cull disable
	{
		map gfx/hud/prong_on_i
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}
}

gfx/hud/prong_on_force
{
	nopicmip
	nomipmaps
	notc
	cull disable
	{
		map gfx/hud/prong_on_f
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}
}

gfx/hud/hudrightframe
{
	nopicmip
    {
        map gfx/hud/static5
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.5 1.4 1
        tcMod scroll 0 1
    }
    {
        map gfx/hud/static9
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
    {
        map gfx/hud/hudrightframe
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

gfx/hud/hudright_innerframe
{
	nopicmip
    {
        map gfx/hud/hudright_innerframe
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/hud/mpi_fboon
{
	nomipmaps
    {
        clampmap gfx/hud/mpi_fboon
        blendFunc GL_ONE GL_ONE
        glow
        tcMod rotate 50
    }
    {
        clampmap gfx/hud/mpi_fboonglo1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave sin 1 0.6 0.2 3
        tcMod rotate -25
    }
    {
        clampmap gfx/hud/mpi_fboon
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave sin 0 1 0 8
        tcMod rotate 80
        tcMod stretch sawtooth 0 1 0 3
    }
}

gfx/hud/mp_levelload
{
	nopicmip
	nomipmaps
    {
        map gfx/hud/mp_levelload
        blendFunc GL_ONE GL_ONE
        glow
    }
}

gfx/hud/load_tick
{
	nopicmip
	nomipmaps
    {
        map gfx/hud/load_tick2
        blendFunc GL_ONE GL_ONE
        glow
    }
}

gfx/hud/load_tick_cap
{
	nopicmip
	nomipmaps
    {
        clampmap gfx/hud/load_tick_cap
        blendFunc GL_ONE GL_ONE
        glow
    }
}

gfx/hud/saber_stylesfast
{
	nopicmip
	nomipmaps
	cull	twosided
    {
        map gfx/hud/saber_stylesfast
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/hud/saber_stylesmed
{
	nopicmip
	nomipmaps
	cull	twosided
    {
        map gfx/hud/saber_stylesmed
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/hud/saber_stylesstrong
{
	nopicmip
	nomipmaps
	cull	twosided
    {
        map gfx/hud/saber_stylesstrong
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
    }
}

gfx/hud/w_icon_atst_na
{
	nomipmaps
    {
        clampmap gfx/hud/w_icon_atst
        blendFunc GL_ONE GL_ZERO
    }
}

gfx/hud/w_icon_atstside_na
{
	nomipmaps
    {
        clampmap gfx/hud/w_icon_atstside
        blendFunc GL_ONE GL_ZERO
    }
}

gfx/hud/force_swirl
{
	nomipmaps
    {
        clampmap gfx/hud/force_swirl
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
        tcMod rotate 195
    }
    {
        map gfx/hud/force_swirl2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
        tcMod rotate -300
    }
    {
        clampmap gfx/hud/force_swirl
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen vertex
        tcMod rotate 195
    }
}

gfx/hud/hudleft_scanline
{
	qer_editorimage	gfx/hud/static2
	nopicmip
    {
        clampmap gfx/hud/static2
        blendFunc GL_ONE GL_ONE
        glow
        tcMod transform 1 0 0 1 0.5 -0.51
        tcMod rotate 125
    }
}

gfx/hud/vehicle_grid
{
	q3map_nolightmap
    {
        map gfx/hud/vehicle_grid
        blendFunc GL_ONE GL_ONE
        glow
    }
}

gfx/hud/vehicle_grid2
{
	q3map_nolightmap
    {
        map gfx/hud/vehicle_grid2
        blendFunc GL_ONE GL_ONE
        glow
    }
}

gfx/sprites/cry_rock_md
{
	nopicmip
	nomipmaps
	cull	twosided
    {
        map gfx/sprites/cry_rock_md
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
}

gfx/sprites/cry_rock_lg
{
	nopicmip
	nomipmaps
	cull	twosided
    {
        map gfx/sprites/cry_rock_lg
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
}

gfx/sprites/sand
{
	cull	twosided
    {
        map gfx/sprites/sand
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
}

gfx/chunks/grate1
{
	cull	twosided
    {
        map gfx/chunks/grate_bit1
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
}

gfx/chunks/grate2
{
	cull	twosided
    {
        map gfx/chunks/grate_bit2
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
    }
}

gfx/decals/vjun_scorch1
{
	polygonOffset
	q3map_nolightmap
    {
        map gfx/decals/vjun_scorch1
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

gfx/decals/vjun_scorch2
{
	qer_editorimage	gfx/decals/vjun_scorch1
	polygonOffset
	q3map_nolightmap
    {
        map gfx/decals/vjun_scorch2
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

gfx/decals/vjun_scorch3
{
	qer_editorimage	gfx/decals/vjun_scorch1
	polygonOffset
	q3map_nolightmap
    {
        map gfx/decals/vjun_scorch3
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

gfx/mp/siegeicons/desert/droid_parts_hilite
{
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/desert/droid_parts
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/desert/droid_parts_hilite
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/desert/wall_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/desert/wall_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/desert/wall_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/desert/tower_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/desert/tower_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/desert/tower_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/desert/gate_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/desert/gate_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/desert/gate_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/desert/console_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/desert/console_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/desert/console_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/generator_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/generator_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/generator_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/infirmary_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/infirmary_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/infirmary_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/bridge_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/bridge_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/bridge_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/walldoor_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/walldoor_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/walldoor_o
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/droid_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/droid_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/droid_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/hoth/comcenter_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/hoth/comcenter_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/hoth/comcenter_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/scepter_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/scepter_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/scepter_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/red_crystal_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/red_crystal_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/red_crystal_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/green_crystal_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/green_crystal_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/blue_crystal_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/blue_crystal_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/blue_crystal_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/blue_crystal_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/gate1_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/gate1_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/gate1_outline
        blendFunc GL_ONE GL_ONE
    }
}

gfx/mp/siegeicons/korriban/coffin_outline
{
	qer_editorimage	gfx/mp/siegeicons/desert/droid_parts
	nopicmip
	nomipmaps
    {
        clampmap gfx/mp/siegeicons/korriban/coffin_o
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        clampmap gfx/mp/siegeicons/korriban/coffin_outline
        blendFunc GL_ONE GL_ONE
    }
}

