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

	// AMBIENT AUDIO
	Entity ambient = Entity(registry.create(), this);
	ambient.AddComponent<AmbienceAudioSource>();

	start();
}

GameScreen::~GameScreen()
{

}

void GameScreen::exit()
{
	//registry.clear<Health>();

	registry.destroy(playerEnt);
	registry.destroy(bishopEnt1);
	registry.destroy(bishopEnt2);
	registry.destroy(bossEnt);
	registry.destroy(dogEnt1);
	registry.destroy(dogEnt2);
	registry.destroy(dogEnt3);
	registry.destroy(dogEnt4);
	registry.destroy(dogEnt5);
	registry.destroy(dogEnt6);
	registry.destroy(dogEnt7);
}

void GameScreen::start()
{
	gui.loadWidgetsFromFile("./Assets/UI/Game.txt");

	screenManager = Entity(registry.create(), this);

	screenManager.AddComponent<CurrentScreen>(ScreenType::GAME);

	//PLAYER
	playerEnt = Entity(registry.create(), this);
	playerEnt.AddComponent<Transform>();
	playerEnt.AddComponent<PlayerInput>();
	playerEnt.AddComponent<ActorAudioSource>();
	playerEnt.AddComponent<Animator>(config.playerScale);
	playerEnt.AddComponent<Movement>(config.playerSpeed);
	playerEnt.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(8700.f, 5770.f), true, playerEnt, PLAYER, OBSTACLE | ATTACK_RADIUS);
	playerEnt.AddComponent<Tag>("Hero");
	playerEnt.AddComponent<CameraTarget>(sf::Vector2f(config.width(), config.height()), map.getSize());
	playerEnt.AddComponent<Vampire>();
	playerEnt.AddComponent<SMcomponent>(new PlayerIdleState(playerEnt));
	playerEnt.AddComponent<Inventory>();
	playerEnt.AddComponent<Player>();
	playerEnt.AddComponent<Dialogue>(playerEnt.GetComponent<RigidBody>().body, 75.f);

	playerEnt.AddComponent<Stats>(config.playerStats);
	auto playerStats = playerEnt.GetComponent<Stats>();
	playerEnt.AddComponent<Health>(playerStats.VIT);
	playerEnt.AddComponent<Stamina>(playerStats.END);
	playerEnt.AddComponent<Attack>(playerEnt.GetComponent<RigidBody>().body, playerStats.STR, config.playerAttackRange, ENEMY_NPC | FRIENDLY_NPC);
	playerEnt.AddComponent<Dash>(playerStats.AGI);

	//BISHOPS

	//bishop1
	bishopEnt1 = Entity(registry.create(), this);
	bishopEnt1.AddComponent<Transform>();
	bishopEnt1.AddComponent<Animator>(config.bishopScale);
	bishopEnt1.AddComponent<Movement>(500.f);
	bishopEnt1.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(2250.f, 7960.f), false, bishopEnt1, FRIENDLY_NPC, OBSTACLE | ATTACK_RADIUS | INTERACTION_ZONE);
	bishopEnt1.AddComponent<Tag>("Bishop");
	bishopEnt1.AddComponent<Dialogue>(bishopEnt1.GetComponent<RigidBody>().body, 75.f);
	bishopEnt1.AddComponent<SMcomponent>(new BishopIdleState(bishopEnt1));
	registry.emplace<NPC>(bishopEnt1);

	bishopEnt1.AddComponent<Stats>(config.bishopStats);
	auto bishopStats = bishopEnt1.GetComponent<Stats>();
	bishopEnt1.AddComponent<Health>(bishopStats.VIT);

	//bishop2
	bishopEnt2 = Entity(registry.create(), this);
	bishopEnt2.AddComponent<Transform>();
	bishopEnt2.AddComponent<Animator>(config.bishopScale);
	bishopEnt2.AddComponent<Movement>(500.f);
	bishopEnt2.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(8800.f, 5770.f), false, bishopEnt2, FRIENDLY_NPC, OBSTACLE | ATTACK_RADIUS | INTERACTION_ZONE);
	bishopEnt2.AddComponent<Tag>("Bishop");
	bishopEnt2.AddComponent<Dialogue>(bishopEnt2.GetComponent<RigidBody>().body, 75.f);
	bishopEnt2.AddComponent<SMcomponent>(new BishopIdleState(bishopEnt2));
	registry.emplace<NPC>(bishopEnt2);

	bishopEnt2.AddComponent<Stats>(config.bishopStats);
	bishopStats = bishopEnt2.GetComponent<Stats>();
	bishopEnt2.AddComponent<Health>(bishopStats.VIT);

	//BOSS
	bossEnt = Entity(registry.create(), this);
	bossEnt.AddComponent<Transform>();
	bossEnt.AddComponent<Animator>(config.bossScale);
	bossEnt.AddComponent<Movement>(300.f);
	bossEnt.AddComponent<RigidBody>(sf::Vector2f(75.f, 135.f), sf::Vector2f(8200.f, 9000.f), true, bossEnt, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	bossEnt.AddComponent<Tag>("Boss");
	bossEnt.AddComponent<ActorAudioSource>();
	bossEnt.AddComponent<SMcomponent>(new BossIdleState(bossEnt));
	bossEnt.AddComponent<Dispose>();
	bossEnt.AddComponent<Boss>();
	registry.emplace<NPC>(bossEnt);

	bossEnt.AddComponent<Stats>(config.bossStats);
	auto bossStats = bossEnt.GetComponent<Stats>();
	bossEnt.AddComponent<Health>(bossStats.VIT);
	bossEnt.AddComponent<Attack>(bossEnt.GetComponent<RigidBody>().body, bossStats.STR, config.bossAttackRange, PLAYER);

	//TO-DO find other solution
	//add pointer to boss body
	playerEnt.GetComponent<Player>().bossBody = bossEnt.GetComponent<RigidBody>().body;
	playerEnt.GetComponent<Dialogue>().bishop1 = bishopEnt1;
	playerEnt.GetComponent<Dialogue>().bishop2 = bishopEnt2;
	
	// RINGS
	ring1 = Entity(registry.create(), this);
	ring1.AddComponent<Item>("Broken ring", RING);
	ring1.AddComponent<ItemOwner>(playerEnt);
	ring1.AddComponent<Description>("It's absolutely trash... Why are you carrying that?");
	ring1.AddComponent<Icon>("./Assets/UI/trashRing.png");
	ring1.AddComponent<HealthBoost>(-0.1f);

	ring2 = Entity(registry.create(), this);
	ring2.AddComponent<Item>("Health ring", RING);
	ring2.AddComponent<ItemOwner>(playerEnt);
	ring2.AddComponent<Description>("Ring with a dull red stone.\n\nIncreases owner health.");
	ring2.AddComponent<Icon>("./Assets/UI/healthRing.png");
	ring2.AddComponent<HealthBoost>(.2f);

	playerEnt.GetComponent<Inventory>().items.push_back(ring1);
	playerEnt.GetComponent<Inventory>().items.push_back(ring2);

	//DOGS

	std::vector<sf::Vector2f> waypoints;
	//DOG1
	dogEnt1 = Entity(registry.create(), this);
	dogEnt1.AddComponent<Transform>();
	dogEnt1.AddComponent<Animator>(config.dogScale);
	dogEnt1.AddComponent<Movement>(300.f);
	dogEnt1.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(2615.f, 11100.f), true, dogEnt1, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt1.AddComponent<Aggresion>(dogEnt1.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt1.AddComponent<Tag>("Dog");
	dogEnt1.AddComponent<ActorAudioSource>();
	dogEnt1.AddComponent<SMcomponent>(new DogIdleState(dogEnt1));
	waypoints.push_back(sf::Vector2f(2615.f, 11100.f));
	waypoints.push_back(sf::Vector2f(4160.f, 11100.f));
	dogEnt1.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt1.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt1);

	dogEnt1.AddComponent<Stats>(config.dogStats);
	auto dogStats = dogEnt1.GetComponent<Stats>();
	dogEnt1.AddComponent<Health>(dogStats.VIT);
	dogEnt1.AddComponent<Attack>(dogEnt1.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 2
	dogEnt2 = Entity(registry.create(), this);
	dogEnt2.AddComponent<Transform>();
	dogEnt2.AddComponent<Animator>(config.dogScale);
	dogEnt2.AddComponent<Movement>(300.f);
	dogEnt2.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(4750.f, 11100.f), true, dogEnt2, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt2.AddComponent<Aggresion>(dogEnt2.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt2.AddComponent<Tag>("Dog");
	dogEnt2.AddComponent<ActorAudioSource>();
	dogEnt2.AddComponent<SMcomponent>(new DogIdleState(dogEnt2));
	waypoints.push_back(sf::Vector2f(4750.f, 11100.f));
	waypoints.push_back(sf::Vector2f(4750.f, 10500.f));
	dogEnt2.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt2.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt2);

	dogEnt2.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt2.GetComponent<Stats>();
	dogEnt2.AddComponent<Health>(dogStats.VIT);
	dogEnt2.AddComponent<Attack>(dogEnt2.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 3
	dogEnt3 = Entity(registry.create(), this);
	dogEnt3.AddComponent<Transform>();
	dogEnt3.AddComponent<Animator>(config.dogScale);
	dogEnt3.AddComponent<Movement>(300.f);
	dogEnt3.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(5580.f, 7000.f), true, dogEnt3, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt3.AddComponent<Aggresion>(dogEnt3.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt3.AddComponent<Tag>("Dog");
	dogEnt3.AddComponent<ActorAudioSource>();
	dogEnt3.AddComponent<SMcomponent>(new DogIdleState(dogEnt3));
	waypoints.push_back(sf::Vector2f(5580.f, 7100.f));
	waypoints.push_back(sf::Vector2f(5580.f, 6200.f));
	dogEnt3.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt3.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt3);

	dogEnt3.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt3.GetComponent<Stats>();
	dogEnt3.AddComponent<Health>(dogStats.VIT);
	dogEnt3.AddComponent<Attack>(dogEnt3.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 4
	dogEnt4 = Entity(registry.create(), this);
	dogEnt4.AddComponent<Transform>();
	dogEnt4.AddComponent<Animator>(config.dogScale);
	dogEnt4.AddComponent<Movement>(300.f);
	dogEnt4.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(5450.f, 3650.f), true, dogEnt4, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt4.AddComponent<Aggresion>(dogEnt4.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt4.AddComponent<Tag>("Dog");
	dogEnt4.AddComponent<ActorAudioSource>();
	dogEnt4.AddComponent<SMcomponent>(new DogIdleState(dogEnt4));
	waypoints.push_back(sf::Vector2f(5450.f, 3650.f));
	waypoints.push_back(sf::Vector2f(5220.f, 3650.f));
	waypoints.push_back(sf::Vector2f(5220.f, 3900.f));
	waypoints.push_back(sf::Vector2f(5220.f, 3650.f));
	dogEnt4.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt4.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt4);

	dogEnt4.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt4.GetComponent<Stats>();
	dogEnt4.AddComponent<Health>(dogStats.VIT);
	dogEnt4.AddComponent<Attack>(dogEnt4.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 5
	dogEnt5 = Entity(registry.create(), this);
	dogEnt5.AddComponent<Transform>();
	dogEnt5.AddComponent<Animator>(config.dogScale);
	dogEnt5.AddComponent<Movement>(300.f);
	dogEnt5.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(6500.f, 3650.f), true, dogEnt5, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt5.AddComponent<Aggresion>(dogEnt5.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt5.AddComponent<Tag>("Dog");
	dogEnt5.AddComponent<ActorAudioSource>();
	dogEnt5.AddComponent<SMcomponent>(new DogIdleState(dogEnt5));
	waypoints.push_back(sf::Vector2f(7000.f, 3650.f));
	waypoints.push_back(sf::Vector2f(7500.f, 3650.f));
	dogEnt5.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt5.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt5);

	dogEnt5.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt5.GetComponent<Stats>();
	dogEnt5.AddComponent<Health>(dogStats.VIT);
	dogEnt5.AddComponent<Attack>(dogEnt5.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 6
	dogEnt6 = Entity(registry.create(), this);
	dogEnt6.AddComponent<Transform>();
	dogEnt6.AddComponent<Animator>(config.dogScale);
	dogEnt6.AddComponent<Movement>(300.f);
	dogEnt6.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(8170.f, 4500.f), true, dogEnt6, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt6.AddComponent<Aggresion>(dogEnt6.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt6.AddComponent<Tag>("Dog");
	dogEnt6.AddComponent<ActorAudioSource>();
	dogEnt6.AddComponent<SMcomponent>(new DogIdleState(dogEnt6));
	waypoints.push_back(sf::Vector2f(7450.f, 3900.f));
	waypoints.push_back(sf::Vector2f(8170.f, 3900.f));
	waypoints.push_back(sf::Vector2f(8170.f, 4300.f));
	waypoints.push_back(sf::Vector2f(8170.f, 3900.f));
	dogEnt6.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt6.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt6);

	dogEnt6.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt6.GetComponent<Stats>();
	dogEnt6.AddComponent<Health>(dogStats.VIT);
	dogEnt6.AddComponent<Attack>(dogEnt6.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	//DOG 7
	dogEnt7 = Entity(registry.create(), this);
	dogEnt7.AddComponent<Transform>();
	dogEnt7.AddComponent<Animator>(config.dogScale);
	dogEnt7.AddComponent<Movement>(300.f);
	dogEnt7.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(8200.f, 6000.f), true, dogEnt7, ENEMY_NPC, OBSTACLE | ATTACK_RADIUS);
	dogEnt7.AddComponent<Aggresion>(dogEnt7.GetComponent<RigidBody>().body, 300.f, 60.f);
	dogEnt7.AddComponent<Tag>("Dog");
	dogEnt7.AddComponent<ActorAudioSource>();
	dogEnt7.AddComponent<SMcomponent>(new DogIdleState(dogEnt7));
	waypoints.push_back(sf::Vector2f(8200.f, 6000.f));
	waypoints.push_back(sf::Vector2f(8200.f, 6680.f));
	dogEnt7.AddComponent<Patrol>(waypoints);
	waypoints.clear();
	dogEnt7.AddComponent<Dispose>();
	registry.emplace<NPC>(dogEnt7);

	dogEnt7.AddComponent<Stats>(config.dogStats);
	dogStats = dogEnt7.GetComponent<Stats>();
	dogEnt7.AddComponent<Health>(dogStats.VIT);
	dogEnt7.AddComponent<Attack>(dogEnt7.GetComponent<RigidBody>().body, dogStats.STR, config.dogAttackRange, PLAYER);

	systems.onCreate(registry, gui);
}

void GameScreen::update(const float& dt)
{
	auto manager = screenManager.GetComponent<CurrentScreen>();
	if (manager.restart)
	{
		//exit();
		systems.onDestroy(registry, gui);
		start();
		manager.restart = false;
		return;
	}
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
		if (event.type == sf::Event::Closed || screenManager.GetComponent<CurrentScreen>().exit)
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

