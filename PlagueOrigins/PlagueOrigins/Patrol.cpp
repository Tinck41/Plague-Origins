#include "stdafx.h"
#include "Patrol.h"

Patrol::Patrol(sf::RectangleShape& shape, std::vector<sf::Vector2f> waypoints) : shape(shape)
{
	direction = { 0.f, 0.f };
	this->waypoints = waypoints;
	pointN = 1;
	N = waypoints.size();
	aggro = false;
}

void Patrol::update()
{
	if (!aggro)
		patrolRoute(waypoints[pointN]);
}

void Patrol::patrolRoute(sf::Vector2f dest)
{
	aggro = false;
	sf::Vector2f currentPos = shape.getPosition();

	if (currentPos.x < dest.x - 5.f)
		direction.x = 1.0f;
	else if (currentPos.x > dest.x + 5.f)
		direction.x = -1.0f;
	else if (abs(currentPos.x - dest.x) <= 5.f)
		direction.x = 0.0f;
	if (currentPos.y < dest.y - 5.f)
		direction.y = 1.0f;
	else if (currentPos.y > dest.y + 5.f)
		direction.y = -1.0f;
	else if (abs(currentPos.y - dest.y) <= 5.f)
		direction.y = 0.0f;

	if ((currentPos.x >= dest.x - 5.f && currentPos.x <= dest.x + 5.f) && (currentPos.y >= dest.y - 5.f && currentPos.y <= dest.y + 5.f))
		pointN++;
	if (pointN >= N)
		pointN = 0;
}

void Patrol::directRoute(sf::Vector2f dest)
{
	aggro = true;
	sf::Vector2f currentPos = shape.getPosition();

	if (currentPos.x < dest.x - 5.f)
		direction.x = 1.0f;
	else if (currentPos.x > dest.x + 5.f)
		direction.x = -1.0f;
	else if (abs(currentPos.x - dest.x) <= 5.f)
		direction.x = 0.0f;
	if (currentPos.y < dest.y - 5.f)
		direction.y = 1.0f;
	else if (currentPos.y > dest.y + 5.f)
		direction.y = -1.0f;
	else if (abs(currentPos.y - dest.y) <= 5.f)
		direction.y = 0.0f;

}
