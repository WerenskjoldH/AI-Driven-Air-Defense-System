#include "objectManager.h"
#include "world.h"

void ObjectManager::initialize()
{

}

void ObjectManager::update(World *world, float dt)
{
	for (std::vector<WorldObject*>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		(*it)->update(world, dt);
	}
}

void ObjectManager::draw(sf::RenderWindow * window)
{
	for (std::vector<WorldObject*>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		(*it)->draw(window);
	}
}

void ObjectManager::addObject(WorldObject *obj)
{
	objects.push_back(obj);
}
