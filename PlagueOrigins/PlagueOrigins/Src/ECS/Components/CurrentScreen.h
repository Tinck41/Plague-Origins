#pragma once

struct CurrentScreen
{
	CurrentScreen(uint8_t type)
	{
		this->type = type;
	}

	uint8_t type;
};