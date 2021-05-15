#pragma once

#include "IUpdateSystem.h"
#include "IOnCreateSystem.h"

#include "Src/ECS/Components.h"

class ActorSoundSystem :
	public IUpdateSystem,
	public IOnCreateSystem
{
public:
	ActorSoundSystem();
	~ActorSoundSystem() = default;

	virtual void onCreate(entt::registry& reg) override;

	virtual void update(entt::registry& reg, const float& dt) override;
private:
	// Player
	sf::SoundBuffer playerAttackBuffer;
	sf::SoundBuffer playerFootStepBuffer;
	sf::SoundBuffer playerDashBuffer;
	sf::SoundBuffer playerGetHitBuffer;

	// Npc dog
	sf::SoundBuffer dogAttackBuffer;
	sf::SoundBuffer dogFootStepBuffer;
	sf::SoundBuffer dogDeathBuffer;
	sf::SoundBuffer dogGetHitBuffer;

	void playPlayerSounds(ActorAudioSource& audioSource);
	void playDogSounds(ActorAudioSource& audioSource);

	void setPlayerSounds(ActorAudioSource& audioSource);
	void setDogSounds(ActorAudioSource& audioSource);
};