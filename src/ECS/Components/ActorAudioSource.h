#pragma once

#include "SFML/Audio.hpp"

struct ActorAudioSource
{
	sf::Sound getHitSound;
	sf::Sound footStepSound;
	sf::Sound attackSound;
	sf::Sound dashSound;
	sf::Sound deathSound;
	sf::Sound aggroSound;

	bool playAttackSound = false;
	bool playGetHitSound = false;
	bool playDashSound = false;
	bool playDeathSound = false;
	bool playAggroSound = false;
	bool playFootStepSound = false;

	bool loopFootStepSound = false;
	bool loopAggroSound = false;
};