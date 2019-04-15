#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <SFML/Graphics.hpp>

#include "consoleColorer.h"
#include "vectorUtility.h"

class World;

class WorldObject
{
public:

	// Having to hand name each derived class is unfortunate, but quick
	WorldObject(const char* objectType, sf::Vector2f position, float boundaryRadius = 0.f);

	virtual ~WorldObject();

	const bool isObjectDead();

	void setObjectDead();

	const int getID();

	void setID(int i);

	const sf::Vector2f getPosition();

	const char* getObjectType();

	bool intersects(WorldObject* o) const;

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