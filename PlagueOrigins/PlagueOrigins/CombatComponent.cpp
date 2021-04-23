#include "stdafx.h"
#include "CombatComponent.h"
#include "Unit.h"

CombatComponent::CombatComponent(sf::RectangleShape& shape, int id, objects objectType, float hitpoints, float damage, float attackRange, b2Body* body) :
	gObjects(GameObjects::Instance()), shape(shape)
{
	this->id = id;
	this->objectType = objectType;
	this->attackRange = attackRange;
	this->body = body;
	std::cout << "ID: " << id << "\n";
	std::cout << "OBJ ID: " << objectType << "\n";
	this->hitpoints = hitpoints;
	this->damage = damage;
	initVariables();
}

CombatComponent::~CombatComponent()
{
	//PhysicsWorld::getWorld()->DestroyJoint(attackBody->GetJointList()->joint);
	PhysicsWorld::getWorld()->DestroyBody(attackBody);
	//PhysicsWorld::getWorld()->DestroyJoint(aggroBody->GetJointList()->joint);
	PhysicsWorld::getWorld()->DestroyBody(aggroBody);
}

void CombatComponent::initVariables()
{
	aggro = false;
	attackPosOffset = 50.f;
	attackCircle.setRadius(attackRange);
	attackCircle.setFillColor(sf::Color::Green);

	attackCircle.setPosition(
		shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
		+ attackPosOffset,
		shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
		+ attackPosOffset
	);
	
	//if not player
	if (id != 1)
	{
		sf::Vector2f aggroRadius = sf::Vector2f(aggroCircle.getRadius(), aggroCircle.getRadius());
		aggroCircle.setRadius(1600.0f);
		aggroCircle.setPosition(
			shape.getPosition().x + shape.getSize().x / 2 - aggroCircle.getRadius(),
			shape.getPosition().y + shape.getSize().y / 2 - aggroCircle.getRadius()
		);

		attackBody = PhysicsWorld::createCircleBody(shape.getPosition(), attackCircle.getRadius(), true, true, ATTACK_RADIUS, PLAYER);
		aggroBody = PhysicsWorld::createCircleBody(shape.getPosition(), aggroCircle.getRadius(), true, true, ENEMY_AGGRO_RADIUS, PLAYER);
	}
	else
	{
		attackBody = PhysicsWorld::createCircleBody(shape.getPosition(), attackCircle.getRadius(), true, true, ATTACK_RADIUS, ENEMY_NPC);
		//aggroBody = PhysicsWorld::createCircleBody(shape.getPosition(), aggroCircle.getRadius(), true, true, ENEMY_AGGRO_RADIUS, PLAYER);
	}
	
}

void CombatComponent::updateCircle(sf::Vector2f direction)
{
	if (direction != sf::Vector2f(0.f, 0.f))
	{
		b2Vec2 temp = b2Vec2();
		if (id != 1)
		{
			aggroCircle.setPosition(
				shape.getPosition().x + shape.getSize().x / 2 - aggroCircle.getRadius(),
				shape.getPosition().y + shape.getSize().y / 2 - aggroCircle.getRadius()
			);
			temp.x = (aggroCircle.getPosition().x + aggroCircle.getRadius()) / 30.f;
			temp.y = (aggroCircle.getPosition().y + aggroCircle.getRadius()) / 30.f;
			aggroBody->SetTransform(temp, body->GetAngle());
		}
		attackCircle.setPosition(
			shape.getPosition().x + shape.getSize().x / 2 - attackCircle.getRadius()
			+ attackPosOffset * direction.x,
			shape.getPosition().y + shape.getSize().y / 2 - attackCircle.getRadius()
			+ attackPosOffset * direction.y
		);
		temp.x = (attackCircle.getPosition().x + attackCircle.getRadius()) / 30.f;
		temp.y = (attackCircle.getPosition().y + attackCircle.getRadius()) / 30.f;
		attackBody->SetTransform(temp, body->GetAngle());
		
	}
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
		
		//Unit* temp = gObjects.getUnitById(id, objectType);
		//gObjects.dropObject(temp, objectType);
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
	target.draw(aggroCircle);
	target.draw(attackCircle);
}

bool CombatComponent::isAggro()
{
	if (PhysicsWorld::getAggro())
	{

		aggro = true;
		aggroCircle.setFillColor(sf::Color::Red);
		return true;
	}
	aggro = false;
	aggroCircle.setFillColor(sf::Color::White);
	return false;

	//if (gObjects.getPlayerAggro(aggroCircle) && getPlayerPosition() != shape.getPosition())
	//{
	//	aggro = true;
	//	aggroCircle.setFillColor(sf::Color::Red);
	//	return true;
	//}
	//else
	//{
	//	aggro = false;
	//	aggroCircle.setFillColor(sf::Color::White);
	//	return false;
	//}
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
