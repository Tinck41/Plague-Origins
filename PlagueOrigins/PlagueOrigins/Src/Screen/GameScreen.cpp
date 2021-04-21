#include "stdafx.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
	if (mapLoader.loadTileMap("./Assets/Map/map.tmx"))
	{
		map = mapLoader.getTileMap();
	}
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
	if (player.getActiveStatus())
		player.update(dt);
	if (npcDog.getActiveStatus())
		npcDog.update(dt);
	if (npcBishop.getActiveStatus())
		npcBishop.update(dt);
	map.update(dt);
	cameraComponent->update(player.getPosition());
	inventoryComponent->update(dt, cameraComponent->getPosition());
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	cameraComponent->setViewport(window);
	map.renderUnderPlayerLayers(window);

	if (npcBishop.getActiveStatus())
		npcBishop.render(window);
	if (npcDog.getActiveStatus())
		npcDog.render(window);
	if (player.getActiveStatus())
		player.render(window);

	map.renderOverPlayerLayers(window);
	inventoryComponent->render(window);
	return ScreenType::GAME;
}

