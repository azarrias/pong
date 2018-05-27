/*
 * GameObject.cpp
 *
 *  Created on: May 26, 2018
 *      Author: adolfo
 */

#include "GameObject.h"
#include "Globals.h"

GameObject::GameObject(int xPos, int yPos, int width, int height)
: m_velocity({ 0, 0 }), m_rect({ xPos, yPos, width, height })
{ }

SDL_Rect* GameObject::GetRect()
{
	return &m_rect;
}

void GameObject::UpdatePos()
{
	m_rect.x += m_velocity.x;
	if (m_rect.x < 0 || m_rect.x + m_rect.w > SCREEN_WIDTH)
	{
		m_rect.x -= m_velocity.x;
	}

	m_rect.y += m_velocity.y;
	if (m_rect.y < 0 || m_rect.y + m_rect.h > SCREEN_HEIGHT)
	{
		m_rect.y -= m_velocity.y;
	}
}
