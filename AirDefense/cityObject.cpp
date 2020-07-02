#include "cityObject.h"
#include "planeObject.h"
#include "world.h"

CityObject::CityObject(float x, float y, int population) : WorldObject("CityObject", sf::Vector2f(x, y))
{
	this->boundaryRadius = RADIUS_MIN + RADIUS_INCREASE_MAX * (population / POPULATION_MAX);

	this->population = population;

	destroyed = false;

	timeAccumulator = 0.f;
	spawnTime = rand() % UPPER_SPAWN_TIME_LIMIT;

	circle.setRadius(boundaryRadius);
	circle.setOrigin(sf::Vector2f(boundaryRadius, boundaryRadius));
	circle.setFillColor(sf::Color(0, 0, 0, 255));
	circle.setPosition(position);
}

CityObject::~CityObject()
{}

int CityObject::getPopulation() const
{
	return population;
}

void CityObject::update(World * world, float dt)
{
	if (isDestroyed())
		return;

	// Deals with sending planes to closest live city
	// This can and should be done in a less redundant way
	if (timeAccumulator >= spawnTime)
	{
		// Select closest city
		int cityNum = 0;
		int a = INT_MAX;
		for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
		{
			if (!(world->getWorldObjects().at(i)->getObjectType() == "CityObject") || ((CityObject*)world->getWorldObjects().at(i))->isDestroyed() || this->getID() == world->getWorldObjects().at(i)->getID())
				continue;

			float distTemp = vu::magnitude(world->getWorldObjects().at(i)->getPosition() - this->getPosition());

			if (distTemp < a)
			{
				a = distTemp;
				cityNum = i;
			}
		}

		world->addObject((WorldObject*)new PlaneObject(getPosition().x, getPosition().y, (CityObject*)world->getWorldObjects().at(cityNum)));

		timeAccumulator = 0;
		spawnTime = rand() % UPPER_SPAWN_TIME_LIMIT;
	}

	timeAccumulator += dt;
}

void CityObject::draw(sf::RenderWindow * window)
{
	window->draw(circle);
}

bool CityObject::isDestroyed() const
{
	return destroyed;
}

void CityObject::destroyCity()
{
	if (destroyed)
		return;

	destroyed = true;
	circle.setFillColor(sf::Color(255, 0 ,0 ,255));
}
