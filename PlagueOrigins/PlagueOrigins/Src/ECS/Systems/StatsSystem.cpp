#include "stdafx.h"
#include "StatsSystem.h"

void StatsSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Health, Stamina>();
	for (auto entity : view)
	{
		Health& health = reg.get<Health>(entity);
		Stamina& stamina = reg.get<Stamina>(entity);
	}
}

void StatsSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Health, Stamina>();
	for (auto entity : view)
	{
		Health& health = reg.get<Health>(entity);
		Stamina& stamina = reg.get<Stamina>(entity);

		tgui::Panel::Ptr statusBar = gui.get<tgui::Panel>("statusBar");
		tgui::ProgressBar::Ptr healthBar = statusBar->get<tgui::ProgressBar>("healthBar");
		tgui::ProgressBar::Ptr staminaBar = statusBar->get<tgui::ProgressBar>("staminaBar");
		
		healthBar->setValue(health.curhealth * 100.f / health.maxHealth);
		staminaBar->setValue(stamina.curStamina * 100.f / stamina.maxStamina);
	}
}
