#pragma once

#include "TileLayer.h"
#include "ColliderLayer.h";
#include "Player.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;

	std::vector<TileLayer> layers;
	std::vector<std::vector<ColliderLayer>> objects;

	// Functions
	void render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId);
public:
	// Constructors/Destructor
	TileMap(
		std::vector<TileLayer> layers,
		sf::Vector2u size,
		std::vector<std::vector<ColliderLayer>> objects
	);
	TileMap();
	~TileMap();

	// Getters
	std::vector<std::vector<ColliderLayer>> getObjects() { return this->objects; }

	// Update
	void update(Player& player);

	// Render
	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);

	// Functions
};
