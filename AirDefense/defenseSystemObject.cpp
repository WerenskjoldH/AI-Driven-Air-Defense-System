#include "defenseSystemObject.h"

DefenseSystemObject::DefenseSystemObject() : WorldObject("DefenseSystemObject", sf::Vector2f(-10.f, -10.f))
{

}

DefenseSystemObject::~DefenseSystemObject()
{}

/// There's some extreme inefficiency happening here
void DefenseSystemObject::update(World * world, float dt)
{
	// Clear all defunct objects ( i.e. have reached destination )
	std::vector<ProjectileData>::iterator it = observedProjectiles.begin();
	while (it != observedProjectiles.end())
	{
		if (it->object->getReachedDestination() || it->object->getDestroyed())
		{
			// Remove SAM targeting
			for (std::vector<SAMSiteObject*>::iterator sit = samArray.begin(); sit != samArray.end(); sit++)
			{
				if ((*sit)->getTarget() == it->object)
					(*sit)->setTarget(NULL);
			}

			it->object->allowDeletion();
			it = observedProjectiles.erase(it);
		}
		else
			it++;
	}

	for (it = observedProjectiles.begin(); it != observedProjectiles.end(); it++)
	{
		// Analyze objects in the list and determine if an object should be intercepted
		/// Todo ///
		if (it->object->getSubObjectType() != "MissileObject")
			continue;

		// If an object is to be intercepted then find the closest SAM site and fire a projectile to deactivate the threat
		if (!it->beingTargeted)
		{
			SAMSiteObject* closest = NULL;
			for (std::vector<SAMSiteObject*>::iterator sit = samArray.begin(); sit != samArray.end(); sit++)
			{
				if ((*sit)->getTarget() != NULL)
					continue;

				if (closest == NULL || vu::magnitude(it->position - (*sit)->getPosition()) < vu::magnitude(it->position - closest->getPosition()))
					closest = (*sit);
			}

			if (closest != NULL)
			{
				closest->setTarget(it->object);
				it->beingTargeted = true;
			}
		}
	}

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

void DefenseSystemObject::addSAMSite(float x, float y, World * world)
{
	// Add SAM site
	SAMSiteObject* samTempPtr = new SAMSiteObject(x, y);
	samTempPtr->setDefenseSystem(this);
	world->addObject((WorldObject*)samTempPtr);
	samArray.push_back(samTempPtr);
}

void DefenseSystemObject::updateProjectileInformation(FlyingObject * flyingObject)
{
	int i = NULL;

	/// Could totally do some hashing here to speed up the look up, lack of time is going to force my hand here to just use a loop for now
	// Iterate through vector, if we reach the end and no match was found then push_back a new struct onto the vector
	for (int j = 1; j < observedProjectiles.size()+1; j++)
	{
		if (flyingObject == observedProjectiles.at(j-1).object)
		{
			i = j;
			break;
		}
	}

	if (i == NULL)
	{
		observedProjectiles.push_back(ProjectileData(flyingObject, flyingObject->getPosition()));
		i = observedProjectiles.size();
	}

	// Update information in struct	
	/// Todo
}
