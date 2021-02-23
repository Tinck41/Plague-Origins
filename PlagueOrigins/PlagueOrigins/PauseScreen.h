#pragma once
#include "Screen.h"
#include "Button.h"

extern Config CONFIG;

class PauseScreen :
    public Screen
{
private:
    Button continueButton;
    Button mainMenuButton;
    Button exitButton;
public:
    static const ScreenType screenType = ScreenType::PAUSE;

    PauseScreen();
    ~PauseScreen();

    void update(const float&);
    ScreenType render(sf::RenderWindow&);
};

