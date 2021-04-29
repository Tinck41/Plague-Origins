#pragma once

#include "TileLayer.h"
//#include "MapCollider.h";

class TileMap
{
private:
	sf::Vector2u size;
	sf::Vector2u tileSize;

	std::vector<TileLayer> tileLayer;
	//std::vector<std::vector<MapCollider>> colliderLayer;

	void render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId);
public:
	TileMap(
		std::vector<TileLayer> layers,
		//std::vector<std::vector<MapCollider>> objects,
		sf::Vector2u mapSize,
		sf::Vector2u tileSize
	);
	TileMap();
	~TileMap();

	//std::vector<std::vector<MapCollider>> getObjects() { return this->colliderLayer; }
	sf::Vector2u getSize();

	void update(const float& dt);

	void renderUnderPlayerLayers(sf::RenderTarget& target);
	void renderOverPlayerLayers(sf::RenderTarget& target);
};
