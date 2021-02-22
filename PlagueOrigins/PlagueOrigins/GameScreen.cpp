#include "GameScreen.h"

GameScreen::GameScreen()
{
	setup();
}

void GameScreen::setup()
{
	this->player = new Player(10.0f, 10.0f);
	if (this->mapLoader.load("./Assets/Map/map.tmx"))
	{
		this->map = mapLoader.parseTileMap();
	}
	this->map.loadLayers();
}

void GameScreen::update(const float& dt)
{
	this->player->update(dt);
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	this->map.render(window);
	this->player->render(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
}