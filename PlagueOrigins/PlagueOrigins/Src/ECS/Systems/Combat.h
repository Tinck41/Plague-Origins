#pragma once

#include "IEcsUpdateSystem.h"

#include "Src/ECS/Components.h"

class Combat :
	public IEcsUpdateSystem
{
	virtual void update(entt::registry& reg, const float& dt) override;
};