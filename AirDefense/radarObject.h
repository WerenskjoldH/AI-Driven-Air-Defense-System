#ifndef RADAR_OBJECT_H
#define RADAR_OBJECT_H

#define RADAR_SIGHT_RADIUS 150.f
#define RADAR_PHYSICAL_SIZE  5.f

#include <SFML/Graphics.hpp>

#include "worldObject.h"
#include "defenseSystemObject.h"

// Forward Declaration
class DefenseSystemObject;

class RadarObject : public WorldObject
{

public:
	RadarObject(float x, float y);

	virtual ~RadarObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void setDefenseSystem(DefenseSystemObject* defenseSystem);

private:
	sf::CircleShape circle;
	sf::CircleShape sightRadiusCircle;

	DefenseSystemObject* defenseSystem;
};

#endif