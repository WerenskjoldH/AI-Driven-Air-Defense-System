#ifndef PROJECTILE_SPAWNER_OBJECT_H
#define PROJECTILE_SPAWNER_OBJECT_H

#include <SFML/Graphics.hpp>
#include "worldObject.h"

class ProjectileSpawnerObject : public WorldObject
{
public:
	//CityObject::CityObject(float x, float y, int population) : WorldObject("CityObject", sf::Vector2f(x, y))
	ProjectileSpawnerObject();

	virtual ~ProjectileSpawnerObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	// Spawn missile
	// addProjectile(float x, float y, projectile information...);
};

#endif