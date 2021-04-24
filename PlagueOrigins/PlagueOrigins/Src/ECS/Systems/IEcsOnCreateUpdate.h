#pragma once

#include "entt.hpp"
#include "SFML/Graphics.hpp"

class IEcsOnCreateUpdate
{
public:
	virtual void onCreate(entt::registry& reg) = 0;
};