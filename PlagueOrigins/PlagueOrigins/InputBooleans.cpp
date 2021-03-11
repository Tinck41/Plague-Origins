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

void InputBooleans::checkMovementInput()
{
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
}

void InputBooleans::checkDashInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		this->isSpacePressed = true;
	}
}

void InputBooleans::checkAttackInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->isM1Pressed = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		this->isM2Pressed = true;
	}
}

void InputBooleans::checkUtilityInput()
{
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
}

void InputBooleans::update()
{
	this->checkMovementInput();
	this->checkDashInput();
	this->checkAttackInput();
	this->checkUtilityInput();
}

