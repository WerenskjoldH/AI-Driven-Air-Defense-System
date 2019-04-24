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

const bool FlyingObject::getReachedDestination()
{
	return reachedDestination;
}

void FlyingObject::setReachedDestination(bool tf)
{
	if (tf)
	{
		circle.setRadius(0.f);
	}
	reachedDestination = tf;
}

const bool FlyingObject::getDestroyed()
{
	return destroyed;
}

void FlyingObject::destroyObject()
{
	destroyed = true;
}

void FlyingObject::allowDeletion()
{
	this->setObjectDead();
}
