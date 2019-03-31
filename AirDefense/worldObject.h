#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include "consoleColorer.h"
#include "objectManager.h"

class World;

class WorldObject
{
public:

	WorldObject() {
		// World objects are marked to be alive after initialization is completed

		isDead = false;
	}

	virtual ~WorldObject() {};

	bool IsDead()
	{
		return isDead;
	}

	virtual void initialization() = 0;

	virtual void update(World* world, float dt) = 0;

	virtual void draw(sf::RenderWindow* window) = 0;

protected:
	sf::Vector2f position;
	
	int isDead;
};

#endif