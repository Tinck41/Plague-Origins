#include "stdafx.h"
#include "Controller.h"


void Controller::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Movement, RigidBody, PlayerInput, Dash>();
	for (auto entity : view)
	{
		Movement& movement = reg.get<Movement>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		Dash& dash = reg.get<Dash>(entity);

		setDirection(movement, playerInput);
		checkDash(playerInput, movement, dash, dt);

		if (!dash.isDashing)
			applyVelocity(movement, rigidBody, dt);
		else
			applyVelocity(dash, rigidBody, dt);
	}
}

void Controller::applyVelocity(Movement& movement, RigidBody& rigidBody, const float& dt)
{
	rigidBody.body->SetLinearVelocity(movement.speed * dt * b2Vec2(movement.direction.x, movement.direction.y));
}

void Controller::applyVelocity(Dash& dash, RigidBody& rigidBody, const float& dt)
{
	rigidBody.body->SetLinearVelocity(dash.speed * dt * b2Vec2(dash.direction.x, dash.direction.y));
}

void Controller::checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, const float& dt)
{
	if (playerInput.spaceWasPressed && dash.curCooldownTime < sf::seconds(0))
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
