#include "Player.h"

Player::Player(float x, float y) : Unit()
{
	initVariables();
	spawnPlayer(x,y);
	createMovementComponent(this->shape, this->speed);
	createAnimationComponent(this->shape, this->factory, this->armatureDisplay);
	//this->armatureDisplay = animationComponent->addAnimation(IDLE,this->shape.getPosition().x, this->shape.getPosition().y);
	this->armatureDisplay = animationComponent->addAnimation(RUN_RIGHT, this->shape.getPosition().x, this->shape.getPosition().y);
	this->states.transform.scale(0.2f, 0.2f);
}

void Player::spawnPlayer(float x, float y)
{
	//create movement component based on shape
	shape.setPosition(x, y);
	//shape.setSize(sf::Vector2f(100.0f, 100.0f));
	//shape.setScale(sf::Vector2f(0.5f, 0.5f));
	//shape.setFillColor(sf::Color::Red);
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
	//std::cout << "PLAYER: shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
	//this->armatureDisplay = animationComponent->play(movementComponent->getState(),dt,this->shape.getPosition().x, this->shape.getPosition().y);
	this->factory.update(dt);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(*armatureDisplay, states);
}
