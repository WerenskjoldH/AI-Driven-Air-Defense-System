#include "cityObject.h"

CityObject::CityObject(float x, float y, int population) : WorldObject("CityObject", sf::Vector2f(x, y))
{
	this->boundaryRadius = RADIUS_MIN + RADIUS_MAX * (population / POPULATION_MAX);

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
	circle.setFillColor(sf::Color(80, 80, 80, 255));
	circle.setPosition(position);

	window->draw(circle);
}
