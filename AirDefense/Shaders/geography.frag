#define sand vec3(0.8764, 0.9, 0.5)
#define grass vec3(0.3117, 0.6764, 0.1196)
#define rock vec3(0.8294, 0.6764, 0.1196)
#define snow vec3(0.9764, 0.9764, 0.9764)

uniform sampler2D mapTexture;
uniform float waterLevel;

vec3 colorLand(float altitude)
{
    if(altitude < 0.4 + (waterLevel*0.1))
    {
        return sand;
    }
    else if(altitude < 0.8)
    {
        return grass;
    }
    else if(altitude < 0.9)
    {
        return rock;
    }
    else
    {
        return snow;
    }
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

    if(pixel.r > waterLevel)
        color = colorLand(pixel.r);
    else if(pixel.r <= waterLevel)
        color = colorWater(pixel.r);

    gl_FragColor = gl_Color * vec4(color.rgb, 1.0);
}