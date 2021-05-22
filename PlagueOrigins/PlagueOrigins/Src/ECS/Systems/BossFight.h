#pragma once

#include "Src/ECS/Components.h"
#include "IUpdateSystem.h"

class BossFight :
	public IUpdateSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};