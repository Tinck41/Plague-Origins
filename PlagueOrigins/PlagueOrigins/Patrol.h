#pragma once
#include "PlayerAnimationStates.h"

class Patrol
{
private:
	sf::RectangleShape& shape;
	sf::Vector2f direction;
	std::vector<sf::Vector2f> waypoints;
	int pointN;
	int N;

public:
	bool aggro;
	Patrol(sf::RectangleShape& shape, std::vector<sf::Vector2f> waypoints);

	void update();

	void patrolRoute(sf::Vector2f dest);
	void directRoute(sf::Vector2f dest);
	sf::Vector2f getDirection() { return direction; }
};

