#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#define ISLAND_COUNTRY true

#include <SFML/Graphics.hpp>

#include "noiseGenerator.h"
#include "consoleColorer.h"

class Geography
{
public:
	Geography(int sizeX, int sizeY, float frequency = 2 ^ 4, float zoom = 1.0, float amplitude = 1.0, float waterLevel = 0.5, int seed = 9996) : worldSizeX{ sizeX }, worldSizeY{ sizeY }, frequency{ frequency }, zoom{ zoom }, amplitude{ amplitude }, waterLevel{ waterLevel }, seed{ seed }
	{
		mapImage.create(sizeX, sizeY);

		mapTexture.create(sizeX, sizeY);

		if (!sf::Shader::isAvailable())
		{
			WRITE_CONSOLE_ERROR("SHADER", "System does not have support for shaders");
		}

		if (!geographyShader.loadFromFile("Shaders/geography.vert", "Shaders/geography.frag"))
		{
			WRITE_CONSOLE_ERROR("SHADER", "Unable to load geography shader code");
		}

		generateLand();

		mapTexture.update(mapImage);
		mapSprite.setTexture(mapTexture);

		quad = new sf::VertexArray(sf::Quads, 4);

		(*quad)[0].position = sf::Vector2f(0.f, 0.f);
		(*quad)[1].position = sf::Vector2f(sizeX, 0.f);
		(*quad)[2].position = sf::Vector2f(sizeX, sizeY);
		(*quad)[3].position = sf::Vector2f(0.f, sizeY);

		(*quad)[0].texCoords = sf::Vector2f(0.f, 0.f);
		(*quad)[1].texCoords = sf::Vector2f(sizeX, 0.f);
		(*quad)[2].texCoords = sf::Vector2f(sizeX, sizeY);
		(*quad)[3].texCoords = sf::Vector2f(0.f, sizeY);
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
	void setWaterLevel(float w) { waterLevel = (w <= 1 && w >= 0) ? w : waterLevel; }

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