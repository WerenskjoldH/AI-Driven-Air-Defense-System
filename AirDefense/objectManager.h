#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "consoleColorer.h"
#include "worldObject.h"

class WorldObject;
class World;

// Only one object should exist of this class typically
class ObjectManager {
public:
	ObjectManager();

	~ObjectManager();

	/*
		Contains all logic for updating objects being managed
		@param world The World that we will be updating objects in
		@param dt The amount of time between last frame and this one
	*/
	void update(World *world, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

	/*
		Takes a reference to an object and adds it to the manager
		@param obj The object to be added to the manager
	*/
	void addObject(WorldObject *obj);

	// Resets the manager resetting most all fields
	void reset();

	// Gets the number of objects being managed
	int getNumberOfObjects();

	/*
		Search the managed objects for a matching id and return true of false
		@param Gets a boolean value whether an object id exists in the manager or not
	*/
	bool checkIfIdExists(int id);

	// Get direct access to all managed objects
	std::vector<WorldObject*> getWorldObjects();

private:
	std::vector<WorldObject*> objects;

	int totalNumObjects;

	void initialize();
};


#endif