#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include "consoleColorer.h"
#include "vectorUtility.h"

class World;

class WorldObject
{
public:

	// Having to hand name each derived class is unfortunate, but quick
	WorldObject(const char* objectType, sf::Vector2f position, float boundaryRadius) : objectType{ (char*)objectType }, position{ position }, boundaryRadius{ boundaryRadius }
	{
		this->isDead = false;

		this->position.x -= boundaryRadius;
		this->position.y -= boundaryRadius;
	}

	virtual ~WorldObject() { };

	const bool isObjectDead() { return isDead; }

	void setObjectDead() { isDead = true;  }

	const int getID() { return uniqueID; };

	void setID(int i) { uniqueID = i; }

	const sf::Vector2f getPosition() { return position; }

	const char* getObjectType() { return objectType; };

	bool intersects(WorldObject* o) const
	{
		if (std::fabs(vu::magnitude(o->getPosition() - this->position)) <= 2.f*boundaryRadius)
			return true;
		return false;
	}

	virtual void initialization() = 0;

	virtual void update(World* world, float dt) = 0;

	virtual void draw(sf::RenderWindow* window) = 0;

protected:
	sf::Vector2f position;
	float boundaryRadius;
	
	int uniqueID;
	char* objectType;
	int isDead;
};

#endif