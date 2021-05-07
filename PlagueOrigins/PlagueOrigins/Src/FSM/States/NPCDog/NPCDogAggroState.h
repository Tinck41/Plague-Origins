#pragma once

#include "NPCDog.h"
#include "NPCDogStates.h"

class NPCDogAggroState :
	virtual public State
{
private:
	Entity& owner;
	sf::Vector2f target;
public:
	NPCDogAggroState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;

};

