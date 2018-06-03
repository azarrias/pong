/*
 * Ball.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Ball.h"

Ball::Ball()
: GameObject()
{}

Ball::Ball(int xPos, int yPos, int width, int height)
: GameObject(GameObjectType::BALL, xPos, yPos, width, height)
{}

Ball::~Ball()
{}

void Ball::UpdatePos()
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

void Ball::UpdateVel()
{
	if(mRect.y <= 0 || mRect.y + mRect.h >= SCREEN_HEIGHT)
	{
		mVelocity.mY = -mVelocity.mY;
	}
}
