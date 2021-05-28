#include "stdafx.h"
#include "BossStates.h"
BossAggroState::BossAggroState(Entity& owner) :
	owner(owner)
{
}

void BossAggroState::enter()
{
	std::cout << "Boss Aggro State\n";

	Movement& movement = owner.GetComponent<Movement>();
	Aggresion& aggresion = owner.GetComponent<Aggresion>();
	Animator& animator = owner.GetComponent<Animator>();

	movement.direction = aggresion.vectorToTarget;
	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void BossAggroState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BossDeathState(owner));
		std::cout << "";
	}
	else if (!owner.GetComponent<Boss>().isBossFight)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BossIdleState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Attack>().radius >= owner.GetComponent<Aggresion>().distanceToTarget)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BossAttackState(owner));
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
}

void BossAggroState::exit()
{
}
