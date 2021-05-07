#pragma once

#include "Screen.h"
#include "Src/GUI/Button.h"

class MainMenuScreen :
    public Screen
{
private:
    Button newGameButton;
    Button exitGameButton;

    bool newGame = false;
    bool quit = false;

    tgui::GuiSFML gui;

    void setGameScreen();
    void setExitScreen();
public:
    static const ScreenType screenType = ScreenType::MAIN_MENU;

    MainMenuScreen();

    void update(const float&);
    ScreenType render(sf::RenderWindow&);
};
