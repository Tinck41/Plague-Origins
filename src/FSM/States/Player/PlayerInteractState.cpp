#include "stdafx.h"
#include "./PlayerStates.h"

PlayerInteractState::PlayerInteractState(Entity& owner) :
	owner(owner)
{
}

void PlayerInteractState::enter()
{
	std::cout << "DIALOGUE START\n";
	Animator& animator = owner.GetComponent<Animator>();
	Attack& attack = owner.GetComponent<Attack>();
	PlayerInput& input = owner.GetComponent<PlayerInput>();
	input.canCheckForAttack = false;
	input.canCheckForMovement = false;

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;
}

void PlayerInteractState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (!owner.GetComponent<Dialogue>().isInteracting)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerIdleState(owner));
		std::cout << "";
		
	}
}

void PlayerInteractState::exit()
{
	std::cout << "DIALOGUE END\n";
	PlayerInput& input = owner.GetComponent<PlayerInput>();
	input.canCheckForAttack = true;
	input.canCheckForMovement = true;
}