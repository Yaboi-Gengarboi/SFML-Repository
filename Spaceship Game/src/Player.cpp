// Spaceship Game
// Player.cpp
// Justyn Durnford
// Created on 2021-05-13
// Last modified on 2021-05-13
// Source file for the Player class.

#include "Player.h"

Player::Player(Texture* texture_ptr) 
	: Entity(texture_ptr) {}

Player::Player(Texture* texture_ptr, float x_pos, float y_pos) 
	: Entity(texture_ptr, x_pos, y_pos) {}

Player::Player(Texture* texture_ptr, const Point2f& pos) 
	: Entity(texture_ptr, pos) {}

Player::Player(Texture* texture_ptr, const IntRect& sprite_rect)
	: Entity(texture_ptr, sprite_rect) {}

Player::Player(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos) 
	: Entity(texture_ptr, sprite_rect, x_pos, y_pos) {}

Player::Player(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos)
	: Entity(texture_ptr, sprite_rect, pos) {}

void Player::update(Time dt)
{
	float s = dt.asSeconds();
	Point2f pos(sprite.getPosition().x, sprite.getPosition().y);
	pos.x += velocity.x * s;
	pos.y += velocity.y * s;
	clamp(pos.x, 0.f, window_width - 32.f);
	clamp(pos.y, 0.f, window_height - 32.f);
	sprite.setPosition(pos.x, pos.y);
}