#pragma once
#include "Src/FSM/State.h"
#include "Src/ECS/Systems/FSM.h"

struct PlayerStates
{
	State* currentState;
	//State* previousState;
	PlayerStates(State* initState)
	{
		currentState = initState;
		//previousState = nullptr;
	}
	void (*changeState)(State*,State*) = FSM::changeState;
};