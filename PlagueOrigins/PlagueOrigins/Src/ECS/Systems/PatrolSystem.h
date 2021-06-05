#pragma once
#include "IUpdateSystem.h"
#include "IRenderSystem.h"
#include "Src/ECS/Components.h"

class PatrolSystem : 
	public IUpdateSystem,
	public IRenderSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;

private:
	void dirToNext(Movement& movement, Patrol& patrol, Transform& transform);
	void nextWaypoint(Patrol& patrol, Transform& transform);
};