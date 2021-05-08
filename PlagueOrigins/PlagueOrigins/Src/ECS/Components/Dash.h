#pragma once

#include "SFML/Graphics.hpp"

struct Dash
{
    bool isDashing = false;

    sf::Vector2f direction;
    sf::Time curDuration;
    sf::Time curCooldownTime = sf::seconds(0);

    float duration = 400.f;
    float speed = 2500.f;
    float cooldownTime = 1.f;
};