#include "stdafx.h"
#include "AmbientSoundSystem.h"

AmbientSoundSystem::AmbientSoundSystem()
{
	windBuffer.loadFromFile("./Assets/SFX/WindAmbience.wav");
	torchBuffer.loadFromFile("./Assets/SFX/FireTorchSoundMono.wav");
	bossFightBuffer.loadFromFile("./Assets/SFX/BossFightMusicV2.wav");
}

void AmbientSoundSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<AmbienceAudioSource>();
	for (auto entity : view)
	{
		AmbienceAudioSource& audioSource = reg.get<AmbienceAudioSource>(entity);

		if (audioSource.playWindSound)
		{
			sf::Sound& sound = audioSource.windSound;
			sound.setBuffer(windBuffer);
			sound.setLoop(true);
			sound.play();
			sound.setVolume(50.f);
			audioSource.playWindSound = false;
		}
		else if (!audioSource.loopWindSound)
		{
			audioSource.windSound.setLoop(false);
		}

		if (audioSource.playTorchSound)
		{
			sf::Sound& sound = audioSource.torchSound;
			sound.setBuffer(torchBuffer);
			sound.setPosition(audioSource.torchSoundPosition);
			sound.setMinDistance(500.f);
			sound.setAttenuation(5.f);
			sound.setLoop(true);
			sound.play();
			sound.setVolume(50.f);
			audioSource.playTorchSound = false;
		}
		else if (!audioSource.loopTorchSound)
		{
			audioSource.torchSound.setLoop(false);
		}

		if (audioSource.playBossFightSound)
		{
			sf::Sound& sound = audioSource.bossFightSound;
			sound.setBuffer(bossFightBuffer);
			sound.setLoop(true);
			sound.play();
			sound.setVolume(0.8f);
			audioSource.playBossFightSound = false;
			audioSource.loopBossFightSound = true;
		}
		else if (!audioSource.loopBossFightSound)
		{
			sf::Sound& sound = audioSource.bossFightSound;
			sound.stop();
			sound.setLoop(false);
		}
	}
}
