#ifndef PROJECTILE_SPAWNER_OBJECT_H
#define PROJECTILE_SPAWNER_OBJECT_H

#define UPPER_SPAWN_TIME_LIMIT 6

#include <SFML/Graphics.hpp>
#include "worldObject.h"

class ProjectileSpawnerObject : public WorldObject
{
public:

	ProjectileSpawnerObject();

	virtual ~ProjectileSpawnerObject();

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

	// Increments the number of destroyed cities
	void incrementDestroyedCities();

private:
	int numberOfCities;
	int numberOfCitiesDestroyed;

	float timeAccumulator;
	float spawnTime;

	bool ceaseFire;

	/*
		Spawns a missile object
		@param world World to spawn the missile into
	*/
	void addProjectile(World* world);
};

#endif