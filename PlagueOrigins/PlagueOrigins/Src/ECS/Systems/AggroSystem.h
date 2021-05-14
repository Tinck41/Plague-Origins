#pragma once
#include "Src/ECS/Components.h"
#include "Src/ECS/Systems/IUpdateSystem.h"
#include "Src/ECS/Systems/IRenderSystem.h"

class AggroSystem :
	public virtual IUpdateSystem,
	public virtual IRenderSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
private:

};