#include "Geography.h"

void Geography::regenerate(int seed = 9996)
{
	this->seed = seed;

	mapImage.create(worldSizeX, worldSizeY);

	mapTexture.create(worldSizeX, worldSizeY);

	generateLand();

	mapTexture.update(mapImage);
	mapSprite.setTexture(mapTexture);
}

float Geography::getAltitude(float x, float y)
{
	float noiseX = (float)x / (float)worldSizeX;
	float noiseY = (float)y / (float)worldSizeY;
	return amplitude * getPerlinNoise(noiseX * frequency / zoom + seed, noiseY * frequency / zoom + seed) + 1.0 / 2.0f;
}

bool Geography::checkIfLand(int x, int y)
{
	if (mapImage.getPixel(x, y).r == 255)
		return true;
	return false;
}

void Geography::drawLand(sf::RenderWindow * window)
{
	window->draw(mapSprite);
}

void Geography::generateLand()
{
	int ctrX, ctrY;
	for (ctrX = 0; ctrX < worldSizeX; ctrX++)
		for (ctrY = 0; ctrY < worldSizeY; ctrY++)
		{
			float noiseX = (float)ctrX / (float)worldSizeX;
			float noiseY = (float)ctrY / (float)worldSizeY;

			float v = (getPerlinNoise(noiseX * frequency + seed, noiseY * frequency + seed) + 1.0) / 2.0f;
			float e = std::pow(v, 1.78);
			int color;

			if (e > 0.5f)
				color = 255;
			else
				color = 0;

			mapImage.setPixel(ctrX, ctrY, sf::Color(color, color, color, 255));
		}
}
