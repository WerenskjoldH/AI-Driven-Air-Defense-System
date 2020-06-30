#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "cityObject.h"
#include "vectorUtility.h"
#include "projectileSpawnerObject.h"

class FlyingObject : public WorldObject
{
public:
	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
		@param size The bounding radius of the object
		@param objectType Type of object given as a string
		@param targetCity City the object is traveling towards
	*/
	FlyingObject(float x, float y, float size, const char* objectType, CityObject * targetCity);

	virtual ~FlyingObject();

	// Pure virtual function that must be overriden providing logic for what to do on each update tick
	virtual void update(World* world, float dt) = 0;

	// Pure virtual function that must be overriden providing logic for what to do on each draw tick
	virtual void draw(sf::RenderWindow* window) = 0;

	// Pure virutal function that must be overriden providing logic for how to generate the object's heat signature
	virtual std::vector<float> generateSignature() = 0;

	// Gets a const char* of the derived object's type
	const char* getSubObjectType();

	// Gets a boolean saying if the object has reached its destination
	const bool getReachedDestination();

	/*
		Set if the object has reached its destination or not
		@param tf Whether the object has reached its desination or not
	*/
	void setReachedDestination(bool tf);

	// Gets if hte object has been destroyed or not
	const bool getDestroyed();

	// "Destroys" the object in the simulation
	void destroyObject();

	// Allows for the object to be cleaned up and the memory freed by the object manager
	void allowDeletion();

protected:
	// Add all properties here
	sf::Vector2f direction;

	float speed;

	bool reachedDestination;
	bool destroyed = false;

	char* subObjectType;

	sf::CircleShape circle;

	CityObject* targetCity;

	static const float sigMean[];

	static const float sigStd[];
};

#endif