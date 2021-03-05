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
	idleUp, idleDown, idleLeft, idleRight,
	moveUp, moveDown, moveLeft, moveRight,
	attackFirst, attackSecond
};