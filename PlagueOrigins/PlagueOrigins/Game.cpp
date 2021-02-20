#include "Game.h"

Game::Game()
{
	initWindow();
	initVariables();
}

Game::~Game()
{
	delete this->window;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Plague: Origins", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->screenHandler = new ScreenHandler();
	this->dt = 0.f;
}

void Game::updateDt()
{
	/*Updates the dt variable with the time it takes to update and render one frame.*/

	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update()
{
	updateSFMLEvents();
	this->screenHandler->update();
}

void Game::render()
{
	this->window->clear();
	// Render
	this->screenHandler->render(*window);

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}