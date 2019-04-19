#ifndef CITY_PLANNER_H
#define CITY_PLANNER_H

// In pixels
#define PREFERRED_CITY_DISTANCE 30.f
#define DISTANCE_STEP_SIZE 10.f

#define NUMBER_OF_PLACEMENT_TEST_DEFAULT 20
#define NUMBER_OF_CITIES_DEFAULT 5

#define DISTANCE(x, y, x0, y0) sqrt(powf(x0 - x, 2) + powf(y0 - y, 2))

class World;
class Geography;

void placeCities(World *world, Geography *geography, int numberOfCitiesToTest = NUMBER_OF_CITIES_DEFAULT, int numberOfTrials = NUMBER_OF_PLACEMENT_TEST_DEFAULT);

#endif