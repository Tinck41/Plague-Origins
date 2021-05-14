#include "stdafx.h"
#include "./DogStates.h"

DogIdleState::DogIdleState(Entity& owner) :
	owner(owner)
{
}

void DogIdleState::enter()
{
	std::cout << "IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	//animator.previousFaceDirection = animator.currentFaceDirection;
	//animator.currentFaceDirection = { .0f, 1.f };
	animator.currentAnimation = IDLE;
}

void DogIdleState::update(const float& dt)
{

	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogDeathState(owner));
		std::cout << "";
	}
	//TO-DO
	else if (owner.GetComponent<Aggresion>().isAggresive)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogAggroState(owner));
		std::cout << "";
	}
	//else if (owner.GetComponent<Attack>().isAttacking)
	//{
	//	PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new DogAttackState(owner));
	//	std::cout << "";
	//}
	else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogMoveState(owner));
		std::cout << "";
	}
	else
	{
		//Animator& animator = owner.GetComponent<Animator>();

		//animator.previousAnimation = animator.currentAnimation;
		//animator.currentAnimation = IDLE;
	}
}

void DogIdleState::exit()
{
}