#pragma once

#include "stdafx.h"

class AnimationComponent
{
private:
	sf::Texture texture;
	bool done;
	int state;

public:
	//Constructor/Destructor
	AnimationComponent(sf::Texture texture);
	~AnimationComponent();

	//Accessors
	const bool& isDone() const;
	void getAnimation();
	void getAnimationState();

	//Functions
	void addAnimation(const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);

	const bool& play(const std::string key, const float& dt);

};