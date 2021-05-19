#include "stdafx.h"
#include "DialogueSystem.h"

void DialogueSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("mainPanel")->setVisible(false);
	gui.get<tgui::Picture>("mainDialogueBox")->setVisible(false);
	gui.get<tgui::Picture>("upgradeStatsBox")->setVisible(false);
	gui.get<tgui::Picture>("tradingBox")->setVisible(false);
}

void DialogueSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
}

void DialogueSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
}
