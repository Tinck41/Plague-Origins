#pragma once
#include "Screen.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class MainMenuScreen :
    public Screen
{
public:
    void update();
    void render(sf::RenderWindow&);
};

