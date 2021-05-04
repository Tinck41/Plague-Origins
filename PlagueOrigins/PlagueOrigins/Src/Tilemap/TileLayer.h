#pragma once

#include "StaticTile.h"
#include "AnimatedTile.h"

class TileLayer : public sf::Drawable, public sf::Transformable
{
private:
	std::string name;
	bool isAnimated;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	std::vector<std::shared_ptr<StaticTile>> tiles;

	sf::VertexArray vertices;
	sf::Texture tileset;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawTile(uint32_t tileNumber, uint32_t x, uint32_t y);
	void loadLayer();
public:
	TileLayer(std::string name, bool isAnimated, std::vector<std::shared_ptr<StaticTile>> tiles, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset);
	TileLayer() = default;
	~TileLayer();

	void update(const float& dt);
};

