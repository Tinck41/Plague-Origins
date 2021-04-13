#include "stdafx.h"
#include "LevelUpComponent.h"
#include "Unit.h"
#include "InputBooleans.h"

LevelUpComponent::LevelUpComponent(sf::RectangleShape& merchant) :
//LevelUpComponent::LevelUpComponent(sf::RectangleShape& merchant, Player& player) :
	merchant(merchant), gObjects(GameObjects::Instance())
{
	stats = new PlayerCharacteristics();
	initTrigger();
	player = gObjects.getPlayer();
	interacting = false;

	delay = sf::seconds(10.f);
	last = gameClock.getElapsedTime();
}

LevelUpComponent::~LevelUpComponent()
{
	delete stats;
	stats = NULL;
}

void LevelUpComponent::interact()
{
	//timer
	std::cout << "frizi uydite\n";

	//sf::Time now = gameClock.getElapsedTime();
	//if (now - last >= delay)
	//{
	//	//while (InputBooleans::isFPressed && interactionTrigger.getGlobalBounds().intersects(player->getShape().getGlobalBounds()) && !interacting)
	//	//if (InputBooleans::isFPressed && interactionTrigger.getGlobalBounds().intersects(player->getShape().getGlobalBounds()) && !interacting)
	//	if (InputBooleans::isFPressed && gObjects.getPlayerInteraction(interactionTrigger) && !interacting)
	//	{
	//		last = now;
	//		InputBooleans::handled = false;
	//		interacting = true;
	//		std::cout << "INTERACTION START\n";



	//		bool pressed = false;


	//		//poka chto tak
	//		while (interacting)
	//		{
	//			//t
	//			InputBooleans iB;
	//			iB.update();

	//			if (InputBooleans::isWPressed && !pressed)
	//			{
	//				pressed = true;
	//				std::cout << InputBooleans::isWPressed << pressed << "\n";
	//				std::cout << "Get Stats\n";
	//				std::cout << "Vitality = " << stats->getChar(charName::VIT) << "\n";
	//				std::cout << "Endurance = " << stats->getChar(charName::END) << "\n";
	//				std::cout << "Strength = " << stats->getChar(charName::STR) << "\n";
	//				std::cout << "Agility = " << stats->getChar(charName::AGI) << "\n";
	//				std::cout << "Intelligence = " << stats->getChar(charName::INT) << "\n";
	//				//std::cout << "Humanity = " << stats->getChar(charName::HUM) << "\n";
	//			}
	//			else if (InputBooleans::isAPressed && !pressed)
	//			{
	//				pressed = true;
	//				std::cout << "Increase Vitality by 1 point\n";
	//				increaseChar(1, charName::VIT);
	//				std::cout << "Vitality = " << stats->getChar(charName::VIT) << "\n";
	//			}
	//			if (!InputBooleans::isWPressed && !InputBooleans::isAPressed && pressed)
	//			{
	//				pressed = false;
	//			}

	//			//exit interaction
	//			if (InputBooleans::isQPressed)
	//			{
	//				InputBooleans::isEscapePressed = false;
	//				InputBooleans::handled = true;
	//				interacting = false;
	//				std::cout << "INTERACTION END\n";
	//			}
	//		}

	//	}
	//}
	

}

void LevelUpComponent::initTrigger()
{
	sf::Vector2f size = { merchant.getSize().x * 2.22f, merchant.getSize().y * 2.22f };
	interactionTrigger.setSize(size);
	interactionTrigger.setPosition(
		merchant.getPosition().x + merchant.getSize().x/2 - interactionTrigger.getSize().x/2,
		merchant.getPosition().y + merchant.getSize().y/2 - interactionTrigger.getSize().y/2);
	interactionTrigger.setFillColor(sf::Color::White);
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
