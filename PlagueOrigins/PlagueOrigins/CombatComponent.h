#pragma once
#include "GameObjects.h"

class CombatComponent
{
private:
	int id;
	objects objectType;

	float attackRange;
	float attackPosOffset;
	GameObjects& gObjects;

	b2Body* body;
	b2Body* attackBody;
	b2Body* aggroBody;

	sf::CircleShape attackCircle;
	sf::RectangleShape& shape;
	sf::CircleShape aggroCircle;

	bool aggro;
	float hitpoints;
	float damage;

	void initVariables();
public:
	CombatComponent(sf::RectangleShape& shape, int id, objects objectType, float hitpoints, float damage, float attackRange, b2Body* body);
	~CombatComponent();
	void receiveDamage(float damage);
	void attackNPC();
	void attackPlayer();

	void updateCircle(sf::Vector2f direction);
	void update(sf::Vector2f direction, const float& dt);
	void render(sf::RenderWindow& target);

	bool isAggro();
	bool isInAttackRange();

	bool isDead() { return hitpoints <= 0; }
	sf::Vector2f getPlayerPosition();
};

