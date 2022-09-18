models/players/hats/cap
{
q3map_nolightmap
cull	twosided
{
map models/players/hats/cap
rgbGen lightingDiffuse
}
}

models/players/hats/cringe
{
q3map_nolightmap
cull	twosided
{
map models/players/hats/cringe
rgbGen lightingDiffuse
}
}

models/players/hats/cringe_prop
{
q3map_nolightmap
cull	twosided
{
map models/players/hats/cringe_prop
alphaFunc GE128
rgbGen vertex
tcMod rotate 1000
}
}

models/players/hats/pumpkin
{
q3map_nolightmap
{
map models/players/hats/pumpkin
rgbGen lightingDiffuse
}
{
map models/players/hats/pumpkin_glow
blendFunc GL_ONE GL_ONE
rgbGen wave square 0 1 0 0
glow
}
}

models/players/hats/mask
{
q3map_nolightmap
cull	twosided
{
map models/players/hats/mask
rgbGen lightingDiffuse
}
}

models/players/hats/hair_yoda
{
	cull	twosided
    {
        map models/players/hats/hair_yoda
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen lightingDiffuse
    }
}

models/players/hats/head_yoda
{
	nopicmip
	nomipmaps
    {
        map models/players/hats/head_yoda
        rgbGen lightingDiffuse
        //alphaFunc GE128
    }
}

models/players/hats/hands_yoda
{
	nopicmip
	nomipmaps
    {
        map models/players/hats/hands_yoda
        rgbGen lightingDiffuse
        //alphaFunc GE128
    }
}

models/players/hats/supersaiyan // supersaiyan
{
	q3map_nolightmap
	q3map_onlyvertexlighting
    {
        map models/players/hats/supersaiyan // supersaiyan
        rgbGen lightingDiffuse
    }
    {
        map models/players/hats/supersaiyanfx2 // do not use
        blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE
        rgbGen wave sin 0 1 0 0.75
        tcMod scroll 0 3
    }
    {
        map models/players/hats/supersaiyanfx // supersaiyanfx
        blendFunc GL_DST_COLOR GL_ONE
        tcGen environment
        tcMod scroll 0.5 0.5
    }
}