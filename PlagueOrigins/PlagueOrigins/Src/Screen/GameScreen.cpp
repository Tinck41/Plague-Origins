#include "stdafx.h"
#include "GameScreen.h"

#include "Src/FSM/States/Player/PlayerStates.h"
#include "Src/FSM/States/Dog/DogStates.h"
#include "Src/FSM/States/Bishop/BishopStates.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/newTiles_map.json", &registry, this))
	{
		map = mapLoader.getTileMap();
	}
	mapLoader.~TilemapParser();

	gui.loadWidgetsFromFile("./Assets/UI/Game.txt");
	
	testEntity = Entity(registry.create(), this);
	testEntity.AddComponent<Transform>();
	testEntity.AddComponent<PlayerInput>();
	testEntity.AddComponent<ActorAudioSource>();
	testEntity.AddComponent<Animator>();
	testEntity.AddComponent<Movement>(config.playerSpeed);
	testEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(315.f, 615.f), true, testEntity, PLAYER);
	testEntity.AddComponent<Tag>("Hero");
	testEntity.AddComponent<CameraTarget>(sf::Vector2f(config.width(), config.height()), map.getSize());
	testEntity.AddComponent<Vampire>();
	testEntity.AddComponent<SMcomponent>(new PlayerIdleState(testEntity));
	testEntity.AddComponent<Inventory>();
	testEntity.AddComponent<Player>();
	testEntity.AddComponent<Dialogue>();

	testEntity.AddComponent<Stats>(config.playerStats);
	auto playerStats = testEntity.GetComponent<Stats>();
	testEntity.AddComponent<Health>(playerStats.VIT);
	testEntity.AddComponent<Stamina>(playerStats.END);
	testEntity.AddComponent<Attack>(testEntity.GetComponent<RigidBody>().body, playerStats.STR, config.playerAttackRange);
	testEntity.AddComponent<Dash>(playerStats.AGI);

	Entity ambient = Entity(registry.create(), this);
	ambient.AddComponent<AmbienceAudioSource>();

	Entity ring1 = Entity(registry.create(), this);
	ring1.AddComponent<Item>("Broken ring", RING);
	ring1.AddComponent<ItemOwner>(testEntity);
	ring1.AddComponent<Description>("It's absolutely trash... Why are you carrying that?");
	ring1.AddComponent<Icon>("./Assets/UI/trashRing.png");
	ring1.AddComponent<HealthBoost>(-0.1f);

	Entity ring2 = Entity(registry.create(), this);
	ring2.AddComponent<Item>("Health ring", RING);
	ring2.AddComponent<ItemOwner>(testEntity);
	ring2.AddComponent<Description>("Ring with a dull red stone.\n\nIncreases owner health.");
	ring2.AddComponent<Icon>("./Assets/UI/healthRing.png");
	ring2.AddComponent<HealthBoost>(.2f);

	testEntity.GetComponent<Inventory>().items.push_back(ring1);
	testEntity.GetComponent<Inventory>().items.push_back(ring2);

	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>();
	npcEntity.AddComponent<Movement>(300.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, npcEntity, ENEMY_NPC);
	npcEntity.AddComponent<Aggresion>(npcEntity.GetComponent<RigidBody>().body, 300.f);
	npcEntity.AddComponent<Tag>("Dog");
	npcEntity.AddComponent<ActorAudioSource>();
	npcEntity.AddComponent<SMcomponent>(new DogIdleState(npcEntity));
	std::vector<sf::Vector2f> waypoints;
	waypoints.push_back(sf::Vector2f(615.f,615.f));
	waypoints.push_back(sf::Vector2f(615.f,915.f));
	npcEntity.AddComponent<Patrol>(waypoints);
	npcEntity.AddComponent<Dispose>();

	npcEntity.AddComponent<Stats>(config.dogStats);
	auto dogStats = npcEntity.GetComponent<Stats>();
	npcEntity.AddComponent<Health>(dogStats.VIT);
	npcEntity.AddComponent<Attack>(npcEntity.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange);

	bishop = Entity(registry.create(), this);
	bishop.AddComponent<Transform>();
	bishop.AddComponent<Animator>();
	//   ?
	bishop.AddComponent<Movement>(500.f);
	bishop.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(415.f, 615.f), false, bishop, FRIENDLY_NPC);
	bishop.AddComponent<Tag>("Bishop");
	bishop.AddComponent<Interact>(bishop.GetComponent<RigidBody>().body, 30.f, "Press F to pay respect");
	bishop.AddComponent<SMcomponent>(new BishopIdleState(bishop));

	bishop.AddComponent<Stats>(config.bishopStats);
	auto bishopStats = bishop.GetComponent<Stats>();
	bishop.AddComponent<Health>(bishopStats.VIT);

	systems.onCreate(registry, gui);
}

GameScreen::~GameScreen()
{

}

void GameScreen::update(const float& dt)
{
	map.update(dt);
	GlobalFactory::Instance().factory.update(dt);
	systems.update(registry, gui, dt);
	PhysicsWorld::update(dt);
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	gui.setTarget(window);
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		
		gui.handleEvent(event);
	}

	tgui::FloatRect visibleArea(0, 0, config.uiWidth, config.uiHeight);
	gui.setAbsoluteView(visibleArea);

	map.renderUnderPlayerLayers(window);
	systems.render(registry, window, gui);
	map.renderOverPlayerLayers(window);
	
	gui.draw();

	auto view = registry.view<CameraTarget>();
	for (auto& entity : view)
	{
		CameraTarget& camera = registry.get<CameraTarget>(entity);
		window.setView(camera.camera);
	}

	return ScreenType::GAME;
}

