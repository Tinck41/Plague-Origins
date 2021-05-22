#pragma once

#include "SFML/Graphics.hpp"

struct Dash
{
    Dash(int AGI)
    {
        cooldownTime = 10.f / AGI + 1.f;
    }

    bool isDashing = false;

    sf::Vector2f direction;

    sf::Time curDuration;
    sf::Time curCooldownTime = sf::seconds(0);

    sf::Int32 duration = 240;

    float cooldownTime;
    float speed = 2500.f;
};