#ifndef WORLD_OBJECT_FACTORY_H	
#define WORLD_OBJECT_FACTORY_H



#include "worldObject.h"

#include "testObject.h"

// Creates a test object at the given coordinates
static WorldObject* createTestObject(float x, float y, float radius)
{
	return (WorldObject*)(new TestObject(x, y, radius));
}


#endif