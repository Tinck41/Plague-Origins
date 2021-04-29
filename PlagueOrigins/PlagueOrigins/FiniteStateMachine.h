// #pragma once

// #include "State.h"

// class FiniteStateMachine
// {
// private:
// 	// TO DO: smart_ptr
// 	State* �urrentState;
// public:
// 	~FiniteStateMachine()
// 	{
// 		delete �urrentState;
// 	}


// 	void changeState(State* newState)
// 	{
// 		if (�urrentState != nullptr)
// 		{
// 			�urrentState->exit();
// 			delete �urrentState;
// 		}

// 		�urrentState = newState;

// 		�urrentState->enter();
// 	}

// 	void executeStateUpdate(const float& dt)
// 	{
// 		if (�urrentState != nullptr)
// 		{
// 			�urrentState->update(dt);
// 		}
// 	}
// };

