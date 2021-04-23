#pragma once
#include "stdafx.h"

#include "Player.h"

#include "FiniteStateMachine.h"
#include "PlayerIdleState.h"

Player::Player(float x, float y) : 
	gFactory(GlobalFactory::Instance()), factory(gFactory.factory), gObjects(GameObjects::Instance())
{
	srand(time(NULL));
	gObjects.registerObject(this, objects::player);
	id = 1;
	initVariables();
	createHitbox(x, y);

	body = PhysicsWorld::createRectangleBody(shape.getPosition(), shape.getSize(), true, PLAYER, ENEMY_NPC | FRIENDLY_NPC | OBSTACLE | ENEMY_AGGRO_RADIUS);

	// create components
	createColliderComponent(body, shape.getSize());
	createMovementComponent(body, speed);
	createCombatComponent(shape, id, objects::player, hitpoints, damage, attackRange, body);

	createAnimationComponent(shape, factory, "Hero");
		animationComponent->initArmature(sf::Vector2f(x,y));
		states.transform.scale(scale, scale);
		animationComponent->setAnimation(animationName::IDLE);


	// init State-Machine
	playerStateMachine->changeState(initState);

	// inventory for essence
	inventory = new PlayerInventory();
}

Player::~Player()
{
}

// create hitbox (shape)
void Player::createHitbox(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(config.playerHitboxWidth, config.playerHitboxHeight));
	shape.setFillColor(sf::Color::Red);
}

void Player::initVariables()
{
	hitpoints = config.playerHitpoints;
	damage = config.playerDamage;
	speed = config.playerSpeed;
	scale = config.playerScale;
	attackRange = 90.f;

	playerStateMachine = new FiniteStateMachine();
	initState = new PlayerIdleState(*this);
}

void Player::update(const float& dt)
{
	// update utility
	directionFinder.update();
	playerStateMachine->executeStateUpdate(dt);

	shape.setPosition(colliderComponent->getPosition());

	// Moving
	combatComponent->update(directionFinder.getDirection(),dt);

	// Animation things
	animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f(
		(1 / scale) * (shape.getPosition().x + shape.getSize().x / 2),
		(1 / scale) * (shape.getPosition().y + shape.getSize().y / 2))
	);
	//animationComponent->updateFactory(dt);
	gFactory.factory.update(dt);
}
	
void Player::render(sf::RenderWindow& target)
{
	// draw hitbox
	//combatComponent->render(target);
	target.draw(shape);
	target.draw(*animationComponent->getArmatureDisplay(), states);
}