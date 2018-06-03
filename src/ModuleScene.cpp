/*
 * ModuleScene.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"
#include "ModuleScene.h"
#include "Random.h"

ModuleScene::ModuleScene()
{}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::CleanUp()
{
	return true;
}

bool ModuleScene::Init()
{
	Start();
	return true;
}

bool ModuleScene::Update()
{
	if(game->mEntities->mBall->CheckCollision(*game->mEntities->mPlayerOnePaddle) ||
	   game->mEntities->mBall->CheckCollision(*game->mEntities->mPlayerTwoPaddle))
	{
		game->mEntities->mBall->mVelocity.mX = -game->mEntities->mBall->mVelocity.mX;
	}

	if(game->mEntities->mBall->GetRect()->x + game->mEntities->mBall->GetRect()->w < 0)
	{
		++mPlayerTwoScore;
		Start();
	}
	else if(game->mEntities->mBall->GetRect()->x > SCREEN_WIDTH)
	{
		++mPlayerOneScore;
		Start();
	}

	return true;
}

bool ModuleScene::Start()
{
	game->mEntities->mBall->SetPos(SCREEN_WIDTH / 2 - BALL_WIDTH / 2,
		SCREEN_HEIGHT / 2 - BALL_HEIGHT / 2);
	game->mEntities->mBall->mVelocity.Set(Random::GetRandom(-2, 2), Random::GetRandom(-2, 2));

    return true;
}

