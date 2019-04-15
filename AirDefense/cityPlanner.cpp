#include "cityPlanner.h"
#include "worldObjectFactory.h"
#include "world.h"
#include "geography.h"

void swapCities(city * a, city * b)
{
	city temp = *a;

	*a = *b;
	*b = temp;
}

int scoreCity(city & c)
{
	return 0;
}

void placeCities(World * world, Geography * geography, int numberToSelect, int numberToTest)
{
	city* cities = (city*)malloc(numberToSelect * sizeof(city));

	float halfGeoWidth = geography->getWidth() / 2.f;
	float halfGeoHeight = geography->getHeight() / 2.f;

	for (int i = 0; i < numberToSelect; i++)
	{
		//srand(std::time(0));

		// Sample a point ( both positive and negative ) based around the center of the map
		float xO = 2.f * (halfGeoWidth) - halfGeoWidth;
		float yO = 2.f * (halfGeoHeight) - halfGeoHeight;
		float r = (2.f*(float(rand())) / float(RAND_MAX)) - 1.f;
		xO *= r;
		r = (2.f*(float(rand())) / float(RAND_MAX)) - 1.f;
		yO *= r;

		cities[i].x = halfGeoWidth + xO;
		cities[i].y = halfGeoHeight + yO;



		// Check if valid position, if not decrement i and continue

		if (!geography->checkIfLand(cities[i].x, cities[i].y))
		{
			i--;
			continue;
		}

		// Population - We use multiple octaves to try to weight population to the upper boundary

		r = (float(rand())) / float(RAND_MAX);

		float p = POPULATION_MIN + (POPULATION_MAX - POPULATION_MIN) * r;
		//r = (float(rand())) / float(RAND_MAX);
		//p += p + (POPULATION_MAX - p) * r;
		//r = (float(rand())) / float(RAND_MAX);
		//p += p + (POPULATION_MAX - p) * r;

		cities[i].pop = p;

		// Weight city - Todo

		// Check top cities and see if weight is greater than any of them, if so swap

		// Create and place city objects

		//for (int i = 0; i < numberToSelect; i++)
		//{
		world->addObject(createCityObject(cities[i].x, cities[i].y, cities[i].pop));
		//}
	}
	// free memory of array of structs
	delete[] cities;
}