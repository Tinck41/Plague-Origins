#include "stdafx.h"
#include "BossStates.h"

BossIdleState::BossIdleState(Entity& owner) :
	owner(owner)
{
}

void BossIdleState::enter()
{
	std::cout << "Boss Idle State\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;

	if (owner.HasComponent<Aggresion>())
	{
		owner.RemoveComponent<Aggresion>();
	}
}

void BossIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BossDeathState(owner));
		std::cout << "";
	}
	//TO-DO
	else if (owner.GetComponent<Boss>().isBossFight)
	{
		owner.AddComponent<Aggresion>(owner.GetComponent<RigidBody>().body, 3000.f, 360.f);
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BossAggroState(owner));
		std::cout << "";
	}
	//else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	//{
	//	SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
	//	stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
	//		new BossMoveState(owner));
	//	std::cout << "";
	//}

}

void BossIdleState::exit()
{
}