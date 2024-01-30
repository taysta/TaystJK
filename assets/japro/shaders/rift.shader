textures/rift/env_crystal
{
	surfaceparm	nonopaque
	surfaceparm	forcefield
	q3map_nolightmap
    {
        map textures/rift/env_crystal_2
        blendFunc GL_ONE GL_ONE
        tcGen environment
    }
}

textures/rift/carvedwall
{
	surfaceparm	nonopaque
    {
        map $lightmap
    }
    {
        map textures/rift/carvedwall
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/carvedwall_lowalpha
{
	qer_editorimage	textures/rift/carvedwall
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	trans
	q3map_nolightmap
	cull	twosided
    {
        map textures/rift/carvedwall
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        alphaGen const 0.3
    }
}

textures/rift/glass_crystal
{
	qer_editorimage	textures/rift/env_crystal
	surfaceparm	nonopaque
	surfaceparm	forcefield
	q3map_nolightmap
    {
        map models/map_objects/rift/glass_crystal
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen vertex
        alphaGen const 0.5
    }
    {
        map textures/rift/env_crystal
        blendFunc GL_DST_COLOR GL_ONE
        rgbGen identity
        tcGen environment
        tcMod scale 0.1 0.1
    }
}

textures/rift/symbol1
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol1_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol1_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol1
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol2
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol2_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol2_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol2
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol3
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol3_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol3_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol3
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol4
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol4_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol4_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol4
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol5
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol5_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol5_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol5
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol6
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol6_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol6_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol6
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol7
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol7_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol7_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol7
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol8
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol8_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol8_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol8
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol9
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol9_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol9_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol9
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol10
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol10_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol10_fx2
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
    {
        map textures/rift/symbol10
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol11
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol11_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol11_fx2
        blendFunc GL_ONE GL_ONE
        glow
    }
    {
        map textures/rift/symbol11
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/symbol12
{
	qer_editorimage	textures/rift/symbol1_fx1
	surfaceparm	forcesight
	polygonOffset
    {
        clampmap textures/rift/symbol12_fx1
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen wave inversesawtooth 0 1.1 0 0.7
        tcMod stretch sin 1.05 0 0 0.1
    }
    {
        map textures/rift/symbol12_fx2
        blendFunc GL_ONE GL_ONE
        glow
    }
    {
        map textures/rift/symbol12
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
}

textures/rift/rock3_phong
{
	q3map_shadeangle	98
	qer_editorimage	textures/yavin/rock3
	q3map_nonplanar
	q3map_splotchfix
	q3map_forcemeta
    {
        map textures/rift/rock3
        rgbGen identity
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/rift/newcolumn
{
    {
        map $lightmap
    }
    {
        map textures/rift/newcolumn
        blendFunc GL_DST_COLOR GL_ZERO
    }
    {
        map textures/rift/newcolumn_glow
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
}

textures/rift/stone_rim
{
    {
        map $lightmap
    }
    {
        map textures/rift/stone_rim
        blendFunc GL_DST_COLOR GL_ZERO
    }
    {
        map textures/rift/stone_rim_glow
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
}

textures/rift/cobweb
{
	surfaceparm	nonsolid
	q3map_nolightmap
	cull	twosided
	deformvertexes	wave	50 sin 0 2.5 0 0.35
    {
        map textures/rift/cobweb
        blendFunc GL_SRC_ALPHA GL_ONE
    }
}

textures/rift/piller_formal
{
	qer_editorimage	textures/rift/piller_formal
    {
        map textures/common/etest4
        tcGen environment
    }
    {
        map textures/rift/piller_formal
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/thin_trim2
{
	qer_editorimage	textures/rift/thin_trim2
    {
        map textures/common/etest4
        tcGen environment
    }
    {
        map textures/rift/thin_trim2
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/basepiller
{
	qer_editorimage	textures/rift/basepiller
    {
        map textures/common/etest4
        tcGen environment
    }
    {
        map textures/rift/basepiller
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/base_ornate
{
	qer_editorimage	textures/rift/base_ornate
    {
        map textures/common/etest4
        tcGen environment
    }
    {
        map textures/rift/base_ornate
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/basewall_ornate
{
	qer_editorimage	textures/rift/basewall_ornate
    {
        map textures/common/etest4
        tcGen environment
    }
    {
        map textures/rift/basewall_ornate
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/rift/cobweb2
{
	qer_editorimage	textures/rift/cobweb2
	surfaceparm	nonsolid
	q3map_nolightmap
	cull	twosided
	deformvertexes	wave	50 sin 0 2.5 0 0.35
    {
        map textures/rift/cobweb2
        blendFunc GL_SRC_ALPHA GL_ONE
    }
}

textures/rift/env_crystal_red
{
	qer_editorimage	textures/rift/env_crystal_2
	surfaceparm	nonopaque
	surfaceparm	forcefield
	q3map_nolightmap
    {
        map textures/rift/env_crystal_red
        blendFunc GL_ONE GL_ONE
        glow
        tcGen environment
    }
}

textures/rift/env_crystal_green
{
	qer_editorimage	textures/rift/env_crystal_2
	surfaceparm	nonopaque
	surfaceparm	forcefield
	q3map_nolightmap
    {
        map textures/rift/env_crystal_green
        blendFunc GL_ONE GL_ONE
        glow
        tcGen environment
    }
}

textures/rift/env_crystal_blue
{
	qer_editorimage	textures/rift/env_crystal_2
	surfaceparm	nonopaque
	surfaceparm	forcefield
	q3map_nolightmap
    {
        map textures/rift/env_crystal
        blendFunc GL_ONE GL_ONE
        glow
        tcGen environment
    }
}

textures/rift/carved_symbol
{
	polygonOffset
	q3map_nolightmap
    {
        map textures/rift/carved_symbol
        alphaFunc GE128
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        depthWrite
        rgbGen vertex
    }
}

models/map_objects/rift/crystal_lamp_alpha
{
	surfaceparm	trans
    {
        map models/map_objects/rift/crystal_lamp
        blendFunc GL_ONE GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen const 0
    }
    {
        map textures/rift/env_crystal
        blendFunc GL_DST_COLOR GL_SRC_COLOR
        rgbGen identity
        tcGen environment
    }
}

models/map_objects/rift/crystal_wall
{
    {
        map $lightmap
    }
    {
        map models/map_objects/rift/crystal_wall
        blendFunc GL_DST_COLOR GL_ZERO
    }
    {
        map models/map_objects/rift/crystal_wall_glow
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
}

models/map_objects/rift/crystal_floor
{
    {
        map $lightmap
    }
    {
        map models/map_objects/rift/crystal_floor
        blendFunc GL_DST_COLOR GL_ZERO
    }
    {
        map models/map_objects/rift/crystal_floor_glow
        blendFunc GL_ONE GL_ONE
        glow
        rgbGen identity
    }
}

models/map_objects/rift/crystal_pilar
{
	q3map_nolightmap
    {
        map textures/cfoster/etest4
        tcGen environment
    }
    {
        map models/map_objects/rift/crystal_pilar
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

gfx/effects/starburst1
{
	surfaceparm	nonsolid
	surfaceparm	trans
	q3map_nolightmap
	q3map_onlyvertexlighting
    {
        map gfx/effects/starburst1
        blendFunc GL_SRC_ALPHA GL_ONE
        rgbGen wave sin 1 0.2 0 0.5
        alphaGen vertex
    }
}

gfx/effects/starburst2
{
	qer_editorimage	gfx/effects/starburst1
	surfaceparm	nonsolid
	surfaceparm	trans
	q3map_nolightmap
	q3map_onlyvertexlighting
    {
        map gfx/effects/starburst2
        blendFunc GL_SRC_ALPHA GL_ONE
        alphaGen vertex
    }
}

textures/decals/floor_scrapes
{
	polygonOffset
	q3map_nolightmap
    {
        map textures/decals/floor_scrapes
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
    }
}

