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
#include <vector>

class ModuleGUI : public Module
{
public:
	ModuleGUI();
	~ModuleGUI();

	bool CleanUp();
	SDL_Texture* GetTexture(int n) const;
	bool Init();
	bool Update();

private:
	TTF_Font *mFont = nullptr;
	std::vector<SDL_Texture*> mTextures;
};

#endif /* MODULEGUI_H_ */
