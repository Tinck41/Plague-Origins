#pragma once

#include "Screen.h"
#include "Src/Screen/Entity.h"
#include "Src/ECS/Components.h"

class LossScreen :
	public Screen
{
private:
	bool newGame = false;
	bool quit = false;

	tgui::GuiSFML gui;

	void setGameScreen();
	void setExitScreen();
public:
	static const ScreenType screenType = ScreenType::LOSS;

	LossScreen();
	~LossScreen();

	void update(const float& dt) override;
	ScreenType render(sf::RenderWindow&) override;
};