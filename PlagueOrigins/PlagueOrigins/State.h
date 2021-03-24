#pragma once

class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void enter() = 0;
	virtual void update(const float& dt) = 0;
	virtual void exit() = 0;
};

