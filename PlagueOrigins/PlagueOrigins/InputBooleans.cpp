#pragma once
#include "stdafx.h"

#include "InputBooleans.h"

//initializing static variables to prevent error
bool InputBooleans::isWPressed = false;
bool InputBooleans::isAPressed = false;
bool InputBooleans::isSPressed = false;
bool InputBooleans::isDPressed = false;
bool InputBooleans::isFPressed = false;
bool InputBooleans::isQPressed = false;
bool InputBooleans::isEPressed = false;
bool InputBooleans::isEscapePressed = false;
bool InputBooleans::isSpacePressed = false;
bool InputBooleans::isM1Pressed = false;
bool InputBooleans::isM2Pressed = false;

bool InputBooleans::handled = true;

/*
	CHECK FUNCTIONS
	check - check if input key is down and make its flag true
	reset - check if input key is up and make its flag false
*/
void InputBooleans::checkMovementInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !isWPressed)
	{
		isWPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !isAPressed)
	{
		isAPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !isSPressed)
	{
		isSPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !isDPressed)
	{
		isDPressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && isWPressed)
	{
		isWPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && isAPressed)
	{
		isAPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && isSPressed)
	{
		isSPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && isDPressed)
	{
		isDPressed = false;
	}
}

void InputBooleans::checkDashInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isSpacePressed)
	{
		isSpacePressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&isSpacePressed)
	{
		isSpacePressed = false;
	}
}

void InputBooleans::checkAttackInput()
{
	//check
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isM1Pressed)
	{
		isM1Pressed = true;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isM1Pressed || !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	//if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isM1Pressed)
	{
		isM1Pressed = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && !isM2Pressed)
	{
		isM2Pressed = true;
	}
	//reset
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && isM2Pressed)
	{
		isM2Pressed = false;
	}
}

void InputBooleans::checkInteractionInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && !isFPressed)
	{
		isFPressed = true;
	}
	//reset
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && isFPressed ||!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		isFPressed = false;
	}
}

void InputBooleans::checkUtilityInput()
{
	//check
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		isQPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		isEPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		isEscapePressed = true;
	}
	//reset
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		isQPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		isEPressed = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		isEscapePressed = false;
	}
}

void InputBooleans::update()
{
	
	checkMovementInput();
	//checkDashInput();
	checkInteractionInput();
	checkAttackInput();
	checkUtilityInput();
	
}

