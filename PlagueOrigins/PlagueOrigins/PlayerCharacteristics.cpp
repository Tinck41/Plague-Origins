#include "stdafx.h"
#include "PlayerCharacteristics.h"

PlayerCharacteristics::PlayerCharacteristics(std::string name)
{
	if (name == "Player")
	{
		VIT = config.playerVIT;
		END = config.playerEND;
		STR = config.playerSTR;
		AGI = config.playerAGI;
		INT = config.playerINT;
		HUM = config.playerHUM;
	}
	else if (name == "Dog")
	{
		VIT = config.dogVIT;
		END = config.dogEND;
		STR = config.dogSTR;
		AGI = config.dogAGI;
		INT = config.dogINT;
		HUM = config.dogHUM;
	}
	else
	{
		VIT = 0;
		END = 0;
		STR = 0;
		AGI = 0;
		INT = 0;
		HUM = 0;
	}
}

float PlayerCharacteristics::Hp()
{
	return VIT*20.f;
}

float PlayerCharacteristics::Stamina()
{
	return END*10.f;
}

float PlayerCharacteristics::Damage()
{
	return STR*5.0f;
}

float PlayerCharacteristics::Armor()
{
	return AGI*0.5f;
}

float PlayerCharacteristics::DashCD()
{
	return 10.f/AGI+1.f;
}

float PlayerCharacteristics::SkillDamage()
{
	return INT*5.5f;
}

float PlayerCharacteristics::SkillCD()
{
	return 20.0f/INT+6.66f;
}

void PlayerCharacteristics::setChar(unsigned int value, charName charName)
{
	switch (charName)
	{
	case charName::VIT:
		VIT = value;
		break;
	case charName::END:
		END = value;
		break;
	case charName::STR:
		STR = value;
		break;
	case charName::AGI:
		AGI = value;
		break;
	case charName::INT:
		INT = value;
		break;
	case charName::HUM:
		HUM = value;
		break;
	default:
		break;
	}
}

int PlayerCharacteristics::getChar(charName charName)
{
	unsigned int temp;
	switch (charName)
	{
	case charName::VIT:
		temp = VIT;
		break;
	case charName::END:
		temp = END;
		break;
	case charName::STR:
		temp = STR;
		break;
	case charName::AGI:
		temp = AGI;
		break;
	case charName::INT:
		temp = INT;
		break;
	case charName::HUM:
		temp = HUM;
		break;
	default:
		temp = 0;
		break;
	}
	return temp;
}
