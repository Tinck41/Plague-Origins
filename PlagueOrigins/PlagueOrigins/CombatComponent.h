#pragma once
#include "GameObjects.h"

class CombatComponent
{
private:
	float attackRange;
	GameObjects& gObjects;

	sf::CircleShape attackCircle;
	sf::RectangleShape& shape;

	sf::CircleShape aggroCircle;

	bool aggro;
	float hitpoints;
	float damage;

	void updateCircle(sf::Vector2f direction);
	void initVariables();
public:
	CombatComponent(sf::RectangleShape& shape, float hitpoints, float damage);
	void receiveDamage(float damage);
	bool checkAggro();
	bool checkAttackRange();
	void attack();
	void update(sf::Vector2f direction, const float& dt);
	void render(sf::RenderWindow& target);

	bool isTriggered() { return aggro; }
	bool isDead() { return hitpoints <= 0; }
};

