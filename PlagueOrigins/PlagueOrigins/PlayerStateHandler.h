#pragma once
#include "IStateHandler.h"

class PlayerStateHandler : public IStateHandler
{
public:
	PlayerStateHandler(Player& player);
	~PlayerStateHandler();
	InputBooleans* iB = NULL;
	Player& player;

	//Унаследовано через StateComponent
	virtual globalState getNextGlobalState(globalState suggestedGlobalState) override;
	virtual localState getNextLocalState(localState suggestedLocalState) override;
	virtual void stateWillSet(globalState newGlobalState, localState newLocalState) override;
	virtual void setState(globalState newState, localState newLocalState, globalState oldState, localState oldLocalState) override;
	virtual void stateDidSet() override;
	virtual void update(const float& dt) override;
};