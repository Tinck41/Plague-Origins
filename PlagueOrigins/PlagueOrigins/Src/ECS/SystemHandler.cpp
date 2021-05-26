#include "stdafx.h"

#include "SystemHandler.h"

SystemHandler::SystemHandler()
{
	auto inputSystem		= new Input();
	auto controllerSystem	= new Controller();
	auto FSMSystem			= new FSM();
	auto animationSystem	= new Animation();
	auto physicsSystem		= new Physics();
	auto combatSystem		= new Combat();
	auto vampiringSystem	= new Vampiring();
	auto interactionSystem	= new Interaction();
	auto cameraSystem		= new Camera();
	auto motionSystem		= new Motion();
	auto actorSoundSystem	= new ActorSoundSystem();
	auto statsSystem		= new StatsSystem();
	auto healthSystem		= new HealthSystem();
	auto ambientSoundSystem = new AmbientSoundSystem();
	auto aggroSystem		= new AggroSystem();
	auto patrolSystem		= new PatrolSystem();
	auto disposalSystem		= new DisposalSystem();
	auto bossFightSystem	= new BossFight();
	auto staminaSystem		= new StaminaSystem();
	auto essenceSystem		= new EssenceSystem();
	auto overlaySystem		= new OverlaySystem();
	auto inventorySystem	= new InventorySystem();
	auto dialogueSystem		= new DialogueSystem();

	// Update systems
	updatableSystems.push_back(inputSystem);
	updatableSystems.push_back(controllerSystem);
	updatableSystems.push_back(FSMSystem);
	updatableSystems.push_back(animationSystem);
	updatableSystems.push_back(physicsSystem);
	updatableSystems.push_back(combatSystem);
	updatableSystems.push_back(vampiringSystem);
	updatableSystems.push_back(interactionSystem);
	updatableSystems.push_back(cameraSystem);
	updatableSystems.push_back(motionSystem);
	updatableSystems.push_back(actorSoundSystem);
	updatableSystems.push_back(statsSystem);
	updatableSystems.push_back(healthSystem);
	updatableSystems.push_back(ambientSoundSystem);
	updatableSystems.push_back(aggroSystem);
	updatableSystems.push_back(patrolSystem);
	updatableSystems.push_back(disposalSystem);
	updatableSystems.push_back(bossFightSystem);
	updatableSystems.push_back(staminaSystem);
	updatableSystems.push_back(essenceSystem);
	updatableSystems.push_back(overlaySystem);
	updatableSystems.push_back(inventorySystem);
	updatableSystems.push_back(dialogueSystem);

	// Render systems
	renderableSystems.push_back(animationSystem);
	renderableSystems.push_back(interactionSystem);
	renderableSystems.push_back(physicsSystem);
	renderableSystems.push_back(patrolSystem);
	renderableSystems.push_back(statsSystem);
	renderableSystems.push_back(healthSystem);
	renderableSystems.push_back(staminaSystem);
	renderableSystems.push_back(essenceSystem);
	renderableSystems.push_back(overlaySystem);
	renderableSystems.push_back(inventorySystem);
	renderableSystems.push_back(dialogueSystem);

	// OnCreate system
	onCreateSystems.push_back(animationSystem);
	onCreateSystems.push_back(actorSoundSystem);
	onCreateSystems.push_back(overlaySystem);
	onCreateSystems.push_back(inventorySystem);
	onCreateSystems.push_back(dialogueSystem);

	// Update && render && onCreate systems
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

	//onCreateSystems.clear();
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
