#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"
#include "vectorUtility.h"
#include "projectileSpawnerObject.h"

class FlyingObject : public WorldObject
{
public:
	FlyingObject(float x, float y, float size, const char* objectType, CityObject * targetCity);

	virtual ~FlyingObject();

	virtual void update(World* world, float dt) = 0;

	virtual void draw(sf::RenderWindow* window) = 0;

	const char* getSubObjectType();

protected:
	// Add all properties here
	sf::Vector2f direction;
	float speed;

	char* subObjectType;

	sf::CircleShape circle;

	CityObject* targetCity;
};

#endif