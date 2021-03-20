#pragma once

class State
{
public:
	virtual void enter() {}
	virtual void execute() {}
	virtual void exit() {}
};

