#include "stdafx.h"

#include <windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int)
//int main()
{
	tgui::setBackend(std::make_shared<tgui::BackendSFML>());
	Game game;
	game.run();
	tgui::setBackend(nullptr);
	return 0;
}