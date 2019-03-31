#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "worldObject.h"

class TestObject : public WorldObject 
{
public:
	TestObject(float x, float y) : WorldObject()
	{
		position.x = x - 5.f;
		position.y = y - 5.f;
	}

	virtual ~TestObject() {};

	void initialization() {};

	void update(World* world, float dt) 
	{
		// Checks if located in water, if so marks for death
		if (!world->checkIfLandAtLocation(position.x, position.y))
			this->isDead = true;
	};

	void draw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(5);
		circle.setFillColor(sf::Color(80, 80, 80, 255));
		circle.setPosition(position);

		window->draw(circle);
	}

};

#endif