#pragma once

#include "IEcsUpdateSystem.h"

#include "Src/ECS/Components.h"

class Controller : 
	public IEcsUpdateSystem
{
private:
	sf::Clock clock;

	void setDirection(Movement& movement, PlayerInput& playerInput);
	void applyVelocity(RigidBody& rigidBody, const float& speed, sf::Vector2f direction, const float& dt);
	void checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, const float& dt);
	void checkAttack(PlayerInput& playerInput, Attack& attack);
public:
	virtual void update(entt::registry& reg, const float& dt) override;
};