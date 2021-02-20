#include "GameScreen.h"

GameScreen::GameScreen()
{
	initVariables();
	initMap();
}

GameScreen::~GameScreen()
{
}

void GameScreen::initMap()
{
	this->tileMapSource = "./Assets/Map/map.tmx";

	if (this->mapLoader.load(tileMapSource))
	{
		this->map = this->mapLoader.parseTileMap();
	}

	this->map.loadLayers();
}

void GameScreen::initVariables()
{
}

void GameScreen::update(const float& dt)
{
	//update player
	this->player->update(dt);
}

void GameScreen::render(sf::RenderWindow& window)
{
	//Render obj
	this->map.render(window);
	this->player->render(window);
}

void GameScreen::temporary()
{
	initVariables();
	initMap();
}
