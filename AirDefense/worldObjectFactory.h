#ifndef WORLD_OBJECT_FACTORY_H	
#define WORLD_OBJECT_FACTORY_H

#include <SFML/Graphics.hpp>

#include "worldObject.h"

#include "testObject.h"

// Creates a 
static WorldObject* createTestObject(float x, float y)
{
	return (WorldObject*)(new TestObject(x, y));
}


#endif