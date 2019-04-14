#ifndef WORLD_H
#define WORLD_H

#define IM InputManager::getInstance()

#include "inputManager.h"
#include "objectManager.h"
#include "geography.h"

class World {
public:

	World(int worldWidth, int worldHeight)
	{
		geography = new Geography(worldWidth, worldHeight, 6, 0.5, 1, 0.4, 1996);

		initialize();
	}

	~World() 
	{
		delete geography;
	}

	void update(sf::RenderWindow* window, float dt);
	void draw(sf::RenderWindow* window);

	void addObject(WorldObject *obj);

	void regenerateGeography(float seed) { geography->regenerate(seed); }

	void resetWorld();

	void resetWorldAndRegenerateGeography();

	int getNumberOfLivingObjects() { return objectManager.getNumberOfObjects(); }

	bool checkIfLandAtMouse() { return geography->checkIfLand(IM.mousePosition().x, IM.mousePosition().y); }

	bool checkIfLandAtLocation(float x, float y) { return geography->checkIfLand(x, y); }

	std::vector<WorldObject*> getWorldObjects() { return objectManager.getWorldObjects();  };

private:
	Geography *geography;

	ObjectManager objectManager;

	void initialize();
};

#endif