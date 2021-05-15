// Spaceship Game
// Entity.h
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-13
// Header file for the Entity class.

#pragma once

#include "Define.h"

class Entity
{
	public:

	Texture* texturePtr;
	Sprite sprite;
	Vector2f velocity;

	//
	Entity();

	//
	Entity(Texture* texture_ptr);

	//
	Entity(Texture* texture_ptr, float x_pos, float y_pos);

	//
	Entity(Texture* texture_ptr, const Point2f& pos);

	//
	Entity(Texture* texture_ptr, const IntRect& sprite_rect);

	// 
	Entity(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos);

	//
	Entity(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos);

	//
	virtual void update(Time dt) = 0;
};