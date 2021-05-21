#pragma once

#include "IRenderSystem.h"
#include "IUpdateSystem.h"
#include "Src/ECS/Components.h"

class Interaction :
	public IRenderSystem,
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
private:
	bool checkForPlayer(RigidBody& rigidBody);
};