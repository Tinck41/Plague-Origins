#include "GameScreen.h"

GameScreen::GameScreen()
{
	setup();
}

void GameScreen::setup()
{
	if (this->mapLoader.load("./Assets/Map/map.tmx"))
	{
		this->map = mapLoader.parseTileMap();
	}
	this->map.loadLayers();
}

void GameScreen::update(const float& dt)
{
	this->player.update(dt);
	this->map.update(this->player);
	std::cout << this->player.getPosition().x << " " << this->player.getPosition().y << "\n";
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		return ScreenType::PAUSE;
	}
	this->map.render(window);
	this->player.render(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
}