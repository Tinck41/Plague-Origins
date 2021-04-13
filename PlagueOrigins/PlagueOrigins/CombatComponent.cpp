#include "stdafx.h"
#include "CombatComponent.h"
#include "Unit.h"

CombatComponent::CombatComponent(sf::RectangleShape& shape, int id, objects objectType, float hitpoints, float damage) :
	gObjects(GameObjects::Instance()), shape(shape)
{
	this->id = id;
	this->objectType = objectType;
	std::cout << "ID: " << id << "\n";
	std::cout << "OBJ ID: " << objectType << "\n";
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
	aggroCircle.setRadius(300.0f);
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
	Unit* player = gObjects.getPlayer();
	hitpoints -= damage;
	//std::cout << "receive " << damage << " damage\n";
	std::cout << "hp = " << hitpoints << "\n";
	if (isDead())
	{
		//TO-DO add baseCost to enemy config
		player->getInventory()->grantEssence(50);
		std::cout << "dead\n";
		Unit* temp = gObjects.getUnitById(id, objectType);
		gObjects.dropObject(temp, objectType);
	}
}

void CombatComponent::attackNPC()
{
	auto temp = gObjects.getOverlapBounds(attackCircle);
	for (auto& enemy : temp)
	{
		enemy->getCombatComponent()->receiveDamage(damage);
	}
}

void CombatComponent::attackPlayer()
{
	Unit* player = gObjects.getPlayer();
	player->getCombatComponent()->receiveDamage(damage);
}

void CombatComponent::update(sf::Vector2f direction, const float& dt)
{
	updateCircle(direction);
	isAggro();
	isInAttackRange();
}

void CombatComponent::render(sf::RenderWindow& target)
{
	//target.draw(aggroCircle);
	target.draw(attackCircle);
}

bool CombatComponent::isAggro()
{
	if (gObjects.getPlayerAggro(aggroCircle) && getPlayerPosition() != shape.getPosition())
	{
		aggro = true;
		aggroCircle.setFillColor(sf::Color::Red);
		return true;
	}
	else
	{
		aggro = false;
		aggroCircle.setFillColor(sf::Color::White);
		return false;
	}
}

bool CombatComponent::isInAttackRange()
{
	if (gObjects.getPlayerAggro(attackCircle))
	{
		attackCircle.setFillColor(sf::Color::Blue);
		return true;
	}
	else
	{
		attackCircle.setFillColor(sf::Color::Green);
		return false;
	}
}

sf::Vector2f CombatComponent::getPlayerPosition()
{
	auto player = gObjects.getPlayer();
	sf::Vector2f playerPos = player->getShape().getPosition();
	return playerPos;
}
