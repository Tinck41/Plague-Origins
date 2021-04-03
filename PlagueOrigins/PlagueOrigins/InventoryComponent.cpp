#include "stdafx.h"
#include "InventoryComponent.h"
#include "ClosedState.h"

InventoryComponent::InventoryComponent()
{
	minimizedInventoryTexture = new sf::Texture();
	minimizedInventorySprite = new sf::Sprite();
	unfoldedInventoryTexture = new sf::Texture();
	unfoldedInventorySprite = new sf::Sprite();
	
	// Load resources
	minimizedInventoryTexture->loadFromFile("./Assets/UI/minimizedInventory.png");
	minimizedInventoryTexture->setSmooth(true);
	minimizedInventorySprite->setTexture(*minimizedInventoryTexture);
	unfoldedInventoryTexture->loadFromFile("./Assets/UI/unfoldedInventory.png");
	unfoldedInventoryTexture->setSmooth(true);
	unfoldedInventorySprite->setTexture(*unfoldedInventoryTexture);

	// Scale sprites
	gap = 10;
	scaleFactor = (float)(config.height() - gap * 2) / (float)unfoldedInventoryTexture->getSize().y;
	minimizedInventorySprite->setScale(scaleFactor, scaleFactor);
	unfoldedInventorySprite->setScale(scaleFactor, scaleFactor);

	// Set initial state
	inventoryRenderer = new InventoryRendererComponent(*this);
	inventoryStateMachine = new FiniteStateMachine();
	initState = new ClosedState(*this);
	inventoryStateMachine->changeState(initState);
}

void InventoryComponent::update(const float& dt, sf::Vector2f position)
{
	sf::Vector2f minimizedPos = sf::Vector2f(position.x + gap, position.y + gap);
	minimizedInventorySprite->setPosition(minimizedPos);
	
	sf::Vector2f unfoldedPos = sf::Vector2f(position.x + gap + minimizedInventoryTexture->getSize().x * scaleFactor + gap, position.y + gap);
	unfoldedInventorySprite->setPosition(unfoldedPos);

	inventoryStateMachine->executeStateUpdate(dt);
}

void InventoryComponent::render(sf::RenderWindow& window)
{
	inventoryRenderer->render(window);
}

InventoryComponent::~InventoryComponent()
{
	delete minimizedInventoryTexture;
	delete minimizedInventorySprite;
	delete unfoldedInventoryTexture;
	delete unfoldedInventorySprite;
	delete initState;
	delete inventoryStateMachine;
	delete inventoryRenderer;
}
