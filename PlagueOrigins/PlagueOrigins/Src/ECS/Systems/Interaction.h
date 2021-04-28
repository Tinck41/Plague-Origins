#pragma once

#include "Src/ECS/Systems.h"
#include "Src/ECS/Components.h"

class Interaction :
	public IEcsRenderSystem,
	public IEcsUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window) override;
private:
	bool checkForPlayer(RigidBody& rigidBody);
};