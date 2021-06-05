#pragma once
#include "entt.hpp"

class IOnDestroySystem
{
public:
	virtual void onDestroy(entt::registry& reg, tgui::GuiSFML& gui) = 0;
};
