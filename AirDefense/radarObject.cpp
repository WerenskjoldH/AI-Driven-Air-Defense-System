#include "RadarObject.h"

RadarObject::RadarObject(float x, float y, int population) : WorldObject("RadarObject", sf::Vector2f(x, y))
{

}

RadarObject::~RadarObject()
{
}

void RadarObject::update(World * world, float dt)
{
}

void RadarObject::draw(sf::RenderWindow * window)
{
}
