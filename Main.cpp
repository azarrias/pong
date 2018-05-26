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
const int PADDLE_BORDER_OFFSET = 20;
const int PADDLE_HEIGHT = 100;
const int PADDLE_WIDTH = 20;
const int BALL_HEIGHT = 20;
const int BALL_WIDTH = 20;

// The window we'll be rendering to
SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

// Game objects
SDL_Rect PlayerOnePaddle;
SDL_Rect PlayerTwoPaddle;
SDL_Rect Ball;

void Close();
bool Init();
void Render();
void SetRect(SDL_Rect &rect, int xPos, int yPos, int width, int height);
void Update();

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

	// Create vsynced renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!gRenderer)
	{
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
		return false;
	}

	SetRect(PlayerOnePaddle, PADDLE_BORDER_OFFSET, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	SetRect(PlayerTwoPaddle, SCREEN_WIDTH - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	SetRect(Ball, SCREEN_WIDTH / 2 - BALL_WIDTH / 2, SCREEN_HEIGHT / 2 - BALL_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT);

	return true;
}

void Render()
{
	// Set background render color to black and clear window
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);

	// Set render color to white and render all objects
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(gRenderer, &PlayerOnePaddle);
	SDL_RenderFillRect(gRenderer, &PlayerTwoPaddle);
	SDL_RenderFillRect(gRenderer, &Ball);

	SDL_RenderPresent(gRenderer);
}

void SetRect(SDL_Rect &rect, int xPos, int yPos, int width, int height)
{
	rect.h = height;
	rect.w = width;
	rect.x = xPos;
	rect.y = yPos;
}

void Update()
{

}
