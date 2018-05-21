/*
 * Main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: adolfo
 */

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// The window we'll be rendering to
SDL_Window *gWindow = nullptr;

// The surface contained by the window
SDL_Surface *gScreenSurface = nullptr;

void Close();
bool Init();
void Update();
void Render();

int main(int argc, char* args[])
{
	if(!Init())
	{
		std::cout << "Failed to initialize!\n";
		return -1;
	}

	bool quit = false;
	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		Update();
		Render();
	}

	Close();

	return 0;
}

void Close()
{
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	TTF_Quit();
	SDL_Quit();
}

bool Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		return false;
	}

	if(TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";
		return false;
	}

	gWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(!gWindow)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
		return false;
	}
	else
	{
		// Get window surface
		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}

	return true;
}

void Update()
{

}

void Render()
{

}
