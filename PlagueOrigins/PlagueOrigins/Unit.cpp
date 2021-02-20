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
	this->movementComponent = NULL;
}

void Unit::createMovementComponent(sf::RectangleShape& shape,int speed)
{
	//create movement component based on shape
	this->movementComponent = new MovementComponent(shape, speed);
}

//void Unit::update(const float& dt)
//{
//	this->movementComponent->update(dt);
//}
//
//void Unit::render(sf::RenderTarget* target)
//{
//	target->draw(shape);
//}
