#include "defenseSystemObject.h"

DefenseSystemObject::DefenseSystemObject() : WorldObject("DefenseSystemObject", sf::Vector2f(-10.f, -10.f))
{

}

DefenseSystemObject::~DefenseSystemObject()
{}

void DefenseSystemObject::update(World * world, float dt)
{
	// Analyze objects in the list and determine if an object should be intercepted

	// If an object is to be intercepted then find the closest SAM site and fire a projectile to deactivate the threat

}

void DefenseSystemObject::draw(sf::RenderWindow * window)
{}

void DefenseSystemObject::addRadar(float x, float y, World* world)
{
	// Add radar
	RadarObject* radarTempPtr = new RadarObject(x, y);
	radarTempPtr->setDefenseSystem(this);
	world->addObject((WorldObject*)radarTempPtr);
	radarArray.push_back(radarTempPtr);
}

void DefenseSystemObject::updateProjectileInformation(FlyingObject * flyingObject)
{
	/// Could totally do some hashing here to speed up the look up, lack of time is going to force my hand here to just use a loop for now

	// Iterate through vector, if we reach the end and no match was found then push_back a new struct onto the vector

	// Update information in struct
}
