#pragma once

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

struct CircleCollider
{
	CircleCollider(float radius, bool isSensor, uint16 categoryBits, uint16 maskBits)
	{
		this->radius = radius;

		b2CircleShape Shape;
		Shape.m_radius = radius / 30.f;
		FixtureDef.shape = &Shape;
		FixtureDef.density = 1.f;
		FixtureDef.friction = 0.f;
		FixtureDef.restitution = 0.f;
		FixtureDef.isSensor = isSensor;
		FixtureDef.filter.categoryBits = categoryBits;
		FixtureDef.filter.maskBits = maskBits;
	}

	b2FixtureDef FixtureDef;
	float radius;
};