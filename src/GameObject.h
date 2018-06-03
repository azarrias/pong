/*
 * GameObject.h
 *
 *  Created on: May 26, 2018
 *      Author: adolfo
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL2/SDL.h>
#include "Vector2D.inl"

enum GameObjectType
{
	BALL,
	PADDLE,
	UNKNOWN
};

class GameObject
{
public:
	GameObject();
	GameObject(GameObjectType type, int xPos, int yPos, int width, int height);
	virtual ~GameObject();

	SDL_Rect* GetRect();
	void SetPos(int xPos, int yPos);
	virtual void UpdatePos();
	virtual void UpdateVel();

	Vector2Df mVelocity;
	GameObjectType mType = UNKNOWN;

protected:
	SDL_Rect mRect;
};

#endif /* GAMEOBJECT_H_ */
