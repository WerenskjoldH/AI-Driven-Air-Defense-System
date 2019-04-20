#include "cityObject.h"

CityObject::CityObject(float x, float y, int population) : WorldObject("CityObject", sf::Vector2f(x, y))
{
	this->boundaryRadius = RADIUS_MIN + RADIUS_INCREASE_MAX * (population / POPULATION_MAX);

	this->population = population;

	// Need to rerun this code since WorldObject takes 0 for radius
	this->position.x -= boundaryRadius;
	this->position.y -= boundaryRadius;

	circle.setRadius(boundaryRadius);
	circle.setFillColor(sf::Color(0, 0, 0, 255));
	circle.setPosition(position);
}

CityObject::~CityObject()
{}

int CityObject::getPopulation() const
{
	return population;
}

void CityObject::update(World * world, float dt)
{
}

void CityObject::draw(sf::RenderWindow * window)
{
	window->draw(circle);
}
