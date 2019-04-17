#ifndef NOISE_GENERATOR_H
#define NOISE_GENERATOR_H

#define PI 3.141592653589

inline static float cosineInterpolation(float a, float b, float x)
{
	float ft = x * PI;
	float f = (1 - std::cos(ft)) * 0.5f;
	return (a * (1 - f) + b * f);
}

// This is a commonly used function to generate a noise field
// It uses prime numbers as non-prime numbers create distict patterns
inline static float getNoise(float nX, float nY)
{
	int n = (int)nX + (int)nY * 57;
	n = (n * 2^13) ^ n;
	int nn = std::abs((n*(n*n * 60493 + 19990303) + 1376312589));
	return 1.0 - ((double)nn / 1073741824.f);
}

inline static float getPerlinNoise(float nX, float nY)
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

#endif