#include "projectileSpawnerObject.h"
#include "projectileObject.h"
#include "consoleColorer.h"
#include "vectorUtility.h"
#include "world.h"

// This is a managing object, we don't need to draw it and therefore we just move it off the screen
ProjectileSpawnerObject::ProjectileSpawnerObject() : WorldObject("ProjectileSpawnerObject", sf::Vector2f(-10.f, -10.f))
{
	timeAccumulator = 0.f;
	spawnTime = rand() % UPPER_SPAWN_TIME_LIMIT;

	numberOfCities = 0;

	ceaseFire = false;
}

ProjectileSpawnerObject::~ProjectileSpawnerObject()
{}

void ProjectileSpawnerObject::update(World * world, float dt)
{
	if (ceaseFire)
		return;

	if (numberOfCities == 0)
	{
		for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
			if (world->getWorldObjects().at(i)->getObjectType() == "CityObject")
				numberOfCities++;
	}

	if (numberOfCitiesDestroyed >= numberOfCities)
		ceaseFire = true;

	if (timeAccumulator >= spawnTime)
	{
		addProjectile(world);
		timeAccumulator = 0;
		spawnTime = rand() % UPPER_SPAWN_TIME_LIMIT;
	}

	timeAccumulator += dt;
}

void ProjectileSpawnerObject::draw(sf::RenderWindow * window)
{

}

void ProjectileSpawnerObject::incrementDestroyedCities()
{
	numberOfCitiesDestroyed++;
}

void ProjectileSpawnerObject::addProjectile(World* world)
{
	float x, y;

	// To avoid human-detectable patterns, we just make three random values
	// We could make this more efficient
	double r = (float(rand())) / float(RAND_MAX);
	double r2 = (float(rand())) / float(RAND_MAX);
	double r3 = (float(rand())) / float(RAND_MAX);

	// Select a position
	// If we get 1 then place on the horizontal, else vertical
	if (int(r + 0.5f))
	{
		y = int(r2 + 0.5f) * world->getWorldHeight();
		x = r3 * world->getWorldWidth();
	}
	else
	{
		x = int(r2 + 0.5f) * world->getWorldWidth();
		y = r3 * world->getWorldHeight();
	}

	// Select closest city
	int cityNum = 0;
	int a = INT_MAX;
	for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
	{
		if (!(world->getWorldObjects().at(i)->getObjectType() == "CityObject") || ((CityObject*)world->getWorldObjects().at(i))->isDestroyed())
			continue;

		float distTemp = vu::magnitude(world->getWorldObjects().at(i)->getPosition() - sf::Vector2f(x, y));

		if (distTemp < a)
		{
			a = distTemp;
			cityNum = i;
		}
	}

	// Add projectile
	ProjectileObject* projectileTempPtr = new ProjectileObject(x, y, (CityObject*)world->getWorldObjects().at(cityNum));
	projectileTempPtr->setSpawner(this);
	world->addObject((WorldObject*)projectileTempPtr);
}
