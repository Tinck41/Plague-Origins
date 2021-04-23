#pragma once
#include <box2d/box2d.h>
#include <box2d/b2_world_callbacks.h>

class RayCastClosestCallback :
    public b2RayCastCallback
{
public:
    bool m_hit;
    b2Vec2 m_point;
    b2Vec2 m_normal;

    RayCastClosestCallback()
    {
        m_hit = false;
    }

    float ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction) override;
    
};

