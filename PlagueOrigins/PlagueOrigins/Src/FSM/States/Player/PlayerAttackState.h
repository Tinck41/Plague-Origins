#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class PlayerAttackState : 
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerAttackState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};