#pragma once

#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class Controller : 
	public IUpdateSystem
{
private:
	sf::Clock clock;

	void setDirection(Movement& movement, PlayerInput& playerInput);
	void checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, const float& dt);
	void checkAttack(PlayerInput& playerInput, Attack& attack);
public:
	virtual void update(entt::registry& reg, const float& dt) override;
};