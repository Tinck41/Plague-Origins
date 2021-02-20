#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	initWindow();
	initVariables();
	initMap();
}

Game::~Game()
{
	delete this->window;
}

void Game::initMap()
{
	this->tileMapSource = "./Assets/Map/map.tmx";

	if (this->mapLoader.load(tileMapSource))
	{
		this->map = this->mapLoader.parseTileMap();
	}

	this->map.loadLayers();
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
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Key::Escape)
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
	updateSFMLEvents();
	this->screenHandler->update();
	//update player
	player->update(dt);
}

void Game::render()
{
	this->window->clear();
	// Render
	this->screenHandler->render(*window);

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
