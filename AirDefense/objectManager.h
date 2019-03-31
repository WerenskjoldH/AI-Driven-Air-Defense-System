#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "consoleColorer.h"
#include "worldObject.h"

class World;

class ObjectManager {
public:
	ObjectManager()
	{
		totalNumObjects = 0;
	}

	~ObjectManager() {}

	void update(World *world, float dt);
	void draw(sf::RenderWindow* window);
	void addObject(WorldObject *obj);
	void reset();

	int getNumberOfObjects() { return objects.size(); }

	std::vector<WorldObject*> getWorldObjects() { return objects; };

private:
	std::vector<WorldObject*> objects;

	int totalNumObjects;

	void initialize();
};


#endif