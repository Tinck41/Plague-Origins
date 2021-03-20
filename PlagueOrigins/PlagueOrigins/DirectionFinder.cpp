#include "stdafx.h"

#include "DirectionFinder.h"



void DirectionFinder::getMovementInput()
{
	if (InputBooleans::isWPressed)
	{
		this->direction.y = -1;
	}
	else if (InputBooleans::isSPressed)
	{
		this->direction.y = 1;
	}
	if (InputBooleans::isAPressed)
	{
		this->direction.x = -1;
	}
	else if (InputBooleans::isDPressed)
	{
		this->direction.x = 1;
	}
}

void DirectionFinder::update()
{
	this->direction.x = 0;
	this->direction.y = 0;

	this->localState = 1;

	this->getMovementInput();
}
