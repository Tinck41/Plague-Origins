#include "stdafx.h"
#include "Combat.h"

void Combat::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Attack, RigidBody, Health, Animator>();
	for (auto entity : view)
	{
		Attack& attack = reg.get<Attack>(entity);
		Health& senderHealth = reg.get<Health>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);
		Transform& transform = reg.get<Transform>(entity);

		if (attack.isAttacking)
		{
			b2Fixture* attackCircle = rigidBody.body->GetFixtureList();

			for (b2ContactEdge* edge = attackCircle->GetBody()->GetContactList(); edge; edge = edge->next)
			{
				if (edge->contact->GetFixtureB() == attackCircle)
				{
					b2Body* bodyA = edge->contact->GetFixtureA()->GetBody();
					b2Body* bodyB = edge->contact->GetFixtureB()->GetBody();

					sf::Vector2f vec1{ bodyA->GetPosition().x * 30.f, bodyA->GetPosition().y * 30.f };
					vec1 = vec1 - transform.position;
					sf::Vector2f vec2{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };

					float angle = angleBetween(vec1, vec2);

					if (angle <= 45.f)
					{
						if (reg.all_of<Health>((entt::entity)bodyA->GetUserData().pointer))
						{
							Health& receiverHealth = reg.get<Health>((entt::entity)bodyA->GetUserData().pointer);
							receiverHealth.curhealth -= attack.damage;

							if (reg.all_of<Vampire>(entity))
							{
								Vampire& vampire = reg.get<Vampire>(entity);
								vampire.vampiredHealth = attack.damage / 100.f * 2.5f;
							}
							
							std::cout << "Sender health: " << senderHealth.curhealth << "\n";
							std::cout << "Recevier health: " << receiverHealth.curhealth << "\n";

							attack.isAttacking = false;

							break;
						}
					}
					break;
				}
			}
			attack.isAttacking = false;
		}
	}
}

float Combat::angleBetween(sf::Vector2f vec1, sf::Vector2f vec2)
{
	float vec1Magnitude = std::sqrtf(vec1.x * vec1.x + vec1.y * vec1.y);
	float vec2Magnitude = std::sqrtf(vec2.x * vec2.x + vec2.y * vec2.y);

	float dotProduct = vec1.x * vec2.x + vec1.y * vec2.y;

	return std::acosf(dotProduct / (vec1Magnitude * vec2Magnitude)) * RADTODEG;
}
