#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class NPCDogMoveState :
	virtual public State
{
private:
	Entity& owner;
public:
	NPCDogMoveState(Entity& owner);

	void enter() override;
	void update(const float& dt) override;
	void exit() override;
};

