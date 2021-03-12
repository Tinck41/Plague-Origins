#include "stdafx.h"

#include "IStateHandler.h"

void IStateHandler::pushState(globalState suggestedGlobalState)
{
	globalState newGlobalState = getNextGlobalState(suggestedGlobalState);
	//localState newLocalState = getNextLocalState(suggestedLocalState);
	stateWillSet(newGlobalState);
	setState(newGlobalState,currentGlobalState);
	//this->previousLocalState = this->currentLocalState;
	//this->previousGlobalState = this->currentGlobalState;
	//this->currentGlobalState = newGlobalState;
	//this->currentLocalState = newLocalState;
	stateDidSet();
}
