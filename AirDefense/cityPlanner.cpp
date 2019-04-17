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

float scoreCity(city* cities, World* world, int numberOfCities, int observedCity)
{
	// Total score should equal out to 3.f
	float score = 0;

	// Score distance from others and connection - This could be cleaned up
	for (int i = 0; i < numberOfCities; i++)
	{
		float dist = DISTANCE(cities[observedCity].x, cities[observedCity].y, cities[i].x, cities[i].y);
		score += (dist >= PREFERRED_CITY_DISTANCE) ? (1.f / float(numberOfCities)) : (0.f);
		
		int step = 0;
		sf::Vector2f origin(cities[observedCity].x, cities[observedCity].y);
		sf::Vector2f direction(cities[i].x - origin.x, cities[i].y - origin.y);
		direction /= dist;

		float distanceCovered = 0;
		while (distanceCovered <= dist)
		{
			distanceCovered = (DISTANCE_STEP_SIZE * step);

			if (world->checkIfLandAtLocation(origin.x + direction.x * distanceCovered, origin.y + direction.y * distanceCovered) == 0)
				break;
			
			step++;
		}

		// Cities are connected by land
		if (distanceCovered >= dist)
			score += (1.f / float(numberOfCities));
		else
			score -= (1.f / float(numberOfCities));
	}

	// Score near water only check above, below, left, and right to speed things up
	if (world->checkIfLandAtLocation(cities[observedCity].x + 2.f * DISTANCE_STEP_SIZE, cities[observedCity].y) || world->checkIfLandAtLocation(cities[observedCity].x - 2.f * DISTANCE_STEP_SIZE, cities[observedCity].y)
		|| world->checkIfLandAtLocation(cities[observedCity].x, cities[observedCity].y + 2.f * DISTANCE_STEP_SIZE) || world->checkIfLandAtLocation(cities[observedCity].x, cities[observedCity].y - 2.f * DISTANCE_STEP_SIZE))
	{
		score += 1.f;
	}

	return score;
}

void placeCities(World * world, Geography * geography, int numberToSelect, int numberToTest)
{
	// Call it a bad habit of writing so many c programs
	city* cities = (city*)malloc(numberToTest * sizeof(city));

	float halfGeoWidth = geography->getWidth() / 2.f;
	float halfGeoHeight = geography->getHeight() / 2.f;

	for (int i = 0; i < numberToTest; i++)
	{
		// Sample a point ( both positive and negative ) based around the center of the map
		float xO = halfGeoWidth;
		float yO = halfGeoHeight;
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

		cities[i].pop = p;
	}

	// Weight cities - This can be hefty calculation 
	for (int i = 0; i < numberToTest; i++)
	{
		cities[i].weight = scoreCity(cities, world, numberToTest, i);
		
		// Check top cities and see if weight is greater than any of them, if so swap
		for (int j = 0; j < numberToSelect; j++)
		{
			if (cities[i].weight > cities[j].weight)
				swapCities(&cities[i], &cities[j]);
		}
	}



	// Create and place city objects

	for (int i = 0; i < numberToSelect; i++)
	{
		world->addObject(createCityObject(cities[i].x, cities[i].y, cities[i].pop));
	}

	// free memory of array of structs
	delete[] cities;
}