/*
 * Paddle.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Paddle.h"

Paddle::Paddle()
: GameObject()
{}

Paddle::Paddle(int xPos, int yPos, int width, int height)
: GameObject(GameObjectType::PADDLE, xPos, yPos, width, height)
{}

Paddle::~Paddle()
{}

void Paddle::UpdatePos()
{
    mRect.x += mVelocity.mX;
	if (mRect.x < 0 || mRect.x + mRect.w > SCREEN_WIDTH)
	{
		mRect.x -= mVelocity.mX;
	}

	mRect.y += mVelocity.mY;
	if (mRect.y < 0 || mRect.y + mRect.h > SCREEN_HEIGHT)
	{
		mRect.y -= mVelocity.mY;
	}
}
