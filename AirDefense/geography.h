#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#define ISLAND_COUNTRY true

#include <SFML/Graphics.hpp>

#include "noiseGenerator.h"
#include "consoleColorer.h"

class Geography
{
public:

	/*
		@param sizeX Pixel width of the area we are creating geography for, this should equal the window size width
		@param sizeY Pixel height of the area we are creating geography for, this should equal the window size height
		@param frequency The noise frequency to use
		@param zoom The noise zoom level to use
		@param amplitude The amplitude of the noise to use, this is best left at 1
		@param waterLevel Any values under this are concidered under water level
		@param seed The noise seed to use, providing limitless variations of the same noise inputs while still allowing reproduction
	*/
	Geography(int sizeX, int sizeY, float frequency = 2 ^ 4, float zoom = 1.0, float amplitude = 1.0, float waterLevel = 0.5, int seed = 9996);

	~Geography();

	void regenerate(int seed = 9996);
	
	/* 
		This gets the pixel color and returns a [0, 1] value for the altitude.
		Since this uses pixel color, it is not as accurate as re-evaluating the position via the noise function
		@param x window position
		@param y window position
		@return Gets a float for the altitude of the land between 0 and 1
	*/
	float getAltitude(float x, float y);

	
	/* 
		This evaluates with the image to determine if the point is land or water
		@param x window position
		@param y window position
		@return Gets a boolean value: land = true, water = false
	*/
	bool checkIfLand(int x, int y);

	/*
		This draws the land to the given RenderWindow
		@param window Pointer to desired RenderWindow to draw to
	*/
	void drawLand(sf::RenderWindow* window);

	/*
		Set the frequency of the noise function manually
		@param f frequency
	*/
	void setFrequency(float f);

	/*
		Set the zoom of the noise function manually
		@param z zoom
	*/
	void setZoom(float z);

	/*
		Set the amplitude of the noise function manually
		@param a amplitude
	*/
	void setAmplitude(float a);

	/* 
		Value must be in interval [0,1]
		@param w Water level [0, 1]
	*/
	void setWaterLevel(float w);

	// Gets 2D width of geography
	int getWidth();

	// Gets 2D height of geography
	int getHeight();

private:
	sf::Image mapImage;
	sf::Sprite mapSprite;
	sf::Texture mapTexture;
	sf::Shader geographyShader;

	// Quads used to draw 2D mesh we will render to
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