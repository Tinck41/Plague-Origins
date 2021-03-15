#include "stdafx.h"
#include "NPC.h"

NPC::NPC(float x, float y)
{
	initVariables();
	createHitbox(x, y);
	fillWaypoints();
	createMovementComponent(this->shape, this->speed);
	createColliderComponent(this->shape);

}

void NPC::fillWaypoints()
{
	this->waypoints.push_back(this->point0);
	this->waypoints.push_back(this->point1);
	//this->waypoints.push_back(this->point2);
	//this->waypoints.push_back(this->point3);
}

sf::Vector2f NPC::getWaypoint(int pointN)
{
	switch (pointN)
	{
	case 0:
		return this->waypoints[0];
	case 1:
		return this->waypoints[1];
	case 2:
		return this->waypoints[2];
	case 3:
		return this->waypoints[3];
	}

	return sf::Vector2f();
}

void NPC::initVariables()
{
	this->pointN = 0;
	this->direction = { 0.0f, 0.0f };
	this->speed = 300;
	this->scale = 0.2f;
}

void NPC::createHitbox(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(100.0f, 150.0f));
	shape.setFillColor(sf::Color::Red);
}
/*
	dumb algorithm to find direction to point
*/
void NPC::pathBuild(sf::Vector2f v)
{
	sf::Vector2f currentPos = this->getPosition();// +sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2);

	if (currentPos.x < v.x)
		this->direction.x = 1;
	else if (currentPos.x > v.x)
		this->direction.x = -1;
	if (currentPos.y < v.y)
		this->direction.y = 1;
	else if (currentPos.y > v.y)
		this->direction.y = -1;

	//if patrol point is done
	if ((currentPos.x >= v.x - 3.0f && currentPos.x <= v.x + 3.0f) && (currentPos.y >= v.y - 3.0f && currentPos.y <= v.y + 3.0f))
		this->pointN++;
	if (pointN > 1)
		pointN = 0;
}

void NPC::update(const float& dt)
{
	std::cout << this->shape.getPosition().x << " " << this->shape.getPosition().y << std::endl;
	//get direction
	this->pathBuild(this->getWaypoint(this->pointN));
	//moving
	this->movementComponent->move(dt, this->direction);
}

void NPC::render(sf::RenderWindow& target)
{
	target.draw(this->shape);
}
