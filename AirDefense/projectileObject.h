#ifndef PROJECTILE_OBJECT_H
#define PROJECTILE_OBJECT_H

#define DEFAULT_PROJECTILE_SIZE 3.f
#define DEFAULT_PROJECTILE_SPEED 10.f

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"
#include "vectorUtility.h"

class ProjectileObject : public WorldObject
{
public:
	ProjectileObject(float x, float y, CityObject* target);

	virtual ~ProjectileObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	// Add all properties here
	sf::Vector2f direction;
	float speed;

	sf::CircleShape circle;

	CityObject* targetCity;

};

#endif