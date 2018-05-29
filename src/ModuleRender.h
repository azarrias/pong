/*
 * ModuleRender.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULERENDER_H_
#define MODULERENDER_H_

#include "Module.h"

struct SDL_Renderer;
struct SDL_Window;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool CleanUp();
	bool Init();
	bool Update();

	SDL_Renderer *mRenderer = nullptr;
};

#endif /* MODULERENDER_H_ */
