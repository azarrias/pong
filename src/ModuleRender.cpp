/*
 * ModuleRender.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include <iostream>
#include "ModuleEntityManager.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include <SDL2/SDL.h>

ModuleRender::ModuleRender()
{}

ModuleRender::~ModuleRender()
{}

bool ModuleRender::CleanUp()
{
	std::cout << "Destroying SDL renderer\n";
	if(mRenderer)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = nullptr;
	}

	return true;
}

bool ModuleRender::Init()
{
	// Create vsynced renderer for window
	mRenderer = SDL_CreateRenderer(game->mWindow->mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!mRenderer)
	{
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
		return false;
	}

	return true;
}

bool ModuleRender::Update()
{
	// Set background render color to black and clear window
	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(mRenderer);

	// Set render color to white and render all objects
	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(mRenderer, game->mEntities->mPlayerOnePaddle->GetRect());
	SDL_RenderFillRect(mRenderer, game->mEntities->mPlayerTwoPaddle->GetRect());
	SDL_RenderFillRect(mRenderer, game->mEntities->mBall->GetRect());

	SDL_RenderPresent(mRenderer);

	return true;
}
