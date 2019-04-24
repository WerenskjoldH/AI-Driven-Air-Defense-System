#ifndef DEFENSE_SYSTEM_OBJECT_H
#define DEFENSE_SYSTEM_OBJECT_H

#include <SFML/Graphics.hpp>

#include "world.h"
#include "worldObject.h"
#include "radarObject.h"
#include "flyingObject.h"
#include "samSiteObject.h"

// Forward Declaration
class RadarObject;
class SAMSiteObject;

enum ThreatLevel {
	LOW = 1,
	MEDIUM = 2,
	HIGH = 3,
	IMMEDIATE = 4
};

struct ProjectileData {
	ProjectileData(FlyingObject* object, sf::Vector2f position) : object{ object }, position{ position }
	{
		// Set ThermalData here

		threatRating = LOW;
	}

	FlyingObject* object;

	sf::Vector2f position;
	sf::Vector2f predictedDirection;

	float estimatedSpeed = 0.f;

	bool beingTargeted = false;

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
	void addSAMSite(float x, float y, World* world);

	void updateProjectileInformation(FlyingObject* flyingObject);

private:
	int numberOfRadars;
	std::vector<RadarObject*> radarArray;
	std::vector<SAMSiteObject*> samArray;;
	std::vector<ProjectileData> observedProjectiles;
};

#endif