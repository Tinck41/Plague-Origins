#include "stdafx.h"
#include "./DogStates.h"
DogAggroState::DogAggroState(Entity& owner) :
	owner(owner)
{
}

void DogAggroState::enter()
{
	std::cout << "Dog Aggro State\n";

	Movement& movement = owner.GetComponent<Movement>();
	Aggresion& aggresion = owner.GetComponent<Aggresion>();
	Animator& animator = owner.GetComponent<Animator>();

	movement.direction = aggresion.vectorToTarget;
	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void DogAggroState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogDeathState(owner));
		std::cout << "";
	}
	else if (!owner.GetComponent<Aggresion>().isAggresive)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogIdleState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Attack>().radius >= owner.GetComponent<Aggresion>().distanceToTarget)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new DogAttackState(owner));
		std::cout << "";
	}
	else
	{
		Movement& movement = owner.GetComponent<Movement>();
		Aggresion& aggresion = owner.GetComponent<Aggresion>();
		Animator& animator = owner.GetComponent<Animator>();

		movement.direction = aggresion.vectorToTarget;
		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = MOVE;
		animator.previousFaceDirection = animator.currentFaceDirection;
		animator.currentFaceDirection = movement.direction;
	}
	//else if (owner.getCombatComponent()->isInAttackRange())
	//{
	//	owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
	//}
	//else if (owner.getCombatComponent()->isDead())
	//{
	//	owner.getStateMachine()->changeState(new NPCDogDeathState(owner));
	//}
	//else
	//{
	//	target = owner.getCombatComponent()->getPlayerPosition();
	//	owner.getMover()->move(dt, owner.getPatrol()->directRoute(target));
	//	this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getPatrol()->getDirection());
	//}
}

void DogAggroState::exit()
{
}
