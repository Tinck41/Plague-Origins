#pragma once
#include "stdafx.h"

#include "MovementComponent.h"

MovementComponent::MovementComponent(b2Body* body, float speed)
{
	this->body = body;
	this->speed = speed;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::move(const float& dt, sf::Vector2f dir)
{
	b2Vec2 direction(dir.x, dir.y);
	direction.Normalize();
	
	body->SetLinearVelocity(dt * speed * direction);
}
