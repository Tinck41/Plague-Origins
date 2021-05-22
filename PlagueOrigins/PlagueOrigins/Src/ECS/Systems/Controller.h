#pragma once

#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class Controller : 
	public IUpdateSystem
{
private:
	sf::Clock clock;

	void setDirection(Movement& movement, PlayerInput& playerInput);
	void checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, Stamina& stamina, const float& dt);
	void checkAttack(PlayerInput& playerInput, Attack& attack, Stamina& stamina);
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
};