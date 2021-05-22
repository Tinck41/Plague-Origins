#include "stdafx.h"

#include "SystemHandler.h"

SystemHandler::SystemHandler()
{
	ActorSoundSystem* actorSoundSystem = new ActorSoundSystem();
	StatsSystem* statsSystem = new StatsSystem();
	Animation* animation = new Animation();
	auto essence = new EssenceSystem();

	// Update systems
	updatableSystems.push_back(new Input());
	updatableSystems.push_back(new Controller());
	updatableSystems.push_back(new FSM());
	updatableSystems.push_back(animation);
	updatableSystems.push_back(new Physics());
	updatableSystems.push_back(new Combat());
	updatableSystems.push_back(new Vampiring());
	updatableSystems.push_back(new Interaction());
	updatableSystems.push_back(new Camera());
	updatableSystems.push_back(new Motion());
	updatableSystems.push_back(actorSoundSystem);
	updatableSystems.push_back(statsSystem);
	updatableSystems.push_back(new AmbientSoundSystem());
	updatableSystems.push_back(new AggroSystem());
	updatableSystems.push_back(new PatrolSystem());
	updatableSystems.push_back(new DisposalSystem());
	updatableSystems.push_back(essence);

	// Render systems
	renderableSystems.push_back(animation);
	renderableSystems.push_back(new Interaction());
	renderableSystems.push_back(new Physics());
	renderableSystems.push_back(new PatrolSystem());
	renderableSystems.push_back(statsSystem);
	renderableSystems.push_back(essence);

	// OnCreate system
	onCreateSystems.push_back(animation);
	onCreateSystems.push_back(actorSoundSystem);
	
	// Update && render && onCreate systems
	auto inventorySystem = new InventorySystem();
	updatableSystems.push_back(inventorySystem);
	renderableSystems.push_back(inventorySystem);
	onCreateSystems.push_back(inventorySystem);
	auto dialogueSystem = new DialogueSystem();
	updatableSystems.push_back(dialogueSystem);
	renderableSystems.push_back(dialogueSystem);
	onCreateSystems.push_back(dialogueSystem);
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
