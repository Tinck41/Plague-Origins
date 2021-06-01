#include "stdafx.h"
#include "LossScreen.h"


LossScreen::LossScreen()
{
	gui.loadWidgetsFromFile("./Assets/UI/GameOver.txt");
	gui.get<tgui::Panel>("gameOverPanel")->setVisible(true);
	gui.get<tgui::Label>("lossLabel")->setVisible(true);
	gui.get<tgui::Label>("winLabel")->setVisible(false);

	gui.get<tgui::Button>("retryButton")->onClick(&LossScreen::setGameScreen, this);
	gui.get<tgui::Button>("exit2Button")->onClick(&LossScreen::setExitScreen, this);
}

LossScreen::~LossScreen()
{
}

void LossScreen::update(const float& dt)
{
}

ScreenType LossScreen::render(sf::RenderWindow& window)
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

void LossScreen::setGameScreen()
{
	std::cout << "set game state" << "\n";
	newGame = true;
}

void LossScreen::setExitScreen()
{
	std::cout << "set exit state" << "\n";
	quit = true;
}