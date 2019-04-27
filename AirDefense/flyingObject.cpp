#include "flyingObject.h"

FlyingObject::FlyingObject(float x, float y, float size, const char* objectType, CityObject * targetCity) : WorldObject("FlyingObject", sf::Vector2f(x, y), size)
{
	this->targetCity = targetCity;

	this->subObjectType = (char*)objectType;
}

FlyingObject::~FlyingObject()
{
}

const char * FlyingObject::getSubObjectType()
{
	return subObjectType;
}

const bool FlyingObject::getReachedDestination()
{
	return reachedDestination;
}

void FlyingObject::setReachedDestination(bool tf)
{
	if (tf)
	{
		circle.setRadius(0.f);
	}
	reachedDestination = tf;
}

const bool FlyingObject::getDestroyed()
{
	return destroyed;
}

void FlyingObject::destroyObject()
{
	destroyed = true;
}

void FlyingObject::allowDeletion()
{
	this->setObjectDead();
}

const float FlyingObject::sigMean[] = {
	7.5,	8.5,	15.,	15.,	10.5,	6.5,	23.,	40.,	71.,	70.,
	23.,	10.,	13.5,	8.5,	7.,		4.5,	3.5,	11.5,	104.5,	216.5,
	207.5,	71.5,	26.5,	17.5,	13.,	13.,	15.,	21.5,	26.,	26.,	23.
};

const float FlyingObject::sigStd[] = {
	7.63714036,		8.59775931,		15.03456633,	14.099007,		10.61373549,	6.65733318,
	22.06264052,	28.04310783,	49.01390016,	35.04026409,	17.06712655,	8.12155314,
	11.60480612,	7.62420275,		7.12963326,		4.71247914,		3.77771338,		5.68604957,
	57.49803736,	113.49978682,	117.4964847,	49.50044225,	10.60131192,	2.86921898,
	3.32108786,		4.23964203,		2.45689822,		3.76453141,		7.14625131,		11.09850496,  12.08093419
};