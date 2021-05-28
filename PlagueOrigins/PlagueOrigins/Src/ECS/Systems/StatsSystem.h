#pragma once
#include "Src/ECS/Components.h"

class StatsSystem
{
public:
	float newHp(Stats& stats, int value);
	float newStamina(Stats& stats, int value);
	float newDamage(Stats& stats, int value);
	float newDashCD(Stats& stats, int value);

	void increaseChar(entt::registry& reg, entt::entity player, Stats& stats, Inventory& essence, charName charName);
	void decreaseChar(entt::registry& reg, entt::entity player, Stats& stats, Inventory& essence, charName charName);
};