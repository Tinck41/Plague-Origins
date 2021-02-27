#pragma once

#include "TileLayer.h"
#include "ColliderComponent.h"
#include "Player.h"

class TileMap
{
private:
	// Variables
	sf::Vector2u size;

	std::vector<TileLayer> layers;
	std::vector<std::vector<sf::RectangleShape>> objects;

	// Functions
public:
	// Constructor/Destructor
	TileMap();
	TileMap(std::vector<TileLayer> layers, sf::Vector2u size);
	~TileMap();

	// Setters
	void setLayers(std::vector<TileLayer> layers) { this->layers = layers; }
	void setSize(sf::Vector2u size) { this->size = size; }
	void setObjects(std::vector<std::vector<sf::RectangleShape>> objects) { this->objects = objects; }

	// Getters
	std::vector<TileLayer> getLayers() { return this->layers; }

	// Update
	void update(Player& player);

	// Render
	void render(sf::RenderTarget& target);
	void renderFirstLayer(sf::RenderTarget& target);
	void renderSecondLayer(sf::RenderTarget& target);

	// Functions
	void loadLayers();
	ColliderComponent getCollider(sf::RectangleShape& rect);
};
