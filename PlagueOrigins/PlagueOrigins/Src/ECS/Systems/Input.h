#pragma once

#include "IEcsUpdateSystem.h"
#include "entt.hpp"
#include "Src/ECS/Components/PlayerInput.h"

class Input :
	public IEcsUpdateSystem
{
	virtual void update(entt::registry& reg, const float& dt) override;

	void movementInput(PlayerInput& input);
	void checkS(PlayerInput& input);
	void checkA(PlayerInput& input);
	void checkW(PlayerInput& input);
	void checkD(PlayerInput& input);
	void checkR(PlayerInput& input);
	void checkSpace(PlayerInput& input);
	void checkLMB(PlayerInput& input);
};