#pragma once
#include <SDL.h>
#include <iostream>

class Casino
{
public:
	Casino();
	~Casino();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	inline bool running() { return isRunning; };

private:
	bool isRunning = false;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int count = 0;

};
