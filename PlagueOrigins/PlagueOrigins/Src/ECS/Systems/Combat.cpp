#include "stdafx.h"
#include "Combat.h"

void Combat::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
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
			if (sf::seconds(animator.currentAnimationDurationLeft).asMilliseconds() <
				sf::seconds(animator.currentAnimationDuration / 1.5f).asMilliseconds())
			{
				return;
			}

 			b2Fixture* attackCircle = rigidBody.body->GetFixtureList();
			while (attackCircle->GetUserData().pointer != ATTACK_RADIUS)
			{
				attackCircle = attackCircle->GetNext();
			}

			for (b2ContactEdge* edge = attackCircle->GetBody()->GetContactList(); edge; edge = edge->next)
			{
				if (edge->contact->GetFixtureB() == attackCircle)
				{

					b2Body* bodyA = edge->contact->GetFixtureA()->GetBody();
					b2Body* bodyB = edge->contact->GetFixtureB()->GetBody();

					sf::Vector2f vec1{ bodyA->GetPosition().x * 30.f, bodyA->GetPosition().y * 30.f };
					vec1 = vec1 - transform.position;
					float vec1Magnitude = std::sqrtf(vec1.x * vec1.x + vec1.y * vec1.y);
					sf::Vector2f vec2{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };

					float angle = PhysicsWorld::angleBetween(vec1, vec2);

					if (angle <= 45.f && vec1Magnitude < attack.radius)
					{
						auto receiverEntity = (entt::entity)bodyA->GetUserData().pointer;
						if (reg.all_of<Health>(receiverEntity))
						{
							Health& receiverHealth = reg.get<Health>(receiverEntity);
							receiverHealth.curhealth -= attack.damage;

							if (reg.all_of<ActorAudioSource>((entt::entity)bodyA->GetUserData().pointer))
							{
								ActorAudioSource& soundSource = reg.get<ActorAudioSource>(receiverEntity);
								soundSource.playGetHitSound = true;
							}

							if (reg.all_of<Vampire>(entity))
							{
								Vampire& vampire = reg.get<Vampire>(entity);
								vampire.vampiredHealth = attack.damage / 100.f * 2.5f;
							}

							if (receiverHealth.curhealth <= 0
								&& reg.all_of<Tag>(receiverEntity)
								&& reg.all_of<Inventory>(entity)
								&& reg.all_of<Dispose>(receiverEntity))
							{
								Tag& attackerTag = reg.get<Tag>(entity);
								Tag& receiverTag = reg.get<Tag>(receiverEntity);
								Dispose& dispose = reg.get<Dispose>(receiverEntity);

								if (attackerTag.name == "Hero" && receiverTag.name == "Dog" && !dispose.isDead)
								{
									reg.get<Inventory>(entity).essence += 350.f;
								}
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
