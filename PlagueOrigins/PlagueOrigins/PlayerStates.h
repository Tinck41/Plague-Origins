#pragma once

enum globalState
{
	IDLE,
	MOVE,
	DASH,
	ATTACK
};

enum localState
{
	idleUp, idleRight, idleDown, idleLeft,
	moveUp, moveRight, moveDown, moveLeft,
	dashUp, dashRight, dashDown, dashLeft,
	attackFirst, attackSecond
};