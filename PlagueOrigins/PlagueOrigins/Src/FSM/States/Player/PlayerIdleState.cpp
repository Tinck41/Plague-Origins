#include "stdafx.h"
#include "./PlayerStates.h"

PlayerIdleState::PlayerIdleState(Entity& owner) :
	owner(owner)
{
}

void PlayerIdleState::enter()
{
	std::cout << "IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();
	//Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	//animator.currentAnimation = IDLE;

	//animator.previousFaceDirection = animator.currentFaceDirection;
	//animator.currentFaceDirection = { 1.f, .0f };
	animator.currentAnimation = IDLE;
}

void PlayerIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Dash>().isDashing)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDashState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Attack>().isAttacking)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerAttackState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState, 
			new PlayerMoveState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
	}
}

void PlayerIdleState::exit()
{
}