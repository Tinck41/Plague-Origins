#include "stdafx.h"
#include "Patrol.h"

Patrol::Patrol(sf::RectangleShape& shape, std::vector<sf::Vector2f> waypoints) : shape(shape)
{
	direction = { 0.f, 0.f };
	this->waypoints = waypoints;
	pointN = 1;
	N = waypoints.size();
}

void Patrol::update()
{
	patrolRoute(waypoints[pointN]);
}

sf::Vector2f Patrol::patrolRoute(sf::Vector2f dest)
{
	sf::Vector2f currentPos = shape.getPosition();

	if (currentPos.x < dest.x)
		direction.x = 1.0f;
	else if (currentPos.x > dest.x)
		direction.x = -1.0f;
	if (currentPos.y < dest.y)
		direction.y = 1.0f;
	else if (currentPos.y > dest.y)
		direction.y = -1.0f;

	//if patrol point is done
	if ((currentPos.x >= dest.x - 5.0f && currentPos.x <= dest.x + 5.0f) && (currentPos.y >= dest.y - 5.0f && currentPos.y <= dest.y + 5.0f))
		pointN++;
	if (pointN >= N)
		pointN = 0;

	return direction;
}

sf::Vector2f Patrol::directRoute(sf::Vector2f dest)
{
	sf::Vector2f currentPos = shape.getPosition();

	if (currentPos.x < dest.x)
		direction.x = 1.0f;
	else if (currentPos.x > dest.x)
		direction.x = -1.0f;
	if (currentPos.y < dest.y)
		direction.y = 1.0f;
	else if (currentPos.y > dest.y)
		direction.y = -1.0f;

	return direction;
}
