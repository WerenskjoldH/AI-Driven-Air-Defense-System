#include "missileObject.h"

MissileObject::MissileObject(float x, float y, CityObject * target) : FlyingObject(x, y, DEFAULT_MISSILE_SIZE, "MissileObject", target)
{
	circle.setRadius(boundaryRadius);
	circle.setOrigin(sf::Vector2f(boundaryRadius, boundaryRadius));
	circle.setFillColor(sf::Color(150, 0, 60, 255));

	speed = DEFAULT_MISSILE_SPEED;

	direction = vu::unit(target->getPosition() - sf::Vector2f(x,y));
}

MissileObject::~MissileObject()
{

}

void MissileObject::update(World * world, float dt)
{
	position += speed * direction * dt;

	if (intersects((WorldObject*)targetCity))
	{
		if (!targetCity->isDestroyed())
		{
			spawner->incrementDestroyedCities();

			// Destroy the city, if it is not destroyed yet
			targetCity->destroyCity();
		}

		// Destroy this missile
		//this->setObjectDead();
		setReachedDestination(true);
	}
}

void MissileObject::draw(sf::RenderWindow * window)
{
	circle.setPosition(position);
	window->draw(circle);
}

void MissileObject::setSpawner(ProjectileSpawnerObject* s)
{
	spawner = s;
}

const float MissileObject::baseSignature[] = {
	15.,	17.,	30.,	29.,	21.,	13.,	45.,	68.,	120.,	105.,
	40.,	18.,	25.,	16.,	14.,	9.,		7.,		7.,		47.,	380.,
	325.,	121.,	38.,	20.,	16.,	17.,	17.,	18.,	19.,	15.,	11.
};

std::vector<float> MissileObject::generateSignature()
{
	std::vector<float> sig;

	int c = sizeof(baseSignature) / sizeof(*baseSignature);

	for (int i = 0; i < c; i++)
	{
		float noisy = baseSignature[i] + MISSILE_SIG_NOISE_MULTIPLIER * ((rand() - rand()) / (float)INT_MAX);
		float normalized = (noisy - sigMean[i]) / sigStd[i];
		sig.push_back(normalized);
	}

	return sig;
}