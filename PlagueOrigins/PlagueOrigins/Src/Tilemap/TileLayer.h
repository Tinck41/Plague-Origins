#pragma once

class TileLayer : public sf::Drawable, public sf::Transformable
{
protected:
	std::string name;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	sf::VertexArray vertices;
	std::shared_ptr<sf::Texture> tileset;
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawTile(uint32_t tileNumber, uint32_t x, uint32_t y);
public:
	TileLayer(std::string name, sf::Vector2u size, sf::Vector2u tileSize, std::shared_ptr<sf::Texture> tileset);
	TileLayer() = default;
	~TileLayer();

	virtual void update(const float& dt);
};

