#include "Player.h"

Player::Player(float x, float y) : Unit()
{
	initVariables();
	spawnPlayer(x,y);
	createMovementComponent(this->shape, this->speed);
}

void Player::spawnPlayer(float x, float y)
{
	//create movement component based on shape
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(100.0f, 100.0f));
	shape.setScale(sf::Vector2f(0.5f, 0.5f));
	shape.setFillColor(sf::Color::Red);
}

void Player::initVariables()
{
	speed = 200;
	dx = 0; //move x direction
	dy = 0; //move y direction
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	this->shape = movementComponent->getShape();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
