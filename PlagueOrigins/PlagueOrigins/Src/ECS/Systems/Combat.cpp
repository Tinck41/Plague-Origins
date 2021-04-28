#include "stdafx.h"
#include "Combat.h"

void Combat::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Attack, RigidBody, Health, Animator>();
	for (auto& entity : view)
	{
		Attack& attack = reg.get<Attack>(entity);
		Health& senderHealth = reg.get<Health>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);

		if (attack.isAttacking)
		{
			int number = chooseSector(animator.currentFaceDirection);

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
								
								if (reg.all_of<Health>((entt::entity)bodyB->GetUserData().pointer))
								{
									Health& receiverHealth = reg.get<Health>((entt::entity)bodyB->GetUserData().pointer);
									receiverHealth.curhealth -= attack.damage;

									if (reg.all_of<Vampire>(entity))
									{
										Vampire& vampire = reg.get<Vampire>(entity);
										vampire.vampiredHealth = attack.damage / 100.f * 2.5f;
									}

									attack.isAttacking = false;

									break;
								}
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

int Combat::chooseSector(sf::Vector2f direction)
{
	int sector = 0;

	if (direction.x > 0 && direction.y < 0) 
	{
		sector = 0;
	}
	else if (direction.x == 0 && direction.y < 0)
	{
		sector = 1;
	}
	else if (direction.x < 0 && direction.y < 0)
	{
		sector = 2;
	}
	else if (direction.x < 0 && direction.y == 0)
	{
		sector = 3;
	}
	else if (direction.x < 0 && direction.y > 0)
	{
		sector = 4;
	}
	else if (direction.x == 0 && direction.y > 0)
	{
		sector = 5;
	}
	else if (direction.x > 0 && direction.y > 0)
	{
		sector = 6;
	}
	else if (direction.x > 0 && direction.y == 0)
	{
		sector = 7;
	}



	return sector;
}
