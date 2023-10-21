// ---------------------------------------------
// Hector's Threewave JEDI Apprentice Shaders
// ---------------------------------------------
//
// q3map_sun <red> <green> <blue> <intensity> <degrees> <elevation>
// degree of 0 = from the east
// degree of 90 = north
// altitude of 0 = sunrise/set, 90 = noon

textures/mp/h_tatsky
{
	qer_editorimage textures/skies/desert_up.tga
	q3map_lightimage textures/mp/s_flatyellow.tga

	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_lightsubdivide	2048
	q3map_surfacelight 	145
	sun 0.874291 1.000000 0.819403 175 25 70
	//sun 0.874291 1.000000 0.819403 175 -85 82
	//sunPos -85 82
	skyParms 	textures/skies/desert 512 -
}

textures/mp/h_tatsky2
{
	qer_editorimage textures/skies/desert_up.tga
	q3map_lightimage textures/mp/s_flatyellow.tga

	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_lightsubdivide	2048
	q3map_surfacelight 	125
	sun 0.874291 1.000000 0.819403 115 25 80
	skyParms 	textures/skies/desert 512 -
}


textures/mp/h_sandstone
{
//	q3map_shadeangle	90
	qer_editorimage	textures/quicktrip/rock_sandstone.tga
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/quicktrip/rock_sandstone.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/mp/h_yavin
{
	qer_editorimage	textures/skies/sky.tga
	q3map_lightimage 	textures/skies/desert_up.tga

	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	q3map_surfacelight 	145
	q3map_lightsubdivide	1024
	sun 1.000000 0.540000 0.629266 180 120 40
	skyParms	textures/skies/yavin 512 -
}

textures/mp/h_black_100
{
	qer_editorimage	textures/mp/h_black.tga
	q3map_lightimage textures/colors/gray.tga
	surfaceparm	nomarks
	q3map_surfacelight 	80
	q3map_lightsubdivide	1024
	q3map_nolightmap
	{
	  map $whiteimage
        rgbGen const ( 0.000000 0.000000 0.000000 )
	}
}

textures/mp/h_fog_black
{
	qer_editorimage	textures/fogs/fog.tga
	qer_nocarve
	surfaceparm nonsolid
	surfaceparm nonopaque
	surfaceparm fog
	surfaceparm trans
	q3map_nolightmap
	fogparms ( 0 0 0 ) 5000.0
	cull twosided
}

// im changing this - scan
textures/mp/h_hevil
{

//	q3map_lightimage	textures/colors/white
	q3map_lightimage	textures/skies/hevil_up

	qer_editorimage	textures/skies/sky.tga
	q3map_surfacelight	200
	q3map_lightsubdivide	2048
//	sun 1 1 1 160 300 50
	sun 0.62149 0.86476 1.000000 230 300 76

	surfaceparm	sky
	surfaceparm	noimpact
	surfaceparm	nomarks
	notc
	q3map_nolightmap
	skyParms	textures/skies/hevil 128 -
      
   }

textures/mp/h_bomb
{
	qer_editorimage	textures/factory/ggoo2
	q3map_nolightmap
    {
        map textures/factory/ggoo2
        rgbGen identity
        tcMod scroll 0.3 0
    }
    {
        map textures/factory/ggoo3
        blendFunc GL_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen identity
        tcMod scroll 0.1 0
    }
}