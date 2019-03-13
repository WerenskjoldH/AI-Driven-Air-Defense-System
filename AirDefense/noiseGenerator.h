#ifndef NOISE_GENERATOR_H
#define NOISE_GENERATOR_H

#define GET_ARRAY_POSITION(x, y, w) (y * w) + x

#define PI 3.141592653589

#include <SFML/Graphics.hpp>

static float cosineInterpolation(float a, float b, float x)
{
	float ft = x * PI;
	float f = (1 - std::cos(ft)) * 0.5f;
	return (a * (1 - f) + b * f);
}

// This is a commonly used function to generate a noise field, don't question it too much. Has to do with prime numbers or something like that
static float getNoise(float nX, float nY)
{
	int n = (int)nX + (int)nY * 57;
	n = (n << 13) ^ n;
	int nn = (n*(n*n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
	return 1.0 - ((double)nn / 1073741824.f);
}

static float getPerlinNoise(float nX, float nY)
{
	float fX = std::floor(nX);
	float fY = std::floor(nY);

	float s = getNoise(fX, fY);
	float t = getNoise(fX + 1, fY);
	float u = getNoise(fX, fY + 1);
	float v = getNoise(fX + 1, fY + 1);

	float lerp1 = cosineInterpolation(s, t, nX - fX);
	float lerp2 = cosineInterpolation(u, v, nX - fX);

	return cosineInterpolation(lerp1, lerp2, nY - fY);
}

static void setHeightfield(sf::Image* image, int x, int y, int seed = 9996)
{
	sf::Uint8* map = new sf::Uint8[4 * (y*x)];

	int ctrX, ctrY;
	for (ctrX = 0; ctrX < x; ctrX++)
		for (ctrY = 0; ctrY < y; ctrY++)
		{
			float noiseX = (float)ctrX / (float)x, noiseY = (float)ctrY / (float)y;

			float v = (getPerlinNoise(noiseX * (2^4) + seed, noiseY * (2^4) + seed) + 1.0) / 2.0f;
			float e = std::pow(v, 1.78);
			int color;

			if (e > 0.5f)
				color = 255;
			else
				color = 0;

			image->setPixel(ctrX, ctrY, sf::Color(color, color, color, 255));
		}

	printf("We made it to the end of the height field!\n");

	delete[] map;
}


#endif