#pragma once
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Src/Utility/PhysicsWorld.h"


struct Aggresion
{
	Aggresion(float radius, sf::Vector2f position, bool isDynamic, entt::entity owner, uint16 categoryBits)
	{
		this->radius = radius;
		shape = new sf::CircleShape(radius);
		shape->setOutlineThickness(2);
		shape->setFillColor(sf::Color::Transparent);
		shape->setOutlineColor(sf::Color::Green);
		body = PhysicsWorld::createCircleleBody(position, radius, isDynamic, owner, categoryBits);
	}

	b2Body* body;
	sf::Vector2f size{ 0.f, 0.f };
	float radius = 0.f;
	bool debugDraw = false;
	sf::Shape* shape;

	bool isAggresive = false;
};