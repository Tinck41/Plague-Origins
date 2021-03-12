#pragma once
/*
	static class designed for handle input in one place
*/


static class InputBooleans
{
public:
	static bool isWPressed;
	static bool isAPressed;
	static bool isSPressed;
	static bool isDPressed;
	static bool isQPressed;
	static bool isEPressed;
	static bool isEscapePressed;
	static bool isSpacePressed;
	static bool isM1Pressed;
	static bool isM2Pressed;

	InputBooleans();

	void checkMovementInput();
	void checkDashInput();
	void checkAttackInput();
	void checkUtilityInput();

	bool isMovementInput() { return (isWPressed || isAPressed || isSPressed || isDPressed); }
	bool isDashInput() { return isSpacePressed; }
	bool isAttackInput() { return (isM1Pressed || isM2Pressed); }

	void update();
};

bool InputBooleans::isWPressed = false;
bool InputBooleans::isAPressed = false;
bool InputBooleans::isSPressed = false;
bool InputBooleans::isDPressed = false;
bool InputBooleans::isQPressed = false;
bool InputBooleans::isEPressed = false;
bool InputBooleans::isEscapePressed = false;
bool InputBooleans::isSpacePressed = false;
bool InputBooleans::isM1Pressed = false;
bool InputBooleans::isM2Pressed = false;

