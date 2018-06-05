/*
 * Ball.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Ball.h"
#include "GameManager.h"
#include "Globals.h"
#include "ModuleEntityManager.h"

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
	mRect.y += mVelocity.mY;

    // If the ball collided with a paddle, revert its movement
    // and modify its velocity properly
    if(CheckCollision(*game->mEntities->mPlayerOnePaddle) ||
       CheckCollision(*game->mEntities->mPlayerTwoPaddle))
    {
    	mRect.x -= mVelocity.mX;
    	mRect.y -= mVelocity.mY;
    	mVelocity.mX = -mVelocity.mX;
    }
}

void Ball::UpdateVel()
{
	if(mRect.y <= 0 || mRect.y + mRect.h >= SCREEN_HEIGHT)
	{
		mVelocity.mY = -mVelocity.mY;
	}
}
