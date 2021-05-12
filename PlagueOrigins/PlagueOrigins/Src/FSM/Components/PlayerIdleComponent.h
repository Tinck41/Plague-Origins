#pragma once
#include "Src/ECS/Systems/FSM.h"

struct PlayerIdleComponent :
	PlayerStates
{
	void(*pointer) = FSM::step(IDLE);
};