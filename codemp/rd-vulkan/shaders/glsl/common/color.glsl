#ifndef SHADER_COLOR_GLSL
#define SHADER_COLOR_GLSL

#if defined(SHADER_FRAG) && defined(USE_VBO_MODEL)
	bool needsShading( in int rgbType ) {
		return ( rgbType >= 9 && rgbType != 11 && rgbType != 12 && rgbType != 13 ) ? true : false;
	}

	float CalcLightAttenuation(float point, float normDist)
	{
		// zero light at 1.0, approximating q3 style
		// also don't attenuate directional light
		float attenuation = ( 0.5 * normDist - 1.5 ) * point + 1.0;
		return clamp( attenuation, 0.0, 1.0 );
	}
#endif

#if defined(SHADER_VERT) && defined(USE_VBO_MODEL)
	vec4 CalcColor( int index, in vec3 position, in vec3 normal ) {
		vec4 color = ( u_global.bundle[index].vertColor * vec4( 0.0 ) ) + u_global.bundle[index].baseColor;		// skip vertColor?

		switch ( u_global.bundle[index].rgbGen ) {
			case 14:// CGEN_DISINTEGRATION_1
			{
				vec3 delta = u_global.disintegration.origin - position;
				float sqrDistance = dot( delta, delta );

				if ( sqrDistance < u_global.disintegration.threshold )
					color *= 0.0;
				else if ( sqrDistance < u_global.disintegration.threshold + 60.0 )
					color *= vec4( 0.0, 0.0, 0.0, 1.0 );
				else if ( sqrDistance < u_global.disintegration.threshold + 150.0 )
					color *= vec4( 0.435295, 0.435295, 0.435295, 1.0 );
				else if ( sqrDistance < u_global.disintegration.threshold + 180.0 )
					color *= vec4( 0.6862745, 0.6862745, 0.6862745, 1.0 );

				return color;
			}
			case 15:// CGEN_DISINTEGRATION_2
			{
				vec3 delta = u_global.disintegration.origin - position;
				float sqrDistance = dot( delta, delta );

				if ( sqrDistance < u_global.disintegration.threshold )
					return vec4(0.0);

				return color;
			}
		}

		switch ( u_global.bundle[index].alphaGen ) {
			case 6: // AGEN_LIGHTING_SPECULAR
			{
				vec3 viewer = normalize( u_entity.localViewOrigin.xyz - position );
				vec3 lightDirection = ( transpose(u_entity.modelMatrix) * vec4( u_entity.localLightOrigin.xyz, 0.0 ) ).xyz;
				vec3 reflected = -reflect( lightDirection, normal );
				color.a = clamp( dot( reflected, normalize( viewer ) ), 0.0, 1.0 );
				color.a *= color.a;
				color.a *= color.a;
				break;
			}
			case 8: // AGEN_PORTAL
			{
				vec3 viewer = normalize( u_entity.localViewOrigin.xyz - position );
				color.a = clamp( length( viewer ) / u_global.portalRange, 0.0, 1.0 );
				break;
			}
		}

		return color;
	}
#endif

#endif