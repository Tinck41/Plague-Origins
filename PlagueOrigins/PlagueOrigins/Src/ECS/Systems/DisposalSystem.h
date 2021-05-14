#pragma once
#include "IUpdateSystem.h"
#include "Src/ECS/Components.h"

class DisposalSystem :
	public virtual IUpdateSystem
{
	virtual void update(entt::registry& reg, const float& dt) override;
};