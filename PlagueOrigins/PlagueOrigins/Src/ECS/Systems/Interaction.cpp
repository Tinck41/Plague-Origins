#include "stdafx.h"
#include "Interaction.h"

void Interaction::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Interact, Transform, Animator>();

	for (auto entity : view)
	{
		Interact& interact = reg.get<Interact>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Animator& animator = reg.get<Animator>(entity);

		interact.interactionZone.setPosition((1 / animator.scale) * transform.position);
	}
}

void Interaction::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Interact, Transform, Animator, RigidBody>();

	for (auto entity : view)
	{
		Interact& interact = reg.get<Interact>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Animator& animator = reg.get<Animator>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		interact.canInteract = checkForPlayer(rigidBody);

		if (interact.canInteract)
		{
			sf::Text text;

			text.setFont(config.font);
			text.setString(interact.text);
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::Red);
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			auto view = reg.view<CameraTarget, Transform>();
			for (auto player : view)
			{
				CameraTarget& camera = reg.get<CameraTarget>(player);
				Transform& transform = reg.get<Transform>(player);
				Player& pl = reg.get<Player>(player);

				text.setPosition(camera.camera.getCenter().x,
					camera.camera.getCenter().y + camera.camera.getSize().y / 3.f);
			}

			window.draw(text);
			window.draw(interact.interactionZone, animator.states);
		}
	}
}

bool Interaction::checkForPlayer(RigidBody& rigidBody)
{
	for (b2Fixture* f = rigidBody.body->GetFixtureList(); f; f = f->GetNext())
	{
		for (b2ContactEdge* edge = f->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->IsTouching())
			{
				if (edge->contact->GetFixtureA()->GetUserData().pointer == PLAYER)
				{
					return true;
				}
			}
		}
	}

	return false;
}

