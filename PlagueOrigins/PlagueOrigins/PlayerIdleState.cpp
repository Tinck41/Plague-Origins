#include "stdafx.h"
#include "PlayerIdleState.h"

PlayerIdleState::PlayerIdleState(FiniteStateMachine& stateMachine, Player& owner) :
	owner(owner), stateMachine(stateMachine)
{
}

void PlayerIdleState::enter()
{
	this->owner.setArmature(this->owner.getAnimator()->playAnimation(0, 1));
}

void PlayerIdleState::execute()
{
	std::cout << "IDLE" << "\n";

	if (owner.getInput().getDirection() != sf::Vector2f(0, 0))
		this->stateMachine.changeState(new PlayerMoveState(this->stateMachine, this->owner));
}

void PlayerIdleState::exit()
{
}
