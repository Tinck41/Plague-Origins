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
	this->window = new sf::RenderWindow(sf::VideoMode(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT), CONFIG.WINDOW_TITLE, CONFIG.IS_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Close);
	this->window->setFramerateLimit(CONFIG.FPS_LIMIT);

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
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Key::Escape)
			{
				this->window->close();
			}
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	resolveSFMLEvents();
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
