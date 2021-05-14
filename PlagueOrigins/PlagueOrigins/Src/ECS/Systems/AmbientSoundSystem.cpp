#include "stdafx.h"
#include "AmbientSoundSystem.h"

AmbientSoundSystem::AmbientSoundSystem()
{
	windBuffer.loadFromFile("./Assets/SFX/WindAmbience.wav");

	windSound.setBuffer(windBuffer);
}

void AmbientSoundSystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<AmbienceAudioSource>();
	for (auto entity : view)
	{
		AmbienceAudioSource& audioSource = reg.get<AmbienceAudioSource>(entity);

		if (audioSource.playWindSound)
		{
			windSound.setLoop(true);
			windSound.play();
			windSound.setVolume(50.f);
			audioSource.playWindSound = false;
		}
		else if (!audioSource.loopWindSound)
		{
			windSound.setLoop(false);
		}
	}
}
