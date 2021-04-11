#include "stdafx.h"
#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(b2Body* body, sf::Vector2f size)
{
	this->body = body;
	this->size = size;
}

ColliderComponent::~ColliderComponent()
{
}

sf::Vector2f ColliderComponent::getPosition()
{
	return sf::Vector2f(body->GetPosition().x * 30.f - size.x / 2.f, body->GetPosition().y * 30.f - size.x / 2.f);
}
