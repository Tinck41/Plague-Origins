#include "stdafx.h"
#include "HealthSystem.h"

void HealthSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<RigidBody, Health, Transform, Tag>();
	for (auto entity : view)
	{
		tgui::Theme theme{ "../vendor/TGUI-0.9/gui-builder/themes/Black.txt" };

		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Health& health = reg.get<Health>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero") continue;

		tgui::ProgressBar::Ptr healthBar = tgui::ProgressBar::create();
		
		healthBar->getRenderer()->setBorders(3.f);
		healthBar->getRenderer()->setBackgroundColor(tgui::Color::Transparent);
		healthBar->getRenderer()->setFillColor(tgui::Color::Red);
		healthBar->setMaximum(100);
		healthBar->setSize(rigidBody.size.x * 2.f, 15.f);
		healthBar->setPosition(transform.position.x, transform.position.y);
		healthBar->moveToFront();
		healthBar->setVisible(true);

		std::string widgetName = std::to_string(uint32_t(entity)) + "healthBar";

		gui.add(healthBar, widgetName);
	}
}

void HealthSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<RigidBody, Health, Transform, Tag>();
	for (auto entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Health& health = reg.get<Health>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero") continue;

		std::string widgetName = std::to_string(uint32_t(entity)) + "healthBar";
		auto healthBar = gui.get<tgui::ProgressBar>(widgetName);

		healthBar->setPosition(transform.position.x - rigidBody.size.x / 2.f, transform.position.y - rigidBody.size.y / 0.7f);

		if (health.curhealth == health.maxHealth || health.curhealth <= 0)
		{
			healthBar->setVisible(false);
		}
		else
		{
			healthBar->setVisible(true);
		}
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

	auto mobsView = reg.view<Health, Transform, Tag>();
	for (auto entity : mobsView)
	{
		Health& health = reg.get<Health>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero") continue;

		std::string widgetName = std::to_string(uint32_t(entity)) + "healthBar";

		auto healthBar = gui.get<tgui::ProgressBar>(widgetName);
		float healthValue = health.curhealth * 100.f / health.maxHealth;

		healthBar->setValue(healthValue);

		healthBar->setPosition(gui.mapPixelToView(window.mapCoordsToPixel(healthBar->getPosition()).x, window.mapCoordsToPixel(healthBar->getPosition()).y));
	}
}

void HealthSystem::onDestroy(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<Health, Tag>();
	for (auto& entity : view)
	{
		Health& health = reg.get<Health>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero") continue;

		std::string widgetName = std::to_string(uint32_t(entity)) + "healthBar";
		auto healthBar = gui.get<tgui::ProgressBar>(widgetName);

		gui.remove(healthBar);
	}
}

