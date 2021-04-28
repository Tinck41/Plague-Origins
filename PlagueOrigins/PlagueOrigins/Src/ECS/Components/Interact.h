#pragma once

#include "box2d/box2d.h"

struct Interact
{
    Interact(b2Body* body, float radius, std::string text)
    {
        b2CircleShape circleShape;
        b2FixtureDef myFixtureDef;
        radius = radius / 30.f;;
        circleShape.m_radius = radius;
        myFixtureDef.shape = &circleShape;
        myFixtureDef.isSensor = true;
        body->CreateFixture(&myFixtureDef);

        interactionZone.setRadius(30.f);
        interactionZone.setFillColor(sf::Color::Red);

        this->text = text;
        this->radius = radius;
    }

    sf::CircleShape interactionZone;
    std::string text;
    bool canInteract = true;
    float radius;
};