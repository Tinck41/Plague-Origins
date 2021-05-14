#pragma once
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Src/Utility/PhysicsWorld.h"


struct Aggresion
{
	Aggresion(b2Body* body, float radius)
	{
		b2CircleShape attackShape;
		b2FixtureDef fixtureDef;
		attackShape.m_radius = radius / 30.f;
		fixtureDef.userData.pointer = ENEMY_AGGRO_RADIUS;
		fixtureDef.shape = &attackShape;
		fixtureDef.isSensor = true;
		body->CreateFixture(&fixtureDef);

		this->radius = radius;
	}
	float radius;

	bool isAggresive = false;
	sf::Vector2f vectorToTarget;
};