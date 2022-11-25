#pragma once
#include "ECS/Components.h"
#include "ECS/Systems/IUpdateSystem.h"

class RestartSystem :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
private:
	void setRetryButton(CurrentScreen& currentScreen);
	void setExitButton(CurrentScreen& currentScreen);
};