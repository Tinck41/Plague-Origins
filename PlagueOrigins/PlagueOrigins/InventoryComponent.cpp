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
}

void InventoryComponent::update(sf::Vector2f position)
{
	minimizedInventorySprite->setPosition(position);
	unfoldedInventorySprite->setPosition(position);
}

void InventoryComponent::render(sf::RenderWindow& window)
{
	//window.draw(*minimizedInventorySprite);
	window.draw(*unfoldedInventorySprite);
}

InventoryComponent::~InventoryComponent()
{
	delete minimizedInventoryTexture;
	delete minimizedInventorySprite;
	delete unfoldedInventoryTexture;
	delete unfoldedInventorySprite;
}
