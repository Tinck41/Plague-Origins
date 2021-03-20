#pragma once

#include "Player.h"
#include "FiniteStateMachine.h"
#include "PlayerStates.h"

class PlayerMoveState :
	virtual public State
{
private:
	FiniteStateMachine& stateMachine;
	Player& owner;
public:
	PlayerMoveState(FiniteStateMachine& stateMachine, Player& owner);

	void enter() override;
	void execute() override;
	void exit() override;
};