#ifndef CITY_PLANNER_H
#define CITY_PLANNER_H

class World;
class Geography;

// This way we don't have to generate 2*n city objects and waste space
struct city {
	float x;
	float y;
	int pop;
	float weight;
	float radius;
	bool choosen = 0;
};

void swapCities(city* a, city* b);

int scoreCity(city &c);

void placeCities(World *world, Geography *geography, int numberToSelect = 6, int numberToTest = 30);

#endif