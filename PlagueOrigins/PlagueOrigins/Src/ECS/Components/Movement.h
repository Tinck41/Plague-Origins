#pragma once
#include "SFML/Graphics.hpp"

struct Movement
{
	Movement(float speed)
	{
		this->speed = speed;
	}

	sf::Vector2f direction;
	float speed;
};