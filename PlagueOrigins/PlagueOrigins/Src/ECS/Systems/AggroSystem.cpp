#include "stdafx.h"
#include "AggroSystem.h"

void AggroSystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<RigidBody, Aggresion>();
	for (auto entity : view)
	{
		
		
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Aggresion& aggresion = reg.get<Aggresion>(entity);
		
		b2Fixture* attackCircle = rigidBody.body->GetFixtureList();

		for (b2ContactEdge* edge = attackCircle->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (aggresion.isAggresive == true)
			{
				std::cout << "not in range\n";
				aggresion.isAggresive = false;
			}

			if (edge->contact->GetFixtureB() == attackCircle)
			{
				b2Body* bodyA = edge->contact->GetFixtureA()->GetBody();
				b2Body* bodyB = edge->contact->GetFixtureB()->GetBody();

				sf::Vector2f playerPos{ bodyA->GetPosition().x * 30.f, bodyA->GetPosition().y * 30.f };
				sf::Vector2f vectorToPlayer = playerPos - transform.position;
				sf::Vector2f directionVector{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };
				
				float angle = PhysicsWorld::angleBetween(vectorToPlayer, directionVector);

				if (angle <= 70.f && aggresion.isAggresive == false)
				{
					std::cout << "AGGRO\n";

					b2Vec2 normalizedVectorToPlayer;
					normalizedVectorToPlayer.x = vectorToPlayer.x;
					normalizedVectorToPlayer.y = vectorToPlayer.y;
					normalizedVectorToPlayer.Normalize();

					aggresion.isAggresive = true;
					aggresion.vectorToTarget.x = normalizedVectorToPlayer.x;
					aggresion.vectorToTarget.y = normalizedVectorToPlayer.y;
					break;
				}
				else if (angle > 70.f && aggresion.isAggresive == true)
				{
					std::cout << "angle >\n";
					aggresion.isAggresive = false;
				}
			}
		}
	}
}

void AggroSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
}
