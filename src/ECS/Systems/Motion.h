#pragma once
#include "ECS/Components.h"
#include "ECS/Systems.h"

class Motion : public IUpdateSystem
{
	// Inherited via IEcsUpdateSystem
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};