#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class PlayerIdleState :
	public State
{
private:
	Entity& owner;

public:
	PlayerIdleState(Entity& owner);
	
	void enter();
	void update(const float& dt);
	void exit();
};