/*
 * Paddle.h
 *
 *  Created on: May 30, 2018
 *      Author: adolfo
 */

#ifndef PADDLE_H_
#define PADDLE_H_

#include "GameObject.h"

class Paddle : public GameObject
{
public:
	Paddle();
	Paddle(int xPos, int yPos, int width, int height);
	~Paddle() override;

	void UpdatePos() override;
};

#endif /* PADDLE_H_ */
