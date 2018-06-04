/*
 * ModuleGUI.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: adolfo
 */

#include <iostream>
#include "ModuleGUI.h"

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

bool ModuleGUI::Init()
{
	if(TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";
		return false;
	}

	mFont = TTF_OpenFont(FONT_PATH, FONT_SIZE);
	mPlayerOneScoreRect.x = SCREEN_WIDTH / 16;
	mPlayerTwoScoreRect.x = SCREEN_WIDTH - SCREEN_WIDTH / 8;
	return true;
}

bool ModuleGUI::Update()
{
	return true;
}


