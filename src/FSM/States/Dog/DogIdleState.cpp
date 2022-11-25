#include "stdafx.h"
#include "./DogStates.h"

DogIdleState::DogIdleState(Entity& owner) :
	owner(owner)
{
}

void DogIdleState::enter()
{
	//std::cout << "Dog Idle State\n";
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
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Aggresion>().isAggresive)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogAggroState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogMoveState(owner));
		std::cout << "";
	}
}

void DogIdleState::exit()
{
}