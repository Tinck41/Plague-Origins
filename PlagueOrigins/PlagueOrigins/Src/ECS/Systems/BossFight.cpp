#include "stdafx.h"
#include "BossFight.h"

void BossFight::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<BossFightArena>();
	for (auto entity : view)
	{
		BossFightArena& bossFightArena = reg.get<BossFightArena>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		if (bossFightArena.arenaClosed) return;

		b2Fixture* bossFightTrigger = rigidBody.body->GetFixtureList();
		while (bossFightTrigger->GetUserData().pointer != BOSS_FIGHT_TRIGGER)
		{
			bossFightTrigger = bossFightTrigger->GetNext();
		}

		for (b2ContactEdge* edge = bossFightTrigger->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->GetFixtureA() == bossFightTrigger && edge->contact->GetFixtureB()->GetUserData().pointer == PLAYER)
			{
				for (size_t i = 0; i < bossFightArena.doors.size(); i++)
				{
					RigidBody& doorRB = reg.get<RigidBody>(entt::entity(bossFightArena.doors[i]));

					doorRB.body->GetFixtureList()->SetSensor(false);
				}

				bossFightArena.arenaClosed = true;
			}
		}
	}
}
