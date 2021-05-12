#pragma once

#include "entt.hpp"

class IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) = 0;
};