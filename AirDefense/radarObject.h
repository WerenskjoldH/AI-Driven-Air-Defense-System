#ifndef RADAR_OBJECT_H
#define RADAR_OBJECT_H

#include <SFML/Graphics.hpp>
#include "worldObject.h"

struct ProjectileData {
	sf::Vector2f position;
	sf::Vector2f predictedDirection;
	float estimatedSpeed = 0.f;
	// ThermalData
};

class RadarObject : public WorldObject
{

public:
	RadarObject(float x, float y, int population);

	virtual ~RadarObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

private:
	sf::CircleShape circle;

};

#endif