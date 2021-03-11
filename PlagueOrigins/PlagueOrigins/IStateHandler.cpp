#include "stdafx.h"

#include "IStateHandler.h"

void IStateHandler::pushState(globalState suggestedGlobalState, localState suggestedLocalState)
{
	globalState newGlobalState = getNextGlobalState(suggestedGlobalState);
	localState newLocalState = getNextLocalState(suggestedLocalState);
	stateWillSet(newGlobalState, newLocalState);
	setState(newGlobalState, newLocalState, currentGlobalState, currentLocalState);
	this->previousLocalState = this->currentLocalState;
	this->previousGlobalState = this->currentGlobalState;
	this->currentGlobalState = newGlobalState;
	this->currentLocalState = newLocalState;
	stateDidSet();
}
