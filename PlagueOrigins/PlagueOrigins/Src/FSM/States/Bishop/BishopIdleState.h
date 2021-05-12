#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class BishopIdleState :
	virtual public State
{
private:
	Entity& owner;

public:
	BishopIdleState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};