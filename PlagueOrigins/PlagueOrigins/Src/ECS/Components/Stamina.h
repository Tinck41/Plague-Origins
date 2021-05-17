#pragma once

struct Stamina
{
	Stamina(float maxStamina)
	{
		this->maxStamina = maxStamina;
		curStamina = maxStamina;
	}

	float maxStamina;
	float curStamina;
};