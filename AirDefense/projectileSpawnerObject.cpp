#include "projectileSpawnerObject.h"

// This is a managing object, we don't need to draw it and therefore we just move it off the screen
ProjectileSpawnerObject::ProjectileSpawnerObject() : WorldObject("ProjectileSpawnerObject", sf::Vector2f(-10.f, -10.f))
{

}

ProjectileSpawnerObject::~ProjectileSpawnerObject()
{

}

void ProjectileSpawnerObject::update(World * world, float dt)
{

}

void ProjectileSpawnerObject::draw(sf::RenderWindow * window)
{

}
