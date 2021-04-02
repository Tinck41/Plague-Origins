#pragma once
#include "stdafx.h"

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::RectangleShape& shape, int speed) :
	shape(shape)
{
	this->initialSpeed = speed;
	this->currentSpeed = speed;
}

MovementComponent::~MovementComponent()
{

}

void MovementComponent::move(const float& dt, sf::Vector2f dir)
{
	this->currentSpeed = this->initialSpeed;

	if (dir.x != 0 && dir.y != 0)
	{
		this->currentSpeed /= sqrt(2);
	}
	this->shape.move(sf::Vector2f(dir.x * this->currentSpeed * dt, dir.y * this->currentSpeed * dt));
}
