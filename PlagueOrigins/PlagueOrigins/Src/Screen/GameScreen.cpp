#include "stdafx.h"
#include "GameScreen.h"

#include "Src/FSM/States/Player/PlayerStates.h"
#include "Src/FSM/States/Dog/DogStates.h"
#include "Src/FSM/States/Bishop/BishopStates.h"
#include "Src/FSM/States/Boss/BossStates.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/newTiles_map2.json", &registry, this))
	{
		map = mapLoader.getTileMap();
	}
	mapLoader.~TilemapParser();

	gui.loadWidgetsFromFile("./Assets/UI/Game.txt");

	screenManager = Entity(registry.create(), this);
	
	screenManager.AddComponent<CurrentScreen>(ScreenType::GAME);

	//PLAYER
	testEntity = Entity(registry.create(), this);
	testEntity.AddComponent<Transform>();
	testEntity.AddComponent<PlayerInput>();
	testEntity.AddComponent<ActorAudioSource>();
	testEntity.AddComponent<Animator>(config.playerScale);
	testEntity.AddComponent<Movement>(config.playerSpeed);
	testEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(315.f, 615.f), true, testEntity, PLAYER);
	testEntity.AddComponent<Tag>("Hero");
	testEntity.AddComponent<CameraTarget>(sf::Vector2f(config.width(), config.height()), map.getSize());
	testEntity.AddComponent<Vampire>();
	testEntity.AddComponent<SMcomponent>(new PlayerIdleState(testEntity));
	testEntity.AddComponent<Inventory>();
	testEntity.AddComponent<Player>();
	testEntity.AddComponent<Dialogue>(testEntity.GetComponent<RigidBody>().body, 75.f);

	testEntity.AddComponent<Stats>(config.playerStats);
	auto playerStats = testEntity.GetComponent<Stats>();
	testEntity.AddComponent<Health>(playerStats.VIT);
	testEntity.AddComponent<Stamina>(playerStats.END);
	testEntity.AddComponent<Attack>(testEntity.GetComponent<RigidBody>().body, playerStats.STR, config.playerAttackRange);
	testEntity.AddComponent<Dash>(playerStats.AGI);


	//AMBIENT AUDIO
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


	//DOG
	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>(config.dogScale);
	npcEntity.AddComponent<Movement>(300.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, npcEntity, ENEMY_NPC);
	npcEntity.AddComponent<Aggresion>(npcEntity.GetComponent<RigidBody>().body, 300.f, 60.f);
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


	//BISHOP
	bishop = Entity(registry.create(), this);
	bishop.AddComponent<Transform>();
	bishop.AddComponent<Animator>(config.bishopScale);
	bishop.AddComponent<Movement>(500.f);
	bishop.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(415.f, 615.f), false, bishop, FRIENDLY_NPC);
	bishop.AddComponent<Tag>("Bishop");
	//bishop.AddComponent<Interact>(bishop.GetComponent<RigidBody>().body, 30.f, "Press F to pay respect");
	bishop.AddComponent<Dialogue>(bishop.GetComponent<RigidBody>().body, 75.f);
	bishop.AddComponent<SMcomponent>(new BishopIdleState(bishop));

	bishop.AddComponent<Stats>(config.bishopStats);
	auto bishopStats = bishop.GetComponent<Stats>();
	bishop.AddComponent<Health>(bishopStats.VIT);


	//BOSS
	boss = Entity(registry.create(), this);
	boss.AddComponent<Transform>();
	boss.AddComponent<Animator>(config.bossScale);
	boss.AddComponent<Movement>(300.f);
	boss.AddComponent<RigidBody>(sf::Vector2f(75.f, 135.f), sf::Vector2f(8200.f, 9000.f), true, boss, ENEMY_NPC);
	boss.AddComponent<Tag>("Boss");
	boss.AddComponent<ActorAudioSource>();
	boss.AddComponent<SMcomponent>(new BossIdleState(boss));
	boss.AddComponent<Dispose>();
	boss.AddComponent<Boss>();

	boss.AddComponent<Stats>(config.bossStats);
	auto bossStats = boss.GetComponent<Stats>();
	boss.AddComponent<Health>(bossStats.VIT);
	boss.AddComponent<Attack>(boss.GetComponent<RigidBody>().body, bossStats.STR, config.bossAttackRange);

	//TO-DO find other solution
	//add pointer to boss body
	testEntity.GetComponent<Player>().bossBody = boss.GetComponent<RigidBody>().body;
	testEntity.GetComponent<Dialogue>().bishop = bishop;

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

	return (ScreenType)screenManager.GetComponent<CurrentScreen>().type;
}

