#include "stdafx.h"
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	mainThemeBuffer.loadFromFile("./Assets/SFX/MainMenuTheme.wav");
	mainTheme.setBuffer(mainThemeBuffer);
	mainTheme.setLoop(true);
	mainTheme.setVolume(10.f);
	mainTheme.play();

	gui.loadWidgetsFromFile("./Assets/UI/Main_menu.txt");
	gui.get<tgui::Button>("newGame")->onClick(&MainMenuScreen::setGameScreen, this);
	gui.get<tgui::Button>("quit")->onClick(&MainMenuScreen::setExitScreen, this);
}

void MainMenuScreen::update(const float &dt)
{

}

ScreenType MainMenuScreen::render(sf::RenderWindow& window)
{
	gui.setTarget(window);
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		gui.handleEvent(event);
	}
	
	tgui::FloatRect visibleArea(0, 0, config.uiWidth, config.uiHeight);
	gui.setAbsoluteView(visibleArea);

	gui.draw();

	if (newGame) 
	{
		mainTheme.stop();
		return ScreenType::GAME;
	}
	if (quit) 
	{
		return ScreenType::EXIT;
	}

	return ScreenType::MAIN_MENU;
}

void MainMenuScreen::setGameScreen()
{
	std::cout << "set game state" << "\n";
	newGame = true;
}

void MainMenuScreen::setExitScreen()
{
	std::cout << "set exit state" << "\n";
	quit = true;
}


