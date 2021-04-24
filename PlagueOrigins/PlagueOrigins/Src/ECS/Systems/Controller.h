#pragma once

#include "IEcsUpdateSystem.h"

#include "Src/ECS/Components/Movement.h"
#include "Src/ECS/Components/Rigidbody.h"
#include "Src/ECS/Components/PlayerInput.h"
#include "Src/ECS/Components/Dash.h"

class Controller : 
	public IEcsUpdateSystem
{
private:
	sf::Clock clock;

	void setDirection(Movement& movement, PlayerInput& playerInput);
	void applyVelocity(Movement& movement, RigidBody& rigidBody, const float& dt);
	void applyVelocity(Dash& dash, RigidBody& rigidBody, const float& dt);
	void checkDash(PlayerInput& playerInput, Movement& movement, Dash& dash, const float& dt);
public:
	virtual void update(entt::registry& reg, const float& dt) override;
};