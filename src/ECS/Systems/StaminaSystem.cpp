#include "stdafx.h"
#include "StaminaSystem.h"

void StaminaSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Stamina, Stats>();
	for (auto entity : view)
	{
		Stamina& stamina = reg.get<Stamina>(entity);
		Stats& stats = reg.get<Stats>(entity);

		if (stamina.canRestore == false) return;

		if (stamina.curStamina < stamina.maxStamina)
		{
			stamina.curStamina += stats.END * 2.f * dt;
		}
		else
		{
			stamina.curStamina = stamina.maxStamina;
		}
	}
}

void StaminaSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Stamina, PlayerInput>();
	for (auto entity : view)
	{
		Stamina& stamina = reg.get<Stamina>(entity);

		tgui::Panel::Ptr statusBar = gui.get<tgui::Panel>("statusBar");
		tgui::ProgressBar::Ptr staminaBar = statusBar->get<tgui::ProgressBar>("staminaBar");

		float staminaValue = stamina.curStamina * 100.f / stamina.maxStamina;

		if (staminaValue <= 0.f) staminaValue = 0.f;

		staminaBar->setValue(staminaValue);
	}
}
