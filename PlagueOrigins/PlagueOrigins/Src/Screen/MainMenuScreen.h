#pragma once

#include "Screen.h"

class MainMenuScreen :
    public Screen
{
private:
    bool newGame = false;
    bool quit = false;

    tgui::GuiSFML gui;

    sf::Sound mainTheme;
    sf::SoundBuffer mainThemeBuffer;

    void setGameScreen();
    void setExitScreen();
public:
    static const ScreenType screenType = ScreenType::MAIN_MENU;

    MainMenuScreen();

    void update(const float&);
    ScreenType render(sf::RenderWindow&);
};
