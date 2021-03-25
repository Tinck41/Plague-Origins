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
		owner.getStateMachine()->changeState(new PlayerAttackState(owner));
	}
	else if (owner.getInput().getDirection() == sf::Vector2f(0, 0))
	{
		this->stateMachine->changeState(new PlayerIdleState(this->owner));
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
