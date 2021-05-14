#pragma once

#include <vector>
#include "box2d/box2d.h"

#define DEGTORAD 3.14f / 180.f

struct Attack
{
	Attack(b2Body* body, float damage, float radius)
	{
        b2CircleShape attackShape;
        b2FixtureDef fixtureDef;
		attackShape.m_radius = radius / 30.f;
		fixtureDef.shape = &attackShape;
		fixtureDef.isSensor = true;
		fixtureDef.userData.pointer = ATTACK_RADIUS;
        body->CreateFixture(&fixtureDef);

		this->damage = damage;
		this->radius = radius;
	}

	float radius;
	float damage;
	bool isAttacking = false;
};