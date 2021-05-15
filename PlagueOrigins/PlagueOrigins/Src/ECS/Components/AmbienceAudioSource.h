#pragma once

struct AmbienceAudioSource
{
	sf::Sound windSound;
	sf::Sound torchSound;

	bool playWindSound = true;
	bool loopWindSound = true;

	bool playTorchSound = true;
	bool loopTorchSound = true;
	sf::Vector3f torchSoundPosition;
};