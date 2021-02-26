#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	initWindow();
	initMap();
}

Game::~Game()
{
	delete this->window;
}

void Game::initMap()
{
	this->camera = this->window->getDefaultView();

	this->tileMapSource = "./Assets/Map/map.tmx";

	if (this->mapLoader.load(tileMapSource))
	{
		this->map = this->mapLoader.parseTileMap();
	}

	this->map.loadLayers();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Plague: Origins", sf::Style::Titlebar | sf::Style::Close);

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
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Key::Escape)
			{
				this->window->close();
			}
			if (ev.key.code == sf::Keyboard::Key::Q)
			{
				camera.zoom(1.05f);
			}
			if (ev.key.code == sf::Keyboard::Key::E)
			{
				camera.zoom(0.95f);
			}
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	updateSFMLEvents();

	//update player
	player->update(dt);
}

void Game::render()
{
	this->window->setView(this->camera);
	this->window->clear();

	//Render obj
	this->map.render(*this->window);
	this->player->render(this->window);

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