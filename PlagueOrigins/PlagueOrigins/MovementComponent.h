#pragma once

class MovementComponent
{
private:
	sf::RectangleShape& shape;

	enum key
	{
		NONE, IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};
	
	int initialSpeed;
	int speed;
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
	void move(const float& dt, sf::Vector2f dir);
	void update(const float& dt);
	bool stateChanged();
};