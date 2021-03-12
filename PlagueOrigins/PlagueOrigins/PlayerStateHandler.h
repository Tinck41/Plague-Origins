#pragma once
#include "IStateHandler.h"
#include "InputBooleans.h"
#include "DirectionFinder.h"

class PlayerStateHandler : public IStateHandler
{
public:
	globalState currentGlobalState = globalState::IDLE;
	globalState previousGlobalState = globalState::IDLE;

	InputBooleans iB;
	//Player& player;

	//PlayerStateHandler();
	//PlayerStateHandler(Player& player);
	//~PlayerStateHandler();

	unsigned getGlobalState() { return this->currentGlobalState; }

	//Унаследовано через StateComponent
	virtual globalState getNextGlobalState(globalState suggestedGlobalState) override;
	//virtual localState getNextLocalState(localState suggestedLocalState) override;
	virtual void stateWillSet(globalState newGlobalState) override;
	//virtual void stateWillSet(globalState newGlobalState, localState newLocalState) override;
	virtual void setState(globalState newState, globalState oldState) override;
	//virtual void setState(globalState newState, localState newLocalState, globalState oldState, localState oldLocalState) override;
	virtual void stateDidSet() override;
	virtual void update(const float& dt) override;
};