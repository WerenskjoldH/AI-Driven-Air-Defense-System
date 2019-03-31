#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "worldObject.h"

class TestObject : public WorldObject 
{
public:
	WorldObject* target;

	TestObject(float x, float y) : WorldObject("TestObject")
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

		if (target == NULL)
		{
			int ctr;
			for (ctr = 0; ctr < world->getNumberOfLivingObjects(); ctr++)
			{
				if (this->getID() != 0)
					ctr++;

				if (world->getWorldObjects().at(ctr)->getID() != this->getID())
				{
					// Cast
					if (ctr != 0 && strcmp(world->getWorldObjects().at(ctr + 1)->getObjectType(), this->getObjectType()) == 0)
					{
						TestObject* t = (TestObject*)world->getWorldObjects().at(ctr - 1);

						printf("The prior %s of ID %i is targetting %i\n\n", t->getObjectType(), t->getID(), t->target->getID());
					}

					printf("Target of ID %i aquired with type: %s\n\n", world->getWorldObjects().at(ctr)->getID(), world->getWorldObjects().at(ctr)->getObjectType());

					target = world->getWorldObjects().at(ctr);
					return;
				}
			}

			printf("No targets, targetting self...\n\n");
			target = this;

		}
	};

	void draw(sf::RenderWindow* window)
	{
		sf::CircleShape circle(5);
		circle.setFillColor(sf::Color(80, 80, 80, 255));
		circle.setPosition(position);

		window->draw(circle);
	}
	
private:
	
};

#endif