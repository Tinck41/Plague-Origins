#pragma once

#include "TileLayer.h"
#include "AnimatedTile.h"


class AnimatedTileLayer :
	public TileLayer
{
private:
	std::vector<AnimatedTile> tiles;

	void loadTiles();
public:
	AnimatedTileLayer(
		std::string name, std::vector<AnimatedTile> tiles,
		sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset
	);
	~AnimatedTileLayer();

	virtual void update(const float& dt);
};