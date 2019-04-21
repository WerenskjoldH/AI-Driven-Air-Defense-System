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

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void incrementDestroyedCities();

private:
	int numberOfCities;
	int numberOfCitiesDestroyed;

	float timeAccumulator;
	float spawnTime;

	bool ceaseFire;

	// Spawn missile
	void addProjectile(World* world);
};

#endif