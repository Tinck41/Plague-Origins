#pragma once

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Src/Utility/PhysicsWorld.h"

struct RigidBody
{
	RigidBody(sf::Vector2f size, sf::Vector2f position, bool isDynamic, entt::entity owner)
	{
		this->size = size;
		body = PhysicsWorld::createRectangleBody(position, size, isDynamic, owner);
	}

	RigidBody(float radius, sf::Vector2f position, bool isDynamic, entt::entity owner)
	{
		this->radius = radius;
		body = PhysicsWorld::createCircleleBody(position, radius, isDynamic, owner);
	}

	RigidBody(b2Body* body)
	{
		this->body = body;
	}

	b2Body* body;
	sf::Vector2f size;
	float radius;
};