#include "stdafx.h"
#include "FSM.h"
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

State* FSM::changeStateP(State* currentState, State* newState)
{
	if (currentState != nullptr)
	{
		currentState->exit();
		delete currentState;
		currentState = nullptr;
	}

	currentState = newState;

	currentState->enter();

	return currentState;
}

void FSM::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<PlayerSMcomponent>();

	for (auto entity : view)
	{
		PlayerSMcomponent& stateMachine = reg.get<PlayerSMcomponent>(entity);

		if (stateMachine.currentState != nullptr)
		{
			stateMachine.currentState->update(dt);
		}
	}
}
