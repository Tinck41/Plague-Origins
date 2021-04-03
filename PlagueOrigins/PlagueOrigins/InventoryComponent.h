#pragma once

#include "FiniteStateMachine.h"
#include "InventoryRendererComponent.h"

class ClosedState;

class InventoryComponent
{
private:
	sf::Texture* minimizedInventoryTexture;
	sf::Texture* unfoldedInventoryTexture;
	
	float scaleFactor;
	float gap;
	
	FiniteStateMachine* inventoryStateMachine;
	State* initState;

public:
	InventoryComponent();
	~InventoryComponent();

	InventoryRendererComponent* inventoryRenderer;
	sf::Sprite* unfoldedInventorySprite;
	sf::Sprite* minimizedInventorySprite;

	void update(const float& dt, sf::Vector2f position);
	void render(sf::RenderWindow& window);

	// TODO: убрать
	bool escapeReleased = true;

	FiniteStateMachine* getStateMachine() { return this->inventoryStateMachine; }
};