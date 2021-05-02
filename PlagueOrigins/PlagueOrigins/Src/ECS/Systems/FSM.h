#pragma once
#include "IEcsUpdateSystem.h"

class State;

static class FSM :
	public IEcsUpdateSystem
{
public:
	static void changeState(State* currentState, State* newState);
	static State* changeStateP(State* currentState, State* newState);
	static void initState(State* currentState, State* newState);
	static State* initStateP(State* currentState, State* newState);
	// Inherited via IEcsUpdateSystem
	virtual void update(entt::registry& reg, const float& dt) override;
};

