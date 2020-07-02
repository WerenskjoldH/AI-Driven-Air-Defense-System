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
	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
		@param population Population of the city
	*/
	CityObject(float x, float y, int population);

	virtual ~CityObject();

	/*
		@return Gets the population of the city
	*/
	int getPopulation() const;

	/*
		Contains all update logic
		@param world The world this city object will interact with
		@param dt the delta time between frames -- this can be static or dynamic
	*/
	void update(World* world, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

	// Gets if the city has been destroyed
	bool isDestroyed() const;

	// Destroys the city and deals with all logic that depends on the city being "alive"
	void destroyCity();

private:
	int destroyed;
	int population;

	float timeAccumulator;
	float spawnTime;

	sf::CircleShape circle;

};

#endif