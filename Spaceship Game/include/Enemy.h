// Spaceship Game
// Enemy.h
// Justyn Durnford
// Created on 2021-05-13
// Last modified on 2021-05-13
// Header file for the Enemy class.

#pragma once

#include "Entity.h"

class Enemy : public Entity
{
	uint32_t turnChance_;

	public:

	Enemy(Texture* texture_ptr);

	Enemy(Texture* texture_ptr, float x_pos, float y_pos);

	Enemy(Texture* texture_ptr, const Point2f& pos);

	Enemy(Texture* texture_ptr, const IntRect& sprite_rect);

	Enemy(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos);

	Enemy(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos);

	void update(Time dt);
};