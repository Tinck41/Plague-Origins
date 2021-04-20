#pragma once

#include "AnimatedTile.h"
#include "StaticTile.h"

class TileLayer : public sf::Drawable, public sf::Transformable
{
private:
	const char* name;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	std::vector<Tile> layer;

	sf::VertexArray vertices;
	sf::Texture tileset;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void load();
public:
	TileLayer(const char* name, std::vector<Tile> layer, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset);
	TileLayer();
	~TileLayer();

	void update();
};

