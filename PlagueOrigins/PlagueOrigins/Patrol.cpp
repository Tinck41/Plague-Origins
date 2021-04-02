#include "stdafx.h"
#include "Patrol.h"

Patrol::Patrol(sf::RectangleShape& shape) : shape(shape)
{
	direction = { 0.f, 0.f };
}

ptrl Patrol::findRoute(sf::Vector2f dest, int& pointN)
{
	sf::Vector2f currentPos = shape.getPosition();
	animationName an;

	if (currentPos.x < dest.x)
		direction.x = 1.0f;
	else if (currentPos.x > dest.x)
		direction.x = -1.0f;
	if (currentPos.y < dest.y)
		direction.y = 1.0f;
	else if (currentPos.y > dest.y)
		direction.y = -1.0f;

	if (direction.x != 0 || direction.y != 0)
	{
		an = animationName::MOVE;
	}

	//if patrol point is done
	if ((currentPos.x >= dest.x - 5.0f && currentPos.x <= dest.x + 5.0f) && (currentPos.y >= dest.y - 5.0f && currentPos.y <= dest.y + 5.0f))
		pointN++;
	if (pointN > 1)
		pointN = 0;

	return { direction, an };
}
