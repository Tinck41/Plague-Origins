#include "stdafx.h"
//
//#include "PlayerStateHandler.h"
//
//globalState PlayerStateHandler::getNextGlobalState(globalState suggestedGlobalState)
//{
//	// Validate the next GLOBAL state
//	return suggestedGlobalState;
//}
//
//void PlayerStateHandler::stateWillSet(globalState newGlobalState)
//{
//	// Prepare for new State
//}
//
//
//
//void PlayerStateHandler::setState(globalState newGlobalState,globalState oldGlobalState)
//{
//	// Activate the new State
//	this->previousGlobalState = this->currentGlobalState;
//	this->currentGlobalState = newGlobalState;
//}
//
//void PlayerStateHandler::stateDidSet()
//{
//	// Dispose resources, cleaning up
//}
//
//void PlayerStateHandler::update(const float& dt)
//{
//	// Listen for user input
//	//if (iB.isDashInput())
//	//{
//	//	std::cout << "DASH INPUT" << std::endl;
//	//	this->pushState(globalState::DASH);
//	//}
//	//else if (iB.isAttackInput())
//	//{
//	//	std::cout << "ATTACK INPUT" << std::endl;
//	//	this->pushState(globalState::ATTACK);
//	//}
//	if (iB.isMovementInput())
//	{
//		this->pushState(globalState::MOVE);
//	}
//	else if (iB.isIdle())
//	{
//		this->pushState(globalState::IDLE);
//	}
//}
