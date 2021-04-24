#pragma once

#include "SFML/Graphics.hpp"

struct Dash
{
    bool isDashing = false;

    sf::Vector2f direction;
    sf::Time curDuration;
    sf::Time curCooldownTime = sf::seconds(0);

    float duration = 30.f;
    float speed = 10000.f;
    float cooldownTime = 1.f;
};