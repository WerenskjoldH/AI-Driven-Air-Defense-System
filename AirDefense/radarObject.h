#ifndef RADAR_OBJECT_H
#define RADAR_OBJECT_H

#define RADAR_SIGHT_RADIUS 120.f
#define RADAR_PHYSICAL_SIZE  5.f

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "defenseSystemObject.h"

// Forward Declaration
class DefenseSystemObject;

class RadarObject : public WorldObject
{

public:
	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
	*/
	RadarObject(float x, float y);

	virtual ~RadarObject();

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
		@param Sets the defense system this radar object belongs to
	*/
	void setDefenseSystem(DefenseSystemObject* defenseSystem);

private:
	sf::CircleShape circle;
	sf::CircleShape sightRadiusCircle;

	DefenseSystemObject* defenseSystem;
};

#endif