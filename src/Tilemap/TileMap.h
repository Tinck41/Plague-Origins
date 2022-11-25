#pragma once

#include "TileLayer.h"

class TileMap
{
private:
	sf::Vector2u size;
	sf::Vector2u tileSize;

	std::vector<std::shared_ptr<TileLayer>> tileLayers;

	void render(sf::RenderTarget& target, uint32_t firstLayerId, uint32_t lastLayerId);
public:
	TileMap(
		std::vector<std::shared_ptr<TileLayer>> layers,
		sf::Vector2u mapSize,
		sf::Vector2u tileSize
	);
	TileMap() = default;
	~TileMap();

	sf::Vector2u getSize();

	void update(const float& dt);

	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);
};
