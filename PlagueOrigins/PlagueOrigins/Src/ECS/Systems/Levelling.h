#pragma once

enum charName
{
    VIT,
    END,
    STR,
    AGI,
    INT,
    HUM
}

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
}