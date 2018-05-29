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
	return true;
}

bool ModuleScene::Start()
{
    game->mEntities->mBall->m_velocity.x = Random::GetRandomInt(-2, 2);
    game->mEntities->mBall->m_velocity.y = Random::GetRandomInt(-2, 2);

    return true;
}
