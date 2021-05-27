#include "stdafx.h"
#include "./PlayerStates.h"

PlayerDashState::PlayerDashState(Entity& owner) :
	owner(owner)
{
}

void PlayerDashState::enter()
{
	//std::cout << "DASH\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();
	Dash& dash = owner.GetComponent<Dash>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DASH;
	animator.currentFaceDirection = movement.direction;

	movement.speed = dash.speed;
	dash.curDuration = sf::milliseconds(dash.duration);

	Stamina& stamina = owner.GetComponent<Stamina>();
	stamina.curStamina -= dash.staminaCost;
	stamina.canRestore = false;
}

void PlayerDashState::update(const float& dt)
{
	Dash& dash = owner.GetComponent<Dash>();

	if (dash.curDuration <= sf::milliseconds(0))
	{
		dash.isDashing = false;
		dash.curDuration = sf::milliseconds(dash.duration);
	}
	else
	{
		dash.curDuration -= sf::seconds(dt);
	}
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	//else if (owner.GetComponent<Animator>().armatureDisplay->getAnimation()->isCompleted())
	else if (!owner.GetComponent<Dash>().isDashing)
	{
		std::cout << "dash animation completed\n";
		if (owner.GetComponent<Attack>().isAttacking)
		{
			SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
			playerStates.currentState = playerStates.changeState(playerStates.currentState,
				new PlayerAttackState(owner));
			std::cout << "";
		}
		else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
		{
			SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
			playerStates.currentState = playerStates.changeState(playerStates.currentState,
				new PlayerMoveState(owner));
			std::cout << "";
		}
		else if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
		{
			SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
			playerStates.currentState = playerStates.changeState(playerStates.currentState,
				new PlayerIdleState(owner));
		}
	}
	
}

void PlayerDashState::exit()
{
	Movement& movement = owner.GetComponent<Movement>();
	Dash& dash = owner.GetComponent<Dash>();

	movement.speed = config.playerSpeed;

	Stamina& stamina = owner.GetComponent<Stamina>();
	stamina.canRestore = true;
}