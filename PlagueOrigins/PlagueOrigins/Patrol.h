#pragma once
#include "PlayerAnimationStates.h"

struct ptrl
{
	sf::Vector2f direction;
	animationName animationName;
};

class Patrol
{
private:
	sf::RectangleShape& shape;
	sf::Vector2f direction;

public:
	Patrol(sf::RectangleShape& shape);

	ptrl findRoute(sf::Vector2f dest, int& pointN);
	sf::Vector2f getDirection() { return direction; }
};

