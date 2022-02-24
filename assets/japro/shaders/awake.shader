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

gfx/misc/splash
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
