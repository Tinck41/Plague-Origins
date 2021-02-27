#pragma once

#include "stdafx.h"

class MovementComponent
{
private:
	sf::RectangleShape& shape;

	enum key
	{
		NONE, IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};

	int speed; 
	int sqrSpeed;
	int dx;
	int dy;
	bool roll;
	int state;
	int prevState;
	bool isStateChanged;

public:

	//Constructor/destructor
	MovementComponent(sf::RectangleShape& shape, int speed);
	//MovementComponent(sf::Texture& texture, int speed);
	virtual ~MovementComponent();

	//Accessors
	int getState();
	sf::Vector2f getPos();

	//Functions
	void move(const float& dt);
	void update(const float& dt);
	bool stateChanged();
};