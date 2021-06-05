#include "stdafx.h"
#include "Physics.h"

void Physics::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<RigidBody, Transform>();
	for (auto& entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Transform& transform = reg.get<Transform>(entity);

		transform.position.x = rigidBody.body->GetPosition().x * 30.f;
		transform.position.y = rigidBody.body->GetPosition().y * 30.f;

		rigidBody.shape->setPosition(transform.position);
	}
}

void Physics::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<RigidBody, Transform>();
	for (auto& entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Transform& transform = reg.get<Transform>(entity);

		if (rigidBody.debugDraw)
		{
			window.draw(*rigidBody.shape);
		}
	}
}

void Physics::onDestroy(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<RigidBody, Transform>();
	for (auto& entity : view) 
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		b2Body* body = rigidBody.body;
		body->GetWorld()->DestroyBody(body);
		reg.destroy(entity);
	}
}
