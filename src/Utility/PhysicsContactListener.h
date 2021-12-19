#pragma once

#include "box2d/box2d.h"

class PhysicsContactListener :
    public b2ContactListener
{
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
    void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};