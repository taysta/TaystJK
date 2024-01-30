textures/jnegretetest/water3
{
	qer_editorimage	textures/common/direction
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	water
	surfaceparm	trans
	q3map_material	Water
    {
        map textures/yavin/lshadow
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen const ( 1.000000 1.000000 1.000000 )
        tcMod turb 2 0.05 0 0.1
    }
    {
        map textures/common/water3
        blendFunc GL_ONE GL_SRC_ALPHA
        rgbGen const ( 0.423529 0.423529 0.423529 )
        alphaGen const 0.7
        tcMod turb 0.5 0.03 0 0.3
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
    {
        clampmap gfx/sprites/fog
            surfaceSprites effect 20 8 50 300
            ssFademax 1000
            ssFadescale 2
            ssVariance 2 1
            ssWind 4
            ssFXDuration 5000
            ssFXGrow 2 2
            ssFXAlphaRange 0.75 0
            ssFXWeather
        blendFunc GL_ONE GL_ONE
    }
}
textures/jnegretetest/water2
{
	qer_editorimage	textures/common/water_1
	qer_trans	0.6
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	water
	surfaceparm	trans
	q3map_material	Water
    {
        map textures/common/water4
        blendFunc GL_ONE GL_SRC_ALPHA
        alphaGen const 0.5
        tcMod turb 0.5 0.03 0 0.3
    }
    {
        map $lightmap
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/jnegretetest/ice_phong
{
	qer_editorimage textures/hoth/h_basicwall.tga
	q3map_nonplanar
	q3map_shadeAngle 120
	q3map_splotchfix
	q3map_forcemeta

    {
	map textures/hoth/h_basicwall.tga
	//tcMod scale 0.25 0.25
	rgbGen identity
    }
    {
	map $lightmap
	blendFunc GL_DST_COLOR GL_ZERO
	rgbGen identity
    }
}

textures/jnegretetest/cut_ice_phong
{
	qer_editorimage textures/hoth/h_basicwall_2.tga
	q3map_nonplanar
	q3map_shadeAngle 120
	q3map_splotchfix
	q3map_forcemeta

    {
	map textures/hoth/h_basicwall_2.tga
	//tcMod scale 0.25 0.25
	rgbGen identity
    }
    {
	map $lightmap
	blendFunc GL_DST_COLOR GL_ZERO
	rgbGen identity
    }
}


textures/jnegretetest/chiseled_phong
{
	qer_editorimage textures/hoth/h_wallchunk

	q3map_nonplanar
	q3map_shadeAngle 120
	q3map_splotchfix
	q3map_forcemeta

    {
	map textures/hoth/h_wallchunk
	//tcMod scale 0.25 0.25
	rgbGen identity
    }
    {
	map $lightmap
	blendFunc GL_DST_COLOR GL_ZERO
	rgbGen identity
    }
}

textures/jnegretetest/ice_rock_phong
{
	qer_editorimage textures/hoth/rock_huge_snow.tga

	q3map_nonplanar
	q3map_shadeAngle 120
	q3map_splotchfix
	q3map_forcemeta

    {
	map textures/hoth/rock_huge_snow.tga
	//tcMod scale 0.25 0.25
	rgbGen identity
    }
    {
	map $lightmap
	blendFunc GL_DST_COLOR GL_ZERO
	rgbGen identity
    }
}


textures/jnegretetest/grey_snow_phong
{
	qer_editorimage textures/hoth/h_floor.tga

	q3map_nonplanar
	q3map_shadeAngle 120
	q3map_splotchfix
	q3map_forcemeta
    {
	map textures/hoth/h_floor.tga
	//tcMod scale 0.25 0.25
	rgbGen identity
    }
    {
	map $lightmap
	blendFunc GL_DST_COLOR GL_ZERO
	rgbGen identity
    }
}

textures/jnegretetest/standard_flare
{
	surfaceparm	nonsolid
	surfaceparm	trans
	q3map_nolightmap
	deformvertexes	autoSprite
    {
        map textures/flares/standard_flare.jpg
	  rgbGen vertex
	  blendFunc GL_ONE GL_ONE
	  depthFunc disable
    }
}

textures/jnegretetest/hoth_fog
{

	qer_editorimage	textures/JNegreteTest/hoth_fog.tga
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	fog
	surfaceparm	trans
	q3map_nolightmap
	// (  Red          Green        Blue     ) Distance
	fogparms	( 0.744375 0.845131 1.000000 ) 4900.0
}


textures/jnegretetest/vjun1_fog
{

	qer_editorimage	textures/jnegretetest/hoth_fog.tga
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	fog
	surfaceparm	trans
	q3map_nolightmap
	//        (  Red     Green    Blue     )  Max Distance
	fogparms  ( 1.000000 0.718533 0.366187 )  1983.0

}

textures/jnegretetest/hoth_2_fog
{


	qer_editorimage	textures/JNegreteTest/hoth_fog.tga
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	fog
	surfaceparm	trans
	q3map_nolightmap
	// (  Red          Green        Blue     ) Distance
	fogparms	( 0.34902 0.454902 0.607843 ) 1900.0
}

textures/jnegretetest/echo_fog
{


	qer_editorimage	textures/JNegreteTest/hoth_fog.tga
	surfaceparm	nonsolid
	surfaceparm	nonopaque
	surfaceparm	fog
	surfaceparm	trans
	q3map_nolightmap
	// (  Red          Green        Blue     ) Distance
	fogparms	( 0.761413 0.910937 1 ) 1700.0
}



// ///////

// HOTH Metashader

// //////

textures/jnegretetest/hoth_0
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )

    {
        map textures/hoth/snow_01
        rgbGen vertex
	  //tcmod scale .1 .1
    }


}

textures/jnegretetest/hoth_1
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )
    {
        map textures/jnegretetest/rock_huge_snow
        rgbGen vertex
        //tcmod scale .25 .25
    }
}

textures/jnegretetest/hoth_2
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )
    {
        map textures/jnegretetest/ice
        rgbGen vertex
        //tcmod scale .25 .25
    }
}

textures/jnegretetest/hoth_0to1
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )
    {
        map textures/jnegretetest/snow_01
        rgbGen vertex
        alphaGen vertex
        //tcmod scale .25 .25
    }
    {
        map textures/jnegretetest/rock_huge_snow
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
        //tcmod scale .25 .25
    }
}

textures/jnegretetest/hoth_0to2
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )
    {
        map textures/jnegretetest/snow_01
        rgbGen vertex
        alphaGen vertex
        //tcmod scale .25 .25
    }
    {
        map textures/jnegretetest/ice
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
        //tcmod scale .25 .25
    }
}

textures/jnegretetest/hoth_1to2
{
	q3map_onlyvertexlighting
      q3map_nonplanar
      q3map_shadeangle 65
      q3map_tcGen ivector ( 512 0 0 ) ( 0 512 0 )
    {
        map textures/jnegretetest/rock_huge_snow
        rgbGen vertex
        alphaGen vertex
        //tcmod scale .25 .25
    }
    {
        map textures/jnegretetest/ice
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen vertex
        alphaGen vertex
	  //tcmod scale .25 .25
    }
}

// Test sky

// q3map_sun <red> <green> <blue> <intensity> <degrees> <elevation>

// intensity falls off with angle but not distance 100 is a fairly bright sun

// degree of 0 = from the east, 90 = north, etc.  altitude of 0 = sunrise/set, 90 = noon

textures/jnegretetest/boba_night
{
	qer_editorimage	textures/skies/sky.tga
	//q3map_surfacelight	220
	//sun 0.219608 0.176471 0.635294 220 75 75
	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_novertexshadows
	skyParms	textures/skies/stars 512 -
}

textures/jnegretetest/boba_late_afternoon
{
	qer_editorimage	textures/skies/sky.tga
	//q3map_surfacelight	220
	//sun 0.219608 0.176471 0.635294 220 75 75
	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_novertexshadows
	skyParms	textures/skies/bespin 512 -
}

textures/jnegretetest/boba_afternoon
{
	qer_editorimage	textures/skies/sky.tga
	//q3map_surfacelight	220
	//sun 0.219608 0.176471 0.635294 220 75 75
	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_novertexshadows
	skyParms	textures/skies/yavin 512 -
}


textures/jnegretetest/rancor_sky
{
	qer_editorimage	textures/skies/sky.tga
	q3map_surfacelight	85
	sun 1 0.624712 0.371286 80 75 80
	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_novertexshadows
	skyParms	textures/skies/desert 512 -
}

textures/jnegretetest/hoth_sky
{
	qer_editorimage	textures/skies/sky.tga
	q3map_surfacelight	75
	sun 1 0.624712 0.371286 80 75 80
	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_novertexshadows
	skyParms	textures/skies/hoth 512 -
}

textures/yavin/dirt1
{
	q3map_normalimage textures/jnegretetest/dirt1_normal
	qer_editorimage	textures/yavin/dirt

	{
		map $lightmap
	}

	{
		map textures/yavin/dirt1
		blendFunc GL_DST_COLOR GL_ZERO
	}
}

textures/jnegretetest/symbol
{
	q3map_normalimage textures/jnegretetest/symbol_norm
	qer_editorimage	textures/jnegretetest/symbol

	{
	    map $lightmap
	    rgbGen identity
	}

	{
          map textures/jnegretetest/symbol
    	    rgbGen identity
	    blendFunc GL_DST_COLOR GL_ZERO
	}
}

textures/jnegretetest/bumpmap
{
	q3map_normalimage textures/jnegretetest/bumpmap_normalmap
	qer_editorimage	textures/jnegretetest/bumpmap_original

	{
	    map $lightmap
	    rgbGen identity
	}

	{
          map textures/jnegretetest/bumpmap_original
    	    rgbGen identity
	    blendFunc GL_DST_COLOR GL_ZERO
	}
}

textures/jnegretetest/rock_huge_snow
{
	q3map_nolightmap
    {
        map textures/jnegretetest/rock_huge_snow
        rgbGen exactVertex
    }
}


textures/jnegretetest/ice
{
	q3map_nolightmap
    {
        map textures/jnegretetest/ice
        rgbGen exactVertex
    }
}

textures/jnegretetest/snow_02
{
	q3map_nolightmap
    {
        map textures/jnegretetest/snow_02
        rgbGen exactVertex
    }
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------
// q3map 2 fur demo shader
// this is expensive, so use it sparingly :)
// note, this can be used with terrain shaders to have a layer with grass...
//
// ydnar@shaderlab.com
// ------------------------------------------------------------------------------


// ------------------------------------------------------------------------------
// sky shader for demo
// ------------------------------------------------------------------------------

textures/jnegretetest/sky
{
	q3map_surfacelight 100
	q3map_sun 1 .85 0.5 65 -30 60

	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	{
		map textures/jnegretetest/sky.tga
	}
}



// ------------------------------------------------------------------------------
// base texture
// ------------------------------------------------------------------------------

textures/jnegretetest/pink_base
{
	q3map_cloneshader textures/jnegretetest/pink_fur

	{
		map $lightmap
	}
	{
		map textures/jnegretetest/pink_base.tga
		blendFunc GL_DST_COLOR GL_ZERO
	}
}



// ------------------------------------------------------------------------------
// fur texture
// ------------------------------------------------------------------------------

textures/jnegretetest/pink_fur
{
	q3map_lightimage textures/jnegretetest/pink_fur.q3map.tga

	q3map_notjunc
	q3map_nonplanar
	q3map_bounce 0.0
	q3map_shadeangle 120

	// format: q3map_fur <layers> <offset> <fade>
	q3map_fur 8 1.25 0.1

	surfaceparm trans
	surfaceparm pointlight
	surfaceparm alphashadow
	surfaceparm nonsolid
	surfaceparm noimpact

	// cull none
	nomipmaps

	{
		map textures/jnegretetest/pink_fur.tga
		//alphaFunc GE128
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}
}

