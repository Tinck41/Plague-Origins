#include "stdafx.h"

#include "Unit.h"

Unit::Unit()
{
	initVariables();
	//spawnUnit();
}

void Unit::spawnUnit()
{
	//create shape
	shape.setPosition(10.f, 10.f);
	shape.setSize(sf::Vector2f(100.0f, 100.0f));
	shape.setScale(sf::Vector2f(0.5f, 0.5f));
	shape.setFillColor(sf::Color::Green);
}

void Unit::initVariables()
{
	//this->movementComponent = NULL;
	//this->animationComponent = NULL;
}

void Unit::createMovementComponent(sf::RectangleShape& shape,int speed)
{
	//create movement component based on shape
	this->movementComponent = new MovementComponent(shape, speed);
}

void Unit::createColliderComponent(sf::RectangleShape& shape)
{
	this->colliderComponent = new ColliderComponent(shape);
}

void Unit::update(const float& dt)
{
}

void Unit::render(sf::RenderWindow* window)
{
}

void Unit::createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory* zf, std::string prefix)
{
	this->animationComponent = new AnimationComponent(shape, zf, prefix);
}
