#pragma once

class InputHandler
{
private:
	sf::Vector2f direction;

	void getMovementInput();
	void getDashInput();
	void getAttackInput();
	void getSpellInput();
public:
	sf::Vector2f getDirection() { return this->direction; }

	void update();
};

