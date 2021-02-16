#include "Player.h"

Player::Player(float x, float y) : Unit()
{
	initVariables();
	spawnPlayer(x,y);
}

void Player::spawnPlayer(float x, float y)
{
	//preparation for sprite
	playerSprite.setPosition(x, y);
	playerSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	//rectangle as draft
	playerShape.setPosition(x, y);
	playerShape.setSize(sf::Vector2f(100.0f, 100.0f));
	playerShape.setScale(sf::Vector2f(0.5f, 0.5f));
	playerShape.setFillColor(sf::Color::Red);
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

void Player::update(float dt)
{
	this->move(dt);
}

void Player::move(float dt)
{
	Unit::move(playerShape, dt);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(playerShape);
}
