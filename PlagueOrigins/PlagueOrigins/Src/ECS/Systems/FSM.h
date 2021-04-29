#pragma once
//#include "Src/ECS/Components.h"
#include "Src/ECS/Systems.h"

#include "Src/FSM/State.h"

class FSM :
	public IEcsUpdateSystem
{
public:
	FSM() {};

	static void changeState(State* currentState, State* newState);
	// Inherited via IEcsUpdateSystem
	virtual void update(entt::registry& reg, const float& dt) override;
};

