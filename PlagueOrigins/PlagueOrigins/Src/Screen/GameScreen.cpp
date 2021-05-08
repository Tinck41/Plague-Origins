#include "stdafx.h"
#include "GameScreen.h"

#include "GlobalFactory.h"
#include "Src/FSM/States/Player/PlayerStates.h"
#include "Src/FSM/States/NPCDog/NPCDogStates.h"
#include "Src/FSM/States/Bishop/BishopStates.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/map.tmx"))
	{
		map = mapLoader.getTileMap();
	}
	mapLoader.~TilemapParser();

	testEntity = Entity(registry.create(), this);
	testEntity.AddComponent<Transform>();
	testEntity.AddComponent<PlayerInput>();
	testEntity.AddComponent<Dash>();
	testEntity.AddComponent<Animator>();
	testEntity.AddComponent<Movement>(500.f);
	testEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(315.f, 615.f), true, testEntity);
	testEntity.AddComponent<Tag>("Hero");
	testEntity.AddComponent<CameraTarget>(sf::Vector2f(config.width(), config.height()));
	testEntity.AddComponent<Health>(300.f);
	testEntity.AddComponent<Vampire>();
	testEntity.AddComponent<Attack>(testEntity.GetComponent<RigidBody>().body, 100.f, 50.f);
	testEntity.AddComponent<PlayerSMcomponent>(new PlayerIdleState(testEntity));

	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>();
	npcEntity.AddComponent<Movement>(500.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, npcEntity);
	npcEntity.AddComponent<Tag>("Dog");
	npcEntity.AddComponent<Health>(300.f);
	npcEntity.AddComponent<PlayerSMcomponent>(new NPCDogIdleState(npcEntity));

	bishop = Entity(registry.create(), this);
	bishop.AddComponent<Transform>();
	bishop.AddComponent<Animator>();
	//   ?
	bishop.AddComponent<Movement>(500.f);
	bishop.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(415.f, 615.f), false, bishop);
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
	map.renderUnderPlayerLayers(window);
	map.renderOverPlayerLayers(window);
	systems.render(registry, window);
	return ScreenType::GAME;
}

