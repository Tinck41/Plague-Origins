#include "stdafx.h"

#include "Player.h"



Player::Player()
{
}

Player::Player(float x, float y) : Unit()
{
	scale = 0.2f;
	initVariables();
	spawnPlayer(x,y);

	//create components
	createMovementComponent(this->shape, this->speed);
	createAnimationComponent(this->shape, this->factory);
		animationComponent->initArmature(sf::Vector2f(x,y));
		this->states.transform.scale(scale, scale);
		this->armatureDisplay = this->animationComponent->playAnimation(IDLE, idleDown);
	createColliderComponent(this->shape);

	//create PlayerState
	//playerStateHandler = new PlayerStateHandler(*this);
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
	isStateChanged = false;
}

void Player::update(const float& dt)
{
	//update utility
	this->inputBooleans.update();
	this->directionFinder.update();
	this->playerStateHandler.update(dt);

	//Moving
	this->movementComponent->move(dt, this->directionFinder.getDirection());
	
	//Animation things
	this->armatureDisplay = this->animationComponent->playAnimation(this->playerStateHandler.getGlobalState(), this->directionFinder.getLocalState());
	this->armatureDisplay->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x),(1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
	this->factory.update(dt);
}
	
void Player::render(sf::RenderWindow& target)
{
	//draw hitbox
	//target.draw(this->shape);
	target.draw(*armatureDisplay, states);
}