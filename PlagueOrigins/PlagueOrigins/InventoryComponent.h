#pragma once
class InventoryComponent
{
private:
	sf::Texture* minimizedInventoryTexture;
	sf::Texture* unfoldedInventoryTexture;
	sf::Sprite* unfoldedInventorySprite;
	sf::Sprite* minimizedInventorySprite;
	float scaleFactor;
	float gap;
public:
	InventoryComponent();
	~InventoryComponent();
	void update(sf::Vector2f position);
	void render(sf::RenderWindow& window);
};

