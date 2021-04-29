#pragma once

#include "Src/ECS/Systems/IEcsUpdateSystem.h"

#include "Src/ECS/Components.h"

class Physics :
	public IEcsUpdateSystem
{
	virtual void update(entt::registry& reg, const float& dt) override;
};