#include "stdafx.h"
#include "LevelUpComponent.h"

LevelUpComponent::LevelUpComponent(sf::RectangleShape& merchant, Player& player) :
	player(player), merchant(merchant)
{
	stats = new PlayerCharacteristics();
	initTrigger();
}

LevelUpComponent::~LevelUpComponent()
{
	delete stats;
	stats = NULL;
}

void LevelUpComponent::initTrigger()
{
	interactionTrigger.setSize(merchant.getSize());
	interactionTrigger.setScale(1.5f, 1.5f);
	interactionTrigger.setPosition(merchant.getPosition());
}

void LevelUpComponent::increaseChar(unsigned int value, charName charName)
{
	stats->setChar(stats->getChar(charName) + value, charName);
}

void LevelUpComponent::decreaseChar(unsigned int value, charName charName)
{
	stats->setChar(stats->getChar(charName) - value, charName);
}

void LevelUpComponent::resetChars()
{
	delete stats;
	stats = new PlayerCharacteristics();
}
