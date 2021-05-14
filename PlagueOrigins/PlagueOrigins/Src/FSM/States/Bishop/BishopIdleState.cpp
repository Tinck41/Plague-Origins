#include "stdafx.h"
#include "./BishopStates.h"

BishopIdleState::BishopIdleState(Entity& owner) :
	owner(owner)
{
}

void BishopIdleState::enter()
{
	std::cout << "BISHOP IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	//animator.previousFaceDirection = animator.currentFaceDirection;
	//animator.currentFaceDirection = { .0f, 1.f };
	animator.currentAnimation = IDLE;

}

void BishopIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Interact>().isInteracting == true)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopInteractState(owner));
		std::cout << "";
	}
	else
	{
	}
}

void BishopIdleState::exit()
{
}