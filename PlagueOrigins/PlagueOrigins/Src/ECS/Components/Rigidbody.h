#pragma once

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Src/Utility/PhysicsWorld.h"

struct RigidBody
{
	RigidBody(sf::Vector2f size, sf::Vector2f position, bool isDynamic, entt::entity owner)
	{
		this->size = size;
		radius = size.x > size.y ? size.x : size.y;
		body = PhysicsWorld::createRectangleBody(position, size, isDynamic, owner);
	}

	RigidBody(float radius, sf::Vector2f position, bool isDynamic, entt::entity owner)
	{
		this->radius = radius;
		size.x = radius;
		size.y = radius;
		body = PhysicsWorld::createCircleleBody(position, radius, isDynamic, owner);
	}

	b2Body* body;
	sf::Vector2f size;
	float radius;
};