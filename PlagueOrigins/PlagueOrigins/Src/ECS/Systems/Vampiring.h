#pragma once

#include "IUpdateSystem.h"
#include "Src/ECS/Components.h"

class Vampiring :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};