#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#define ISLAND_COUNTRY true

#include <SFML/Graphics.hpp>

#include "noiseGenerator.h"
#include "consoleColorer.h"

class Geography
{
public:
	Geography(int sizeX, int sizeY, float frequency = 2 ^ 4, float zoom = 1.0, float amplitude = 1.0, float waterLevel = 0.5, int seed = 9996);

	~Geography();

	void regenerate(int seed = 9996);
	
	// (Slow)
	// This does a full calculation at the given point
	float getAltitude(float x, float y);

	// (Fast)
	// This evaluates with the image
	bool checkIfLand(int x, int y);

	void drawLand(sf::RenderWindow* window);

	void setFrequency(float f);
	void setZoom(float z);
	void setAmplitude(float a);
	// Value must be in interval [0,1]
	void setWaterLevel(float w);

	int getWidth();
	int getHeight();

private:
	sf::Image mapImage;
	sf::Sprite mapSprite;
	sf::Texture mapTexture;
	sf::Shader geographyShader;

	sf::VertexArray *quad;

	int worldSizeX, worldSizeY;
	float frequency;
	float zoom;
	float amplitude;
	float waterLevel;
	int seed;

	void generateLand();

};

#endif