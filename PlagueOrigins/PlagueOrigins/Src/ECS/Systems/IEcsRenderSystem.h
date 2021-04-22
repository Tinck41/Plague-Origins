#pragma once

#include "entt.hpp"

class IEcsRenderSystem
{
public:
	virtual void render(entt::registry& reg, sf::RenderWindow& window) = 0;
};