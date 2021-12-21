#pragma once
#include "ECS/Components/Stats.h"

class Levelling
{
	float Hp();
	float Stamina();
	float Damage();
	float Armor();
	float DashCD();
	float SkillDamage();
	float SkillCD();
	void increaseChar(Stats& stats, unsigned int value, charName charName);
	void decreaseChar(Stats& stats, unsigned int value, charName charName);
};