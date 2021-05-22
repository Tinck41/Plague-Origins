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
		std::cout << maxHealth << " maxHealth\n";
	}
	
	float maxHealth;
	float curhealth;
};