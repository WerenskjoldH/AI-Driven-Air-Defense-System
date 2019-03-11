#ifndef NOISE_GENERATOR_H
#define NOISE_GENERATOR_H

#define GET_ARRAY_POSITION(x, y, w) (y * w) + x

#include <SFML/Graphics.hpp>

static float getNoise(float nX, float nY)
{
	int n = (int)nX + (int)nY * 57;
	n = (n << 13) ^ n;
	int nn = (n*(n*n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
	return 1.0 - ((double)nn / 1073741824.0);
}

static void setHeightfield(sf::Image* image, int x, int y, int seed = 9996)
{
	sf::Uint8* map = new sf::Uint8[4*(y*x)];

	int ctrX, ctrY;
	for(ctrX = 0; ctrX < x; ctrX++)
		for (ctrY = 0; ctrY < y; ctrY++)
		{
			float noiseX = (float)ctrX / (float)x, noiseY = (float)ctrY / (float)y;

			float v = (getNoise(20* noiseX -0.5, 20* noiseY -0.5) + 1.0) / 2.0f;
			int color;

			if (v > 0.5)
				color = 255;
			else
				color = 0;

			image->setPixel(ctrX, ctrY, sf::Color(color, color, color, 255));
		}

	printf("We made it to the end of the height field!\n");

	delete[] map;
}


#endif