#pragma once

#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class EffectsSystem :
	public IUpdateSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};