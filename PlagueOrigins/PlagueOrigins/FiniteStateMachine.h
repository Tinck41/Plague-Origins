#pragma once

#include "State.h"

class FiniteStateMachine
{
private:
	// TO DO: smart_ptr
	State* ñurrentState;
public:
	~FiniteStateMachine()
	{
		delete ñurrentState;
	}

	void changeState(State* newState)
	{
		if (ñurrentState != nullptr)
		{
			ñurrentState->exit();
			delete ñurrentState;
		}

		ñurrentState = newState;

		ñurrentState->enter();
	}

	void executeStateUpdate(const float& dt)
	{
		if (ñurrentState != nullptr)
		{
			ñurrentState->update(dt);
		}
	}
};

