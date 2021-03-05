#include "stdafx.h"

#include "Player.h"

Player::Player()
{
}

Player::Player(float x, float y) : Unit()
{
	scale = 0.2f;
	this->posX = x;
	this->posY = y;
	initVariables();
	spawnPlayer(x,y);
	createMovementComponent(this->shape, this->speed);
	createAnimationComponent(this->shape, this->factory);
	animationComponent->initArmature(sf::Vector2f(x,y));
	this->states.transform.scale(scale, scale);
	this->armatureDisplay = this->animationComponent->playAnimation(IDLE, this->shape.getPosition().x, this->shape.getPosition().y);
	createColliderComponent(this->shape);
}

Player::~Player()
{
}

void Player::spawnPlayer(float x, float y)
{
	//create movement component based on shape
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(100.0f, 150.0f));
	//shape.setScale(sf::Vector2f(0.5f, 0.5f));
	shape.setFillColor(sf::Color::Red);
}

void Player::initVariables()
{
	speed = 600;
	dx = 0; //move x direction
	dy = 0; //move y direction
	isStateChanged = false;
}

void Player::update(const float& dt)
{
	this->inputHandler.update();

	this->movementComponent->move(dt, this->inputHandler.getDirection());

	posX = this->shape.getPosition().x + this->colliderComponent->getHalfSize().x;
	posY = this->shape.getPosition().y + this->colliderComponent->getHalfSize().y;
	
	if (this->movementComponent->stateChanged())
	{
		/*std::cout << "STATE CHANGED" << std::endl;
		std::cout << "ARM POS:" << armatureDisplay->getPosition().x << " " << armatureDisplay->getPosition().y << std::endl;
		std::cout << "SHAPE POS:" << this->shape.getPosition().x << " " << this->shape.getPosition().y << std::endl;*/
		this->armatureDisplay = this->animationComponent->playAnimation(movementComponent->getState(), this->shape.getPosition().x, this->shape.getPosition().y);
	}
	
	this->armatureDisplay->setPosition(sf::Vector2f((1/scale)*posX,(1/scale)*posY));
	//std::cout << "PLAYER: shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
	this->factory.update(dt);
}
	
void Player::render(sf::RenderWindow& target)
{
	//draw hitbox
	//target.draw(this->shape);
	target.draw(*armatureDisplay, states);
}