#include "stdafx.h"
#include "Src\FSM\States\Player\PlayerIdleState.h"
#include "Src\FSM\States\Player\PlayerStates.h"

PlayerIdleState::PlayerIdleState(Entity& owner) :
	owner(owner)
{
}

void PlayerIdleState::enter()
{
	std::cout << "IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void PlayerIdleState::update(const float& dt)
{
	if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	{
		PlayerStates& playerStates = owner.GetComponent<PlayerStates>();
		//FSM::changeState(playerStates.currentState, new PlayerMoveState(owner));
		playerStates.changeState(playerStates.currentState, new PlayerMoveState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
		animator.previousFaceDirection = animator.currentFaceDirection;
		animator.currentFaceDirection = movement.direction;
	}
}

void PlayerIdleState::exit()
{
}