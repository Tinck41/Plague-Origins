#include "stdafx.h"

#include "PlayerStateHandler.h"
#include "InputBooleans.h"
#include "InputHandler.h"

PlayerStateHandler::PlayerStateHandler(Player& player) :
	player(player)
{
	iB = new InputBooleans();
}

PlayerStateHandler::~PlayerStateHandler()
{
}

globalState PlayerStateHandler::getNextGlobalState(globalState suggestedGlobalState)
{
	// Validate the next GLOBAL state
	return suggestedGlobalState;
}

localState PlayerStateHandler::getNextLocalState(localState suggestedLocalState)
{
	// Validate the next LOCAL state
	return suggestedLocalState;
}

void PlayerStateHandler::stateWillSet(globalState newGlobalState, localState newLocalState)
{
	// Prepare for new State
}



void PlayerStateHandler::setState(globalState newGlobalState, localState newLocalState, globalState oldGlobalState, localState oldLocalState)
{
	// Activate the new State
	this->previousLocalState = this->currentLocalState;
	this->previousGlobalState = this->currentGlobalState;
	this->currentGlobalState = newGlobalState;
	this->currentLocalState = newLocalState;
}

void PlayerStateHandler::stateDidSet()
{
	// Dispose resources, cleaning up
}

void PlayerStateHandler::update(const float& dt)
{
	// Listen for user input
	if (iB->isMovementInput())
	{
		this->setState(globalState::MOVE, this->currentState);
	}


}
