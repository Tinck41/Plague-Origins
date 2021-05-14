#pragma once

#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class PlayerSoundSystem :
	public IUpdateSystem
{
public:
	PlayerSoundSystem();
	~PlayerSoundSystem() = default;

	virtual void update(entt::registry& reg, const float& dt) override;
private:
	sf::SoundBuffer playerAttackBuffer;
	sf::SoundBuffer playerFootStepBuffer;
	sf::SoundBuffer playerDashBuffer;

	sf::Sound playerAttackSound;
	sf::Sound playerFootStepSound;
	sf::Sound playerDashSound;
};