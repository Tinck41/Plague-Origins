#pragma once

#include "TileLayer.h"
#include "MapCollider.h";
#include "Player.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;
	sf::Vector2u tileSize;

	std::vector<TileLayer> tileLayer;
	std::vector<std::vector<MapCollider>> colliderLayer;

	// Functions
	void render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId);
public:
	// Constructors/Destructor
	TileMap(
		std::vector<TileLayer> layers,
		std::vector<std::vector<MapCollider>> objects,
		sf::Vector2u mapSize,
		sf::Vector2u tileSize
	);
	TileMap();
	~TileMap();

	// Getters
	std::vector<std::vector<MapCollider>> getObjects() { return this->colliderLayer; }
	sf::Vector2u getSize() { return size; }
	sf::Vector2u getTileSize() { return tileSize; }

	// Update
	void update(Player& player);

	// Render
	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);

	// Functions
};
