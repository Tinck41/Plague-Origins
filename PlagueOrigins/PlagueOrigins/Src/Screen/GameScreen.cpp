#include "stdafx.h"
#include "GameScreen.h"

#include "GlobalFactory.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/map.tmx"))
	{
		map = mapLoader.getTileMap();
	}

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

	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>();
	npcEntity.AddComponent<Movement>(500.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, npcEntity);
	npcEntity.AddComponent<Tag>("Dog");
	npcEntity.AddComponent<Health>(300.f);

	bishop = Entity(registry.create(), this);
	bishop.AddComponent<Transform>();
	bishop.AddComponent<Animator>();
	bishop.AddComponent<Movement>(500.f);
	bishop.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(415.f, 615.f), false, bishop);
	bishop.AddComponent<Tag>("Bishop");

	testEntity.GetComponent<Health>().curhealth = 200.f;

	systems.onCreate(registry);
}

GameScreen::~GameScreen()
{
	delete cameraComponent;
	delete inventoryComponent;
}

void GameScreen::update(const float& dt)
{
	//if (player.getActiveStatus())
	//	player.update(dt);
	//if (npcDog.getActiveStatus())
	//	npcDog.update(dt);
	//if (npcBishop.getActiveStatus())
	//	npcBishop.update(dt);
	//cameraComponent->update(player.getPosition());
	//inventoryComponent->update(dt, cameraComponent->getPosition());
	map.update(dt);
	systems.update(registry, dt);
	std::cout << testEntity.GetComponent<Health>().curhealth << "\n";
	// AnimationFactory::update(dt);
	GlobalFactory::Instance().factory.update(dt);
	PhysicsWorld::update(dt);
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	//cameraComponent->setViewport(window);
	map.renderUnderPlayerLayers(window);
	//if (npcBishop.getActiveStatus())
	//	npcBishop.render(window);
	//if (npcDog.getActiveStatus())
	//	npcDog.render(window);
	//if (player.getActiveStatus())
	//	player.render(window);
	//inventoryComponent->render(window);

	map.renderOverPlayerLayers(window);
	systems.render(registry, window);
	return ScreenType::GAME;
}

