/*
 * Ball.h
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#ifndef BALL_H_
#define BALL_H_

#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball();
	Ball(int xPos, int yPos, int width, int height);
	~Ball() override;

	void UpdatePos() override;
};

#endif /* BALL_H_ */
