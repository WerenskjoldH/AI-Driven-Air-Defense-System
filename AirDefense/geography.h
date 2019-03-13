#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <SFML/Graphics.hpp>

#include "noiseGenerator.h"

class Geography
{
public:
	Geography(int sizeX, int sizeY, float frequency = 2 ^ 4, float zoom = 1.0, float amplitude = 1.0, float waterLevel = 0.5, int seed = 9996) : worldSizeX{ sizeX }, worldSizeY{ sizeY }, frequency{ frequency }, zoom{ zoom }, amplitude{ amplitude }, waterLevel{ waterLevel }, seed{ seed }
	{
		mapImage.create(sizeX, sizeY);

		mapTexture.create(sizeX, sizeY);

		generateLand();

		mapTexture.update(mapImage);
		mapSprite.setTexture(mapTexture);
	}

	~Geography()
	{
	}

	void regenerate(int seed);
	
	// (Slow)
	// This does a full calculation at the given point
	float getAltitude(float x, float y);

	// (Fast)
	// This evaluates with the image
	bool checkIfLand(int x, int y);

	void drawLand(sf::RenderWindow* window);

	void setFrequency(float f) { frequency = f; }
	void setZoom(float z) { zoom = z; }
	void setAmplitude(float a) { amplitude = a; }

	// Value must be in interval [0,1]
	void setWaterLevel(float w) { waterLevel = (w <= 1 && w >= 0) ? w : waterLevel;  }

private:
	sf::Image mapImage;
	sf::Sprite mapSprite;
	sf::Texture mapTexture;
	int worldSizeX, worldSizeY;
	float frequency;
	float zoom;
	float amplitude;
	float waterLevel;
	int seed;

	void generateLand();

};

#endif