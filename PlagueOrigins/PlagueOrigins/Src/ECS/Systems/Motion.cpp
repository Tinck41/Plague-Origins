#include "stdafx.h"
#include "Motion.h"

void Motion::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<RigidBody, Movement>();

	for (auto entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Movement& movement = reg.get<Movement>(entity);

		rigidBody.body->SetLinearVelocity(movement.speed * dt * b2Vec2(movement.direction.x, movement.direction.y));
	}
}
