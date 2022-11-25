#pragma once

struct Health
{
	//Health(float health)
	//{
	//	this->maxHealth = health;
	//	this->curhealth = health;
	//}
	Health(int VIT)
	{
		this->maxHealth = VIT * 20.f;
		this->curhealth = VIT * 20.f;

		baseHealth = maxHealth;

		std::cout << maxHealth << " maxHealth\n";
	}
	
	float baseHealth;
	float maxHealth;
	float curhealth;
};