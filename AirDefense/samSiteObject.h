#ifndef SAM_SITE_OBJECT_H
#define SAM_SITE_OBJECT_H

#define SAM_SIGHT_RADIUS 120.f


#define SAM_TIME_TO_TRAVEL_MAP 4.f

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "defenseSystemObject.h"

// Forward Declaration
class DefenseSystemObject;

class SAMSiteObject : public WorldObject
{
public:

	SAMSiteObject(float x, float y);

	virtual ~SAMSiteObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void setTarget(FlyingObject* target);
	const FlyingObject* getTarget();

	void setDefenseSystem(DefenseSystemObject* defenseSystem);

private:

	sf::RectangleShape rect;

	float interceptorAccumulator;

	//sf::CircleShape sightRadiusCircle;

	sf::Vertex targetLine[2];

	FlyingObject* target;

	DefenseSystemObject* defenseSystem;
};

#endif