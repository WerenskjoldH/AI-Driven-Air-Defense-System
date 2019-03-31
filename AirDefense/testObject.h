#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "worldObject.h"

class TestObject : public WorldObject 
{
public:
	TestObject(float x, float y)
	{
		position.x = x - 5.f;
		position.y = y - 5.f;
	}

	void update(World* world, float dt) {};

	void draw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(5);
		circle.setFillColor(sf::Color(80, 80, 80, 255));
		circle.setPosition(position);

		window->draw(circle);
	}

};

#endif