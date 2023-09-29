models/cosmetics/hats/cap
{
q3map_nolightmap
cull	twosided
{
map models/cosmetics/hats/cap
rgbGen lightingDiffuse
}
}

models/cosmetics/hats/cringe
{
q3map_nolightmap
cull	twosided
{
map models/cosmetics/hats/cringe
rgbGen lightingDiffuse
}
}

models/cosmetics/hats/cringe_prop
{
q3map_nolightmap
cull	twosided
{
map models/cosmetics/hats/cringe_prop
alphaFunc GE128
rgbGen vertex
tcMod rotate 1000
}
}

models/cosmetics/hats/pumpkin
{
q3map_nolightmap
{
map models/cosmetics/hats/pumpkin
rgbGen lightingDiffuse
}
{
map models/cosmetics/hats/pumpkin_glow
blendFunc GL_ONE GL_ONE
rgbGen wave square 0 1 0 0
glow
}
}

models/cosmetics/hats/mask
{
q3map_nolightmap
cull	twosided
{
map models/cosmetics/hats/mask
rgbGen lightingDiffuse
}
}

models/cosmetics/hats/supersaiyan // supersaiyan
{
	q3map_nolightmap
	q3map_onlyvertexlighting
    {
        map models/cosmetics/hats/supersaiyan // supersaiyan
        rgbGen lightingDiffuse
    }
    {
        map models/cosmetics/hats/supersaiyanfx2 // do not use
        blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE
        rgbGen wave sin 0 1 0 0.75
        tcMod scroll 0 3
    }
    {
        map models/cosmetics/hats/supersaiyanfx // supersaiyanfx
        blendFunc GL_DST_COLOR GL_ONE
        tcGen environment
        tcMod scroll 0.5 0.5
    }
}