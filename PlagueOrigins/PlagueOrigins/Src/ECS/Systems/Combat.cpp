#include "stdafx.h"
#include "Combat.h"

void Combat::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Attack, Health, RigidBody, Transform, Animator>();
	for (auto& entity : view)
	{
		Attack& attack = reg.get<Attack>(entity);
		Health& health = reg.get<Health>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Animator& animator = reg.get<Animator>(entity);

		if (attack.isAttacking)
		{
			int number = 1;

			int i = 0;
			for (b2Fixture* f = rigidBody.body->GetFixtureList(); f; f = f->GetNext())
			{
				if (number == i)
				{
					for (b2ContactEdge* edge = f->GetBody()->GetContactList(); edge; edge = edge->next)
					{
						if (edge->contact->IsTouching())
						{
							if (f == edge->contact->GetFixtureA())
							{
								b2Body* bodyB = edge->contact->GetFixtureB()->GetBody();

								Health& health = reg.get<Health>((entt::entity)bodyB->GetUserData().pointer);
								health.curhealth -= attack.damage;

								attack.isAttacking = false;

								break;
							}
						}
					}
					break;
				}
				i++;
			}
			attack.isAttacking = false;
		}
	}
}
