#ifndef WORLD_OBJECT_FACTORY_H	
#define WORLD_OBJECT_FACTORY_H

#include "cityObject.h"

// I'm still asking myself if a factory is really all that necessary for this project... 
// Keeping it in seems pointless

static WorldObject* createCityObject(float x, float y, int population)
{
	return (WorldObject*)(new CityObject(x, y, population));
}


#endif