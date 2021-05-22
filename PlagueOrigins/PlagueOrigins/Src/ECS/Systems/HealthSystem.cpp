#include "stdafx.h"
#include "HealthSystem.h"

void HealthSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Health, PlayerInput>();
	for (auto entity : view)
	{

	}
}

void HealthSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Health, PlayerInput>();
	for (auto entity : view)
	{
		Health& health = reg.get<Health>(entity);

		tgui::Panel::Ptr statusBar = gui.get<tgui::Panel>("statusBar");
		tgui::ProgressBar::Ptr healthBar = statusBar->get<tgui::ProgressBar>("healthBar");

		float healthValue = health.curhealth * 100.f / health.maxHealth;

		if (healthValue <= 0.f) healthValue = 0.f;

		healthBar->setValue(healthValue);
	}
}
