#pragma once

#include "IOnCreateSystem.h"
#include "IRenderSystem.h"
#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class OverlaySystem :
	public IOnCreateSystem,
	public IUpdateSystem,
	public IRenderSystem
{
public:
	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) override;
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};