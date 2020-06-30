#ifndef WORLD_H
#define WORLD_H

#define IM InputManager::getInstance()

#include <SFML/Graphics.hpp>

#include "inputManager.h"
#include "objectManager.h"

// Inform the compiler that these classes exist and implementations will be provided after linking
class Geography;
class WorldObject;
class ObjectManager;

// The World class handles everything that dwells within the simulation space
class World {
public:

	/*
		@param worldWidth Width of the world in pixels, this should match window width
		@param worldHeight Height of the world in pixels, this shoudl match window height
	*/
	World(int worldWidth, int worldHeight);

	~World();

	/*
		Contains all update logic
		@param window The RenderWindow we will be referencing, do NOT put draw calls here
		@param dt the delta time between frames -- this can be static or dynamic
	*/
	void update(sf::RenderWindow* window, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

	/*
		
	*/
	void addObject(WorldObject *obj);

	// Resets the world and creates new geography
	void resetWorldAndRegenerateGeography();

	/*
		@return Gets the number of objects in the ObjectManager
	*/
	int getNumberOfLivingObjects();

	/*
		@return Gets if there is land where the mouse has clicked
	*/
	bool checkIfLandAtMouse();

	/*
		@param x X coordinate
		@param y Y coordinate
		@return Gets if there is land at the given <x,y> coordinates
	*/
	bool checkIfLandAtLocation(float x, float y);

	/*
		@param x X coordinate
		@param y Y coordinate
		@return Gets the altitude at the given <x,y> coordinates
	*/
	float getAltitudeAtLocation(float x, float y);

	/*
		@return Gets the world width in pixels
	*/
	int getWorldWidth();
	/*
		@return Gets the world height in pixels
	*/
	int getWorldHeight();

	/*
		Return a vector of references to all world objects
	*/
	std::vector<WorldObject*> getWorldObjects();

private:
	Geography *geography;

	ObjectManager objectManager;

	// Initializes the object on creation
	void initialize();

	// Regenerate the geography and update given a seed
	void regenerateGeography(float seed);

	// Removes all objects in the simulation space
	void resetWorld();
};

#endif