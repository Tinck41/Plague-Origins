#pragma once

struct CurrentScreen
{
	CurrentScreen(uint8_t type)
	{
		this->type = type;
	}

	bool gameOver = false;
	bool restart = false;
	bool exit = false;
	uint8_t type;
};