#include "world.h"

void World::initialize()
{

}

void World::update(sf::RenderWindow * window, float dt)
{
	objectManager.update(this, dt);

}

void World::draw(sf::RenderWindow * window)
{
	geography->drawLand(window);

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
	srand(std::time(0));
	regenerateGeography(rand() % 1996);
	resetWorld();
}
