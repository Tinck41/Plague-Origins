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
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Plague: Origins", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(600);
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
		case sf::Event::KeyPressed: //KeyPressed events for TYPE 2 PLAYER MOVEMENT see Player::move()
			if (ev.key.code == sf::Keyboard::Key::Escape)
			{
				this->window->close();
			}
			if (ev.key.code == sf::Keyboard::Key::W && !player->isWPressed)
			{
				player->isWPressed = true;
				std::cout << "W is Pressed\n";
			}
			if (ev.key.code == sf::Keyboard::Key::S && !player->isSPressed)
			{
				player->isSPressed = true;
				std::cout << "S is Pressed\n";
			}
			if (ev.key.code == sf::Keyboard::Key::A && !player->isAPressed)
			{
				player->isAPressed = true;
				std::cout << "A is Pressed\n";
			}
			if (ev.key.code == sf::Keyboard::Key::D && !player->isDPressed)
			{
				player->isDPressed = true;
				std::cout << "D is Pressed\n";
			}
			break;
		case sf::Event::KeyReleased: //KeyReleased events for TYPE 2 PLAYER MOVEMENT see Player::move()
			if (ev.key.code == sf::Keyboard::Key::W && player->isWPressed)
			{
				player->isWPressed = false;
				std::cout << "W is Released\n";
			}
			if (ev.key.code == sf::Keyboard::Key::S && player->isSPressed)
			{
				player->isSPressed = false;
				std::cout << "S is Released\n";
			}
			if (ev.key.code == sf::Keyboard::Key::A && player->isAPressed)
			{
				player->isAPressed = false;
				std::cout << "A is Released\n";
			}
			if (ev.key.code == sf::Keyboard::Key::D && player->isDPressed)
			{
				player->isDPressed = false;
				std::cout << "D is Released\n";
			}
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
	this->window->clear();

	//Render obj
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