#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include "consoleColorer.h"
#include "objectManager.h"

class World;

class WorldObject
{
public:

	// Having to hand name each derived class is unfortunate, but quick
	WorldObject(const char* objectType) : objectType{(char*)objectType}
	{
		isDead = false;
	}

	virtual ~WorldObject() { };

	const bool IsDead() { return isDead; }

	const int getID() { return uniqueID; };

	void setID(int i) { uniqueID = i; }

	const char* getObjectType() { return objectType; };

	virtual void initialization() = 0;

	virtual void update(World* world, float dt) = 0;

	virtual void draw(sf::RenderWindow* window) = 0;

protected:
	sf::Vector2f position;
	
	int uniqueID;
	char* objectType;
	int isDead;
};

#endif