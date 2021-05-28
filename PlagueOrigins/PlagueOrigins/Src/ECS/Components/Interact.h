#pragma once

#include "box2d/box2d.h"

struct Interact
{
    Interact(b2Body* body, float radius, std::string text)
    {
        b2CircleShape circleShape;
        b2FixtureDef fixtureDef;
        radius = radius / 30.f;;
        fixtureDef.userData.pointer = INTERACTION_ZONE;
        circleShape.m_radius = radius;
        fixtureDef.shape = &circleShape;
        fixtureDef.isSensor = true;
        body->CreateFixture(&fixtureDef);

        interactionZone.setRadius(30.f);
        interactionZone.setFillColor(sf::Color::Red);

        this->text = text;
        this->radius = radius;
    }

    sf::CircleShape interactionZone;
    std::string text;

    bool canInteract = true;
    bool isInteracting = false;
    float radius;
};