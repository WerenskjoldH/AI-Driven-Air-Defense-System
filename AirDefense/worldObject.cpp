#include "worldObject.h"

WorldObject::WorldObject(const char * objectType, sf::Vector2f position, float boundaryRadius) : objectType{ (char*)objectType }, position{ position }, boundaryRadius{ boundaryRadius }
{
	this->isDead = false;

	this->position.x -= boundaryRadius;
	this->position.y -= boundaryRadius;
}

WorldObject::~WorldObject()
{
}

const bool WorldObject::isObjectDead()
{
	return isDead;
}

void WorldObject::setObjectDead()
{
	isDead = true;
}

const int WorldObject::getID()
{
	return uniqueID;
}
void WorldObject::setID(int i)
{
	uniqueID = i;
}

const sf::Vector2f WorldObject::getPosition()
{
	return position;
}

const char * WorldObject::getObjectType()
{
	return objectType;
}

bool WorldObject::intersects(WorldObject * o) const
{
	if (std::fabs(vu::magnitude(o->getPosition() - this->position)) <= 2.f*boundaryRadius)
		return true;
	return false;
}
