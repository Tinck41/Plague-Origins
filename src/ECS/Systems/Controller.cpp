#include "stdafx.h"
#include "Controller.h"


void Controller::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Movement, RigidBody, PlayerInput, Animator, Dash, Attack>();
	for (auto entity : view)
	{
		Movement& movement = reg.get<Movement>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		Dash& dash = reg.get<Dash>(entity);
		Animator& animator = reg.get<Animator>(entity);
		Attack& attack = reg.get<Attack>(entity);
		Stamina& stamina = reg.get<Stamina>(entity);

		setDirection(movement, playerInput);
		checkDash(playerInput, movement, dash, stamina, dt);
		checkAttack(playerInput, attack, stamina);

		//std::cout << rigidBody.body->GetPosition().x * 30.f << " " 
		//		  << rigidBody.body->GetPosition().y * 30.f << " : player pos\n";
	}
}

void Controller::checkAttack(PlayerInput& playerInput, Attack& attack, Stamina& stamina)
{
	if (stamina.curStamina <= 0) return;

	if (playerInput.LMBwasPressed)
	{
		attack.isAttacking = true;
	}
}

void Controller::checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, Stamina& stamina, const float& dt)
{
	if (stamina.curStamina <= 0) return;
	if (movement.direction == sf::Vector2f(0.f, 0.f)) return;

	if (playerInput.spaceWasPressed && dash.curCooldownTime < sf::seconds(0.f))
	{
		dash.curCooldownTime = sf::seconds(dash.cooldownTime);
		dash.isDashing = true;
		dash.curDuration = sf::milliseconds(dash.duration);
		dash.direction = movement.direction;
	}
	else
	{
		dash.curCooldownTime -= sf::seconds(dt);
	}

	if (dash.isDashing)
	{
		if (dash.curDuration <= sf::milliseconds(0))
		{
			dash.isDashing = false;
			dash.curDuration = sf::milliseconds(dash.duration);
		}
		else
		{
			dash.curDuration -= sf::seconds(dt);
		}
	}
}

void Controller::setDirection(Movement& movement, PlayerInput& playerInput)
{
	b2Vec2 direction(0.f, 0.f);

	if (playerInput.wPressed)
	{
		direction.y = -1;
	}
	if (playerInput.sPressed)
	{
		direction.y = 1;
	}
	if (playerInput.aPressed)
	{
		direction.x = -1;
	}
	if (playerInput.dPressed)
	{
		direction.x = 1;
	}

	direction.Normalize();

	movement.direction.x = direction.x;
	movement.direction.y = direction.y;
}
