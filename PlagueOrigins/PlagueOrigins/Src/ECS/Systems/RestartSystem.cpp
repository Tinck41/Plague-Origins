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
				CurrentScreen& currentScreen = reg.get<CurrentScreen>(manager);
				currentScreen.gameOver = true;
				gui.get<tgui::Label>("winLabel")->setVisible(true);
				if (gui.get<tgui::Button>("retryButton")->isMouseDown())
				{
					setRetryButton(currentScreen);
				}
				if (gui.get<tgui::Button>("exit2Button")->isMouseDown())
				{
					setExitButton(currentScreen);
				}
			}
		}
		else if (bossFightArena.bossIsDead)
		{
			auto screenManager = reg.view<CurrentScreen>();
			for (auto manager : screenManager)
			{
				CurrentScreen& currentScreen = reg.get<CurrentScreen>(manager);
				currentScreen.gameOver = true;
				gui.get<tgui::Label>("winLabel")->setVisible(true);
				if (gui.get<tgui::Button>("retryButton")->isMouseDown())
				{
					setRetryButton(currentScreen);
				}
				if (gui.get<tgui::Button>("exit2Button")->isMouseDown())
				{
					setExitButton(currentScreen);
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
