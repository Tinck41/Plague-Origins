#pragma once

#include "Src/ECS/Components.h"
#include "IUpdateSystem.h"

class BossFight :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
private:
	void checkForTrigger(entt::registry& reg);
	void checkBoss(entt::registry& reg, BossFightArena& bossFightArena);
	void checkPlayer(entt::registry& reg, BossFightArena& bossFightArena);

	void setBossFightMusic(entt::registry& reg, bool playMusic);
};