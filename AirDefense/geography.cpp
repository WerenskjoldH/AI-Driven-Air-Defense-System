#include "Geography.h"

Geography::Geography(int sizeX, int sizeY, float frequency, float zoom, float amplitude, float waterLevel, int seed) : worldSizeX{ sizeX }, worldSizeY{ sizeY }, frequency{ frequency }, zoom{ zoom }, amplitude{ amplitude }, waterLevel{ waterLevel }, seed{ seed }
{
	if (!sf::Shader::isAvailable())
	{
		WRITE_CONSOLE_ERROR("SHADER", "System does not have support for shaders");
	}

	if (!geographyShader.loadFromFile("Shaders/geography.vert", "Shaders/geography.frag"))
	{
		WRITE_CONSOLE_ERROR("SHADER", "Unable to load geography shader code");
	}

	regenerate();

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

Geography::~Geography()
{
}

void Geography::regenerate(int seed)
{
	this->seed = seed;

	mapImage.create(worldSizeX, worldSizeY);

	mapTexture.create(worldSizeX, worldSizeY);

	generateLand();
}

float Geography::getAltitude(float x, float y)
{
	if (x >= worldSizeX || y >= worldSizeY || x <= 0 || y <= 0)
		return 0.f;

	return mapImage.getPixel(x, y).r/255.f;
}

bool Geography::checkIfLand(int x, int y)
{
	if (x >= worldSizeX || y >=  worldSizeY || x <= 0 || y <= 0)
		return false;

	if (mapImage.getPixel(x, y).r >= waterLevel * 255.f)
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

void Geography::setFrequency(float f)
{
	frequency = f;
}

void Geography::setZoom(float z)
{
	zoom = z;
}

void Geography::setAmplitude(float a)
{
	amplitude = a;
}

void Geography::setWaterLevel(float w)
{
	waterLevel = (w <= 1 && w >= 0) ? w : waterLevel;
}

int Geography::getWidth()
{
	return worldSizeX;
}

int Geography::getHeight()
{
	return worldSizeY;
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
			float n2 = getPerlinNoise(2.0f * noiseX * frequency / zoom + seed, 2.0 * noiseY * frequency / zoom + seed);
			float n3 = getPerlinNoise(4.0f * noiseX * frequency / zoom + seed, 4.0 * noiseY * frequency / zoom + seed);

			float elevation = n1 + 0.5 * n2 + 0.25f * n3; 

			float v = 0;

			if(ISLAND_COUNTRY)
				v -= 1.7f * (std::sqrt(std::pow(0.5f - noiseX, 2.f) + std::pow(0.5f - noiseY, 2.f)));

			v += std::min((elevation + 1.0f) / 2.0f, 1.0f);
			float e = std::pow(v, 0.74);

			e = std::min(v, 1.0f);
			e = std::max(v, 0.f);

			color = 255 * e;

			mapImage.setPixel(ctrX, ctrY, sf::Color(color, color, color, 255));
		}

	mapTexture.update(mapImage);
	mapSprite.setTexture(mapTexture);

	// Update the geography shader
	geographyShader.setUniform("waterLevel", waterLevel);
}
