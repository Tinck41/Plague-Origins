#pragma once
#include "PlayerStates.h"

class IStateHandler
{
public:
	globalState currentGlobalState;
	globalState previousGlobalState;

	virtual globalState getNextGlobalState(globalState suggestedGlobalState) = 0;

	virtual void stateWillSet(globalState newGlobalState) = 0;
	virtual void setState(globalState newGlobalState, globalState oldState) = 0;
	virtual void stateDidSet() = 0;

	void pushState(globalState suggestedGlobalState);
	
	virtual void update(const float& dt) = 0;
};

