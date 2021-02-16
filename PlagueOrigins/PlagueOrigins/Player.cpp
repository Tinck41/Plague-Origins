#include "Player.h"

Player::Player()
{
	initVariables();
	spawnPlayer();
}

void Player::spawnPlayer()
{
	//preparation for sprite
	playerSprite.setPosition(10.f, 10.f);
	playerSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	//rectangle as draft
	playerShape.setPosition(10.f, 10.f);
	playerShape.setSize(sf::Vector2f(100.0f, 100.0f));
	playerShape.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Player::initVariables()
{
	isWPressed = false;
	isAPressed = false;
	isSPressed = false;
	isDPressed = false;
	speed = 200;
	dx = 0; //move x direction
	dy = 0; //move y direction
}

void Player::move(float dt)
{
	/*
		using dt for independency of framerate

		TYPE 1: sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) only Player.cpp
		TYPE 2: using Game events for KeyPressed/KeyReleased events --implemented
		//TYPE 2 = Global var in Player class OR create static var for all project
	*/

	//reset direction
	dx = 0;
	dy = 0;

	//check for direction
	/*
	TYPE 1:
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		std::cout << "W is pressed" << "\n";
		dy = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		std::cout << "S is pressed" << "\n";
		dy = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		std::cout << "A is pressed" << "\n";
		dx = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		std::cout << "D is pressed" << "\n";
		dx = 1;
	}
	
	*/

	/*
		TYPE 2:
	*/
	if (isWPressed)
	{
		//std::cout << "W is pressed" << "\n";
		dy = -1;
	}
	else if (isSPressed)
	{
		//std::cout << "S is pressed" << "\n";
		dy = 1;
	}
	if (isAPressed)
	{
		//std::cout << "A is pressed" << "\n";
		dx = -1;
	}
	else if (isDPressed)
	{
		//std::cout << "D is pressed" << "\n";
		dx = 1;
	}

	//player move
	playerShape.move(sf::Vector2f(dx*speed*dt, dy*speed*dt));
	//playerSprite.move(sf::Vector2f(dx * speed * dt, dy * speed * dt));
}

void Player::update(float dt)
{
	this->move(dt);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(playerShape);
}