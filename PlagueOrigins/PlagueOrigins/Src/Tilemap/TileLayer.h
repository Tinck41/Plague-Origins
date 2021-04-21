#pragma once

#include "Tile.h"

class TileLayer : public sf::Drawable, public sf::Transformable
{
private:
	const char* name;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	std::vector<Tile> tiles;

	sf::VertexArray vertices;
	sf::Texture tileset;

	bool firstRender;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawTile(uint32_t tileNumber, uint32_t x, uint32_t y);
public:
	TileLayer(const char* name, std::vector<Tile> tiles, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset);
	TileLayer() {}
	~TileLayer();

	void update(const float& dt);
};

