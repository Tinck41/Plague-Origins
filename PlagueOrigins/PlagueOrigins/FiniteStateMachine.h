#pragma once

#include "State.h"

class FiniteStateMachine
{
private:
	State* currentState;
	State* previousState;
public:
	void changeState(State* newState)
	{
		if (this->currentState != nullptr)
			this->currentState->exit();

		this->previousState = this->currentState;
		this->currentState = newState;

		this->currentState->enter();
	}

	void executeStateUpdate()
	{
		if (this->currentState != nullptr)
			this->currentState->execute();
	}

	void switchToPreviousState()
	{
		this->currentState->exit();
		this->currentState = this->previousState;
		this->currentState->enter();
	}
};

