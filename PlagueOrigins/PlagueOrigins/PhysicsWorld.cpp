#include "stdafx.h"
#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
{
    b2Vec2 gravity(0.f, 0.f);
    world = new b2World(gravity);
    world->SetContactListener(&contactListener);
}

PhysicsWorld::~PhysicsWorld()
{
}

void PhysicsWorld::updateInternal(const float& dt)
{
    world->Step(dt, 6, 2);
}

b2Body* PhysicsWorld::createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic)
{
    return get().createRectangleBodyInternal(position, size, isDynamic);
}

b2Body* PhysicsWorld::createCircleleBody(sf::Vector2f position, float radius, bool isDynamic)
{
    return get().createCircleBodyInternal(position, radius, isDynamic);
}

b2Body* PhysicsWorld::createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic)
{
    b2Body* body;
    b2BodyDef bodyDef;
    b2PolygonShape Shape;
    b2FixtureDef FixtureDef;

    if (isDynamic)
    {
        bodyDef.type = b2_dynamicBody;
    }
    else
    {
        bodyDef.type = b2_staticBody;
    }

    bodyDef.position = b2Vec2(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = world->CreateBody(&bodyDef);

    Shape.SetAsBox(size.x / 2, size.y / 2);
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;
    body->CreateFixture(&FixtureDef);
	
    return body;
}

b2Body* PhysicsWorld::createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic)
{
    b2Body* body;
    b2BodyDef bodyDef;
    b2CircleShape Shape;
    b2FixtureDef FixtureDef;

    if (isDynamic)
    {
        bodyDef.type = b2_dynamicBody;
    }
    else
    {
        bodyDef.type = b2_staticBody;
    }

    bodyDef.position = b2Vec2(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = world->CreateBody(&bodyDef);

    Shape.m_radius = radius;
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;
    body->CreateFixture(&FixtureDef);

    return body;
}
