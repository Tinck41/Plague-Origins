#include "stdafx.h"
#include "PlayerMoveState.h"

PlayerMoveState::PlayerMoveState(FiniteStateMachine& stateMachine, Player& owner) :
	owner(owner), stateMachine(stateMachine)
{
}

void PlayerMoveState::enter()
{
	this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getInput().getDirection());
}

void PlayerMoveState::execute()
{
	std::cout << "MOVE" << " " << this->owner.getInput().getDirection().x << " " << this->owner.getInput().getDirection().y << "\n";

	if (owner.getInput().getDirection() == sf::Vector2f(0, 0))
		this->stateMachine.changeState(new PlayerIdleState(this->stateMachine, this->owner));

	this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getInput().getDirection());
}

void PlayerMoveState::exit()
{
}
