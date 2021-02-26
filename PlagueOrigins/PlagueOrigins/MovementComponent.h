#pragma once

#include "stdafx.h"

class MovementComponent
{
private:
	sf::RectangleShape& shape;
	sf::Texture texture;

	enum key
	{
		IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};

	int speed; 
	int sqrSpeed;
	int dx;
	int dy;
	bool roll;
	int state;

public:

	//Constructor/destructor
	MovementComponent(sf::RectangleShape& shape, int speed);
	//MovementComponent(sf::Texture& texture, int speed);
	virtual ~MovementComponent();

	//Accessors
	sf::RectangleShape getShape();
	sf::Texture getTexture();
	int getState();

	//Functions
	void move(const float& dt);
	void update(const float& dt);
};