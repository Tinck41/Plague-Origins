#include "stdafx.h"
#include "StatsSystem.h"

void StatsSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	
}

void StatsSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	
}

void StatsSystem::increaseChar(Stats& stats, int value, charName charName)
{
    switch (charName)
    {
    case charName::VIT:
        stats.VIT += value;
        break;
    case charName::END:
        stats.END += value;
        break;
    case charName::STR:
        stats.STR += value;
        break;
    case charName::AGI:
        stats.AGI += value;
        break;
    case charName::INTT:
        stats.INT += value;
        break;
    default:
        break;
    }
}

void StatsSystem::decreaseChar(Stats& stats, int value, charName charName)
{
    switch (charName)
    {
    case charName::VIT:
        stats.VIT -= value;
        break;
    case charName::END:
        stats.END -= value;
        break;
    case charName::STR:
        stats.STR -= value;
        break;
    case charName::AGI:
        stats.AGI -= value;
        break;
    case charName::INTT:
        stats.INT -= value;
        break;
    default:
        break;
    }
}
