/*
 * ModuleGUI.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: adolfo
 */

#include <iostream>
#include "GameManager.h"
#include "ModuleGUI.h"
#include "ModuleRender.h"

ModuleGUI::ModuleGUI()
{}

ModuleGUI::~ModuleGUI()
{}

bool ModuleGUI::CleanUp()
{
	TTF_CloseFont(mFont);
	TTF_Quit();
	return true;
}

SDL_Texture* ModuleGUI::GetTexture(int n) const
{
	return mTextures[n];
}

bool ModuleGUI::Init()
{
	if(TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";
		return false;
	}

	mFont = TTF_OpenFont(FONT_PATH_NORMAL, FONT_SIZE);
	mTextures.reserve(10);
	SDL_Color color = { 255, 255, 255 };

	for(int i=0; i < 10; ++i)
	{
		char buffer[2];
		int ret;
		ret = sprintf(buffer, "%d", i);

		if(ret < 0)
		{
			std::cout << "Error: Could not initialize TTF textures!\n";
			return false;
		}

		SDL_Surface *surface = TTF_RenderText_Solid(mFont, buffer, color);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(game->mRenderer->mRenderer, surface);
		mTextures.push_back(texture);

		SDL_FreeSurface(surface);
	}

//	mPlayerOneScoreRect.x = SCREEN_WIDTH / 16;
//	mPlayerTwoScoreRect.x = SCREEN_WIDTH - SCREEN_WIDTH / 8;
	return true;
}

bool ModuleGUI::Update()
{
	return true;
}


