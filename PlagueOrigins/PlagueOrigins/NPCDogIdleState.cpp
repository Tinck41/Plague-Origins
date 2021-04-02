#include "stdafx.h"
#include "NPCDogIdleState.h"

NPCDogIdleState::NPCDogIdleState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

NPCDogIdleState::~NPCDogIdleState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void NPCDogIdleState::enter()
{
	this->owner.getAnimator()->setAnimation(animationName::IDLE);
}

void NPCDogIdleState::update(const float& dt)
{
	if (owner.getInput().getAttack())
	{
		owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
	}
	else if (owner.getInput().getDirection() != sf::Vector2f(0, 0))
	{
		stateMachine->changeState(new NPCDogMoveState(owner));
	}
	else
	{
		owner.getAnimator()->setAnimation(animationName::IDLE);
	}
}

void NPCDogIdleState::exit()
{
}
