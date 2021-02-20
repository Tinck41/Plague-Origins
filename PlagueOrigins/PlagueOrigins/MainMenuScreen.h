#pragma once

#include "Screen.h"

class MainMenuScreen :
    public Screen
{
public:
    MainMenuScreen();
    ~MainMenuScreen();
    void update(const float& dt);
    void render(sf::RenderWindow&);
};

