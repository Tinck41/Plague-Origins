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

	this->camera.setSize(sf::Vector2f(1600.0f, 1200.0f));

}

void GameScreen::update(const float& dt)
{
	this->player.update(dt);
	this->map.update(this->player);
	this->camera.setCenter(this->player.getPosition());
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		return ScreenType::PAUSE;
	}
	window.setView(this->camera);
	//this->map.render(window);
	this->map.renderFirstLayer(window);
	this->player.render(window);
	this->map.renderSecondLayer(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
}