#include "PlayerStateHandler.h"

PlayerStateHandler::PlayerStateHandler(Player& player) :
	player(player)
{
}

PlayerStateHandler::~PlayerStateHandler()
{
}

State PlayerStateHandler::getNextState(State suggestedState)
{
	// Validate the next state
	return suggestedState;
}

void PlayerStateHandler::stateWillSet(State newState)
{
	// Prepare for new State
}

void PlayerStateHandler::setState(State newState, State oldState)
{
	// Activate the new State
}

void PlayerStateHandler::stateDidSet()
{
	// Dispose resources, cleaning up
}

void PlayerStateHandler::update(const float& dt)
{
	// Listen for user input
}
