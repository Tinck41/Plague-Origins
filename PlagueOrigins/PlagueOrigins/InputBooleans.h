#pragma once

class InputBooleans
{
public:
	bool isWPressed = false;
	bool isAPressed = false;
	bool isSPressed = false;
	bool isDPressed = false;
	bool isQPressed = false;
	bool isEPressed = false;
	bool isEscapePressed = false;
	bool isSpacePressed = false;
	bool isM1Pressed = false;
	bool isM2Pressed = false;

	InputBooleans();

	void checkMovementInput();
	void checkDashInput();
	void checkAttackInput();
	void checkUtilityInput();
	bool isMovementInput() { return (isWPressed || isAPressed || isSPressed || isDPressed); }
	bool isDashInput() { return (isSpacePressed); }
	bool isAttackInput() { return (isM1Pressed || isM2Pressed); }

	void update();
};