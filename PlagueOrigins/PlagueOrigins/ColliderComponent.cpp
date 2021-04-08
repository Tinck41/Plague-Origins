#include "stdafx.h"
#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(b2Body* body)
{
	this->body = body;
}

ColliderComponent::~ColliderComponent()
{
}

sf::Vector2f ColliderComponent::getPosition()
{
	return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}
