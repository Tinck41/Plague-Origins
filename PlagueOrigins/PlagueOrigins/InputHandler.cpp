#include "stdafx.h"

#include "InputHandler.h"



void InputHandler::getMovementInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->direction.y = -1;
		this->globalState = globalState::MOVE;
		this->localState = localState::moveUp;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->direction.y = 1;
		this->globalState = globalState::MOVE;
		this->localState = localState::moveDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->direction.x = -1;
		this->globalState = globalState::MOVE;
		this->localState = localState::moveLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->direction.x = 1;
		this->globalState = globalState::MOVE;
		this->localState = localState::moveRight;
	}
}

void InputHandler::update()
{
	this->direction.x = 0;
	this->direction.y = 0;

	this->globalState = 0;
	this->localState = 1;

	this->getMovementInput();
}
