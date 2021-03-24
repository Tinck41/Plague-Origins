#pragma once

#include "Player.h"
#include "PlayerStates.h"

class PlayerAttackState : 
	public State
{
private:
	FiniteStateMachine* stateMachine;
	Player& owner;
public:
	PlayerAttackState(Player& owner);
	~PlayerAttackState();

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

