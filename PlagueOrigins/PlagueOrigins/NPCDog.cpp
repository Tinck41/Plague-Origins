#pragma once
#include "stdafx.h"
#include "NPCDog.h"

NPCDog::NPCDog(float x, float y) : gFactory(GlobalFactory::Instance()), factory(gFactory.factory)
{
	initVariables();
	createHitbox(x, y);

	// create components
	createMovementComponent(this->shape, this->speed);

	createAnimationComponent(this->shape, this->factory, "Dog");
		animationComponent->initArmature(sf::Vector2f(x, y));
		this->states.transform.scale(scale, scale);
		this->animationComponent->setAnimation(animationName::MOVE);

	createColliderComponent(this->shape);
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
	this->speed = 200;
	this->scale = 0.3f;
	this->pointN = 0;
	this->direction = { .0f, .0f };
	fillWaypoints();
}

void NPCDog::createHitbox(float x, float y)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(100.0f, 150.0f));
	this->shape.setFillColor(sf::Color::Red);
}

void NPCDog::findRoute(sf::Vector2f dest)
{
	sf::Vector2f currentPos = this->getPosition();// +sf::Vector2f(this->shape.getSize().x / 2, this->shape.getSize().y / 2);

	if (currentPos.x < dest.x)
		this->direction.x = 1.0f;
	else if (currentPos.x > dest.x)
		this->direction.x = -1.0f;
	if (currentPos.y < dest.y)
		this->direction.y = 1.0f;
	else if (currentPos.y > dest.y)
		this->direction.y = -1.0f;

	if (this->direction.x != 0 || this->direction.y != 0)
		this->animationComponent->setAnimation(animationName::MOVE, this->direction);

	//if patrol point is done
	if ((currentPos.x >= dest.x - 5.0f && currentPos.x <= dest.x + 5.0f) && (currentPos.y >= dest.y - 5.0f && currentPos.y <= dest.y + 5.0f))
		this->pointN++;
	if (pointN > 1)
		pointN = 0;
}

void NPCDog::update(const float& dt)
{
	//get direction
	this->findRoute(this->getWaypoint(this->pointN));
	//moving
	this->movementComponent->move(dt, this->direction);
	//animation
	this->animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x), (1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
	this->animationComponent->updateFactory(dt);
}

void NPCDog::render(sf::RenderWindow& target)
{
	//target.draw(this->shape);
	target.draw(*this->animationComponent->getArmatureDisplay(), states);
}
