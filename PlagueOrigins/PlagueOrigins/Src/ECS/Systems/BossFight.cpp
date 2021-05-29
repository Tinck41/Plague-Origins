#include "stdafx.h"
#include "BossFight.h"

void BossFight::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<BossFightArena>();
	for (auto entity : view)
	{
		BossFightArena& bossFightArena = reg.get<BossFightArena>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		checkForWin(reg);

		if (bossFightArena.arenaClosed) return;

		b2Fixture* bossFightTrigger = rigidBody.body->GetFixtureList();
		while (bossFightTrigger->GetUserData().pointer != BOSS_FIGHT_TRIGGER)
		{
			bossFightTrigger = bossFightTrigger->GetNext();
		}

		for (b2ContactEdge* edge = bossFightTrigger->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->GetFixtureA() == bossFightTrigger 
					&& edge->contact->GetFixtureB()->GetUserData().pointer == PLAYER
				|| edge->contact->GetFixtureB()->GetUserData().pointer == PLAYER 
					&& edge->contact->GetFixtureA() == bossFightTrigger)
			{
				for (size_t i = 0; i < bossFightArena.doors.size(); i++)
				{
					RigidBody& doorRB = reg.get<RigidBody>(entt::entity(bossFightArena.doors[i]));

					doorRB.body->GetFixtureList()->SetSensor(false);
				}
				entt::entity playerEntity = (entt::entity)edge->contact->GetFixtureB()->GetBody()->GetUserData().pointer;
				Player& player = reg.get<Player>(playerEntity);
				entt::entity bossEntity = (entt::entity)player.bossBody->GetUserData().pointer;
				Boss& boss = reg.get<Boss>(bossEntity);
				boss.isBossFight = true;

				sf::Vector2f playerPos = reg.get<Transform>(playerEntity).position;
				sf::Vector2f bossPos = reg.get<Transform>(bossEntity).position;
				b2Vec2 vectorToPlayer;
				vectorToPlayer.x = playerPos.x - bossPos.x;
				vectorToPlayer.y = playerPos.y - bossPos.y;
				vectorToPlayer.Normalize();
				boss.normVector.x = vectorToPlayer.x;
				boss.normVector.y = vectorToPlayer.y;

				setBossFightMusic(reg, true);

				bossFightArena.arenaClosed = true;
			}
		}
	}
}

void BossFight::checkForWin(entt::registry& reg)
{
	auto view = reg.view<Boss>();
	for (auto entity : view)
	{
		Boss& boss = reg.get<Boss>(entity);

		if (!boss.isBossFight)
		{
			setBossFightMusic(reg, false);
		}
	}
}

void BossFight::setBossFightMusic(entt::registry& reg, bool playMusic)
{
	auto view = reg.view<AmbienceAudioSource>();
	for (auto entity : view)
	{
		AmbienceAudioSource& soundSource = reg.get<AmbienceAudioSource>(entity);

		soundSource.playBossFightSound = playMusic;
		soundSource.loopBossFightSound = playMusic;
	}
}
