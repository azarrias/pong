/*
 * Main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: adolfo
 */

#include "GameObject.h"
#include "Globals.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>

// The window we'll be rendering to
SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

// Game objects
GameObject *gPlayerOnePaddle;
GameObject *gPlayerTwoPaddle;
GameObject *gBall;

void Close();
bool Init();
void Render();
bool Update();

int main(int argc, char* args[])
{
	if(!Init())
	{
		std::cout << "Failed to initialize!\n";
		return -1;
	}

	bool run = true;

	while(run)
	{
		run = Update();
		Render();
	}

	Close();

	return 0;
}

void Close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

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

	gPlayerOnePaddle = new GameObject(PADDLE_BORDER_OFFSET, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	gPlayerTwoPaddle = new GameObject(SCREEN_WIDTH - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	gBall = new GameObject(SCREEN_WIDTH / 2 - BALL_WIDTH / 2, SCREEN_HEIGHT / 2 - BALL_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT);

	return true;
}

void Render()
{
	// Set background render color to black and clear window
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);

	// Set render color to white and render all objects
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(gRenderer, gPlayerOnePaddle->GetRect());
	SDL_RenderFillRect(gRenderer, gPlayerTwoPaddle->GetRect());
	SDL_RenderFillRect(gRenderer, gBall->GetRect());

	SDL_RenderPresent(gRenderer);
}

bool Update()
{
	SDL_Event e;

	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
		{
			return false;
		}

		if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					return false;
					break;
				case SDLK_w:
					gPlayerOnePaddle->m_velocity.y -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					gPlayerOnePaddle->m_velocity.y += PADDLE_VELOCITY_DELTA;
					break;
			}
		}
		else if(e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_w:
					gPlayerOnePaddle->m_velocity.y += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					gPlayerOnePaddle->m_velocity.y -= PADDLE_VELOCITY_DELTA;
					break;
			}
		}
	}

	gPlayerOnePaddle->UpdatePos();

	return true;
}
