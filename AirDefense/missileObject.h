#ifndef PROJECTILE_OBJECT_H
#define PROJECTILE_OBJECT_H

#define DEFAULT_MISSILE_SIZE 3.f

#define DEFAULT_MISSILE_SPEED 100.f

#define MISSILE_SIG_NOISE_MULTIPLIER 2.5f

#include "projectileSpawnerObject.h"
#include "flyingObject.h"

class MissileObject : public FlyingObject
{
public:
	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
		@param target Target city for the missile object
	*/
	MissileObject(float x, float y, CityObject* target);

	virtual ~MissileObject();

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

	// Set the spawner reference equal to s
	void setSpawner(ProjectileSpawnerObject* s);

	// Generates the heat signature
	std::vector<float> generateSignature();

private:
	ProjectileSpawnerObject* spawner;

	static const float baseSignature[];
};

#endif