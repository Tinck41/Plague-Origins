#pragma once

#include <vector>
#include "box2d/box2d.h"

#define DEGTORAD 3.14 / 180

struct Attack
{
	Attack(b2Body* body, float damage, float radius)
	{
        for (int k = 0; k < 19; k += 3)
        {
            b2PolygonShape polygonShape;
            b2FixtureDef myFixtureDef;
            float radius = 100 / 30.f;;
            b2Vec2 vertices[8];
            vertices[0].Set(0, 0);

            for (int i = k; i < k + 7; i++)
            {
                float angle = i / 6.0 * 90 * DEGTORAD;
                vertices[i + 1 - k].Set(radius * cosf(angle), radius * sinf(angle));
            }
            polygonShape.Set(vertices, 8);
            myFixtureDef.shape = &polygonShape;
            myFixtureDef.isSensor = true;
            body->CreateFixture(&myFixtureDef);
        }

		this->damage = damage;
		this->radius = radius;
	}

	float radius;
	float damage;
	bool isAttacking = false;
};