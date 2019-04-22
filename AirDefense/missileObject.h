#ifndef PROJECTILE_OBJECT_H
#define PROJECTILE_OBJECT_H

#define DEFAULT_PROJECTILE_SIZE 3.f
#define DEFAULT_PROJECTILE_SPEED 100.f

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"
#include "vectorUtility.h"
#include "projectileSpawnerObject.h"

class MissileObject : public WorldObject
{
public:
	MissileObject(float x, float y, CityObject* target);

	virtual ~MissileObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void setSpawner(ProjectileSpawnerObject* s);

private:
	// Add all properties here
	sf::Vector2f direction;
	float speed;

	sf::CircleShape circle;

	CityObject* targetCity;

	ProjectileSpawnerObject* spawner;
};

#endif