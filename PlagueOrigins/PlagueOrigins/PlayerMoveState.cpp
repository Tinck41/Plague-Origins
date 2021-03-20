#include "stdafx.h"
#include "PlayerMoveState.h"

PlayerMoveState::PlayerMoveState(FiniteStateMachine& stateMachine, Player& owner) :
	owner(owner), stateMachine(stateMachine)
{
}

void PlayerMoveState::enter()
{
	this->owner.setArmature(this->owner.getAnimator()->playAnimation(1, 4));
}

void PlayerMoveState::execute()
{
	std::cout << "MOVE" << "\n";

	if (owner.getInput().getDirection() == sf::Vector2f(0, 0))
		this->stateMachine.changeState(new PlayerIdleState(this->stateMachine, this->owner));
}

void PlayerMoveState::exit()
{
}
