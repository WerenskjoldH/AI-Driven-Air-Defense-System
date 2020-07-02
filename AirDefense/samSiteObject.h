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
	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
	*/
	SAMSiteObject(float x, float y);

	virtual ~SAMSiteObject();

	/*
		Contains all update logic
		@param world The world this city object will interact with
		@param dt the delta time between frames -- this can be static or dynamic
	*/
	void update(World* world, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

	/*
		@param target Sets the target for the SAM to shoot down
	*/
	void setTarget(FlyingObject* target);

	// Gets the target of the SAM site
	const FlyingObject* getTarget();

	/*
		@param defenseSystem Sets the defense system this SAM site belongs to
	*/
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