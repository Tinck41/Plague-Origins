#include "stdafx.h"
#include "PlayerSoundSystem.h"

PlayerSoundSystem::PlayerSoundSystem()
{
	playerAttackBuffer.loadFromFile("./Assets/SFX/PlayerAttack.wav");
	playerFootStepBuffer.loadFromFile("./Assets/SFX/PlayerFootStep.wav");

	playerAttackSound.setBuffer(playerAttackBuffer);
	playerFootStepSound.setBuffer(playerFootStepBuffer);
}

void PlayerSoundSystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<PlayerAudioSource>();
	for (auto entity : view)
	{
		PlayerAudioSource& audioSource = reg.get<PlayerAudioSource>(entity);

		if (audioSource.playAttackSound)
		{
			playerAttackSound.play();
			playerAttackSound.setVolume(50.f);
			audioSource.playAttackSound = false;
		}

		if (audioSource.playFootStepSound)
		{
			playerFootStepSound.setLoop(true);
			playerFootStepSound.setPitch(0.6f);
			playerFootStepSound.play();
			playerFootStepSound.setVolume(25.f);
			audioSource.playFootStepSound = false;
		}
		else if (!audioSource.loopFootStepSound)
		{
			playerFootStepSound.setLoop(false);
		}

	}
}
