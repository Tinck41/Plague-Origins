#include "stdafx.h"

#include "Player.h"

#include "FiniteStateMachine.h"
#include "PlayerIdleState.h"
#include "PlayerMoveState.h"

Player::Player(float x, float y) : Unit()
{
	initVariables();
	createHitbox(x, y);

	// create components
	createMovementComponent(this->shape, this->speed);

	createAnimationComponent(this->shape, this->factory);
		animationComponent->initArmature(sf::Vector2f(x,y));
		this->states.transform.scale(scale, scale);
		this->animationComponent->setAnimation(animationName::IDLE);
		this->armatureDisplay = this->animationComponent->getArmatureDisplay();

	createColliderComponent(this->shape);

	// init State-Machine
	this->playerStateMachine.changeState(this->initState);
}

Player::~Player()
{
}

// create hitbox (shape)
void Player::createHitbox(float x, float y)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(100.0f, 150.0f));
	this->shape.setFillColor(sf::Color::Red);
}

void Player::initVariables()
{
	this->speed = 600;
	this->scale = 0.2f;

	this->initState = new PlayerIdleState(this->playerStateMachine, *this);
}

void Player::update(const float& dt)
{
	// update utility
	this->inputBooleans.update();
	this->directionFinder.update();
	this->playerStateMachine.executeStateUpdate();

	// Moving
	this->movementComponent->move(dt, this->directionFinder.getDirection());

	// Animation things
	this->armatureDisplay = this->animationComponent->getArmatureDisplay();
	this->armatureDisplay->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x),(1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
	this->factory.update(dt);
}
	
void Player::render(sf::RenderWindow& target)
{
	// draw hitbox
	//target.draw(this->shape);
	target.draw(*armatureDisplay, states);
}