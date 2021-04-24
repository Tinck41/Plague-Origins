#include "stdafx.h"
#include "Physics.h"

void Physics::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<RigidBody, Transform>();
	for (auto& entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Transform& transform = reg.get<Transform>(entity);

		transform.position.x = rigidBody.body->GetPosition().x * 30.f;
		transform.position.y = rigidBody.body->GetPosition().y * 30.f;
	}
}
