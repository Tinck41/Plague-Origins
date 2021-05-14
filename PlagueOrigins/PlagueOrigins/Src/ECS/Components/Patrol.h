#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

struct Patrol
{
	std::vector<sf::Vector2f> waypoints;
	int currentIndex;

	Patrol(std::vector<sf::Vector2f> waypoints)
	{
		this->waypoints = waypoints;
		currentIndex = 0;
	}
};