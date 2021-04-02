#include "stdafx.h"

#include "Game.h"

Game::Game()
{
	setup();
}

Game::~Game()
{
}

void Game::setup()
{
	this->window = new sf::RenderWindow(
		config.isFullscreen ? sf::VideoMode::getDesktopMode() : sf::VideoMode(config.width(), config.height()),
		config.title,
		config.isFullscreen ? sf::Style::Fullscreen : sf::Style::Close
	);
	this->window->setFramerateLimit(config.fps);
	this->window->setVerticalSyncEnabled(true);
	this->screenHandler = new ScreenHandler(ScreenType::MAIN_MENU);
	this->deltaTime = 0.f;
}

void Game::updateDeltaTime()
{
	this->deltaTime = deltaTimeClock.restart().asSeconds();
}

void Game::resolveSFMLEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	resolveSFMLEvents();
	if (this->window->hasFocus())
		this->inputBooleans.update();
	this->screenHandler->update(deltaTime);
}

void Game::render()
{
	this->window->clear();
	this->screenHandler->render(*window);
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		updateDeltaTime();
		update();
		render();
	}
}
