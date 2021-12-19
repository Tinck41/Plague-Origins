#include "stdafx.h"
#include "EssenceSystem.h"

void EssenceSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view)
	{
		Inventory& inventory = reg.get<Inventory>(entity);
	}
}

void EssenceSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view)
	{
		Inventory& inventory = reg.get<Inventory>(entity);

		tgui::TextArea::Ptr essenceCount = gui.get<tgui::TextArea>("essenceBarText");
		essenceCount->setText((tgui::String)inventory.essence);
	}
}
