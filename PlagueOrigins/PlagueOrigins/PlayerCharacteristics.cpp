#include "stdafx.h"
#include "PlayerCharacteristics.h"

PlayerCharacteristics::PlayerCharacteristics()
{
	VIT = 5;
	END = 5;
	STR = 5;
	AGI = 5;
	INT = 5;
	HUM = 5;
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
