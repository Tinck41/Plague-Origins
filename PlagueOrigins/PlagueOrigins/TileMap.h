#pragma once

#include "TileLayer.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;

	std::vector<TileLayer> layers;

	// Functions
public:
	// Constructor/Destructor
	TileMap();
	TileMap(std::vector<TileLayer> layers, sf::Vector2u size);
	~TileMap();

	// Setters
	void setLayers(std::vector<TileLayer> layers) { this->layers = layers; }
	void setSize(sf::Vector2u size) { this->size = size; }

	// Getters
	std::vector<TileLayer> getLayers() { return this->layers; }

	// Update
	void update();

	// Render
	void render(sf::RenderTarget& target);

	// Functions
	void loadLayers();
};
