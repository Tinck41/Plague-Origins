#include "stdafx.h"
#include "NPCDogAttackState.h"

NPCDogAttackState::NPCDogAttackState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
	delay = sf::seconds(1.f);
}

NPCDogAttackState::~NPCDogAttackState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void NPCDogAttackState::enter()
{
	std::cout << "Dog Attack State\n";
	//this->owner.getAnimator()->getArmatureDisplay() = new dragonBones::SFMLArmatureDisplay("")
	//this->owner.getAnimator()->getArmatureDisplay()->getAnimation()->gotoAndPlayByProgress("attack0", 100.f, 1);
	//this->owner.getAnimator()->setAnimation(animationName::NONE);
	this->owner.getAnimator()->setAnimation(animationName::ATTACK);
	this->owner.getCombatComponent()->attackPlayer();

	//Timer
	last = gameClock.getElapsedTime();
}

void NPCDogAttackState::update(const float& dt)
{
	if (owner.getCombatComponent()->isDead())
	{
		owner.getStateMachine()->changeState(new NPCDogDeathState(owner));
	}
	else
	{
		now = gameClock.getElapsedTime();
		if (now - last >= delay)
		{
			if (owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted())
			{
				if (owner.getCombatComponent()->isInAttackRange())
				{
					owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
				}
				else
				{
					owner.getStateMachine()->changeState(new NPCDogAggroState(owner));
				}
			}
		}
	}
	
}

void NPCDogAttackState::exit()
{
	this->owner.getAnimator()->setAnimation(animationName::IDLE);
	std::cout << "Dog EXIT attack state\n";
}
