#include "stdafx.h"
#include "VictoryScreen.h"

VictoryScreen::VictoryScreen()
{
	gui.loadWidgetsFromFile("./Assets/UI/GameOver.txt");
	gui.get<tgui::Panel>("gameOverPanel")->setVisible(true);
	gui.get<tgui::Label>("lossLabel")->setVisible(false);
	gui.get<tgui::Label>("winLabel")->setVisible(true);

	gui.get<tgui::Button>("retryButton")->onClick(&VictoryScreen::setGameScreen, this);
	gui.get<tgui::Button>("exit2Button")->onClick(&VictoryScreen::setExitScreen, this);
}

VictoryScreen::~VictoryScreen()
{
}

void VictoryScreen::update(const float& dt)
{
}

ScreenType VictoryScreen::render(sf::RenderWindow& window)
{
	gui.setTarget(window);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		gui.handleEvent(event);
	}

	gui.draw();

	if (newGame)
	{
		return ScreenType::GAME;
	}
	if (quit)
	{
		return ScreenType::EXIT;
	}

	return ScreenType::WIN;
}


void VictoryScreen::setGameScreen()
{
	std::cout << "set game state" << "\n";
	newGame = true;
}

void VictoryScreen::setExitScreen()
{
	std::cout << "set exit state" << "\n";
	quit = true;
}