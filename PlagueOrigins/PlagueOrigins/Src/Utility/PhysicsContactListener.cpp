#include "stdafx.h"

#include "PhysicsContactListener.h"

void PhysicsContactListener::BeginContact(b2Contact* contact)
{
    // Exmaple
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    //std::cout << fixtureA->GetUserData().pointer << " fixA\n";
    //std::cout << fixtureB->GetUserData().pointer << " fixB\n";

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    if (bodyA == nullptr && bodyB == nullptr) return;

    //if (fixtureA->GetUserData().pointer == OBSTACLE &&
    //    fixtureB->GetUserData().pointer == PLAYER)
    //{
    //    std::cout << "start. player - obstacle\n";
    //}
    //else if (fixtureA->GetUserData().pointer == ENEMY_AGGRO_RADIUS &&
    //    fixtureB->GetUserData().pointer == PLAYER)
    //{
    //    std::cout << "start. player - aggro\n";
    //}
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

    //if (fixtureA->GetUserData().pointer == OBSTACLE &&
    //    fixtureB->GetUserData().pointer == PLAYER)
    //{
    //    std::cout << "end. player - obstacle\n";
    //}
}

void PhysicsContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    // Same as previous
}

void PhysicsContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
    // Same as previous
}