#pragma once

#include "TileLayer.h"
#include "Player.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;
	sf::Vector2u tileSize;

	std::vector<TileLayer> tileLayer;
	std::vector<std::vector<ColliderComponent>> colliderLayer;

	// Functions
	void render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId);
public:
	// Constructors/Destructor
	TileMap(
		std::vector<TileLayer> layers,
		std::vector<std::vector<ColliderComponent>> objects,
		sf::Vector2u mapSize,
		sf::Vector2u tileSize
	);
	TileMap();
	~TileMap();

	// Getters
	sf::Vector2u getSize();

	// Update
	void update(const float& dt);

	// Render
	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);

	// Functions
};
