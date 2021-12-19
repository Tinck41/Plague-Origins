#include "stdafx.h"
#include "StatsSystem.h"

float StatsSystem::newHp(Stats& stats, int value)
{
    return (stats.VIT + value) * 20.f;
}

float StatsSystem::newStamina(Stats& stats, int value)
{
    return (stats.END + value) * 10.f;
}

float StatsSystem::newDamage(Stats& stats, int value)
{
    return (stats.STR + value) * 5.0f;
}

float StatsSystem::newDashCD(Stats& stats, int value)
{
    return 10.f / (stats.AGI + value) + 1.f;
}

void StatsSystem::increaseChar(entt::registry& reg, entt::entity player, Stats& stats, Inventory& essence, charName charName)
{
    if (essence.essence >= stats.upgradeCost)
    {
        Health& health = reg.get<Health>(player);
        Stamina& stamina = reg.get<Stamina>(player);
        Attack& attack = reg.get<Attack>(player);
        Dash& dash = reg.get<Dash>(player);
        switch (charName)
        {
        case charName::VIT:
            health.maxHealth = newHp(stats,1);
            stats.VIT++;
            break;
        case charName::END:
            stamina.maxStamina = newStamina(stats,1);
            stats.END++;
            break;
        case charName::STR:
            attack.damage = newDamage(stats,1);
            stats.STR++;
            break;
        case charName::AGI:
            dash.cooldownTime = newDashCD(stats,1);
            stats.AGI++;
            break;
        case charName::INTT:
            stats.INT++;
            break;
        default:
            break;
        }
        essence.essence -= stats.upgradeCost;
        stats.upgradeCost = -950 + (stats.VIT + stats.END + stats.STR + stats.AGI) * 25;
    }
}

void StatsSystem::decreaseChar(entt::registry& reg, entt::entity player, Stats& stats, Inventory& essence, charName charName)
{
    Health& health = reg.get<Health>(player);
    Stamina& stamina = reg.get<Stamina>(player);
    Attack& attack = reg.get<Attack>(player);
    Dash& dash = reg.get<Dash>(player);
    switch (charName)
    {
    case charName::VIT:
        if (stats.VIT > 1) 
        {
            health.maxHealth = newHp(stats,-1);
            stats.VIT--;
        }
        break;
    case charName::END:
        if (stats.END > 1)
        {
            stamina.maxStamina = newStamina(stats, -1);
            stats.END--;
        }
        break;
    case charName::STR:
        if (stats.STR > 1)
        {
            attack.damage = newDamage(stats, -1);
            stats.STR--;
        }
        break;
    case charName::AGI:
        if (stats.AGI > 1)
        {
            dash.cooldownTime = newDashCD(stats, -1);
            stats.AGI--;
        }
        break;
    case charName::INTT:
        if (stats.INT > 1)
            stats.INT--;
        break;
    default:
        break;
    }
    essence.essence += stats.upgradeCost;
    stats.upgradeCost = -950 + (stats.VIT + stats.END + stats.STR + stats.AGI) * 25;
}
