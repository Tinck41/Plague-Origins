#include "stdafx.h"

#include "PlayerStateHandler.h"

globalState PlayerStateHandler::getNextGlobalState(globalState suggestedGlobalState)
{
	// Validate the next GLOBAL state
	std::cout << "";
	return suggestedGlobalState;
}

//localState PlayerStateHandler::getNextLocalState(localState suggestedLocalState)
//{
//	// Validate the next LOCAL state
//	std::cout << "";
//	return localState::idleDown;
//	//return suggestedLocalState;
//}

void PlayerStateHandler::stateWillSet(globalState newGlobalState)
{
	// Prepare for new State
	std::cout << newGlobalState << " will set\n";
}



void PlayerStateHandler::setState(globalState newGlobalState,globalState oldGlobalState)
{
	// Activate the new State
	//this->previousLocalState = this->currentLocalState;
	this->previousGlobalState = this->currentGlobalState;
	this->currentGlobalState = newGlobalState;
	//this->currentLocalState = newLocalState;
}

void PlayerStateHandler::stateDidSet()
{
	// Dispose resources, cleaning up
	std::cout << currentGlobalState << " is set.\n";
}

void PlayerStateHandler::update(const float& dt)
{
	// Listen for user input
	if (iB.isDashInput())
	{
		std::cout << "DASH INPUT" << std::endl;
		this->pushState(globalState::DASH);
	}
	else if (iB.isAttackInput())
	{
		std::cout << "ATTACK INPUT" << std::endl;
		this->pushState(globalState::ATTACK);
	}
	else if (iB.isMovementInput())
	{
		std::cout << "MOVEMENT INPUT" << std::endl;
		this->pushState(globalState::MOVE);
		//this->setState(globalState::MOVE, this->currentState);
	}
	else if (iB.isIdle())
	{
		std::cout << "NO INPUT - IDLE" << std::endl;
		this->pushState(globalState::IDLE);
	}


}
