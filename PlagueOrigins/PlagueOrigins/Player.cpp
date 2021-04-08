#pragma once
#include "stdafx.h"

#include "Player.h"

#include "FiniteStateMachine.h"
#include "PlayerIdleState.h"

Player::Player(float x, float y) : 
	gFactory(GlobalFactory::Instance()), factory(gFactory.factory), gObjects(GameObjects::Instance())
{
	gObjects.registerObject(this, objects::player);
	id = 1;
	initVariables();
	createHitbox(x, y);

	b2Body* body = PhysicsWorld::createRectangleBody(shape.getPosition(), shape.getSize(), true);

	// create components
	createColliderComponent(body);
	createMovementComponent(body, this->speed);
	createCombatComponent(shape, hitpoints, damage);
	createAnimationComponent(this->shape, this->factory, "Hero");
		animationComponent->initArmature(sf::Vector2f(x,y));
		this->states.transform.scale(scale, scale);
		this->animationComponent->setAnimation(animationName::IDLE);


	// init State-Machine
	playerStateMachine->changeState(initState);
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
	hitpoints = 20;
	damage = 5;

	this->speed = 1000000000.f;
	this->scale = 0.2f;

	this->playerStateMachine = new FiniteStateMachine();
	this->initState = new PlayerIdleState(*this);
}

void Player::update(const float& dt)
{
	// update utility
	this->directionFinder.update();
	this->playerStateMachine->executeStateUpdate(dt);

	// Moving
	combatComponent->update(directionFinder.getDirection(), dt);

	shape.setPosition(colliderComponent->getPosition());

	// Animation things
	//this->armatureDisplay = this->animationComponent->getArmatureDisplay();
	this->animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + shape.getSize().x / 2),(1 / scale) * (shape.getPosition().y + shape.getSize().y / 2)));
	this->animationComponent->updateFactory(dt);
	//GlobalFactory::zf->update(dt);
}
	
void Player::render(sf::RenderWindow& target)
{
	// draw hitbox
	//combatComponent->render(target);
	target.draw(this->shape);
	target.draw(*this->animationComponent->getArmatureDisplay(), states);
}