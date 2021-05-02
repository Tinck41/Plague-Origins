#include "stdafx.h"
#include "Src\FSM\States\Player\PlayerMoveState.h"
#include "Src\FSM\States\Player\PlayerStates.h"

PlayerMoveState::PlayerMoveState(Entity& owner) :
	owner(owner)
{
}

void PlayerMoveState::enter()
{
	std::cout << "MOVE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void PlayerMoveState::update(const float& dt)
{
	if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState, new PlayerIdleState(owner));
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = MOVE;
		animator.previousFaceDirection = animator.currentFaceDirection;
		animator.currentFaceDirection = movement.direction;
	}
}

void PlayerMoveState::exit()
{
}