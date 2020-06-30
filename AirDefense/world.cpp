#include "world.h"
#include "cityPlanner.h"
#include "geography.h"

World::World(int worldWidth, int worldHeight)
{
	geography = new Geography(worldWidth, worldHeight, 6, 0.5f, 1, 0.4f, 1996);

	initialize();
}

World::~World()
{
	delete geography;
}

void World::initialize()
{
	resetWorldAndRegenerateGeography();
}

void World::update(sf::RenderWindow * window, float dt)
{
	objectManager.update(this, dt);
}

void World::draw(sf::RenderWindow * window)
{
	// Draw the geography first
	geography->drawLand(window);

	// Draw the objects second, on top
	objectManager.draw(window);
}

void World::addObject(WorldObject *obj)
{
	objectManager.addObject(obj);
}

void World::resetWorld()
{
	objectManager.reset();
}

void World::resetWorldAndRegenerateGeography()
{
	resetWorld();
	regenerateGeography(rand() % 1996);
}

int World::getNumberOfLivingObjects()
{
	return objectManager.getNumberOfObjects();
}

// This function exists as a helper, I got tired of typing this on repeat
// We could actually just make this a pre-processor call, or inline it
bool World::checkIfLandAtMouse()
{
	return geography->checkIfLand(IM.mousePosition().x, IM.mousePosition().y);
}

bool World::checkIfLandAtLocation(float x, float y)
{
	return geography->checkIfLand(x, y);
}

float World::getAltitudeAtLocation(float x, float y)
{
	return geography->getAltitude(x, y);
}

int World::getWorldHeight()
{
	return geography->getHeight();
}

int World::getWorldWidth()
{
	return geography->getWidth();
}

std::vector<WorldObject*> World::getWorldObjects()
{
	return objectManager.getWorldObjects();
}

void World::regenerateGeography(float seed)
{
	geography->regenerate(seed);

	placeCities(this, this->geography);
}