// Spaceship Game
// Player.h
// Justyn Durnford
// Created on 2021-05-13
// Last modified on 2021-05-13
// Header file for the Player class.

#ifndef SPACESHIP_GAME_PLAYER_H
#define SPACESHIP_GAME_PLAYER_H

#include "Entity.h"

class Player : public Entity
{
	public:

	Player(Texture* texture_ptr);

	Player(Texture* texture_ptr, float x_pos, float y_pos);

	Player(Texture* texture_ptr, const Point2f& pos);

	Player(Texture* texture_ptr, const IntRect& sprite_rect);

	Player(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos);

	Player(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos);

	void update(Time dt);
};

#endif // SPACESHIP_GAME_PLAYER_H