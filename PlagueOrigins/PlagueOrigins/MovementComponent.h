#pragma once

class MovementComponent
{
private:
	b2Body* body;
	
	float speed;
public:
	//Constructor/destructor
	MovementComponent(b2Body* body, float speed);
	virtual ~MovementComponent();

	//Functions
	void move(const float& dt, sf::Vector2f dir);
};