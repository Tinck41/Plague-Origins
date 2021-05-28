#include "stdafx.h"
#include "./PlayerStates.h"

PlayerInteractState::PlayerInteractState(Entity& owner) :
	owner(owner)
{
}

void PlayerInteractState::enter()
{
	//std::cout << "DIALOGUE START\n";
	Animator& animator = owner.GetComponent<Animator>();
	//if (owner.HasComponent<Movement>())
	//	owner.RemoveComponent<Movement>();
	//if (owner.HasComponent<Attack>())
	//	owner.RemoveComponent<Attack>();
	//if (owner.HasComponent<Dash>())
	//	owner.RemoveComponent<Dash>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;
}

void PlayerInteractState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (!owner.GetComponent<Dialogue>().isInteracting)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerIdleState(owner));
		std::cout << "";
	}
}

void PlayerInteractState::exit()
{
	std::cout << "DIALOGUE END\n";
	//owner.AddComponent<Movement>(config.playerSpeed);
	//Stats& playerStats = owner.GetComponent<Stats>();
	//owner.AddComponent<Attack>(owner.GetComponent<RigidBody>().body, playerStats.STR, config.playerAttackRange);
	//owner.AddComponent<Dash>(playerStats.AGI);
}