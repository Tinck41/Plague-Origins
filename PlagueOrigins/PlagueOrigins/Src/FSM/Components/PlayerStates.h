#pragma once
#include "Src/FSM/State.h"
#include "Src/ECS/Systems/FSM.h"

struct PlayerStates
{
	State* currentState;
	State* newState;

	FSM fsm;

	PlayerStates()
	{
		fsm = FSM();
	}

	void (*changeState)(State*,State*) = fsm.changeState;
};