#ifndef CITY_OBJECT_H
#define CITY_OBJECT_H

#define POPULATION_MIN 50000.f
#define POPULATION_MAX 100000.f

#define RADIUS_MIN 4.f
#define RADIUS_INCREASE_MAX 8.f

#define UPPER_SPAWN_TIME_LIMIT 6

#include <SFML/Graphics.hpp>
#include "worldObject.h"

class CityObject : public WorldObject
{
public:

	CityObject(float x, float y, int population);

	virtual ~CityObject();

	int getPopulation() const;

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	bool isDestroyed() const;

	void destroyCity();

private:
	int destroyed;
	int population;

	float timeAccumulator;
	float spawnTime;

	sf::CircleShape circle;

};

#endif