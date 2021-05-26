#pragma once

#include "IUpdateSystem.h"
#include "entt.hpp"
#include "Src/ECS/Components.h"

class Input :
	public IUpdateSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	void movementInput(PlayerInput& input);
	void attackInput(PlayerInput& input);
	void menuInput(PlayerInput& input);
	void interactionInput(PlayerInput& input);
	void checkS(PlayerInput& input);
	void checkA(PlayerInput& input);
	void checkW(PlayerInput& input);
	void checkD(PlayerInput& input);
	void checkF(PlayerInput& input);
	void checkR(PlayerInput& input);
	void checkSpace(PlayerInput& input);
	void checkLMB(PlayerInput& input);
	void checkEsc(PlayerInput& input);
};