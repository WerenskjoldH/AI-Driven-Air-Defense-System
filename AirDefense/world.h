#ifndef WORLD_H
#define WORLD_H

#define IM InputManager::getInstance()

#include "geography.h"
#include "inputManager.h"

class World {
public:

	World(int worldWidth, int worldHeight)
	{
		geography = std::unique_ptr<Geography>(new Geography(worldWidth, worldHeight, 6, 0.9, 1, 0.4));

		initialize();
	}

	~World() {}

	void initialize();
	void update(sf::RenderWindow* window, float dt);
	void draw(sf::RenderWindow* window);

	bool checkIfLandAtMouse() { return geography->checkIfLand(IM.mousePosition().x, IM.mousePosition().y); }
	void regenerateGeography(float seed) { geography->regenerate(seed); }

private:
	std::unique_ptr<Geography> geography;
};

#endif