#include "flyingObject.h"

FlyingObject::FlyingObject(float x, float y, float size, const char* objectType, CityObject * targetCity) : WorldObject("FlyingObject", sf::Vector2f(x, y), size)
{
	this->targetCity = targetCity;

	this->subObjectType = (char*)objectType;
}

FlyingObject::~FlyingObject()
{
}

const char * FlyingObject::getSubObjectType()
{
	return subObjectType;
}
