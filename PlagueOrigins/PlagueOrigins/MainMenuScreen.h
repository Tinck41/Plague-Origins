#pragma once
#include "Screen.h"
#include "SFML/Graphics/RenderWindow.hpp"

class MainMenuScreen :
    public Screen
{
public:
    MainMenuScreen();
    ~MainMenuScreen();
    void update(const float& dt);
    void render(sf::RenderWindow&);
};

