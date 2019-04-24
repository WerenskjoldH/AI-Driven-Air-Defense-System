#include "planeObject.h"
#include "world.h"

PlaneObject::PlaneObject(float x, float y, CityObject * destinationCity) : FlyingObject(x, y, PLANE_SIZE, "PlaneObject", destinationCity)
{
	circle.setRadius(boundaryRadius);
	circle.setOrigin(sf::Vector2f(boundaryRadius, boundaryRadius));
	circle.setFillColor(sf::Color(0, 150, 60, 255));

	speed = DEFAULT_PLANE_SPEED;

	direction = vu::unit(destinationCity->getPosition() - sf::Vector2f(x, y));
}

PlaneObject::~PlaneObject()
{

}

void PlaneObject::update(World * world, float dt)
{
	position += speed * direction * dt;

	if (intersects((WorldObject*)targetCity))
	{
		//this->setObjectDead();
		setReachedDestination(true);
	}

	// Find the closest city to detour to, else fly off into the oblivion and despawn
	if (targetCity->isDestroyed())
	{
		// Select closest city
		int cityNum = 0;
		int a = INT_MAX;
		for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
		{
			if (!(world->getWorldObjects().at(i)->getObjectType() == "CityObject") || ((CityObject*)world->getWorldObjects().at(i))->isDestroyed())
				continue;

			float distTemp = vu::magnitude(world->getWorldObjects().at(i)->getPosition() - getPosition());

			if (distTemp < a)
			{
				a = distTemp;
				cityNum = i;
			}
		}

		// No city found
		if (a == INT_MAX)
			targetCity == NULL;
		else
		{
			targetCity = (CityObject*)world->getWorldObjects().at(cityNum);

			direction = vu::unit(targetCity->getPosition() - getPosition());
		}
		
	}

	if (position.x < 0 || position.y < 0 || position.x > world->getWorldWidth() || position.y > world->getWorldHeight())
		this->setObjectDead();
}

void PlaneObject::draw(sf::RenderWindow * window)
{
	circle.setPosition(position);
	window->draw(circle);
}
