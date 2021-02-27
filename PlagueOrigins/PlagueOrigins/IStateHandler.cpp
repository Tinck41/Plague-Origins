#include "IStateHandler.h"

void IStateHandler::pushState(State suggestedState)
{
	State newState = getNextState(suggestedState);
	stateWillSet(newState);
	setState(newState, currentState);
	this->previousState = this->currentState;
	this->currentState = newState;
	stateDidSet();
}
