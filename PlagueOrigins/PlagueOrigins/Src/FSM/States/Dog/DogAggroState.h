#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class DogAggroState :
	virtual public State
{
private:
	Entity& owner;
	sf::Vector2f target;
public:
	DogAggroState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;

};

