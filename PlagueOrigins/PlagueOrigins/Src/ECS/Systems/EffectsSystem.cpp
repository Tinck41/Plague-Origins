#include "stdafx.h"
#include "EffectsSystem.h"

void EffectsSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto healthBoostersBuff = reg.view<ItemOwner, HealthBoost, JustEquiped>();
	for (auto entity : healthBoostersBuff)
	{
		ItemOwner& owner = reg.get<ItemOwner>(entity);
		Health& health = reg.get<Health>(owner.owner);
		HealthBoost& effect = reg.get<HealthBoost>(entity);

		health.maxHealth += health.baseHealth * effect.boost;
		health.curhealth = health.curhealth * effect.boost;

		std::cout << "Just eqiped" << "\n";

		reg.remove<JustEquiped>(entity);
	}

	auto healthBoostersDebuff = reg.view<ItemOwner, HealthBoost, JustUnequiped>();
	for (auto entity : healthBoostersDebuff)
	{
		ItemOwner& owner = reg.get<ItemOwner>(entity);
		Health& health = reg.get<Health>(owner.owner);
		HealthBoost& effect = reg.get<HealthBoost>(entity);

		health.maxHealth -= health.baseHealth * effect.boost;

		if (health.curhealth > health.maxHealth)
			health.curhealth = health.maxHealth;

		std::cout << "Just uneqiped" << "\n";

		reg.remove<JustUnequiped>(entity);
	}

}
