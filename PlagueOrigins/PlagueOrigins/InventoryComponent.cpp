#include "stdafx.h"
#include "InventoryComponent.h"

InventoryComponent::InventoryComponent()
{
	minimizedInventoryTexture = new sf::Texture();
	unfoldedInventoryTexture = new sf::Texture();
	minimizedInventorySprite = new sf::Sprite();
	unfoldedInventorySprite = new sf::Sprite();
	
	minimizedInventoryTexture->loadFromFile("./Assets/UI/minimizedInventory.png");
	unfoldedInventoryTexture->loadFromFile("./Assets/UI/unfoldedInventory.png");
	minimizedInventoryTexture->setSmooth(true);
	unfoldedInventoryTexture->setSmooth(true);
	
	minimizedInventorySprite->setTexture(*minimizedInventoryTexture);
	unfoldedInventorySprite->setTexture(*unfoldedInventoryTexture);

	gap = 10;

	scaleFactor = (float)(config.height() - gap * 2) / (float)unfoldedInventoryTexture->getSize().y;
	minimizedInventorySprite->setScale(scaleFactor, scaleFactor);
	unfoldedInventorySprite->setScale(scaleFactor, scaleFactor);
}

void InventoryComponent::update(sf::Vector2f position)
{
	sf::Vector2f minimizedPos = sf::Vector2f(position.x + gap, position.y + gap);
	minimizedInventorySprite->setPosition(minimizedPos);
	
	sf::Vector2f unfoldedPos = sf::Vector2f(position.x + gap + minimizedInventoryTexture->getSize().x * scaleFactor + gap, position.y + gap);
	unfoldedInventorySprite->setPosition(unfoldedPos);
}

void InventoryComponent::render(sf::RenderWindow& window)
{
	window.draw(*minimizedInventorySprite);
	window.draw(*unfoldedInventorySprite);
}

InventoryComponent::~InventoryComponent()
{
	delete minimizedInventoryTexture;
	delete minimizedInventorySprite;
	delete unfoldedInventoryTexture;
	delete unfoldedInventorySprite;
}
