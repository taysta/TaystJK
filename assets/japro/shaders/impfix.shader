//Shader fix by TnG, adapted to Eternaljk by Art

models/map_objects/imperial/airpure
{
	{
		map $lightmap
		rgbGen identity
	}
	{
		map models/map_objects/imperial/airpure
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map models/map_objects/imperial/airpure_glw
		blendFunc GL_ONE GL_ONE
		glow
		rgbGen identity
	}
}
