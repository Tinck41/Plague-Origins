#include "stdafx.h"

#include "SystemHandler.h"

SystemHandler::SystemHandler()
{
	// Update systems
	updatableSystems.push_back(new Input());
	updatableSystems.push_back(new Controller());
	updatableSystems.push_back(new FSM());
	updatableSystems.push_back(new Animation());
	updatableSystems.push_back(new Physics());
	updatableSystems.push_back(new Combat());
	updatableSystems.push_back(new Vampiring());
	updatableSystems.push_back(new Interaction());
	updatableSystems.push_back(new Camera());
	updatableSystems.push_back(new Motion());
	updatableSystems.push_back(new AggroSystem());
	updatableSystems.push_back(new PatrolSystem());
	updatableSystems.push_back(new DisposalSystem());

	// Render systems
	renderableSystems.push_back(new Animation());
	renderableSystems.push_back(new Interaction());
	renderableSystems.push_back(new Physics());
	renderableSystems.push_back(new PatrolSystem());

	// OnCreate system
	onCreateSystems.push_back(new Animation());
	
	// Update && render && onCreate systems
	auto inventorySystem = new InventorySystem();
	updatableSystems.push_back(inventorySystem);
	renderableSystems.push_back(inventorySystem);
	onCreateSystems.push_back(inventorySystem);
}

SystemHandler::~SystemHandler()
{
	updatableSystems.clear();
	renderableSystems.clear();
}

void SystemHandler::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	for (auto& system : onCreateSystems)
	{
		system->onCreate(reg, gui);
	}

	onCreateSystems.clear();
}

void SystemHandler::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	for (auto& system : updatableSystems)
	{
		system->update(reg, gui, dt);
	}
}

void SystemHandler::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	for (auto& system : renderableSystems)
	{
		system->render(reg, window, gui);
	}
}
