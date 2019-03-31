#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "worldObject.h"

class TestObject : public WorldObject 
{
public:
	WorldObject* target;

	TestObject(float x, float y, float radius) : WorldObject("TestObject", sf::Vector2f(x, y), radius)
	{ }

	virtual ~TestObject() {};

	void initialization() {};

	void update(World* world, float dt) 
	{
		// Checks if located in water, if so marks for death
		//if (!world->checkIfLandAtLocation(position.x, position.y))
		//	this->isDead = true;

		//sf::Vector2f direction = vu::unit(this->position);

		//direction = vu::cclockwisePerpendicular(direction);

		//this->position += 10.f * direction * dt;

		std::vector<WorldObject*> worldObjs = world->getWorldObjects();

		for (std::vector<WorldObject*>::iterator it = worldObjs.begin(); it != worldObjs.end(); it++)
		{
			if ((*it)->getID() != this->getID() && this->intersects((*it)))
				(*it)->setObjectDead();
		}
		
	};

	void draw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(boundaryRadius);
		circle.setFillColor(sf::Color(80, 80, 80, 255));
		circle.setPosition(position);

		window->draw(circle);
	}
	
private:
	
};

#endif