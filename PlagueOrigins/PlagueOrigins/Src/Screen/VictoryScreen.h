#pragma once

#include "Screen.h"
#include "Src/Screen/Entity.h"
#include "Src/ECS/Components.h"

class VictoryScreen :
	public Screen
{
private:
	bool newGame = false;
	bool quit = false;

	tgui::GuiSFML gui;

	void setGameScreen();
	void setExitScreen();
public:
	static const ScreenType screenType = ScreenType::WIN;

	VictoryScreen();
	~VictoryScreen();

	void update(const float& dt) override;
	ScreenType render(sf::RenderWindow&) override;
};
