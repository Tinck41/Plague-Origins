#include "stdafx.h"
#include "./PlayerStates.h"

PlayerMoveState::PlayerMoveState(Entity& owner) :
	owner(owner)
{
}

void PlayerMoveState::enter()
{
	//std::cout << "MOVE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();
	ActorAudioSource& audioSource = owner.GetComponent<ActorAudioSource>();

	audioSource.playFootStepSound = true;
	audioSource.loopFootStepSound = true;

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.currentFaceDirection = movement.direction;
}

void PlayerMoveState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Dash>().isDashing)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDashState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Attack>().isAttacking)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerAttackState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState, 
			new PlayerIdleState(owner));
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.currentFaceDirection = movement.direction;
	}
}

void PlayerMoveState::exit()
{
	ActorAudioSource& audioSource = owner.GetComponent<ActorAudioSource>();

	audioSource.loopFootStepSound = false;
}