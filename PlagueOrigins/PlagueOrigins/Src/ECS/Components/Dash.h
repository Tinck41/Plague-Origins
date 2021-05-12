#pragma once

#include "SFML/Graphics.hpp"

struct Dash
{
    bool isDashing = false;

    sf::Vector2f direction;

    sf::Time curDuration;
    sf::Time curCooldownTime = sf::seconds(0);

    sf::Int32 duration = 240;

    float cooldownTime = 1.f;
    float speed = 2500.f;
};