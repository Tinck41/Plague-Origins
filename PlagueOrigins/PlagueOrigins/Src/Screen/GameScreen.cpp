#include "stdafx.h"
#include "GameScreen.h"

#include "Src/ECS/Components/PlayerInput.h"
#include "Src/ECS/Components/Movement.h"
#include "Src/ECS/Components/Rigidbody.h"
#include "Src/ECS/Components/Dash.h"
#include "Src/ECS/Components/Tag.h"
#include "Src/ECS/Components/Transform.h"
#include "Src/ECS/Components/Animator.h"
#include "Src/Utility/AnimationFactory.h"
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
	testEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 150.f), sf::Vector2f(315.f, 615.f), true, PLAYER, OBSTACLE | ENEMY_NPC);
	testEntity.AddComponent<Tag>("Hero");

	npcEntity = Entity(registry.create(), this);
	npcEntity.AddComponent<Transform>();
	npcEntity.AddComponent<Animator>();
	npcEntity.AddComponent<Movement>(500.f);
	npcEntity.AddComponent<RigidBody>(sf::Vector2f(50.f, 50.f), sf::Vector2f(615.f, 615.f), true, ENEMY_NPC, OBSTACLE | PLAYER);
	npcEntity.AddComponent<Tag>("Dog");
	
	entityShape.setSize(sf::Vector2f(50.f, 50.f));
	entityShape.setPosition(sf::Vector2f(315.f, 615.f));
	entityShape.setFillColor(sf::Color::Red);

	systems.onCreate(registry);

	//cameraComponent = new CameraComponent();
	//cameraComponent->setBounds(map.getSize());
	//inventoryComponent = new InventoryComponent();
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
	entityShape.setPosition(testEntity.GetComponent<RigidBody>().body->GetPosition().x * 30.f - entityShape.getSize().x / 2.f, testEntity.GetComponent<RigidBody>().body->GetPosition().y * 30.f - entityShape.getSize().y / 2.f);
	map.update(dt);
	systems.update(registry, dt);
	// AnimationFactory::update(dt);
	GlobalFactory::Instance().factory.update(dt);
	PhysicsWorld::update(dt);
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	//cameraComponent->setViewport(window);
	map.renderUnderPlayerLayers(window);
	window.draw(entityShape);
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

