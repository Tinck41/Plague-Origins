#pragma once
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "Src/Utility/PhysicsWorld.h"


struct Aggresion
{
	Aggresion(b2Body* body, float radius, float angle)
	{
		b2CircleShape aggroShape;
		b2FixtureDef fixtureDef;
		aggroShape.m_radius = radius / 30.f;
		fixtureDef.userData.pointer = ENEMY_AGGRO_RADIUS;
		fixtureDef.shape = &aggroShape;
		fixtureDef.isSensor = true;
		fixtureDef.filter.categoryBits = ENEMY_AGGRO_RADIUS;
		fixtureDef.filter.maskBits = PLAYER;
		body->CreateFixture(&fixtureDef);

		this->radius = radius;
		this->angle = angle;
		distanceToTarget = radius + 1.f;
	}
	float radius;
	float angle;

	bool isAggresive = false;
	sf::Vector2f vectorToTarget;
	float distanceToTarget;
};