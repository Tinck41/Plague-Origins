#pragma once
#include "IUpdateSystem.h"
#include "IRenderSystem.h"
#include "Src/ECS/Components.h"

class PatrolSystem : 
	public IUpdateSystem,
	public IRenderSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
	PatrolSystem()
	{
		marker.setRadius(5.f);
		marker.setFillColor(sf::Color::Blue);
	};
private:
	
	sf::CircleShape marker;
	void dirToNext(Movement& movement, Patrol& patrol, Transform& transform);
	void nextWaypoint(Patrol& patrol, Transform& transform);
};