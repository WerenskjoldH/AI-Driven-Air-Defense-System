#ifndef DEFENSE_SYSTEM_OBJECT_H
#define DEFENSE_SYSTEM_OBJECT_H

#include <SFML/Graphics.hpp>

#include "world.h"
#include "worldObject.h"
#include "radarObject.h"
#include "flyingObject.h"

// Forward Declaration
class RadarObject;

enum ThreatLevel {
	LOW = 1,
	MEDIUM = 2,
	HIGH = 3,
	IMMEDIATE = 4
};

struct ProjectileData {
	FlyingObject* object;

	sf::Vector2f position;
	sf::Vector2f predictedDirection;

	float estimatedSpeed = 0.f;

	ThreatLevel threatRating;
	// ThermalData
};

class DefenseSystemObject : public WorldObject
{
public:

	DefenseSystemObject();

	virtual ~DefenseSystemObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void addRadar(float x, float y, World* world);

	void updateProjectileInformation(FlyingObject* flyingObject);

	// This could be moved to private w/ accessors
	std::vector<ProjectileData> observedProjectiles;

private:
	int numberOfRadars;
	std::vector<RadarObject*> radarArray;

};

#endif