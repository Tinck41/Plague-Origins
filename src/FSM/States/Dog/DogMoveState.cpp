#include "stdafx.h"
#include "./DogStates.h"

DogMoveState::DogMoveState(Entity& owner) :
	owner(owner)
{
}

void DogMoveState::enter()
{
	//std::cout << "Dog Move State\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void DogMoveState::update(const float& dt)
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
	else if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogIdleState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = MOVE;
		animator.previousFaceDirection = animator.currentFaceDirection;
		animator.currentFaceDirection = movement.direction;
	}
}

void DogMoveState::exit()
{
}
