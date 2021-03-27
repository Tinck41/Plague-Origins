#pragma once

#include "Screen.h"
#include "Button.h"

extern Config CONFIG;

class MainMenuScreen :
    public Screen
{
private:
    Button newGameButton;
    Button exitGameButton;
public:
    static const ScreenType screenType = ScreenType::MAIN_MENU;

    MainMenuScreen();

    void update(const float&);
    ScreenType render(sf::RenderWindow&);
};

