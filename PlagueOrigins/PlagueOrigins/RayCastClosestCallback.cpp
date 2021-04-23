#include "stdafx.h"
#include "RayCastClosestCallback.h"
#include "EntityCategory.h"

float RayCastClosestCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction)
{
    uintptr_t index = fixture->GetBody()->GetUserData().pointer;
    //std::cout << index << "\n";
    if (index == EntityCategory::PLAYER)
    {
        m_hit = true;
        m_point = point;
        m_normal = normal;

        return fraction;
    }
    else
    {
        m_hit = false;
        m_point = point;
        m_normal = normal;

        return -1.f;
    }
}