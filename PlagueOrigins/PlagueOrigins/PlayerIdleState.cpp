#include "stdafx.h"
#include "PlayerIdleState.h"

PlayerIdleState::PlayerIdleState(Player& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

PlayerIdleState::~PlayerIdleState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void PlayerIdleState::enter()
{
	this->owner.getAnimator()->setAnimation(animationName::IDLE);
}

void PlayerIdleState::update(const float& dt)
{
	//std::cout << "IDLE" << " " << this->owner.getInput().getDirection().x << " " << this->owner.getInput().getDirection().y << "\n";
	
	if (owner.getInput().getAttack())
	{
		owner.getStateMachine()->changeState(new PlayerAttackState(owner));
	}
	else if (owner.getInput().getDirection() != sf::Vector2f(0, 0))
	{
		this->stateMachine->changeState(new PlayerMoveState(this->owner));
	}
	else
	{
		this->owner.getAnimator()->setAnimation(animationName::IDLE);
	}
}

void PlayerIdleState::exit()
{
}
