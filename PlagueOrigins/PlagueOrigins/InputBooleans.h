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

	/*
		check input based on context (move, dash, attack, utility e.g. menus, misc things)
	*/
	void checkMovementInput();
	void checkDashInput();
	void checkAttackInput();
	void checkUtilityInput();

	/*
		isMovementInput() return true if player is moving
		isDashInput() return true if player is dashing
		isAttackInput() return true if player is attacking
		isIdle() return true if player is idle (not making any action mentioned above)
	*/
	bool isMovementInput() { return (isWPressed || isAPressed || isSPressed || isDPressed); }
	bool isDashInput() { return isSpacePressed; }
	bool isAttackInput() { return (isM1Pressed || isM2Pressed); }
	bool isIdle(){ return !(isMovementInput() || isDashInput() || isAttackInput()); }

	void update();
};



