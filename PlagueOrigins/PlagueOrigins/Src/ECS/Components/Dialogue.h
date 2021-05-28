#pragma once

struct Dialogue
{
    Dialogue(b2Body* body, float radius)
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

        this->radius = radius;
        state = 0;
        isInteracting = false;
    }

	/*
	* 0 - closed
	* 1 - main
	* 2 - upgrade
	* 3 - trade
	*/
    sf::CircleShape interactionZone;
    float radius;
    int state;
    bool isInteracting;
};