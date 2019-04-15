#ifndef WORLD_OBJECT_FACTORY_H	
#define WORLD_OBJECT_FACTORY_H

#include "cityObject.h"

static WorldObject* createCityObject(float x, float y, int population)
{
	return (WorldObject*)(new CityObject(x, y, population));
}


#endif