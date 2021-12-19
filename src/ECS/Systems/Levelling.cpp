#include "stdafx.h"

#include "Levelling.h"

#include "ECS/Components/Stats.h"

float Levelling::Hp()
{
	return VIT*20.f;
}

float Levelling::Stamina()
{
	return END*10.f;
}

float Levelling::Damage()
{
	return STR*5.0f;
}

float Levelling::Armor()
{
	return AGI*0.5f;
}

float Levelling::DashCD()
{
	return 10.f/AGI+1.f;
}

float Levelling::SkillDamage()
{
	return INTT*5.5f;
}

float Levelling::SkillCD()
{
	return 20.0f/INTT+6.66f;
}

void Levelling::increaseChar(Stats& stats, unsigned int value, charName charName)
{
    switch (charName)
    {
    case charName::VIT:
        VIT += value;
        break;
    case charName::END:
        END += value;
        break;
    case charName::STR:
        STR += value;
        break;
    case charName::AGI:
        AGI += value;
        break;
    case charName::INTT:
        INTT += value;
        break;
    case charName::HUM:
        HUM += value;
        break;
    default:
        break;
    }
}

void Levelling::decreaseChar(Stats& stats, unsigned int value, charName charName)
{
    switch (charName)
    {
    case charName::VIT:
        VIT -= value;
        break;
    case charName::END:
        END -= value;
        break;
    case charName::STR:
        STR -= value;
        break;
    case charName::AGI:
        AGI -= value;
        break;
    case charName::INTT:
        INTT -= value;
        break;
    case charName::HUM:
        HUM -= value;
        break;
    default:
        break;
    }
}
