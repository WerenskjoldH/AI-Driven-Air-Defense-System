#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "consoleColorer.h"
#include "worldObject.h"

class WorldObject;
class World;

class ObjectManager {
public:
	ObjectManager();

	~ObjectManager();

	void update(World *world, float dt);
	void draw(sf::RenderWindow* window);
	void addObject(WorldObject *obj);
	void reset();

	int getNumberOfObjects();

	bool checkIfIdExists(int id);

	std::vector<WorldObject*> getWorldObjects();

private:
	std::vector<WorldObject*> objects;

	int totalNumObjects;

	void initialize();
};


#endif