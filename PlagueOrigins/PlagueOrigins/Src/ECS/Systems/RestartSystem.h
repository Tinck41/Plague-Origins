#pragma once
#include "Src/ECS/Components.h"
#include "Src/ECS/Systems/IUpdateSystem.h"

class RestartSystem :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
private:
};