#ifndef PLANE_OBJECT_H
#define PLANE_OBJECT_H

#define DEFAULT_PLANE_SPEED 50.f

#define PLANE_SIZE 4.f

#define PLANE_SIG_NOISE_MULTIPLIER 5.f

#include <SFML/Graphics.hpp>

#include "flyingObject.h"

class PlaneObject : public FlyingObject 
{
public:

	/*
		@param x X coordinate to place the object
		@param y Y coordinate to place the object
		@param destinationCity Target city for the plane object
	*/
	PlaneObject(float x, float y, CityObject* destinationCity);

	virtual ~PlaneObject();

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

	// Generates a heat signature for the plane object
	std::vector<float> generateSignature();

private:
	static const float baseSignature[];
};

#endif