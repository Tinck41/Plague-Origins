#include "stdafx.h"
#include "./BishopStates.h"

BishopInteractState::BishopInteractState(Entity& owner) :
	owner(owner)
{
}

void BishopInteractState::enter()
{
	std::cout << "DIALOGUE START\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;

	owner.GetComponent<Interact>().isInteracting = true;
}

void BishopInteractState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopDeathState(owner));
		std::cout << "";
	}
	//END OF INTERACTION
	else if (owner.GetComponent<Interact>().isInteracting == false)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopIdleState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
	}
}

void BishopInteractState::exit()
{
	std::cout << "DIALOGUE END\n";
}