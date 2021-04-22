#pragma once

#include "Src/ECS/SystemHandler.h"
#include "entt.hpp"

enum class ScreenType {
	LOADING,
	GAME,
	MAIN_MENU,
	EXIT
};

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

