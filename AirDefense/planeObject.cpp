#include "planeObject.h"

PlaneObject::PlaneObject(float x, float y, CityObject * destinationCity) : WorldObject("ProjectileObject", sf::Vector2f(x, y))
{
}

PlaneObject::~PlaneObject()
{
}

void PlaneObject::update(World * world, float dt)
{
}

void PlaneObject::draw(sf::RenderWindow * window)
{
}
