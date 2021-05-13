#pragma once
#include "IUpdateSystem.h"
#include "Src/ECS/Components.h"

class InventorySystem:
	public IUpdateSystem
{
public:
	InventorySystem();
	virtual void update(entt::registry& reg, const float& dt) override;
};

