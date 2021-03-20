#pragma once

#include "Player.h"
#include "FiniteStateMachine.h"
#include "PlayerStates.h"

class PlayerIdleState :
	virtual public State
{
private:
	FiniteStateMachine& stateMachine;
	Player& owner;
public:
	PlayerIdleState(FiniteStateMachine& stateMachine, Player& owner);

	void enter() override;
	void execute() override;
	void exit() override;
};