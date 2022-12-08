#include "Casino.h"

Casino::~Casino() {};
Casino::Casino() {};

void Casino::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer is  successfully created" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;

	}
}

void Casino::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}

}

void Casino::update()
{
	count++;
	std::cout << count << std::endl;
}

void Casino::render()
{
	SDL_RenderClear(renderer);
	//this is where we would add stuff to render
	SDL_RenderPresent(renderer);

}

void Casino::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Casino is closed" << std::endl;
}
