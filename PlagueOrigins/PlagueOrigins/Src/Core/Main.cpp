#include "stdafx.h"

#include "Game.h"

int main()
{
	tgui::setBackend(std::make_shared<tgui::BackendSFML>());
	Game game;
	game.run();
	tgui::setBackend(nullptr);
	return 0;
}