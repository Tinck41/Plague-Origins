#include "stdafx.h"
#include "RestartSystem.h"

void RestartSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<BossFightArena>();
	for (auto entity : view)
	{
		BossFightArena bossFightArena = reg.get<BossFightArena>(entity);

		if (bossFightArena.playerIsDead)
		{
			auto screenManager = reg.view<CurrentScreen>();
			for (auto manager : screenManager)
			{
				std::cout << "player is dead\n";
				CurrentScreen& currentScreen = reg.get<CurrentScreen>(manager);
				currentScreen.gameOver = true;
				gui.get<tgui::Panel>("gameOverPanel")->setVisible(true);
				gui.get<tgui::Label>("lossLabel")->setVisible(true);
				if (gui.get<tgui::Button>("retryButton")->isMouseDown())
				{
					setRetryButton(currentScreen);
					gui.get<tgui::Panel>("gameOverPanel")->setVisible(false);
					gui.get<tgui::Label>("lossLabel")->setVisible(false);
					//reset BossFightArena
					bossFightArena.bossIsDead = false;
					bossFightArena.playerIsDead = false;
					bossFightArena.arenaClosed = false;
				}
				if (gui.get<tgui::Button>("exit2Button")->isMouseDown())
				{
					setExitButton(currentScreen);
					gui.get<tgui::Panel>("gameOverPanel")->setVisible(false);
					gui.get<tgui::Label>("lossLabel")->setVisible(false);
					//reset BossFightArena
					bossFightArena.bossIsDead = false;
					bossFightArena.playerIsDead = false;
					bossFightArena.arenaClosed = false;
				}
			}
		}
		else if (bossFightArena.bossIsDead)
		{
			auto screenManager = reg.view<CurrentScreen>();
			for (auto manager : screenManager)
			{
				std::cout << "boss is dead\n";
				CurrentScreen& currentScreen = reg.get<CurrentScreen>(manager);
				currentScreen.gameOver = true;
				gui.get<tgui::Panel>("gameOverPanel")->setVisible(true);
				gui.get<tgui::Label>("winLabel")->setVisible(true);
				if (gui.get<tgui::Button>("retryButton")->isMouseDown())
				{
					setRetryButton(currentScreen);
					gui.get<tgui::Panel>("gameOverPanel")->setVisible(false);
					gui.get<tgui::Label>("lossLabel")->setVisible(false);
					//reset BossFightArena
					bossFightArena.bossIsDead = false;
					bossFightArena.playerIsDead = false;
					bossFightArena.arenaClosed = false;
				}
				if (gui.get<tgui::Button>("exit2Button")->isMouseDown())
				{
					setExitButton(currentScreen);
					gui.get<tgui::Panel>("gameOverPanel")->setVisible(false);
					gui.get<tgui::Label>("lossLabel")->setVisible(false);
					//reset BossFightArena
					bossFightArena.bossIsDead = false;
					bossFightArena.playerIsDead = false;
					bossFightArena.arenaClosed = false;
				}
			}
		}
	}
}

void RestartSystem::setRetryButton(CurrentScreen& currentScreen)
{
	currentScreen.gameOver = false;
	currentScreen.restart = true;
}

void RestartSystem::setExitButton(CurrentScreen& currentScreen)
{
	currentScreen.gameOver = false;
	currentScreen.exit = true;
}
