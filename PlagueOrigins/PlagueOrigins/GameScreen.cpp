#include "stdafx.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
	if (mapLoader.load("./Assets/Map/map.tmx"))
	{
		map = mapLoader.getTileMap();
	}
	cameraComponent = new CameraComponent();
	cameraComponent->setBounds(map.getSize());
	inventoryComponent = new InventoryComponent();
}

void GameScreen::update(const float& dt)
{
	npcDog.update(dt);
	player.update(dt);
	map.update(player);
	cameraComponent->update(player.getPosition());
	inventoryComponent->update(cameraComponent->getPosition());
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	cameraComponent->setViewport(window);
	map.renderUnderPlayerLayers(window);
	npcDog.render(window);
	player.render(window);
	map.renderOverPlayerLayers(window);
	inventoryComponent->render(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
	delete cameraComponent;
	delete inventoryComponent;
}
