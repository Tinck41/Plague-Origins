#pragma once
#include "Player.h"
#include "PlayerStates.h"

class IStateHandler
{
public:
	globalState currentGlobalState;
	localState currentLocalState;
	globalState previousGlobalState;
	localState previousLocalState;

	virtual globalState getNextGlobalState(globalState suggestedGlobalState) = 0;
	virtual localState getNextLocalState(localState suggestedLocalState) = 0;

	virtual void stateWillSet(globalState newGlobalState, localState newLocalState) = 0;
	virtual void setState(globalState newGlobalState, localState newLocalState, globalState oldState, localState oldLocalState) = 0;
	virtual void stateDidSet() = 0;

	void pushState(globalState suggestedGlobalState, localState suggestedLocalState);
	
	virtual void update(const float& dt) = 0;
};

