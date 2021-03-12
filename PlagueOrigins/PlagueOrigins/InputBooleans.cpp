#pragma once

#include "stdafx.h"

#include "InputBooleans.h"

InputBooleans::InputBooleans()
{
	this->isWPressed = false;
	this->isAPressed = false;
	this->isSPressed = false;
	this->isDPressed = false;
	this->isQPressed = false;
	this->isEPressed = false;
	this->isEscapePressed = false;
	this->isSpacePressed = false;
	this->isM1Pressed = false;
	this->isM2Pressed = false;
}


/*
	CHECK FUNCTIONS
	check - check if input key is down and make its flag true
	reset - check if input key is up and make its flag false
*/
void InputBooleans::checkMovementInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->isWPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->isAPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->isSPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->isDPressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->isWPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->isAPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->isSPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->isDPressed = false;
	}
}

void InputBooleans::checkDashInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		this->isSpacePressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		this->isSpacePressed = false;
	}
}

void InputBooleans::checkAttackInput()
{
	//check
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->isM1Pressed = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		this->isM2Pressed = true;
	}
	//reset
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->isM1Pressed = false;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		this->isM2Pressed = false;
	}
}

void InputBooleans::checkUtilityInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		this->isQPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		this->isEPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->isEscapePressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		this->isQPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		this->isEPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->isEscapePressed = false;
	}
}

void InputBooleans::update()
{
	this->checkMovementInput();
	this->checkDashInput();
	this->checkAttackInput();
	this->checkUtilityInput();
}

