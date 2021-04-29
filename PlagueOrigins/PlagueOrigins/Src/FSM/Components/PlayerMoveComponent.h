#pragma once
#include "Src/ECS/Systems/FSM.h"

struct PlayerMoveComponent :
	PlayerStates
{
	void(*pointer) = FSM::step(MOVE);
};