#pragma once

#include <iostream>

struct Description
{
	Description(std::string description)
	{
		this->description = description;
	}

	std::string description;
};