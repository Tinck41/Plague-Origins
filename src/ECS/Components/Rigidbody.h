#pragma once

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Utility/PhysicsWorld.h"

struct RigidBody
{
	RigidBody(sf::Vector2f size, sf::Vector2f position, bool isDynamic, entt::entity owner, uint16 categoryBits, uint16 maskBits)
	{
		this->size = size;
		shape = new sf::RectangleShape(size);
		shape->setOutlineThickness(2);
		shape->setFillColor(sf::Color::Transparent);
		shape->setOutlineColor(sf::Color::Green);
		shape->setOrigin(size / 2.f);
		body = PhysicsWorld::createRectangleBody(position, size, isDynamic, owner, categoryBits, maskBits);
	}

	RigidBody(float radius, sf::Vector2f position, bool isDynamic, entt::entity owner, uint16 categoryBits, uint16 maskBits)
	{
		this->radius = radius;
		shape = new sf::CircleShape(radius);
		shape->setOutlineThickness(2);
		shape->setFillColor(sf::Color::Transparent);
		shape->setOutlineColor(sf::Color::Green);
		body = PhysicsWorld::createCircleBody(position, radius, isDynamic, owner, categoryBits, maskBits);
	}

	b2Body* body;
	sf::Vector2f size{0.f, 0.f};
	float radius = 0.f;
	bool debugDraw = false;	
	sf::Shape* shape;
};