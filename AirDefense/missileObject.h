#ifndef PROJECTILE_OBJECT_H
#define PROJECTILE_OBJECT_H

#define DEFAULT_MISSILE_SIZE 3.f
#define DEFAULT_MISSILE_SPEED 100.f

#include "projectileSpawnerObject.h"
#include "flyingObject.h"

class MissileObject : public FlyingObject
{
public:
	MissileObject(float x, float y, CityObject* target);

	virtual ~MissileObject();

	void update(World* world, float dt);

	void draw(sf::RenderWindow* window);

	void setSpawner(ProjectileSpawnerObject* s);

private:
	ProjectileSpawnerObject* spawner;
};

#endif