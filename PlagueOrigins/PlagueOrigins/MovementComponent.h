#pragma once

class MovementComponent
{
private:
	sf::RectangleShape& shape;
	
	int initialSpeed;
	int currentSpeed;

public:

	//Constructor/destructor
	MovementComponent(sf::RectangleShape& shape, int speed);
	virtual ~MovementComponent();

	//Functions
	void move(const float& dt, sf::Vector2f dir);
};