#pragma once

#include "stdafx.h"

class MovementComponent
{
private:
	sf::RectangleShape& shape;

	int speed; 
	int dx;
	int dy;
	bool roll;

public:

	//Constructor/destructor
	MovementComponent(sf::RectangleShape& shape, int speed);
	virtual ~MovementComponent();

	//Accessors
	sf::RectangleShape getShape();

	//Functions
	void move(const float& dt);
	void update(const float& dt);
};