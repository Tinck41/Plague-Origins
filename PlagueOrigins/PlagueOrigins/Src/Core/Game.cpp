#include "stdafx.h"

#include "Game.h"

Game::Game()
{
	setup();
}

Game::~Game()
{
	delete screenHandler;
	delete window;
}

void Game::setup()
{
	window = new sf::RenderWindow(
		config.isFullscreen ? sf::VideoMode::getDesktopMode() : sf::VideoMode(config.width(), config.height()),
		config.title,
		config.isFullscreen ? sf::Style::Fullscreen : sf::Style::Close
	);
	window->setFramerateLimit(config.fps);
	window->setVerticalSyncEnabled(true);
	screenHandler = new ScreenHandler(ScreenType::GAME);
	deltaTime = 0.f;
}

void Game::updateDeltaTime()
{
	deltaTime = deltaTimeClock.restart().asSeconds();
}

void Game::resolveSFMLEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	resolveSFMLEvents();
	if (window->hasFocus())
	{
		inputBooleans.update();
	}
	screenHandler->update(deltaTime);
}

void Game::render()
{
	window->clear();
	screenHandler->render(*window);
	window->display();
}

void Game::run()
{
	while (window->isOpen())
	{
		updateDeltaTime();
		update();
		render();
	}
}