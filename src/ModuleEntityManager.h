/*
 * ModuleEntityManager.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULEENTITYMANAGER_H_
#define MODULEENTITYMANAGER_H_

#include "Globals.h"
#include "Module.h"
#include <vector>

class GameObject;

class ModuleEntityManager : public Module
{
public:
	ModuleEntityManager();
	~ModuleEntityManager();

	bool CleanUp();
	bool Init();
	bool Update();

	GameObject *mPlayerOnePaddle;
	GameObject *mPlayerTwoPaddle;
	GameObject *mBall;
private:
	std::vector<GameObject*> mEntities;
};

#endif /* MODULEENTITYMANAGER_H_ */
