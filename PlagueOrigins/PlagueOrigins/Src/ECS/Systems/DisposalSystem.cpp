#include "stdafx.h"
#include "DisposalSystem.h"

void DisposalSystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Dispose>();

	for (auto entity : view)
	{
		Dispose& dispose = reg.get<Dispose>(entity);

		if (dispose.toDispose)
		{
			b2Body* body = reg.get<RigidBody>(entity).body;
			body->GetWorld()->DestroyBody(body);
			reg.remove_all(entity);
		}
	}
}
