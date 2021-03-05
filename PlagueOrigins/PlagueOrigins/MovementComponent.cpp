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
}

MovementComponent::~MovementComponent()
{

}

void MovementComponent::move(const float& dt, sf::Vector2f dir)
{
	this->speed = this->initialSpeed;

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
		speed /= sqrt(2);
	}

	this->shape.move(sf::Vector2f(dir.x * this->speed * dt, dir.y * this->speed * dt));
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
