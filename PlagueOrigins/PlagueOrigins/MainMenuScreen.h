#pragma once

#include "Screen.h"
#include "Button.h"
#include "stdafx.h"

extern Config CONFIG;

class MainMenuScreen :
    public Screen
{
private:
    Button newGameButton;
public:
    MainMenuScreen();
    ~MainMenuScreen();

    void update(const float&);
    ScreenType render(sf::RenderWindow&);
};

