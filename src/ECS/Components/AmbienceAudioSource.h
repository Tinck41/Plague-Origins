#pragma once

struct AmbienceAudioSource
{
	sf::Sound windSound;
	sf::Sound torchSound;
	sf::Sound bossFightSound;

	bool playWindSound = true;
	bool loopWindSound = true;

	bool playBossFightSound = false;
	bool loopBossFightSound = false;

	bool playTorchSound = true;
	bool loopTorchSound = true;
	sf::Vector3f torchSoundPosition;
};