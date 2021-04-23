#include "stdafx.h"
#include "NPCDogAggroState.h"

NPCDogAggroState::NPCDogAggroState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

NPCDogAggroState::~NPCDogAggroState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void NPCDogAggroState::enter()
{
	std::cout << "Dog Aggro State\n";
	owner.getPatrol()->aggro = true;
	target = owner.getCombatComponent()->getPlayerPosition();
	owner.getPatrol()->directRoute(target);
	owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getPatrol()->getDirection());
}

void NPCDogAggroState::update(const float& dt)
{
	if (owner.getCombatComponent()->isDead())
	{
		owner.getStateMachine()->changeState(new NPCDogDeathState(owner));
	}
	else if (!owner.getCombatComponent()->isAggro())
	{
		owner.getPatrol()->aggro = false;
		owner.getStateMachine()->changeState(new NPCDogMoveState(owner));
	}
	else if (owner.getCombatComponent()->isInAttackRange())
	{
		owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
	}
	else 
	{
		target = owner.getCombatComponent()->getPlayerPosition();
		owner.getPatrol()->directRoute(target);
		owner.getMover()->move(dt, owner.getPatrol()->getDirection());
		this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getPatrol()->getDirection());
	}
}

void NPCDogAggroState::exit()
{
	std::cout << "Dog EXIT aggro state\n";
}
