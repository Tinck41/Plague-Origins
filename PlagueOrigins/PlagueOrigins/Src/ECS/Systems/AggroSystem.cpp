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

				sf::Vector2f vec1{ bodyA->GetPosition().x * 30.f, bodyA->GetPosition().y * 30.f };
				vec1 = vec1 - transform.position;
				sf::Vector2f vec2{ animator.currentFaceDirection.x, animator.currentFaceDirection.y };

				float angle = PhysicsWorld::angleBetween(vec1, vec2);

				if (angle <= 70.f && aggresion.isAggresive == false)
				{
					std::cout << "AGGRO\n";
					aggresion.isAggresive = true;
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
