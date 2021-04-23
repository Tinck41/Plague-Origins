#pragma once

#include "entt.hpp"
#include "Screen.h"

class Entity
{
private:
	entt::entity entityHandle{ entt::null };
	Screen* screen = nullptr;
public:
	Entity() = default;
	Entity(entt::entity handle, Screen* screen);
	Entity(const Entity & other) = default;

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		T& component = screen->registry.emplace<T>(entityHandle, std::forward<Args>(args)...);
		return component;
	}

	template<typename T>
	T& GetComponent()
	{
		return screen->registry.get<T>(entityHandle);
	}

	template<typename T>
	bool HasComponent()
	{
		return screen->registry.all_of<T>(entityHandle);
	}

	template<typename T>
	void RemoveComponent()
	{
		screen->registry.remove<T>(entityHandle);
	}

	operator bool() const { return entityHandle != entt::null; }
	operator entt::entity() const { return entityHandle; }
	operator uint32_t() const { return (uint32_t)entityHandle; }

	bool operator==(const Entity& other) const
	{
		return entityHandle == other.entityHandle && screen == other.screen;
	}

	bool operator!=(const Entity& other) const
	{
		return !(*this == other);
	}
};

