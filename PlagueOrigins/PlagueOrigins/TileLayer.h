#pragma once

class TileLayer : public sf::Drawable, public sf::Transformable
{
private:
	// Variables
	const char* name;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	// Array with tiles ID
	std::vector<unsigned> layer;

	// Fast drawing vertex array
	sf::VertexArray vertices;
	sf::Texture tileset;

	// Functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	// Constructor/Destructor
	TileLayer(const char* name, std::vector<unsigned> layer, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset);
	TileLayer();
	~TileLayer();

	// Update
	void update();

	// Functions
	void load();
};

