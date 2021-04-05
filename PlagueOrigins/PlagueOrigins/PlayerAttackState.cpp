#include "stdafx.h"
#include "PlayerAttackState.h"

PlayerAttackState::PlayerAttackState(Player& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

PlayerAttackState::~PlayerAttackState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void PlayerAttackState::enter()
{
	//std::cout << owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted() << "\n";
	this->owner.getAnimator()->setAnimation(animationName::ATTACK);
	this->owner.getCombatComponent()->attackNPC();
}

void PlayerAttackState::update(const float& dt)
{
	//std::cout << "ATTACK" << " " << this->owner.getInput().getDirection().x << " " << this->owner.getInput().getDirection().y << "\n";
	if (owner.getCombatComponent()->isDead())
	{
		owner.getStateMachine()->changeState(new PlayerDeathState(owner));
	}
	else if (owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted())
	{
		if (owner.getInput().getAttack())
		{
			owner.getStateMachine()->changeState(new PlayerAttackState(owner));
		}
		else
		{
			owner.getStateMachine()->changeState(new PlayerIdleState(owner));
		}
	}
}

void PlayerAttackState::exit()
{
}
