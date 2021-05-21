#include "stdafx.h"
#include "DialogueSystem.h"

void DialogueSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
	gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
	gui.get<tgui::Panel>("tradePanel")->setVisible(false);
}

void DialogueSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
}

void DialogueSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
}
