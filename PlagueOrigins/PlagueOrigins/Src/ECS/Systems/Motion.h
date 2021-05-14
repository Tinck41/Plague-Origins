#pragma once
#include "Src/ECS/Components.h"
#include "Src/ECS/Systems.h"

class Motion : public IUpdateSystem
{
	// Inherited via IEcsUpdateSystem
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};