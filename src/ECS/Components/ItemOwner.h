#pragma once

#include "entt.hpp"

struct ItemOwner
{
	ItemOwner(entt::entity owner)
	{
		this->owner = owner;
	}

	entt::entity owner;
};