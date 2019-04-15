#include "cityObject.h"

CityObject::CityObject(float x, float y, int population) : WorldObject("CityObject", sf::Vector2f(x, y))
{
	this->boundaryRadius = RADIUS_MIN + RADIUS_INCREASE_MAX * (population / POPULATION_MAX);

	this->population = population;

	// Need to rerun this code since WorldObject takes 0 for radius
	this->position.x -= boundaryRadius;
	this->position.y -= boundaryRadius;
}

CityObject::~CityObject()
{}

void CityObject::initialization()
{
}

void CityObject::update(World * world, float dt)
{
}

void CityObject::draw(sf::RenderWindow * window)
{
	sf::CircleShape circle(boundaryRadius);
	circle.setFillColor(sf::Color(0, 0, 0, 255));
	circle.setPosition(position);

	window->draw(circle);
}
