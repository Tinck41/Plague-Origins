#include "stdafx.h"
#include "DialogueSystem.h"

DialogueSystem::DialogueSystem()
{
}

void DialogueSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
	gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
	gui.get<tgui::Panel>("tradePanel")->setVisible(false);
}

void DialogueSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Dialogue, PlayerInput>();
	for (auto entity : view)
	{
		Dialogue& dialogue = reg.get<Dialogue>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		if (playerInput.fReleased)
		{
			dialogueSwitch(dialogue);
		}
		
		if (playerInput.LMBreleased && dialogue.state == 1)
		{
			if (gui.get<tgui::Button>("upgradeStatsButton")->isMouseDown()) dialogue.state = 2;
			if (gui.get<tgui::Button>("tradeButton")->isMouseDown()) dialogue.state = 3;
			if (gui.get<tgui::Button>("exitButton")->isMouseDown()) dialogue.state = 0;
		}
	}
}

void DialogueSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Dialogue>();
	for (auto entity : view)
	{
		Dialogue& dialogue = reg.get<Dialogue>(entity);
		switch (dialogue.state)
		{
		case 0:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
			break;
		case 1:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(true);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
			break;
		case 2:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(true);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
		break;
		case 3:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(true);
		break;
		default:
			break;
		}
	}
}

void DialogueSystem::dialogueSwitch(Dialogue& dialogue)
{
	if (dialogue.state == 0)
	{
		dialogue.state = 1;
	}
	else if (dialogue.state > 1)
	{
		dialogue.state = 1;
	}
	else if (dialogue.state == 1)
	{
		dialogue.state = 0;
	}
}
