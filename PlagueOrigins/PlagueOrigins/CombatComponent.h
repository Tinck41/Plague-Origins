#pragma once
#include "GameObjects.h"

class CombatComponent
{
private:
	float attackRange;
	GameObjects& gObjects;

	sf::CircleShape attackCircle;
	sf::RectangleShape& shape;

	float hitpoints;
	float damage;

	void updateCircle(sf::Vector2f direction);
	void initVariables();
public:
	CombatComponent(sf::RectangleShape& shape, float hitpoints, float damage);
	void receiveDamage(float damage);
	void attack();
	void update(sf::Vector2f direction, const float& dt);
	void render(sf::RenderWindow& target);

	bool isDead() { return hitpoints <= 0; }
};

