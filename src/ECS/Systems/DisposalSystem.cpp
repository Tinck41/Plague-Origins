#include "stdafx.h"
#include "DisposalSystem.h"

void DisposalSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Dispose>();

	for (auto entity : view)
	{
		Dispose& dispose = reg.get<Dispose>(entity);

		if (dispose.toDispose)
		{
			b2Body* body = reg.get<RigidBody>(entity).body;
			body->GetWorld()->DestroyBody(body);
			reg.remove_all(entity);

			std::string widgetName = std::to_string(uint32_t(entity)) + "healthBar";
			auto healthBar = gui.get<tgui::ProgressBar>(widgetName);

			gui.remove(healthBar);
		}
	}
}
