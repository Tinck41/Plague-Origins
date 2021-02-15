#include "Game.h"

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Plague: Origins", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
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
		switch (this->ev.type)
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
	updateSFMLEvents();
}

void Game::render()
{
	this->window->clear();

	//Render obj

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