#pragma once

class InventoryComponent;

class InventoryRendererComponent
{
private:
	InventoryComponent* inventory;
	bool minimizedVisible;
	bool unfoldedVisible;
public:
	InventoryRendererComponent(InventoryComponent& inventory);

	void render(sf::RenderWindow& window);
	void closeAll();
	void openMinimized();
	void openUnfolded();
};

