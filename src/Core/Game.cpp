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
	//window->setVerticalSyncEnabled(true);
	screenHandler = new ScreenHandler(ScreenType::MAIN_MENU);
	deltaTime = 0.f;
}

void Game::updateDeltaTime()
{
	deltaTime = deltaTimeClock.restart().asSeconds();
	lastFPSTime += deltaTime;
	fps++;
}

void Game::update()
{
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
		if (lastFPSTime >= 1)
		{
			window->setTitle(config.title + " " + std::to_string(fps));
			lastFPSTime = 0.f;
			fps = 0;
		}

		updateDeltaTime();
		update();
		render();
	}
}
