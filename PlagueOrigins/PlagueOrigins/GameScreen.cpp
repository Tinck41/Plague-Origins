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
}

void GameScreen::update(const float& dt)
{
	player.update(dt);
	npcDog.update(dt);
	npcBishop.update(dt);
	map.update(player);
	cameraComponent->update(player.getPosition());
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		cameraComponent->reset();
		cameraComponent->setViewport(window);
		return ScreenType::PAUSE;
	}
	cameraComponent->setViewport(window);
	map.renderUnderPlayerLayers(window);

	npcBishop.render(window);
	npcDog.render(window);
	player.render(window);

	map.renderOverPlayerLayers(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
	delete(cameraComponent);
}
