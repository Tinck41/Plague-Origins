#include "stdafx.h"
#include "GameScreen.h"

#include "Src/ECS/Components/PlayerInput.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/map.tmx"))
	{
		map = mapLoader.getTileMap();
	}

	testEntity = Entity(registry.create(), this);
	testEntity.AddComponent<PlayerInput>();

	cameraComponent = new CameraComponent();
	cameraComponent->setBounds(map.getSize());
	inventoryComponent = new InventoryComponent();
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

