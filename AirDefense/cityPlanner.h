#ifndef CITY_PLANNER_H
#define CITY_PLANNER_H

// In pixels
#define PREFERRED_CITY_DISTANCE 100.f
#define DISTANCE_STEP_SIZE 10.f

#define NUMBER_TO_SELECT_DEFAULT 6
#define NUMBER_TO_TEST_DEFAULT 20

#define DISTANCE(x, y, x0, y0) sqrt(powf(x0 - x, 2) + powf(y0 - y, 2))

class World;
class Geography;

// This way we don't have to generate 2*n city objects and waste space
struct city {
	float x;
	float y;
	int pop;
	float weight = 0;
	float radius;
};

void swapCities(city* a, city* b);

float scoreCity(city* cities, World* world, int numberOfCities, int observedCity);

void placeCities(World *world, Geography *geography, int numberToSelect = NUMBER_TO_SELECT_DEFAULT, int numberToTest = NUMBER_TO_TEST_DEFAULT);

#endif