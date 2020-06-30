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
	/*
		@param objectType Pass a string identifier of the objectType for quick identification
		@param position Where the object will be placed in the world
		@param boundaryRadius Circle bounding radius
	*/
	WorldObject(const char* objectType, sf::Vector2f position, float boundaryRadius = 0.f);

	virtual ~WorldObject();

	// Gets if the object is dead
	const bool isObjectDead();

	// Set the object to be dead
	void setObjectDead();

	// Get the integer identifier of the object
	const int getID();

	// Set the integer identifier of the object
	void setID(int i);

	// Gets the object position
	const sf::Vector2f getPosition();

	// Gets the string object type of this object
	const char* getObjectType();

	/*
		Gets if the object's circle bounding radius intersects another object's
		@param o Object to be tested against
		@return Gets a bool of true or false if it does intersect
	*/
	bool intersects(WorldObject* o) const;

	// Pure virtual function that must be overriden providing logic for what to do on each update tick
	virtual void update(World* world, float dt) = 0;

	// Pure virtual function that must be overriden providing logic for what to do on each draw tick
	virtual void draw(sf::RenderWindow* window) = 0;

protected:
	sf::Vector2f position;
	float boundaryRadius;
	
	int uniqueID;
	char* objectType;
	int isDead;
};

#endif