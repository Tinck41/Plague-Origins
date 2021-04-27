#pragma once

struct Health
{
	Health(float health)
	{
		this->maxHealth = health;
		this->curhealth = health;
	}
	
	float maxHealth;
	float curhealth;
};