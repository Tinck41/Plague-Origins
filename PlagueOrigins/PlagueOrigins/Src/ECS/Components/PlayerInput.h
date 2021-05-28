#pragma once

struct PlayerInput
{
	// Movement input
	bool wWasPressed = false;
	bool wPressed = false;
	bool wReleased = false;
	bool aWasPressed = false;
	bool aPressed = false;
	bool aReleased = false;
	bool sWasPressed = false;
	bool sPressed = false;
	bool sReleased = false;
	bool dWasPressed = false;
	bool dPressed = false;
	bool dReleased = false;

	// Dash input
	bool spaceWasPressed = false;
	bool spacePressed = false;
	bool spaceReleased = false;

	// Attack input
	bool LMBwasPressed = false;
	bool LMBpressed = false;
	bool LMBreleased = false;

	// Interaction input
	bool fWasPressed = false;
	bool fPressed = false;
	bool fReleased = false;

	bool rWasPressed = false;
	bool rPressed = false;
	bool rReleased = false;

	bool RMBwasPressed = false;
	bool RMBpressed = false;
	bool RMBreleased = false;
	
	bool escWasPressed = false;
	bool escPressed = false;
	bool escReleased = false;
};