#pragma once

#include "entt.hpp"

class IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) = 0;
};