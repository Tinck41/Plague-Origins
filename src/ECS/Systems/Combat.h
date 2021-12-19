#pragma once
#include "IUpdateSystem.h"

#include "ECS/Components.h"

#define RADTODEG 180.f / M_PI

class Combat :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};