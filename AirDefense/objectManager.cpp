#include "objectManager.h"
#include "world.h"

void ObjectManager::initialize()
{

}

void ObjectManager::update(World *world, float dt)
{
	/// Check for removals
	std::vector<WorldObject*>::iterator it = objects.begin();
	while (it != objects.end())
	{
		if ((*it)->IsDead())
		{
			delete (*it);
			it = objects.erase(it);
		}
		else
			++it;
	}

	/// Update 'alive' objects
	for (it = objects.begin(); it != objects.end(); it++)
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

void ObjectManager::reset()
{
	std::vector<WorldObject*>::iterator it = objects.begin();

	while (it != objects.end())
	{
		WorldObject* obj = (*it);
		it = objects.erase(it);
		delete obj;
	}
}
