#pragma once

#include "dragonBones/SFMLFactory.h"

class AnimationFactory
{
public:
	static AnimationFactory& get()
	{
		static AnimationFactory instance;
		return instance;
	}

	AnimationFactory(const AnimationFactory& root) = delete;
	~AnimationFactory();

	static void update(const float& dt) { get().updateInternal(dt); }
private:
	dragonBones::SFMLFactory factory;

    sf::Texture heroAnim;
	sf::Texture dogAnim;
	sf::Texture bishopAnim;

	AnimationFactory();

	void updateInternal(const float& dt);
};