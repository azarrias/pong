/*
 * GameObject.h
 *
 *  Created on: May 26, 2018
 *      Author: adolfo
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL2/SDL.h>

SDL_Point typedef Velocity;

class GameObject
{
public:
	GameObject(int xPos, int yPos, int width, int height);
	SDL_Rect* GetRect();
	void UpdatePos();
	Velocity m_velocity;
private:
	SDL_Rect m_rect;
};

#endif /* GAMEOBJECT_H_ */
