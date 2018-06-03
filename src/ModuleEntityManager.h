/*
 * ModuleEntityManager.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULEENTITYMANAGER_H_
#define MODULEENTITYMANAGER_H_

#include "Ball.h"
#include "Globals.h"
#include "Module.h"
#include "Paddle.h"
#include <vector>

class GameObject;

class ModuleEntityManager : public Module
{
public:
	ModuleEntityManager();
	~ModuleEntityManager();

	bool CleanUp();
	GameObject* CreateGameObject(GameObjectType type, int xPos, int yPos, int width, int height);
	bool Init();
	bool Update();

	Paddle *mPlayerOnePaddle;
	Paddle *mPlayerTwoPaddle;
	Ball *mBall;
private:
	std::vector<GameObject*> mEntities;
};

#endif /* MODULEENTITYMANAGER_H_ */
