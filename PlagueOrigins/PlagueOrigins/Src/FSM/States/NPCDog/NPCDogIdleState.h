#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class NPCDogIdleState :
	virtual public State
{
private:
	Entity& owner;

public:
	NPCDogIdleState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};