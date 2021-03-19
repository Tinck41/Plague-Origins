#pragma once

#include "TileLayer.h"
#include "MapCollider.h";
#include "Player.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;

	std::vector<TileLayer> tileLayer;
	std::vector<std::vector<MapCollider>> colliderLayer;

	// Functions
	void render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId);
public:
	// Constructors/Destructor
	TileMap(
		std::vector<TileLayer> layers,
		sf::Vector2u size,
		std::vector<std::vector<MapCollider>> objects
	);
	TileMap();
	~TileMap();

	// Getters
	std::vector<std::vector<MapCollider>> getObjects() { return this->colliderLayer; }

	// Update
	void update(Player& player);

	// Render
	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);

	// Functions
};
