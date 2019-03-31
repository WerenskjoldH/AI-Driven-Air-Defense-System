#include "Geography.h"

void Geography::regenerate(int seed = 9996)
{
	this->seed = seed;

	mapImage.create(worldSizeX, worldSizeY);

	mapTexture.create(worldSizeX, worldSizeY);

	generateLand();
}

float Geography::getAltitude(float x, float y)
{
	float noiseX = (float)x / (float)worldSizeX;
	float noiseY = (float)y / (float)worldSizeY;
	return amplitude * getPerlinNoise(noiseX * frequency / zoom + seed, noiseY * frequency / zoom + seed) + 1.0 / 2.0f;
}

bool Geography::checkIfLand(int x, int y)
{
	if (mapImage.getPixel(x, y).r >= waterLevel * 255)
		return true;
	
	return false;
}

void Geography::drawLand(sf::RenderWindow * window)
{
	sf::RenderStates states;
	states.texture = &mapTexture;
	states.shader = &geographyShader;

	// This is not necessarily how I would like to do this since it does not support multiple textures
	// But, this does allow us to easily take advantage of both SFML's native drawing abilities and drawing with shaders
	window->draw(*quad, states);
}

void Geography::generateLand()
{
	int color;

	int ctrX, ctrY;
	for (ctrX = 0; ctrX < worldSizeX; ctrX++)
		for (ctrY = 0; ctrY < worldSizeY; ctrY++)
		{
			float noiseX = (float)ctrX / (float)worldSizeX;
			float noiseY = (float)ctrY / (float)worldSizeY;

			float n1 = getPerlinNoise(noiseX * frequency / zoom + seed, noiseY * frequency / zoom + seed);
			float n2 = getPerlinNoise(2.0 * noiseX * frequency / zoom + seed, 2.0 * noiseY * frequency / zoom + seed);
			float n3 = getPerlinNoise(4.0 * noiseX * frequency / zoom + seed, 4.0 * noiseY * frequency / zoom + seed);

			float elevation = n1 + 0.5 * n2 + 0.25 * n3; 

			float v = std::min((elevation + 1.0) / 2.0, 1.0);
			float e = std::pow(v, 0.74);


			color = 255 * e;

			mapImage.setPixel(ctrX, ctrY, sf::Color(color, color, color, 255));
		}

	mapTexture.update(mapImage);
	mapSprite.setTexture(mapTexture);

	// Update the geography shader
	geographyShader.setUniform("waterLevel", waterLevel);
}
