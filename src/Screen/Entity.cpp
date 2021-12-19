#include "stdafx.h"

#include "Entity.h"

Entity::Entity(entt::entity handle, Screen* screen)
	: entityHandle(handle), screen(screen)
{
}
