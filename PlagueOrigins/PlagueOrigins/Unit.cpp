#include "stdafx.h"

#include "Unit.h"

Unit::Unit() : gObjects(GameObjects::Instance())
{
}

void Unit::spawnUnit()
{
	//create shape
	shape.setPosition(10.f, 10.f);
	shape.setSize(sf::Vector2f(100.0f, 100.0f));
	shape.setScale(sf::Vector2f(0.5f, 0.5f));
	shape.setFillColor(sf::Color::Green);
}

void Unit::initVariables()
{
	//this->movementComponent = NULL;
	//this->animationComponent = NULL;
}

void Unit::createMovementComponent(b2Body* body, float speed)
{
	this->movementComponent = new MovementComponent(body, speed);
}

void Unit::createColliderComponent(b2Body* body, sf::Vector2f size)
{
	this->colliderComponent = new ColliderComponent(body, size);
}

void Unit::createCombatComponent(sf::RectangleShape& shape, int id, objects objectType, float hitpoints, float damage, float attackRange, b2Body* body)
{
	combatComponent = new CombatComponent(shape, id, objectType, hitpoints, damage, attackRange, body);
}

void Unit::update(const float& dt)
{
}

void Unit::render(sf::RenderWindow* window)
{
}

void Unit::createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix)
{
	this->animationComponent = new AnimationComponent(shape, zf, prefix);
}
