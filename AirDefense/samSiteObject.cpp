#include "samSiteObject.h"

SAMSiteObject::SAMSiteObject(float x, float y) : WorldObject("SAMSiteObject", sf::Vector2f(x, y))
{
	boundaryRadius = 10.f;
	rect.setSize(sf::Vector2f(boundaryRadius, boundaryRadius));
	rect.setOrigin(sf::Vector2f(boundaryRadius/2.f, boundaryRadius/2.f));
	rect.setFillColor(sf::Color(0, 0, 0, 255));
	rect.setPosition(position);

	//sightRadiusCircle.setRadius(SAM_SIGHT_RADIUS);
	//sightRadiusCircle.setOrigin(sf::Vector2f(SAM_SIGHT_RADIUS, SAM_SIGHT_RADIUS));
	//sightRadiusCircle.setFillColor(sf::Color(200, 50, 0, 80));
	//sightRadiusCircle.setPosition(position);

	targetLine[0] = sf::Vertex(getPosition());

	target = NULL;
}

SAMSiteObject::~SAMSiteObject()
{

}

void SAMSiteObject::update(World * world, float dt)
{
	if (target == NULL)
		return;

	targetLine[1] = target->getPosition();

	if (interceptorAccumulator >= SAM_TIME_TO_TRAVEL_MAP * vu::magnitude(target->getPosition() - getPosition())/world->getWorldWidth())
	{
		target->destroyObject();
		interceptorAccumulator = 0.f;
	}

	interceptorAccumulator += dt;
}

void SAMSiteObject::draw(sf::RenderWindow * window)
{
	window->draw(rect);

	if(target != NULL)
		window->draw(targetLine, 2, sf::Lines);

	//window->draw(sightRadiusCircle);
}

void SAMSiteObject::setTarget(FlyingObject * target)
{
	this->target = target;
	interceptorAccumulator = 0.f;
}

const FlyingObject* SAMSiteObject::getTarget()
{
	return target;
}

void SAMSiteObject::setDefenseSystem(DefenseSystemObject * defenseSystem)
{
	this->defenseSystem = defenseSystem;
}
