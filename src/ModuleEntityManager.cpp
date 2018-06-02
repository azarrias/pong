/*
 * ModuleEntityManager.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"

ModuleEntityManager::ModuleEntityManager()
{
	mPlayerOnePaddle = new Paddle(PADDLE_BORDER_OFFSET, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	mPlayerTwoPaddle = new Paddle(SCREEN_WIDTH - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT);
	mBall = new Ball(SCREEN_WIDTH / 2 - BALL_WIDTH / 2, SCREEN_HEIGHT / 2 - BALL_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT);

	mEntities.push_back(mPlayerOnePaddle);
	mEntities.push_back(mPlayerTwoPaddle);
	mEntities.push_back(mBall);
}

ModuleEntityManager::~ModuleEntityManager()
{
	if(mPlayerOnePaddle)
	{
		delete mPlayerOnePaddle;
		mPlayerOnePaddle = nullptr;
	}

	if(mPlayerTwoPaddle)
	{
		delete mPlayerTwoPaddle;
		mPlayerTwoPaddle = nullptr;
	}

	if(mBall)
	{
		delete mBall;
		mBall = nullptr;
	}
}

bool ModuleEntityManager::CleanUp()
{
	return true;
}

bool ModuleEntityManager::Init()
{
	return true;
}

bool ModuleEntityManager::Update()
{
	for (std::vector<GameObject*>::iterator it = mEntities.begin(); it != mEntities.end(); ++it)
	{
		(*it)->UpdatePos();
	}

	return true;
}
