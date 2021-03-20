#include "stdafx.h"

#include "DirectionFinder.h"



void DirectionFinder::getMovementInput()
{
	if (InputBooleans::isWPressed)
	{
		this->direction.y = -1.f;
	}
	else if (InputBooleans::isSPressed)
	{
		this->direction.y = 1.f;
	}
	if (InputBooleans::isAPressed)
	{
		this->direction.x = -1.f;
	}
	else if (InputBooleans::isDPressed)
	{
		this->direction.x = 1.f;
	}
}

void DirectionFinder::update()
{
	this->direction.x = 0.f;
	this->direction.y = 0.f;

	this->getMovementInput();
}
