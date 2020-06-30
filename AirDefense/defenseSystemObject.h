#ifndef DEFENSE_SYSTEM_OBJECT_H
#define DEFENSE_SYSTEM_OBJECT_H

#include <SFML/Graphics.hpp>

#include "world.h"
#include "worldObject.h"
#include "radarObject.h"
#include "flyingObject.h"
#include "samSiteObject.h"
#include "agent.h"

// Forward Declaration
class RadarObject;
class SAMSiteObject;

// Threat levels
enum ThreatLevel {
	LOW = 1,
	MEDIUM = 2,
	HIGH = 3,
	IMMEDIATE = 4
};

#define CLASS_TO_THREAT(x) \
	(x < 0.33f) ? LOW : \
	(x < 0.66f) ? MEDIUM : \
	(x < 0.90f) ? HIGH : \
	IMMEDIATE

// Contains all information on tracked projecticles
struct ProjectileData {
	ProjectileData(FlyingObject* object, sf::Vector2f position) : object{ object }, position{ position }
	{
		signature = object->generateSignature();
		classPrediction = IntelligentAgent::predict(signature);
		threatRating = CLASS_TO_THREAT(classPrediction);
	}

	FlyingObject* object;

	sf::Vector2f position;
	sf::Vector2f predictedDirection;

	float estimatedSpeed = 0.f;

	bool beingTargeted = false;

	ThreatLevel threatRating;
	std::vector<float> signature;
	float classPrediction = 0.f;
};

// Manages its own defense system
class DefenseSystemObject : public WorldObject
{
public:

	DefenseSystemObject();

	virtual ~DefenseSystemObject();

	/*
		Contains all update logic
		@param window The RenderWindow we will be referencing, do NOT put draw calls here
		@param dt the delta time between frames -- this can be static or dynamic
	*/
	void update(World* world, float dt);

	/*
		Contains all rendering logic
		@param window The RenderWindow that we will be drawing to
	*/
	void draw(sf::RenderWindow* window);

	/*
		Creates a radar object and adds it to the world object manager
		@param x X coordinate to place Radar
		@param y Y coordinate to place Radar
	*/
	void addRadar(float x, float y, World* world);

	/*
		Creates a SAM object and adds it to the world object manager
		@param x X coordinate to place SAM
		@param y Y coordinate to place SAM
	*/
	void addSAMSite(float x, float y, World* world);

	/*
		Updates information logged on flying object observed by Radar
		@param flyingObject The object being logged/updated
	*/
	void updateProjectileInformation(FlyingObject* flyingObject);

private:
	int numberOfRadars;
	std::vector<RadarObject*> radarArray;
	std::vector<SAMSiteObject*> samArray;;
	std::vector<ProjectileData> observedProjectiles;
};

#endif