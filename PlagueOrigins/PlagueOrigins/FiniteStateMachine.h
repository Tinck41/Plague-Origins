#pragma once

#include "State.h"

class FiniteStateMachine
{
private:
	// TO DO: smart_ptr
	State* ņurrentState;
public:
	~FiniteStateMachine()
	{
		delete ņurrentState;
	}

	void changeState(State* newState)
	{
		if (ņurrentState != nullptr)
		{
			ņurrentState->exit();
			delete ņurrentState;
		}

		ņurrentState = newState;

		ņurrentState->enter();
	}

	void executeStateUpdate(const float& dt)
	{
		if (ņurrentState != nullptr)
		{
			ņurrentState->update(dt);
		}
	}
};

