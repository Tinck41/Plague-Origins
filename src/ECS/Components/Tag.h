#pragma once

#include <string>

struct Tag
{
	Tag(std::string name)
	{
		this->name = name;
	}
	
	std::string name;
};