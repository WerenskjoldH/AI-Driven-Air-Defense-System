#ifndef PLANE_OBJECT_H
#define PLANE_OBJECT_H

#define DEFAULT_PLANE_SPEED 50.f

#define PLANE_SIZE 4.f

#include <SFML/Graphics.hpp>

#include "flyingObject.h"

class PlaneObject : public FlyingObject 
{
public:
	PlaneObject(float x, float y, CityObject* destinationCity);

	virtual ~PlaneObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
};

#endif