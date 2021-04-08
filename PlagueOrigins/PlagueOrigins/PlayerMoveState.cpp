#include "stdafx.h"
#include "PlayerMoveState.h"

PlayerMoveState::PlayerMoveState(Player& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

PlayerMoveState::~PlayerMoveState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void PlayerMoveState::enter()
{
	this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getInput().getDirection());
}

void PlayerMoveState::update(const float& dt)
{
	//std::cout << "MOVE" << " " << this->owner.getInput().getDirection().x << " " << this->owner.getInput().getDirection().y << "\n";

	if (owner.getInput().getAttack())
	{
		owner.getMover()->move(dt, sf::Vector2f(0.f, 0.f)); // �������
		owner.getStateMachine()->changeState(new PlayerAttackState(owner));
	}
	else if (owner.getInput().getDirection() == sf::Vector2f(0, 0))
	{
		owner.getMover()->move(dt, sf::Vector2f(0.f, 0.f)); // �������
		this->stateMachine->changeState(new PlayerIdleState(this->owner));
	}
	else if (owner.getCombatComponent()->isDead())
	{
		owner.getStateMachine()->changeState(new PlayerDeathState(owner));
	}
	else
	{
		owner.getMover()->move(dt, owner.getInput().getDirection());
		this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getInput().getDirection());
	}
}

void PlayerMoveState::exit()
{
}
