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
				currentScreen.type = ScreenType::LOSS;
			}
		}
		else if (bossFightArena.bossIsDead)
		{
			auto screenManager = reg.view<CurrentScreen>();
			for (auto manager : screenManager)
			{
				CurrentScreen& currentScreen = reg.get<CurrentScreen>(manager);
				currentScreen.type = ScreenType::WIN;
			}
		}
	}
}