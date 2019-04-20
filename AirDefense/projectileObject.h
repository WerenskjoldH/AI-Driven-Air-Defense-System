#ifndef PROJECTILE_OBJECT_H
#define PROJECTILE_OBJECT_H

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"

class ProjectileObject : public WorldObject
{
public:
	ProjectileObject(float x, float y, CityObject* target);

	virtual ~ProjectileObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	// Add all properties here

	sf::Vector2f velocity;

};

#endif