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
	Movement& movement = owner.GetComponent<Movement>();

	//movement.direction = { .0f, 1.f };

	animator.currentAnimation = IDLE;
	animator.previousFaceDirection = animator.currentFaceDirection;
}

void BishopIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Interact>().isInteracting == true)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopInteractState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
	}
}

void BishopIdleState::exit()
{
}