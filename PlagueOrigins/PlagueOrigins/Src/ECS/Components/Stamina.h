#pragma once

struct Stamina
{
	Stamina(int END)
	{
		maxStamina = END * 10.f;
		curStamina = END * 10.f;
	}
	//Stamina(float maxStamina)
	//{
	//	this->maxStamina = maxStamina;
	//	curStamina = maxStamina;
	//}

	float maxStamina;
	float curStamina;
};