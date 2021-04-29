#include "stdafx.h"
// #pragma once
// #include "stdafx.h"

// #include "Player.h"

// #include "FiniteStateMachine.h"
// #include "PlayerIdleState.h"

// Player::Player(float x, float y) : 
// 	gFactory(GlobalFactory::Instance()), factory(gFactory.factory), gObjects(GameObjects::Instance())
// {
// 	srand(time(NULL));
// 	gObjects.registerObject(this, objects::player);
// 	id = 1;
// 	initVariables();

// 	// create components
// 	createMovementComponent(shape, speed);
// 	createAnimationComponent(shape, factory, "Hero");
// 		animationComponent->initArmature(sf::Vector2f(x,y));
// 		states.transform.scale(scale, scale);
// 		animationComponent->setAnimation(animationName::IDLE);

// 	createColliderComponent(shape);

// 	// init State-Machine
// 	playerStateMachine->changeState(initState);
// 	createHitbox(x, y);
// 	createCombatComponent(shape, hitpoints, damage);

// 	// inventory for essence
// 	inventory = new PlayerInventory();
// }

// Player::~Player()
// {
// }

// // create hitbox (shape)
// void Player::createHitbox(float x, float y)
// {
// 	shape.setPosition(x, y);
// 	shape.setSize(sf::Vector2f(config.playerHitboxWidth, config.playerHitboxHeight));
// 	shape.setFillColor(sf::Color::Red);
// }

// void Player::initVariables()
// {
// 	hitpoints = config.playerHitpoints;
// 	damage = config.playerDamage;
// 	speed = config.playerSpeed;
// 	scale = config.playerScale;

// 	playerStateMachine = new FiniteStateMachine();
// 	initState = new PlayerIdleState(*this);
// }

// void Player::update(const float& dt)
// {
// 	// update utility
// 	directionFinder.update();
// 	playerStateMachine->executeStateUpdate(dt);

// 	// Moving
// 	combatComponent->update(directionFinder.getDirection(), dt);

// 	// Animation things
// 	//this->armatureDisplay = this->animationComponent->getArmatureDisplay();
// 	animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x),(1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
// 	animationComponent->updateFactory(dt);
// 	//GlobalFactory::zf->update(dt);
// }
	
// void Player::render(sf::RenderWindow& target)
// {
// 	// draw hitbox
// 	//combatComponent->render(target);
// 	target.draw(shape);
// 	target.draw(*animationComponent->getArmatureDisplay(), states);
// }