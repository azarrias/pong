/*
 * ModuleGUI.h
 *
 *  Created on: Jun 3, 2018
 *      Author: adolfo
 */

#ifndef MODULEGUI_H_
#define MODULEGUI_H_

#include "Module.h"
#include <SDL2/SDL_ttf.h>

class ModuleGUI : public Module
{
public:
	ModuleGUI();
	~ModuleGUI();

	bool CleanUp();
	bool Init();
	bool Update();

private:
	TTF_Font *mFont = nullptr;
	SDL_Rect mPlayerOneScoreRect, mPlayerTwoScoreRect;
};

#endif /* MODULEGUI_H_ */
