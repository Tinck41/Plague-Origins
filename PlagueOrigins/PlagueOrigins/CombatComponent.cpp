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
	aggro = false;

	attackCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2,
		shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2
	);
	attackCircle.setRadius(shape.getSize().y / 2);
	attackCircle.setFillColor(sf::Color::Green);
	//sf::Vector2f pos, float radius

	aggroCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - aggroCircle.getRadius(),
		shape.getPosition().y + shape.getSize().y / 2 - aggroCircle.getRadius()
	);
	aggroCircle.setRadius(500.0f);
	attackCircle.setFillColor(sf::Color::White);
}

void CombatComponent::updateCircle(sf::Vector2f direction)
{
	attackCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2 * direction.x,
		shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
		+ shape.getSize().x / 2 * direction.y
	);
	aggroCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - aggroCircle.getRadius(),
		shape.getPosition().y + shape.getSize().y / 2 - aggroCircle.getRadius()
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

bool CombatComponent::checkAggro()
{
	if (gObjects.getPlayerAggro(aggroCircle))
	{
		aggroCircle.setFillColor(sf::Color::Red);
		return true;
	}
	else
	{
		aggroCircle.setFillColor(sf::Color::White);
		return false;
	}
}

bool CombatComponent::checkAttackRange()
{
	if (gObjects.getPlayerAggro(attackCircle))
	{
		std::cout << "Dog attacks\n";
		return true;
	}
	return false;
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
	checkAggro();
	checkAttackRange();
}

void CombatComponent::render(sf::RenderWindow& target)
{
	target.draw(attackCircle);
	target.draw(aggroCircle);
}
