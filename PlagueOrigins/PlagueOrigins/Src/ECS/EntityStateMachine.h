#pragma once

#include "Src/Screen/Entity.h"
#include "Src/ECS/EntityState.h"

class EntityStateMachine
{
private:
	Entity* entity;
public:
	EntityStateMachine(Entity* owner);
	~EntityStateMachine();

};