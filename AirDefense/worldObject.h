#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include "consoleColorer.h"
#include "objectManager.h"

class World;

class WorldObject
{
public:

	virtual void update(World* world, float dt) = 0;

	virtual void draw(sf::RenderWindow* window) = 0;

protected:
	sf::Vector2f position;
};

#endif