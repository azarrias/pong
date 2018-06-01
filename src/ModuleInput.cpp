/*
 * ModuleInput.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"
#include "ModuleInput.h"
#include <SDL2/SDL.h>

ModuleInput::ModuleInput()
{

}

ModuleInput::~ModuleInput()
{

}

bool ModuleInput::CleanUp()
{
	return true;
}

bool ModuleInput::Init()
{
	return true;
}

bool ModuleInput::Update()
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
					game->mEntities->mPlayerOnePaddle->m_velocity.y -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					game->mEntities->mPlayerOnePaddle->m_velocity.y += PADDLE_VELOCITY_DELTA;
					break;
			}
		}
		else if(e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_w:
					game->mEntities->mPlayerOnePaddle->m_velocity.y += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					game->mEntities->mPlayerOnePaddle->m_velocity.y -= PADDLE_VELOCITY_DELTA;
					break;
			}
		}
	}

	return true;
}