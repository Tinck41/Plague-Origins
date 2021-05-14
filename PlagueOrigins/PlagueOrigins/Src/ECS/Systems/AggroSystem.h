#pragma once
#include "Src/ECS/Components.h"
#include "Src/ECS/Systems/IUpdateSystem.h"

class AggroSystem :
	public virtual IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};