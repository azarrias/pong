/*
 * ModuleScene.h
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#ifndef MODULESCENE_H_
#define MODULESCENE_H_

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool CleanUp();
	bool Init();
	bool Start();
	bool Update();
};

#endif /* MODULESCENE_H_ */
