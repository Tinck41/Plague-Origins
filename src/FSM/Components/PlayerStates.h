#pragma once
#include "FSM/State.h"
#include "ECS/Systems/FSM.h"

struct SMcomponent
{
	State* currentState;
	
	SMcomponent(State* initState)
	{
		currentState = initState;
		currentState->enter();

	}
	State* (*changeState)(State*,State*) = FSM::changeStateP;
};