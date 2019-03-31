#ifndef VECTOR_UTILITY_H
#define VECTOR_UTILITY_H

#include <SFML/Graphics.hpp>

namespace vu
{
	inline static float dot(const sf::Vector2f &vec1, const sf::Vector2f &vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	inline static float magnitude(const sf::Vector2f &vec)
	{
		return std::sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	inline static sf::Vector2f invert(const sf::Vector2f &vec)
	{
		return sf::Vector2f(-1.f * vec.x, -1.f * vec.y);
	}

	inline static sf::Vector2f unit(const sf::Vector2f &vec)
	{
		return sf::Vector2f(vec / magnitude(vec));
	}

	inline static sf::Vector2f clockwisePerpendicular(const sf::Vector2f &vec)
	{
		return sf::Vector2f(vec.y, -vec.x);
	}

	inline static sf::Vector2f cclockwisePerpendicular(const sf::Vector2f &vec)
	{
		return sf::Vector2f(-vec.y, vec.x);
	}
}

#endif