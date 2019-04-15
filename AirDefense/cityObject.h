#ifndef CITY_OBJECT_H
#define CITY_OBJECT_H

#define POPULATION_MIN 50000
#define POPULATION_MAX 100000

#define RADIUS_MIN 8
#define RADIUS_MAX 14

#include <SFML/Graphics.hpp>
#include "worldObject.h"

class CityObject : public WorldObject
{
public:

	CityObject(float x, float y, int population);

	virtual ~CityObject();

	void initialization();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	int population;

};

#endif