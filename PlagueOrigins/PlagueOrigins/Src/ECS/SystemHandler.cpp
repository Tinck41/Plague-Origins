#include "stdafx.h"

#include "SystemHandler.h"
#include "Src/ECS/Systems/Input.h"
#include "Src/ECS/Systems/Animation.h"
#include "Src/ECS/Systems/Controller.h"
#include "Src/ECS/Systems/Physics.h"

SystemHandler::SystemHandler()
{
	// Update systems
	updatableSystems.push_back(new Input());
	updatableSystems.push_back(new Controller());
	updatableSystems.push_back(new Animation());
	updatableSystems.push_back(new Physics());

	// Render systems
	renderableSystems.push_back(new Animation());

	// OnCreate system
	onCreateSystems.push_back(new Animation());
}

SystemHandler::~SystemHandler()
{
	updatableSystems.clear();
	renderableSystems.clear();
}

void SystemHandler::onCreate(entt::registry& reg)
{
	for (auto& system : onCreateSystems)
	{
		system->onCreate(reg);
	}

	onCreateSystems.clear();
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
