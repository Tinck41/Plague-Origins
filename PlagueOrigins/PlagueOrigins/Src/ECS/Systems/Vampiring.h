#pragma once

#include "IEcsUpdateSystem.h"
#include "Src/ECS/Components.h"

class Vampiring :
	public IEcsUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;
};