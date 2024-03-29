#pragma once

#include "IUpdateSystem.h"

#include "ECS/Components.h"

class AmbientSoundSystem :
	public IUpdateSystem
{
public:
	AmbientSoundSystem();
	~AmbientSoundSystem() = default;

	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
private:
	sf::SoundBuffer windBuffer;
	sf::SoundBuffer torchBuffer;
	sf::SoundBuffer bossFightBuffer;
};