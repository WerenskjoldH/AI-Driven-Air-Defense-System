#include "objectManager.h"

void ObjectManager::initialize()
{

}

ObjectManager::ObjectManager()
{
	totalNumObjects = 0;
}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::update(World *world, float dt)
{
	/// Check for removals
	std::vector<WorldObject*>::iterator it = objects.begin();
	while (it != objects.end())
	{
		if ((*it)->isObjectDead())
		{
			delete (*it);
			it = objects.erase(it);
		}
		else
			++it;
	}

	/// Update 'alive' objects - we must loop this to avoid the issues of adding new objects from inside object
	int i = objects.size();
	for (int j = 0; j < i; j++)
	{
		objects.at(j)->update(world, dt);
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
	obj->setID(totalNumObjects++);
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

int ObjectManager::getNumberOfObjects()
{
	return objects.size();
}

bool ObjectManager::checkIfIdExists(int id)
{
	for (std::vector<WorldObject*>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		if ((*it)->getID() == id)
			return true;
	}

	return false;
}

std::vector<WorldObject*> ObjectManager::getWorldObjects()
{
	return objects;
}