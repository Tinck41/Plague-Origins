#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class PlayerDashState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerDashState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};