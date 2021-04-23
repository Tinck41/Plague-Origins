#include "stdafx.h"
#include "PhysicsWorld.h"
#include "EntityCategory.h"
#include "RayCastClosestCallback.h"

PhysicsWorld::PhysicsWorld()
{
    b2Vec2 gravity(0.f, 0.f);
    world = new b2World(gravity);
    world->SetContactListener(&contactListener);

    ////////
    int n = 5;
    aggro = new bool[n];
    for (int i = 0; i < n; i++)
    {
        aggro[i] = false;
    }
    ////////
}

PhysicsWorld::~PhysicsWorld()
{
    
}

void PhysicsWorld::reRaycast()
{
    for (ag s : get().enemies)
    {
        RayCastClosestCallback callback;
        world->RayCast(&callback, s.body->GetTransform().p, player->GetTransform().p);
        if (callback.m_hit)
        {
            //PhysicsWorld::setRange(true);
            //enemies.remove(s);
            std::cout << "RAYCAST TRUE\n";
        }
        else
        {
            std::cout << "RAYCAST FALSE\n";
        }
    }
}

void PhysicsWorld::pushBody(b2Body* body, bool value)
{
    get().enemies.push_back({ body,value });
}

void PhysicsWorld::updateInternal(const float& dt)
{
    uint32_t velocityIterations = 6;
    uint32_t positionIterations = 2;

    reRaycast();

    world->Step(dt, velocityIterations, positionIterations);


    for (b2Body* body = world->GetBodyList(); body; body = body->GetNext())
    {
        body->SetLinearVelocity(b2Vec2(0.f, 0.f));
    }
}

b2Body* PhysicsWorld::createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits)
{
    return get().createRectangleBodyInternal(position, size, isDynamic, categoryBits, maskBits);
}

b2Body* PhysicsWorld::createCircleBody(sf::Vector2f position, float radius, bool isDynamic, bool isSensor, uint16 categoryBits, uint16 maskBits)
{
    return get().createCircleBodyInternal(position, radius, isDynamic, isSensor, categoryBits, maskBits);
}

b2Body* PhysicsWorld::createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits)
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
    
    bodyDef.position = b2Vec2((position.x + size.x / 2) / SCALE, (position.y + size.y / 2) / SCALE);
    bodyDef.fixedRotation = true;
    bodyDef.userData.pointer = categoryBits;        // Identifier for collision checking
    body = world->CreateBody(&bodyDef);

    Shape.SetAsBox((size.x / 2) / SCALE, (size.y / 2) / SCALE);
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;

    FixtureDef.filter.categoryBits = categoryBits;  // I'm <...> 
    FixtureDef.filter.maskBits = maskBits;          // I collide with <...>

    body->CreateFixture(&FixtureDef);
	
    return body;
}

b2Body* PhysicsWorld::createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic, bool isSensor, uint16 categoryBits, uint16 maskBits)
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

    FixtureDef.isSensor = isSensor;

    if (isSensor)
    {
        FixtureDef.userData.pointer = categoryBits;
    }

    bodyDef.position = b2Vec2((position.x + radius / 2) / SCALE, (position.y + radius / 2) / SCALE);
    bodyDef.fixedRotation = true;
    body = world->CreateBody(&bodyDef);

    Shape.m_radius = radius / SCALE;
    FixtureDef.shape = &Shape;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.f;
    FixtureDef.restitution = 0.f;

    FixtureDef.filter.categoryBits = categoryBits; // I'm <...> 
    FixtureDef.filter.maskBits = maskBits; // I collide with <...>

    body->CreateFixture(&FixtureDef);

    return body;
}
