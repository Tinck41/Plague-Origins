#include "stdafx.h"
#include "ActorSoundSystem.h"

ActorSoundSystem::ActorSoundSystem()
{
	playerAttackBuffer.loadFromFile("./Assets/SFX/PlayerAttack.wav");
	playerFootStepBuffer.loadFromFile("./Assets/SFX/PlayerFootStep.wav");
	playerGetHitBuffer.loadFromFile("./Assets/SFX/GetHit.wav");

	dogGetHitBuffer.loadFromFile("./Assets/SFX/GetHit.wav");
}

void ActorSoundSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<ActorAudioSource, Tag>();
	for (auto entity : view)
	{
		ActorAudioSource& audioSource = reg.get<ActorAudioSource>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero")
		{
			setPlayerSounds(audioSource);
		}
		else if (tag.name == "Dog")
		{
			setDogSounds(audioSource);
		}
	}
}


void ActorSoundSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<ActorAudioSource, Tag, Transform>();
	for (auto entity : view)
	{
		ActorAudioSource& audioSource = reg.get<ActorAudioSource>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);

		if (tag.name == "Hero")
		{
			sf::Listener::setPosition(sf::Vector3f(transform.position.x, 0.f, transform.position.y));
			playPlayerSounds(audioSource);
		}
		else if (tag.name == "Dog")
		{
			playDogSounds(audioSource);
		}
	}
}

void ActorSoundSystem::playPlayerSounds(ActorAudioSource& audioSource)
{
	if (audioSource.playAttackSound)
	{
		sf::Sound& sound = audioSource.attackSound;
		sound.play();
		sound.setVolume(50.f);
		audioSource.playAttackSound = false;
	}

	if (audioSource.playFootStepSound)
	{
		sf::Sound& sound = audioSource.footStepSound;
		sound.setLoop(true);
		sound.setPitch(0.6f);
		sound.play();
		sound.setVolume(25.f);
		audioSource.playFootStepSound = false;
	}
	else if (!audioSource.loopFootStepSound)
	{
		audioSource.footStepSound.setLoop(false);
	}

	if (audioSource.playGetHitSound)
	{
		sf::Sound& sound = audioSource.getHitSound;
		sound.play();
		sound.setVolume(50.f);
		audioSource.playGetHitSound = false;
	}
}

void ActorSoundSystem::playDogSounds(ActorAudioSource& audioSource)
{
	if (audioSource.playAttackSound)
	{
		sf::Sound& sound = audioSource.attackSound;

		sound.play();
		sound.setVolume(50.f);
		audioSource.playAttackSound = false;
	}

	if (audioSource.playFootStepSound)
	{
		sf::Sound& sound = audioSource.footStepSound;
		sound.setLoop(true);
		sound.setPitch(0.6f);
		sound.play();
		sound.setVolume(25.f);
		audioSource.playFootStepSound = false;
	}
	else if (!audioSource.loopFootStepSound)
	{
		audioSource.footStepSound.setLoop(false);
	}

	if (audioSource.playGetHitSound)
	{
		sf::Sound& sound = audioSource.getHitSound;
		sound.play();
		sound.setVolume(50.f);
		audioSource.playGetHitSound = false;
	}
}

void ActorSoundSystem::setPlayerSounds(ActorAudioSource& audioSource)
{
	audioSource.attackSound.setBuffer(playerAttackBuffer);
	audioSource.footStepSound.setBuffer(playerFootStepBuffer);
	audioSource.getHitSound.setBuffer(playerGetHitBuffer);

	audioSource.attackSound.setRelativeToListener(true);
	audioSource.footStepSound.setRelativeToListener(true);
	audioSource.getHitSound.setRelativeToListener(true);

}

void ActorSoundSystem::setDogSounds(ActorAudioSource& audioSource)
{
	audioSource.attackSound.setBuffer(dogAttackBuffer);
	audioSource.footStepSound.setBuffer(dogFootStepBuffer);
	audioSource.getHitSound.setBuffer(dogGetHitBuffer);
}

