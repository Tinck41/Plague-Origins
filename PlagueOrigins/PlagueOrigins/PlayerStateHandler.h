#pragma once
#include "IStateHandler.h"

class PlayerStateHandler : public IStateHandler
{
public:
	PlayerStateHandler(Player& player);
	~PlayerStateHandler();

	Player& player;

	// Унаследовано через StateComponent
	virtual State getNextState(State suggestedState) override;
	virtual void stateWillSet(State newState) override;
	virtual void setState(State newState, State oldState) override;
	virtual void stateDidSet() override;
	virtual void update(const float& dt) override;
};