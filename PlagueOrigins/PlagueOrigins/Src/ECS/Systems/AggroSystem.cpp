#include "stdafx.h"
#include "AggroSystem.h"

void AggroSystem::update(entt::registry& reg, const float& dt)
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
				sf::Vector2f directionVector{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };
				
				float angle = PhysicsWorld::angleBetween(vectorToPlayer, directionVector);

				if (angle <= 60.f)
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
				else if (angle > 60.f)
				{
					std::cout << "angle >\n";
					aggresion.isAggresive = false;
				}
			}
		}
		if (!playerFound)
		{
			std::cout << "player out of range\n";
			aggresion.isAggresive = false;
		}
	}
}

void AggroSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
}
