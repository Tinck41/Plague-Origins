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

	gui.loadWidgetsFromFile("../AdditionalLibraries/TGUI-0.9/gui-builder/Game.txt");

	testEntity = Entity(registry.create(), this);
	testEntity.AddComponent<Transform>();
	testEntity.AddComponent<PlayerInput>();
	testEntity.AddComponent<Dash>();
	testEntity.AddComponent<Animator>();
	testEntity.AddComponent<Movement>(500.f);
	testEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(315.f, 615.f), true, testEntity, PLAYER);
	testEntity.AddComponent<Tag>("Hero");
	testEntity.AddComponent<CameraTarget>(sf::Vector2f(config.width(), config.height()), map.getSize());
	testEntity.AddComponent<Health>(300.f);
	testEntity.AddComponent<Vampire>();
	testEntity.AddComponent<Attack>(testEntity.GetComponent<RigidBody>().body, 100.f, 100.f);
	testEntity.GetComponent<Health>().curhealth = 100.f;
	testEntity.AddComponent<PlayerSMcomponent>(new PlayerIdleState(testEntity));

	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>();
	npcEntity.AddComponent<Movement>(500.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, npcEntity, ENEMY_NPC);
	npcEntity.AddComponent<Aggresion>(250.f, sf::Vector2f(615.f, 615.f), true, npcEntity, ENEMY_AGGRO_RADIUS);
	npcEntity.AddComponent<Tag>("Dog");
	npcEntity.AddComponent<Health>(300.f);
	npcEntity.AddComponent<PlayerSMcomponent>(new DogIdleState(npcEntity));

	bishop = Entity(registry.create(), this);
	bishop.AddComponent<Transform>();
	bishop.AddComponent<Animator>();
	//   ?
	bishop.AddComponent<Movement>(500.f);
	bishop.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(415.f, 615.f), false, bishop, FRIENDLY_NPC);
	bishop.AddComponent<Tag>("Bishop");
	bishop.AddComponent<Interact>(bishop.GetComponent<RigidBody>().body, 30.f, "Press F to pay respect");
	bishop.AddComponent<Health>(300.f);
	bishop.AddComponent<PlayerSMcomponent>(new BishopIdleState(bishop));

	systems.onCreate(registry);
}

GameScreen::~GameScreen()
{

}

void GameScreen::update(const float& dt)
{
	map.update(dt);
	GlobalFactory::Instance().factory.update(dt);
	systems.update(registry, dt);
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

