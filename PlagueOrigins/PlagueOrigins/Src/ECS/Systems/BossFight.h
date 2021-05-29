#pragma once

#include "Src/ECS/Components.h"
#include "IUpdateSystem.h"

class BossFight :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
private:
	void checkForWin(entt::registry& reg);

	void setBossFightMusic(entt::registry& reg, bool playMusic);
};