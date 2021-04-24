#pragma once

class EntityState
{
private:
	std::vector<class T> components;
public:
	EntityState();
	~EntityState();

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args) // type : Class = Class type
	{
		//components.push_back(T);
		return EntityState;
	}
};