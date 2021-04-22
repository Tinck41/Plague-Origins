#include "stdafx.h"

#include "SystemHandler.h"
#include "Src/ECS/Systems/Input.h"
#include "Src/ECS/Systems/Animation.h"

SystemHandler::SystemHandler()
{
	// Update systems
	updatableSystems.push_back(new Input());
	updatableSystems.push_back(new Animation());

	// Render systens

}

SystemHandler::~SystemHandler()
{
	for (auto& system : updatableSystems)
		delete system;

	for (auto& system : renderableSystems)
		delete system;

	updatableSystems.clear();
	renderableSystems.clear();
}

void SystemHandler::update(entt::registry& reg, const float& dt)
{
	for (auto& system : updatableSystems)
	{
		system->update(reg, dt);
	}
}

void SystemHandler::render(entt::registry& reg, sf::RenderWindow& window)
{
	for (auto& system : renderableSystems)
	{
		system->render(reg, window);
	}
}
