#ifndef CITY_OBJECT_H
#define CITY_OBJECT_H

#define POPULATION_MIN 50000.f
#define POPULATION_MAX 100000.f

#define RADIUS_MIN 4.f
#define RADIUS_INCREASE_MAX 8.f

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