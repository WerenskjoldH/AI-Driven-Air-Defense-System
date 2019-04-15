#ifndef WORLD_H
#define WORLD_H

#define IM InputManager::getInstance()

#include <SFML/Graphics.hpp>

#include "inputManager.h"
#include "objectManager.h"

class Geography;
class WorldObject;
class ObjectManager;

class World {
public:

	World(int worldWidth, int worldHeight);

	~World();

	void update(sf::RenderWindow* window, float dt);
	void draw(sf::RenderWindow* window);

	void addObject(WorldObject *obj);

	void resetWorld();

	void resetWorldAndRegenerateGeography();

	int getNumberOfLivingObjects();

	bool checkIfLandAtMouse();

	bool checkIfLandAtLocation(float x, float y);

	std::vector<WorldObject*> getWorldObjects();

private:
	Geography *geography;

	ObjectManager objectManager;

	void initialize();

	void regenerateGeography(float seed);
};

#endif