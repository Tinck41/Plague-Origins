#pragma once
#include "Src/FSM/State.h"
#include "Src/ECS/Systems/FSM.h"

//#include "Src/Screen/Entity.h"
//#include "Src/FSM/States/Player/PlayerStates.h"

struct PlayerSMcomponent
{
	State* currentState;
	//State* previousState;
	PlayerSMcomponent()
	{
		currentState = nullptr;
	}
	PlayerSMcomponent(State* initState)
	{
		currentState = initState;
		//previousState = nullptr;
	}
	void (*changeState)(State*,State*) = FSM::changeState;
};