#include "stdafx.h"

#include "InputHandler.h"



void InputHandler::getMovementInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->direction.y = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->direction.x = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->direction.x = 1;
	}
}

void InputHandler::update()
{
	this->direction.x = 0;
	this->direction.y = 0;

	this->getMovementInput();
}
