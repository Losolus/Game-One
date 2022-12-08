#include <iostream>
#include "Casino.h"

Casino* casino = nullptr;


int main(int argc, char *argv[])
{
	casino = new Casino();

	casino->init("Casinac onlina igrat nada syka blyat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);
	
	while (casino->running())
	{
		casino->handleEvents();
		casino->update();
		casino->render();
	}

	casino->clean();

	return 0;
}
