#pragma once

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

struct RectCollider
{
	RectCollider(sf::Vector2f size, bool isSensor, uint16 categoryBits, uint16 maskBits)
	{
		this->size = size;

		b2PolygonShape Shape;
		Shape.SetAsBox(((size.x / 2.f) / 30.f), ((size.y / 2.f) / 30.f));
		FixtureDef.shape = &Shape;
		FixtureDef.density = 1.f;
		FixtureDef.friction = 0.f;
		FixtureDef.restitution = 0.f;
		FixtureDef.isSensor = isSensor;
		FixtureDef.filter.categoryBits = categoryBits;
		FixtureDef.filter.maskBits = maskBits;
	}

	b2FixtureDef FixtureDef;
	sf::Vector2f size;
};