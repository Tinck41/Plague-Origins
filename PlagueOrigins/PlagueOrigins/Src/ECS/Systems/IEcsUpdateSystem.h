#pragma once

#include "entt.hpp"

class IEcsUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) = 0;
};