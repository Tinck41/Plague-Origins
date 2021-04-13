#pragma once
#include "stdafx.h"
#include "NPCDog.h"
#include "FiniteStateMachine.h"
#include "NPCDogIdleState.h"

NPCDog::NPCDog(float x, float y) : 
	gFactory(GlobalFactory::Instance()), factory(gFactory.factory), gObjects(GameObjects::Instance())
{
	gObjects.registerObject(this, objects::enemies);
	id = 2;
	initVariables();
	createHitbox(x, y);

	// create components
	createMovementComponent(this->shape, this->speed);

	createAnimationComponent(this->shape, this->factory, "Dog");
		animationComponent->initArmature(sf::Vector2f(x, y));
		this->states.transform.scale(scale, scale);
		this->animationComponent->setAnimation(animationName::MOVE);

	createColliderComponent(this->shape);
	createCombatComponent(shape, hitpoints, damage);
	
	patrolComponent = new Patrol(shape, waypoints);

	// init State-Machine
	npcDogStateMachine->changeState(initState);

}

NPCDog::~NPCDog()
{
}

void NPCDog::fillWaypoints()
{
	this->waypoints.push_back(this->point0);
	this->waypoints.push_back(this->point1);
}

sf::Vector2f NPCDog::getWaypoint(int pointN)
{
	switch (pointN)
	{
	case 0:
		return this->waypoints[0];
	case 1:
		return this->waypoints[1];
	}

	return sf::Vector2f();
}

void NPCDog::initVariables()
{
	hitpoints = config.dogHitpoints;
	damage = config.dogDamage;
	speed = config.dogSpeed;
	scale = config.dogScale;
	pointN = 0;
	direction = { .0f, .0f };
	fillWaypoints();
	npcDogStateMachine = new FiniteStateMachine();
	this->initState = new NPCDogIdleState(*this);
}

void NPCDog::createHitbox(float x, float y)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(config.dogHitboxWidth, config.dogHitboxHeight));
	this->shape.setFillColor(sf::Color::Red);
}

void NPCDog::update(const float& dt)
{
	//update utility
	patrolComponent->update();
	combatComponent->update(direction, dt);
	npcDogStateMachine->executeStateUpdate(dt);

	//animation
	animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x), (1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
	//animationComponent->updateFactory(dt);

}

void NPCDog::render(sf::RenderWindow& target)
{
	//combatComponent->render(target);
	target.draw(shape);
	target.draw(*animationComponent->getArmatureDisplay(), states);
}
