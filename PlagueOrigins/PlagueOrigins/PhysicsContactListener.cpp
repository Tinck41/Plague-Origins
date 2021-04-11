#include "stdafx.h"
#include "PhysicsContactListener.h"

void PhysicsContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
}

void PhysicsContactListener::EndContact(b2Contact* contact)
{
}

void PhysicsContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
}

void PhysicsContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
}
