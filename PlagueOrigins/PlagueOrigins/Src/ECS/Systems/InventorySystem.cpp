#include "stdafx.h"
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

void InventorySystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view) 
	{
		Inventory& inventory = reg.get<Inventory>(entity);
		std::cout << inventory.essence << std::endl;
	}
	std::cout << " Hello epta" << std::endl;
}

void InventorySystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{

}
