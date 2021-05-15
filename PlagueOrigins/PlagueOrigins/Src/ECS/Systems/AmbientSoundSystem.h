#pragma once

#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

class AmbientSoundSystem :
	public IUpdateSystem
{
public:
	AmbientSoundSystem();
	~AmbientSoundSystem() = default;

	virtual void update(entt::registry& reg, const float& dt) override;
private:
	sf::SoundBuffer windBuffer;
	sf::SoundBuffer torchBuffer;
};