#include "radarObject.h"
#include "flyingObject.h"

RadarObject::RadarObject(float x, float y) : WorldObject("RadarObject", sf::Vector2f(x, y))
{
	boundaryRadius = RADAR_PHYSICAL_SIZE;

	circle.setRadius(boundaryRadius);
	circle.setOrigin(sf::Vector2f(boundaryRadius, boundaryRadius));
	circle.setFillColor(sf::Color(0, 0, 0, 255));
	circle.setPosition(position);

	sightRadiusCircle.setRadius(RADAR_SIGHT_RADIUS);
	sightRadiusCircle.setOrigin(sf::Vector2f(RADAR_SIGHT_RADIUS, RADAR_SIGHT_RADIUS));
	sightRadiusCircle.setFillColor(sf::Color(120, 50, 100, 100));
	sightRadiusCircle.setPosition(position);
}

RadarObject::~RadarObject()
{}

void RadarObject::update(World * world, float dt)
{
	// When a projectile enters the radius, check if it exists in the system's observed objects vector
	for (int i = 0; i < world->getNumberOfLivingObjects(); i++)
	{
		if (!(world->getWorldObjects().at(i)->getObjectType() == "FlyingObject") && !((FlyingObject*)world->getWorldObjects().at(i))->getReachedDestination())
			continue;

		FlyingObject* currentFlyingObject = (FlyingObject*)world->getWorldObjects().at(i);

		float distTemp = vu::magnitude(currentFlyingObject->getPosition() - this->getPosition());

		if (distTemp < RADAR_SIGHT_RADIUS)
		{
			defenseSystem->updateProjectileInformation(currentFlyingObject);
		}
	}
}

void RadarObject::draw(sf::RenderWindow * window)
{
	window->draw(circle);
	window->draw(sightRadiusCircle);
}

void RadarObject::setDefenseSystem(DefenseSystemObject* defenseSystem)
{
	this->defenseSystem = defenseSystem;
}
