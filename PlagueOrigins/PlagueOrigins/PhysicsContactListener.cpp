#include "stdafx.h"
#include "PhysicsContactListener.h"
#include "RayCastClosestCallback.h"

void PhysicsContactListener::BeginContact(b2Contact* contact)
{
    // Exmaple
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    if (bodyA == nullptr && bodyB == nullptr) return;

    if (bodyA->GetUserData().pointer == PLAYER &&
        bodyB->GetUserData().pointer == OBSTACLE)
    {
        std::cout << "It's the beginning of collision between PLAYER and OBSTACLE" << "\n";
    }

    if (bodyA->GetUserData().pointer == PLAYER &&
        bodyB->GetUserData().pointer == ATTACK_RADIUS)
    {
        std::cout << "It's the beginning of collision between PLAYER and ATTACK_RADIUS" << "\n";
    }

    if (bodyA->GetUserData().pointer == PLAYER &&
        fixtureB->GetUserData().pointer == ENEMY_AGGRO_RADIUS)
    {
        std::cout << "AGGRO START BOX2D\n";
        //PhysicsWorld& phWorld = PhysicsWorld::get();
        //b2World* world = phWorld.getWorld();
        //RayCastClosestCallback callback;
        //world->RayCast(&callback, bodyB->GetTransform().p, bodyA->GetTransform().p);
        //if (callback.m_hit)
        //{
        //    phWorld.setRange(true);
        //}
    }


    // It's gonna be a lot of "if" statements here...
}


void PhysicsContactListener::EndContact(b2Contact* contact)
{
    // Exmaple
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    if (bodyA == nullptr && bodyB == nullptr) return;

    if (bodyA->GetUserData().pointer == PLAYER &&
        bodyB->GetUserData().pointer == OBSTACLE)
    {
        std::cout << "It's the end of collision between PLAYER and OBSTACLE" << "\n";
    }

    if (bodyA->GetUserData().pointer == PLAYER &&
        bodyB->GetUserData().pointer == ATTACK_RADIUS)
    {
        std::cout << "It's the end of collision between PLAYER and ATTACK_RADIUS" << "\n";
    }

    if (bodyA->GetUserData().pointer == PLAYER &&
        fixtureB->GetUserData().pointer == ENEMY_AGGRO_RADIUS)
    {
        std::cout << "AGGRO END BOX2D\n";
        //PhysicsWorld& phWorld = PhysicsWorld::get();
        //b2World* world = phWorld.getWorld();
        //RayCastClosestCallback callback;
        //world->RayCast(&callback, bodyB->GetTransform().p, bodyA->GetTransform().p);
        //if (callback.m_hit)
        //{
        //    phWorld.setRange(false);
        //}
    }
}

void PhysicsContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    if (bodyA == nullptr && bodyB == nullptr) return;
    // Same as previous
    if (bodyA->GetUserData().pointer == PLAYER &&
        bodyB->GetUserData().pointer == OBSTACLE)
    {
        std::cout << "It's the end of collision between PLAYER and OBSTACLE" << "\n";
    }
}

void PhysicsContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
    // Same as previous
}
