#pragma once
#include "SFML/Graphics.hpp"
#include <list>

struct Patrol
{
	std::list<sf::Vector2f> waypoints;
	sf::Vector2f currentWaypoint;
	int currentIndex;

	Patrol(std::list<sf::Vector2f> waypoints)
	{
		this->waypoints = waypoints;
		currentWaypoint = waypoints.front();
		currentIndex = 0;
	}
};