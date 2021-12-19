#include "stdafx.h"
#include "AggroSystem.h"

void AggroSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<RigidBody, Aggresion, Transform, Animator>();
	for (auto entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Aggresion& aggresion = reg.get<Aggresion>(entity);
		
		b2Fixture* aggroCircle = rigidBody.body->GetFixtureList();
		while (aggroCircle->GetUserData().pointer != ENEMY_AGGRO_RADIUS)
		{
			aggroCircle = aggroCircle->GetNext();
		}
		bool playerFound = false;

		for (b2ContactEdge* edge = aggroCircle->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->GetFixtureB() == aggroCircle && edge->contact->GetFixtureA()->GetUserData().pointer == PLAYER)
			{
				playerFound = true;
				b2Body* bodyA = edge->contact->GetFixtureA()->GetBody();
				b2Body* bodyB = edge->contact->GetFixtureB()->GetBody();

				sf::Vector2f playerPos{ bodyA->GetPosition().x * 30.f, bodyA->GetPosition().y * 30.f };
				sf::Vector2f vectorToPlayer = playerPos - transform.position;
				aggresion.distanceToTarget = sqrtf(std::pow(vectorToPlayer.x, 2) + std::pow(vectorToPlayer.y, 2));
				sf::Vector2f directionVector{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };
				
				float angle = PhysicsWorld::angleBetween(vectorToPlayer, directionVector);

				if (angle <= aggresion.angle)
				{
					b2Vec2 normalizedVectorToPlayer;
					//normalizedVectorToPlayer.x = vectorToPlayer.x;
					//normalizedVectorToPlayer.y = vectorToPlayer.y;
					//normalizedVectorToPlayer.Normalize();
					if (transform.position.x < playerPos.x - 15.f)
					{
						normalizedVectorToPlayer.x = 1.f;
					}
					else if (transform.position.x > playerPos.x + 15.f)
					{
						normalizedVectorToPlayer.x = -1.f;
					}
					else if (std::fabs(transform.position.x - playerPos.x) <= 15.f)
					{
						normalizedVectorToPlayer.x = 0.f;
					}
					if (transform.position.y < playerPos.y - 15.f)
					{
						normalizedVectorToPlayer.y = 1.f;
					}
					else if (transform.position.y > playerPos.y + 15.f)
					{
						normalizedVectorToPlayer.y = -1.f;
					}
					else if (std::fabs(transform.position.y - playerPos.y) <= 15.f)
					{
						normalizedVectorToPlayer.y = 0.f;
					}
					normalizedVectorToPlayer.Normalize();

					aggresion.isAggresive = true;
					aggresion.vectorToTarget.x = normalizedVectorToPlayer.x;
					aggresion.vectorToTarget.y = normalizedVectorToPlayer.y;
					break;
				}
				else if (angle > aggresion.angle)
				{
					aggresion.isAggresive = false;
				}
			}
		}
		if (!playerFound)
		{
			aggresion.isAggresive = false;
		}
	}
}
