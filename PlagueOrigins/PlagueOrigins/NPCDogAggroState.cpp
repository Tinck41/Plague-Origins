//#include "stdafx.h"
//#include "NPCDogAggroState.h"
//
//NPCDogAggroState::NPCDogAggroState(NPCDog& owner) :
//	owner(owner)
//{
//	stateMachine = owner.getStateMachine();
//}
//
//NPCDogAggroState::~NPCDogAggroState()
//{
//	stateMachine = NULL;
//	delete stateMachine;
//}
//
//void NPCDogAggroState::enter()
//{
//	std::cout << "Dog Aggro State\n";
//	target = owner.getCombatComponent()->getPlayerPosition();
//	owner.getAnimator()->setAnimation(animationName::MOVE, owner.getPatrol()->directRoute(owner.getCombatComponent()->getPlayerPosition()));
//}
//
//void NPCDogAggroState::update(const float& dt)
//{
//	if (!owner.getCombatComponent()->isAggro())
//	{
//		owner.getStateMachine()->changeState(new NPCDogMoveState(owner));
//	}
//	else if (owner.getCombatComponent()->isInAttackRange())
//	{
//		owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
//	}
//	else if (owner.getCombatComponent()->isDead())
//	{
//		owner.getStateMachine()->changeState(new NPCDogDeathState(owner));
//	}
//	else
//	{
//		target = owner.getCombatComponent()->getPlayerPosition();
//		owner.getMover()->move(dt, owner.getPatrol()->directRoute(target));
//		this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getPatrol()->getDirection());
//	}
//}
//
//void NPCDogAggroState::exit()
//{
//}
#include "stdafx.h"
