#include "stdafx.h"
#include "PlayerIdleState.h"

PlayerIdleState::PlayerIdleState(FiniteStateMachine& stateMachine, Player& owner) :
	owner(owner), stateMachine(stateMachine)
{
}

void PlayerIdleState::enter()
{
	this->owner.getAnimator()->setAnimation(animationName::IDLE, this->owner.getInput().getDirection());
}

void PlayerIdleState::execute()
{
	std::cout << "IDLE" << " " << this->owner.getInput().getDirection().x << " " << this->owner.getInput().getDirection().y << "\n";
	if (owner.getInput().getDirection() != sf::Vector2f(0, 0))
		this->stateMachine.changeState(new PlayerMoveState(this->stateMachine, this->owner));

	this->owner.getAnimator()->setAnimation(animationName::IDLE, this->owner.getInput().getDirection());
}

void PlayerIdleState::exit()
{
}
