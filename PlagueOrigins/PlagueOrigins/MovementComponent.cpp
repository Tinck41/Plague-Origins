#pragma once
#include "stdafx.h"

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::RectangleShape& shape, int speed) :
	shape(shape)
{
	this->initialSpeed = speed;
	roll = false;
	isStateChanged = false;
	state = NONE;
	prevState = NONE;

	currentSpeed = 0;
}

MovementComponent::~MovementComponent()
{

}

void MovementComponent::move(const float& dt, sf::Vector2f dir)
{
	this->currentSpeed = this->initialSpeed;

	if (dir.y == -1 && dir.x == 0)
	{
		prevState = state;
		state = RUN_UP;
	}
	else if (dir.y == 1 && dir.x == 0)
	{
		prevState = state;
		state = RUN_DOWN;
	}
	if (dir.x == -1)
	{
		prevState = state;
		state = RUN_LEFT;
	}
	else if (dir.x == 1)
	{
		prevState = state;
		state = RUN_RIGHT;
	}
	if (dir.x == 0 && dir.y == 0)
	{
		prevState = state;
		state = IDLE;
	}

	if (dir.x != 0 && dir.y != 0)
	{
		currentSpeed /= sqrt(2);
	}

	this->shape.move(sf::Vector2f(dir.x * this->currentSpeed * dt, dir.y * this->currentSpeed * dt));
}

void MovementComponent::update(const float& dt)
{

}

int MovementComponent::getState()
{
	return this->state;
}

sf::Vector2f MovementComponent::getPos()
{
	return this->shape.getPosition();
}

bool MovementComponent::stateChanged()
{
	return prevState != state;
}
