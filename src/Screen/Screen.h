#pragma once

#include "ECS/SystemHandler.h"
#include "entt.hpp"

class Screen
{
public:
	Screen() = default;
	~Screen();

	virtual void update(const float& dt) = 0;
	virtual ScreenType render(sf::RenderWindow&) = 0;
protected:
	entt::registry registry;
	SystemHandler systems;

	friend class Entity;
};	

