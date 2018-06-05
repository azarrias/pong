/*
 * ModuleScene.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include <cmath>
#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"
#include "ModuleScene.h"
#include "Random.h"

#define PI 3.14159265

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

	float startPosX = 0.0f;
	float startPosY = 0.0f;

	// Start ball with angle between 15 and 45 degrees
	while(startPosX + startPosY < 0.1f)
	{
		startPosX = Random::GetRandom(0.0f, 1.0f);
		startPosY = Random::GetRandom((float)tan(15 * PI / 180.0) * startPosX, startPosX);
	}

	// Then randomize sign
	if(Random::GetRandom(0, 1))
	{
		startPosX = - startPosX;
	}
	if(Random::GetRandom(0, 1))
	{
		startPosY = - startPosY;
	}

	game->mEntities->mBall->mVelocity.Set(startPosX, startPosY);
	game->mEntities->mBall->mVelocity.Normalize();
	game->mEntities->mBall->mVelocity *= 10;

    return true;
}

