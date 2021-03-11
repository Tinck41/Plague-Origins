#include "stdafx.h"

#include "GameScreen.h"

GameScreen::GameScreen()
{
	setup();
}

void GameScreen::setup()
{
	if (this->mapLoader.load("./Assets/Map/map1.tmx"))
	{
		this->map = mapLoader.getTileMap();
	}
}

void GameScreen::update(const float& dt)
{
	this->player.update(dt);
	this->map.update(this->player);
	this->camera.setSize(sf::Vector2f(CONFIG.getWidth(), CONFIG.getHeight()));
	this->camera.setCenter(this->player.getPosition());
}

ScreenType GameScreen::render(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->camera.setSize(sf::Vector2f(CONFIG.getWidth(), CONFIG.getHeight()));
		this->camera.setCenter(CONFIG.getWidth() / 2, CONFIG.getHeight() / 2);
		window.setView(this->camera);
		return ScreenType::PAUSE;
	}
	window.setView(this->camera);
	this->map.renderFirstLayer(window);
	this->player.render(window);
	this->map.renderSecondLayer(window);
	return ScreenType::GAME;
}

GameScreen::~GameScreen()
{
}