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
    uint32_t velocityIterations = 6;
    uint32_t positionIterations = 2;

    world->Step(dt, velocityIterations, positionIterations);

    for (b2Body* body = world->GetBodyList(); body; body = body->GetNext())
    {
        body->SetLinearVelocity(b2Vec2(0.f, 0.f));
    }
}

b2Body* PhysicsWorld::createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic, entt::entity owner, uint16 categoryBits)
{
    return get().createRectangleBodyInternal(position, size, isDynamic, owner, categoryBits);
}

b2Body* PhysicsWorld::createCircleleBody(sf::Vector2f position, float radius, bool isDynamic, entt::entity owner, uint16 categoryBits)
{
    return get().createCircleBodyInternal(position, radius, isDynamic, owner, categoryBits);
}

b2Body* PhysicsWorld::createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic, entt::entity owner, uint16 categoryBits)
{
    b2Body* body;
    b2BodyDef bodyDef;
    b2PolygonShape Shape;
    b2FixtureDef FixtureDef;

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;

    bodyDef.position = b2Vec2((position.x + size.x / 2) / SCALE, (position.y + size.y / 2) / SCALE);
    bodyDef.fixedRotation = true;
    bodyDef.userData.pointer = (uint16)owner;
    body = world->CreateBody(&bodyDef);

    Shape.SetAsBox((size.x / 2) / SCALE, (size.y / 2) / SCALE);
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;

    FixtureDef.filter.categoryBits = categoryBits;  // I'm <...> 
    //FixtureDef.filter.maskBits = maskBits;          // I collide with <...>

    body->CreateFixture(&FixtureDef);

    return body;
}

b2Body* PhysicsWorld::createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic, entt::entity owner, uint16 categoryBits)
{
    b2Body* body;
    b2BodyDef bodyDef;
    b2CircleShape Shape;
    b2FixtureDef FixtureDef;

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;

    bodyDef.position = b2Vec2((position.x + radius / 2) / SCALE, (position.y + radius / 2) / SCALE);
    bodyDef.fixedRotation = true;
    bodyDef.userData.pointer = (uint16)owner;
    body = world->CreateBody(&bodyDef);

    Shape.m_radius = radius;
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;

    //FixtureDef.filter.categoryBits = categoryBits;  // I'm <...> 
    //FixtureDef.filter.maskBits = maskBits;          // I collide with <...>

    body->CreateFixture(&FixtureDef);

    return body;
}