#include "stdafx.h"
#include "CombatComponent.h"
#include "Unit.h"

CombatComponent::CombatComponent(sf::RectangleShape& shape, float hitpoints, float damage) :
	gObjects(GameObjects::Instance()), shape(shape)
{
	this->hitpoints = hitpoints;
	this->damage = damage;
	initVariables();
}

void CombatComponent::initVariables()
{
	this->attackCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2,
		shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2
	);
	this->attackCircle.setRadius(shape.getSize().y / 2);
	attackCircle.setFillColor(sf::Color::Green);
	//sf::Vector2f pos, float radius
}

void CombatComponent::updateCircle(sf::Vector2f direction)
{
	this->attackCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2 * direction.x,
		shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2 * direction.y
	);
}

void CombatComponent::receiveDamage(float damage)
{
	hitpoints -= damage;
	std::cout << "take damage\n";
	if (isDead())
	{
		std::cout << "dead\n";
			
	}
}

void CombatComponent::attack()
{
	auto temp = gObjects.getOverlapBounds(attackCircle);
	for (auto& enemy : temp)
	{
		enemy->getCombatComponent()->receiveDamage(damage);
	}
}

void CombatComponent::update(sf::Vector2f direction, const float& dt)
{
	updateCircle(direction);
}

void CombatComponent::render(sf::RenderWindow& target)
{
	target.draw(this->attackCircle);
}
