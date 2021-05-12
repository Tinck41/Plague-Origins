#pragma once
#include "IUpdateSystem.h"

class State;

class FSM :
	public IUpdateSystem
{
public:
	static State* changeStateP(State* currentState, State* newState);
	// Inherited via IEcsUpdateSystem
	virtual void update(entt::registry& reg, const float& dt) override;
};

