
uniform sampler2D mapTexture;
uniform float waterLevel;

vec3 colorLand(float altitude)
{
    return vec3(0.2, 0.5, 0.3);
}

vec3 colorWater(float altitude)
{
    return vec3(0.0, 0.0, 0.7);
}

void main()
{
    vec4 pixel = texture2D(mapTexture, gl_TexCoord[0].xy);
    
    // By default make it as red as possible to signal an error ( consider this an assertion, it should NEVER happen )
    vec3 color = vec3(1.0, 0.0, 0.0);

    if(pixel.r >= waterLevel)
        color = colorLand(pixel.r);
    else if(pixel.r < waterLevel)
        color = colorWater(pixel.r);

    gl_FragColor = gl_Color * vec4(color.rgb, 1.0);
}