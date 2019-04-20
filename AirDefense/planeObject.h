#ifndef PLANE_OBJECT_H
#define PLANE_OBJECT_H

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"

class PlaneObject : public WorldObject
{
public:
	PlaneObject(float x, float y, CityObject* destinationCity);

	virtual ~PlaneObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	// Add all properties here

	sf::Vector2f velocity;

};

#endif