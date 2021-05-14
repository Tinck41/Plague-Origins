#include "stdafx.h"
#include "./DogStates.h"
DogAggroState::DogAggroState(Entity& owner) :
	owner(owner)
{
}

void DogAggroState::enter()
{
	//std::cout << "Dog Aggro State\n";
	//target = owner.getCombatComponent()->getPlayerPosition();
	//owner.getAnimator()->setAnimation(animationName::MOVE, owner.getPatrol()->directRoute(owner.getCombatComponent()->getPlayerPosition()));
}

void DogAggroState::update(const float& dt)
{
	//if (!owner.getCombatComponent()->isAggro())
	//{
	//	owner.getStateMachine()->changeState(new NPCDogMoveState(owner));
	//}
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
