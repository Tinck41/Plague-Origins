#include "stdafx.h"
#include "Vampiring.h"

void Vampiring::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Vampire, Health>();

	for (auto& entity : view)
	{
		Vampire& vampire = reg.get<Vampire>(entity);
		Health& health = reg.get<Health>(entity);

		if (health.curhealth < health.maxHealth)
		{
			health.curhealth += vampire.vampiredHealth;
			health.curhealth = health.curhealth > health.maxHealth ? health.maxHealth : health.curhealth;
		}

		vampire.vampiredHealth = 0;
	}
}
